/******************************************************************************
 * Program Filename: functions.h
 * Author: Kelvin Watson (OSU ID 932540242)
 * Date: 11 January, 2015
 * Description: (Assignment 1, CS 162) Interface for functions.cpp. 
 					Contains prototypes for functions implemented in functions.cpp and 
 					called in main().
 * Output: See functions.cpp for output.         
 *****************************************************************************/
#ifndef WATSOKEL_FUNCTIONS_H
#define WATSOKEL_FUNCTIONS_H
#include <string>
using std::string;

void show_intro_rules();
void show_options();
string get_command();
void get_rules();
int validate_iterations();
int validate_seconds();
int validate_starting_row(string);
int validate_starting_col(string);
 
#endif