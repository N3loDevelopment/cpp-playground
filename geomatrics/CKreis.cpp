//
// Created by rosar on 16.04.2026.
//

#include "CKreis.h"

#include <cstdio>

coordinates CKreis::get_mittelpunkt() {
    return this->mittelPunkt;
}

double CKreis::get_radius() {
    return this->radius;
}

void CKreis::set_mittelpunkt(coordinates cords) {
    this->mittelPunkt = cords;
}

void CKreis::set_radius(double r) {
    if (r < 0) {
        printf("radius darf nicht - sein!\n");
        return;
    }
    this->radius = r;
}

char* CKreis::get_name() const {
    return this->cGrundForm.getTitle();
}

void CKreis::set_name(const char* name) {
    this->cGrundForm.setTitle(name);
}

double CKreis::get_flaeche() const {
    const double PI = 3.14159265359;
    return PI * this->radius * this->radius;
}

void CKreis::output() {
    printf("Der Kreis hat die Bezeichnung: %s\nDer Punkt lautet: (%.2f : %.2f)\nDer Radius lautet: %.2f\nDie Flaeche lautet: %.2f\n",
           this->cGrundForm.getTitle(),
           this->mittelPunkt.x,
           this->mittelPunkt.y,
           this->radius,
           this->get_flaeche());
}









