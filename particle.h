#pragma once
#include "vec.h"

class Particle {
private:
    Vec m_position;
    Vec m_velocity;
    Vec m_force;

public:
    Particle() : m_position(Vec()), m_velocity(Vec()), m_force(Vec()) {}
    Particle(Vec position, Vec velocity) : m_position(position), m_velocity(velocity), m_force(Vec()) {}

    void randomizePosition(double a, double b);

    Vec& getPosition() { return m_position; }
};
