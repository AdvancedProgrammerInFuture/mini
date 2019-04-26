#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>

typedef struct carType Car; 
struct carType{ 
	int id_of_vehicle;
	char manufacturer[20];
	char model_of_veh[20];
	int year_of_manufacture;
	int mileage;
	double cost;
	Car *next;
}; 

Car *Scanlist(Car *headpointer, int search_ID);
void AddEntry(Car *headpointer);
void DeleteEntry(Car *headpointer);
void Search(Car *headPointer);
	
int main() {
	int operation = 0; // current operation to be performed
	Car carBase; // is an empty head node
	
	carBase.next = NULL;
	
	printf("=========================\n");
	printf("=== Used car database ===\n");
	printf("=========================\n");
	
	while (operation != 4) {
		printf("Enter an operation:\n");
		printf("1 - Car aquired. Add a new entry for it.\n");
		printf("2 - Car sold. Remove its entry.\n");
		printf("3 - Query. Look up a car's information.\n");
		printf("4 - Quit.\n");
		scanf("%d", &operation);
			
		switch(operation) {
			case 1: AddEntry(&carBase);
			case 2:	DeleteEntry(&carBase);
			case 3: Search(&carBase);
			case 4: printf("Goodbye. \n\n");
			default: printf("invalid operation. Try again.\n\n");
		}
	}
	return 0;
}	

Car *ScanList(Car *headPointer, int search_ID)
{
	Car *previous_Car;
	Car *current_Car;
	
	previous_Car = headPointer;
	current_Car = headPointer->next;

	while ((current_Car != NULL) && (current_Car->id_of_vehicle < search_ID)) {
		previous_Car = current_Car;
		current_Car = current_Car->next;
	}

	return previous_Car;
}

void AddEntry(Car *headPointer)
{
	Car *newNode; // Points to new Car-info
	Car *nextNode; // Points to Car to follow new one
	Car *prevNode; // Points to Car before this one

	newNode = (Car *) malloc(sizeof(Car));
	
	if (newNode == NULL) {
		printf("Error: could not allocate a new node\n");
		exit(1);
	}
	
	printf("Enter the following info about the car.\n");
	printf("Separate each field by white space:\n");
	printf("vehicle_id make model year mileage cost\n");
	
	scanf("%d %s %s %d %d %lf", &newNode->id_of_vehicle, newNode->manufacturer, newNode->model_of_veh, &newNode->year_of_manufacture, &newNode->mileage, &newNode->cost); 	

	prevNode = ScanList(headPointer, newNode->id_of_vehicle);
	nextNode = prevNode->next;
	
	if ((nextNode == NULL) || (nextNode->id_of_vehicle != newNode->id_of_vehicle)) {
		prevNode->next = newNode;
		newNode->next = nextNode;
		printf("Entry added.\n\n");
	}
	else {
		printf("That car already exists in the database!\n");
		printf("Entry not added.\n\n");
		free(newNode);
	}
}

void DeleteEntry(Car *headPointer) 
{
	int id_of_vehicle;
	Car *delNode; // Points to node that need to delete
	Car *prevNode; // Points to node that prior to delNode

	printf("Enter id of the vehicle of the car that need to delete");
	scanf("%d", &id_of_vehicle);

	prevNode = ScanList(headPointer, id_of_vehicle);
	delNode = prevNode->next;
	
	if (delNode != NULL && delNode->id_of_vehicle == id_of_vehicle) {
		prevNode->next = delNode->next;
		printf("Vehicle with ID %d deleted. \n\n", id_of_vehicle);
		free(delNode);
	}
	else
		printf("This vehicle not found in database");
	
}

void Search(Car *headPointer) 
{
	int id_of_vehicle;
	Car *searchNode;
	Car *prevNode;
	
	printf("Enter a vehicle id number that need to search: ");
	scanf("%d", &id_of_vehicle);

	prevNode = ScanList(headPointer, id_of_vehicle);
	searchNode = prevNode->next;

	if (searchNode->next != NULL &&  searchNode->id_of_vehicle == id_of_vehicle) {
		printf( "vehicle ID %d\n", searchNode->id_of_vehicle);
		printf( " make %s\n", searchNode->manufacturer);
		printf( "model %s\n", searchNode->model_of_veh);
		printf( "year %d\n", searchNode->year_of_manufacture);
		printf( "mileage %d\n", searchNode->mileage); 
		printf("cost : $%10.2f\n\n", searchNode->cost); 
	}
	else  
		printf("This vehicle %d does not found in the database of linked list", id_of_vehicle);
}

