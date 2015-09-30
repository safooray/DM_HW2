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

vector<strset> Utils::subsets(int k, vector<string> trans)
{
    vector<strset> cursubsets;
    vector<strset> presubsets;
    if (k == 0 || trans.empty() || trans.size() < k) { 
        return cursubsets; 
    }

    if (trans.size() == k || k == 1) {
        
        for (int m = 0; m < trans.size(); m++)
        {
            vector<string> tmp;
            tmp.push_back(trans.at(m));
            cursubsets.push_back(tmp);
        }
        return cursubsets; 
    }
    presubsets = (vector<strset>) subsets(k - 1, trans);
    int mycount = 0;
    for (int i = 0; i < presubsets.size(); i++ )
    {
//        cout << " pre subset: ";
//        for (int m = 0; m < presubsets.at(i).size(); m ++)
//        {
//            cout << presubsets.at(i).at(m) << " ";
//        }
//        cout << endl;
        for(int j = 0; j < trans.size(); j++)
        {
          //  cout << k << endl;
            if (atoi(trans.at(j).c_str()) > atoi(presubsets.at(i).at(k - 2).c_str()))
            {
                cursubsets.insert(cursubsets.begin() + mycount, presubsets.at(i));
                cursubsets.at(mycount).push_back(trans.at(j));
            }
        }
    }
    return cursubsets;
}

void Utils::printVecOfStrset(vector<strset> cursubsets)
{
    int mycount = 0;
    while (mycount < cursubsets.size())
    {
        cout << cursubsets.at(mycount).size()<< ": "; 
        for (int m = 0; m < cursubsets.at(mycount).size(); m ++)
        {
            cout << cursubsets.at(mycount).at(m) << " ";
        }
        cout << endl;
        mycount ++;
    }
}
int Utils::Factorial(int n)
{
  int result = 1;
  while (n > 1) {
    result *= n--;
  }
  return result;
}