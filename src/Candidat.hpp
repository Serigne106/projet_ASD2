#ifndef CANDIDAT_HPP
#define CANDIDAT_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Personne.hpp"
#include "Candidat.hpp"


//using namespace std ;
namespace elections {

class Candidat : public Personne {

private:
    int num_ ; //  numéro du candidat sur la liste 
    

public:

  Candidat(int nu,const std::string& prenom, const std::string& nom, int spol) ;

  int getNum() const ;


};

}//elections

#endif