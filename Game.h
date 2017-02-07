/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: andrea,riccardo
 *
 * Created on 11 giugno 2016, 20.02
 */

#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Grid.h"

class Game {
public:
    Game(){one=NULL;two=NULL;};
    explicit Game(const Human_Player &one_ ,const Human_Player &two_);
    explicit Game(const Human_Player &one_ , const PC_Player &two_ );
    Game(const Game& orig);
    ~Game();
    void SetTurno(int value){turno=value; }
    int GetTurno() const{return turno;} 
    void Play();
  
    
    
private:
    Player *one; 
    Player *two;
    
    int turno;
    
    
    

};

#endif /* GAME_H */

