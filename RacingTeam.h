/***********************************************************************
*			Header for the Teams-Companies
* The values of the fields will fill in corresponding each team power
************************************************************************/
#ifndef	__Racing_Team_H__
#define __Racing_Team_H__

#include "RacingDriver.h"

#define	TOTAL_TEAMS	6
#define TEAM_NAME 	15
#define TOTAL_LAPS	10		

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
char*			GetTeamName(const Team);					/*Return the name of the team*/
unsigned short	GetTeamTeamwork(const Team);				/*Return the power level of the team*/
unsigned short	GetTeamStrategy(const Team);				/*Return the teamwork value of the team*/
int				GetTeamPitStop(const Team);					/*Return the strategy value of the team*/
void			TeamSetAttributes(p_Team, const p_Driver);	/*Fill in the fields of team random values*/
void			TeamPrint(const p_Team);					/*Printing the values of teams*/
void			TeamDestroy(p_Team);						/*Free the allocated memory*/
void			TeamRacingAbility(p_Team);					/*Calculate the total team ability adding her driver ability*/
float			TeamFinalTime(const Team);					/*Calculate the race lapse time for the teams*/
void			StartRace(p_Team);

#endif
