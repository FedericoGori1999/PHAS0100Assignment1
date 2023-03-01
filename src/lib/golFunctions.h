/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef golFunctions_h
#define golFunctions_h

#include <golGameClass.h>

/* See .cpp file for explanation of functions and behaviours. */

namespace gol {

void gameOfLife(game gridToPlay, grid initialGrid, int iterations);
void searchStationaryPatterns(int rows, int columns, int aliveCells,
                              int iterations);
void reInitialiseGrid(grid *initialGrid, int rows, int columns, int aliveCells);
void reInitialiseGame(game *gameToPlay, grid iniTialGrid);
bool notAllDead(game gameToPlay);

} // namespace gol

#endif
