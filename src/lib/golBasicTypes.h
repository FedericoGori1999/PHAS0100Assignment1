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
#include <memory>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <stdexcept>
#include <fstream>

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
namespace gol
{
  class grid
  {
    public:

    /* Here we have the following constructors: the first one allows us to create the grid manually, entering all cells' status as input.
    The second constructor allows us to create the grid randomly, having given only the number of alive cells. The third constructor
    takes the grid setup from an external file. */

    grid(int rowsArgument, int columnsArgument);
    grid(int rowsArgument, int columnsArgument, int aliveCells);
    grid(std::string fileName);
    ~grid();

    void printGrid();

    /* The function setGridElement() allows us to set the status of the cell whose coordinates are given as an input. The same arguments are
    taken in input by getGridElement(), which instead gives us back the status of the cell. */

    void setGridElement(int rowCoordinate, int columnCoordinate);
    void getGridElement(int rowCoordinate, int columnCoordinate);

    private:

    int rows;
    int columns;     
    char status;
    std::vector<char> elementsInRow {};
    std::vector<std::vector<char>> vectorOfRows {};
    FILE *f;
  };

} // end namespace

#endif
