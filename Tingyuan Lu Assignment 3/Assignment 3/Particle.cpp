#include "Particle.h"

using namespace sf;

Particle::Particle() : lifespan(0) {};

Particle::Particle(const Vector2f& position, const Vector2f& velocity, int lifespan)
	: position(position), velocity(velocity), lifespan(lifespan), alive(true) {
}

Particle::~Particle() {

}

void Particle::Update(RenderWindow& window) {
	if (alive)
		lifespan--;
	if (alive && lifespan <= 0) {
		sleep();
	}
}

void Particle::setPosition(const sf::Vector2f& pos) {
	position = pos;
}
void Particle::setVelocity(const sf::Vector2f& v) {
	velocity = v;
}

void Particle::setLifespan(int life) {
	this->lifespan = life;
};
void Particle::setAlive(bool a) {
	this->alive = a;
};

const Vector2f& Particle::getPosition() const {
	return position;
}
const Vector2f& Particle::getVelocity() const {
	return velocity;
}
const int Particle::getLifespan() const {
	return lifespan;
}
const boolean Particle::isAlive() const {
	return alive;
}
