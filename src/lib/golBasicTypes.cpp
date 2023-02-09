/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "golBasicTypes.h"

namespace gol {

  /* The idea is to setup the grid as a 2D matrix, i.e. a vector of vectors, as shown below. This is a sample constructor that takes the char values to add as an input
  We must include the exception for other values inserted rather than '-' and 'o', and we must include the testing */

  grid::grid(int rowsArgument, int columnsArgument) : rows(rowsArgument), columns(columnsArgument)
  {
    for(int i = 0; i < rows; i++)
    {
      for(int j = 0; j < columns; j++)
      {
        std::cin >> status;
        elementsInRow.push_back(status);        
      }
      vectorOfRows.push_back(elementsInRow);
      elementsInRow.clear();
    }
  }

  /* This constructor generates the grid randomly having taken as an input the number of alive cells that should be in the grid */

  grid::grid(int rowsArgument, int columnsArgument, int aliveCells) : rows(rowsArgument), columns(columnsArgument)
  {
    for(int i = 0; i < rows; i++)
    {
      for(int j = 0; j < columns; j++)
      {
        elementsInRow.push_back('-');        
      }
      vectorOfRows.push_back(elementsInRow);
      elementsInRow.clear();
    }
    std::mt19937 generator;
    std::random_device trueRandomNumber;
    generator.seed(trueRandomNumber());
    std::vector<int> placeAliveCells(aliveCells);
    std::vector<int> numbersToDraw {};
    
    /* In order to generate the random places in the matrix where we should put the alive cells, we have created a sorted vector with all the elements
    of the matrix, then with shuffle we have shuffled the vectors and then extract the required number of cells to put alive, which is aliveCells.
    We have done this to avoid repetition in the generated random numbers */

    for(int k = 0; k < rows * columns -1; k++)
    {                                                     
      numbersToDraw.push_back(k);
    }
    std::shuffle(numbersToDraw.begin(), numbersToDraw.end(), generator);
    for(int k = 0; k < aliveCells; k++)
    {
      placeAliveCells.at(k) = numbersToDraw.at(k);
    }
    for(int k = 0; k < aliveCells; k++)
    {
      std::cout << placeAliveCells.at(k) << std::endl;
    }
    for(int it = 0; it < aliveCells; it++)
    { 
      int positionInTheRow = placeAliveCells.at(it) / columns;
      int positionInTheColumn = placeAliveCells.at(it) % columns;
      vectorOfRows.at(positionInTheRow).at(positionInTheColumn) = 'o';
    }
  }

  /* Functions to implement */
  
  grid::~grid(){}

  void grid::printGrid()
  {
    for(int i = 0; i < rows; i++)
    {
      for(int j = 0; j < columns; j++)
      {
        std::cout << vectorOfRows.at(i).at(j) << " ";
      }
      std::cout << std::endl;
    }
  }

  void grid::setGrid(){}

} // end namespace
