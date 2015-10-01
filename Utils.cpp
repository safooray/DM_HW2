/* 
 * File:   Utils.cpp
 * Author: Ayine
 * 
 * Created on September 30, 2015, 1:19 PM
 */

#include <map>

#include "Utils.h"

Utils::Utils() {
}

Utils::Utils(const Utils& orig) {
}

Utils::~Utils() {
}

vector<strset> Utils::subsets(int k, vector<string> trans, int tid)
{
    //printVecOfStrset(subSetStore[tid]);
    //if(subSetStore.find(tid) != subSetStore.end())
    //    return subSetStore[tid];
    vector<strset> cursubsets;
    vector<strset> presubsets;
    if (k == 0 || trans.empty() || trans.size() < k) { 
        return cursubsets; 
    }

    if (trans.size() == k) {
        vector<string> tmp;
        //if(subSetStore.find(tid) == subSetStore.end())
        //{
            for (int m = 0; m < trans.size(); m++)
            {
                tmp.push_back(trans.at(m));
            }
            cursubsets.push_back(tmp);
            subSetStore[tid] = cursubsets;
        //}
        //else
        return cursubsets;
    }
    if (k == 2)
    {
        for (int m = 0; m < trans.size(); m++)
        {
            vector<string> tmp;
            tmp.push_back(trans.at(m));
            presubsets.push_back(tmp);
        }
        subSetStore[tid] = presubsets;
    }
    
    presubsets = subSetStore[tid];
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
    subSetStore[tid] = cursubsets;
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