/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <golBasicFunctions.h>
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

void reInitialiseGrid(grid* initialGrid, int rows, int columns, int aliveCells)
{
  grid newGrid(rows, columns, aliveCells);
  *initialGrid = newGrid;
}

void reInitialiseGame(game* gameToPlay, grid initialGrid)
{
  game newGame(initialGrid);
  *gameToPlay = newGame;
}

bool notAllDead(game gameToPlay)
{
  int counter = 0;
  for(int i = 0; i < gameToPlay.getGridClass()->getRows(); i++)
  {
    for(int j = 0; j < gameToPlay.getGridClass()->getColumns(); j++)
    {
      if(gameToPlay.getGridClass()->getGridElement(i, j) == '-')
      {
        counter++;
      }
    }
  }
  if(counter == gameToPlay.getGridClass()->getRows() * gameToPlay.getGridClass()->getColumns())
  {
    return false;
  }
  else
  {
    return true;
  }

}

void searchStationaryPatterns(int rows, int columns, int aliveCells, int iterations)
{
  bool notEmptyGrid = true;
  bool stillLifeFound = false;
  grid initialGrid(rows, columns, aliveCells);
  game gameToPlay(initialGrid);
  game temporaryGame(*(gameToPlay.getGridClass()));
  while(!stillLifeFound)
  {
    for(int i = 0; i < iterations; i++)
    {
      gameToPlay.takeStep();
      notEmptyGrid = notAllDead(gameToPlay);
      if(gameToPlay.getGridClass()->getGrid() == temporaryGame.getGridClass()->getGrid() && notEmptyGrid == true)
      {
        i = iterations;
        std::cout << "We have found a stationary pattern!\n" << std::endl;
        gameToPlay.getGridClass()->printGrid();
        stillLifeFound = true;
      }
      temporaryGame = gameToPlay;
    }
    reInitialiseGrid(&initialGrid, rows, columns, aliveCells);
    reInitialiseGame(&gameToPlay, initialGrid);
  }
}

} // namespace gol
