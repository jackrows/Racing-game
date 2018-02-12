/********************************************
*	Author:		Polychronopoulos
*	Nickname:	c0sm0sD3v
*	Release:	8/2/2018
*********************************************/

#include "RacingTeam.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	/*Variables*/
	int i;									/*Variable to index the array of teams*/
	p_Team Teams = TeamCreation();			/*Create the array of teams with TOTAL TEAMS size*/
	p_Driver Drivers = DriverCreation();	/*Create the array of drivers*/
	if(Teams == NULL)
	{
		printf("\n\t#Error in TeamCreation at malloc function!\n");
		printf("#Exiting...\n");
		return 1;
	}
	else if(Drivers == NULL)
	{
		printf("\n\t#Error in DriverCreation at malloc function!\n");
		printf("#Exiting...\n");
		return 1;
	}
	DriverSetAttributes(Drivers);		/*Set random values to driver attributes*/
	TeamSetAttributes(Teams, Drivers);	/*Set random valies to team attributes and assign a driver to the team*/
	TeamPrint(Teams);
	DriverPrint(Drivers);
	
	return 0;
}
