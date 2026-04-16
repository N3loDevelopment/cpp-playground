//
// Created by rosar on 16.04.2026.
//

#include <algorithm>
#include <iostream>
#include <vector>

#include "CKreis.h"
#include "CViereck.h"

int main() {
    auto k = new CKreis("Kreis 1");
    k->set_mittelpunkt({2, 2});
    k->set_radius(2.2);
    k->output();

    auto v = new CViereck("Viereck 1");
    std::vector<coordinates> punkte = {
        {1, 3222},
        {41, 1},
        {1, 82},
        {1, 822}
    };
    v->set_viereck_coordinates(punkte);
    v->output();

    return 0;
}
