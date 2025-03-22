#ifndef ELECTION_HPP
#define ELECTION_HPP

#include <iostream>
#include <string> 
#include <vector>
#include <iterator>
#include "Personne.hpp"
#include "Candidat.hpp"



//using namespace std ;
//using namespace elections ;

namespace elections {

class Election  {

private:
   std::string nom_ ;
   std::vector<Candidat> list_cand_ ;
   
public:
    // constructeur
    Election(const std::string nom) ;
    
    // getter
    /**
     * \return le nom de l'élection
    */
   std::string getnom() const ; 
  

   //int getNum() const ;

   /**
    * \return  la liste des candidats
   */
   std::vector<Candidat> getlist_cand() ;


    // ajouter Candidat
    /**
     * \ajoute un candidat dans la liste des candidats
    */
    void ajouterCandidat(Candidat& c) ;

    /**
     * affichage des candidats 
   */
    void afficherCandidat() ; 
   


};


} // namespace elections

#endif