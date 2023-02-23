/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <golBasicTypes.h>
#include <golExceptionMacro.h>
#include <golMyFunctions.h>
#include <iostream>
#include <string>
#include <stdexcept>

/* The app should be run as ./build/bin/gof_simulator *typeOfInput*
*argumentsInput* *nGenerations* *-h*, where: *typeInput* is 0 or 1: if 0 then
the program will expect a file from which it will read the input. If 1, it will
expect a random initialisation of the grid *argumentsInput* are the arguments
depending on the choice made in *typeInput*. Specifically:
    - if *typeInput* == 0, then *argumentsInput* should be a string
*nameFile.txt*
    - if *typeInput* == 1, then *argumentsInput* should expect 3 numbers
*numRows*, *numColumns* and *aliveCell*, which will be passed to the random
constructor *nGenerations* is the number of generations to simulate with
takeStep()
  *-h* is a facultative argument that will redirect to an help section (If the
number *nGenerations* is not specified we should also be redirected to an help
section) */

int main(int argc, char **argv) {
  try {
    std::string inputMethod = argv[1];
    std::vector<int> argumentsRandom {};
    std::string iterationsToInt = "null";
    std::string helpString = argv[argc - 1];
    if (argc == 1 || helpString == "-h") {
      /* Help message */

      std::cout << "Please launch the app from terminal with the following "
                   "prompt:\n\n./build/bin/gof_simulator *typeOfInput* "
                   "*argumentsInput* *nGenerations* *-h*\n\nThe arguments have "
                   "the following meaning:\n"
                   "-> *typeInput* is 'file' or 'random':\n"
                   "   -> if 'file' the program will expect a file in input, "
                   "where it will read the initial grid\n"
                   "   -> If 'random', it will expect a random initialisation "
                   "of the grid\n\n"
                   "-> *argumentsInput* are the arguments depending on the "
                   "choice made in *typeInput*. Specifically:\n"
                   "   -> if *typeInput* == 0, then *argumentsInput* should be "
                   "a string *nameFile.txt*\n"
                   "   -> if *typeInput* == 1, then *argumentsInput* should "
                   "expect 3 numbers *numRows*, *numColumns* and *aliveCell*, "
                   "which will be passed to the random constructor\n\n"
                   "-> *nGenerations* is the number of generations to simulate "
                   "with takeStep()\n\n"
                   "-> *-h* will let you read this message again\n"
                << std::endl;
      return 1;
    }
    if (inputMethod == "file") {
      /* Here the program initializes the grid from file */

      if (argc < 3) {
        /* If the number of arguments is lower than 3, then the name of the file
         * is missing */

        std::cout << "\nThe name of the file is missing! Please try again.\n"
                  << std::endl;
        return 1;
      } else {
        std::string fileInput = argv[2];
        gol::grid initialGrid(fileInput);
        gol::game gameToPlay(initialGrid);

        /* Four arguments are expected for the program to run if it reads from file */

        if (argc == 4) {
          iterationsToInt = argv[3];
          int iterations = std::stoi(iterationsToInt);
          gameOfLife(gameToPlay, initialGrid, iterations);
        } else {
          std::cout << "\nError in calling the program: number of arguments in "
                       "command line is different than expected\n"
                    << std::endl;
          return 1;
        }
      }
    } else if (inputMethod == "random") {
      /* Here we initializes the grid with the random constructor */

      if (argc < 6) {

        /* If argc < 6, some initial parameters are missing */

        std::cout << "\nToo few arguments! Please launch -h as last argument to "
                     "see how you should use the random constructor.\n"
                  << std::endl;
        return 1;
      } else {
        std::string rowToInt = argv[2];
        int row = std::stoi(rowToInt);
        std::string columnToInt = argv[3];
        int column = std::stoi(columnToInt);
        std::string aliveCellToInt = argv[4];
        int aliveCell = std::stoi(aliveCellToInt);
        iterationsToInt = argv[5];
        int iterations = std::stoi(iterationsToInt);
        gol::grid initialGrid(row, column, aliveCell);
        gol::game gameToPlay(initialGrid);

        /* 6 is the correct number of parameters if we use the random grid */

        if (argc == 6) {
          gameOfLife(gameToPlay, initialGrid, iterations);
        } else {
          std::cout << "\nToo many arguments! Please launch -h as last argument to see how you should use the random constructor.\n" << std::endl;
          return 1;
        }
      }
    } else {
      /* Error in specifying the type of input */

      std::cout << "\nType of input selected not correct! Retry.\n" << std::endl;
      return 1;
    }
    std::cout << "\nEnd of the game\n" << std::endl;
    return 0;
  } catch (std::logic_error e) {
    std::cout << e.what() << std::endl;
  } catch (std::runtime_error e) {
    std::cout << e.what() << std::endl;
  }

}

/*int returnStatus = EXIT_FAILURE;

  try
  {
    throw std::runtime_error("Something went wrong!");

    returnStatus = EXIT_SUCCESS;
  }
  catch (gol::Exception& e)
  {
    std::cerr << "Caught gol::Exception: " << e.GetDescription() << std::endl;
  }
  catch (std::exception& e)
  {
    std::cerr << "Caught std::exception: " << e.what() << std::endl;
  }

  return returnStatus;*/