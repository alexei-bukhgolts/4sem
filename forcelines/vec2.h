#pragma once
#include <ostream>

struct vec2 {
    double x, y;

    vec2();
    vec2(double x, double y);

    vec2 operator* (const double k) const;
    vec2 operator/ (const double k) const;

    double operator* (const vec2& other) const;
    double operator^ (const vec2& other) const;
    vec2& operator*= (const double k);
    vec2 operator+ (const vec2& other);
    vec2& operator+= (const vec2& other);
    vec2 operator- (const vec2& other);
    vec2& operator-= (const vec2& other);

    vec2 operator- () const;

    double len() const;
    double lenSquared() const;

    vec2& rotate(double phi);
    vec2 getRotated(double phi) const;
    vec2 getNormalized() const;
    vec2 getPerp() const;
};

std::ostream& operator<< (std::ostream& stream, vec2 v);
std::istream& operator>> (std::istream& stream, vec2& v);
vec2 operator*(double k, vec2 v);
