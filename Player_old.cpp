/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.cpp
 * Author: andrea,riccardo
 * 
 * Created on 11 giugno 2016, 17.39
 */

#include "Player.h"
#include <iostream>
#include<cstdlib>

/*############## metodi Player ##############*/

bool Player::flag_colour=false;
char Player::colour_disc=' ';


/*########### metodi Human Player     ###########*/
Human_Player::Human_Player(std::string name_) {
    name=name_;
    // inizio controllo per la decisione del colore delle pedine
    int control=0;
    
    if(flag_colour==false){
        do {
          std::cout<<"premi 1 per le pedine rosse , 2 per le pedine blu"<<std::endl;
          std::cin>>control;
        
        }while(control != 1 && control != 2 );
        
        switch (control) {
            case(1): {
                colour_disc='R';
                this->pedina=new Disc(colour_disc);  
                flag_colour=true;
                break;
            }
            
            case(2): {
                colour_disc='B';
                this->pedina=new Disc(colour_disc);  
                flag_colour=true;
                break;
                           
            }  
            default:
                std::cout<<"errore nella scelta"<<std::endl;
        } 
        
    }else{
       
        if(colour_disc=='R'){
            this->pedina=new Disc('B');  
        }else if(colour_disc=='B') {
            this->pedina=new Disc('R');  
        }
    } //fine controllo
        
    
  
    
}


Human_Player::Human_Player(const Human_Player& orig){
    this->name=orig.name;
    this->pedina= new Disc(*orig.pedina);
}

void Human_Player::Decision(Grid &griglia){
    int column;
    
    do{ 
        std::cout<<"scegli la colonna (0-6) "<<std::endl;
        std::cin>>column;
    }while(column <0 || column>6);
    if(griglia.IsColumnFull(column)) {
        std::cout<<"colonna :"<<column<<" è piena, scegli la colonna"<<std::endl;
        Decision(griglia);
    }else griglia.Insert(column,this->pedina);

    
    
    
}

char Human_Player::getColour() const{ return this->pedina->getChar();}















///////////////////////////////////////////////
///////////////////////////////////////////////
/*########### metodi PC Player     ###########*/
///////////////////////////////////////////////
///////////////////////////////////////////////



PC_Player::PC_Player(const PC_Player& orig){
    this->name=orig.name;
    this->pedina= new Disc(*orig.pedina);
}

 char PC_Player::getColour() const{return this->pedina->getChar();}
 
 
 void PC_Player::Decision(Grid &griglia){
     char color=this->colour_disc;
     
    std::cout << "Giocata del computer: "<<std::endl;
    int a,b,c,d,n,column;
    srand((unsigned)time( NULL )); // inizializza la funzione rand()
  
    /*########## mosse di attacco #######à*/
    ///////////////Attacco Verticale/////////////////////////////////////////////////
   if(color=='R'){
        for (a=0,b=1,c=2,d=3,n=0;d<6;a++,b++,c++,d++) {
        
            if (griglia.Matrix[a][n].getChar()=='R' && griglia.Matrix[b][n].getChar()=='R' && griglia.Matrix[c][n].getChar()=='R'  &&  griglia.Matrix[d][n].getChar()=='0'  ) {
                           
                if(this->getColour()=='R'){
                    if(!griglia.IsColumnFull(n))  griglia.Insert(n,this->pedina); 
                
                    break;
                
                }
                           
            if (d==5 && n<7) {n++;a=-1;b=0;c=1;d=2; continue;}
            } 
    
        }
    }else if(color=='B'){
            for (a=0,b=1,c=2,d=3,n=0;d<6;a++,b++,c++,d++) {
        
            if (griglia.Matrix[a][n].getChar()=='B' && griglia.Matrix[b][n].getChar()=='B' && griglia.Matrix[c][n].getChar()=='B'  && griglia.Matrix[d][n].getChar()=='0'  ) {
                           
                if(this->getColour()=='B'){
                   if(!griglia.IsColumnFull(n))  griglia.Insert(n,this->pedina); 
                break;}
                           
            if (d==5 && n<7) {n++;a=-1;b=0;c=1;d=2; continue;}
            } 
              
            }
    }
   
///////////////Attacco Orizzontale [VersoDestra]{Ultimo Della Fila}/////////////
/*Prima Riga*/ 
      if(color=='R'){
        for (a=0,b=1,c=2,d=3;d<7;a++,b++,c++,d++) {
            if (griglia.Matrix[0][a].getChar()=='R' && griglia.Matrix[0][b].getChar()=='B' && griglia.Matrix[0][c].getChar()=='R' && griglia.Matrix[0][d].getChar()=='0') {
                               if(this->getColour()=='R'){
                                   if(!griglia.IsColumnFull(d))  griglia.Insert(d,this->pedina);   break;
                               }
            }
        }
    }else if(color=='B'){
        for (a=0,b=1,c=2,d=3;d<7;a++,b++,c++,d++) {
            if (griglia.Matrix[0][a].getChar()=='B' && griglia.Matrix[0][b].getChar()=='B' && griglia.Matrix[0][c].getChar()=='B' && griglia.Matrix[0][d].getChar()=='0' ){
                              if(this->getColour()=='B'){ 
                                  if(!griglia.IsColumnFull(d))  griglia.Insert(d,this->pedina);   break;
                              }
            }
        }
    }
/*Altre Righe*/   
   if (color=='R'){
        for (a=0,b=1,c=2,d=3,n=0;d<6;a++,b++,c++,d++) {
            if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n][b].getChar()=='R' && griglia.Matrix[n][c].getChar()=='R' && griglia.Matrix[n-1][d].getChar()!='0' && griglia.Matrix[n][d].getChar()=='0') {//perchè n-1?
                               if(this->getColour()=='R'){ 
                                   if(!griglia.IsColumnFull(d))  griglia.Insert(d,this->pedina);  break;
                               }
            }
           if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2; continue;}
            }    
    }else if (color=='B'){
       for (a=0,b=1,c=2,d=3,n=0;d<6;a++,b++,c++,d++) {
            if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n][b].getChar()=='B' && griglia.Matrix[n][c].getChar()=='B'   && griglia.Matrix[n-1][d].getChar()!='0' && griglia.Matrix[n][d].getChar()=='0') {//perchè n-1?
                              if(this->getColour()=='B'){
                                 if(!griglia.IsColumnFull(d))  griglia.Insert(c,this->pedina);  break;
                              }
            }
           if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2; continue;}
       }
    }    
    
    
    
 ///////////////Attacco Orizzontale [VersoDestra]{Penultimo Della Fila}//////////

    /*Prima Riga*/
    if(color=='R'){
        for (a=0,b=1,c=2,d=3;d<6;a++,b++,c++,d++) {
            if (griglia.Matrix[0][a].getChar()=='R' && griglia.Matrix[0][b].getChar()=='R' && griglia.Matrix[0][d].getChar()=='R' && griglia.Matrix[0][c].getChar()=='0') {
                               if(this->getColour()=='R') {
                                   if(!griglia.IsColumnFull(c))  griglia.Insert(c,this->pedina);  
                                   break;
                                  
                               }
                               }
        }
    }else if(color=='B'){
        for (a=0,b=1,c=2,d=3;d<6;a++,b++,c++,d++) {
            if (griglia.Matrix[0][a].getChar()=='B' && griglia.Matrix[0][b].getChar()=='B' && griglia.Matrix[0][d].getChar()=='B' && griglia.Matrix[0][c].getChar()=='0') {
                               if(this->getColour()=='B'){
                                   
                                   if(!griglia.IsColumnFull(c))  griglia.Insert(c,this->pedina);
                                   break;
                               }
                               }
        }
    }    
