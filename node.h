#pragma once
#include <vector>
#include <iostream>
#include "vec.h"
#include "particle.h"

class Node {
private:
    int         m_numberOfParticles;
    double      m_length;
    double      m_lengthHalf;
    Vec         m_position;
    Particle*   m_particle;

    /*
    bool        m_northEastInitialized  = false;
    bool        m_northWestInitialized  = false;
    bool        m_southEastInitialized  = false;
    bool        m_southWestInitialized  = false;
    Node*       m_northEast             = nullptr;
    Node*       m_northWest             = nullptr;
    Node*       m_southEast             = nullptr;
    Node*       m_southWest             = nullptr;
    */

    bool        m_rightInitialized = false;
    bool        m_leftInitialized  = false;
    Node*       m_right = nullptr;
    Node*       m_left  = nullptr;

public:
    Node(Vec position, double length);

    void    insertParticle(Particle* particle);
    Node*   computeSubQuadrant(Particle* Particle);
    void    printTree(int level, bool right=false);
    friend std::ostream& operator<<(std::ostream& os, const Node& node);
};
