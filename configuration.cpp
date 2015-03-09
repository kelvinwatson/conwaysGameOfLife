/******************************************************************************
** Program Filename: configuration.cpp
** Author: Kelvin Watson (OSU ID 932540242)
** Date: 11 January, 2015
** Description: (Assignment 1, CS 162) Implementation file for configuration
**				 class. Contains the definitions for static member variables, and 
					 class functions declared in configuration.h.
** Input:  Some configuration class member functions require/accept input. See
					 individual member functions. 
** Output: See individual member function definitions below.         
******************************************************************************/

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

#include "configuration.h"
#include <ctime>

#ifndef ROWS 
#define ROWS 26 //26 ROWS, row 0-25
#endif

#ifndef COLS 
#define COLS 84 //84 COLS, col 0-83
#endif

const int configuration::ACTUAL_MIN_ROW = 2;
const int configuration::ACTUAL_MAX_ROW = 23;
const int configuration::ACTUAL_MIN_COL = 2;
const int configuration::ACTUAL_MAX_COL = 81;

/******************************************************************************
** Function: configuration::configuration()
** Description:	Default constructor for configuration class.
** Parameters:	No parameters.
** Pre-Conditions: Object must be declared, and of the configuration class.
** Post-Conditions: All grid (member array) elements are assigned ASCII of 32.
******************************************************************************/
configuration::configuration()	
{	
	clear_grid();	
}


/******************************************************************************
** Function: configuration::configuration(int,int,int,clock_t,int,string)
** Description:	Constructor for configuration class, which initializes member
			variables, and calls the clear_grid(), clear_grid2(), and 
			set_live_cells() function.
** Parameters: This function has six parameters. The starting row, starting 
			column, number of live cells (coordinates), time-delay in milliseconds,
			number of generations, and the desired pattern.  
** Pre-Conditions: Object of the configuration class must be declared, six 
			arguments of the correct data types in the correct order must be passed
			into this constructor.
** Post-Conditions: Member variables are initialized, actual_starting_row and
			actual_starting_col are calculated, and the clear_grid(), clear_grid2() 
			and set_live_cells() functions are called and executed.
******************************************************************************/
configuration::configuration(int starting_row, int starting_col, int num_coordinates,
														clock_t seconds, int generations, string pattern)
{
	clear_grid();
	clear_grid2();
	this->starting_row = starting_row;
	this->starting_col = starting_col;
	this->num_coordinates = num_coordinates;
	this->seconds = seconds;
	this->generations = generations;
	this->pattern = pattern;
	actual_starting_row = starting_row + 1;
	actual_starting_col = starting_col + 1;
	cout << "IND: starting_row=" << starting_row << " starting_col=" << starting_col <<
	" num_coordinates=" << num_coordinates << " seconds=" << seconds << 
	" generations=" << generations << " pattern=" << pattern << endl;
	set_live_cells();
}


/******************************************************************************
** Function: configuration::clear_grid()
** Description:	Assigns the <SPACE> character ' ' (i.e. ASCII 32) to each 
			element/cell of the member 2D array named grid.
** Parameters: This function does not contain parameters.  
** Pre-Conditions: Member grid must be declared with the constants ROWS and 
			COLS.
** Post-Conditions: Each element of the grid 2D array is assigned the char ' '.
******************************************************************************/
void configuration::clear_grid()
{
	for (int row = 0; row < ROWS; row++)
 	{
 		for (int col = 0; col < COLS; col++)
 		{
 			grid[row][col] = ' '; //ASCII 32 is <SPACE>
 		}
 	}
}


/******************************************************************************
** Function: configuration::clear_grid2()
** Description:	Assigns the <SPACE> character ' ' (i.e. ASCII 32) to each 
			element/cell of the member 2D array named grid.
** Parameters: This function does not contain parameters.  
** Pre-Conditions: Member grid must be declared with the constants ROWS and 
			COLS.
** Post-Conditions: Each element of the grid 2D array is assigned the char ' '.
******************************************************************************/
void configuration::clear_grid2()
{
	for (int row = 0; row < ROWS; row++)
 	{
 		for (int col = 0; col < COLS; col++)
 		{
 			//cout << "row: " << row << "col: " << col << endl;
 			grid2[row][col] = ' ';
 		}
 	}
}


