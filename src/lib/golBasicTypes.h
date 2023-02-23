/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef golBasicTypes_h
#define golBasicTypes_h

#pragma once
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <memory>
#include <random>
#include <stdexcept>
#include <thread>
#include <vector>

/**
 * \defgroup internal internal
 * \brief Internal stuff, not for end-users.
 */

/**
 * \defgroup types types
 * \brief Package-wide data types.
 */

/**
 * \defgroup utilities utilities
 * \brief Groups of c-style functions.
 */

/**
 * \defgroup applications applications
 * \brief Small, end-user applications, most likely command line.
 */

/**
 * \file golBasicTypes.h
 * \brief Defines types and typedefs used in this library.
 * \ingroup types
 */

//! Single namespace for all code in this package
namespace gol {
class grid {
public:
  /* Here we have the following constructors: the first one allows us to create
  the grid manually, entering all cells' status as input. The second constructor
  allows us to create the grid randomly, having given only the number of alive
  cells. The third constructor takes the grid setup from an external file. */

  grid(int rowsArgument, int columnsArgument);
  grid(int rowsArgument, int columnsArgument, int aliveCells);
  grid(std::string fileName);
  grid() = default;
  ~grid();

  void printGrid();

  /* The function setGridElement() allows us to set the status of the cell whose
  coordinates are given as an input. The same arguments are taken in input by
  getGridElement(), which instead gives us back the status of the cell. */

  void setGridElement(int rowCoordinate, int columnCoordinate);
  char getGridElementUser(int rowCoordinate, int columnCoordinate);
  char getGridElement(int rowCoordinate, int columnCoordinate);
  std::vector<std::vector<char>> getGrid();
  int fetchNeighboursUser(int rowCoordinate, int columnCoordinate);
  int fetchNeighbours(int rowCoordinate, int columnCoordinate);
  void copyGrid(std::vector<std::vector<char>> &gridToCopy);
  int getRows();
  int getColumns();

private:
  char status = '-';
  std::vector<char> elementsInRow{};
  FILE *f;
  std::vector<std::vector<char>> vectorOfRows{};
  int rows = 1;
  int columns = 1;
};

/* We have to understand how to pass the constructor to game through
 * game(grid()). The matrix initialGrid copy the grid set up by the grid class
 */

class game {
public:
  game(grid initialGrid);
  void takeStep();
  void printGridGame();
  grid *getGridClass();

private:
  grid gridPassed;
  std::vector<char> temporaryRow{};
  std::vector<std::vector<char>> temporaryGrid{};
};

void gameOfLife(game gridToPlay, grid initialGrid, int iterations);

} // namespace gol

#endif
