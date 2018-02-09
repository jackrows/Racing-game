/********************************************
*	Author:		Polychronopoulos
*	Nickname:	c0sm0sD3v
*	Release:	8/2/2018*/

#include "RacingTeam.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	/*Variables*/
	int i;							/*Variable to index the array of teams*/
	p_Team Teams = TeamCreation();	/*Create the array of teams with TOTAL TEAMS size*/
	
	for(i = 0; i < TOTAL_TEAMS; i++)
	{
		printf("Teams %d : \n", i+1);
		printf("Name : %s\n", Teams[i].name);
		printf("power: %d\n", Teams[i].power);
	}
	
	return 0;
}
