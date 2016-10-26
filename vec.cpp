#include "vec.h"
#include "randomnumbergenerator.h"


void Vec::set(double x, double y) {
    m_x = x;
    m_y = y;
}

Vec& Vec::operator+=(double value) {
    m_x += value;
    m_y += value;
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

Vec operator+(Vec left, const Vec& right) {
    left += right;
    return left;
}

Vec operator-(Vec left, const Vec& right) {
    left -= right;
    return left;
}

std::__1::ostream& operator<<(std::__1::ostream& os, const Vec& vec) {
    os  << vec.m_x << ", " << vec.m_y;
    return os;
}

/*
void Vec::set(double x, double y) {
    m_x = x;
    m_y = y;
    m_z = z;
}

Vec& Vec::operator+=(double value) {
    m_x += value;
    m_y += value;
    m_z += value;
    return *this;
}

Vec& Vec::operator+=(const Vec& other) {
    m_x += other.m_x;
    m_y += other.m_y;
    m_z += other.m_z;
    return *this;
}
*/
