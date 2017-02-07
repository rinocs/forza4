/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Disc.cpp
 * Author: andrea,riccardo
 * 
 * Created on 11 giugno 2016, 15.53
 */

#include "Disc.h"


Disc::Disc(){
    this->character='0';
}

Disc::Disc(char c) {
    this->character=c;
}
 
 Disc::Disc(const Disc& orig){
    this->character=orig.getChar();

}

char Disc::getChar()const{ return character;}



std::ostream& operator<<(std::ostream& out,const Disc &disc ) {
    out<<disc.character;
    return out;
  }

bool Disc::operator ==(const char& c) {
    if(this->character==c) return true;
    return false;
}
bool Disc::operator !=(const char& c) {
    if(this->character != c) return true;
     return false;
}






