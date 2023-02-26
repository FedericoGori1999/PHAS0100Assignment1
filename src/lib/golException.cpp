/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "golException.h"
#include <iostream>

namespace gol {

ExceptionGolSimulator::ExceptionGolSimulator(int argc, std::string inputMethod, std::string helpString)
{
  if(argc == 1 || helpString == "-h")
  {
    /* Help message */

    message = "Please launch the app from terminal with the following "
          "command:\n\n./build/bin/golSimulator *typeOfInput* "
          "*argumentsInput* *nGenerations* *-h*\n\nThe arguments have "
          "the following meaning:\n"
          "-> *typeInput* is 'file' or 'random':\n"
          "   -> if 'file' the program will expect a file in input, "
          "where it will read the initial grid\n"
          "   -> If 'random', it will expect a random initialisation "
          "of the grid\n\n"
          "-> *argumentsInput* are the arguments depending on the "
          "choice made in *typeInput*. Specifically:\n"
          "   -> if *typeInput* == 0, then *argumentsInput* should be "
          "a string *nameFile.txt*\n"
          "   -> if *typeInput* == 1, then *argumentsInput* should "
          "expect 3 numbers *numRows*, *numColumns* and *aliveCell*, "
          "which will be passed to the random constructor\n\n"
          "-> *nGenerations* is the number of generations to simulate "
          "with takeStep()\n\n"
          "-> *-h* will let you read this message again\n";
  }
  else
  {
    if(inputMethod == "file")
    {
      /* Four arguments are expected for the program to run if it reads from file. */

      if (argc < 3)
      {
        message = "\nThe name of the file is missing in the arguments! Please try again.\n";
      }
      else if (argc != 4)
      {
        message = "\nError in calling the program: number of arguments in command line is different than expected. Use -h as argument in command line to see the expected arguments.\n";
      }
    }
    else if(inputMethod == "random")
    {
      /* 6 is the correct number of parameters if we use the random grid */

      if(argc < 6)
      {
        message = "\nToo few arguments! Please launch -h as last argument to see how you should use the random constructor.\n";
      }
      else if(argc != 6)
      {
        message = "\nToo many arguments! Please launch -h as last argument to see how you should use the random constructor.\n";
      }
    }
    else
    {
      /* Error in specifying the type of input */
      
      message = "\nType of input selected not correct! Retry.\n";
    }
  }
}

std::string ExceptionGolSimulator::whatProblem()
{
  return message;
}

ExceptionGolStationaryPatterns::ExceptionGolStationaryPatterns(int argc, std::string helpString)
{
  if (argc == 1 || helpString == "-h")
  {
    /* Help message */

    message = "Please launch the app from terminal with the following command\n\n" 
    "./golStationaryPatterns *rows* *columns* *aliveCells* *iterations* *-h*\n\n"
    "where:\n\n"
    "-> *rows* is the number of rows of the grid\n"
    "-> *columns* is the number of columns of the grid\n"
    "-> *aliveCells* is the number of alive cells put initially in the grid\n"
    "-> *iterations* is the number of iterations that the program has to make in order to find stationary patterns\n"
    "-> *-h* will let you read this message again\n";
  }
  else
  {
    /* 5 is the correct number of parameters if we use the random grid. If argc < 5, some initial parameters are missing */

    if (argc < 5)
    {
      message = "\nToo few arguments! Please launch -h as last argument to see how you should use the program.\n";
    }
    else
    {
      if(argc > 5)
      {
        message = "\nToo many arguments! Please launch -h as last argument to see how you should use the program.\n";
      }
    }
  }
}

std::string ExceptionGolStationaryPatterns::whatProblem()
{
  return message;
}

ExceptionGrid::ExceptionGrid(int rows, int columns, int aliveCells)
{
  if(rows == 0 || columns == 0)
  {
    message = "\nThe grid cannot have 0 rows or 0 columns!\n";
  }
  else
  {
    if(aliveCells == 0)
    {
      message = "\nWarning: you have placed 0 alive cells!\n";
    }
    if(aliveCells > rows * columns)
    {
      message = "\nYou cannot place more alive cells than available cells in the grid! Retry\n";
    }
  }
}

ExceptionGrid::ExceptionGrid(std::string nameFile, FILE *f)
{
  if(!f)
  {
    message = "\nThe file " + nameFile + " is missing! Please try again.\n";
  }
}

ExceptionGrid::ExceptionGrid(char status, int rowCoordinate, int columnCoordinate)
{
  std::string charToString(1, status);
  //std::cout << status << std::endl;
  if (status != 'o' && status != 'o' && status != ' ' && status != '\n');
  {
    message = "\nInvalid character '" + charToString + "' in input from file (position (" + std::to_string(rowCoordinate+1) + "," + std::to_string(columnCoordinate+1) + "))! Please try again.\n";
    // (position (" + rowCoordinate + "," + columnCoordinate + ""))
  }
}

std::string ExceptionGrid::whatProblem()
{
  return message;
}

ExceptionGame::ExceptionGame(int iterations)
{
  if(iterations == 0)
  {
    message = "\nYou have requested 0 iterations! Retry.\n";
  }
}

std::string ExceptionGame::whatProblem()
{
  return message;
}


} // namespace gol


/*
//-----------------------------------------------------------------------------
Exception::Exception(const std::string &fileName, int lineNumber)
    : std::exception(), m_Description(""), m_FileName(fileName),
      m_LineNumber(lineNumber) {}

//-----------------------------------------------------------------------------
Exception::~Exception() {}

//-----------------------------------------------------------------------------
std::string Exception::GetFileName() const { return m_FileName; }

//-----------------------------------------------------------------------------
int Exception::GetLineNumber() const { return m_LineNumber; }

//-----------------------------------------------------------------------------
std::string Exception::GetDescription() const { return m_Description; }

//-----------------------------------------------------------------------------
void Exception::SetDescription(const std::string &desc) {
  m_Description = desc;
}

//-----------------------------------------------------------------------------
const char *Exception::What() { return m_Description.c_str(); }
*/