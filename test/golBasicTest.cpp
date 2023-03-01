/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "catch.hpp"
#include <golGameClass.h>
#include "golCatchMain.h"
#include <golFunctions.h>


/* Testing getGridElement(). */

TEST_CASE("Testing getGridElement()", "[ex3]")
{
  REQUIRE(gol::grid("glider.txt", "test").getGridElement(9, 9) == '-');
  REQUIRE(gol::grid("glider.txt", "test").getGridElement(1, 2) == 'o');
  REQUIRE(gol::grid("glider.txt", "test").getGridElement(2, 0) == 'o');
}

/* Testing fetchNeighbours().*/

TEST_CASE("Counting the neighbours", "[ex4]") {
  std::string path = "../../";
  REQUIRE(gol::grid("glider.txt", "test").fetchNeighbours(1, 2) == 1);
  REQUIRE(gol::grid("glider.txt", "test").fetchNeighbours(9, 9) == 0);
  REQUIRE(gol::grid("glider.txt", "test").fetchNeighbours(3, 2) == 2);
}

/* Testing takeStep(). We have created the file gliderEvolution.txt that depicts the expected evolution after one step of the configuration assumed in glider.txt.*/

TEST_CASE("Take step testing", "[ex5]") {
  gol::grid gridToEvolve("glider.txt", "test");
  gol::grid gridResultExpected("gliderEvolution.txt", "test");
  gol::game gameOfLifeTest(gridToEvolve);
  gameOfLifeTest.takeStep();
  REQUIRE(gameOfLifeTest.getObjectGrid()->getGrid() ==
          gridResultExpected.getGrid());
}
