[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-f4981d0f882b2a3f0472912d15f9806d57e124e0fc890972558857b51b24a6f9.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=10034516)
PHAS0100ASSIGNMENT1
------------------

Purpose
-------

This project serves as a starting point for the PHAS0100 2022/23 Assignment 1 Game of Life Simulation coursework. It has a reasonable folder structure for [CMake](https://cmake.org/) based projects that use [CTest](https://cmake.org/) to run unit tests via [Catch](https://github.com/catchorg/Catch2). 

Further information on the specific project is left as an exercise for the student.

Credits
-------

This project is maintained by [Dr. Jamie Quinn](http://jamiejquinn.com/). It is based on [CMakeCatch2](https://github.com/UCL/CMakeCatch2.git) that was originally developed as a teaching aid for UCL's ["Research Computing with C++"](https://github-pages.ucl.ac.uk/research-computing-with-cpp/) course developed by [Dr. James Hetherington](http://www.ucl.ac.uk/research-it-services/people/james) and [Dr. Matt Clarkson](https://iris.ucl.ac.uk/iris/browse/profile?upi=MJCLA42).

Build Instructions
------------------

To run cmake:

```
cmake -B build
```

To compile:

```
cmake --build build
```

To test:

```
cd build
ctest
```

Additional build and running instructions left to the student.


------------------------------------------------------------------------- READ HERE -------------------------------------------------------------------------------------------------------

I have created two executable files to use in this assignment:

- The first one is golSimulator, and it run the game of life, having taken in input the right arguments. It can create the initial grid by reading it from file or by creating it randomly. In particular:
    - If one wants to create the grid by file, the following command should be used:
        ./build/bin/golSimulator file run <name of file> <number of iterations>
        (if one runs ./build/bin/golSimulator file run <name of file> <number of iterations> -h, an help message should be displayed)
    - If one wants to create the grid randomly, the following command should be used:
        ./build/bin/golSimulator random <number of rows> <number of columns> <number of alive cells to put in the grid> <number of iterations>
        (if one runs ./build/bin/golSimulator random <number of rows> <number of columns> <number of alive cells to put in the grid> <number of iterations> -h, an help message should be displayed)
    - If one runs ./golSimulator, an help message should be displayed
    - If one calls the program in an unintended way, an error message should be displayed.
   golSimulator should give an output like this:

    -> The initial grid is the following one
    ->  <grid>
    -> Next step
    ->  <grid>
    -> Next step
    ->  <grid>
    ...
    -> End of the game

- The second one is golstationaryPatterns, it searches for game of life patterns that remain the same after an evolution. The program should be called in this way:

    ./build/bin/golStationaryPatterns <number of rows> <number of columns> <number of alive cells to put in the grid> <number of iterations>
    (if one runs ./build/bin/golStationaryPatterns <number of rows> <number of columns> <number of alive cells to put in the grid> <number of iterations> -h, an help message should be displayed)

    This program creates grids to test with the dimensions specified in the arguments, and it let them evolve for the number of iterations requested in the argument line. If at the end of the evolution the grid has not displayed any still life/pattern, the grid is re-initialised randomly and in the same way the object of the class game is then re-initialised.
    The program stops when a still life pattern is found, and it prints it to the screen in this way:

    -> We have found a stationary pattern!
    -> <grid>
    -> End of the game

    There is a limit in the time of execution of the program set to 60 seconds: after this time has passed, an error message will be displayed. This has been implemented to avoid infinite loops for impossible stationary patterns requested.

The requested screenshots can be found in the folder test/data/ScreenshotsGol. There are many still lives that we can find in a 4x4 grid, some of them have been captured in the screenshots.

The testing can be done with ctest under the folder build. We have tested the functions as required in the assignment, in particular:
    - In golCommandLineArgsTest.cpp we have tested the initialisation of the grids with the arguments passed by command line, and they are:
        - Initialisation of the random grid
        - Initialisation of the grid read by file
        - Tested the randomness of the generation of the grid
    - In golBasicTest we have tested:
        - The function getGridElement()
        - The function fetchNeighbours()
        - the function takeStep()

Additional comment on the construction of the program can be found in the .h and .cpp files.

We have found many still patterns in a 4x4 grid, including:
    - the square-blocks of 4 alive cells (they can be 9 in a 4x4 grid), e.g.

    - - - -
    o o - - 
    o o - -
    - - - - 

    - the hexagon-like patterns (they can be 4 in a 4x4 grid), e.g.

    - o - - 
    o - o - 
    o - o - 
    - o - -

    - the octagon

    - o o - 
    o - - o   
    o - - o 
    - o o - 

    - strange-shaped patterns, e.g. (hard to predict how many of them there could be)

    - - - - 
    - - o - 
    - o - o 
    - - o o 

    Some of these patterns are available in the ScreenshotGol folder.