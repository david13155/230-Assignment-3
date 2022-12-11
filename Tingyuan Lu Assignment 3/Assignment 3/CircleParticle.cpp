#include "CircleParticle.h"

using namespace sf;

CircleParticle::CircleParticle() : GeometryParticle() {
	shape = new CircleShape();
	shape->setFillColor(color);
}
CircleParticle::CircleParticle(const Vector2f& position, const Vector2f& velocity, float size, int lifespan)
	: GeometryParticle(position, velocity, lifespan) {
	shape = new CircleShape(size);
	shape->setFillColor(color);
	shape->setPosition(position);
}

void CircleParticle::Update(sf::RenderWindow& window) {
	Particle::Update(window);
}
void CircleParticle::Render(sf::RenderWindow& window) {
	window.draw(*dynamic_cast<CircleShape*>(shape));
}

void CircleParticle::setRadius(float radius) {
	dynamic_cast<CircleShape*>(shape)->setRadius(radius);
}
const float CircleParticle::getRadius() const {
	return dynamic_cast<CircleShape*>(shape)->getRadius();
}

CircleParticle::~CircleParticle() {
	delete shape;
}