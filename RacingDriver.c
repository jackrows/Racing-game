/********************************************
*	Implementation of Driver functions
*********************************************/

#include "RacingDriver.h"

const char* DriversName[TOTAL_DRIVERS] = {"Schumacher", "Hamilton", "Senna", "Niki Lauda", "Vettel", "Raikkonen"}; /*Static array with driver's names*/

/*Allocate memory for the drivers and initialize their attributes*/
p_Driver DriverCreation()
{
	p_Driver driver = malloc(sizeof(Driver) * TOTAL_DRIVERS);
	if(driver == NULL)
		return NULL;
		
	int i;
	for(i = 0; i < TOTAL_DRIVERS; i++)
	{
		driver[i].name = malloc(sizeof(Driver) * DRIVER_NAME);
		if(driver[i].name == NULL)
			return NULL;
		strcpy(driver[i].name, DriversName[i]);
		driver[i].acceleration = 0;
		driver[i].determination = 0;
		driver[i].handling = 0;
		driver[i].speed = 0;
	}
	return driver;
}

/*Set at driver's attributes randon mumbers between 1-10
* All attributes fill in random with a value 1-10*/
void DriverSetAttributes(p_Driver driver)
{
	time_t t;	/*Used for srand()*/
	srand((unsigned)time(&t));	/*Initialize the seed for random number generator(rand)*/
	
	int i;
	int min = 1;	/*Minimum value for attributes, used on rand()*/
	int max = ATTRIBUTE_MAX;
	
	for(i = 0; i < TOTAL_DRIVERS; i++)
	{
		driver[i].acceleration = (rand() % (max + 1 - min)) + min;	/*(rand() % (max + 1 - min)) + min*/
		driver[i].determination = (rand() % (max + 1 - min)) + min;
		driver[i].handling = (rand() % (max + 1 - min)) + min;
		driver[i].speed = (rand() % (max + 1 - min)) + min;
	}
}

/*Return the driver specified given position*/
Driver GetDriver(const p_Driver driver, int pos)
{
	return driver[pos];
}

/*Printing the values of specific driver*/
void DriverPrintOne(const p_Driver driver)
{
	printf("\n\t*** %s ***\n", driver->name);
	printf("\t-Speed: %d\n", driver->speed);
	printf("\t-Acceleration: %d\n", driver->acceleration);
	printf("\t-Handling: %d\n", driver->handling);
	printf("\t-Determination: %d\n", driver->determination);
}

/*Printing the values of all drivers*/
void DriverPrint(const p_Driver driver)
{
	int i;
	for(i = 0; i < TOTAL_DRIVERS; i++)
	{
		printf("\n\t*** %s ***\n", driver[i].name);
		printf("-Speed: %d\n", driver[i].speed);
		printf("-Acceleration: %d\n", driver[i].acceleration);
		printf("-Handling: %d\n", driver[i].handling);
		printf("-Determination: %d\n", driver[i].determination);
	}
}
