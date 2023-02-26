/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef golException_h
#define golException_h

#include <ostream>
#include <sstream>
#include <stdexcept>
#include <iostream>

namespace gol {

/**
 * \class Exception
 * \brief Base exception class.
 * \ingroup types
 */

class ExceptionGolSimulator : public std::exception {

  public:
  
  ExceptionGolSimulator(int argc, std::string inputMethod, std::string helpString);
  std::string whatProblem();

  private:
  std::string message;
};

class ExceptionGolStationaryPatterns : public std::exception
{
  public:
  ExceptionGolStationaryPatterns(int argc, std::string helpString);
  std::string whatProblem();

  private:
  std::string message;
};

class ExceptionGrid : public std::exception
{
  public:

  ExceptionGrid(int rows, int columns, int aliveCells);
  ExceptionGrid(std::string nameFile, FILE *f);
  ExceptionGrid(char status, int rowCoordinate, int columnCoordinate);
  std::string whatProblem();

  private:
  std::string message;

};

class ExceptionGame : public std::exception
{
  public:

  ExceptionGame(int iterations);
  std::string whatProblem();

  private:
  std::string message;
};

} // namespace gol

#endif

/*public:
  Exception(const std::string &fileName, int lineNumber);
  virtual ~Exception();

  std::string GetFileName() const;
  int GetLineNumber() const;

  std::string GetDescription() const;
  void SetDescription(const std::string &desc);
  virtual const char *What();

  Exception &operator<<(std::ostream &(*func)(std::ostream &)) {
    std::ostringstream ss;
    ss << this->GetDescription() << func;
    this->SetDescription(ss.str());
    return *this;
  }

  template <class T> inline Exception &operator<<(T &data) {
    std::ostringstream ss;
    ss << this->GetDescription() << data;
    this->SetDescription(ss.str());
    return *this;
  }

  template <class T> inline Exception &operator<<(const T &data) {
    std::ostringstream ss;
    ss << this->GetDescription() << data;
    this->SetDescription(ss.str());
    return *this;
  }

private:
  std::string m_Description;
  std::string m_FileName;
  int m_LineNumber;*/