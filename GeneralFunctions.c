/******************************************
*	Implementation of General functions
*******************************************/

#include "GeneralFunctions.h"

/*Display the final standing, after the laps finished*/
void FinalStanding(float times[][2], p_Team team)
{
	printf("\n\n#The final standing of race:\n");
	int i;
	for(i = 0; i < TOTAL_TEAMS; i++)
	{
		printf("-%d. %s - %.4f", i+1, team[(int)times[i][1]].driver.name, times[i][0]);
		if(i == 0)	/*Big winner*/
			printf(" - BIG WINNEEEEER!!!!\n");
		if(i == 1)	/*Silver winner*/
			printf(" - Second at pedestal!!\n");
		if(i == 2)	/*Bronze winner*/
			printf(" - Third at pedestal!!\n");
		printf("\n");
	}
}

/*Sorting the time of drivers each lap
* This function help to print the result properly*/
void SortingTimes(float standing[][2])
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

/*Switch the whole row of standing array
* Each row has two element, the time and the indexing with the driver*/
void Swap(float time1[], float time2[])
{
	float temp[2];
	int i;
	for(i = 0; i < 2; i++)
		temp[i] = time1[i];
	for(i = 0; i < 2; i++)
		time1[i] = time2[i];
	for(i = 0; i < 2; i++)
		time2[i] = temp[i];
}
