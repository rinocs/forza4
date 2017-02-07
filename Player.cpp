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
///////////////////////////////////////////////
/*############## metodi Player ##############*/
///////////////////////////////////////////////
bool Player::flag_colour=false;
char Player::colour_disc=' ';


/*########### metodi Human Player     ###########*/
Human_Player::Human_Player(std::string name_){
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
        if (column <0 || column >6) std::cout<<"errore,reinserire la colonna."<<std::endl;
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
    
    this->name=orig.Player::name;
    this->pedina= new Disc(*orig.pedina);
}

 char PC_Player::getColour() const{return this->pedina->getChar();}


 void PC_Player::Decision(Grid &griglia){
    char color=this->getColour();

    std::cout << "Giocata del computer: "<<std::endl;
    int a,b,c,d;
    int n;
    srand((unsigned)time( NULL )); // inizializza la funzione rand()

    
if(color=='R'){   
    
 
    
    
    ///////////////////////////////////////
    /*########## mosse di attacco #######*/
    //////////////////////////////////////
    
    
    
    ///////////////Attacco Verticale/////////////////////////////////////////////////

   
       
        for (a=0,b=1,c=2,d=3,n=0;d<6;a++,b++,c++,d++) {

            if (griglia.Matrix[a][n].getChar()=='R' && griglia.Matrix[b][n].getChar()=='R' && griglia.Matrix[c][n].getChar()=='R'  &&  griglia.Matrix[d][n].getChar()=='0'  ) {

                    griglia.Insert(n,this->pedina);  return;
                    
                }

            if (d==5 && n<7) {n++;a=-1;b=0;c=1;d=2; continue;}
        }
///////////////Attacco Orizzontale [VersoDestra]{Ultimo Della Fila}/////////////
/*Prima Riga*/

        for (a=0,b=1,c=2,d=3;d<6;a++,b++,c++,d++) {
            if (griglia.Matrix[0][a].getChar()=='R' && griglia.Matrix[0][b].getChar()=='R' && griglia.Matrix[0][c].getChar()=='R' && griglia.Matrix[0][d].getChar()=='0') {

                      griglia.Insert(d,this->pedina);  return;
                       
            }
        }
/*Altre Righe*/
      
        for (a=0,b=1,c=2,d=3,n=1;d<6;a++,b++,c++,d++) {
            if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n][b].getChar()=='R' && griglia.Matrix[n][c].getChar()=='R' && griglia.Matrix[n-1][d].getChar()!='0' && griglia.Matrix[n][d].getChar()=='0') {

                  griglia.Insert(d,this->pedina); return;
                  

            }
           if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2; continue;}
            }
///////////////Attacco Orizzontale [VersoDestra]{Penultimo Della Fila}//////////
/*Prima Riga*/
        
        for (a=0,b=1,c=2,d=3;d<6;a++,b++,c++,d++) {
            if (griglia.Matrix[0][a].getChar()=='R' && griglia.Matrix[0][b].getChar()=='R' && griglia.Matrix[0][d].getChar()=='R' && griglia.Matrix[0][c].getChar()=='0') {

                        griglia.Insert(c,this->pedina); return;
                       
            }
        }
/*Altre Righe*/
        
      for (a=0,b=1,c=2,d=3,n=1;d<6;a++,b++,c++,d++) {
            if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n][b].getChar()=='R' && griglia.Matrix[n][d].getChar()=='R' && griglia.Matrix[n-1][c].getChar()!='0' && griglia.Matrix[n][c].getChar()=='0') {

                         griglia.Insert(c,this->pedina);  return;
                         
           }
           if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2;}
        }
///////////////Attacco Orizzontale [VersoDestra]{Terzultimo Della Fila}/////////
/*Prima Riga*/
    
        for (a=0,b=1,c=2,d=3;d<7;a++,b++,c++,d++) {
                if (griglia.Matrix[0][a].getChar()=='R' && griglia.Matrix[0][c].getChar()=='R' && griglia.Matrix[0][d].getChar()=='R' && griglia.Matrix[0][b].getChar()=='0') {

                        griglia.Insert(b,this->pedina);  return;
                        

                }
        }
/*Altre Righe*/
        for (a=0,b=1,c=2,d=3,n=1;d<6;a++,b++,c++,d++) {
            if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n][c].getChar()=='R' && griglia.Matrix[n][d].getChar()=='R' && griglia.Matrix[n-1][b].getChar()!='0' && griglia.Matrix[n][b].getChar()=='0') {
                      griglia.Insert(b,this->pedina); return;
                     
            }
            if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2; }
        }
///////////////Attacco Orizzontale [VersoSinistra]{Ultimo Della Fila}///////////
/*Prima Riga*/       
    for (a=6,b=5,c=4,d=3;d>0;a--,b--,c--,d--) {
            if (griglia.Matrix[0][a].getChar()=='R' && griglia.Matrix[0][b].getChar()=='R' && griglia.Matrix[0][c].getChar()=='R' && griglia.Matrix[0][d].getChar()=='0') {
                 griglia.Insert(d,this->pedina);  return;
               
            }
    }
