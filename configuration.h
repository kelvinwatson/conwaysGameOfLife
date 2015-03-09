/******************************************************************************
 * Program Filename: configuration.h
 * Author: Kelvin Watson (OSU ID 932540242)
 * Date: 11 January, 2015
 * Description: (Assignment 1, CS 162) Interface for configuration.cpp. 
 					Contains the declaration for the configuration class, with member
 					variables (attributes) and member functions (behaviors).
 * Output: See configuration.cpp for output.         
 *****************************************************************************/

#ifndef WATSOKEL_CONFIGURATION_H
#define WATSOKEL_CONFIGURATION_H

#include <string>

#ifndef ROWS 
#define ROWS 26
#endif

#ifndef COLS 
#define COLS 84
#endif

#ifndef NUM_COORDINATES_BLINKER  
#define NUM_COORDINATES_BLINKER 3
#endif

#ifndef NUM_COORDINATES_GLIDER 
#define NUM_COORDINATES_GLIDER 5
#endif

#ifndef NUM_COORDINATES_GUN 
#define NUM_COORDINATES_GUN 36
#endif

class configuration
{
private:
	char grid[ROWS][COLS];
	char grid2[ROWS][COLS];				//changes from grid copied to grid2
	int starting_row, starting_col;					//user's starting coordinates
	int actual_starting_row, actual_starting_col;	//includes ghost rows/cols
	int num_coordinates;
	clock_t seconds; 							//for delay
	int generations; 							//number of generations to iterate
	string pattern;
	static const int ACTUAL_MIN_ROW;
	static const int ACTUAL_MAX_ROW; 
	static const int ACTUAL_MIN_COL;
	static const int ACTUAL_MAX_COL;
public:
	configuration();									//default constructor
	configuration(int, int, int, clock_t, int, string);
	void set_seconds(clock_t);
	void clear_grid();
	void clear_grid2();
	void set_live_cells();								//set initial configuration
	int get_neighbors(char [][COLS], int, int);
	void print_grid();
	void time_delay();
	int get_neighbors(int,int);
	void copy_grid();
	string get_proceed();
	void set_generations();
	void algorithm();
};

#endif