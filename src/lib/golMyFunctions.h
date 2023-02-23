/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef golMyFunctions_h
#define golMyFunctions_h
#include <golBasicTypes.h>

/**
 * \file golMyFunctions.h
 * \brief Various Utilities.
 * \ingroup utilities
 */
namespace gol {

void gameOfLife(game gridToPlay, grid initialGrid, int iterations);

} // namespace gol

#endif
