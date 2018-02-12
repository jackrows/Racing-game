/******************************************************
*	Implementation of RacingTeam functions
*******************************************************/

#include "RacingTeam.h"

const char* ConstructorTeams[TOTAL_TEAMS] = {"McLaren", "Ferrari", "Red Bull", "Renault", "Mercented", "Force India"};	/*Static array with team's names*/

/*Allocate memory for the racing teams and initialize the attributes*/
p_Team TeamCreation()
{
	p_Team team = (p_Team)malloc(sizeof(Team) * TOTAL_TEAMS);
	if(team == NULL)
		return NULL;
	/*Team teams[TOTAL_TEAMS];*/
	int i;
	for(i = 0; i < TOTAL_TEAMS; i++)
	{
		team[i].name = (char*)malloc(sizeof(char) * TEAM_NAME);
		if(team[i].name == NULL)
			return NULL;
		strcpy(team[i].name, ConstructorTeams[i]);
	/*	team[i].name = ConstructorTeams[i];*/
		team[i].pit_stop = 0;
		team[i].power = 0;
		team[i].strategy = 0;
		team[i].teamwork = 0;
	}
	return team;
}

/*Set team's attributes. First set power as it efect the rest attributes.
* Depend power value separate levels for the teams.
* power <=4 -> low, <= 7 -> medium, > 7 -> strong*/
void TeamSetAttributes(p_Team team, const p_Driver drivers)
{
	time_t t;	/*Used for srand*/
	srand((unsigned)time(&t));	/*Initialize the seed for random number generator(rand)*/
	
	int i;
	int min = 1;	/*Minimum value for attributes, used on rand()*/
	short low = 5, medium = 7, high = ATTRIBUTE_MAX;	/*low: small team power, medium: medium team power, high: strong team power*/
	for(i = 0; i < TOTAL_TEAMS; i++)
	{
		int p = 0;	/*Auxiliary variable to store the power of team*/
		team[i].power = (rand() % (ATTRIBUTE_MAX + 1 - min)) + min;	/*(rand() % (max + 1 - min)) + min. We want 1-10 range. This attribute will effect the others*/
		p = team[i].power;
		
		if(p < low)	/*Low level of power of team, the rest attribute will filled with low level values 1-5*/
		{
			team[i].strategy = (rand() % (low + 1 - min)) + min;
			team[i].teamwork = (rand() % (low + 1 - min)) + min;
			team[i].pit_stop = (rand() % (low + 1 - min)) + min;
		}
		else if(p <= medium)	/*Medium level of power, the rest attribute will be filled with values 3-7*/
		{
			min += 2;
			team[i].strategy = (rand() % (medium + 1 - min)) + min;
			team[i].teamwork = (rand() % (medium + 1 - min)) + min;
			team[i].pit_stop = (rand() % (medium + 1 - min)) + min;
			min = 1;
		}
		else	/*strong team power, the rest attribute will be filled with values 6-10*/
		{
			min = medium - 1;
			team[i].strategy = (rand() % (high + 1 - min)) + min;
			team[i].teamwork = (rand() % (high + 1 - min)) + min;
			team[i].pit_stop = (rand() % (high + 1 - min)) + min;
			min = 1;
		}
		team[i].driver = GetDriver(drivers, i);
	}
}

/*Printing the values of all teams*/
void TeamPrint(const p_Team team)
{
	int i;
	for(i = 0; i < TOTAL_TEAMS; i++)
	{
		printf("\n\t*** %s ***\n", team[i].name);
		printf("Power : %d\n", team[i].power);
		printf("Strategy : %d\n", team[i].strategy);
		printf("Teamwork : %d\n", team[i].teamwork);
		printf("Pit-Stop speed : %d\n", team[i].pit_stop);
		DriverPrintOne(&team[i].driver);
	}
}
