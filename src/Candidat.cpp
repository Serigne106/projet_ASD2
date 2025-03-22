
#include "Candidat.hpp"



namespace elections{




    Candidat::Candidat(int nu, const std::string& p, const std::string& n,int sp) : Personne(p , n , sp), num_(nu)
    {
        //
    }

 


int Candidat::getNum() const 
{
    return num_ ;
}



}

