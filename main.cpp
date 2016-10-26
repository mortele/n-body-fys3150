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
    RandomNumberGenerator::seed(12948598231049823);

    int N = 10000;
    vector<Particle*> particles;
    particles.resize(N);

    Node parent(Vec(0.0), 2.0);


    for (int i=0; i<N; i++) {
        Particle* p = new Particle(1.0);
        p->randomizePosition(-1.0,1.0);
        parent.insertParticle(p);
    }

    //parent.printTree(0);
    cout << parent.getCenterOfMass() << endl;

    return 0;
}
