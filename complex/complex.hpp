//   Implementation of complex numbers.

#ifndef COMPLEX_H
#define COMPLEX_H

class complex {
    private:
        double re;
        double im;
    public:
        // i | i^2 = -1 
        static const complex i;
        // Constructors and destructors
        complex() : re(0.), im(0.) {}; 
        complex(double re, double im) : re(re), im(im) {};
        complex(double real) : re(real), im(0.) {};
        complex(complex &oldNum) : re(oldNum.re), im(oldNum.im){};
        ~complex(){ re = 0; im = 0;};

        // Member functions
        complex operator+=(complex &toAddNumber);
        complex operator-=(complex &toSubstractNumber);
        complex operator*=(complex &toMultiplyNumber);
        complex operator/=(complex &toDivideNumber);

        // Non-member functions
        complex operator+(const complex &toAddNumber);
        complex operator-(const complex &toSubstractNumber);
        complex operator*(const complex &toMultiplyNumber);
        complex operator/(const complex &toDivideNumber);
        complex operator==(const complex &toCompareNumber);
        complex operator<<(const complex &toSerialize);
        complex operator>>(const complex &toDeserialize);
        // Getters and Setters
        complex get();
        void set();
        double real();
        double imag();
        double abs(); // return the magnitude
        double norm(); 
        double conj(); 
        complex proj(); // the projection onto the Riemann sphere
        complex polar(); 
        complex nroot(double n);
        complex npower(double n);
        complex exp(); // returns the complex base e exponential
        complex log(); // complex natural log with the branch cuts along the negative real axis
        complex log10(); // complex common logarithm with the branch cuts along the negative real axis

        // Trigonometric and hyperbolic functions
        // sin, cos, tan, asin, acos, sinh, cosh...
};
 
#endif /* COMPLEX_H */