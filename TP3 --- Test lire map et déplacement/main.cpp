/*****************************************************************************
File  : main.cpp
Author: Marc-Etienne Pepin 
Date  : 2017/11/01
Goal  : Extrait des labyrinthes a partir de fichier texte
Resout des labyrinthes a l'aide de :
Robot qui se promene dans le labyrinthe
Pile de deplacement qui contient le chemin du robot
Affiche le labyrinthe dans la console
******************************************************************************/

#pragma once
////////////////////
using namespace std;
////////////////////
#include <chrono>
#include <thread>
#include <iostream>
#include <string>

#include "entity.h"
#include "labyrinthe.h"
#include "deplacement.h"
#include "map.hpp"

void jeux();

void main()
{
	// ================ initialisation dah ==================
	string nomDeLaMap = "labyrinthe1.txt";
	cout << "bienvenue dans le test dah" << endl;
	map<char> carte("placeholder", 1, 1);
	lab laby;
	const char* nomFichier = nomDeLaMap.c_str();
	laby.readFile(carte, nomFichier);
	// ================ fin initialisation ==================
	laby.print(cout, carte);
	char input = 'f';
	entity player(laby.posiDX(), laby.posiDY(), 'N');
	carte[player.getX()][player.getY()] = 'V';
	deplacement mouvement;
	while (input != 'n') {

		if (GetAsyncKeyState(VK_LEFT)) {
			if (player.getDirection() == 'N')
				mouvement.avance(carte, player);
			else
				player.setDirection('N');
		}
		else if (GetAsyncKeyState(VK_RIGHT)) {
			if (player.getDirection() == 'S')
				mouvement.avance(carte, player);
			else
				player.setDirection('S');
		}
		else if (GetAsyncKeyState(VK_DOWN)) {
			if (player.getDirection() == 'E')
				mouvement.avance(carte, player);
			else
				player.setDirection('E');
		}
		else if (GetAsyncKeyState(VK_UP)) {
			if (player.getDirection() == 'O')
				mouvement.avance(carte, player);
			else
				player.setDirection('O');
		}

		//this_thread::sleep_for(std::chrono::milliseconds(10));
		system("cls");
		laby.print(cout, carte);
	}
	system("pause");
}
void jeux()
{
	char input = 'f';
	//entity player = player(2, 4, 'N');
	while (input = 'n') {
	}
}