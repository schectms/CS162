/*******************************************************************************
 ** Author: Group 39
 ** Date: 5/11/2018
 ** Description: Ant class declaration- derived class
*******************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"
#include "Board.hpp"

class Ant :
public Critter
{
public:
    Ant();
    Ant(int currentRow, int currentCol);
    virtual ~Ant();
    virtual void breed(Board &board);
    virtual bool canBreed();
    bool move(Board &board);
    virtual void copyCritter(Board &board, int currentRow, int currentColumn);

};

#endif
