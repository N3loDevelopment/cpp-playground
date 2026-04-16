//
// Created by rosar on 16.04.2026.
//

#include "CGrundForm.h"

char *CGrundForm::getTitle() const {
       return const_cast<char*>(this->title);
}

void CGrundForm::setTitle(const char * t) {
       this->title = t;
}
