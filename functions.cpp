/******************************************************************************
 * Program Filename: functions.cpp
 * Author: Kelvin Watson (OSU ID 932540242)
 * Date: 11 January, 2015
 * Description: (Assignment 1, CS 162) Implementation for functions.cpp. 
 					Contains definitions for functions declared in functions.h.
 * Output: See individual function definitions below.        
 *****************************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cstdlib>
#include <cstring>
#include <string>
using std::string;
#include <iomanip>
using std::setw;
using std::left;

#include "functions.h"
#include <ctime>


/******************************************************************************
** Function: show_intro_rules()
** Description:	Displays the title of the program, as well as the rules of 
			Conway's Game of Life.
** Parameters: Does not contain parameters.
** Pre-Conditions: No arguments are passed into this function.
** Post-Conditions: Title and rules are printed. No variables are modified.
******************************************************************************/
void show_intro_rules()
{
	cout << "**************************" << endl;
 	cout << "* CONWAYS'S GAME OF LIFE *" << endl;
 	cout << "**************************" << endl;
 	cout << "RULES:" << endl; 
 	cout << "1. If an occupied cell has <2 neighbors, it dies of "
 	"loneliness." << endl;
 	cout << "2. If an occupied cell has >3 neighbors, it dies of overcrowding."
 	<< endl;
 	cout << "3. If an occupied cell has 2 or 3 neighbours, it survives to the "
 	"next generation." << endl;
 	cout << "4. If an unoccupied cell has 3 occupied neighbours, it becomes "
 	"occupied." << endl;
}


/******************************************************************************
** Function: get_rules()
** Description:	Displays the rules of Conway's Game of Life.
** Parameters: Does not contain parameters.
** Pre-Conditions: No arguments are passed into this function.
** Post-Conditions: Rules are printed. No variables are modified.
******************************************************************************/
void get_rules()
{
	cout << endl << "RULES:" << endl; 
 	cout << "1. If an occupied cell has <2 neighbors, it dies of "
 	"loneliness." << endl;
 	cout << "2. If an occupied cell has >3 neighbors, it dies of overcrowding."
 	<< endl;
 	cout << "3. If an occupied cell has 2 or 3 neighbours, it survives to the "
 	"next generation." << endl;
 	cout << "4. If an unoccupied cell has 3 occupied neighbours, it becomes "
 	"occupied." << endl;
}


/******************************************************************************
** Function: show_options()
** Description:	Displays the possible command options in the form of a menu.
** Parameters: Does not contain parameters.
** Pre-Conditions: No arguments are passed into this function.
** Post-Conditions: Menu is printed. No variables are modified.
******************************************************************************/
void show_options()
{
cout << endl 
<< "------------------------------------------------------------" << endl;
cout << endl << "Please enter a command from the following menu"
<< endl << endl;
cout << left << setw(11) << "COMMAND" << left << setw(53) << "DESCRIPTION" 
<< endl;
cout << left << setw(11) << "blinker" << left << setw(53) << "Blinker pattern (oscillator)" 
<< endl;
cout << left << setw(11) << "beacon" << left << setw(53) << "Beacon pattern (oscillator)" 
<< endl;
cout << left << setw(11) << "glider" << left << setw(53) << "Glider pattern (spaceship)" 
<< endl;
cout << left << setw(11) << "gun" << left << setw(53) << "Glider gun pattern" 
<< endl;
cout << left << setw(11) << "rules" << left << setw(53) << "Show game rules" 
<< endl;
cout << left << setw(11) << "quit" << left << setw(53) << "Exit program" 
<< endl;
cout << "------------------------------------------------------------" << endl;
}
	

/******************************************************************************
** Function: get_command()
** Description:	Prompts user to enter a command from the menu, reads input into 
			a string object and valdiates to ensure only "blinker", "glider", "gun", 
			"rules" or quit" are entered, and returns the string.
** Parameters: Does not contain parameters.
** Pre-Conditions: No arguments are passed into this function.
** Post-Conditions: A string which holds one of "blinker", "glider", 
			"gun", "rules" or quit" is returned.
******************************************************************************/
string get_command()
{
	string choice;
 	cout << endl << "Please enter a command from the menu above: ";
 	getline(cin,choice);
 	while (choice != "blinker" && choice != "beacon" && choice != "glider" && 
 	choice != "gun" && choice != "rules" && choice != "quit")
 	{  
 		cout << "Invalid selection. Please re-enter menu selection: ";
  	getline(cin,choice);
 	}
  return choice;
}


