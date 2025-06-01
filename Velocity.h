#ifndef VELOCITY_H
#define VELOCITY_H

#include "Vector2D.h"
#include "ArrayList.h"
#include <tuple>

ArrayList<std::tuple<Vector2D, Vector2D, double>> velocity(double y, double dt, double degree);

#endif // VELOCITY_H
