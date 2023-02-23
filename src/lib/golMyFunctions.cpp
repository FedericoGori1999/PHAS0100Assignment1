/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "golMyFunctions.h"
#include <iostream>

namespace gol {

void gameOfLife(game gameToPlay, grid initialGrid, int iterations) {
  std::cout << "The initial grid is the following one\n" << std::endl;
  initialGrid.printGrid();
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  for (int i = 0; i < iterations; i++) {
    gameToPlay.takeStep();
    gameToPlay.printGridGame();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  }
}

} // namespace gol
