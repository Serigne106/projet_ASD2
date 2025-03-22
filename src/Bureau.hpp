//#ifndef Bureau_HPP
//#define Bureau_HPP
 /**
 * \file Bureau.hpp
 * \author
 */



#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include "Personne.hpp" //alpha 

namespace elections { 

class Bureau{

 private:
   Decharge* decharge; 
   std::string nom;
   int tmax;
   std::set<Personne*, Personne::CompAlpha> lis_elc ;
   std::queue<Personne> electeurs;
   //std::vector<Personne> liste;// liste des electeurs
   std::vector<Personne> interieur; // la liste de personne à l'interieur du bureau
 public:
  Bureau(int tmax, const std::string& nom, int tempsDecharge);
  std::string Nom();
  int Tmax();
  std::set<Personne*, Personne::CompAlpha> get_lis_elc() ;
  void file();
  //void ajouter(Personne pers);
  void ajouterPersonne(Personne p) ;
  void afficher() ;
  //void affichage();
  Personne Entrer();
  int Random();
std::vector<Personne> Liste();
 void simulation(); // un fonction juste pour tester le code en general.( je simule au fur et à mesure)
  void Sortir();
  Personne sommetfile();
  bool test_lis_elec( Personne* p) ;
  int taille();
  bool estvide();
  // Dans pour le sommet de file e decharge d
Personne sommetDecharge();
void entrerDecharge();
void SortirDecharge();
void choixde(std::vector<Personne> candidats);
};

}
//#endif




