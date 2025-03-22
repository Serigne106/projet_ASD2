#ifndef ELECTEUR_HPP
#define ELECTEUR_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>     
#include "Personne.hpp"  
#include "Bulletin.hpp"


//using namespace std ;
namespace elections{

class Electeur : public Personne {

private:
    /* 
    *la duree ici est le cumule de Dd + Di + Dv : les 3 tmps passes dans le bureau
    */
    int duree_ ; // temps que doit mettre l'electeur dans le bureau pour voter
    std::vector<Bulletin> l_bul ; // liste de bulletins 


public:
    //constructeur
    Electeur(const std::string& nom, const std::string& prenom, int spol, int duree,std::vector<int> indBul) ;


    
   /**
    * Accesseur.
    * \return la durée 
    */
   int getduree() const ;

    /**
     * methode pour choisir un bulletin de vote
    */
   void choisirBulletin(int ind_Bulletin);

    /**
     * accessseur pour les bulletins choisit
    */

    std::vector<Bulletin>& getL_bul() const ; 

    //sortir 

};

}
#endif  