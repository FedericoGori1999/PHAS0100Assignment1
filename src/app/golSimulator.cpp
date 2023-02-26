/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <golBasicClasses.h>
#include <golExceptionMacro.h>
#include <golBasicFunctions.h>
#include <iostream>
#include <stdexcept>
#include <string>

int main(int argc, char **argv) {
  int returnStatus = EXIT_FAILURE;
  try {
    std::string inputMethod = "null";
    std::vector<int> argumentsRandom{};
    std::string iterationsToInt = "null";
    std::string helpString = argv[argc - 1];
    if(argc > 1)
    {
      inputMethod = argv[1];
      //helpString = argv[argc - 1];
    }
    if (argc == 1 || helpString == "-h" || inputMethod == "file" && argc != 4 || inputMethod == "random" && argc != 6 || inputMethod != "file" && inputMethod != "random") {
      throw gol::ExceptionGolSimulator(argc, inputMethod, helpString);
    }
    if (inputMethod == "file") {

      /* Here the program initializes the grid from file */

      std::string fileInput = argv[2];
      gol::grid initialGrid(fileInput);
      gol::game gameToPlay(initialGrid);
      iterationsToInt = argv[3];
      int iterations = std::stoi(iterationsToInt);
      if(iterations == 0)
      {
        throw gol::ExceptionGame(iterations);
      }
      gameOfLife(gameToPlay, initialGrid, iterations);
        
      
    } else if (inputMethod == "random") {
      
      /* Here we initializes the grid with the random constructor */

    std::string rowToInt = argv[2];
    int rows = std::stoi(rowToInt);
    std::string columnToInt = argv[3];
    int columns = std::stoi(columnToInt);
    std::string aliveCellsToInt = argv[4];
    int aliveCells = std::stoi(aliveCellsToInt);
    iterationsToInt = argv[5];
    int iterations = std::stoi(iterationsToInt);
    if(iterations == 0)
      {
        throw gol::ExceptionGame(iterations);
      }
    if(rows == 0 || columns == 0 || iterations == 0)
    {
      throw gol::ExceptionGrid(rows, columns, aliveCells);
    }
    gol::grid initialGrid(rows, columns, aliveCells);
    gol::game gameToPlay(initialGrid);
    gameOfLife(gameToPlay, initialGrid, iterations);
    } 
    std::cout << "\nEnd of the game\n" << std::endl;
    returnStatus = EXIT_SUCCESS;
  } catch (gol::ExceptionGolSimulator e) {
    std::cout << e.whatProblem() << std::endl;
  } catch (gol::ExceptionGrid e)
  {
    std::cout << e.whatProblem() << std::endl;
  } catch (gol::ExceptionGame e)
  {
    std::cout << e.whatProblem() << std::endl;
  }
  return returnStatus;
}

/* To implement: searching for still lives and manage exceptions */

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