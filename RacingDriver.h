/********************************************
*	Header file for the driver
*********************************************/
#ifndef	__RACING_DRIVER_H__
#define __RACING_DRIVER_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*#include "RacingTeam.h"*/

#define ATTRIBUTE_MAX	10
#define	TOTAL_DRIVERS	6
#define DRIVER_NAME		13	

/*Definition of the driver struct*/
typedef struct Driver {
	char *name;				/*Store the name of the driver*/
	short speed;			/*Speed ability of driver. Range 1-10*/
	short acceleration;		/*Accelerationa ability. Range 1-10*/
	short handling;			/*Handling ability of vehicle. Range 1-10*/
	short determination;	/*Determination ability. Range 1-10*/
}Driver;

typedef Driver* p_Driver; 	/*pointer on struct Driver*/

/*Declaration of functions about driver*/
p_Driver	DriverCreation();						/*Create the array with the drivers and initialize the attributes*/
void		DriverSetAttributes(p_Driver);			/*Set driver's attributes with random values*/
Driver		GetDriver(const p_Driver, int);			/*Get back the driver from array that position specify*/
void 		DriverPrint(const p_Driver);			/*Print whole the driver array*/
void		DriverPrintOne(const p_Driver);			/*Print the values from just one driver*/
void		DriverDestroy(p_Driver);				/*Free the located memory for name and driver array*/
float		DriverRacingAbility(const p_Driver);	/*Calculate the final driving ability of driver depend his attributes*/

#endif
