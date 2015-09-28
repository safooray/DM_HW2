
#include "Itemset.h"

class Itemset {

};

void Itemset::freq(istream& in, item_freq_map& words) {

    string s;

    while (in >> s) {
       ++words[s];
    }
}  





