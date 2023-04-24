# G6 Graphics Library
G6Graphics is an free-to-use and open source library useful for novice programmers to visualize data they are trying to learn. Data like arrays and operations like sorts are examples of things users can visualize using our library. 

# Who We Are
The G6Graphics team is a group of 4 undergrad students tasked with creating this library in a Software Engineering course. The team consists of (in alphabetical order by last name) Joseph Angelo, Slava Borysyuk, Frank Louie, and Jackson Haverly. Design and development of the G6Graphics Library took place over the course of the Spring 2023 semester, and is as such, a work in progress. 

# Uses / Applications
A beginner in programming may be interested in seeing exactly how a sort they have written is occurring within the array they are sorting. Perhaps this programmer is brand new in the world of computing, and they would like to see their array visualized as a bar graph or an indexed grid. These are the kinds of things our library aims to assist with.

# Tools and Practices
To develop the G6Graphics Library, our team utilized a graphical library known as TiGr (TIny GRaphics Library https://github.com/erkkah/tigr ) to build our outputs to the user. We worked primarily in C / C++ in various IDE's, Visual Studio Code being the most used. 

# How To Use G6
1. Install the G6Graphics.zip folder
2. Extract files into your project
3. In your project, write "#include 'G6Graphics.h' " at the top of your file
4. In your linker settings write the following
a. Windows: '-lopengl32' and '-lgdi32'
b. MacOS: '-framework OpenGL' and '-framework Cocoa'
c. Linux: '-lGL' and '-lx11'
5. Use function of choice in your code (reference product documentation for detailed use)
6. Profit


# Function List 
1. G6ArrayDisplay()
a. This function prints an array of integers as an indexed grid
2. G6BarGraph()
a. This function displays an array of integers as a bar graph
3. G6Help()
a. This function prints general help tips to the terminal
4. G6SortVis()
a. This function displays an array through different stages of a user defined sort

All functions further described in product documentation 

# Disclaimer
The G6Graphics Library is free-to-use and open source. It is provided  "as-is" without warranty of any kind. If any problems arise, feel free to contact us at g6graphics23@gmail.com