#include "moves.h"

linear::object::object(Vector::vector<double> pos) : obj_pos(pos) {}

linear::object::object(double mass_) : mass(mass_) {}

void linear::object::setPos(Vector::vector<double> pos) {
    obj_pos = pos;
}

void linear::object::setv_med(double v) {
    v_med = v;
}

void linear::object::setG(double g) {
    G = g;
}

void linear::object::setPos_function(double (*pos_func)(double)) {
    pos_function = pos_func;
}

Vector::vector<double> linear::object::getPos() {
    return obj_pos;
}
