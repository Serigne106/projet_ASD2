// ctrl à gauche + 6 pour dimunier la taille de vs code
/**
 * \file main.cpp
 * \author Laurent Granvilliers
 */

#include <cstdlib>
#include <ctime>
#include <set>
#include <chrono>
#include <thread>
#include <iostream>
#include <vector>
#include "Personne.hpp" 
#include "Election.hpp" 
#include "Candidat.hpp"
#include "Decharge.hpp"
#include "Bureau.hpp"

using namespace std;
using namespace elections;

int main(void)
{
   // initialisation du générateur de nombres aléatoires
   std::srand(std::time(nullptr));

   // création des personnes
   std::vector<Personne*> vp = {
      new Personne("A", "bic", 7),
      new Personne("B", "gad", 9),
      new Personne("C", "ann", 2),
      new Personne("D", "pol", 5),
      new Personne("E", "lam", 1),
      new Personne("F", "bul", 10), 
      new Personne("G", "yap", 3),
      new Personne("X", "nel", 5),
      new Personne("Y", "rik", 2),
      new Personne("Z", "pat", 8)
   };




  int t_max ; 
  int td;
  cout<<"donner le temps max"<<endl;
  cin>>t_max;
  //cout<<"donner le temps bureau"<<endl;
  //cin>> tb;
  cout<<"donner le temps decharge"<<endl;
  cin>> td;
  //cout<<"donner le temps de l'isoloir"<<endl;
  //cin>> ti;


   // creation des candidats de l'election
   Candidat c1(0,"X", "nel", 5);
   Candidat c2(1,"Y", "rik", 2);
   Candidat c3(2,"Z", "pat", 8);
   //Candidat c4(3,"T", "lam", 1);

    Election euro2024("Euro 2024");
    
    // ajout des candidat dans la liste des candidats
    euro2024.ajouterCandidat(c1);
    euro2024.ajouterCandidat(c2);
    euro2024.ajouterCandidat(c3);
    //euro2024.ajouterCandidat(c4);
    euro2024.afficherCandidat(); 


      Personne p1("A", "bic", 7);
      Personne p2("B", "gad", 9);
      Personne p3("C", "ann", 2);
      Personne p4("D", "pol", 5);
      Personne p5("E", "lam", 1);
      Personne p6("F", "bul", 10); 
      Personne p7("G", "yap", 3);
      //Personne p8("A", "bic", 7);
      //new Personne("X", "nel", 5),



  Bureau bureau(td,"238", 2);
  cout << "\n" << endl ;
  cout << "BUREAU n°" << bureau.Nom()<<endl;
  std::cout<< "LISTE ELECTORALE"<< std::endl;
  bureau.ajouterPersonne(p1);
  bureau.ajouterPersonne(p2);
  bureau.ajouterPersonne(p3);
  bureau.ajouterPersonne(p4);  
  bureau.ajouterPersonne(p5);
  bureau.ajouterPersonne(p6);
  bureau.ajouterPersonne(p7);
 // bureau.ajouterPersonne(p8);
      cout << "\n" << endl ;
  bureau.file();

  Decharge d(td);


  int i=0;
  while(i<t_max){ // || !bureau.Liste().empty()){
    
    cout<<"T = "<<i<<endl; 
  
    i=i+1;
   // bureau.file();
   bureau.Entrer();
   //d.Affichage();
   d.file(bureau.Entrer());
   d.Entrer();
   td--;
   if(td==0){
   d.Sortir();
   td=3;
   this_thread::sleep_for(chrono::milliseconds(1000));
  }
  // std::this_thread::sleep_for(std::chrono::seconds(3));
    //bureau.simulation();
  }




/*
bureau.file();
// bureau.affichage();
 bureau.Entrer();
  
    for (int i = 1; i <= max; i++) {
     cout << "T=" << i << endl;
     // Entrée dans le bureau tous les 2 tours
    if (te == 0 && !bureau.estvide()) {
       bureau.Entrer();
       te = 2; // Réinitialiser te après qu'une personne soit entrée
     }
     // Entrée dans la décharge tous les 2 tours
     if (td == 0) {
       d.Entrer();
       td = 2; // Réinitialiser
     }

     if (tb == 0) {
    // d.choisir(d.getbulletin());
     d.Sortir();
        tb=3;
      }

     te--; // Décrémenter te à chaque tour
     td--; // Décrémenter td à chaque tour
     tb--;
   }*/





   // TODO
   // Code de simulation dans lequel on manipulera les personnes
   // via des pointeurs sur les éléments du vecteur vp.

   // destruction des personnes
   for (Personne* psn : vp)
   {
      delete psn;
   }

   return 0;
}





