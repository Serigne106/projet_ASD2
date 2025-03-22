/**
 * \file Bureau.CPP
 * \author*/

#include "Personne.hpp"
#include "Decharge.hpp"
#include "Bureau.hpp"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <thread>
#include <vector>

 
//namespace std;
namespace elections {

Bureau::Bureau(int tmax, const std::string& nom, int tempsDecharge)
    :decharge(new Decharge(tempsDecharge)), nom(nom), tmax(tmax)
{}

std::string Bureau::Nom() { // accesseurs
  return nom;
}

int Bureau::Tmax() { // accesseurs
  return tmax;
}
std::set<Personne*, Personne::CompAlpha> Bureau::get_lis_elc(){
  return lis_elc ;
}

/*
void Bureau::ajouter(Personne pers) { // la liste d'electeurs
   // liste.push_back(pers);
}*/


//////////////////////////////////////////////////////////////////////////////
void Bureau::ajouterPersonne(Personne p){         ////////////////////////
   lis_elc.insert(&p) ; 
   afficher();
}


void Bureau::afficher(){
 // std::cout<< "LISTE ELECTORALE"<< std::endl;
    for (Personne* p : lis_elc) {
        std::cout << "      " << p->nom() << "  " << p->prenom() << "  (" << p->id() << ")"<< std::endl;
    }

}
//////////////////////////////////////////////////////////////////////////////


bool Bureau::estvide() { return electeurs.empty(); }

/*
void Bureau::affichage() {
  //std::cout << "sommet de file : " << electeurs.front() << std::endl;
  // electeurs.pop();
  for (Personne const &p : liste) {
  std::cout << "      " << p.nom() << "  " << p.prenom() << "  " << p.spol() << std::endl ;
  }
}*/

 Personne Bureau::sommetDecharge() {
      return decharge->sommetfile2();
  }


Personne Bureau::sommetfile() { // le sommet de la file d'entée.
  return electeurs.front();
}
int Bureau::taille() { return electeurs.size(); }
///////////////////////////////////
std::vector<Personne> Bureau::Liste() { return interieur; }

/////////////////////////////////////

int Bureau::Random() {
  int random = std::rand() % lis_elc.size();
  return random;
}
/////////////////////////////////////

/*
ici on teste si la personne est sur la liste electorale
*/

  bool Bureau::test_lis_elec(Personne* p){

    return lis_elc.find(p) != lis_elc.end() ;

  }



void Bureau::file() { // Remplir la file devient remplir laliste

  //std::set<Personne*, Personne::CompAlpha>::iterator it = lis_elc.begin();
 // Personne* p=nullptr;
  //for(auto it : lis_elc){ //(int i = 0; i < tmax; ++i) {
  for (auto it = lis_elc.begin(); it != lis_elc.end(); ++it){
  //if (test_lis_elec(*it)) { //it != lis_elc.end()
      ///std::cout<< "la personne est inscrit , on le met sur la file d'attente"<< std::endl;
      electeurs.push(*(*it));
     // std::cout << *(*it) << " entre" << std::endl;
     // ++it;
  //}
   //std::cout<< "Elle n'est pas inscrit , elle ne peut pas voter" << std::endl;
  }
}
/*
   std::set<int> used; // Ensemble pour suivre les indices utilisés
  for (int i = 0; i < tmax; i++) {
    int index = Random();
    if (used.find(index) == used.end()) {
      electeurs.push(lis_elc(index));
      std::cout<<lis_elc(index) << " entre" << std::endl;
      used.insert(index); //
    }
   //std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
}*/ 
////////////////////////////////////////

Personne Bureau::Entrer() {
  if (!electeurs.empty()) {
    Personne x =electeurs.front();
    interieur.push_back(x);
    std::cout << "   ENTREE" << std::endl;
    std::cout << "    " << x.id() << "   entre" << std::endl;
    decharge->file(x); // Utilisation de l'instance membre decharge
    electeurs.pop();
    return x;
  } else {       
    // Gérer le cas où la file est vide 
   // x=Personne("","",0) ;
   // std::cout << "Aucun électeur à entrer." << std::endl;
    return Personne("", "", -1); // Retourne une personne "vide" ou invalide
  }
}

void Bureau:: entrerDecharge() {
    if (decharge) {
      decharge->Entrer();
    }
}

void Bureau::choixde(std::vector<Personne> candidats){
  decharge->choisir(candidats);
}  

void elections::Bureau::Sortir(){ 
  // on recupere l'identifianr de celui qui vient juste de sortir de la table de
  // vote et on l'enleve de la liste des personnes à l'interieur du bureau.
}

  void Bureau:: SortirDecharge() {
    if (decharge) {
      decharge->Sortir();
          }
      }


  
void Bureau::simulation() {
  for (int i = 0; i < tmax; ++i) {
    std::cout << "T = : " << i + 1 << std::endl;
    // file vide ou pas.
    if (!estvide()) {
      // On appelle  entrer
     //Entrer();
      Personne entrant = Entrer();
      decharge->file(entrant); // Ajouter la personne à la décharge
    }

     // Sortie des électeurs de la décharge
    decharge->Sortir();
   //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    // Attendre une seconde avant la prochaine itération
    std::this_thread::sleep_for(std::chrono::seconds(3));
  }

  std::cout << "Simulation terminée." << std::endl;
}
} // namespace elections
  // void getel();



