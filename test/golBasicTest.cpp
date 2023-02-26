/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "catch.hpp"
#include "golBasicClasses.h"
#include "golCatchMain.h"
#include "golBasicFunctions.h"
#include <iostream>
#include <vector>

TEST_CASE("Instantiation of the class", "[ex1]") {
  /* Testing instantiations of the grid classes for the random constructed grid
  (apart from the part in which we have to give an input for the state of the
  cell, the construction of the grid is the same, so we can test directly the
  random generated one). */

  REQUIRE_NOTHROW(gol::grid(5, 5, 4));

  /* We require an exception thrown for grids that have one of the two
   * dimensions that are 0 (testing on the random grid setup constructor) */

  REQUIRE_THROWS(gol::grid(0, 2, 1));
  REQUIRE_THROWS(gol::grid(1, 0, 0)); // Implement exception when one of the dimension is zero.

  /* Here we require an exception thrown if the number of alive cells is
   * superior than the number of cells in the grid. */

  REQUIRE_THROWS(gol::grid(2, 2, 5));

  /* Here we test if the grid is correctly built from the read of an external
   * file. We throw an exception if the reading part fails. */

  REQUIRE_NOTHROW(gol::grid("glider.txt"));
  REQUIRE_NOTHROW(gol::grid("oscillators.txt"));
  REQUIRE_NOTHROW(gol::grid("still_lifes.txt"));

  /* Testing getGridElement. */

  REQUIRE(gol::grid("glider.txt").getGridElement(9, 9) == '-');
  REQUIRE(gol::grid("glider.txt").getGridElement(1, 2) == 'o');
  REQUIRE(gol::grid("glider.txt").getGridElement(2, 0) == 'o');
}

/* Counting the neighbours */

TEST_CASE("Counting the neighbours", "[ex2]") {
  REQUIRE(gol::grid("glider.txt").fetchNeighbours(1, 2) == 1);
  REQUIRE(gol::grid("glider.txt").fetchNeighbours(9, 9) == 0);
  REQUIRE(gol::grid("glider.txt").fetchNeighbours(3, 2) == 2);
}

/* Testing takeStep function. We have created the file gliderEvolution.txt that
 * depicts the expected evolution of the configuration assumed in glider.txt*/

TEST_CASE("Take step testing", "[ex3]") {
  gol::grid gridToEvolve("glider.txt");
  gol::grid gridResultExpected("gliderEvolution.txt");
  gol::game gameOfLifeTest(gridToEvolve);
  gameOfLifeTest.takeStep();
  REQUIRE(gameOfLifeTest.getGridClass()->getGrid() ==
          gridResultExpected.getGrid());
}