/*Altre Righe*/   
    for (a=6,b=5,c=4,d=3,n=1;d>0;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n][b].getChar()=='R' && griglia.Matrix[n][c].getChar()=='R' && griglia.Matrix[n-1][d].getChar()!='0' && griglia.Matrix[n][d].getChar()=='0') {
                 griglia.Insert(d,this->pedina); return;
               
        if (d==0 && n<6) {n++;a=7;b=6;c=5;d=4; }
        }
    }
///////////////Attacco Orizzontale [VersoSinistra]{Penultimo Della Fila}////////
/*Prima Riga*/     
      for (a=6,b=5,c=4,d=3;d>0;a--,b--,c--,d--) {
            if (griglia.Matrix[0][a].getChar()=='R' && griglia.Matrix[0][b].getChar()=='R' && griglia.Matrix[0][d].getChar()=='R' && griglia.Matrix[0][c].getChar()=='0') {
                griglia.Insert(c,this->pedina); return;
                
            }
        }
/*Altre Righe*/    
       for (a=6,b=5,c=4,d=3,n=1;d>0;a--,b--,c--,d--) {
              if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n][b].getChar()=='R' && griglia.Matrix[n][d].getChar()=='R' && griglia.Matrix[n-1][c].getChar()!='0'  &&griglia.Matrix[n][c].getChar()=='0') {
                griglia.Insert(c,this->pedina);  return;
                
            }
           if (d==0 && n<6) {n++;a=7;b=6;c=5;d=4;}
        }
        
///////////////Attacco Orizzontale [VersoSinistra]{Terzultimo Della Fila}///////
/*Prima Riga*/     
        for (a=6,b=5,c=4,d=3;d>0;a--,b--,c--,d--) {
            if (griglia.Matrix[0][a].getChar()=='R' && griglia.Matrix[0][c].getChar()=='R' && griglia.Matrix[0][d].getChar()=='R' && griglia.Matrix[0][b].getChar()=='0') {
                     griglia.Insert(b,this->pedina); return;
                  
            }
        }
/*Altre Righe*/    
       for (a=6,b=5,c=4,d=3,n=1;d>0;a--,b--,c--,d--) {
            if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n][c].getChar()=='R' && griglia.Matrix[n][d].getChar()=='R' && griglia.Matrix[n-1][b].getChar()=='0' && griglia.Matrix[n][b].getChar()=='0') {
                    griglia.Insert(b,this->pedina); return;
                   
            
            if (d==0 && n<6) {n++;a=7;b=6;c=5;d=4; }
            }            
        }    
 ///////////////Attacco Diagonale [VersoDestra]{Ultimo Della Fila}///////////////
    for (a=0,b=1,c=2,d=3,n=0;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n+1][b].getChar()=='R' && griglia.Matrix[n+2][c].getChar()=='R'  && griglia.Matrix[n+2][d].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='0') {
                griglia.Insert(d,this->pedina); return;
                
        }
       if (d==6 && n<3) {n++;a=-1;b=0;c=1;d=2;}
    }
///////////////Attacco Diagonale [VersoDestra]{Penultimo Della Fila}////////////
    for (a=0,b=1,c=2,d=3,n=0;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n+1][b].getChar()=='R' && griglia.Matrix[n+2][c].getChar()=='0' && griglia.Matrix[n+1][c].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='R') {
                griglia.Insert(c,this->pedina);return;
                
        }
       if (d==6 && n<3) {n++;a=-1;b=0;c=1;d=2; }
    }            
///////////////Attacco Diagonale [VersoDestra]{Terzultimo Della Fila}///////////
    for (a=0,b=1,c=2,d=3,n=0;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n+1][b].getChar()=='0' && griglia.Matrix[n+2][c].getChar()=='R' && griglia.Matrix[n+3][d].getChar()=='R' && griglia.Matrix[n][b].getChar()!='0') {
                       griglia.Insert(b,this->pedina); return;
                           
        }
        if (d==6 && n<3) {n++;a=-1;b=0;c=1;d=2; }
    }             
///////////////Attacco Diagonale [VersoSinistra]{Ultimo Della Fila}/////////////
    for (a=6,b=5,c=4,d=3,n=0;d>-1;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n+1][b].getChar()=='R' && griglia.Matrix[n+2][c].getChar()=='R' && griglia.Matrix[n+2][d].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='0') {
                        griglia.Insert(d,this->pedina); return;
                        
        }
       if (d==0 && n<3) {n++;a=7;b=6;c=5;d=4;}
        }

///////////////Attacco Diagonale [VersoSinistra]{Penultimo Della Fila}//////////
    for (a=6,b=5,c=4,d=3,n=0;d>-1;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n+1][b].getChar()=='R' && griglia.Matrix[n+2][c].getChar()=='0' && griglia.Matrix[n+1][c].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='R') {
                          griglia.Insert(c,this->pedina); return;
                          
        }
       if (d==0 && n<3) {n++;a=7;b=6;c=5;d=4; }
        }

///////////////Attacco Diagonale [VersoSinistra]{Terzultimo Della Fila}/////////
    for (a=6,b=5,c=4,d=3,n=0;d>-1;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n+1][b].getChar()=='0' && griglia.Matrix[n+2][c].getChar()=='0' && griglia.Matrix[n][b].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='R') {
                           griglia.Insert(b,this->pedina);  return;
        }
        if (d==0 && n<3) {n++;a=7;b=6;c=5;d=4; continue;}
        }
        
   
