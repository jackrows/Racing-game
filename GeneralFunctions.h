/*************************************
*	Header of General functions
**************************************/
#ifndef __General_Functions_H__
#define __General_Functions_H__

#include "RacingTeam.h"

/*Declaration of General functions*/
void FinalStanding(float [][2], p_Team);			
void SortingTimes(float [][2]);				/*Sorting the time of teams*/
void Swap(float*, float*);					/*Switch the rows of each lap driver's time*/
/*int ReadTeamsAndDrivers(FILE* f, char a[], char b[])*/

#endif
