#include <iostream>
#include <vector>
#include "node.h"
#include "particle.h"
#include "vec.h"
#include "randomnumbergenerator.h"

using std::cout;
using std::endl;
using std::vector;


int main(int, char**) {
    RandomNumberGenerator::seed();

    int N = 10;
    vector<Particle*> particles;
    particles.resize(N);

    Node parent(Vec(0.5, 0.5), 1.0);

    for (int i=0; i<N; i++) {
        Particle* p = new Particle();
        particles.at(i) = p;
        p->randomizePosition(0,1);
        parent.insertParticle(p);
    }


    return 0;
}
