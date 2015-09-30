
#include "Itemset.h"
Itemset::Itemset() {};
Itemset::~Itemset() {};
void Itemset::freq(istream& in, item_freq_map& words, Trie& trie) 
{
    string s;

    while (in >> s) 
    {
       ++words[s];
    }
}  





