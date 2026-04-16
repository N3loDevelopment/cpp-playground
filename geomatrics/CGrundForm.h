//
// Created by rosar on 16.04.2026.
//

#ifndef CPP_PLAYGROUND_MAIN_CGRUNDFORM_H
#define CPP_PLAYGROUND_MAIN_CGRUNDFORM_H


class CGrundForm {
protected:
    const char* title;
public:
    CGrundForm() : title(nullptr) {};

    CGrundForm(const char* name) : title(name) {};

    ~CGrundForm() {};

    char* getTitle() const;
    void setTitle(const char*);
};


#endif //CPP_PLAYGROUND_MAIN_CGRUNDFORM_H