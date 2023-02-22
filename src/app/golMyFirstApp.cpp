/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <golMyFunctions.h>
#include <golBasicTypes.h>
#include <golExceptionMacro.h>
#include <iostream>

/* The app should be run as ./build/bin/gof_simulator *nGenerations* *-h*, where *nGenerations* is the number of generations to simulate
and -h is a facultative argument that will redirect to an help section (If the number *nGenerations* is not specified we should also be
redirected to an help section) */

int main(int argc, char** argv)
{
  int returnStatus = EXIT_FAILURE;
  
  try
  {
    throw std::runtime_error("Something went wrong!");

    returnStatus = EXIT_SUCCESS;
  }
  catch (gol::Exception& e)
  {
    std::cerr << "Caught gol::Exception: " << e.GetDescription() << std::endl;
  }
  catch (std::exception& e)
  {
    std::cerr << "Caught std::exception: " << e.what() << std::endl;
  }

  return returnStatus;

}





/*if (*argv[1] is not an int)
  {
    std::cout << "Too few arguments: in order to launch the program you should launch the gof_simulator with the command\n\n./build/bin/gof_simulator *nGenerations* -h\n\nwhere *nGenerations* is the number of generations to produce with the game and -h is a facultative argument that redirects to a help window." << std::endl;
  }*/
  /*bool inputMethodWrong = true;
  char inputMethod;
  do{*/

    /* Selecting the input method */

    /*std::cout << "Game of Life Simulator: select the input method for setting the initial grid: \n 1) Read from file\n 2) Randomly set grid" << std::endl;
    std::cin >> inputMethod;
    if(inputMethod == '1' || inputMethod == '2')
    {
      inputMethodWrong = false;
    }
  }while(inputMethodWrong);*/ 

  /* If 1 is selected */

  /*if(inputMethod == '1')
  {
    std::string nameFile;
    std::cout << "Please insert the name of the file to open:" << std::endl;
    std::cin >> nameFile;
    //gol::grid(nameFile);
  }*/
  /* If 2 is selected */