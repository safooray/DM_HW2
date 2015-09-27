
#include "Itemset.h"

class Itemset {

};

typedef map <string, int> item_freq_map;

void Itemset::freq(istream& in, item_freq_map& words) {

    string s;

    while (in >> s) {
       ++words[s];
    }
}  





