/* 
 * File:   Utils.cpp
 * Author: Ayine
 * 
 * Created on September 30, 2015, 1:19 PM
 */

#include "Utils.h"

Utils::Utils() {
}

Utils::Utils(const Utils& orig) {
}

Utils::~Utils() {
}

void Utils::subsets(int k, vector<string> s)
{
    if (k == 0 || s.empty() || s.size() < k) { 
        return;// { { } }; 
    }

    if (s.size() == k) { 
        return;// { s }; 
    }

    vector<string> result;
    int n = s.size();
    int skip = Factorial(n - k);
    
    cout << "These are the Possible Permutations: " << endl;

    do
    {
        for (int i = 0; i < k; i++)
        {
            std::cout << s.at(i).c_str() << " ";
        }
        cout << endl;
        for (int i = 1; i <= skip; ++i)
        {
            std::next_permutation(s.begin(),s.end());
        }
    } while (std::next_permutation(s.begin(),s.end()));
    
    //return result;
}

int Utils::Factorial(int n)
{
  int result = 1;
  while (n > 1) {
    result *= n--;
  }
  return result;
}