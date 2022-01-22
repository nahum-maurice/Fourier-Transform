// Implementation of symmetric groups 

// Since the only class of groups considered is the class of 
// finite groups, we can just focus on implementing the algorithm
// for S_n since every finite group of order n is isomorphic to a 
// subgroup S_n by Cayley's theorem
#ifndef _SYMMETRICGROUPS
#define _SYMMETRICGROUPS

#include <string>
#include <vector>
#include "permutations.hpp"
#include "partitions.hpp"

class SymmetricGroup {
    // The symmetric group defined over any set is the group
    // whose elements are all bijections from the set to 
    // itself, and whose group operation is the composition
    // of function.
    // In particular, the finite symmetric group S_n defined
    // over a finite set of n symbols consists of the 
    // permutations that can be performed on the n elements.

    public :
        // constructors and destructors
        SymmetricGroup(); // trivial 
        SymmetricGroup(int n);
        ~SymmetricGroup();
        // functions
        int order(); // The number of permutations : n!
        int degree(); // n
        bool isAbelian(); // If degree <= 2
        bool isTrivial(); // n= 0 || 1
        bool isSolvable(); // n <= 4
        std::vector<int> representation(std::vector<int> &V, std::string type);
};

#endif