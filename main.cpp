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
    RandomNumberGenerator::seed(1294859823104995824);

    int N = 3;
    vector<Particle*> particles;
    particles.resize(N);

    Node parent(Vec(0.0, 0.0), 1.0);

    for (int i=0; i<1*N; i++) {
        double r = RandomNumberGenerator::uniform(0,1);
    }

    cout << "[";
    for (int i=0; i<N; i++) {
        Particle* p = new Particle();
        particles.at(i) = p;
        p->randomizePosition(-0.5, 0.5);
        parent.insertParticle(p);
        cout << p->getPosition();
        if (i != N-1) {
            cout << ";" << endl;
        } else {
            cout << "]" << endl;
        }
    }


    parent.printTree(0);

    return 0;
}