////////////////////////////////////////////////////////////////////////////////
///////////////Mosse di Difesa//////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
    

 /*-------------------------------------------------------------------------------*/

///////////////Difesa Verticale/////////////////////////////////////////////////
    for (a=0,b=1,c=2,d=3,n=0 ; d<6 ; a++,b++,c++,d++) {
        if (griglia.Matrix[a][n].getChar()=='B' && griglia.Matrix[b][n].getChar()=='B' && griglia.Matrix[c][n].getChar()=='B'  && griglia.Matrix[d][n].getChar()=='0') {
                 griglia.Insert(n,this->pedina); return;   
        }
        if(d==5 && n<7){n++;a=-1;b=0;c=1;d=2;}
    } 
        
  ///////////////Difesa Orizzontale [VersoDestra]{Ultimo Della Fila}//////////////
 /*Prima Riga*/
    for (a=0,b=1,c=2,d=3;d<6;a++,b++,c++,d++) {
            if (griglia.Matrix[0][a].getChar()=='B' && griglia.Matrix[0][b].getChar()=='B' && griglia.Matrix[0][c].getChar()=='B' &&  griglia.Matrix[0][d].getChar()=='0') {
                    griglia.Insert(d,this->pedina); return;
            }
                               
    }
 /*Altre Righe*/  
    for (a=0,b=1,c=2,d=3,n=1;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n][b].getChar()=='B' && griglia.Matrix[n][c].getChar()=='B' && griglia.Matrix[n-1][d].getChar()!='0' && griglia.Matrix[n][d].getChar()=='0') {
                           griglia.Insert(d,this->pedina); return;
        }
       if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2;}
    }
  
///////////////Difesa Orizzontale [VersoDestra]{Penultimo Della Fila}///////////
/*Prima Riga*/      
    for (a=0,b=1,c=2,d=3;d<6;a++,b++,c++,d++) {
            if (griglia.Matrix[0][a].getChar()=='B' && griglia.Matrix[0][b].getChar()=='B' && griglia.Matrix[0][d].getChar()=='B' && griglia.Matrix[0][c].getChar()=='0') {
                    griglia.Insert(c,this->pedina); return;
            }
    }
/*Altre Bighe*/   
    for (a=0,b=1,c=2,d=3,n=1;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n][b].getChar()=='B' && griglia.Matrix[n][d].getChar()=='B' && griglia.Matrix[n-1][c].getChar()!='0' && griglia.Matrix[n][c].getChar()=='0') {
                           griglia.Insert(c,this->pedina); return;
                           }
       if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2;}
        }   
       
    
 ///////////////Difesa Orizzontale [VersoDestra]{Terzultimo Della Fila}///////////
/*Prima Biga*/      
    for (a=0,b=1,c=2,d=3;d<6;a++,b++,c++,d++) {
            if (griglia.Matrix[0][a].getChar()=='B' && griglia.Matrix[0][c].getChar()=='B' && griglia.Matrix[0][d].getChar()=='B' && griglia.Matrix[0][b].getChar()=='0') {
                    griglia.Insert(b,this->pedina); return;
            }
    }
/*Altre Bighe*/   
    for (a=0,b=1,c=2,d=3,n=1;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n][c].getChar()=='B' && griglia.Matrix[n][d].getChar()=='B' && griglia.Matrix[n-1][b].getChar()!='0' && griglia.Matrix[n][b].getChar()=='0') {
                           griglia.Insert(b,this->pedina); return;
                           }
       if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2;}
    }
///////////////Difesa Orizzontale [VersoSinistra]{Ultimo Della Fila}////////////
/*Prima Biga*/        
    for (a=6,b=5,c=4,d=3;d>0;a--,b--,c--,d--) {
        if (griglia.Matrix[0][a].getChar()=='B' && griglia.Matrix[0][b].getChar()=='B' && griglia.Matrix[0][c].getChar()=='B' && griglia.Matrix[0][d].getChar()=='0') {
                    griglia.Insert(d,this->pedina); return;
        }
    }
/*Altre Bighe*/   
    for (a=6,b=5,c=4,d=3,n=1;d>0;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n][b].getChar()=='B' && griglia.Matrix[n][c].getChar()=='B' && griglia.Matrix[n-1][d].getChar()!='0' &&griglia.Matrix[n][d].getChar()=='0') {
                    griglia.Insert(d,this->pedina); return;
        }
        if (d==0 && n<6) {n++;a=7;b=6;c=5;d=4; }
    }
///////////////Difesa Orizzontale [VersoSinistra]{Penultimo Della Fila}////////////
/*Prima Biga*/        
    for (a=6,b=5,c=4,d=3;d>0;a--,b--,c--,d--) {
        if (griglia.Matrix[0][a].getChar()=='B' && griglia.Matrix[0][b].getChar()=='B' && griglia.Matrix[0][d].getChar()=='B' && griglia.Matrix[0][c].getChar()=='0') {
                    griglia.Insert(c,this->pedina); return;
        }
    }
/*Altre Bighe*/   
    for (a=6,b=5,c=4,d=3,n=1;d>0;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n][b].getChar()=='B' && griglia.Matrix[n][d].getChar()=='B' && griglia.Matrix[n-1][c].getChar()!='0' && griglia.Matrix[n][c].getChar()=='0') {
                    griglia.Insert(c,this->pedina); return;
        }
        if (d==0 && n<6) {n++;a=7;b=6;c=5;d=4; }
    }
