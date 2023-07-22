#ifndef MOVES_H
#define MOVES_H

#include "vectors.h"

namespace linear{
    class object {
        public:
        
        object(Vector::vector<double> pos);
        object(double mass);

        void setPos(Vector::vector<double>);
        void setv_med(double v);
        void setG(double g);
        Vector::vector<double> getPos();
        double getv_med();
        
        //position in function of time, user defines it.
        //argument is pointer to a function that accepts a double (time in this case)
        double pos_function(double (*pos_func)(double)); 

        private:
            Vector::vector<double> obj_pos;
            double v_med;
            double G; //gravitation constant
            double mass;
            double density;
            
    };
}

#endif