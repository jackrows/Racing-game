/***********************************************************************
*			Header for the Teams-Companies
* The values of the fields will fill in corresponding each team power
************************************************************************/
#ifndef	__Racing_Team_H__
#define __Racing_Team_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	TOTAL_TEAMS	6

const char* ConstructorTeams[TOTAL_TEAMS] = {"McLaren", "Ferrari", "Red Bull", "Renault", "Mercented", "Force India"};

/*Struct definition Team's members/fields/characteristics*/
typedef struct Team {
	char 			*name;		/*Store the name of each team*/
	unsigned short	power;		/*General financial and potential staff. The rest fields will effect from this. Range  1-10*/
	unsigned short	teamwork;	/*Store teamworking level. Range 1-10*/
	unsigned short	strategy;	/*Store team strategy level. Range 1-10*/
	unsigned short	pit_stop;	/*Store team speed in pit_stop. Range 1-10*/
}Team;

typedef Team* p_Team;

/*Declaration of the functions of racing teams*/
p_Team			TeamCreation();					/*Create the team and initialize the attributes*/
char*			GetTeamName(const Team);		/*Return the name of the team*/
unsigned short	GetTeamTeamwork(const Team);	/*Return the power level of the team*/
unsigned short	GetTeamStrategy(const Team);	/*Return the teamwork value of the team*/
int				GetTeamPitStop(const Team);		/*Return the strategy value of the team*/
void			SetAttributes(p_Team);			/*Fill in the fields of team random values*/

#endif