/*
using namespace std;
using namespace elections;

int main(void) {
  // initialisation du générateur de nombres aléatoires
  std::srand(std::time(nullptr));

  // création des personnes
  std::vector<Personne *> vp = {
      new Personne("A", "bic", 7), new Personne("B", "gad", 9),
      new Personne("C", "ann", 2), new Personne("D", "pol", 5),
      new Personne("E", "lam", 1), new Personne("F", "bul", 10),
      new Personne("G", "yap", 3), new Personne("X", "nel", 5),
      new Personne("Y", "rik", 2), new Personne("Z", "pat", 8)};
  int te = 1;
  int td = 2;
  int tb = 3;
  int max, dv;
  cout << "donner le tmax" << endl;
  cin >> max;
  cout << "donner le temps de decharge " << endl;
  cin >> dv;
  Bureau bureau(max, "238", dv);
  cout << "Bureau :" << bureau.Nom() << endl;
  Personne p1("A", "bic", 7);
  Personne p2("B", "gad", 9);
  Personne p3("C", "ann", 2);
  Personne p4("E", "lam", 1);

   bureau.ajouter(p1);
   bureau.ajouter(p2);
   bureau.ajouter(p3) ;
   bureau.ajouter(p4) ;
   bureau.affichage() ;

 


  
  // creation des candidats de l'election
   Candidat c1(0,"X", "nel", 9);
   Candidat c2(1,"Y", "rik", 2);
   Candidat c3(2,"Z", "pat", 5);
   //Candidat c4(3,"T", "lam", 1);

    Election E("Euro 2024");

    // ajout des candidat dans la liste des candidats
    E.ajouterCandidat(c1);
    E.ajouterCandidat(c2);
    E.ajouterCandidat(c3);
    //euro2024.ajouterCandidat(c4);
    E.afficherCandidat(); 


cout<<"********************************"<<endl;
cout<<"********************************"<<endl;
cout<<"********************************"<<endl;

 
  bureau.file();
  bureau.affichage();

  cout<<"********************************"<<endl;
  cout<<"********************************"<<endl;
  cout<<"********************************"<<endl;
  cout<<"********************************"<<endl;

  for (int i = 1; i <= max; i++) {
    cout << "T=" << i << endl;
    // Entrée dans le bureau tous les 2 tours
   if (te == 0 && !bureau.estvide()) {
      bureau.Entrer();
      te = 2; // Réinitialiser te après qu'une personne soit entrée
    }
    // Entrée dans la décharge tous les 2 tours
    if (td == 0) {
      bureau.entrerDecharge();
      td = 2; // Réinitialiser
    }
     
    if (tb == 0) {
    //bureau.choixde(E.getlist_cand());
    bureau.SortirDecharge();
       tb=3;
     }

    te--; // Décrémenter te à chaque tour
    td--; // Décrémenter td à chaque tour
    tb--;
  }
  cout << "///////////////////////////////" << endl;

  // TODO
  // Code de simulation dans lequel on manipulera les personnes
  // via des pointeurs sur les éléments du vecteur vp.

  // destruction des personnes
    for (Personne *psn : vp) {
    delete psn;
  }


  //return 0;
}
*/



int nb_vote(std::vector<int> liste){
    

   for(int i=0; i<= liste.size(); i++){
     int nb = liste.size() - liste;
   }
   return nb ;
}
