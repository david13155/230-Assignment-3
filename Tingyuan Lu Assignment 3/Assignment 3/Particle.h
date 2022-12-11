#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

class Particle
{
protected:

	sf::Vector2f position;
	sf::Vector2f velocity;
	int lifespan;
	boolean alive = false;

public:
	Particle();
	Particle(const sf::Vector2f& position, const sf::Vector2f& velocity, int lifespan);

	virtual void Update(sf::RenderWindow& window) = 0;//movement of particle
	virtual void Render(sf::RenderWindow& window) = 0;

	virtual void setPosition(const sf::Vector2f& pos);
	virtual void setVelocity(const sf::Vector2f& v);
	virtual void setLifespan(int life);
	virtual void setAlive(bool a);

	virtual const sf::Vector2f& getPosition() const;
	virtual const sf::Vector2f& getVelocity() const;
	virtual const int getLifespan() const;
	virtual const boolean isAlive() const;

	virtual void sleep() = 0;
	virtual void reset(const sf::Vector2f& position, const sf::Vector2f& velocity, int lifespan) = 0;

	~Particle();
};

