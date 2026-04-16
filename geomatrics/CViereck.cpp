//
// Created by rosar on 16.04.2026.
//

#include "CViereck.h"
#include <cstdio>
#include <cmath>

bool are_collinear(const coordinates& p1, const coordinates& p2, const coordinates& p3) {
    double cross = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x); // kreuzprodukt
    return std::fabs(cross) < 0.01;
}

bool CViereck::is_valid_viereck(const std::vector<coordinates>& cords) const {
    if (cords.size() != 4) {
        printf("viereck muss 4 ecken haben %zu\n", cords.size());
        return false;
    }
    
    for (size_t i = 0; i < 4; i++) {
        size_t next1 = (i + 1) % 4;
        size_t next2 = (i + 2) % 4;
        if (are_collinear(cords[i], cords[next1], cords[next2])) {
            printf("ist kein viereck\n", i, next1, next2);
            return false;
        }
    }
    
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = i + 1; j < 4; j++) {
            if (std::fabs(cords[i].x - cords[j].x) < 0.01 && 
                std::fabs(cords[i].y - cords[j].y) < 0.01) {
                printf("ist kein viereck!\n", i, j);
                return false;
            }
        }
    }
    
    double flaeche = 0.0;
    for (size_t i = 0; i < 4; i++) {
        size_t next = (i + 1) % 4;
        flaeche += cords[i].x * cords[next].y;
        flaeche -= cords[next].x * cords[i].y;
    }
    flaeche = flaeche < 0 ? -flaeche / 2.0 : flaeche / 2.0;
    
    if (flaeche < 0.1) {
        printf("fläche zu klein, kein viereck\n");
        return false;
    }
    
    return true;
}

void CViereck::set_viereck_coordinates(std::vector<coordinates> cords) {
    if (!is_valid_viereck(cords)) {
        printf("fehler, kein gültiger viereck!\n");
        return;
    }
    this->viereck_coordinates = std::move(cords);
}

std::vector<coordinates> CViereck::get_viereck_coordinates() {
    return this->viereck_coordinates;
}

char* CViereck::get_name() const {
    return this->cGrundForm.getTitle();
}

void CViereck::set_name(const char* name) {
    this->cGrundForm.setTitle(name);
}

double CViereck::get_flaeche() const {
    if (this->viereck_coordinates.size() < 3) {
        return 0.0;
    }
    double flaeche = 0.0;
    for (size_t i = 0; i < this->viereck_coordinates.size(); i++) {
        size_t next = (i + 1) % this->viereck_coordinates.size();
        flaeche += this->viereck_coordinates[i].x * this->viereck_coordinates[next].y;
        flaeche -= this->viereck_coordinates[next].x * this->viereck_coordinates[i].y;
    }
    return flaeche < 0 ? -flaeche / 2.0 : flaeche / 2.0;
}

void CViereck::output() {
    printf("Das Viereck hat die Bezeichnung: %s\nDie Punkte lauten:\n", this->cGrundForm.getTitle());
    for (const auto& p : this->viereck_coordinates) {
        printf("{ %.0f %.0f }\n", p.x, p.y);
    }
    printf("Die Flaeche lautet: %.2f\n", this->get_flaeche());
}
