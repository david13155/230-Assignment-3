#include "SnowEffect.h"

using namespace sf;

SnowEffect::SnowEffect() :ParticleEffect() {}

SnowEffect::SnowEffect(const sf::Vector2i& position, int lifespan, int particleNum, float width, bool loop) : ParticleEffect(sf::Vector2f(position.x, position.y), lifespan, particleNum, loop) {
	this->width = width;
}


void SnowEffect::Update(sf::RenderWindow& window) {
	ParticleEffect::Update(window);

	for (int i = 0; i < particles.size(); i++) {
		/*float leftmostX = (position.x - width / 2);
		float positionX = leftmostX + (((float)rand()) / (float)RAND_MAX) * width;
		particles[i]->setPosition(Vector2f(positionX, position.y));
		float velocityY = 0.1f + (((float)rand()) / (float)RAND_MAX) * (2.0f - 0.1f);
		particles[i]->setVelocity(Vector2f(0, velocityY));
		velocityY += 0.8f;*/
		dynamic_cast<CircleParticle*>(particles[i])->setPosition(
			Vector2f(dynamic_cast<CircleParticle*>(particles[i])->getPosition().x + dynamic_cast<CircleParticle*>(particles[i])->getVelocity().x,
				dynamic_cast<CircleParticle*>(particles[i])->getPosition().y + dynamic_cast<CircleParticle*>(particles[i])->getVelocity().y));
		if (fabs(particles[i]->getVelocity().x) + fabs(particles[i]->getVelocity().y) < 0.8 || particles[i]->getLifespan() == 0) {
			particles[i]->setAlive(false);
		}
		if (loop && (!particles[i]->isAlive())) {
			particles[i]->reset(Vector2f(position.x + gm::RandomFloat(-width / 2, width / 2), position.y), Vector2f(0, gm::RandomFloat(1.f, 1.2f)), gm::RandomInt(150, 200));
		}
	}
}

void SnowEffect::createParticle(int index) {
	CircleParticle* particle = new CircleParticle(Vector2f(position.x + gm::RandomFloat(-width / 2, width / 2), position.y), Vector2f(0, gm::RandomFloat(0.7f, 1.5f)), gm::RandomFloat(3.f, 5.f), gm::RandomInt(0, 150));
	particle->setColor(255, 255, 255, 255);
	if (particle->isAlive()) {
		particle->setColor(255, 255, 255, (int)(255 * gm::RandomFloat(0,1)*particle->getLifespan()));
	}
	particle->setRotate(gm::RandomFloat(0, 360));
	particles[index] = particle;
}

SnowEffect::~SnowEffect() {
	for (unsigned int i = 0; i < particles.size(); i++) {
		delete particles[i];
	}
}
