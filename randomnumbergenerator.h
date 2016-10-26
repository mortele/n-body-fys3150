#pragma once
#include <random>

static std::mt19937_64 generator;


class RandomNumberGenerator {
public:
    static void seed(unsigned long int seed=std::mt19937_64::default_seed) {
        generator.seed(seed);
    }

    static double uniform(double a, double b) {
        std::uniform_real_distribution<double> distribution(a,b);
        return distribution(generator);
    }
};

