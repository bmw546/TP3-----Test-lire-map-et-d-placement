/*****************************************************************************
File  : robot.hpp
Author: Anthony Cote & Marc-Etienne Pepin
Date  : 2017/11/01
Goal  : L�objet robot offre les m�canismes suivants�:
s�initialiser, s�afficher, avancer ds le labyrinthe en empilant les
d�placements, changer de direction. Initialiser le robot consiste �
empiler la position de d�part. La pile sera une pile de d�placement.
******************************************************************************/

#pragma once
///////////////////
#include <assert.h>
#include <iostream>
///////////////////
using namespace std;


class entity {
private:
	int _x;                     // position x du robot
	int _y;                     // position y du robot
	char _direction;            // direction dans laquel le robot regarde
public:
	entity(unsigned int x, unsigned int y, char direction);  // constructeur param
	entity(const entity & d);     // copieur
	void move();                // le robot avance de 1 dans la direction
	void turnLeft();            // change la direction anticlockwise
	void turnRight();           // change la direction clockwise
	void setDirection(char direction);                  // choisi la direction
	void setPosition(unsigned int x, unsigned int y);   // change la position
	char getDirection()const;   // retourne la direction du robot
	int getX()const;            // Retourne la position X
	int getY()const;            // Retourne la position Y
};
