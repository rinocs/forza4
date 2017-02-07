/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Disc.h
 * Author: andrea,riccardo
 *
 * Created on 11 giugno 2016, 15.53
 */

#ifndef DISC_H
#define DISC_H
#include <iostream>


class Disc{
public:
    Disc(void);
    explicit Disc(char );
    Disc(const Disc &orig);
    char getChar() const;
    friend std::ostream &operator<<(std::ostream& out,const Disc & );
    bool operator==(const char& );
    bool operator!=(const char& );
    
private:
    char character;

};

#endif /* DISC_H */

