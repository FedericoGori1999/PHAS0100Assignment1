/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef golGridClass_h
#define golGridClass_h
#pragma once

#include <algorithm>
#include <chrono>
#include <fstream>
#include <golException.h>
#include <iostream>
#include <memory>
#include <random>
#include <stdexcept>
#include <thread>
#include <vector>

/* See .cpp file for explanation of functions and behaviours. */

namespace gol {
class grid {
public:
  grid(int rowsArgument, int columnsArgument);
  grid(int rowsArgument, int columnsArgument, int aliveCells);
  grid(std::string fileName, std::string testOrRun);
  grid() = default;
  ~grid();

  void printGrid();
  void setGridElement(int rowCoordinate, int columnCoordinate);
  char getGridElement(int rowCoordinate, int columnCoordinate);
  std::vector<std::vector<char>> getGrid();
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

} // namespace gol

#endif
