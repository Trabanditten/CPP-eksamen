#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
public:
    Vector2D();
    Vector2D(double x,double y);
    double getx();
    double gety();
private:
    double x;
    double y;
};

#endif // VECTOR2D_H
