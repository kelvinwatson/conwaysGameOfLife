/******************************************************************************
* Program Filename: main.cpp
* Author: Kelvin Watson (OSU ID 932540242)
* Date: 11 January, 2015
* Description: (Assignment 1, CS 162) Implementation of Conway's Game Of Life. 
* Input: User inputs commands (blinker, glider, gun, rules or quit), number of
*				generations, number of milliseconds between display of generations, 
				and starting location of the configuration.	
* Output: Each generation is displayed on the console, with a time delay 
				between generations to allow the user to see the changes.         
******************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cstdlib>
#include <string>
using std::string;
#include <cstring>
#include <iomanip>

#include "functions.h"
#include "configuration.h"

#define ROWS 26
#define COLS 84
 
#define NUM_COORDINATES_BLINKER 3
#define NUM_COORDINATES_GLIDER 5
#define NUM_COORDINATES_BEACON 6
#define NUM_COORDINATES_GUN 36


int main()
{
	system("clear");
 	show_intro_rules();

 	string command;

 	do
 	{
 		command.clear();
 		show_options();
 		command = get_command();
 		if (command == "blinker")
 		{
 			cout << "You have selected the BLINKER:" << endl;
			
			/* obtain/validate initial conditions */
			int iterations = validate_iterations();		
			clock_t sec = validate_seconds(); 				//for time delay between display of generations;
			int start_row = validate_starting_row(command);
			int start_col = validate_starting_col(command);
			
			configuration blinker(start_row, start_col, NUM_COORDINATES_BLINKER, sec, iterations, command); //instantiate blinker class	
 		}
 		else if (command == "beacon")
		{
			cout << "You have selected the BEACON:" << endl;
			//obtain/validate initial conditions
			int iterations = validate_iterations();	
			clock_t sec = validate_seconds(); 		 
			int start_row = validate_starting_row(command);
			int start_col = validate_starting_col(command);
			
			configuration beacon(start_row, start_col, NUM_COORDINATES_BEACON, sec, iterations, command); //instantiate beacon class	 

		}
 		else if (command == "glider")
		{
			cout << "You have selected the GLIDER:" << endl;
			//obtain/validate initial conditions
			int iterations = validate_iterations();	
			clock_t sec = validate_seconds(); 		 
			int start_row = validate_starting_row(command);
			int start_col = validate_starting_col(command);
			
			configuration glider(start_row, start_col, NUM_COORDINATES_GLIDER, sec, iterations, command); //instantiate glider class	 

		}
		else if (command == "gun")
		{
			cout << "You have selected the GLIDER GUN:" << endl;
			//obtain/validate initial conditions
			int iterations = validate_iterations();	
			clock_t sec = validate_seconds(); 		 
			int start_row = validate_starting_row(command);
			int start_col = validate_starting_col(command);
			
			configuration gun(start_row, start_col, NUM_COORDINATES_GUN, sec, iterations, command); //instantiate blinker class
		}
		else if (command == "rules")
		{
			get_rules();
		}
		else if (command == "quit")
		{
			cout << "You are exiting the Game of Life program. Goodbye." << endl;
			exit(EXIT_SUCCESS);	
		}
 	} while(command != "quit");

	return 0;
}