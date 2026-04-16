//
// Created by rosar on 16.04.2026.
//

#ifndef CPP_PLAYGROUND_MAIN_CPUNKT_H
#define CPP_PLAYGROUND_MAIN_CPUNKT_H


class CPunkt {
private:
    double x;
    double y;

public:
    CPunkt();
    CPunkt(double x, double y);

    double get_x() const;
    double get_y() const;

    void set_x(double x);
    void set_y(double y);
    void set_koordinaten(double x, double y);

    void output() const;
    double distance_to(const CPunkt& other) const;
};


#endif //CPP_PLAYGROUND_MAIN_CPUNKT_H
