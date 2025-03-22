/**
 * \file Bulletin.CPP
 * \author*/
#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include<vector>
#include<queue>
#include "Bulletin.hpp"

using namespace std;

Bulletin::Bulletin(int id,int nombre)
      : id(id), nombre(nombre)
{}
int Bulletin::getid(){
  return id;
}
int Bulletin::getnombre(){
  return nombre;
}
