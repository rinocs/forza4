
/* 
 * File:   Grid.cpp
 * Author: andrea,riccardo
 * 
 * Created on 11 giugno 2016, 16.27
 */

#include "Grid.h"
#include <cstdio>
//#include "Disc.h"
#include <vector>



Grid::Grid() { 
    /*####### LA GRIGLIA È 6 X 7 ############# */
    
    /*Matrix.resize(6);               
    for(int i=0;i<Matrix.size();i++)
        Matrix[i].resize(7);
     */
    for(int i=0;i<6;i++){
        std::vector<Disc> row;
        for(int j=0;j<7;j++){
            row.push_back(Disc());
        
        }
        Matrix.push_back(row);
    
    }
    // inserimento delle pedine 

    
    
   /* for(int i=0;i<Matrix.size();i++)
        Matrix[i].push_back(Disc());
    */
}

void Grid::PrintGrid() const{
 /*##############   LA MATRICE E' SCRITTA COS' PERCHÈ PER NOI È PIU COMODO CONTROLLARE DAL BASSO VERSO L' ALTO*/   
     printf("\e[2J\e[H");

	
     
     std::cout << std::endl << "-------------------------------------" << std::endl;
     std::cout << "| " << Matrix[5][0] << " | " << Matrix[5][1] << " | " << Matrix[5][2] << " | " << Matrix[5][3] << " | " << Matrix[5][4] << " | " << Matrix[5][5] << " | " << Matrix[5][6] ;
     std::cout << std::endl << "-------------------------------------" << std::endl;
     std::cout << "| " << Matrix[4][0] << " | " << Matrix[4][1] << " | " << Matrix[4][2] << " | " << Matrix[4][3] << " | " << Matrix[4][4] << " | " << Matrix[4][5] << " | " << Matrix[4][6] ;
     std::cout << std::endl << "-------------------------------------" << std::endl;
     std::cout << "| " << Matrix[3][0] << " | " << Matrix[3][1] << " | " << Matrix[3][2] << " | " << Matrix[3][3] << " | " << Matrix[3][4] << " | " << Matrix[3][5] << " | " << Matrix[3][6] ;
     std::cout << std::endl << "-------------------------------------" << std::endl;
     std::cout << "| " << Matrix[2][0] << " | " << Matrix[2][1] << " | " << Matrix[2][2] << " | " << Matrix[2][3] << " | " << Matrix[2][4] << " | " << Matrix[2][5] << " | " << Matrix[2][6] ;
     std::cout << std::endl << "-------------------------------------" << std::endl;
     std::cout << "| " << Matrix[1][0] << " | " << Matrix[1][1] << " | " << Matrix[1][2] << " | " << Matrix[1][3] << " | " << Matrix[1][4] << " | " << Matrix[1][5] << " | " << Matrix[1][6] ;
     std::cout << std::endl << "-------------------------------------" << std::endl;
     std::cout << "| " << Matrix[0][0] << " | " << Matrix[0][1] << " | " << Matrix[0][2] << " | " << Matrix[0][3] << " | " << Matrix[0][4] << " | " << Matrix[0][5] << " | " << Matrix[0][6] ;
     std::cout << std::endl << "-------------------------------------" << std::endl;
     std::cout         << "  0   1   2   3   4   5   6  \n\n";
}

bool Grid::IsColumnFull(int column) {
    
   
    if(this->Matrix[0][column]!='0' && this->Matrix[1][column]!='0' && this->Matrix[2][column]!='0' && this->Matrix[3][column]!='0' && this->Matrix[4][column]!='0' && this->Matrix[5][column]!='0' ){
      return true;
    }else return false; // non è piena
    
    
}


void Grid::Insert(int column,Disc *pedina) {
    
    for(int i=0;i<this->Matrix.size();i++ ){
       if(this->Matrix[i][column] =='0' ){
            this->Matrix[i][column]=*pedina; break;
       }
    }
}




char Grid::Winner(){
    char vincitore=' ';
    
    //Orizzontale
    
     for (int n = 0 ; n < 6 ; n++) {
         for (int a=0,b=1,c=2,d=3 ; d<7 ; a++,b++,c++,d++) {
             if (Matrix[n][a].getChar()=='R' && Matrix[n][b].getChar()=='R' && Matrix[n][c].getChar()=='R' && Matrix[n][d].getChar()=='R') {
                               
                 return 'R';
             }else if (Matrix[n][a].getChar()=='B' && Matrix[n][b].getChar()=='B' && Matrix[n][c].getChar()=='B' && Matrix[n][d].getChar()=='B') {
                               
                  return 'B';      
             
                     }else vincitore= 'N';    
             
             }
         }
     
     
     
     //Verticale
     for (int n = 0 ; n < 7 ; n++) {
         for (int a=0,b=1,c=2,d=3 ; d<6 ; a++,b++,c++,d++) {
             if (Matrix[a][n].getChar()=='R' && Matrix[b][n].getChar()=='R' && Matrix[c][n].getChar()=='R' && Matrix[d][n].getChar()=='R') {
                        return 'R';       
                 }else if (Matrix[a][n].getChar()=='B' && Matrix[b][n].getChar()=='B' && Matrix[c][n].getChar()=='B' && Matrix[d][n].getChar()=='B') {
                        return 'B';    
                        }else vincitore= 'N';
         }
     }
     
     //Diagonale [VersoDestra]
     for (int n = 0 ; n < 3 ; n++) {
         for (int a=0,b=1,c=2,d=3 ; d<7 ; a++,b++,c++,d++) {
             if (Matrix[n][a].getChar()=='R' && Matrix[n+1][b].getChar()=='R' && Matrix[n+2][c].getChar()=='R' && Matrix[n+3][d].getChar()=='R') {
                               
                 return 'R';
             }else if (Matrix[n][a].getChar()=='B' && Matrix[n+1][b].getChar()=='B' && Matrix[n+2][c].getChar()=='B' && Matrix[n+3][d].getChar()=='B') {
                               
                  return 'B';      
             
                     }else vincitore= 'N';    
             }
         }

     //Diagonale [VersoSinistra]
     for (int n = 0 ; n < 3 ; n++) {
         for (int a=3,b=4,c=5,d=6 ; a>0 ; a--,b--,c--,d--) {
            if (Matrix[n][d].getChar()=='R' && Matrix[n+1][c].getChar()=='R' && Matrix[n+2][b].getChar()=='R' && Matrix[n+3][a].getChar()=='R') {
                               
                 return 'R';
             }else if (Matrix[n][d].getChar()=='B' && Matrix[n+1][c].getChar()=='B' && Matrix[n+2][b].getChar()=='B' && Matrix[n+3][a].getChar()=='B') {
                               
                  return 'B' ;     
             
                     }else vincitore= 'N';    
             }
         }
  
    return vincitore;
  }