///////////////Difesa Orizzontale [VersoSinistra]{Terzultimo Della Fila}////////////
/*Prima Biga*/        
    for (a=6,b=5,c=4,d=3;d>0;a--,b--,c--,d--) {
        if (griglia.Matrix[0][a].getChar()=='B' && griglia.Matrix[0][c].getChar()=='B' && griglia.Matrix[0][d].getChar()=='B' && griglia.Matrix[0][b].getChar()=='0') {
                    griglia.Insert(b,this->pedina); return;
        }
    }
/*Altre Bighe*/   
    for (a=6,b=5,c=4,d=3,n=1;d>0;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n][c].getChar()=='B' && griglia.Matrix[n][d].getChar()=='B' && griglia.Matrix[n-1][b].getChar()!='0' && griglia.Matrix[n][b].getChar()=='0') {
                    griglia.Insert(b,this->pedina); return;
        }
        if (d==0 && n<6) {n++;a=7;b=6;c=5;d=4; }
    }    
 
///////////////Difesa Diagonale [VersoDestra]{Ultimo Della Fila}////////////////
    for (a=0,b=1,c=2,d=3,n=0;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n+1][b].getChar()=='B' && griglia.Matrix[n+2][c].getChar()=='B' && griglia.Matrix[n+2][d].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='0') {
                      griglia.Insert(d,this->pedina); return;
                           }
       if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2;}
        }  
///////////////Difesa Diagonale [VersoDestra]{Penultimo Della Fila}////////////////
    for (a=0,b=1,c=2,d=3,n=0;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n+1][b].getChar()=='B' && griglia.Matrix[n+2][c].getChar()=='0' && griglia.Matrix[n+1][c].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='B') {
                      griglia.Insert(c,this->pedina); return;
                           }
       if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2;}
        }        
    
///////////////Difesa Diagonale [VersoDestra]{Terzultimo Della Fila}////////////////
    for (a=0,b=1,c=2,d=3,n=0;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n+1][b].getChar()=='0' && griglia.Matrix[n+2][c].getChar()=='B' && griglia.Matrix[n][b].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='B') {
                      griglia.Insert(b,this->pedina); return;
                           }
       if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2;}
        }
///////////////Difesa Diagonale [VersoDestra]{Quartultimo Della Fila}////////////////
/*prima riga*/
  for (a=0,b=1,c=2,d=3;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[0][a].getChar()=='0' && griglia.Matrix[1][b].getChar()=='B' && griglia.Matrix[2][c].getChar()=='B' && griglia.Matrix[3][d].getChar()=='B') {
                      griglia.Insert(a,this->pedina); return;
        }
   }
 /*altre righe*/   
    for (a=0,b=1,c=2,d=3,n=1;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='0' && griglia.Matrix[n+1][b].getChar()=='B' && griglia.Matrix[n+2][c].getChar()=='B' && griglia.Matrix[n-1][a].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='B') {
                      griglia.Insert(a,this->pedina); return;
            }
        if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2;}
    } 

///////////////Difesa Diagonale [VersoSinistra]{Ultimo Della Fila}//////////////
    for (a=6,b=5,c=4,d=3,n=0;d>-1;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n+1][b].getChar()=='B' && griglia.Matrix[n+2][c].getChar()=='B'  && griglia.Matrix[n+2][d].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='0') {
            griglia.Insert(d,this->pedina); return;
        }
        if (d==0 && n<3) {n++;a=7;b=6;c=5;d=4;}
    }
///////////////Difesa Diagonale [VersoSinistra]{Penultimo Della Fila}//////////////
    for (a=6,b=5,c=4,d=3,n=0;d>-1;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n+1][b].getChar()=='B' && griglia.Matrix[n+2][c].getChar()=='0'  && griglia.Matrix[n+1][c].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='B') {
            griglia.Insert(c,this->pedina); return;
        }
        if (d==0 && n<3) {n++;a=7;b=6;c=5;d=4;}
    }  
///////////////Difesa Diagonale [VersoSinistra]{Terzultimo Della Fila}//////////////
    for (a=6,b=5,c=4,d=3,n=0;d>-1;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n+1][b].getChar()=='0' && griglia.Matrix[n+2][c].getChar()=='B'  && griglia.Matrix[n][b].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='B') {
            griglia.Insert(b,this->pedina); return;
        }
        if (d==0 && n<3) {n++;a=7;b=6;c=5;d=4;}
    }
