

#ifndef GRID_H
#define GRID_H

#include <vector>
#include "Disc.h"
#include <string>
#include <iostream>


class Grid {
public:
    Grid();
    ~Grid(){ Matrix.clear();}
    
    void PrintGrid() const;
    void Insert(int column,Disc *pedina);
    bool IsColumnFull(int column); // verifica se la colonna è piena 
    char Winner();
    friend class PC_Player;
    //friend class Player;
    friend class Human_Player;
    
private:
    std::vector<std::vector<Disc> > Matrix;

};

#endif /* GRID_H */

