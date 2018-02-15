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
	p_Team Teams = TeamCreation();			/*Create the array of teams with TOTAL TEAMS size*/
	p_Driver Drivers = DriverCreation();	/*Create the array of drivers*/
	
	if(Teams == NULL)	/*Check for the malloc on TeamCreation*/
	{
		printf("\n\t#Error in TeamCreation at malloc function!\n");
		printf("#Exiting...\n");
		return 1;
	}
	else if(Drivers == NULL)	/*Check for the malloc on TeamCreation*/
	{
		printf("\n\t#Error in DriverCreation at malloc function!\n");
		printf("#Exiting...\n");
		return 1;
	}
	
	printf("#Teams and Drivers are been preparing...\n");
	
	/*Set random values to driver attributes*/
	DriverSetAttributes(Drivers);		
	
	/*Set random values to team attributes and assign a driver to the team*/
	TeamSetAttributes(Teams, Drivers);	
	
	/*Calculate the racing ability of teams*/
	TeamRacingAbility(Teams);		
	
	/*Start the race*/
	StartRace(Teams);
	
	/*Free the located memory*/
	DriverDestroy(Drivers);
	TeamDestroy(Teams);
	
	printf("\n#Thank you for watching the today race.\n");
	return 0;
}