///////////////Difesa Diagonale [VersoSinistra]{Quartultimo Della Fila}//////////////
/*prima riga*/
  for (a=6,b=5,c=4,d=3;d>-1;a--,b--,c--,d--) {
        if (griglia.Matrix[0][a].getChar()=='0' && griglia.Matrix[1][b].getChar()=='B' && griglia.Matrix[2][c].getChar()=='B' && griglia.Matrix[3][d].getChar()=='B') {
            griglia.Insert(a,this->pedina); return;
        }
    }
  
 /*altre righe*/ 
 for (a=6,b=5,c=4,d=3,n=1;d>-1;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='0' && griglia.Matrix[n+1][b].getChar()=='B' && griglia.Matrix[n+2][c].getChar()=='B'  && griglia.Matrix[n-1][a].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='B') {
            griglia.Insert(a,this->pedina); return;
        }
        if (d==0 && n<3) {n++;a=7;b=6;c=5;d=4;}
    }  
       
 
    
                          
   }else if(color=='B'){
       

    ///////////////////////////////////////
    /*########## mosse di attacco #######*/
    //////////////////////////////////////
    
    
  for (a=0,b=1,c=2,d=3,n=0;d<6;a++,b++,c++,d++) {

            if (griglia.Matrix[a][n].getChar()=='B' && griglia.Matrix[b][n].getChar()=='B' && griglia.Matrix[c][n].getChar()=='B'  &&  griglia.Matrix[d][n].getChar()=='0'  ) {

                    griglia.Insert(n,this->pedina);  return;
                    
                }

            if (d==5 && n<7) {n++;a=-1;b=0;c=1;d=2; continue;}
        }
///////////////Attacco Orizzontale [VersoDestra]{Ultimo Della Fila}/////////////
/*Prima Biga*/

        for (a=0,b=1,c=2,d=3;d<7;a++,b++,c++,d++) {
            if (griglia.Matrix[0][a].getChar()=='B' && griglia.Matrix[0][b].getChar()=='B' && griglia.Matrix[0][c].getChar()=='B' && griglia.Matrix[0][d].getChar()=='0') {

                      griglia.Insert(d,this->pedina);  return;
                       
            }
        }
/*Altre Righe*/
      
        for (a=0,b=1,c=2,d=3,n=1;d<6;a++,b++,c++,d++) {
            if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n][b].getChar()=='B' && griglia.Matrix[n][c].getChar()=='B' && griglia.Matrix[n-1][d].getChar()!='0' && griglia.Matrix[n][d].getChar()=='0') {

                  griglia.Insert(d,this->pedina); return;
                  

            }
           if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2; continue;}
            }
///////////////Attacco Orizzontale [VersoDestra]{Penultimo Della Fila}//////////
/*Prima Biga*/
        
        for (a=0,b=1,c=2,d=3;d<6;a++,b++,c++,d++) {
            if (griglia.Matrix[0][a].getChar()=='B' && griglia.Matrix[0][b].getChar()=='B' && griglia.Matrix[0][d].getChar()=='B' && griglia.Matrix[0][c].getChar()=='0') {

                        griglia.Insert(c,this->pedina); return;
                       
            }
        }
/*Altre Bighe*/
        
      for (a=0,b=1,c=2,d=3,n=1;d<6;a++,b++,c++,d++) {
            if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n][b].getChar()=='B' && griglia.Matrix[n][d].getChar()=='B'&& griglia.Matrix[n-1][c].getChar()!='0' && griglia.Matrix[n][c].getChar()=='0') {

                         griglia.Insert(c,this->pedina);  return;
                         
           }
           if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2;}
        }
///////////////Attacco Orizzontale [VersoDestra]{Terzultimo Della Fila}/////////
/*Prima Biga*/
    
        for (a=0,b=1,c=2,d=3;d<6;a++,b++,c++,d++) {
                if (griglia.Matrix[0][a].getChar()=='B' && griglia.Matrix[0][c].getChar()=='B' && griglia.Matrix[0][d].getChar()=='B' && griglia.Matrix[0][b].getChar()=='0') {

                        griglia.Insert(b,this->pedina);  return;
                        

                }
        }
/*Altre Bighe*/
        for (a=0,b=1,c=2,d=3,n=1;d<6;a++,b++,c++,d++) {
            if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n][c].getChar()=='B' && griglia.Matrix[n][d].getChar()=='B' &&  griglia.Matrix[n-1][b].getChar()!='0' && griglia.Matrix[n][b].getChar()=='0') {
                      griglia.Insert(b,this->pedina); return;
                     
            }
            if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2; }
        }
///////////////Attacco Orizzontale [VersoSinistra]{Ultimo Della Fila}///////////
/*Prima Biga*/       
    for (a=6,b=5,c=4,d=3;d>0;a--,b--,c--,d--) {
            if (griglia.Matrix[0][a].getChar()=='B' && griglia.Matrix[0][b].getChar()=='B' && griglia.Matrix[0][c].getChar()=='B' && griglia.Matrix[0][d].getChar()=='0') {
                 griglia.Insert(d,this->pedina);  return;
               
            }
    }
/*Altre Bighe*/   
    for (a=6,b=5,c=4,d=3,n=1;d>0;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n][b].getChar()=='B' && griglia.Matrix[n][c].getChar()=='B' && griglia.Matrix[n-1][d].getChar()!='0' && griglia.Matrix[n][d].getChar()=='0') {
                 griglia.Insert(d,this->pedina); return;
               
        if (d==0 && n<6) {n++;a=7;b=6;c=5;d=4; }
        }
    }
///////////////Attacco Orizzontale [VersoSinistra]{Penultimo Della Fila}////////
/*Prima Biga*/     
      for (a=6,b=5,c=4,d=3;d>0;a--,b--,c--,d--) {
            if (griglia.Matrix[0][a].getChar()=='B' && griglia.Matrix[0][b].getChar()=='B' && griglia.Matrix[0][d].getChar()=='B' && griglia.Matrix[0][c].getChar()=='0') {
                griglia.Insert(c,this->pedina); return;
                
            }
        }
