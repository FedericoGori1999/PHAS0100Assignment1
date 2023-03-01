/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "catch.hpp"
#include "golCatchMain.h"
#include <golGameClass.h>

TEST_CASE("Instantiation of the grid class", "[ex1]") {

  /* Testing instantiations of the grid classes for the random constructed grid.
   * This is a legit construction, so no throw is expected.*/

  REQUIRE_NOTHROW(gol::grid(5, 5, 4));

  /* We require an exception thrown for grids that have one of the two
   * dimensions that are 0 (testing on the random grid setup constructor).*/

  REQUIRE_THROWS(gol::grid(0, 2, 1));
  REQUIRE_THROWS(gol::grid(1, 0, 0));

  /* Here we require an exception thrown if the number of alive cells is
   * superior than the number of available cells in the grid.*/

  REQUIRE_THROWS(gol::grid(5, 5, 26));

  /* Here we test if the grid is correctly built from the read of an external
   * file.*/

  REQUIRE_NOTHROW(gol::grid("oscillators.txt", "test"));
  REQUIRE_NOTHROW(gol::grid("still_lifes.txt", "test"));
  REQUIRE_NOTHROW(gol::grid("glider.txt", "test"));

  /* Here we require to throw an error when we call a file that does not
   * exist.*/

  REQUIRE_THROWS(gol::grid("glimer.txt", "test"));
}

TEST_CASE("Randomness of the grid", "[ex2]") {
  /* Here we check for the randomness of the grid built. We test it for very big
  grids with few alive cells, so that the probability of having the same grid is
  really low. If the grids match, we instantiate a second grid and test again.
  We repeat this process two times in order to have a negligible probability of
  having the same grid initialised. In doing so, with a grid 10x10 with only an
  element = 'o', there is a probability of (10^(-4))^(-3) of getting the same
  grid, assuming that the randomizer works ideally. */

  bool differentGrid = true;
  gol::grid test1(100, 100, 1);
  gol::grid test2(100, 100, 1);
  if (test1.getGrid() == test2.getGrid()) {
    gol::grid test3(100, 100, 1);
    if (test1.getGrid() == test3.getGrid()) {
      gol::grid test4(100, 100, 1);
      if (test1.getGrid() == test4.getGrid()) {
        bool differentGrid = false;
      } else {
        bool differentGrid = true;
      }
    } else {
      bool differentGrid = true;
    }
  } else {
    bool differentGrid = true;
  }
  REQUIRE(differentGrid == true);
}
