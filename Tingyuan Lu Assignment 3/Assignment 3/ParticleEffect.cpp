#include "ParticleEffect.h"
#include "CircleParticle.h"

ParticleEffect::ParticleEffect() : lifespan(0), particleNum(0) {}

ParticleEffect::ParticleEffect(const sf::Vector2f& position, int lifespan, int particleNum, bool loop)
	: position(position), lifespan(lifespan), particleNum(particleNum), loop(loop), alive(true) {
	particles = std::vector<Particle*>(particleNum, nullptr);
}

void ParticleEffect::Emit() {
	for (int i = 0; i < particleNum; i++) {
		createParticle(i);
	}
}

void ParticleEffect::Update(sf::RenderWindow& window) {
	for (int i = 0; i < particleNum; i++) {
		particles[i]->Update(window);
	}

	if (!loop) {
		lifespan--;
		if (lifespan <= 0)
			alive = false;
	}
}
void ParticleEffect::Render(sf::RenderWindow& window) {
	for (int i = 0; i < particleNum; i++) {
		particles[i]->Render(window);
	}
}

boolean ParticleEffect::isAlive() const {
	return alive;
}

ParticleEffect::~ParticleEffect() {
	for (int i = 0; i < particleNum; i++) {
		delete particles[i];
	}
}