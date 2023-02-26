/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "golBasicClasses.h"

namespace gol {

/* The idea is to setup the grid as a 2D matrix, i.e. a vector of vectors, as
shown below. This is a sample constructor that takes the char values to add as
an input We must include the exception for other values inserted rather than '-'
and 'o'. */

grid::grid(int rowsArgument, int columnsArgument)
    : rows(rowsArgument), columns(columnsArgument) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      std::cin >> status;
      elementsInRow.push_back(status);
    }
    vectorOfRows.push_back(elementsInRow);
    elementsInRow.clear();
  }
}

/* This constructor generates the grid randomly having taken as an input the
 * number of alive cells that should be in the grid */

grid::grid(int rowsArgument, int columnsArgument, int aliveCells)
    : rows(rowsArgument), columns(columnsArgument) {
  if (rows == 0 || columns == 0 || aliveCells > rows * columns) {
    throw gol::ExceptionGrid(rows, columns, aliveCells);
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      elementsInRow.push_back('-');
    }
    vectorOfRows.push_back(elementsInRow);
    elementsInRow.clear();
  }
  std::mt19937 generator;
  std::random_device trueRandomNumber;
  generator.seed(trueRandomNumber());
  std::vector<int> placeAliveCells(aliveCells);
  std::vector<int> numbersToDraw{};

  /* In order to generate the random places in the matrix where we should put
  the alive cells, we have created a sorted vector with all the elements of the
  matrix, then with shuffle we have shuffled the vectors and then extract the
  required number of cells to put alive, which is aliveCells. We have done this
  to avoid repetition in the generated random numbers */

  for (int k = 0; k < rows * columns - 1; k++) {
    numbersToDraw.push_back(k);
  }
  std::shuffle(numbersToDraw.begin(), numbersToDraw.end(), generator);
  for (int k = 0; k < aliveCells; k++) {
    placeAliveCells.at(k) = numbersToDraw.at(k);
  }

  /* This piece of code was to test the shuffling of the numbers

  for(int k = 0; k < aliveCells; k++)
  {
    std::cout << placeAliveCells.at(k) << std::endl;
  }

  End of comment */

  for (int it = 0; it < aliveCells; it++) {
    int positionInTheRow = placeAliveCells.at(it) / columns;
    int positionInTheColumn = placeAliveCells.at(it) % columns;
    vectorOfRows.at(positionInTheRow).at(positionInTheColumn) = 'o';
  }
}

grid::grid(std::string fileName) {
  std::string path = "test/data/";
  path = path + fileName;
  f = std::fopen(path.c_str(), "rw");
  if (!f) {
    throw gol::ExceptionGrid(fileName, f);
  }
  int i = 0;
  int j = 0;
  while ((std::fscanf(f, "%c", &status)) != EOF) {
    if (status == 'o' || status == '-') {
      elementsInRow.push_back(status);
      j++;
    } else if (status == '\n') {
      vectorOfRows.push_back(elementsInRow);
      columns = j;
      j = 0;
      i++;
      elementsInRow.clear();
    } else if(status != ' ') {
      throw gol::ExceptionGrid(status, i, j);
    }
  }
  vectorOfRows.push_back(elementsInRow);
  rows = i + 1;
  fclose(f);
}

grid::~grid() {}

void grid::printGrid() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      std::cout << vectorOfRows.at(i).at(j) << " ";
    }
    std::cout << std::endl;
  }
}

void grid::setGridElement(int rowCoordinate, int columnCoordinate) {
  std::cout << "Insert the status of the cell with coordinates ("
            << rowCoordinate << "," << columnCoordinate << "):" << std::endl;
  std::cin >> status;
  vectorOfRows.at(rowCoordinate - 1).at(columnCoordinate - 1) = status;
}

char grid::getGridElementUser(int rowCoordinate, int columnCoordinate) {
  return vectorOfRows.at(rowCoordinate - 1).at(columnCoordinate - 1);
}

/* getGridElement takes the coordinates starting from (0, 0) as the first cell
 * of the matrix. */

