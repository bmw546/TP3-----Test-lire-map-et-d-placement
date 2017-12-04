/*************************************************************************************
*	Auteur:		Micael Gaumond-Roy
*	Date:		02/12/2017
*	Fichier:	movement.h
*	But:		@@- A changer -@@
************************************************************************************/
//#pragma once
//
//#include <SFML\Graphics.hpp>
//#include "map.hpp"
//#include "entity.h"
//
//enum int_dir
//{
//	north,
//	east,
//	south,
//	west
//};
//
//enum cas
//{
//	floor,
//	object,
//	zombie,
//	player
//};
//
//class movement
//{
//private:
//	float _x;		//position x
//	float _y;		//position y
//	int _dir;		//direction du deplacement
//	///ou char a voir se qui va le mieu avec SFML
//public:
//	movement();
//	movement(float x, float y, int dir);
//	~movement();
//
//	float getX()const;
//	float getY()const;
//	int getDir()const;
//
//	/*void setX(float x);
//	void setY(float y);*/
//	void setDir(int dir);
//	///voir entity e ou entity
//	void setPos(float x, float y, sf::Sprite entity);
//
//	void moveFoward(gen::map<float>& m, entity& who);
//	bool canAdvance(gen::map<float>& m, const float& y, const float& x, const int& direction, int cas);
//};