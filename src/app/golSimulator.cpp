/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <golGameClass.h>
#include <golExceptionMacro.h>
#include <golFunctions.h>


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
    }
    if (argc == 1 || helpString == "-h" || inputMethod == "file" && argc != 5 || inputMethod == "random" && argc != 6 || inputMethod != "file" && inputMethod != "random") {
      throw gol::ExceptionGolSimulator(argc, inputMethod, helpString);
    }
    if (inputMethod == "file") {

      /* Here the program initializes the grid from file */

      std::string runCommand = argv[2];
      if(runCommand == "test")
      {
        std::cout << "\nYou cannot call 'test' explicitly! It serves only for testing purposes.\n" << std::endl;
        return returnStatus;
      }
      std::string fileInput = argv[3];
      gol::grid initialGrid(fileInput, runCommand);
      gol::game gameToPlay(initialGrid);
      iterationsToInt = argv[4];
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