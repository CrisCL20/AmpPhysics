#ifndef STATISTICS_H
#define STATISTICS_H

namespace dist {
    class bern {

    };
    
    class normal {
        public:
            normal(double mu, double sigma);
            ~normal();

            double std(double z);
        private:
            double mu, sigma;
            double (*pdf)(double);
            double (*cdf)(double);

    };

    class uni {

    };

    class gamma {

    };

    class beta {

    };

    class z {

    };

}


#endif