/*Altre Bighe*/    
       for (a=6,b=5,c=4,d=3,n=1;d>0;a--,b--,c--,d--) {
              if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n][b].getChar()=='B' && griglia.Matrix[n][d].getChar()=='B' && griglia.Matrix[n-1][c].getChar()!='0' && griglia.Matrix[n][c].getChar()=='0') {
                griglia.Insert(c,this->pedina);  return;
                
            }
           if (d==0 && n<6) {n++;a=7;b=6;c=5;d=4;}
        }
        
///////////////Attacco Orizzontale [VersoSinistra]{Terzultimo Della Fila}///////
/*Prima Biga*/     
        for (a=6,b=5,c=4,d=3;d>0;a--,b--,c--,d--) {
            if (griglia.Matrix[0][a].getChar()=='B' && griglia.Matrix[0][c].getChar()=='B' && griglia.Matrix[0][d].getChar()=='B' && griglia.Matrix[0][b].getChar()=='0') {
                     griglia.Insert(b,this->pedina); return;
                  
            }
        }
/*Altre Bighe*/    
       for (a=6,b=5,c=4,d=3,n=1;d>0;a--,b--,c--,d--) {
            if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n][c].getChar()=='B' && griglia.Matrix[n][d].getChar()=='B' && griglia.Matrix[n-1][b].getChar()=='0' && griglia.Matrix[n][b].getChar()=='0') {
                    griglia.Insert(b,this->pedina); return;
                   
            
            if (d==0 && n<6) {n++;a=7;b=6;c=5;d=4; }
            }            
        }    
 ///////////////Attacco Diagonale [VersoDestra]{Ultimo Della Fila}///////////////
    for (a=0,b=1,c=2,d=3,n=0;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n+1][b].getChar()=='B' && griglia.Matrix[n+2][c].getChar()=='B'  && griglia.Matrix[n+2][d].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='0') {
                griglia.Insert(d,this->pedina); return;
                
        }
       if (d==6 && n<3) {n++;a=-1;b=0;c=1;d=2;}
    }
///////////////Attacco Diagonale [VersoDestra]{Penultimo Della Fila}////////////
    for (a=0,b=1,c=2,d=3,n=0;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n+1][b].getChar()=='B' && griglia.Matrix[n+2][c].getChar()=='0' && griglia.Matrix[n+1][c].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='B') {
                griglia.Insert(c,this->pedina);return;
                
        }
       if (d==6 && n<3) {n++;a=-1;b=0;c=1;d=2; }
    }            
///////////////Attacco Diagonale [VersoDestra]{Terzultimo Della Fila}///////////
    for (a=0,b=1,c=2,d=3,n=0;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n+1][b].getChar()=='0' && griglia.Matrix[n+2][c].getChar()=='B' && griglia.Matrix[n+3][d].getChar()=='B' && griglia.Matrix[n][b].getChar()!='0') {
                       griglia.Insert(b,this->pedina); return;
                           
        }
        if (d==6 && n<3) {n++;a=-1;b=0;c=1;d=2; }
    }             
///////////////Attacco Diagonale [VersoSinistra]{Ultimo Della Fila}/////////////
    for (a=6,b=5,c=4,d=3,n=0;d>-1;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n+1][b].getChar()=='B' && griglia.Matrix[n+2][c].getChar()=='B' && griglia.Matrix[n+2][d].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='0') {
                        griglia.Insert(d,this->pedina); return;
                        
        }
       if (d==0 && n<3) {n++;a=7;b=6;c=5;d=4;}
        }

///////////////Attacco Diagonale [VersoSinistra]{Penultimo Della Fila}//////////
    for (a=6,b=5,c=4,d=3,n=0;d>-1;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n+1][b].getChar()=='B' && griglia.Matrix[n+2][c].getChar()=='0' && griglia.Matrix[n+1][c].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='B') {
                          griglia.Insert(c,this->pedina); return;
                          
        }
       if (d==0 && n<3) {n++;a=7;b=6;c=5;d=4; }
        }

///////////////Attacco Diagonale [VersoSinistra]{Terzultimo Della Fila}/////////
    for (a=6,b=5,c=4,d=3,n=0;d>-1;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='B' && griglia.Matrix[n+1][b].getChar()=='0' && griglia.Matrix[n+2][c].getChar()=='0' && griglia.Matrix[n][b].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='B') {
                           griglia.Insert(b,this->pedina);  return;
        }
        if (d==0 && n<3) {n++;a=7;b=6;c=5;d=4; continue;}
        }              

 
////////////////////////////////////////////////////////////////////////////////
///////////////Mosse di Difesa//////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

///////////////Difesa Verticale/////////////////////////////////////////////////
  for (a=0,b=1,c=2,d=3,n=0 ; d<6 ; a++,b++,c++,d++) {
        if (griglia.Matrix[a][n].getChar()=='R' && griglia.Matrix[b][n].getChar()=='R' && griglia.Matrix[c][n].getChar()=='R'  && griglia.Matrix[d][n].getChar()=='0') {
                 griglia.Insert(n,this->pedina); return;   
        }
        if(d==5 && n<6){n++;a=-1;b=0;c=1;d=2;} //per riazzerare il ciclo
    }
  ///////////////Difesa Orizzontale [VersoDestra]{Ultimo Della Fila}//////////////
 /*Prima Riga*/
    for (a=0,b=1,c=2,d=3;d<6;a++,b++,c++,d++) {
            if (griglia.Matrix[0][a].getChar()=='R' && griglia.Matrix[0][b].getChar()=='R' && griglia.Matrix[0][c].getChar()=='R' &&  griglia.Matrix[0][d].getChar()=='0') {
                    griglia.Insert(d,this->pedina); return;
            }
                               
    }
 /*Altre Righe*/  
    for (a=0,b=1,c=2,d=3,n=1;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n][b].getChar()=='R' && griglia.Matrix[n][c].getChar()=='R' && griglia.Matrix[n-1][d].getChar()!='0' && griglia.Matrix[n][d].getChar()=='0') {
                           griglia.Insert(d,this->pedina); return;
        }
        if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2;}
    }
  
