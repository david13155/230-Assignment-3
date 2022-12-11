#ifndef SHAPE_PARTICLE_H
#define SHAPE_PARTICLE_H
#include "Particle.h"

class GeometryParticle :
    public Particle
{
protected:
    // A shape pointer for the particle
    sf::Shape* shape;
    sf::Color color = sf::Color::White;

    float rotateSpeed = 0.f;

public:


    GeometryParticle();
    GeometryParticle(const sf::Vector2f& position, const sf::Vector2f& velocity, int lifespan);

    virtual void Update(sf::RenderWindow& window) = 0;
    virtual void Render(sf::RenderWindow& window) = 0;

    virtual void setPosition(const sf::Vector2f& pos);
    virtual void setVelocity(const sf::Vector2f& v);
    virtual void setColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 a);
    virtual void setRotateSpeed(float rSpeed);
    virtual void setRotate(float angle);

    virtual const sf::Vector2f& getPosition() const;
    virtual const sf::Vector2f& getVelocity() const;
    virtual const sf::Shape* getShape() const;
    virtual const sf::Color& getColor() const;

    virtual void sleep();
    virtual void reset(const sf::Vector2f& position, const sf::Vector2f& velocity, int lifespan);

    ~GeometryParticle();
};
#endif

