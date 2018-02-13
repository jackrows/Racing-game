/******************************************
*	Implementation of General functions
*******************************************/

#include "GeneralFunctions.h"

/*void FinalStanding(float times[], p_Team team)
{
	int i, index = 0;
	float min = 0.0, temp = 0.0;
	float standing[TOTAL_TEAMS][2];
	
}*/

void SortingStanding(float standing[][2])
{
	int i, j;
	for(i = 0; i < TOTAL_TEAMS -1; i++)
	{
		for(j = 0; j < TOTAL_TEAMS-i-1; j++)
		{
			if(standing[j][0] > standing[j+1][0])
			{
				Swap(standing[j], standing[j+1]);
			}
		}
	}
}

void Swap(float* time1, float* time2)
{
	float temp = *time1;
	*time1 = *time2;
	*time2 = temp;
}