///////////////Difesa Orizzontale [VersoDestra]{Penultimo Della Fila}///////////
/*Prima Riga*/      
    for (a=0,b=1,c=2,d=3;d<6;a++,b++,c++,d++) {
            if (griglia.Matrix[0][a].getChar()=='R' && griglia.Matrix[0][b].getChar()=='R' && griglia.Matrix[0][d].getChar()=='R' && griglia.Matrix[0][c].getChar()=='0') {
                    griglia.Insert(c,this->pedina); return;
            }
    }
/*Altre Righe*/   
    for (a=0,b=1,c=2,d=3,n=1;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n][b].getChar()=='R' && griglia.Matrix[n][d].getChar()=='R' && griglia.Matrix[n-1][c].getChar()!='0' && griglia.Matrix[n][c].getChar()=='0') {
                           griglia.Insert(c,this->pedina); return;
                           }
       if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2;}
        }   
       
    
 ///////////////Difesa Orizzontale [VersoDestra]{Terzultimo Della Fila}///////////
/*Prima Riga*/      
    for (a=0,b=1,c=2,d=3;d<6;a++,b++,c++,d++) {
            if (griglia.Matrix[0][a].getChar()=='R' && griglia.Matrix[0][c].getChar()=='R' && griglia.Matrix[0][d].getChar()=='R' && griglia.Matrix[0][b].getChar()=='0') {
                    griglia.Insert(b,this->pedina); return;
            }
    }
/*Altre Righe*/   
    for (a=0,b=1,c=2,d=3,n=1;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n][c].getChar()=='R' && griglia.Matrix[n][d].getChar()=='R' && griglia.Matrix[n-1][b].getChar()!='0' && griglia.Matrix[n][b].getChar()=='0') {
                           griglia.Insert(b,this->pedina); return;
                           }
       if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2;}
    }
///////////////Difesa Orizzontale [VersoSinistra]{Ultimo Della Fila}////////////
/*Prima Riga*/        
    for (a=6,b=5,c=4,d=3;d>0;a--,b--,c--,d--) {
        if (griglia.Matrix[0][a].getChar()=='R' && griglia.Matrix[0][b].getChar()=='R' && griglia.Matrix[0][c].getChar()=='R' && griglia.Matrix[0][d].getChar()=='0') {
                    griglia.Insert(d,this->pedina); return;
        }
    }
/*Altre Righe*/   
    for (a=6,b=5,c=4,d=3,n=1;d>0;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n][b].getChar()=='R' && griglia.Matrix[n][c].getChar()=='R' && griglia.Matrix[n-1][d].getChar()!='0' &&griglia.Matrix[n][d].getChar()=='0') {
                    griglia.Insert(d,this->pedina); return;
        }
        if (d==0 && n<6) {n++;a=7;b=6;c=5;d=4; }
    }
///////////////Difesa Orizzontale [VersoSinistra]{Penultimo Della Fila}////////////
/*Prima Riga*/        
    for (a=6,b=5,c=4,d=3;d>0;a--,b--,c--,d--) {
        if (griglia.Matrix[0][a].getChar()=='R' && griglia.Matrix[0][b].getChar()=='R' && griglia.Matrix[0][d].getChar()=='R' && griglia.Matrix[0][c].getChar()=='0') {
                    griglia.Insert(c,this->pedina); return;
        }
    }
/*Altre Righe*/   
    for (a=6,b=5,c=4,d=3,n=1;d>0;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n][b].getChar()=='R' && griglia.Matrix[n][d].getChar()=='R' && griglia.Matrix[n-1][c].getChar()!='0' &&griglia.Matrix[n][c].getChar()=='0') {
                    griglia.Insert(c,this->pedina); return;
        }
        if (d==0 && n<6) {n++;a=7;b=6;c=5;d=4; }
    }
///////////////Difesa Orizzontale [VersoSinistra]{Terzultimo Della Fila}////////////
/*Prima Riga*/        
    for (a=6,b=5,c=4,d=3;d>0;a--,b--,c--,d--) {
        if (griglia.Matrix[0][a].getChar()=='R' && griglia.Matrix[0][c].getChar()=='R' && griglia.Matrix[0][d].getChar()=='R' && griglia.Matrix[0][b].getChar()=='0') {
                    griglia.Insert(b,this->pedina); return;
        }
    }
