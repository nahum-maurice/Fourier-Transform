#include <vector>
#include "permutations.hpp"

Permutations::Permutations(int n) : len(n) {
    // create a n-dimensional vector : [1, 2, 3, ..., n]
    std::vector<int> toPermute = {n};
    for(int i=1; i<=len; i++) {
        toPermute[i] = i;
    };
    // apply the permutation algorithm
    // the complexity is O(n*n!) because of recursion.
    
}   

Permutations::Permutations(std::vector<int> &toPermute) : len(toPermute.size) {
    // apply the permutation algorithm.
}

int Permutations::length() {return len;};

std::vector<std::vector<int>> Permutations::elements() {
    // return the list of all the permutations.
}