/*
MIT License

Copyright (c) 2021 Nahum Maurice

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef FFT_RECURSIVE
#define FFT_RECURSIVE

#include<complex>
#include<vector>

using cd = std::complex<double>;
const double PI = 3.1415;

// Implementing the Fast Fourier Transform (FFT) and
// the inverse Fast Fourier Transform (inverse FFT)
// in one recursive function.

// The C++STL complex and vector are used.

void fft_recursive(std::vector<cd> & a, bool isInvert) {

    int n = a.size(); // Should equal to 2^k
    if (n == 1) 
        return;

    // These vectors will recursively contains half of the 
    // current vector.
    std::vector<cd> a0(n / 2), a1(n /2);
    for(int i = 0; 2 * i < n; i++) {
        /*
            The vector a is split into two sub vectors
            elements of whom are alternated

            if :
            a = [a_0, a_1, a_2, a_3, ...]
            then :
            a0 = [a_0, a_2, ...]
            a1 = [a_1, a_3, ...]

        */
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    };
    
    // Recursion
    fft_recursive(a0, isInvert);
    fft_recursive(a1, isInvert);
    
    // Perform the operations themselves...
    double angle = 2 * PI / n * (isInvert ? -1 : 1);
    cd w(1), wn(cos(angle), sin(angle));
    for (int i = 0; i < n / 2; i++){
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if(isInvert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        };
        w *= wn;
    };
}

#endif
