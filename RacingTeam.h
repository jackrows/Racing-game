/***********************************************************************
*			Header for the Teams-Companies
* The values of the fields will fill in corresponding each team power
************************************************************************/
#ifndef	__Racing_Team_H__
#define __Racing_Team_H__

#include "RacingDriver.h"

#define	TOTAL_TEAMS	6		/*Total teams that exist in static array*/
#define TEAM_NAME 	15		/*Size of team's name that will commit on memory*/
#define TOTAL_LAPS	6		/*The number of the willing laps*/

/*Struct definition Team's members/fields/characteristics*/
typedef struct Team {
	char			*name;		/*Store the name of each team*/
	unsigned short	power;		/*General financial and potential staff. The rest fields will effect from this. Range  1-10. 1-4 low, 5-7 medium, 8-10 strong level*/
	unsigned short	teamwork;	/*Store teamworking level. Range 1-10*/
	unsigned short	strategy;	/*Store team strategy level. Range 1-10*/
	unsigned short	pit_stop;	/*Store team speed in pit_stop. Range 1-10*/
	Driver			driver;		/*Assign a driver to each team*/
	float			racing;		/*Store the racing ability of the team, which resulting combined with driver ability*/
}Team;

typedef Team* p_Team;

/*Declaration of the functions of racing teams*/
p_Team			TeamCreation();								/*Create the team and initialize the attributes*/
void			TeamSetAttributes(p_Team, const p_Driver);	/*Fill in the fields of team random values*/
void			TeamPrint(const p_Team);					/*Printing the values of teams*/
void			TeamDestroy(p_Team);						/*Free the allocated memory*/
void			TeamRacingAbility(p_Team);					/*Calculate the total team ability adding her driver ability*/
float			TeamFinalTime(const Team);					/*Calculate the race lapse time for the teams*/
void			StartRace(p_Team);							/*Leading function that perform the race, display the result at every lap and the winner*/
int 			TeamAssignDriverRandom(p_Team, const p_Driver);	/*Assign driver to each team randomly at each program running*/

#endif
