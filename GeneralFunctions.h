/*************************************
*	Header of General functions
**************************************/
#ifndef __General_Functions_H__
#define __General_Functions_H__

#include "RacingTeam.h"

/*Declaration of General functions*/
void FinalStanding(float [][2], p_Team);	/*Display the final standing of the race. arg1: the array with driver's time stored*/
void SortingTimes(float [][2]);				/*Sorting the time of teams*/
void Swap(float*, float*);					/*Switch the rows of each lap driver's time*/


#endif
