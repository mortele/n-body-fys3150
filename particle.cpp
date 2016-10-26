#include "particle.h"
#include "randomnumbergenerator.h"


void Particle::randomizePosition(double a, double b) {
    double x = RandomNumberGenerator::uniform(a, b);
    double y = RandomNumberGenerator::uniform(a, b);

    m_position.set(x,0);
    m_velocity.set(0,0);
    m_force   .set(0,0);
}
