#pragma once
#include <cmath>

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double xVal = 0, double yVal = 0);

    double getX() const;
    double getY() const;
    void setX(double xVal);
    void setY(double yVal);

    double value() const;
    double angleToXAxis() const;
    double angleToYAxis() const;
    double angleToVector(Vector2D v) const;
    double scalarProduct(Vector2D v) const;
    double vectorProduct(Vector2D v) const;
};