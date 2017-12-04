/*************************************************************************************
 *	Auteur:		Micael Gaumond-Roy
 *	Date:		01/12/2017
 *	Fichier:	game.cpp
 *	But:		@@@@@@@@@
 ************************************************************************************/
#include "game.h"

game::game()
{
}

game::~game()
{
}

bool game::init()
{
	//cree la fenetre principale
	RenderWindow window(VideoMode(1280, 720, 32), ("Game"));

	//limite le FPS a 60
	window.setFramerateLimit(60);

	//texture renderer
	textureRenderer<Texture> mapTex;
	
	///pour les mouvements du player
	//textureRenderer<Texture> playerMove;

	//image du plancher
	Texture floorTex;
	Sprite* floor;
	mapTex.add(floorTex);
	if (!floorTex.loadFromFile("floor.png"))
		return EXIT_FAILURE;

	//image des murs
	Texture wallTex;
	Sprite* wall;
	mapTex.add(wallTex);
	if (!wallTex.loadFromFile("wall.png"))
		return EXIT_FAILURE;

	//image des coin de murs
	Texture cornerTex;
	Sprite* corner;
	mapTex.add(cornerTex);
	if (!wallTex.loadFromFile("corner.png"))
		return EXIT_FAILURE;

	//image des petits murs horizontal
	Texture boxTex;
	Sprite* box;
	mapTex.add(boxTex);
	if (!boxTex.loadFromFile("box.png"))
		return EXIT_FAILURE;

	//image du joueur
	Texture playerTex;
	Sprite* player;
	mapTex.add(boxTex);
	if (!playerTex.loadFromFile("player.png"))
		return EXIT_FAILURE;

	//flux d'entree
	ifstream input;
	input.open("map01.txt");

	//carte du jeu
	gen::map<int> gameMap;
	gameMap.resize(32, 18);
	gameMap.read(input);
	input.close();

	//boucle de l'execution principale
	while (window.isOpen())
	{
		//boucle d'evenement
		event(window);

		//mise a jour de la fenetre
		window.display();

		//for (int line = 0; line < 32; line++)
		//	for (int col = 0; col < 18; col++)
		//		switch (gameMap[line][col])
		//		{
		//		case typeFloor:
		//		{
		//			print(floor, typeFloor, line, col);
		//			window.draw(*floor);
		//			break;
		//		}
		//		/*case typeWall:
		//			mapTex.print(wall, typeWall, line, col);
		//			window.draw(*wall);
		//			break;
		//		case typeCorner:
		//			mapTex.print(corner, typeCorner, line, col);
		//			window.draw(*corner);
		//			break;
		//		case typeBox:
		//			mapTex.print(box, typeBox, line, col);
		//			window.draw(*box);
		//			break;
		//		case typePlayer:
		//			mapTex.print(player, typePlayer, line, col);
		//			break;*/
		//		}
	}

	window.clear();

	return 0;
}

void game::event(RenderWindow& window)
{
	//evenement de processus
	Event event;
	while (window.pollEvent(event))
	{
		///test de deplacement
		/*if (Keyboard::W)
			player.setPosition(Vector2f(player.getPosition().x, player.getPosition().y - 2.0));*/

		//ferme la fenetre
		if (event.type == Event::Closed)
			window.close();
	}
}

void game::print(Sprite* sprite, texture_type type, int noLine, int noCol)
{
	sprite = new Sprite;
	sprite->setTexture(_texRen[type]);
	sprite->setPosition(Vector2f((float)(noLine * 40), ((float)noCol * 40)));
}
