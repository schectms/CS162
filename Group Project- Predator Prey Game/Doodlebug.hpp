/*******************************************************************************
 ** Author: Group 39
 ** Date: 5/11/2018
 ** Description: Doodlebug class declaration- derived class
*******************************************************************************/

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"
#include "Board.hpp"

class Doodlebug : public Critter
{
public:
    Doodlebug();
    virtual ~Doodlebug();
    Doodlebug(int currentRow, int currentCol);
    bool move(Board &board);
    virtual void breed(Board &board);
    virtual bool canBreed();
    virtual void copyCritter(Board &board, int currentRow, int currentColumn);

};

#endif
