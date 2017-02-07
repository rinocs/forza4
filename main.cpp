/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: andrea,riccardo
 * 
 * Created on 11 giugno 2016, 16.27
 */





#include"Grid.h"
#include"Player.h"
#include"Game.h"
#include<iostream>
#include <cstdio>
#include<string>


int main (){
    
 int scelta;   
 printf("\e[2J\e[H");
  
 std::cout<<"  _____   U  ___ u   ____      _____     _       _  _   "<<std::endl;
 std::cout<<" |\" ___|   \\/\"_\\/U |  _\"\\ u  |\"_  /uU  /\"\\  | | |\"|"<<std::endl;
 std::cout<<"U| |_  u   | | | | \\| |_) |/  U / //  \\/ _ \\/   | | | |_"<<std::endl;
 std::cout<<"\\|  _|/.-,_| |_| |  |  _ <    \\/ /_   / ___ \\   |__   _|"<<std::endl;
 std::cout<<" |_|    \\_)-\\___/   |_| \\_\\   /____| /_/   \\_\\    /|_|\\ "<<std::endl;
 std::cout<<" )(\\,-      \\     //   \\_  _//<<,- \\    >>   u_|||_u"<<std::endl;
 std::cout<<"(__)(_/     (__)   (__)  (__)(__) (_/(__)  (__)  (__)__)"<<std::endl;
 
 std::cout<<std::endl;
 std::cout<<std::endl;
 
 
 std::cout<<"come vuoi giocare?"<<std::endl;
 std::cout<<"1)player vs Player  2) player vs PC 3)exit"<<std::endl;
 std::cin>>scelta;
 
 
 switch(scelta){
     case(1):{
          std::string name1,name2;  
          std::cout<<"inserisci il nome del Player 1"<<std::endl;  
          std::cin>>name1;
          Human_Player uno(name1);
          std::cout<<"inserisci il nome del Player 2"<<std::endl;  
          std::cin>>name2;
          Human_Player due(name2);
          Game gioco(uno,due);
          gioco.Play();
          break;
     
     }   
     case(2):{
          std::string name1;  
          std::cout<<"inserisci il nome del Player 1"<<std::endl;  
          std::cin>>name1;
          Human_Player uno(name1);
          PC_Player due;
          Game gioco(uno,due);
          gioco.Play();
          break;
     }
     case(3):{
         std::cout<<"grazie per aver giocato.Arrivederci."<<std::endl;
         break;
     
     
     
     }
     default:
         break;
         
 }
 
 return 0;
 
    
    
    
}