#include "BubbleEffect.h"
#include "CircleParticle.h"

using namespace sf;

BubbleEffect::BubbleEffect() : ParticleEffect(){}
BubbleEffect::BubbleEffect(const sf::Vector2i& position, int lifespan, int particleNum, bool loop)
	:ParticleEffect(Vector2f(float(position.x), float(position.y)), lifespan, particleNum, loop){
}

void BubbleEffect::Update(sf::RenderWindow& window)
{
	ParticleEffect::Update(window);
	int red,green,blue,alpha;
	red = gm::RandomInt(0, 255);
	blue = gm::RandomInt(0, 255);
	green = gm::RandomInt(0, 255);
	alpha = gm::RandomInt(0, 255);
	for (unsigned int i = 0; i < particles.size(); i++) {
		if (particles[i]->isAlive()) {
			alpha = dynamic_cast<CircleParticle*>(particles[i])->getColor().a;
			red = dynamic_cast<CircleParticle*>(particles[i])->getColor().a;
			green = dynamic_cast<CircleParticle*>(particles[i])->getColor().a;
			blue = dynamic_cast<CircleParticle*>(particles[i])->getColor().a;
			if (alpha > 0) {
				alpha -= 1;
			}
		}
		dynamic_cast<CircleParticle*>(particles[i])->setColor(red, green, blue, alpha);
		dynamic_cast<CircleParticle*>(particles[i])->setPosition(
			Vector2f(dynamic_cast<CircleParticle*>(particles[i])->getPosition().x + dynamic_cast<CircleParticle*>(particles[i])->getVelocity().x,
				dynamic_cast<CircleParticle*>(particles[i])->getPosition().y + dynamic_cast<CircleParticle*>(particles[i])->getVelocity().y));
		if (loop && (!particles[i]->isAlive())) {
			particles[i]->reset(position, Vector2f(gm::RandomFloat(-1.f, 1.f), gm::RandomFloat(-1.f, 1.f)), gm::RandomInt(100, 600));
		}
	}
}

void BubbleEffect::createParticle(int index)
{
	CircleParticle* particle = new CircleParticle(position, Vector2f(gm::RandomFloat(-1.f, 1.f), gm::RandomFloat(-1.f, 1.f)), float(gm::RandomInt(2, 15)), gm::RandomInt(100, lifespan));
	particle->setColor(gm::RandomInt(0,255), gm::RandomInt(0,255), gm::RandomInt(0,255), 255);
	particle->setPosition(Vector2f(float(position.x) - particle->getRadius(), float(position.y) - particle->getRadius()));
	particles[index] = particle;
}

BubbleEffect::~BubbleEffect()
{
	for (unsigned int i = 0; i < particles.size(); i++) {
		delete particles[i];
	}
}

