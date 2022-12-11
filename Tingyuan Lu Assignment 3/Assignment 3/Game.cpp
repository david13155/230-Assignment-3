#include "Game.h"
#include "SnowEffect.h"
#include "BubbleEffect.h"
using namespace gm;
using namespace std;

ParticleEffect* currentParticleEffect;

enum particleType { Bubbles, snow };
particleType type = Bubbles;

Game::Game() {

}

void Game::handleInput(sf::RenderWindow& window) {

	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Button::Left) {
				if (currentParticleEffect != nullptr)
					delete currentParticleEffect;

				switch (type)
				{
				case particleType::Bubbles:
					currentParticleEffect = new BubbleEffect(sf::Mouse::getPosition(window), 600, 150, true);
					dynamic_cast<BubbleEffect*>(currentParticleEffect)->Emit();
					break;
				case particleType::snow:
					currentParticleEffect = new SnowEffect(sf::Mouse::getPosition(window), 600, 50, 200.f, true);
					dynamic_cast<SnowEffect*>(currentParticleEffect)->Emit();
					break;
				default:
					cout << "type error" << endl;
					break;
				}
			}
		}
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Num1) {
				type = particleType::Bubbles;
			}
			if (event.key.code == sf::Keyboard::Num2) {
				type = particleType::snow;
			}
		}

	}
}
void Game::update(sf::RenderWindow& window) {

	if (currentParticleEffect != nullptr)
		currentParticleEffect->Update(window);
}
void Game::render(sf::RenderWindow& window) {
	window.clear();

	if (currentParticleEffect != nullptr)
		currentParticleEffect->Render(window);

	window.display();
}

float gm::RandomFloat(float min, float max) {
	return (min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min))));
}

int gm::RandomInt(int min, int max) {
	int temp = min + rand() % (max - min + 1);
	if (temp == 0) {
		return 1;
	}
	return temp;
}

Game::~Game() {

}