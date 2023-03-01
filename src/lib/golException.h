/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef golException_h
#define golException_h

#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>

/* See .cpp file for explanation of functions and behaviours. */

namespace gol {

class ExceptionGolSimulator : public std::exception {

public:
  ExceptionGolSimulator(int argc, std::string inputMethod,
                        std::string helpString);
  std::string whatProblem();

private:
  std::string message;
};

class ExceptionGolStationaryPatterns : public std::exception {
public:
  ExceptionGolStationaryPatterns(int argc, std::string helpString);
  std::string whatProblem();

private:
  std::string message;
};

class ExceptionGrid : public std::exception {
public:
  ExceptionGrid(int rows, int columns, int aliveCells);
  ExceptionGrid(std::string nameFile, FILE *f, std::string testOrRun);
  ExceptionGrid(char status, int rowCoordinate, int columnCoordinate);
  std::string whatProblem();

private:
  std::string message;
};

class ExceptionGame : public std::exception {
public:
  ExceptionGame(int iterations);
  std::string whatProblem();

private:
  std::string message;
};

} // namespace gol

#endif