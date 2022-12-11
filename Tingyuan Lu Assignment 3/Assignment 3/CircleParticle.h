#ifndef CIRCLE_PARTICLE_H
#define CIRCLE_PARTICLE_H
#include "GeometryParticle.h"

class CircleParticle :
    public GeometryParticle
{
public:
    //Constructor
    CircleParticle();
    CircleParticle(const sf::Vector2f& position, const sf::Vector2f& velocity, float size, int lifespan);

    //update and render functions
    virtual void Update(sf::RenderWindow& window);
    virtual void Render(sf::RenderWindow& window);

    //Setters are already implemented but size
    virtual void setRadius(float radius);
    //Getters are already implemented but size
    virtual const float getRadius() const;

    //functions to reset and turn off shape had been implemented
    //virtual void Sleep();
    //virtual void Reset(const sf::Vector2f& position, const sf::Vector2f& velocity, int lifespan);

    ~CircleParticle();
};
#endif
