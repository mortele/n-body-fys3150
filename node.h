#pragma once
#include <vector>
#include "vec.h"
#include "particle.h"

class Node {
private:
    double      m_length;
    double      m_lengthHalf;
    bool        m_isEmpty;
    Vec         m_position;
    Particle*   m_particle;

    bool        m_northEastInitialized  = false;
    bool        m_northWestInitialized  = false;
    bool        m_southEastInitialized  = false;
    bool        m_southWestInitialized  = false;
    Node*       m_northEast             = nullptr;
    Node*       m_northWest             = nullptr;
    Node*       m_southEast             = nullptr;
    Node*       m_southWest             = nullptr;

public:
    Node(Vec position, double length);

    bool    insertParticle(Particle* particle);
    Node*   computeSubQuadrant(Particle* Particle);
};
