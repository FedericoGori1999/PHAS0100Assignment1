/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <golFunctions.h>

namespace gol {

/* The function gameOfLife() evolves the game object under the rules of the game of life, and add a sleep time of 2 s between each iteration.*/

void gameOfLife(game gameToPlay, grid initialGrid, int iterations) {
  std::cout << "\nThe initial grid is the following one\n" << std::endl;
  initialGrid.printGrid();
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  for (int i = 0; i < iterations; i++) {
    gameToPlay.takeStep();
    gameToPlay.printGame();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  }
}

/* The function reInitialiseGrid() has the purpose of re-shuffling the initial grid to pass to the game to evolve when searching for stationary patterns.*/

void reInitialiseGrid(grid* initialGrid, int rows, int columns, int aliveCells)
{
  grid newGrid(rows, columns, aliveCells);
  *initialGrid = newGrid;
}

/* The function reInitialiseGrid() has the purpose of re-shuffling the game to evolve when searching for stationary patterns.*/

void reInitialiseGame(game* gameToPlay, grid initialGrid)
{
  game newGame(initialGrid);
  *gameToPlay = newGame;
}

/* The function notAllDead() excludes the all-dead-in-grid pattern as a stationary pattern when searching for still lives.*/

bool notAllDead(game gameToPlay)
{
  int counter = 0;
  for(int i = 0; i < gameToPlay.getObjectGrid()->getRows(); i++)
  {
    for(int j = 0; j < gameToPlay.getObjectGrid()->getColumns(); j++)
    {
      if(gameToPlay.getObjectGrid()->getGridElement(i, j) == '-')
      {
        counter++;
      }
    }
  }
  if(counter == gameToPlay.getObjectGrid()->getRows() * gameToPlay.getObjectGrid()->getColumns())
  {
    return false;
  }
  else
  {
    return true;
  }

}

/* The function searchStationaryPatterns() takes in input the dimensions and the number of alive cells of the grids where to search for stationary patterns. It does create only one
object per class and if in the required number of iterations a still pattern is not found, then it re-creates the initial grid by shuffling the positions in the initial grid.*/

void searchStationaryPatterns(int rows, int columns, int aliveCells, int iterations)
{
  bool notEmptyGrid = true;
  bool stillLifeFound = false;
  grid initialGrid(rows, columns, aliveCells);
  game gameToPlay(initialGrid);
  game temporaryGame(*(gameToPlay.getObjectGrid()));
  while(!stillLifeFound)
  {
    for(int i = 0; i < iterations; i++)
    {
      gameToPlay.takeStep();
      notEmptyGrid = notAllDead(gameToPlay);
      if(gameToPlay.getObjectGrid()->getGrid() == temporaryGame.getObjectGrid()->getGrid() && notEmptyGrid == true)
      {
        i = iterations;
        std::cout << "\nWe have found a stationary pattern!\n" << std::endl;
        gameToPlay.getObjectGrid()->printGrid();
        stillLifeFound = true;
      }
      temporaryGame = gameToPlay;
    }
    reInitialiseGrid(&initialGrid, rows, columns, aliveCells);
    reInitialiseGame(&gameToPlay, initialGrid);
  }
}

} // namespace gol
