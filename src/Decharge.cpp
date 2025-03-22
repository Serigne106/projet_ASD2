#include "Decharge.hpp"
#include "Personne.hpp"
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;
namespace elections {

Decharge::Decharge(int time) : estlibre(true), time(time), who("a", "b", 14) {}

int Decharge::gettime() { return time; }
void Decharge::settime(int time) { this->time = time; }
void Decharge::file(Personne x) { fdch.push_back(x); }

Personne Decharge::sommetfile2() {
  if (!fdch.empty()) {
    return fdch.front();
  } else {
    cout << "La file est vide" << std::endl;
    return Personne("", "", -1);  //Retourne une Personne  invalide
  }
}

void Decharge::supp() { fdch.pop_back(); }


void Decharge::Affichage() {
  if (!fdch.empty()) {
    cout << "Sommet de la Decharge : " << fdch.front() << endl; 
  } else {
    cout << "La Decharge est vide." << endl;
  }
}

  void Decharge::Entrer() {
    if (estlibre && !fdch.empty()) {
      cout << "DECHARGE" << endl;
      who = fdch.front();
      fdch.pop_back(); 
      cout<< "    "  << who.id() << " entre" << endl; 
      estlibre = false;
    }
  }


  void Decharge::Sortir() {
    if (!estlibre) {
      estlibre = true;
      cout << "DECHARGE" << endl;
      cout << "    "  << who.id() << " sort" << endl;
      // Réinitialiser 'who' pour indiquer que la table est libre
      who = Personne("", "", -1);
    }
  }
void Decharge::choisir(const std::vector<Personne>& candidats) {
      int nbBulletins = random();  // Nombre aléatoire de bulletins à choisir
 

          std::set<int> indicesChoisis;  // Pour  que les indices choisis sont uniques

          while (indicesChoisis.size() < nbBulletins && indicesChoisis.size() < candidats.size()) {
              int index = randomindice(candidats);  // Choisir un index de candidat aléatoirement
              if (indicesChoisis.find(index) == indicesChoisis.end()) {
                  indicesChoisis.insert(index);
                 std::cout << who.id() << " prend " << candidats[index]  << std::endl;
              }
          }

          std::cout << std::endl;
      }


  int Decharge::randomindice(const std::vector<Personne>& liste) {
      if (liste.empty()) {
          return -1;  // Retourner une valeur indicative d'erreur ou gérer autrement
      }
      int random = std::rand() % liste.size();
      return random;
  }


int Decharge::random() {
  // Génère un nombre aléatoire entre  2 et 4
  int random = std::rand() % 3+ 2;
  return random;
}
};
// namespace elections
