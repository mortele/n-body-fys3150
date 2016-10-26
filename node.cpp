#include "node.h"
#include <iomanip>

using std::cout;
using std::endl;

/*
 * http://beltoforion.de/article.php?a=barnes-hut-galaxy-simulator
 *

Function TreeNode::InsertToNode(newParticle) {

    if (number of particles in this node > 1) {
        quad = GetQuadrant(newParticle);

        if subnode(quad) does not exist {
            create subnode(quad)
        }

        subnode(quad)->InsertToNode(newParticle)

    } else if (number of particles in this node == 1) {
        quad = GetQuadrant(existingParticle);
        if subnode(quad) does not exist {
            create subnode(quad)
        }
        subnode(quad)->InsertToNode(existingParticle)

        quad = GetQuadrant(newParticle);
        if subnode(quad) does not exist
            create subnode(quad)
        subnode(quad)->InsertToNode(newParticle);
    } else if node is empty {
        store newParticle in node as existingParticle
    }

    Increase number of particles
}
*/

Node::Node(Vec position, double length) {
    m_position          = position;
    m_length            = length;
    m_lengthHalf        = 0.5 * length;
    m_numberOfParticles = 0;
    m_totalMass         = 0;
    m_centerOfMassTimesMass = Vec();
    m_centerOfMass      = Vec();
}


void Node::insertParticle(Particle* particle) {
    m_centerOfMassTimesMass += particle->getPosition() * particle->getMass();
    m_totalMass             += particle->getMass();
    m_centerOfMass           = m_centerOfMassTimesMass / m_totalMass;

    if (m_numberOfParticles > 1) {
        Node* quad = computeSubQuadrant(particle);
        quad->insertParticle(particle);

    } else if (m_numberOfParticles == 1) {
        Node* quadOld = computeSubQuadrant(m_particle);
        quadOld->insertParticle(m_particle);
        Node* quadNew = computeSubQuadrant(particle);
        quadNew->insertParticle(particle);

    } else if (m_numberOfParticles == 0) {
        m_particle = particle;

    } else {
        cout << "Invalid number of particles in node: " << m_numberOfParticles << endl;
    }
    m_numberOfParticles++;
}


Node* Node::computeSubQuadrant(Particle *Particle) {
    Vec& particlePosition = Particle->getPosition();
    bool right = (particlePosition[0] > m_position[0]);

    if (right) {
        if (! m_rightInitialized) {
            m_right = new Node(m_position + 0.5*m_lengthHalf, m_lengthHalf);
            m_rightInitialized = true;
        }
        return m_right;
    } else {
        if (! m_leftInitialized) {
            m_left = new Node(m_position - 0.5*m_lengthHalf, m_lengthHalf);
            m_leftInitialized = true;
        }
        return m_left;
    }
}

void Node::printTree(int level, bool right) {
    cout << std::setw(2) << level << " ";
    for (int i=0; i<level; i++) {
        cout << " .";
    }
    if (right) {
        cout << "R " << *this << endl;
    } else {
        cout << "L " << *this << endl;
    }
    if (m_rightInitialized) {
        m_right->printTree(level+1, true);
    }
    if (m_leftInitialized) {
        m_left->printTree(level+1, false);
    }
}

std::ostream& operator<<(std::ostream& os, const Node& node) {
    os << &node << " SubNode: (" << (node.m_rightInitialized== true) << ","
                                 << (node.m_leftInitialized == true) << ")";
    os << " ["  << node.m_position-node.m_lengthHalf    << ", "
                << node.m_position+node.m_lengthHalf    << "] ";
    os << " cm{" << node.m_centerOfMass << "}";
    os << " M=" << node.m_totalMass;
    if (node.m_numberOfParticles == 1) {
        os << " Particle: " << node.m_particle->getPosition();
    }
    return os;
}


/*
Node* Node::computeSubQuadrant(Particle* Particle) {
    Vec& particlePosition = Particle->getPosition();
    bool east  = particlePosition[0] > (m_position[0] - m_lengthHalf);
    bool north = particlePosition[1] > (m_position[1] - m_lengthHalf);

    if (north && east) {
        if (! m_northEastInitialized) {
            m_northEast = new Node(m_position + 0.5 * (+ north + east), m_lengthHalf);
            m_northEastInitialized = true;
        }
        return m_northEast;
    } else if (north && !east) {
        if (! m_northWestInitialized) {
            m_northWest = new Node(m_position + 0.5 * (+ north - east), m_lengthHalf);
            m_northWestInitialized = true;
        }
        return m_northWest;
    } else if (!north && east) {
        if (! m_southEastInitialized) {
            m_southEast = new Node(m_position + 0.5 * (- north + east), m_lengthHalf);
            m_southEastInitialized = true;
        }
        return m_southEast;
    } else if (!north && !east) {
        if (! m_southWestInitialized) {
            m_southWest = new Node(m_position + 0.5 * (- north - east), m_lengthHalf);
            m_southWestInitialized = true;
        }
        return m_southWest;
    } else {
        return nullptr;
    }
}

std::ostream& operator<<(std::ostream& os, const Node& node) {
    if (node.m_numberOfParticles == 1) {
        os << &node << "SubNode: (" << (node.m_northEastInitialized == true) << ","
           << (node.m_northWestInitialized == true) << ","
           << (node.m_southEastInitialized == true) << ","
           << (node.m_southWestInitialized == true) << ")"
           << " Particle: " << node.m_particle->getPosition();
    } else {
        if (node.m_numberOfParticles > 1) {
            if (node.m_northEastInitialized) {
                os << node.m_northEast;
            }
            if (node.m_northWestInitialized) {
                os << node.m_northWest;
            }
            if (node.m_southEastInitialized) {
                os << node.m_southEast;
            }
            if (node.m_southWestInitialized) {
                os << node.m_southWest;
            }
        }
    }
    return os;
}*/










