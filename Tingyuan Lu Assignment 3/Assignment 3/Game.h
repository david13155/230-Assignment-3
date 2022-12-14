// Our include guards
// These are critical for preventing collision related errors from a file accidentally getting fully included multiple times
#ifndef GAME_H
#define GAME_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <vector>
#include <cstdlib>

#include <iostream>

 /* My Includes */

// Place our classes, functions, variables, and so forth in their own namespace to avoid naming collisions
namespace gm {

	/* Our Game Class                               *
	 * Implements the Game Loop Programming Pattern */
	class Game {
	private:

	public:
		/* Protoypes */
		// Constructor
		Game();
		// Will start and manage the game loop programming pattern
		// Game Loop Programming Pattern Methods
		void handleInput(sf::RenderWindow& window);
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		// Destructor
		~Game();

		
	};
	float RandomFloat(float min, float max);
	int RandomInt(int min, int max);
}

#endif