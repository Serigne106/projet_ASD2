#include "Isoloir.hpp"
#include <iostream>
#include <string>
#include <list>



namespace elections{

class EspaceIso
{
private:
    /* data */
   std::list<Isoloir> lis_iso ;
   int nbIso ; //nombre d'isoloir  max autorisé




public:
    EspaceIso(int nb);
   // ~EspaceIso();
   
int getNbIso() ;
std::list<Isoloir> getLis_iso() ;




};

 





}