/* 
 * File:   Utils.h
 * Author: Ayine
 *
 * Created on September 30, 2015, 1:19 PM
 */

#ifndef UTILS_H
#define	UTILS_H
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include "Trie.h"
using namespace std;
typedef vector<string> strset;
class Utils {
public:
    Utils();
    Utils(const Utils& orig);
    virtual ~Utils();
    static vector<strset> subsets(int k, vector <string> s);
    int static Factorial(int n);
    void printVecOfStrset(vector<strset>);
private:

};

#endif	/* UTILS_H */

