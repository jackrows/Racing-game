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
	/*float final_time[TOTAL_TEAMS];			Array with race time of each team*/
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
	
	/*DriverPrint(Drivers);*/
	
	TeamRacingAbility(Teams);		/*Calculate the racing ability of teams*/
	
	/*for(i = 0; i < TOTAL_TEAMS; i++)
	{
		final_time[i] = TeamFinalTime(Teams[i]);
	}
	
	FinalStanding(final_time);
	
	for(i = 0; i < TOTAL_TEAMS; i++)
	{
		
	}*/
	
	StartRace(Teams);
	
/*	TeamPrint(Teams);*/
	
	DriverDestroy(Drivers);
	TeamDestroy(Teams);
	return 0;
}
