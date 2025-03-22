#ifndef Bureau_HPP
#define Bureau_HPP
/**
*file Decharge.hpp
* \ *author
*/
//#ifndef Bulletin_HPP
//#define Bulletin_HPP
#include <iostream>
#include <string>
#include<vector>
#include<queue>


namespace elections{

class Bulletin{ 


    
public:
Bulletin(int id,int nombre);//constructeur
int getid();
int getnombre();



private:
int id;
int nombre;


};

}
#endif

