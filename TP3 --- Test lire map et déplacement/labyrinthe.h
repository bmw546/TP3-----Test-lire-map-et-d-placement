/*****************************************************************************
File  : labyrinthe.h
Author: Marc-Etienne Pepin & Anthony Cote
Date  : 2017/11/01
Goal  : Classe qui contient les dimensions du labyrinthe
******************************************************************************/
#pragma once

#include <istream>
#include <fstream>
#include <string>
#include <Windows.h>
//////////////////
#include "map.HPP"
using namespace std;


class lab {
private:
	int posDX; // Position X de depart
	int posDY; // Position Y de depart
	int posAX; // Position X d'arrivee
	int posAY; // Position Y d'arrivee
	int nbCol; // Taille X
	int nbLine;// Taille Y



public:
	lab();          // Constructeur
	~lab();         // Destructeur
	int& posiDX();  // Retourne la valeur X de depart
	int& posiDY();  // Retourne la valeur Y de depart
	int& posiAX();  // Retourne la valeur X d'arrivee
	int& posiAY();  // Retourne la valeur Y d'arrivee
	void print(ostream& sortie, map<char> &m) const; // Print map in the ostream
	bool readFile(map <char> &mapLabyrinthe, const char* nomFichier); // Lit la map
	void tailleEcran(int x, int y); // Change la taille de l'ecran

};
ostream& operator<< (ostream &sortie, map<char> element); // raccourci de print