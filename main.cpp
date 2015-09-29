#include <iostream>
#include <vector>

#include "Node.h"
#include "Trie.h"
#include "Itemset.h"


// Test program
int main(int argc, char *argv[])
{
    Trie trie;// = new Trie();
    
    clock_t s,e;
    s = clock();
    Itemset* is = new Itemset();
    /**** get inputs ****/
    argv[0] = "T10I4D100K.dat";
    argv[1] = "5";
    argv[2] = "out.dat";
    string input_filename = argv[0];
    string output_filename = argv[2];
    int min_st = atoi(argv[1]);


    /*** check if the input file exist***/
    ifstream input(input_filename);
    if ( !input.is_open() ) {
// handle error.
            cout << "input file not found!"<< endl;	
    }

    /***** read input file and count one-item frequecies *****/
    item_freq_map one_item_candidate;

    is->freq(input, one_item_candidate, trie);

    
    
    //trie.print(trie.getRoot());
    int tst = trie.searchWord("775");
    /****** find one-item sets ******/
	for (auto it = one_item_candidate.begin(); it != one_item_candidate.end(); ){
		if (it->second < min_st){
			one_item_candidate.erase(it++);
		}
		else{
			++it;
		}
	}


	ofstream output;
	output.open(output_filename);
	vector <string> one_item;
	/****** write one-item sets into the output file ****/
	for (item_freq_map::iterator it = one_item_candidate.begin(); it != one_item_candidate.end(); ++it) {
		output << it->first << " ("<< it->second << ")\n";
		one_item.push_back(it->first);
    }

    sort(one_item.begin(), one_item.end());


    map <string ,int> two_item_candidate;
    for(int i = 0; i < one_item.size(); i++){
		for(int j = i + 1; j < one_item.size(); j++){

			string candidate = one_item[i]+" "+one_item[j];
			two_item_candidate[candidate] = 0;
		}
	}

	//count_frequency(two_item_candidate)

	/*** check which two-item-candidate are frequent ****/
	for (auto it = two_item_candidate.begin(); it != two_item_candidate.end(); ){
		if (it->second < min_st){
			two_item_candidate.erase(it++);
		}
		else{
			++it;
		}
	}

	/*** get item names ***/
	vector <string> two_item;

	/****** write two-item sets into the output file ****/
	for (item_freq_map::iterator it = two_item_candidate.begin(); it != two_item_candidate.end(); ++it) {
		output << it->first << " ("<< it->second << ")\n";
		two_item.push_back(it->first);
    }

    vector <string> many_item = two_item;

    int count = 0;
	while(count <=0){

		vector <string> prev_item = many_item;
		map <string ,int> many_item_candidate;
		cout<<"AREAR 1"<<endl;
    	for(int i = 0; i < prev_item.size(); ++i){
			for(int j = i + 1; j < prev_item.size(); ++j){
				vector<string> st;
				int item_size = 0;

				/****** split string by space *****/
				string s1;
				istringstream iss(prev_item[i]);
				while ( getline( iss, s1, ' ' ) ) {
     				st.push_back(s1.c_str());
     				item_size ++;
  				}

    			istringstream iss2(prev_item[j]);
    			string s2;
    			while ( getline( iss2, s2, ' ' ) ) {
     				st.push_back(s2.c_str());
  				}

    			st.erase( unique( st.begin(), st.end() ), st.end() );
    			if(st.size()> item_size+1) continue;
    			sort(st.begin(), st.end());
    			string candidate;
    			/*** concatinate string *****/
    			int k = 0;
    			for(k = 0; k != st.size()-1; ++k){
    				string temp = st[k] + " " ;
    				candidate = candidate + temp;
    			}

    			candidate = candidate + st[k];  
				many_item_candidate[candidate] = 0;

			}
			cout << "i: "<< i<< endl;
		}

		//count_frequency(two_item_candidate)
		/*** check which many-item-candidate are frequent ****/
		for (auto it = many_item_candidate.begin(); it != many_item_candidate.end(); ){
			if (it->second < min_st){
				many_item_candidate.erase(it++);
			}
			else{
				++it;
			}
		}
		
		vector <string> many_item;
		/****** write many-item sets into the output file ****/
		for (item_freq_map::iterator it = many_item_candidate.begin(); it != many_item_candidate.end(); ++it) {
			output << it->first << " ("<< it->second << ")\n";
			many_item.push_back(it->first);
    	}

    	count ++;
	}
	

			

    output.close();
	cout << "Done!\n";

  	

	//set <int> items;
  	vector <vector<int> > transactions;
  	string line;
  	/***** another way to read input file and save it as 2D vector ****/
  	//while(getline(input, line)){
    	//stringstream ss(line);
    	//istream_iterator<int> begin(ss), end;
    	//transactions.push_back(vector<int>(begin, end));
    	//items.insert(transactions.end())
	//}
	
  	cout << two_item[0]<<endl;

  	/**** stop timer *****/
  	e = clock();
  	float diff ((float)e-(float)s);
    cout << diff << endl;
  	return 0;
}