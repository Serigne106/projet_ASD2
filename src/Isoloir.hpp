#include "Personne.hpp"
#include "Bureau.hpp"
#include "Bulletin.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>


namespace elections{

class Isoloir
{
private:
  int Di_ ; // duree que passe l'electecteur dans l'isoloir
  bool estPresent_ ; // oui ou non on peut add quelqu'un?
  Personne p_;
  std::queue<Personne> fdch;



public:
    Isoloir(int d);
   // ~Isoloir();
    Bulletin choisir(std::vector<Bulletin> b);
    void Entrer() ;
    void Sortir();
    void file(Personne p); 
    int getDuree() ;
   
};


}