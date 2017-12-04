/***********************************************************************
File  : map.hpp
Author: Marc-Étienne Pépin & Anthony Cote
Date  : 12 octobre 2017
Goal  : Sert a initialiser un objet map dynamique,
on peut modifer son nom , sa taille ,certain élément ,l'imprimmer,
lire un fichier pour créer une carte rapidemment, etc ...
***********************************************************************/

#pragma once
#include <iostream>
#include <assert.h>
///////////////////
using namespace std;


template <class TYPE>
class map
{
private:
	char *_name;												//pointeur sur le nom de la map
	int   _nbLine; 												//nombre de ligne pour la matrice
	int	  _nbCol;												//nombre de colonne pour la matrice

public:
	TYPE  **_map;												//La map dynamique en ligne et colonne

	map();														// constructeur sans valeur
	map(const char* name, unsigned int line, unsigned int col);	// constructeur avec valeur
	map(const map<TYPE> &m);									// constructeur copieur
	~map();														// destructeur
	void clear();												// objet clear (destructeur)S

																//getteurs
	int& nbLine(); 											    //retourne le nb de ligne
	int& nbCol(); 											    //retourne le nb de colonne
	void resize(int nbLine, int nbCol);							//resize la matrice avec nouv dims

	TYPE& at(int posI, int posJ)const;							//retourne une référence à l’élément 
																//à la position i,j pour accéder ou modifier
	TYPE* operator[](int line);									// fait la même affaire que at

	const char* getName()const; 	  							//retourne le nom de la map
	void setName(const char* name);  							//modifie le nom de la map
	const map<TYPE>& operator=(const map<TYPE> & m);			// copie une map sur une autre

	void print(ostream& sortie)const;  							//print la matrice (sans le nom)
	void read(istream& entree);									//lit la matrice de la map ds le flux

};
template <class TYPE>
ostream& operator<<(ostream& sortie, const map<TYPE>& x);		// racourci de print (sert a print la matrice)

template <class TYPE>
istream& operator >> (istream& entree, map<TYPE>& x);			// racourci de read (lis la matrice et l'affecte)




																// constructeur sans paramètre
template <class TYPE>
map<TYPE>::map() {
	// mise a zéro pour tous
	_nom = nullptr;
	_map = nullptr;
	_nbLine = 0;
	_nbCol = 0;
}

// constructeur avec paramètre
template <class TYPE>
map<TYPE>::map(const char* name, unsigned int line, unsigned int col)
{
	// initialisation des variable
	int charlong = (strlen(name));
	_name = nullptr;
	_map = nullptr;
	_nbLine = line;
	_nbCol = col;
	// initialisation du tableau
	// des ligne
	if (line > 0 && col > 0) {
		_map = new TYPE*[_nbLine];
		// les colonne
		for (int i = 0; i < line; i++)
		{
			*(_map + i) = new TYPE[col];
		}
	}


	if (charlong > 0)
	{
		_name = new char[charlong + 1];
		strcpy_s(_name, charlong + 1, name);
	}
}

// Constructeur de copieur
template <class TYPE>
map<TYPE>::map(const map<TYPE> &m) {

	_nbLine = m._nbLine;
	_nbCol = m._nbCol;
	_map = nullptr;
	_name = nullptr;
	if (_nbLine > 0 && _nbCol > 0) { // s'assure que la map et pas vide
		_map = new TYPE*[_nbLine];
		for (int i = 0; i < _nbLine && i < _nbLine; i++)
			*(_map + i) = new TYPE[_nbCol];				// créer les colone

		for (int i = 0; i < _nbLine && i < _nbLine; i++) {
			for (int j = 0; j < _nbCol && j < _nbCol; j++) {
				*(*(_map + i) + j) = *(*(m._map + i) + j); // remplit la matrice  avec
														   // les chiffre de l'original tout en 
			}
		}
	}
	// section pour le nom
	int charlong = (strlen(m._name));
	if (charlong > 0)			// pour s'assurer que il y a un nom.
	{
		_name = new char[charlong + 1];
		strcpy_s(_name, charlong + 1, m._name); // copie le nom de m sur this
	}
}

// DESTRUCTEUR 
template <class TYPE>
map<TYPE>::~map()
{
	clear();
}

//Méthode Clear
template <class TYPE>
void map<TYPE>::clear() {
	delete[]_name;
	_name = NULL;
	for (int i = 0; i < _nbLine; i++) {
		delete[] * (_map + i);	// Suprime chaque colone
	}
	delete[]_map;				// Suprime chaque lignes
	_map = NULL;
	_nbLine = _nbCol = 0;
}

// retourne le nb de ligne
template <class TYPE>
int& map<TYPE>::nbLine() {
	return _nbLine;
}

// retourne le nb de colonne
template <class TYPE>
int& map<TYPE>::nbCol() {
	return _nbCol;
}

