
#include "Election.hpp"


namespace elections{


Election::Election(const std::string nom) : nom_(nom)      
{}

//getter qui affiche le nom de l'election
std::string Election::getnom() const
{
    return nom_;
} 
 
//getter qui retourne la liste des candidats
std::vector<Candidat> Election::getlist_cand()
{
  return list_cand_;
}

/*
int Candidat::getNum() const 
{
    return num_ ;
}
*/

// methode pour ajouter un candidat dans la liste des candidats
void Election::ajouterCandidat(Candidat& c)
{
    list_cand_.push_back(c) ;
}

// methode pour afficher les candidats de l'election
void Election::afficherCandidat()
{  
    std::cout<< "ELECTION" << " " << nom_ << ":" << std::endl ;

    for(auto it : list_cand_){

      std::cout << "     " << "candidat n° " <<  it.getNum() << " : " << it.nom() << "  " << it.prenom() << "  " << it.spol() << std::endl ;

    }
}

} //namespace
