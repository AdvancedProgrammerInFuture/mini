#include<stdio.h> 

typedef struct carType { 
	int id_of_vehicle;
	char manufacturer[20];
	char model_of_veh[20];
	int year_of_manufacture;
	int mileage;
	double cost;
	carType *next;
} Car; 

Car *Scanlist(Car *headpointer, int search_ID);

int main() {
	int operation = 0 // current operation to be performed
	Car carBase; // is an empty head node
	
	carBase.next = NULL;
	
	printf("=========================\n");
	printf("=== Used car database ===\n");
	printf("=========================\n");
	
	while (operation != 4) {
		printf("Enter an operation:\n");
		printf("1 - Car aquired. Add a new entry for it.\nM);
		printf("2 - Car sold. Remove its entry.\nM);
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
	  	
	return 0;
}

Car *Scanlist(Car *headPointer, int search_ID)
{
	Car *previous_Car;
	Car *current_Car;
	
	previous_Car = headPointer;
	current_Car = headPointer->next;

	while ((current_Car != NULL) && (current_Car->id_of_vehicle < search_ID)) {
		previous_Car = current_Car;
		current_Car = current_Car->next;
	}
`	
	return previous;
}