/*Altre Righe*/   
    for (a=6,b=5,c=4,d=3,n=1;d>0;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n][c].getChar()=='R' && griglia.Matrix[n][d].getChar()=='R' && griglia.Matrix[n-1][b].getChar()!='0' &&griglia.Matrix[n][b].getChar()=='0') {
                    griglia.Insert(b,this->pedina); return;
        }
        if (d==0 && n<6) {n++;a=7;b=6;c=5;d=4; }
    }    
  
  ///////////////Difesa Diagonale [VersoDestra]{Ultimo Della Fila}////////////////
    for (a=0,b=1,c=2,d=3,n=0;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n+1][b].getChar()=='R' && griglia.Matrix[n+2][c].getChar()=='R' && griglia.Matrix[n+2][d].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='0') {
                      griglia.Insert(d,this->pedina); return;
                           }
       if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2;}
        }  
///////////////Difesa Diagonale [VersoDestra]{Penultimo Della Fila}////////////////
    for (a=0,b=1,c=2,d=3,n=0;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n+1][b].getChar()=='R' && griglia.Matrix[n+2][c].getChar()=='0' && griglia.Matrix[n+1][c].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='R') {
                      griglia.Insert(c,this->pedina); return;
                           }
       if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2;}
        }        
    
///////////////Difesa Diagonale [VersoDestra]{Terzultimo Della Fila}////////////////
    for (a=0,b=1,c=2,d=3,n=0;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n+1][b].getChar()=='0' && griglia.Matrix[n+2][c].getChar()=='R' && griglia.Matrix[n][b].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='R') {
                      griglia.Insert(b,this->pedina); return;
                           }
       if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2;}
        }
///////////////Difesa Diagonale [VersoDestra]{Quartultimo Della Fila}////////////////
/*prima riga*/
  for (a=0,b=1,c=2,d=3;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[0][a].getChar()=='0' && griglia.Matrix[1][b].getChar()=='R' && griglia.Matrix[2][c].getChar()=='R' && griglia.Matrix[3][d].getChar()=='R') {
                      griglia.Insert(a,this->pedina); return;
        }
   }
  /*altre righe*/
  for (a=0,b=1,c=2,d=3,n=1;d<6;a++,b++,c++,d++) {
        if (griglia.Matrix[n][a].getChar()=='0' && griglia.Matrix[n+1][b].getChar()=='R' && griglia.Matrix[n+2][c].getChar()=='R' && griglia.Matrix[n-1][a].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='R') {
                      griglia.Insert(a,this->pedina); return;
            }
        if (d==6 && n<6) {n++;a=-1;b=0;c=1;d=2;}
    }

///////////////Difesa Diagonale [VersoSinistra]{Ultimo Della Fila}//////////////
    for (a=6,b=5,c=4,d=3,n=0;d>-1;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n+1][b].getChar()=='R' && griglia.Matrix[n+2][c].getChar()=='R'  && griglia.Matrix[n+2][d].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='0') {
            griglia.Insert(d,this->pedina); return;
        }
        if (d==0 && n<3) {n++;a=7;b=6;c=5;d=4;}
    }
  
///////////////Difesa Diagonale [VersoSinistra]{Penultimo Della Fila}//////////////
    for (a=6,b=5,c=4,d=3,n=0;d>-1;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n+1][b].getChar()=='R' && griglia.Matrix[n+2][c].getChar()=='0'  && griglia.Matrix[n+1][c].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='R') {
            griglia.Insert(c,this->pedina); return;
        }
        if (d==0 && n<3) {n++;a=7;b=6;c=5;d=4;}
    }  
///////////////Difesa Diagonale [VersoSinistra]{Terzultimo Della Fila}//////////////
    for (a=6,b=5,c=4,d=3,n=0;d>-1;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='R' && griglia.Matrix[n+1][b].getChar()=='0' && griglia.Matrix[n+2][c].getChar()=='R'  && griglia.Matrix[n][b].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='R') {
            griglia.Insert(b,this->pedina); return;
        }
        if (d==0 && n<3) {n++;a=7;b=6;c=5;d=4;}
    }
///////////////Difesa Diagonale [VersoSinistra]{Quartultimo Della Fila}//////////////
/*prima riga*/
    for (a=6,b=5,c=4,d=3;d>-1;a--,b--,c--,d--) {
        if (griglia.Matrix[0][a].getChar()=='0' && griglia.Matrix[1][b].getChar()=='R' && griglia.Matrix[2][c].getChar()=='R' && griglia.Matrix[3][d].getChar()=='R') {
            griglia.Insert(a,this->pedina); return;
        }
    }
  
 /*altre righe*/ 
  for (a=6,b=5,c=4,d=3,n=1;d>-1;a--,b--,c--,d--) {
        if (griglia.Matrix[n][a].getChar()=='0' && griglia.Matrix[n+1][b].getChar()=='R' && griglia.Matrix[n+2][c].getChar()=='R'  && griglia.Matrix[n-1][a].getChar()!='0' && griglia.Matrix[n+3][d].getChar()=='R') {
            griglia.Insert(a,this->pedina); return;
        }
        if (d==0 && n<3) {n++;a=7;b=6;c=5;d=4;}
    }  
  
                                

  
  
  
   }    
/////////////////////////mossa casuale /////////////////////////////
   
     n=rand()%7;
     if(color=='R') {if(!griglia.IsColumnFull(n))  griglia.Insert(n,this->pedina);}
     if(color=='B')  { if(!griglia.IsColumnFull(n))  griglia.Insert(n,this->pedina);}
 
}
