/**
*file Decharge.hpp
* \ *author
*/
#ifndef Decharge_HPP
#define Decharge_HPP
#include "Bulletin.hpp"
#include "Personne.hpp"
#include <iostream>
#include <string>
#include<vector>
#include<queue>
#include <stack>

namespace elections {

class Decharge{

public:
Decharge(int time);//constructeur 
//Decharge ();//constructeur par défaut 
int gettime();
void settime(int time);
void file(Personne x);
void supp();
void Entrer();
void Affichage();
Personne sommetfile2();
void choisir(const std::vector<Personne>& candidats); // il choisit les bulletins.
bool estvide();
void Sortir();
int random();
int randomindice(const std::vector<Personne>& liste);

private:
std::vector<Personne> fdch ;
  bool estlibre ; // oui ou non on peut add quelqu'un?
  int time;
  Personne who;// personne normalement.
 };
}
#endif

