/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: andrea,ricardo
 *
 * Created on 11 giugno 2016, 17.39
 */

#ifndef PLAYER_H
#define PLAYER_H
#include"Disc.h" 
#include "Grid.h"
#include <string>

class Player{
    protected:
        std::string name;
        Disc *pedina;// pedine 
    public:
        
        Player(){}
        
        virtual ~Player(){}
        static bool flag_colour;
        static char colour_disc;
        /* metodi */
        virtual char getColour() const =0;
        virtual std::string GetName() const=0;
        virtual void Decision(Grid &griglia)=0;
    

};


class Human_Player:public Player{
public:
    /* constructors and destructors*/
     
     Human_Player(std::string name_);
     Human_Player(const Human_Player &orig);
     virtual ~Human_Player(){delete pedina;}
   
    /* metodi */ 
    virtual char getColour() const;
    virtual void Decision(Grid &griglia);
    virtual std::string GetName() const{return this->name;} 
    

    
  
    

};


class PC_Player:public Player{

public:
    /* costruttori */
    PC_Player(){
        name="computer";
        if(colour_disc=='R'){
        this->pedina=new Disc('B');
        }else if(colour_disc=='B') this->pedina=new Disc('R');
        
    }
    PC_Player(const PC_Player& orig);
    virtual ~PC_Player(){delete pedina;}
    
    /* metodi */
    virtual void Decision(Grid &griglia);
    virtual std::string GetName() const{return this->name;} 
    virtual char getColour() const;



};


#endif /* PLAYER_H */

