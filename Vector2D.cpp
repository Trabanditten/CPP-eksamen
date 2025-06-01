#include "Vector2D.h"


Vector2D::Vector2D() {

}
Vector2D::Vector2D(double x, double y) {
    this->x=x;
    this->y=y;
}

double Vector2D::getx(){
    return x;
}
double Vector2D::gety(){
    return y;
}
