/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: andrea,riccardo
 * 
 * Created on 11 giugno 2016, 20.02
 */

#include "Game.h"
#include<cstdlib>


/*################### COSTRUTTORE ################*/
Game::Game(const Human_Player &one_ , const Human_Player &two_ ) { 
    one=new Human_Player(one_);
    two=new Human_Player(two_);
    
    
}
Game::Game(const Human_Player &one_ , const PC_Player &two_ ) { 
    one=new Human_Player(one_);
    two=new PC_Player(two_);
    
    
}

/*###################### DISTRUTTORE #################*/
Game::~Game(){
    delete one;
    delete two;
}

Game::Game(const Game& orig) {
}


void Game::Play(){
    
    Grid griglia;
    int scelta;    
    std::cout<<"vuoi iniziare per primo? 1)si 2)no"<<std::endl;
    std::cin>>scelta;
    if(scelta==1 ) this->SetTurno(0);
    else this->SetTurno(1);
    griglia.PrintGrid();
    while((griglia.Winner()!='R' && griglia.Winner()!='B')){ //dopo sarà il while(check())
        
   
        if(this->GetTurno()==0){
            std::cout<<"turno "<<one->GetName() << " pedina: "<<one->getColour()<<std::endl;
            
            one->Decision(griglia);
            this->SetTurno(1);
        }else if(this->GetTurno()==1) {
            std::cout<<"turno "<<two->GetName()<< " pedina: "<<two->getColour()<<std::endl;
            
            two->Decision(griglia);
            this->SetTurno(0);
        }
            
            griglia.PrintGrid();

   }
    
    if(griglia.Winner()==one->getColour()){
      std::cout<<"il vincitore è : "<<one->GetName()<<std::endl;
    }else if(griglia.Winner()==two->getColour()){
      std::cout<<"il vincitore è : "<<two->GetName()<<std::endl;  
           
    }else {
        
        std::cout<<"pareggio "<<std::endl;
    }
    
    
    
}

