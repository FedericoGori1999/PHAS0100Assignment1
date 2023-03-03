/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <golExceptionMacro.h>
#include <golFunctions.h>
#include <golGameClass.h>

int main(int argc, char **argv) {
  int returnStatus = EXIT_FAILURE;
  try {
    std::vector<int> arguments{};
    std::string iterationsToInt = "null";
    std::string helpString = argv[argc - 1];
    if (argc == 1 || argv[1] == "-h" || argc != 5) {
      throw gol::ExceptionGolStationaryPatterns(argc, helpString);
    }
    std::string rowToInt = argv[1];
    int row = std::stoi(rowToInt);
    std::string columnToInt = argv[2];
    int column = std::stoi(columnToInt);
    std::string aliveCellsToInt = argv[3];
    int aliveCells = std::stoi(aliveCellsToInt);
    iterationsToInt = argv[4];
    int iterations = std::stoi(iterationsToInt);
    if (row <= 0 || column <= 0 || aliveCells <= 0) {
      throw gol::ExceptionGrid(row, column, aliveCells);
    }
    if (iterations <= 0) {
      throw gol::ExceptionGame(iterations);
    }
    gol::grid initialGrid(row, column, aliveCells);
    gol::game gameToPlay(initialGrid);
    gol::searchStationaryPatterns(row, column, aliveCells, iterations);
    std::cout << "\nEnd of the game\n" << std::endl;
    returnStatus = EXIT_SUCCESS;
  } catch (gol::ExceptionGolStationaryPatterns e) {
    std::cout << e.whatProblem() << std::endl;
  } catch (gol::ExceptionGrid e) {
    std::cout << e.whatProblem() << std::endl;
  } catch (gol::ExceptionGame e) {
    std::cout << e.whatProblem() << std::endl;
  }
  return returnStatus;
}