/*****************************************************************************
File  : labyrinthe.cpp
Author: Marc-Etienne Pepin & Anthony Cote
Date  : 2017/11/01
Goal  : Contient les dimensions et les fonctions de la classe labyrinthe
******************************************************************************/

#include "labyrinthe.h"

using namespace std;

// Raccourci pour alleger la lecture de la fonction print()
#define setColor SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),

//Constructeur
lab::lab()
{
	posDX = 0;
	posDY = 0;
	posAX = 0;
	posAY = 0;
	nbLine = 0;
	nbCol = 0;
}

// Destructeur
lab::~lab()
{

}

// Affiche la map du labyrinthe
void lab::print(ostream& sortie, map<char> &m) const {

	for (int i = 0; i < m.nbLine(); i++) {    // pour chaque ligne
		for (int j = 0; j < m.nbCol(); j++) { // pour chaque colonne

											  // on imprime le charactère relatif
			if (m[i][j] == '0') {       // Libre
				setColor  FOREGROUND_INTENSITY | FOREGROUND_GREEN);
sortie << '.';
			}
			else if (m[i][j] == '1') {  // Bloque
				setColor  FOREGROUND_INTENSITY | 7); // White = 1 + 2 + 4
				sortie << '#';
			}
			else if (m[i][j] == 'C') {  // Chemin
				setColor  FOREGROUND_INTENSITY | FOREGROUND_BLUE);
				sortie << 'C';
			}
			else if (m[i][j] == 'V') {  // Visite
				setColor  FOREGROUND_INTENSITY | FOREGROUND_RED);
				sortie << 'P';
			}
			sortie << " "; // charatère qui permet d'espacer les charactère de la map
						   // pour éviter toute confusion
		}
		setColor  FOREGROUND_INTENSITY | 3); //Blue+Green = 1 + 2 
		sortie << endl;
	};
}

// Lecture du fichier et extrait la map
bool lab::readFile(map <char> &mapLabyrinthe, const char* nomFichier) {
	ifstream fichier(nomFichier);   // Ouverture du ficher
	int X, Y;                       // Permet de donner la taille du lab
	int dx = 0, dy = 0, ax = 0, ay = 0;
	int total = 0;

	if ((fichier.is_open()) && !(fichier.peek() == std::ifstream::traits_type::eof()))
	{
		mapLabyrinthe.setName(nomFichier);	// va changer le nom
		fichier >> X >> Y;	// prend la taille
		nbLine = (int)X;	// converti la taille en integer pour le resize
		nbCol = (int)Y;

		mapLabyrinthe.resize(nbLine, nbCol);// et resizer la map
		tailleEcran(nbLine + 45, nbCol + 8);// va redimensionner l'écran pour adapter au jeux

		fichier >> mapLabyrinthe;		    //lecture de la matrice

		fichier >> dx >> dy >> ax >> ay;	// lecture de la position de départ et d'arrivée
		posDX = (int)dx, posDY = (int)dy, posAX = (int)ax, posAY = (int)ay;
		fichier.close();
		return true;
	}
	else
		cout << "Fichier : " << nomFichier << " innexistant"; // si map non trouvé
	return false;
}

// Redimentionne la taille de la console
void lab::tailleEcran(int x, int y)
{
	HANDLE MaConsoleEcran = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD MaTailleEcran = { x + 5,y + 5 };
	SMALL_RECT MonRectangle = { 0,0,x - 1,y - 1 };

	SetConsoleScreenBufferSize(MaConsoleEcran, MaTailleEcran);
	SetConsoleWindowInfo(MaConsoleEcran, TRUE, &MonRectangle);
}

// Retourne les positions de depart et d'arrivee
int& lab::posiDX() { return posDX; }
int& lab::posiDY() { return posDY; }
int& lab::posiAX() { return posAX; }
int& lab::posiAY() { return posAY; }
