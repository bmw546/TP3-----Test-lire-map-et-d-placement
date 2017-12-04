/*************************************************************************************
*	Auteur:		Micael Gaumond-Roy
*	Date:		02/12/2017
*	Fichier:	movement.cpp
*	But:		@@- A changer -@@
************************************************************************************/

//#include "movement.h"
//movement::movement()
//{
//}
//
//movement::movement(float x, float y, int dir)
//{
//}
//
//movement::~movement()
//{
//}
//
//float movement::getX() const
//{
//	return _x;
//}
//
//float movement::getY() const
//{
//	return _y;
//}
//
//int movement::getDir() const
//{
//	return _dir;
//}
//
////void movement::setX(float x)
////{
////	_x = x;
////}
////
////void movement::setY(float y)
////{
////	_y = y;
////}
//
//void movement::setDir(int dir)
//{
//	_dir = dir;
//}
//
//void movement::setPos(float x, float y, sf::Sprite entity)
//{
//	entity.setPosition(x, y);
//}

//void movement::moveFoward(gen::map<float>& m, entity& who) {
//
//	char direction = who.getDirection();
//
//	if (canAdvance(m, who.getY(), who.getX(), direction, floor)) {
//		m[who.getX()][who.getY()] = floor;
//		who.move();
//		m[who.getX()][who.getY()] = object;
//		/// mettre le son de mouvement
//	}
//	else if (canAdvance(m, who.getY(), who.getX(), direction, zombie)) {
//		/// si who = player then die else do nothing
//		/// z = zombie
//		/// avec son de mort + lose ?
//	}
//	else if (canAdvance(m, who.getY(), who.getX(), direction, player)) {
//		/// p = porte ou truc a acheter
//		/// afficher le prix du truc ? 
//	}
//	else {
//		/// bruit collision, do nothing
//	}
//}

//bool movement::canAdvance(gen::map<float>& m, const float& y, const float& x, const int& direction, int cas) {
//
//	if (y > 0)
//		if (direction == north)
//			if ((m[x][y - 1] == cas))
//				return true;
//
//	if (x < m.nbLine())
//		if (direction == east)
//			if ((m[x + 1][y] == cas))
//				return true;
//
//	if (y < m.nbCol())
//		if (direction == south)
//			if ((m[x][y + 1] == cas))
//				return true;
//
//	if (x > 0)
//		if (direction == west)
//			if ((m[x - 1][y] == cas))
//				return true;
//
//	return false;
//}