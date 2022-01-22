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

#include<vector>

const int mod = 7340033;
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1 << 20; 

void fft(std::vector<int> & a, bool isInvert) {
    int n = a.size();

    for (int i=1, j=0; i<n; i++){
        int bit = n >> 1;
        for (; j&bit; bit>>=1) 
            j ^= bit;
        j^= bit;

        if (i<j) std::swap(a[i], a[j]);
    }

    for (int len=2; len <= n; len <<= 1) {
        int wlen = isInvert ? root_1 : root;
        for (int i = len; i< root_pw; i << 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i=0; i<n; i+=len) {
            int w=1;
            for(int j=0; j<len/2; j++){
                int u=a[i+j], v=(int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (isInvert) {
        int n_1 = _inverse(n, mod);
        for (int & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }

}

int _inverse(int n, int mod){
    int x, y;
    int g = extended_euclid(n, mod, x, y);
    if(g!=1) return -1;
}

int extended_euclid(int n, int mod, int & x, int & y){
    if(mod == 0) {
        x = 1; y=0;
        return n;
    };
    int x1, y1;
    int d = extended_euclid(mod, n % mod, x1, y1);
    x = y1;
    y = x1 = y1 * (n / mod);
    return d;
}