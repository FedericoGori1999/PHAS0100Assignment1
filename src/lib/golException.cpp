/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "golException.h"
#include <iostream>

namespace gol {

ExceptionGolSimulator::ExceptionGolSimulator(int argc, std::string inputMethod,
                                             std::string helpString) {
  if (argc == 1 || helpString == "-h") {
    /* Help message displayed for golSimulator*/

    message =
        "Please launch the app from terminal with the following "
        "command:\n\n./build/bin/golSimulator <typeOfInput> "
        "<argumentsInput> <nGenerations> <-h>\n\nThe arguments have "
        "the following meaning:\n"
        "-> <typeInput> is 'file' or 'random':\n"
        "   -> if 'file' the program will expect a file in input, "
        "from which it will read the initial grid\n"
        "   -> If 'random', it will expect a random initialisation "
        "of the grid\n\n"
        "-> <argumentsInput> are the arguments depending on the "
        "choice made in <typeInput>. Specifically:\n"
        "   -> if <typeInput> == file, then <argumentsInput> should expect "
        "2 strings: <run> (this argument has been implemented for testing "
        "purposes) and <nameFile.txt>\n"
        "   -> if <typeInput> == random, then <argumentsInput> should "
        "expect 3 numbers <numRows>, <numColumns> and <aliveCell>, "
        "which will be passed to the random constructor\n\n"
        "-> <nGenerations> is the number of generations to simulate "
        "with the takeStep() fucntion\n\n"
        "-> <-h> will let you read this message again\n";
  } else {
    if (inputMethod == "file") {
      /* Five arguments are expected for the program to run if it reads from
       * file. */

      if (argc < 5) {
        /* Less arguments than expected.*/

        message = "\nFewer arguments than expected! Please launch "
                  "./build/bin/golSimulator or use -h as last argument to see "
                  "how you should call the program.\n";
      } else if (argc > 5) {
        /* More arguments than expected.*/

        message =
            "\nToo many arguments! Please launch ./build/bin/golSimulator or "
            "use -h as last argument to see how you should call the program.\n";
      }
    } else if (inputMethod == "random") {
      /* 6 is the correct number of parameters if we use the random grid */

      if (argc < 6) {
        /* Less arguments than expected.*/

        message = "\nFewer arguments than expected! Please launch "
                  "./build/bin/golSimulator or use -h as last argument to see "
                  "how you should call the program.\n";
      } else if (argc > 6) {
        /* More arguments than expected.*/

        message =
            "\nToo many arguments! Please launch ./build/bin/golSimulator or "
            "use -h as last argument to see how you should call the program.\n";
      }
    } else {
      /* Error in specifying the type of input (neither file or random).*/

      message = "\nType of input selected not correct! Please launch "
                "./build/bin/golSimulator or use -h as last argument to see "
                "how you should call the program.\n";
    }
  }
}

/* This function prints out the message string.*/

std::string ExceptionGolSimulator::whatProblem() { return message; }

ExceptionGolStationaryPatterns::ExceptionGolStationaryPatterns(
    int argc, std::string helpString) {
  if (argc == 1 || helpString == "-h") {
    /* Help message */

    message =
        "Please launch the app from terminal with the following command\n\n"
        "./golStationaryPatterns <rows> <columns> <aliveCells> <iterations> "
        "<-h>\n\n"
        "where:\n\n"
        "-> <rows> is the number of rows of the grid\n"
        "-> <columns> is the number of columns of the grid\n"
        "-> <aliveCells> is the number of alive cells put initially in the "
        "grid\n"
        "-> <iterations> is the number of iterations that the program has to "
        "make in order to find stationary patterns\n"
        "-> <-h> will let you read this message again\n";
  } else {
    /* 5 is the correct number of parameters if we use the random grid.*/

    if (argc < 5) {
      /* Less arguments than expected.*/

      message = "\nFewer arguments than expected! Please launch "
                "./build/bin/golStationaryPatterns or use -h as last argument "
                "to see how you should use the program.\n";
    } else {
      if (argc > 5) {
        /* More arguments than expected.*/

        message = "\nToo many arguments! Please launch "
                  "./build/bin/golStationaryPatterns or use -h as last "
                  "argument to see how you should use the program.\n";
      }
    }
  }
}

std::string ExceptionGolStationaryPatterns::whatProblem() { return message; }

ExceptionGrid::ExceptionGrid(int rows, int columns, int aliveCells) {
  if (rows <= 0 || columns <= 0) {
    /* Grid cannot have one of the dimensions equal to 0.*/

    message = "\nBad dimensions called for the grid! (0 or negative numbers "
              "called)\n";
  } else {
    if (aliveCells < 0) {
      /* Empty grid selected.*/

      message = "\nWarning: you have placed a wrong number of alive cells!\n";
    }
    if (aliveCells > rows * columns) {
      /* More alive cells than available cells in the grid.*/

      message = "\nYou cannot place more alive cells than available cells in "
                "the grid!\n";
    }
    if (aliveCells < 0) {
      message = "\nBad input in the number of alive cells!\n";
    }
  }
}

ExceptionGrid::ExceptionGrid(std::string nameFile, FILE *f,
                             std::string testOrRun) {
  if (testOrRun != "run" && testOrRun != "test") {
    /* Use the 'run' keyword to run the program. 'test' is used only for testing
     * (it specifies a different relative path).*/

    message = "\nInvalid call of the program! Please use 'run' after the "
              "'file' argument.\n";
  } else {
    if (!f) {
      /* File is missing.*/

      message = "\nThe file " + nameFile + " is missing! Please try again.\n";
    } else {
      message = "\nEmpty file! Please specify another file.\n";
    }
  }
}

ExceptionGrid::ExceptionGrid(char status, int rowCoordinate,
                             int columnCoordinate) {
  std::string charToString(1, status);
  if (status != 'o' && status != 'o' && status != ' ' && status != '\n')
    ;
  {
    /* Character read is neither 'o' or '-'.*/

    message = "\nInvalid character '" + charToString +
              "' in input from file (position (" +
              std::to_string(rowCoordinate + 1) + "," +
              std::to_string(columnCoordinate + 1) + "))! Please try again.\n";
  }
}

std::string ExceptionGrid::whatProblem() { return message; }

ExceptionGame::ExceptionGame(int iterations) {
  if (iterations <= 0) {
    /* 0 iterations requested: no game of life.*/

    message = "\nYou have requested a bad number of iterations!\n";
  }
}

std::string ExceptionGame::whatProblem() { return message; }

} // namespace gol