/******************************************************************************
** Function: configuration::set_live_cells()
** Description:	Assigns elements of the member array grid with the asterisk char
			according to the user-specified pattern. The result is the initial 
			pattern of either the blinker, glider or gun.
** Parameters: This function does not contain parameters.  
** Pre-Conditions: The member variables pattern, actual_starting_row and 
			actual_starting_col must be assigned and valid. 
** Post-Conditions: The specified elements of the grid are assigned a '*', 
			resulting in an initial pattern of either the blinker, glider or gun.
******************************************************************************/
void configuration::set_live_cells()
{
	if (pattern == "blinker") //blinker
	{
		grid[actual_starting_row][actual_starting_col] = '*';
		grid[actual_starting_row][actual_starting_col+1] = '*';
		grid[actual_starting_row][actual_starting_col+2] = '*';
	}
	else if (pattern == "beacon")
	{
		grid[actual_starting_row][actual_starting_col] = '*';
		grid[actual_starting_row+1][actual_starting_col] = '*';
		grid[actual_starting_row][actual_starting_col+1] = '*';
		grid[actual_starting_row+3][actual_starting_col+2] = '*';
		grid[actual_starting_row+2][actual_starting_col+3] = '*';
		grid[actual_starting_row+3][actual_starting_col+3] = '*';
	}
	else if (pattern == "glider")
	{
		grid[actual_starting_row][actual_starting_col] = '*';
		grid[actual_starting_row+1][actual_starting_col+1] = '*';
		grid[actual_starting_row+1][actual_starting_col+2] = '*';
		grid[actual_starting_row+2][actual_starting_col] = '*';
		grid[actual_starting_row+2][actual_starting_col+1] = '*';
	}
	else if (pattern == "gun")
	{
		grid[actual_starting_row][actual_starting_col] = '*';
		grid[actual_starting_row+1][actual_starting_col] = '*';
		grid[actual_starting_row+1][actual_starting_col-2] = '*';
		grid[actual_starting_row+5][actual_starting_col] = '*';
		grid[actual_starting_row+6][actual_starting_col] = '*';
		grid[actual_starting_row+2][actual_starting_col-3] = '*';
		grid[actual_starting_row+2][actual_starting_col-4] = '*';
		grid[actual_starting_row+3][actual_starting_col-4] = '*';
		grid[actual_starting_row+3][actual_starting_col-3] = '*';
		grid[actual_starting_row+4][actual_starting_col-3] = '*';
		grid[actual_starting_row+4][actual_starting_col-4] = '*';
		grid[actual_starting_row+5][actual_starting_col-2] = '*';
		grid[actual_starting_row+2][actual_starting_col+10] = '*';
		grid[actual_starting_row+3][actual_starting_col+10] = '*';
		grid[actual_starting_row+2][actual_starting_col+11] = '*';
		grid[actual_starting_row+3][actual_starting_col+11] = '*';
		grid[actual_starting_row+5][actual_starting_col-7] = '*';
		grid[actual_starting_row+4][actual_starting_col-8] = '*';
		grid[actual_starting_row+5][actual_starting_col-8] = '*';
		grid[actual_starting_row+6][actual_starting_col-8] = '*';
		grid[actual_starting_row+3][actual_starting_col-9] = '*';
		grid[actual_starting_row+7][actual_starting_col-9] = '*';
		grid[actual_starting_row+5][actual_starting_col-10] = '*';
		grid[actual_starting_row+2][actual_starting_col-11] = '*';
		grid[actual_starting_row+8][actual_starting_col-11] = '*';
		grid[actual_starting_row+2][actual_starting_col-12] = '*';
		grid[actual_starting_row+8][actual_starting_col-12] = '*';
		grid[actual_starting_row+3][actual_starting_col-13] = '*';
		grid[actual_starting_row+7][actual_starting_col-13] = '*';
		grid[actual_starting_row+4][actual_starting_col-14] = '*';
		grid[actual_starting_row+5][actual_starting_col-14] = '*';
		grid[actual_starting_row+6][actual_starting_col-14] = '*';
		grid[actual_starting_row+4][actual_starting_col-23] = '*';
		grid[actual_starting_row+5][actual_starting_col-23] = '*';
		grid[actual_starting_row+4][actual_starting_col-24] = '*';
		grid[actual_starting_row+5][actual_starting_col-24] = '*';
	}
	print_grid();
	algorithm();
}


