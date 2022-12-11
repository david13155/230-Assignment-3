#pragma once
#include "ParticleEffect.h"
#include "CircleParticle.h"
class SnowEffect :
	public ParticleEffect
{
protected:
	float width = 50.f;
public:
	SnowEffect();
	SnowEffect(const sf::Vector2i& position, int lifespan, int particleNum, float width, bool loop);

	virtual void Update(sf::RenderWindow& window);
	virtual void createParticle(int index);

	~SnowEffect();
};

