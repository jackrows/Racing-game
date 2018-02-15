/********************************************
*	Implementation of Driver functions
*********************************************/

#include "RacingDriver.h"

const char* DriversName[TOTAL_DRIVERS] = {"Schumacher", "Hamilton", "Senna", "Niki Lauda", "Vettel", "Raikkonen", "Colin McRay"}; /*Static array with driver's names*/

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
	int min = 1;				/*Minimum value for attributes, used on rand()*/
	int max = ATTRIBUTE_MAX;	/*Maximum value for attributes, used on rand()*/
	
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

/*Free the located memory for name string and whole driver array*/
void DriverDestroy(p_Driver driver)
{
	int i;
	for(i = 0; i < TOTAL_DRIVERS; i++)
	{
		free(driver[i].name);
	}
	free(driver);
}

/*Calculate the total racing ability of driver accordingly his attribute's values
* The ability calculate from the form: Ability = 1.6speed + 1.9acceleration + 1.8handling + 1.4determination*/
float DriverRacingAbility(const p_Driver driver)
{
	float ability = 0.0;	/*Store the racing ability*/
	float factor_sp = 1.6, factor_ac = 1.9, factor_ha = 1.8, factor_dt = 1.4;	/*Affect for each attribute*/
	
	ability = factor_sp * driver->speed + factor_ac * driver->acceleration + factor_ha * driver->handling + factor_dt * driver->determination;
/*	printf("\n#%s ability = %.2f\n",driver->name, ability);*/
	return ability;
}
