*****************************************************************************************
* Author:	Alexandros Polychronopoulos
* Nickname:	c0sm0sD3v
* Release:	8/2/2018
*****************************************************************************************

Brief description:
This is a console program in c language that simulate a car racing game.
The program doesn't accept command line arguments and doesn't interact with the user. 
For the teams, drivers, lap's time used arrays.

Files:
Racing.c: Main function, malloc and free the necessary memory, start the race.
RacingTeam.h: Struct of team, declaration of functions
RacingTeam.c: Source code for team functions
RacingDriver.h: Struct of driver, declaration of functions
RacingDriver.c: Implementation of driver functions
GeneralFunctions.h: Declaration of general purpose functions
GeneralFunctions.c: Implementation of general functions

Operation:
The program start with locate the memory for the teams and drivers array and initialize their attributes.
Next set the values of driver attributes random between the range 1-10.
Then set the team attributes random. The most important attribute is the power which affect the price of other attributes.
The power splited in 3 categories, low <= 4, medium <= 7 and strong 8-10. The rest attributes fill in random,
and depend on power level. For low the range is 1-5, for medium 3-7, for strong 6-10.
After that calculated the racing ability for each team as follow: first counting the driver ability depend on his
attributes which each attribute has different factor(weight). Second calculating the team racing ability which come of 
driver ability and team attributes which each attribute has different factor(weight).
Then the race started. The number of laps is general variable and for every lap display the time of each driver.
The time calculated with follow way: laps * 100 / team_ability + random_factor, random factor is a small decima number
between 0-2 and effect the time of each driver. This factor added to make the result different each lap and more
interesting and unpredictable.
Final print the standing and the winners.
