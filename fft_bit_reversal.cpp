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

#include<complex>
#include<vector>

using cd = std::complex<double>;
const double PI = acos(-1);

// Implementing the Fast Fourier Transform (FFT) and
// the inverse Fast Fourier Transform (inverse FFT)
// in one function. Beforehand we proceed to the bit-
// reversal permutatation by swapping each element
// with the element of the reversed position. Thus,
// we compute the DFT for each block of the corresponding 
// size.

// The C++STL complex and vector are used.

int _reverse(int num, int lg_n) {
    int result = 0;
    for (int i = 0; i < lg_n; i++) {
        if ( num & (1 << i)) result |= 1 << (lg_n -1 -i);
    }
    return result;
}

void fft(std::vector<cd> & a, bool isInvert) {
    // In this implementation, we first iterated all bits of the index
    // and created a bitwise reversed index.

    int n = a.size();
    int lg_n = 0;
    while ((1 << lg_n) < n) lg_n++;

    for (int i = 0; i < n; i++) {
        if(i < _reverse(i, lg_n)) std::swap(a[i], a[_reverse(i, lg_n)]);
    }

    for (int len=2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (isInvert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for(int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (isInvert) for(cd & x : a) x /= n;
}

void fft_optimized(std::vector<cd> & a, bool isInvert) {
    // If j contains the reverse of i, we increment i and we also 
    // increment j, in a reversed number system. 
    // We flip all leading ones, and also the next zero
    int n = a.size();

    for (int i=1, j=0; i< n; i++) {
        int bit = n >> 1;
        for (; & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j) std::swap(a[i], a[j]);
    }

    for (int len=2; len <= n; len <<= 1) {
        double ang = 2 * PI /len * (isInvert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i=0; i<n; i += len) {
            cd w(1);
            for (int j=0; j < len / 2; j++){
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (isInvert) for(cd & x : a) x /= n;
}
