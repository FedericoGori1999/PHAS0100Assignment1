/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <golGameClass.h>

namespace gol {

/* This constructor of the game object takes as input a grid object and copy it
 * in the private grid object of the class.*/

game::game(grid initialGrid) { gridStored = initialGrid; }

/* Default destructor of the game object.*/

game::~game() {}

/* takeStep() takes as input a game object and evolve its grid under the rules
 * of the Game of Life.*/

void game::takeStep() {
  int i = 0;
  int j = 0;
  for (i = 0; i < gridStored.getRows(); i++) {
    for (j = 0; j < gridStored.getColumns(); j++) {
      if (gridStored.getGridElement(i, j) == 'o') {
        if (gridStored.fetchNeighbours(i, j) == 2 ||
            gridStored.fetchNeighbours(i, j) == 3) {
          temporaryRow.push_back('o');
        } else {
          temporaryRow.push_back('-');
        }
      } else {
        if (gridStored.fetchNeighbours(i, j) == 3) {
          temporaryRow.push_back('o');
        } else {
          temporaryRow.push_back('-');
        }
      }
    }
    temporaryGrid.push_back(temporaryRow);
    temporaryRow.clear();
  }
  gridStored.copyGrid(temporaryGrid);
}

/* The function printGame() calls the printGrid() function of the private grid
object in the game object as many times as the number of iterations require, and
add a delimitator between the various iterations that are printed.*/

void game::printGame() {
  std::cout << "\n"
            << "Next step"
            << "\n"
            << std::endl;
  gridStored.printGrid();
}

/* getObjectGrid() gives back as output a pointer to the private grid object of
 * the game object.*/

grid *game::getObjectGrid() { return &gridStored; }

} // namespace gol