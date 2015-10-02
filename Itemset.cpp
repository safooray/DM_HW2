
#include "Itemset.h"
Itemset::Itemset() {};
Itemset::~Itemset() {};
void Itemset::freq(istream& in, item_freq_map& words) 
{
    string s;

    while (in >> s) 
    {
    	cout<<in<<endl;
       ++words[s];
    }
}  