/******************************************************************************
** Function: validate_iterations()
** Description:	Prompts user to enter number of generations, reads input into 
			a Cstring, parses Cstring to ensure only numerical characters are 
			accepted, converts Cstring to an integer, validates to ensure only values 
			between 1 and 9999 (inclusive) are accepted, and returns the validated 
			int containing the number of generations of output desired.
** Parameters: Does not contain parameters.
** Pre-Conditions: No arguments are passed into this function.
** Post-Conditions: Only an integer containing a value between 1 and 9999
			(inclusive) is returned.
******************************************************************************/
int validate_iterations()
{
	char char_gen[50];
	//parse, then convert to int
	bool input_accepted = false, range_valid = false; //priming read
	int int_gen = 1;
	while(range_valid == false) 
	{ 
		do
	  { 
	  	cout << "    Please specify the number of generations: ";
			cin.getline(char_gen,50); 
	    for (int i=0; char_gen[i] != '\0'; i++)
	    { 
	    	if (char_gen[i] < 48 || char_gen[i] > 57)
	      { 
	      	input_accepted = false;
	        cout << "    Invalid number of generations." << endl;
	        break;
	      }
	      else
	      { 
	      	input_accepted = true;
	        continue;
	      }
	    }
	    if(input_accepted == true)
	      break;
	  } while (input_accepted == false);
	  if (input_accepted == true)
	    int_gen = atoi(char_gen);
		if (int_gen < 1 || int_gen > 9999)
	  {
	  	cout << "    Invalid number of generations (must be between 1 and 9999)." 
	  	<< endl;
	  	input_accepted = range_valid = false;
	  }
	  else 
	  	input_accepted = range_valid = true;
	}
	return int_gen;
}


/******************************************************************************
** Function: validate_seconds()
** Description:	Prompts user to enter a number of seconds for the time
			delay between generation output, reads input into a Cstring, parses 
			Cstring to ensure only numerical characters are accepted, converts 
			Cstring to an integer, validates to ensure only values between 1 and 
			10,000 (inclusive) are accepted, and returns the validated number of
			milliseconds of delay between generation output.
** Parameters: Does not contain parameters.
** Pre-Conditions: No arguments are passed into this function.
** Post-Conditions: Only an integer containing a value between 1 and 10,000
			(inclusive) is returned.
******************************************************************************/
int validate_seconds()
{
	char char_sec[50];
	//parse, then convert to int
	bool input_accepted = false, range_valid = false; //priming read
  int int_sec = 1;
  while(range_valid == false)
	{ 
		do
	  { 
	  	cout << "    Please specify the delay in seconds (range 1-10) between "
	  	"generation output." << endl; 
	  	cout << "        (For optimal viewing, the suggested seconds 1): ";
			cin.getline(char_sec,50); 
	    for (int i=0; char_sec[i] != '\0'; i++)
	    { 
	    	if (char_sec[i] < 48 || char_sec[i] > 57 || strlen(char_sec) > 4)
	      { 
	      	input_accepted = false;
	        cout << "    Invalid number of seconds." << endl;
	        break;
	      }
	      else
	      { 
	      	input_accepted = true;
	        continue;
	      }
	    }
	    if(input_accepted == true)
	      break;
	  } while (input_accepted == false);
	  if (input_accepted == true)
	    int_sec = atoi(char_sec);	
	  if (int_sec < 1 || int_sec > 10)
	  {
	  	cout << "    Invalid number of seconds (range 1-10)." << endl;
	  	input_accepted = range_valid = false;
	  }
	  else 
	  	input_accepted = range_valid = true;
	}	
	return int_sec;
}


