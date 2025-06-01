#include "Velocity.h"
#include <cmath>
#include <iostream>

ArrayList<std::tuple<Vector2D, Vector2D, double>> velocity(double y, double dt, double degree) {
    const double rho = 1.204;                                      // Densitet
    const double C_d = 0.47;                                       // Drag coefficient
    const double eta = 1.837 * pow(10, -5);                        // Viskositet
    const double d = 0.68;                                         // Diameter i inches
    const double r = (d * 0.5) / 39.37;                            // Kuglens radius i meter
    const double A = M_PI * pow(r, 2);                             // Tværsnit af kugle er pi*r^2
    const double v_0 = 91.0;                                       // Velocity at 0
    double v;                                                      // velocity variabel
    const double m = 3.2 / 1000.0;                                 // Mass i g
    const double g = 9.82;                                         // Tyngdeacceleration
    double x = 0;                                                  // længde i x akse
    double t = 0;                                                  // forskel pr step
    double V_y = 0.0;                                              // Hastighed for Y
    double V_x = 0.0;                                              // Hastighed for X

    ArrayList<std::tuple<Vector2D, Vector2D, double>> VectorListe; // Bruger ArrayList i stedet for vector

    v = v_0 + dt * (-1 * ((0.5 * rho * C_d * A) / m) * pow(v_0, 2.0) - ((6.0 * M_PI * eta * r) / m) * v_0); // Første værdi med V_0
    V_x = cos(degree * M_PI / 180) * v;
    V_y = sin(degree * M_PI / 180) * v;

    std::cout << "V_x = " << V_x << std::endl;
    std::cout << "V_y = " << V_y << std::endl;

    VectorListe.add(std::tuple<Vector2D, Vector2D, double>(Vector2D(x, y), Vector2D(V_x, V_y), t));
    std::cout << "Røv X = " << y << ", dt = " << dt << ", degree = " << degree << std::endl;

    while (y > 0) {
        V_x = V_x + dt * (-1 * ((0.5 * rho * C_d * A) / m) * pow(V_x, 2.0) - ((6.0 * M_PI * eta * r) / m) * V_x); // udregn hastigheden for X
        V_y = V_y + dt * (-1 * ((0.5 * rho * C_d * A) / m) * pow(V_y, 2.0) - ((6.0 * M_PI * eta * r) / m) * V_y - g); // udregn hastigheden for Y
        x = x + V_x * dt; // udregn længde bevæget sig lægger x til den nye x værdi
        y = y + V_y * dt; // Udregn højde ud fra kuglens hastighed

        VectorListe.add(std::tuple<Vector2D, Vector2D, double>(Vector2D(x, y), Vector2D(V_x, V_y), t)); // Tilføj elementer med add

        std::cout << "Røv X = " << x << ", Y = " << y << ", t = " << t << ", V_x = " << V_x << ", V_y = " << V_y << std::endl;
        t = t + dt;
    }

    std::cout << VectorListe.size() << std::endl;
    for (int i = 0; i < VectorListe.size(); ++i) {
        std::cout << "X = " << std::get<0>(VectorListe[i]).getx() << " Y = " << std::get<0>(VectorListe[i]).gety() << " Tid = " << std::get<2>(VectorListe[i]) << std::endl;
    }

    return VectorListe;
}
