#pragma once
#ifndef BUBBLE_EFFECT_H
#include "ParticleEffect.h"

class BubbleEffect :public ParticleEffect {
public:
	BubbleEffect();
	BubbleEffect(const sf::Vector2i& position, int lifespan, int particleNum, bool loop);
	virtual void Update(sf::RenderWindow& window);
	virtual void createParticle(int index);
	~BubbleEffect();
};
#endif // !BUBBLE_EFFECT_H
