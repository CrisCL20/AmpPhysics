
#ifndef MOVES_H
#define MOVES_H

#include "vectors.h"

namespace linear{
    class object {
        public:
        
        object(Vector::vector<double> pos) : obj_pos(pos) {}
        object(double mass) : mass(mass) {}

        void setPos(Vector::vector<double> pos);
        void setv_med(double v);
        void setG(double g);
        Vector::vector<double> getPos();
        double getv_med();
        

        /**
         * @brief sets position in function of time, user defines it.
         * 
         * 
         * @param pointer to a function that accepts a double 
         * @return the function itself.
         * 
         * Use case:
         *      double pos_func(double t) {
         *          return v*t;
         *      }
         * 
         *      object.setPos_function(pos_func);
         */
        void setPos_function(double (*pos_func)(double)); 

        private:
            Vector::vector<double> obj_pos;
            double v_med;
            double G; //gravitation constant
            double mass;
            double density;
            double (*pos_function)(double); //position in function of time
            
    };
}

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


#endif