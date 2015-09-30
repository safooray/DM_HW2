#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <time.h>
#include <map>
#include <algorithm>

using namespace std;


int main23(int argc, char* argv[])
{
    //string input_filename = argv[1];
    argv[0] = "T10I4D100K.dat";
    string input_filename = argv[0];
	/*** check if the input file exist***/
	ifstream input(input_filename);
  	if ( !input.is_open() ) {
    // handle error.
  		cout << "input file not found!"<< endl;	
	}


	string trans;
	
	while (std::getline(input, trans))
	{
    	istringstream iss(trans);
    	string s;
    	vector<int> st;
    	while ( getline( iss,s, ' ' ) ) 
    	{
     		st.push_back(atoi(s.c_str()));
  		}
  		sort(st.begin(), st.end());
  		string sorted_trans;
  		int k;
  		for( k = 0; k < st.size()-1; ++k){
    		string temp = to_string(st[k]) + " " ;
    		sorted_trans = sorted_trans + temp;
    	}
    	sorted_trans = sorted_trans + to_string(st[k]);
        
    	//cout << sorted_trans << endl;
	}	
}
