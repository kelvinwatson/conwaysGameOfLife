# Conway's Game of Life
Description: Implementation of Conway's Game of Life using  static 2-dimensional arrays. Ghost cells enable the illusion of an infinite grid as the program prints oscillating (blinker and beacon), and glider and glider gun (cannon) patterns/configurations, incorporating user-defined time delays to show the different frames.

##Design Features
- two rows and ghost cells and two columns of ghost cells line each edge of the display field which allow the inner cells to behave according to the Game of life rules and project the illusion of an infinite grid
- constrains the user-defined coordinates for the glider gun configuration to allow full view of the gun portion
- validates user's starting coordinates by parsing C-strings
- use the atoi() function to convert char’s to int’s
- incorporates time delays between each "frame" using clock_t
- determines which cells are “live” or “dead” after each generation depending on the states of the cells in the previous generation, update the cells, and prints the results to the console

##Citations
1. http://www.cplusplus.com/reference/ctime/clock/
2. http://www.cplusplus.com/forum/unices/10491/
3. http://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
4. http://www.tech.org/~stuart/life/rules.html
5. http://www.conwaylife.com/wiki/Gun
6. http://www.cs.umd.edu/class/fall2002/cmsc214/Tutorial/makefile.html