/*Altre Righe*/   
    if(color=='R'){    
        for (a=0,b=1,c=2,d=3,n=0;d<6;a++,b++,c++,d++) {
            if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n][b].getChar()=='R' && griglia.Matrix[n][d].getChar()=='R'  
            && griglia.Matrix[n-1][c].getChar()!='0' && griglia.Matrix[n][c].getChar()=='0') {
                                if(this->getColour()=='R'){
                                    if(!griglia.IsColumnFull(c))  griglia.Insert(c,this->pedina); 
                                } break;
                               }
           if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2; continue;}
            }
    
    }else if(color=='B'){    
        for (a=0,b=1,c=2,d=3,n=0;d<6;a++,b++,c++,d++) {
            if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n][b].getChar()=='B' && griglia.Matrix[n][d].getChar()=='B'  
            && griglia.Matrix[n-1][c].getChar()!='0' && griglia.Matrix[n][c].getChar()=='0') {
                                if(this->getColour()=='B') {
                                   if(!griglia.IsColumnFull(c))  griglia.Insert(c,this->pedina);
                                   break;
                                }
            }
           if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2; continue;}
            }   
    }
    
///////////////Attacco Orizzontale [VersoDestra]{Terzultimo Della Fila}/////////
/*Prima Riga*/   
if(color=='R'){
    for (a=0,b=1,c=2,d=3;d<7;a++,b++,c++,d++) {
            if (griglia.Matrix[0][a].getChar()=='R' && griglia.Matrix[0][c].getChar()=='R' && griglia.Matrix[0][d].getChar()=='R' && griglia.Matrix[0][b].getChar()=='0') {
                               if(this->getColour()=='R') {
                                   if(!griglia.IsColumnFull(b))  griglia.Insert(b,this->pedina);
                                   break;
                               }
            }
    }  
}else if(color=='B'){
    for (a=0,b=1,c=2,d=3;d<7;a++,b++,c++,d++) {
            if (griglia.Matrix[0][a].getChar()=='B' && griglia.Matrix[0][c].getChar()=='B' && griglia.Matrix[0][d].getChar()=='B' && griglia.Matrix[0][b].getChar()=='0') {
                               if(this->getColour()=='B') {
                                   if(!griglia.IsColumnFull(b))  griglia.Insert(b,this->pedina);
                                   break;
                               }
            }
    }
}    
/*Altre Righe*/ 
    
if(color='R'){    
    for (a=0,b=1,c=2,d=3,n=0;d<7;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n][c].getChar()=='R' && griglia.Matrix[n][d].getChar()=='R' && griglia.Matrix[n-1][b].getChar()!='0' && griglia.Matrix[n][b].getChar()=='0') {
                          if(this->getColour()=='R') {
                                   if(!griglia.IsColumnFull(b))  griglia.Insert(b,this->pedina);
                                   break;
                               }
                           }
       if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2; continue;}
        }    
}else if(color='B'){    
    for (a=0,b=1,c=2,d=3,n=0;d<7;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n][c].getChar()=='B' && griglia.Matrix[n][d].getChar()=='B' && griglia.Matrix[n-1][b].getChar()!='0' && griglia.Matrix[n][b].getChar()=='0') {
                          if(this->getColour()=='B') {
                                   if(!griglia.IsColumnFull(b))  griglia.Insert(b,this->pedina);
                                   break;
                               }
                           }
       if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2; continue;}
        }    
}   

    
    
    
    
    
    
    
    
    
    
    
    
 /////////////////////////mossa casuale /////////////////////////////
    
    n=rand()%6;
     if(this->getColour()=='R') {if(!griglia.IsColumnFull(n))  griglia.Insert(n,this->pedina);}
     if(this->getColour()=='B') {if(!griglia.IsColumnFull(n))  griglia.Insert(n,this->pedina);}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
 }