#include "vec.h"
#include "randomnumbergenerator.h"

using std::setprecision;
using std::setw;

void Vec::set(double x, double y) {
    m_x = x;
    m_y = y;
}

Vec& Vec::operator+=(double value) {
    m_x += value;
    m_y += value;
    return *this;
}

Vec&Vec::operator*=(double value) {
    m_x *= value;
    m_y *= value;
    return *this;
}

Vec&Vec::operator/=(double value) {
    m_x /= value;
    m_y /= value;
    return *this;
}

Vec& Vec::operator+=(const Vec& other) {
    m_x += other.m_x;
    m_y += other.m_y;
    return *this;
}

Vec&Vec::operator-=(double value) {
    m_x -= value;
    m_y -= value;
    return *this;
}

Vec&Vec::operator-=(const Vec& other) {
    m_x -= other.m_x;
    m_y -= other.m_y;
    return *this;
}

Vec operator/(Vec left, const double right) {
    left /= right;
    return left;
}

Vec operator*(Vec left, const double right) {
    left *= right;
    return left;
}

Vec operator+(Vec left, const double right) {
    left += right;
    return left;
}

Vec operator-(Vec left, const double right) {
    left -= right;
    return left;
}

Vec operator+(Vec left, const Vec& right) {
    left += right;
    return left;
}

Vec operator-(Vec left, const Vec& right) {
    left -= right;
    return left;
}

std::ostream& operator<<(std::ostream& os, const Vec& vec) {
    os  << setw(4) << setprecision(2) << vec.m_x;// << ", "
        //<< setw(10) << setprecision(2) << vec.m_y;
    return os;
}