/******************************************************************************
** Function: configuration::print_grid()
** Description:	Displays current grid configuration to the console. The grid's
			border is assigned the character 'G' to indicate that it is a ghost cell.
			The remaining inner cells' contents are displayed to the console. The
			resulting display consists of a 80x22 inner grid with two additional rows 
			and columns on each edge.
** Parameters: This function does not contain parameters.  
** Pre-Conditions: The grid must be defined with the constants ROWS and COLS. 
** Post-Conditions: The display consists of a 80x22 inner grid with two 
			additional rows and columns on each edge. No modifications are made to
			the grid.
******************************************************************************/
void configuration::print_grid()
{
	cout << endl;
	system("clear");
	for(int row = 0; row < ROWS; row++)
	 {
	 	for (int col = 0; col < COLS; col++)
	 	{
			if ((row == 0) || (row == 1) || (row == 24) || (row == 25) || (col == 0) || (col == 1) || (col == 82) || (col == 83)  )
				cout << 'G';
			else 
				cout << grid[row][col];
	 	}	
	 	cout << endl;
	 }
}


/******************************************************************************
** Function: configuration::time_delay()
** Description:	Causes a delay by a user-specified number of milliseconds
** Parameters: This function does not contain parameters.  
** Pre-Conditions: The member variable milliseconds must be initialized on
			class instantiation. The header <ctime> must also be included.   
** Post-Conditions: The clock() time must be reached in order to exit the 
			function. No variables are modified. 
******************************************************************************/
void configuration::time_delay()
{
	clock_t start = clock();
	clock_t end = seconds*CLOCKS_PER_SEC + start;
	while(clock() < end); //while (clock!=end)
}


/******************************************************************************
** Function: configuration::get_neighbors()
** Description:	Increments the count variable for each asterisk char found in
			neighboring cells.
** Parameters: This function has to int parameters, one for a row, and one for
			a column.  
** Pre-Conditions: A valid row and column from grid must be passed as arguments
			to this function.   
** Post-Conditions: Count must be 0 or a positive integer. 
******************************************************************************/
int configuration::get_neighbors(int r, int c)
{	
	int count = 0;
	if (grid[r][c-1] == '*') 
		count++;
	if (grid[r][c+1] == '*') 
		count++;
	if (grid[r-1][c] == '*') 
		count++;
	if (grid[r+1][c] == '*') 
		count++;
	if (grid[r-1][c-1] == '*') 
		count++;
	if (grid[r+1][c+1] == '*') 
		count++;
	if (grid[r-1][c+1] == '*') 
		count++;
	if (grid[r+1][c-1] == '*') 
		count++;
	//cout << " are executed @ r" << r << " c" << c << " total*count=" << count << endl;
	return count;	
}


/******************************************************************************
** Function: configuration::copy_grid()
** Description:	Copies values in the 2D array grid2, to the 2D array grid1.
** Parameters: This function contains no parameters.  
** Pre-Conditions: grid and grid2 must be created by the class constructor on
			class instantiation.   
** Post-Conditions: The contents of grid must be the same as the contents of
			grid2. 
******************************************************************************/
void configuration::copy_grid()
{
	clear_grid();
	for (int row = 0; row < ROWS; row++)
 	{
 		for (int col = 0; col < COLS; col++)
 		{
 			grid[row][col] = grid2[row][col];
 		}
 	}
}


