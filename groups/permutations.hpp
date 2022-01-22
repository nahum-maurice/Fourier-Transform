#ifndef _PERMUTATIONS
#define _PERMUTATIONS 

#include <vector>

class Permutations {
    // Permutations are possible arrangements of the elements
    // of a given set. The collection of all permutations 
    // form a symmetric group.
    private:
        int len;
    public:
        // constructors and destructors 
        Permutations(int n);
        Permutations(std::vector<int> &toPermute);
        // functions 
        int length();
        std::vector<std::vector<int>> elements(); 
};

#endif