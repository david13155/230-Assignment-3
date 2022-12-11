#ifndef PARTICLE_EFFECT_H
#define PARTICLE_EFFECT_H
#include "Game.h"
#include "Particle.h"
#include <vector>

class ParticleEffect
{
protected:
	sf::Vector2f position;
	int lifespan;

	std::vector<Particle*> particles;
	boolean alive = false;
	int particleNum;
	bool loop = false;

public:
	ParticleEffect();
	ParticleEffect(const sf::Vector2f& position, int lifespan, int particleNum, bool loop);
	virtual void Update(sf::RenderWindow& window);
	virtual void Render(sf::RenderWindow& window);

	virtual void createParticle(int index) = 0;

	virtual void Emit();

	virtual boolean isAlive() const;
	~ParticleEffect();
};


#endif

