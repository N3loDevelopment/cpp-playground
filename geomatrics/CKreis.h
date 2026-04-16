//
// Created by rosar on 16.04.2026.
//

#ifndef CPP_PLAYGROUND_MAIN_CKREIS_H
#define CPP_PLAYGROUND_MAIN_CKREIS_H
#include "CGrundForm.h"
#include "coordinates.h"

class CKreis {
private:
    CGrundForm cGrundForm;
    coordinates mittelPunkt;
    double radius;
public:
    CKreis(const char* name) : cGrundForm(name), mittelPunkt({0.0, 0.0}), radius(0.0) {};

    coordinates get_mittelpunkt();
    double get_radius();
    char* get_name() const;
    double get_flaeche() const;

    void set_mittelpunkt(coordinates);
    void set_radius(double);
    void set_name(const char* name);

    void output();
};


#endif //CPP_PLAYGROUND_MAIN_CKREIS_H