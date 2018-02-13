/******************************************************
*	Implementation of RacingTeam functions
*******************************************************/

#include "RacingTeam.h"
#include "GeneralFunctions.h"

const char* ConstructorTeams[TOTAL_TEAMS] = {"McLaren", "Ferrari", "Red Bull", "Renault", "Mercentes", "Force India"};	/*Static array with team's names*/

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
		team[i].racing = 0.0;
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
		team[i].driver = GetDriver(drivers, i);		/*Assign driver to team racing*/
	}
}

/*Printing the values of all teams*/
void TeamPrint(const p_Team team)
{
	int i;
	for(i = 0; i < TOTAL_TEAMS; i++)
	{
		printf("\n\n****** %s ******\n", team[i].name);
		printf("-Power: %d\n", team[i].power);
		printf("-Strategy: %d\n", team[i].strategy);
		printf("-Teamwork: %d\n", team[i].teamwork);
		printf("-Pit-Stop speed: %d\n", team[i].pit_stop);
		printf(" -%5s's driver:",team[i].name);
		DriverPrintOne(&team[i].driver);
		printf("-%s racing strength: %.2f\n",team[i].name, team[i].racing);
	}
}

/*Unlocate the memory from name and whole team array*/
void TeamDestroy(p_Team team)
{
	int i;
	for(i = 0; i < TOTAL_TEAMS; i ++)
		free(team[i].name);		/*Free the memory of name from each team*/
	
	free(team);		/*Free the memory of whole array*/
}

/*Calculate team racing ability combine her driver driving ability
* The amount resulting by the form: ability = 1.8power + 1.5strategy + 1.7teamwork + 1.4pit_stop + 1.6driver_ability*/
void TeamRacingAbility(p_Team team)
{
	int i;
	float driver_ab = 0.0;
	float team_ab = 0.0;
	float factor_po = 1.8, factor_st = 1.5, factor_tw = 1.7, factor_ps = 1.4, factor_dr = 1.6;
	
	for(i = 0; i < TOTAL_TEAMS; i++)
	{
		driver_ab = DriverRacingAbility(&team[i].driver);
		team_ab = (factor_po * team[i].power) + (factor_st * team[i].strategy) + (factor_tw * team[i].teamwork) + (factor_ps * team[i].pit_stop) + (factor_dr * driver_ab);
		team[i].racing = team_ab;
		printf(" %s race ability: %.3f | %s skill: %.2f\n", team[i].name, team[i].racing, team[i].driver.name, driver_ab);
	}
}

/*Calculate the race time of each team accordingly her ability
* The time resulting by the form: T = laps / ability*/
float TeamFinalTime(const Team team)
{
	float timing = 0.0;
	timing = TOTAL_LAPS * 100 / team.racing;
	/*printf("\n%s race time = %f\n",team.name, timing);*/
	return timing;
}

/**/
void StartRace(p_Team team)
{
	int i, laps = 1;
	float standing[TOTAL_TEAMS][2];
	float random_factor = 0;
	
	printf("\n####### The Race began! 3, 2, 1, GO!!#######\n");
	while(laps <= TOTAL_LAPS)
	{
		printf("\n***************************************\n");
		printf("Lap number %d/%d:\n", laps, TOTAL_LAPS);
		random_factor = (float)rand()/(float)(RAND_MAX/1.6);
		for(i = 0; i < TOTAL_TEAMS; i++)
		{
			standing[i][0] = TeamFinalTime(team[i]) + random_factor;
			standing[i][1] = (float)i;
		}
		SortingStanding(standing);
		printf("#Results:\n");
		for(i = 0; i < TOTAL_TEAMS; i++)
		{
			printf("-%d. %s - %.4f\n", i+1, team[(int)standing[i][1]].driver.name, standing[i][0]);
		}
		printf("\n***************************************\n");
		laps++;
	}
}
