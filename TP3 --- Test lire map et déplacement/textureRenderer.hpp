/*************************************************************************************
 *	Auteur:		Micael Gaumond-Roy
 *	Date:		30/11/2017
 *	Fichier:	textureRenderer.hpp
 *	But:		Vecteur d'image pour afficher dans une matrice
 ************************************************************************************/
#pragma once
#include "vecteur.hpp"
#include "map.hpp"
#include <SFML\Graphics.hpp>

using namespace sf;

template <class TYPE>
class textureRenderer : public gen::vecteur<TYPE>
{
private:
	vecteur<TYPE> _texVec;
public:
	textureRenderer();
	~textureRenderer();
	
	void add(Texture tex);
	//void print(Sprite* sprite, texture_type type, int noLine, int noCol);
	//bool loadTex(Texture tex, string texName);
};

//constructeur
template<class TYPE>
textureRenderer<TYPE>::textureRenderer()
{
	_texVec = NULL;
}

//destructeur
template<class TYPE>
textureRenderer<TYPE>::~textureRenderer()
{
	_texVec = NULL;
}

//ajoute une texture au vecteur de texture
template<class TYPE>
void textureRenderer<TYPE>::add(Texture tex)
{
	_texVec.push_back(tex);
}

///not sure
//template<class TYPE>
//void textureRenderer<TYPE>::print(Sprite* sprite, texture_type type, int noLine, int noCol)
//{
//	sprite = new Sprite;
//	sprite->setTexture(_texVec[type]);
//	sprite->setPosition(Vector2f((float)(noLine * 40), ((float)noCol * 40)));
//}

///probablement inutile
//template<class TYPE>
//bool textureRenderer<TYPE>::loadTex(Texture tex, string texName)
//{
//	if(!tex.loadFromFile(texName.c_str()))
//		return -1;
//}