char grid::getGridElement(int rowCoordinate, int columnCoordinate) {
  return vectorOfRows.at(rowCoordinate).at(columnCoordinate);
}

int grid::fetchNeighboursUser(int rowCoordinate, int columnCoordinate) {
  status = getGridElement(rowCoordinate, columnCoordinate);
  int liveNeighbours = 0;
  int lowerLimitRow = rowCoordinate - 2;
  int upperLimitRow = rowCoordinate;
  int lowerLimitColumn = columnCoordinate - 2;
  int upperLimitColumn = columnCoordinate;
  if (rowCoordinate == 1) {
    lowerLimitRow++;
  }
  if (rowCoordinate == rows) {
    upperLimitRow--;
  }
  if (columnCoordinate == 1) {
    lowerLimitColumn++;
  }
  if (columnCoordinate == columns) {
    upperLimitColumn--;
  }
  for (int i = lowerLimitRow; i <= upperLimitRow; i++) {
    for (int j = lowerLimitColumn; j <= upperLimitColumn; j++) {
      if (vectorOfRows.at(i).at(j) == 'o') {
        liveNeighbours++;
      }
    }
  }
  if (vectorOfRows.at(rowCoordinate - 1).at(columnCoordinate - 1) == 'o') {
    return liveNeighbours - 1;
  } else {
    return liveNeighbours;
  }
}

/* fetchNeighbours takes the coordinates starting from (0, 0) as the first cell
 * of the matrix. */

int grid::fetchNeighbours(int rowCoordinate, int columnCoordinate) {
  status = getGridElement(rowCoordinate, columnCoordinate);
  int liveNeighbours = 0;
  int lowerLimitRow = rowCoordinate - 1;
  int upperLimitRow = rowCoordinate + 1;
  int lowerLimitColumn = columnCoordinate - 1;
  int upperLimitColumn = columnCoordinate + 1;
  if (rowCoordinate == 0) {
    lowerLimitRow++;
  }
  if (rowCoordinate == rows - 1) {
    upperLimitRow--;
  }
  if (columnCoordinate == 0) {
    lowerLimitColumn++;
  }
  if (columnCoordinate == columns - 1) {
    upperLimitColumn--;
  }
  for (int i = lowerLimitRow; i <= upperLimitRow; i++) {
    for (int j = lowerLimitColumn; j <= upperLimitColumn; j++) {
      if (vectorOfRows.at(i).at(j) == 'o') {
        liveNeighbours++;
      }
    }
  }
  if (vectorOfRows.at(rowCoordinate).at(columnCoordinate) == 'o') {
    return liveNeighbours - 1;
  } else {
    return liveNeighbours;
  }
}

int grid::getRows() { return rows; }

int grid::getColumns() { return columns; }

void grid::copyGrid(std::vector<std::vector<char>> &gridToCopy) {
  vectorOfRows = std::move(gridToCopy);
}

std::vector<std::vector<char>> grid::getGrid() { return vectorOfRows; }

game::game(grid initialGrid) { gridPassed = initialGrid; }

game::~game(){}

void game::takeStep() {
  int i = 0;
  int j = 0;
  for (i = 0; i < gridPassed.getRows(); i++) {
    for (j = 0; j < gridPassed.getColumns(); j++) {
      if (gridPassed.getGridElement(i, j) == 'o') {
        if (gridPassed.fetchNeighbours(i, j) == 2 ||
            gridPassed.fetchNeighbours(i, j) == 3) {
          temporaryRow.push_back('o');
        } else {
          temporaryRow.push_back('-');
        }
      } else {
        if (gridPassed.fetchNeighbours(i, j) == 3) {
          temporaryRow.push_back('o');
        } else {
          temporaryRow.push_back('-');
        }
      }
    }
    temporaryGrid.push_back(temporaryRow);
    temporaryRow.clear();
  }
  gridPassed.copyGrid(temporaryGrid);
}

void game::printGridGame() {
  std::cout << "\n"
            << "Next step"
            << "\n"
            << std::endl;
  gridPassed.printGrid();
}

grid *game::getGridClass() { return &gridPassed; }

} // namespace gol
