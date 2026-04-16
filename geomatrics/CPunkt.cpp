//
// Created by rosar on 16.04.2026.
//

#include "CPunkt.h"
#include <cstdio>
#include <cmath>

CPunkt::CPunkt() : x(0.0), y(0.0) {}

CPunkt::CPunkt(double x, double y) : x(x), y(y) {}

double CPunkt::get_x() const {
    return this->x;
}

double CPunkt::get_y() const {
    return this->y;
}

void CPunkt::set_x(double x) {
    this->x = x;
}

void CPunkt::set_y(double y) {
    this->y = y;
}

void CPunkt::set_koordinaten(double x, double y) {
    this->x = x;
    this->y = y;
}

void CPunkt::output() const {
    printf("Punkt: (%.2f, %.2f)\n", this->x, this->y);
}

double CPunkt::distance_to(const CPunkt& other) const {
    double dx = this->x - other.x;
    double dy = this->y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}
