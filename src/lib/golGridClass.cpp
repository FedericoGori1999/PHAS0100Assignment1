/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <golGridClass.h>


namespace gol {

/* Setting the grid: The idea is to setup the grid as a 2D matrix, i.e. a vector of vectors. */

/* Initial constructor, never used in the program. */

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
 * number of alive cells that should be in the grid and the dimensions of the grid. */

grid::grid(int rowsArgument, int columnsArgument, int aliveCells)
    : rows(rowsArgument), columns(columnsArgument) {
  if (rows == 0 || columns == 0 || aliveCells > rows * columns || aliveCells == 0) {
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

  /* In order to generate the random places in the matrix where we should put the alive cells, we have created a sorted vector of int with all the places of the
  matrix, then with std::shuffle we have shuffled the vector and then extract the required number of cells to put alive, which is aliveCells. We have done this
  to avoid repetition in the generated random numbers. */

  for (int k = 0; k < rows * columns ; k++) {
    numbersToDraw.push_back(k);
  }
  std::shuffle(numbersToDraw.begin(), numbersToDraw.end(), generator);
  for (int k = 0; k < aliveCells; k++) {
    placeAliveCells.at(k) = numbersToDraw.at(k);
  }
  for (int it = 0; it < aliveCells; it++) {
    int positionInTheRow = placeAliveCells.at(it) / columns;
    int positionInTheColumn = placeAliveCells.at(it) % columns;
    vectorOfRows.at(positionInTheRow).at(positionInTheColumn) = 'o';
  }
}

/* Constructor from file for the grid. The keyword 'test' specifies a different path for the search of the file, because ctest is working under build.*/

grid::grid(std::string fileName, std::string testOrRun) {
  std::string path = "";
  if (testOrRun == "run")
  {
    path = "test/data/" + fileName;  
  }
  else if(testOrRun == "test")
  {
    path = "../../test/data/" + fileName;
  }
  else
  {
    throw gol::ExceptionGrid(fileName, f, testOrRun);
  }
  f = std::fopen(path.c_str(), "rw");
  if (!f) {
    throw gol::ExceptionGrid(fileName, f, testOrRun);
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
  if(i == 0 && j == 0)
  {
    throw gol::ExceptionGrid(fileName, f, testOrRun);
  }
  vectorOfRows.push_back(elementsInRow);
  rows = i + 1;
  fclose(f);
}

/* Destructor of the grid. */

grid::~grid() {}

/* printGrid() allows you to print the grid. */

void grid::printGrid() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      std::cout << vectorOfRows.at(i).at(j) << " ";
    }
    std::cout << std::endl;
  }
}

/* setGridElement() allows you to set a particular element in the grid given the coordinates (starts counting coordinates from 0).*/

void grid::setGridElement(int rowCoordinate, int columnCoordinate) {
  std::cout << "Insert the status of the cell with coordinates ("
            << rowCoordinate + 1 << "," << columnCoordinate + 1 << "):" << std::endl;
  std::cin >> status;
  vectorOfRows.at(rowCoordinate).at(columnCoordinate) = status;
}

/* getGridElement takes the coordinates (starting from (0, 0) as the first cell) in input and gives in output the character in that cell.*/

char grid::getGridElement(int rowCoordinate, int columnCoordinate) {
  return vectorOfRows.at(rowCoordinate).at(columnCoordinate);
}

/* fetchNeighbours counts the neighbours of a given cell that are alive (starts counting coordinates from 0). */

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

/* getRows() gives back the number of rows of the grid as output. */

int grid::getRows() { return rows; }

/* getColumns() gives back the number of columns of the grid as output. */

int grid::getColumns() { return columns; }

/* copyGrid() copies the grid received in input in the called grid's object.*/

void grid::copyGrid(std::vector<std::vector<char>> &gridToCopy) {
  vectorOfRows = std::move(gridToCopy);
}

/* getGrid() gives as an output the matrix of a given grid object.*/

std::vector<std::vector<char>> grid::getGrid() { return vectorOfRows; }

} // namespace gol
