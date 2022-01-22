#ifndef _PARTITIONS
#define _PARTITIONS

#include <set>
#include <vector>

using std::set;
using std::vector;

class Partitions {
    // An integer partition of a natural number n is a set 
    // { p_1, ..., p_n} where p_i is an element of N, 
    // p_1 >= ... >= p_n, and p_1 + ... + p_n = n

    public:
        int n; // the integer
        vector<int> partition; // an n-vector that will keep the
        set<vector<int>> partitions; // contains all the partitions

    // constructors and destructor
    Partitions(int n);
    // two functions are really needed
    // length() : the returns the number of partitions
    // list() : that returns the partitions
    int length();
    set<vector<int>> list();
};

#endif