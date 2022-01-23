#include<iostream>
#include<vector>
#include<complex>

#include "fft_recursive.cpp"
#include "fft_bit_reversal.cpp"
#include "fft_number_theoretic.cpp"

using cd = std::complex<double>;

int main (){

    // // RECURSIVE FFT

    std::vector<cd> vect_1;
    for (int i = 0; i < 8; i++){
        vect_1.push_back(i);
    };

    std::cout << "\n";
    std::cout << "FAST FOURIER TRANSFORM (RECURSIVE APPROACH)";
    std::cout << "\n\n";

    // Printing the original
    std::cout << "The source vector\n";
    for (int i = 0; i < vect_1.size(); i++) {
        std::cout << vect_1[i];
    };
    fft_recursive(vect_1, false);

    // Printing the transformed
    std::cout << "\n\n";
    std::cout << "The transformed vector\n";
    for (int i = 0; i < vect_1.size(); i++) {
        std::cout << vect_1[i];
    };

    fft_recursive(vect_1, true);

    // Printing the reverse transformed
    std::cout << "\n\n";
    std::cout << "The inverse transformed vector\n";
    for (int i = 0; i < vect_1.size(); i++) {
        std::cout << vect_1[i] << " ";
    };

    // ITERATIVE FFT

    std::vector<cd> vect_2;
    for (int i = 0; i < 8; i++){
        vect_2.push_back(i);
    };

    std::cout << "\n\n";
    std::cout << "FAST FOURIER TRANSFORM (ITERATIVE APPROACH)";
    std::cout << "\n\n";

    // Printing the original vector
    std::cout << "The source vector\n";
    for (int i = 0; i < vect_2.size(); i++) {
        std::cout << vect_2[i];
    };
    
    fft_br_optimized(vect_2, false);

    // Printing the transformed
    std::cout << "\n\n";
    std::cout << "The transformed vector\n";
    for (int i = 0; i < vect_2.size(); i++) {
        std::cout << vect_2[i];
    };

    fft_br_optimized(vect_2, true);

    // Printing the reverse transformed
    std::cout << "\n\n";
    std::cout << "The inverse transformed vector\n";
    for (int i = 0; i < vect_2.size(); i++) {
        std::cout << vect_2[i] << " ";
    };

    // NTT

    std::vector<int> vect_3;
    for (int i = 0; i < 8; i++) {
        vect_3.push_back(i);
    };
    std::cout << "\n\n";
    std::cout << "NUMBER THEORETIC TRANSFORM";
    std::cout << "\n\n";

    std::cout << "The source vector\n";
    for (int i = 0; i < vect_3.size(); i++) {
        std::cout << vect_3[i] << " ";
    };
    fft_nt(vect_3, false);

    // Printing the transformed
    std::cout << "\n\n";
    std::cout << "The transformed vector\n";
    for (int i = 0; i < vect_3.size(); i++) {
        std::cout << vect_3[i] << " ";
    };

    fft_nt(vect_3, true);

    // Printing the reverse transformed
    std::cout << "\n\n";
    std::cout << "The inverse transformed vector\n";
    for (int i = 0; i < vect_3.size(); i++) {
        std::cout << vect_3[i] << " ";
    };

}

