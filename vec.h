#pragma once
#include <iostream>
#include <iomanip>

class Vec {
private:
    double m_x;
    double m_y;

public:
    Vec() : m_x(0), m_y(0) {}
    Vec(double x, double y) : m_x(x), m_y(y) {}

    void set(double x,  double y);
    double operator[](int i) { return (i==0) ? m_x : m_y; }
    Vec& operator+=(double value);
    Vec& operator+=(const Vec& other);
    Vec& operator-=(double value);
    Vec& operator-=(const Vec& other);
    friend Vec operator+(Vec left, const Vec& right);
    friend Vec operator+(Vec left, const double right);
    friend Vec operator-(Vec left, const Vec& right);
    friend Vec operator-(Vec left, const double right);

    friend std::ostream& operator<<(std::ostream& os, const Vec& vec);
};
