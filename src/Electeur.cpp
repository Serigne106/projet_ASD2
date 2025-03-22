
#include "Electeur.hpp"

namespace elections{


Electeur::Electeur(const std::string& nom, const std::string&
 prenom, int spol, int duree, std::vector<int> indBul) 
       : Personne(nom, prenom, spol), duree_(duree), indBul_(indBul) 
{}


int Electeur::getduree() const
{
return duree_ ;
}

 void Electeur::choisirBulletin(int ind_bulletin)
 {
   indBul_.push_back(ind_bulletin) ;
 }


std::vector<Bulletin>&  Electeur::getBulletinChoisit() const
{
     return indBul_ ;
}


}
