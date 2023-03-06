/*
    G6Graphics Visualization Library
    --------------------------------

    Authors     : Joseph Angelo, Slava Borysyuk, Jackson Haverly, Frank Louie


    Description : G6Graphics is intended to be a data/processes visualization library for Computer Science students
                  at the freshman level to understand data types, structures, and processes they are
                  trying to learn. To use G6Graphics, simply place the included files into your project directory,
                  #include the G6Graphics.h file in your code, and begin using the functions as desired.


    Notes       : G6Graphics builds upon the existing TiGr library available at (https://github.com/erkkah/tigr).

*/

//a basic menu the user can call to get information about our functions
void G6Help();

//displays an array passed to the function as well as the indexes of values
int G6ArrayDisplay(int *userArray, int arrSize);

//displays an array passed to the function as an indexed bar graph (values must be between 0 -20)
void G6BarGraph(int userAry[], int arySize);
