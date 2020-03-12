#include "vec2.h"
#include <ostream>
#include <istream>
#include <cmath>

using namespace std;

vec2::vec2() {
    this->x = 0;
    this->y = 0;
}

vec2::vec2(double x, double y) {
    this->x = x;
    this->y = y;
}

vec2 vec2::operator*  (double k) const {
    return {this->x * k, this->y * k};
}

vec2& vec2::operator*=  (const double k) {
    this->x *= k;
    this->y *= k;
    return *this;
}
vec2 vec2::operator+ (const vec2 &other) {
    return {this->x + other.x, this->y + other.y};
}

vec2 vec2::getRotated(double phi) const {
    double s = sin(phi), c = cos(phi);
    return {this->x * c - this->y * s, this->x * s + this-> y * c};
}

vec2 vec2::operator/ (const double k) const {
    return {this->x / k, this->y / k};
}

double vec2::operator* (const vec2& other) const {
    return this->x * other.x + this->y * other.y;
}

double vec2::operator^ (const vec2& other) const {
    return this->x * other.y - this->y * other.x;
}

vec2& vec2::operator+= (const vec2& other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
}

vec2 vec2::operator- (const vec2& other) {
    return *this + (other * -1);
}

vec2& vec2::operator-= (const vec2& other) {
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}

vec2 vec2::operator- () const {
    return *this * -1;
}

double vec2::len() const {
    return sqrt(this->lenSquared());
}

double vec2::lenSquared() const {
    return *this * *this;
}

vec2& vec2::rotate(double phi) {
    *this = this->getRotated(phi);
    return *this;
}

vec2 vec2::getNormalized() const {
    return *this / this->len();
}

vec2 vec2::getPerp() const {
    return vec2(this->y, -this->x);
}

vec2 operator* (double k, const vec2 v) {
  return v * k;
}

ostream& operator<<  (ostream& stream, const vec2 v) {
  stream << v.x << " " << v.y;
  return stream;
}

istream& operator>>  (istream& stream, vec2& v) {
   stream >> v.x >> v.y;
   return stream;
 }
