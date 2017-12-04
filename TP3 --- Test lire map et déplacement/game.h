/*************************************************************************************
 *	Auteur:		Micael Gaumond-Roy
 *	Date:		01/12/2017
 *	Fichier:	game.h
 *	But:		@@@@
 ************************************************************************************/
#pragma once
#include "textureRenderer.hpp"
#include <fstream>
#include <string>

 //enumerateur de texture
enum texture_type
{
	typeFloor,
	typeWall,
	typeCorner,
	typeBox,
	typePlayer
};

class game
{
private:
	textureRenderer<Texture> _texRen;

public:
	game();
	~game();

	bool init();

	void event(RenderWindow& window);
	void print(Sprite* sprite, texture_type type, int noLine, int noCol);
};