/******************************************************************************
** Function: configuration::get_proceed()
** Description:	Prompts for, validates, and returns a user-inputted string 
			(either "Y", "y" or "stop").
** Parameters: No parameters.  
** Pre-Conditions: Before calling the function, a variable must be declared to
			hold this function's returned value.   
** Post-Conditions: The value of the string object, forward, must be either
			"Y", "y" or "stop".
******************************************************************************/
string configuration::get_proceed()
{
	string forward;
 	cout << endl << "    Enter \"Y\" or \"y\" to continue iterations, or enter \"stop\" "
 	"to stop iterations and return to the main menu: ";
 	getline(cin,forward);
 	while ((forward != "Y") && (forward != "y") && (forward != "stop"))
 	{  
 		cout << "    Invalid input. Please enter either \"Y\" to continue iterations, or enter \"stop\" "
 		"to stop iterations and return to the main menu: ";
  	getline(cin,forward);
 	}
  return forward;
}

/******************************************************************************
** Function: configuration::set_generations()
** Description:	This is a mutator function which prompts for, and validates 
			user input. User input is read into a Cstyle string, which is then parsed 
			to ensure only numerical characters are entered. The Cstring is then 
			converted to an integer using atoi(), and the resulting integer is 
			subsequently validated to ensure that it is within the range 1-9999. If 
			not, the while loop iterates again until the user enters a valid integer 
			between 1-9999. Otherwise, the value is assigned to the generations 
			member variable.
** Parameters: No parameters.  
** Pre-Conditions: The member variable generations must be created by the 
			constructor before this function is called. The <cstring> header file
			is required for this function.  
** Post-Conditions: The value of the string object, forward, must be either
			"Y", "y" or "stop".
******************************************************************************/
void configuration::set_generations()
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
	generations = int_gen;
}


/******************************************************************************
** Function: configuration::algorithm()
** Description:	This function assigns values to the elements of grid2 depending 
			on the values held by neighboring cells. The reason why a second 2D array 
			(grid2) is used is to ensure that all values from grid2 are copied to the 
			first 2D array (grid) at the same time using copy_grid, as opposed to 
			being implemented while the rows and columns in grid are still being 
			checked by get_neighbors(), which could alter the values of cells in grid
			that have not yet been checked by get_neighbors(). 
** Parameters: No parameters.  
** Pre-Conditions: get_neighbours(), copy_grid(), print_grid(), clear_grid2(), 
			time_delay(), set_proceed() and set_generations() must be defined at 
			class instantiation.  
** Post-Conditions: Values in grid2 must be copied to grid1, grid must be 
			printed for each generation, and get_proceed() must either return "Y", 
			"y" (in which case generations is reset/mutated), or "stop" (in which 
			case control returns to set_live_cells(), which is immediately exited).
******************************************************************************/
void configuration::algorithm()
{
	int live_neighbors = 0;
	string proceed = "Y";
	do
	{
		for (int g = 0; g < generations; g++)
		{
			for (int row = 0; row < ROWS; row++)
			{
				for (int col = 0; col < COLS; col++)
				{	
					if (grid[row][col] == '*') 
					{	
						live_neighbors = get_neighbors(row, col);
						if ((live_neighbors < 2) || (live_neighbors > 3)) 
							grid2[row][col] = ' ';
						else if ((live_neighbors == 2) || (live_neighbors == 3)) 
							grid2[row][col] = '*'; 
					}
					if (grid[row][col] == ' ') 
					{	
						live_neighbors = get_neighbors(row, col);
						if (live_neighbors == 3) 
							grid2[row][col] = '*';
						else if (live_neighbors != 3) 
							grid2[row][col] = ' ';	
					}
				}	
			}
			copy_grid();
			print_grid();
			clear_grid2();
			time_delay();
		}		
		cout << endl << "Generations complete. Would you like to continue "
		"iterating the current pattern (" << pattern << " at " << seconds << "s delay)? ";
		proceed = get_proceed();
		if (proceed == "Y" || proceed == "y")
			set_generations();
		else
			break;
	} while (proceed == "Y" || proceed == "y");
}