/**
 * \file Personne.cpp
 * \author Laurent Granvilliers
 */

#include "Personne.hpp"
#include <random>

namespace elections {

int Personne::sid_ = -13;

Personne::Personne(const std::string& nom, const std::string& prenom,
                   int spol)
      : nom_(nom), prenom_(prenom), id_(sid_++), spol_(spol)
{

 //id_ = std::rand()%25 ;

}

Personne::Personne(){}

std::string Personne::nom() const
{
   return nom_;
} 

std::string Personne::prenom() const
{
   return prenom_;
}

int Personne::id() const
{
   return id_;
}

int Personne::spol() const
{
   return spol_;
}

std::ostream& operator<<(std::ostream& os, const Personne& psn)
{
   os << psn.nom() << " " << psn.prenom() << " " << psn.spol();
   return os;
}

} // namespace
