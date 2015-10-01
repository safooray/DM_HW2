/* 
 * File:   Utils.h
 * Author: Ayine
 *
 * Created on September 30, 2015, 1:19 PM
 */

#ifndef UTILS_H
#define	UTILS_H
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Trie.h"
using namespace std;
typedef vector<string> strset;
typedef vector<strset> strsets;
class Utils {
public:
    Utils();
    Utils(const Utils& orig);
    virtual ~Utils();
    vector<strset> subsets(int k, vector <string> s, int);
    int Factorial(int n);
    void printVecOfStrset(vector<strset>);
    map<int, strsets> subSetStore;
private:

};

#endif	/* UTILS_H */

