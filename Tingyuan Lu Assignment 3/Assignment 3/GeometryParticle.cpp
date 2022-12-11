#include "GeometryParticle.h"

using namespace sf;

GeometryParticle::GeometryParticle(): shape(nullptr) {};

GeometryParticle::GeometryParticle(const Vector2f& position, const Vector2f& velocity, int lifespan)
:Particle(position, velocity, lifespan), shape(nullptr){
}

void GeometryParticle::setPosition(const Vector2f& pos) {
	shape->setPosition(pos);
	Particle::setPosition(position);
}
void GeometryParticle::setVelocity(const Vector2f& v) {
	velocity = v;
}
void GeometryParticle::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
	color = Color(r, g, b, a);
	shape->setFillColor(color);
}

void GeometryParticle::setRotateSpeed(float rSpeed) {
	this->rotateSpeed = rSpeed;
}
void GeometryParticle::setRotate(float angle) {
	shape->setRotation(angle);
}

const Vector2f& GeometryParticle::getPosition() const {
	return shape->getPosition();
}
const Vector2f& GeometryParticle::getVelocity() const {
	return velocity;
}
const Shape* GeometryParticle::getShape() const {
	return shape;
}
const Color& GeometryParticle::getColor() const {
	return color;
}

void GeometryParticle::sleep() {
	velocity = Vector2f(0.f, 0.f);
	shape->setPosition(0.f, 0.f);
	shape->setFillColor(Color::Transparent);
	alive = false;
	lifespan = 0;
}
void GeometryParticle::reset(const Vector2f& position = Vector2f(0.f, 0.f), const Vector2f& velocity = Vector2f(0.f, 0.f), int lifespan =100) {
	shape->setFillColor(color);
	shape->setPosition(position);
	this->velocity = velocity;
	this->lifespan = lifespan;
	alive = true;
}

GeometryParticle::~GeometryParticle() {
	delete shape;
}