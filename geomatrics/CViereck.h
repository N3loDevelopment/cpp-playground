//
// Created by rosar on 16.04.2026.
//

#ifndef CPP_PLAYGROUND_MAIN_CVIERECK_H
#define CPP_PLAYGROUND_MAIN_CVIERECK_H
#include "CGrundForm.h"
#include <vector>

#include "coordinates.h"

class CViereck{
private:
     CGrundForm cGrundForm;
     std::vector<coordinates> viereck_coordinates;
     bool is_valid_viereck(const std::vector<coordinates>& cords) const;
public:
     CViereck(const char* name) : cGrundForm(name) {};

     std::vector<coordinates> get_viereck_coordinates();
     char* get_name() const;
     double get_flaeche() const;

     void set_viereck_coordinates(std::vector<coordinates> cords);
     void set_name(const char* name);

     void output();
};


#endif //CPP_PLAYGROUND_MAIN_CVIERECK_H