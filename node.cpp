#include "node.h"

using std::cout;
using std::endl;


Node::Node(Vec position, double length) {
    m_position      = position;
    m_length        = length;
    m_lengthHalf    = 0.5 * length;
    m_isEmpty       = true;
}


bool Node::insertParticle(Particle* particle) {
    if (m_isEmpty) {
        m_particle = particle;
        m_isEmpty = false;
        return true;
    } else {
        Node* subQuadrant = computeSubQuadrant(particle);
        subQuadrant->insertParticle(particle);
    }
}


Node* Node::computeSubQuadrant(Particle* Particle) {
    Vec& particlePosition = Particle->getPosition();
    bool east  = particlePosition[0] > (m_position[0] - m_lengthHalf);
    bool north = particlePosition[1] > (m_position[1] - m_lengthHalf);

    if (north && east) {
        if (! m_northEastInitialized) {
            m_northEast = new
        }
        return m_northEast;
    } else if (north && !east) {
        return m_northWest;
    } else if (!north && east) {
        return m_southEast;
    } else if (!north && !east) {
        return m_southWest;
    } else {
        return nullptr;
    }
}

