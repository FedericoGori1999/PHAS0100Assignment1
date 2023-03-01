/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <golException.h>
#include <golGridClass.h>

#ifndef golGameClass_h
#define golGameClass_h

/* See .cpp file for explanation of functions and behaviours. */

namespace gol {
class game {
public:
  game(grid initialGrid);
  game() = default;
  ~game();

  void takeStep();
  void printGame();
  grid *getObjectGrid();

private:
  grid gridStored;
  std::vector<char> temporaryRow{};
  std::vector<std::vector<char>> temporaryGrid{};
};

} // namespace gol

#endif