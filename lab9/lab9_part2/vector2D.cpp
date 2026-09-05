#include "vector2d.h"

Vector2D::Vector2D(double xVal, double yVal) {
    x = xVal;
    y = yVal;
}

double Vector2D::getX() const {
    return x;
}

double Vector2D::getY() const {
    return y;
}

void Vector2D::setX(double xVal) {
    x = xVal;
}

void Vector2D::setY(double yVal) {
    y = yVal;
}

double Vector2D::value() const {
    return std::sqrt(x * x + y * y);
}

double Vector2D::angleToXAxis() const {
    return std::atan2(y, x);
}

double Vector2D::angleToYAxis() const {
    return std::atan2(x, y);
}

double Vector2D::angleToVector(Vector2D v) const {
    double dot = x * v.getX() + y * v.getY();
    double magnitudes = value() * v.value();
    return std::acos(dot / magnitudes);
}

double Vector2D::scalarProduct(Vector2D v) const {
    return x * v.getX() + y * v.getY();
}

double Vector2D::vectorProduct(Vector2D v) const {
    return x * v.getY() - y * v.getX();
}
