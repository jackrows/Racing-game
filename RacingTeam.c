/******************************************************
*	Implementation of RacingTeam functions
*******************************************************/

#include "RacingTeam.h"

const char* ConstructorTeams[TOTAL_TEAMS] = {"McLaren", "Ferrari", "Red Bull", "Renault", "Mercented", "Force India"};

/**/
p_Team TeamCreation()
{
	p_Team team = (p_Team)malloc(sizeof(Team) * TOTAL_TEAMS);
	/*Team teams[TOTAL_TEAMS];*/
	int i;
	for(i = 0; i < TOTAL_TEAMS; i++)
	{
		team[i].name = (char*)malloc(sizeof(char) * 15);
		team[i].name = ConstructorTeams[i];
		team[i].pit_stop = 0;
		team[i].power = 0;
		team[i].strategy = 0;
		team[i].teamwork = 0;
	}
	return team;
}