// retourne le nom de la map
template <class TYPE>
const char* map<TYPE>::getName() const {
	if (_name == nullptr) // si nom null retourne rien
		return "\0";
	return _name; // sinon retourne le nom
}

// modifie le nom de la map
template <class TYPE>
void map<TYPE>::setName(const char* name) {
	delete[]_name;
	_name = nullptr; // suprime le vecteur nom
	int charlong = (strlen(name));
	if (charlong > 0) { // l'initialise avec le nouveaux nom
		_name = new char[charlong + 1];
		strcpy_s(_name, charlong + 1, name);
	}
}

// modifie le nom de la map
template <class TYPE>
void map<TYPE>::resize(int nbLine, int nbCol) {
	assert(nbLine >= 0 && nbCol >= 0); // pour évite des chiffre négatif
	if (nbLine == 0 && nbCol == 0) { // si le tableau se fait vider
		for (int i = 0; i < _nbLine; i++) {
			delete[] * (_map + i);	// Suprime chaque colone
		}
		delete[]_map;				// Suprime chaque lignes
		_map = NULL;
		_nbLine = _nbCol = 0;
		return;
	}
	if (_nbLine == _nbLine && nbCol == _nbCol) // si le tableau reste le même
		return;


	TYPE **_temp = new TYPE*[nbLine]; // nouvelle matric dynamique temporaire

	for (int i = 0; i < nbLine; i++) {
		*(_temp + i) = new TYPE[nbCol]; // crée les colonne
	}

	for (int i = 0; i < nbLine && i < _nbLine; i++) {
		for (int j = 0; j < nbCol && j < _nbCol; j++) {
			*(*(_temp + i) + j) = *(*(_map + i) + j); // remplit la matrice temporaire avec
													  // les chiffre de l'original tout en 
													  // respectant sa taille
		}
	}
	for (int i = 0; i < _nbLine; i++) { // suprime chaque col de la matrice original
		delete[] * (_map + i);
	}
	// suprime l'objet map original et le remplace par _temp
	delete[]_map;
	_map = _temp;
	_nbCol = nbCol;
	_nbLine = nbLine;
	_temp = nullptr;
}

// mutateur / setteur at (permet de modifier, recevoir une position du vecteur)
template <class TYPE>
TYPE& map<TYPE>::at(int posI, int posJ)const {
	// s'assure que la map est valide, que les position sont valide et comprise dans la matrice
	// et ensuite le retourne pour accéder ou modifier.
	assert(_map != nullptr && posI >= 0 && posJ >= 0 && posI < _nbLine && posJ < _nbCol);
	return *(*(_map + posI) + posJ);
}

// muttateur / setteur [] fait la même job que at
template <class TYPE>
TYPE* map<TYPE>::operator[](int line) {
	assert(line >= 0 && line < _nbLine);
	return *(_map + line);
}

// imprimme la map
template <class TYPE>
void map<TYPE>::print(ostream& sortie) const {
	for (int i = 0; i < _nbLine; i++) { // pour chaque ligne
		for (int j = 0; j < _nbCol; j++) { // chaque colone
			cout << *(*(_map + i) + j);  // on imprime le charactère
			sortie << " "; // charatère qui permet d'espacer les charactère de la map
						   // pour éviter toute confusion
		}
		sortie << endl;
	}
}

// raccourci de print
template <class TYPE>
ostream& operator<<(ostream& sortie, const map<TYPE>& x) {
	x.print(sortie);
	return sortie;
}

// raccourci du read
template <class TYPE>
istream& operator >> (istream& entree, map<TYPE>& x) {
	x.read(entree);
	return entree;
}

// sert a lire un fichier de type entree pour créer une map 
template <class TYPE>
void map<TYPE>::read(istream& entree) {
	assert(_map != nullptr && _nbLine > 0 && _nbCol > 0);
	for (int i = 0; i < _nbLine; i++) {     // pour chaque ligne ...
		for (int j = 0; j < _nbCol; j++) {  // et chaque colone ...
			entree >> *(*(_map + i) + j);   // ... on remplace le charactère par celuil
											// de l'entree
		}
	}
}

// copie la map m sur la map this
template <class TYPE>
const map<TYPE>& map<TYPE>::operator=(const map<TYPE> & m) {
	if (&m == this) // vérifie si ce sont pas les même map
		return *this;
	clear();		// efface la map this
	_nbCol = m._nbCol;		// ajuste  ces nouvel valeur a la taille de la map m
	_nbLine = m._nbLine;

	if (_nbLine > 0 && _nbCol > 0) { // si la taille est plus grande que 0
		_map = new TYPE*[_nbLine];

		for (int i = 0; i < _nbLine; i++)
			*(_map + i) = new TYPE[_nbCol]; //créer une ligne

		for (int i = 0; i < _nbLine; i++) {
			for (int j = 0; j < _nbCol; j++) { // et créer les colone ensuite
				*(*(_map + i) + j) = *(*(m._map + i) + j);
			}
		}
	}
	setNom(m._name);
	return *this;
}