/******************************************************************************
** Function: validate_starting row()
** Description:	Prompts user to enter the starting row for the pattern of 
			choice, reads input into a Cstring, parses Cstring to ensure only 
			numerical characters are accepted, converts Cstring to an integer.
			For the glider gun pattern, the function restricts the valid starting row
			to an integer between 1 and 14 in order to allow full view of the glider
			gun. For the other patterns, the user is able to enter starting rows betwee
			1 and 22. The function then returns starting row.
** Parameters: Does not contain parameters.
** Pre-Conditions: No arguments are passed into this function.
** Post-Conditions: Only an integer containing a value between 1 and 22 is 
			entered for patterns other than the glider gun, and only an integer
			containing a value between 1 and 14 is returned for the glider gun
			pattern.
******************************************************************************/
int validate_starting_row(string config)
{
	char char_row[50];
	//parse, then convert to int
	bool input_accepted = false, range_valid = false; //priming reads
	int int_row;
  while(range_valid == false)
	{ 
		do
	  { 
	  	if (config == "gun")
	  		cout << "    Please specify a starting row between 1 and 14 inclusive "
	  		"(to allow full view of glider gun): ";
	  	else 
	  		cout << "    Please specify a starting row between 1 and 22: ";
			cin.getline(char_row,50); 
	    for (int i=0; char_row[i] != '\0'; i++)
	    { 
	    	if (char_row[i] < 48 || char_row[i] > 57 || strlen(char_row) > 2)
	      { 
	      	input_accepted = false;
	        cout << "    INVALID starting row." << endl;
	        break;
	      }
	      else
	      { 
	      	input_accepted = true;
	        continue;
	      }
	    }
	    if(input_accepted == true)
	      break;
	  } while (input_accepted == false);
	  if (input_accepted == true)
	    int_row = atoi(char_row);	
		if (config == "gun")
		{
			if (int_row < 1 || int_row > 14)
		  {
		  	cout << "    INVALID starting row (must be between 1 and 14 to allow "
		  		"full view of glider gun)." 
		  	<< endl;
		  	input_accepted = range_valid = false;
		  }
		  else 
		  	input_accepted = range_valid = true;

		}
		else
		{  
		  if (int_row < 1 || int_row > 22)
		  {
		  	cout << "    INVALID starting row (must be between 1 and 22)." 
		  	<< endl;
		  	input_accepted = range_valid = false;
		  }
		  else 
		  	input_accepted = range_valid = true;
		}
	}	
	return int_row;
}


/******************************************************************************
** Function: validate_starting col()
** Description:	Prompts user to enter the starting column for the pattern of 
			choice, reads input into a Cstring, parses Cstring to ensure only 
			numerical characters are accepted, converts Cstring to an integer.
			For the glider gun pattern, the function restricts the valid starting 
			column to an integer between 25 and 69 in order to allow full view of 
			the glider gun. For the other patterns, the user is able to enter 
			starting columns between 1 and 80. The function then returns starting 
			column.
** Parameters: Does not contain parameters.
** Pre-Conditions: No arguments are passed into this function.
** Post-Conditions: Only an integer containing a value between 1 and 80 is 
			entered for patterns other than the glider gun, and only an integer
			containing a value between 25 and 69 is returned for the glider gun
			pattern.
******************************************************************************/
int validate_starting_col(string config)
{
	char char_col[50];
	//parse, then convert to int
	bool input_accepted = false, range_valid = false; //priming reads
	int int_col;
  while(range_valid == false)
	{ 
		do
	  { 
	  	if (config == "gun")
	  		cout << "    Please specify a starting column between 25 and 69 "
	  		"inclusive (to allow full view of glider gun): ";
	  	else 	
	  		cout << "    Please specify a starting column between 1 and 80: ";
			cin.getline(char_col,50); 
	    for (int i=0; char_col[i] != '\0'; i++)
	    { 
	    	if (char_col[i] < 48 || char_col[i] > 57 || strlen(char_col) > 2)
	      { 
	      	input_accepted = false;
	        cout << "    INVALID starting column." << endl;
	        break;
	      }
	      else
	      { 
	      	input_accepted = true;
	        continue;
	      }
	    }
	    if(input_accepted == true)
	      break;
	  } while (input_accepted == false);
	  if (input_accepted == true)
	    int_col = atoi(char_col);	
		if (config == "gun")
		{
			if (int_col < 25 || int_col > 69)
		  {
		  	cout << "    INVALID starting column (must be between 1 and 45 to "
		  		"allow full view of glider gun)." 
		  	<< endl;
		  	input_accepted = range_valid = false;
		  }
		  else 
		  	input_accepted = range_valid = true;
		}  
		else
		{	
		  if (int_col < 1 || int_col > 80)
		  {
		  	cout << "    INVALID starting column (must be between 1 and 80)." 
		  	<< endl;
		  	input_accepted = range_valid = false;
		  }
		  else 
		  	input_accepted = range_valid = true;
		}
	}	
	return int_col;	
}