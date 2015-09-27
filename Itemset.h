/* 
 * File:   Itemset.h
 * Author: Ayine
 *
 * Created on September 27, 2015, 1:05 AM
 */

#ifndef ITEMSET_H
#define	ITEMSET_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <time.h>
#include <map>
#include <algorithm>

using namespace std;

typedef map <string, int> item_freq_map;

class Itemset {
public:
    Itemset();
    Itemset(const Itemset& orig);
    virtual ~Itemset();
    freq(istream& in, item_freq_map& words);
private:

};

#endif	/* ITEMSET_H */

