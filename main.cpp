#include <iostream>
#include <vector>

#include "Node.h"
#include "Trie.h"
#include "Itemset.h"
#include "Utils.h"


// Test program
int main(int argc, char *argv[])
{
    clock_t s,e;
    s = clock();
    /**** get inputs ****/
//    argv[1] = "T10I4D100K.dat";
//    argv[2] = "1";
//    argv[3] = "outss.txt";
    string input_filename = argv[1];
    string output_filename = argv[3];
    int min_st = atoi(argv[2]);


    /*** check if the input file exist***/
    ifstream input(input_filename);
    if ( !input.is_open() ) {
        // handle error.
        cout << "input file not found!"<< endl;	
    }

    /***** read input file and count one-item frequecies *****/
    item_freq_map one_item_candidate;
    Itemset is;
    is.freq(input, one_item_candidate);

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
    vector <int> one_item;
    /****** write one-item sets into the output file ****/
    for (item_freq_map::iterator it = one_item_candidate.begin(); it != one_item_candidate.end(); ++it) {
        output << it->first << " ("<< it->second << ")\n";
        one_item.push_back(stoi(it->first));
    }

    sort(one_item.begin(), one_item.end());

    Trie trie;
    map <string ,int> two_item_candidate;
    for(int i = 0; i < one_item.size(); i++){
        for(int j = i + 1; j < one_item.size(); j++){

            string candidate = to_string(one_item[i])+" "+to_string(one_item[j]);
            trie.addWord(candidate);
            two_item_candidate[candidate] = 0;
        }
    }
    ifstream in(input_filename);
    if (!in.is_open() ) {
    // handle error.
        cout << "input file not found!"<< endl;	
    }
    Utils utils;
    string trans;
    int tid = 0;
    while (std::getline(in, trans))
	{
    	istringstream iss(trans);
    	string s;
    	vector<int> st;    
        //cout << "tid = " << tid<< endl;
    	while ( getline( iss,s, ' ' ) ) 
    	{
            st.push_back(atoi(s.c_str()));
            }
            sort(st.begin(), st.end());
            vector<string> sorted_trans;
            int k;
            for( k = 0; k < st.size(); k++){
            string temp = to_string(st[k]);
            sorted_trans.push_back(temp);
            }
            vector<strset> cursubsets = utils.subsets(2, sorted_trans, tid);
            tid++;
            //utils.printVecOfStrset(cursubsets);
            for(int sub = 0; sub < cursubsets.size(); sub ++)
            {
                string subsetStr = "";
                for (int submem = 0; submem < cursubsets.at(sub).size(); submem++)
                {
                    subsetStr = subsetStr + cursubsets.at(sub).at(submem).c_str() + " ";
                }
                subsetStr = subsetStr.substr(0, subsetStr.length() - 1);
                int support = trie.searchWord(subsetStr);
                two_item_candidate[subsetStr] = support;             
                //cout << "support = " << support << endl;
            }
	}		
    in.close();
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
            //cout << it->first << " ("<< it->second << ")\n";
            output << it->first << " ("<< it->second << ")\n";
            two_item.push_back(it->first);
    }

    vector <string> many_item = two_item;
    //cout<<"two_item: "<<two_item.size()<<endl;
    //cout<<"many:"<<many_item.size()<<endl;
    

    int count = 0;
    int k_item = 3;
    
    while(k_item<=5){
       // vector <string> prev_item = many_item;
        map <string ,int> many_item_candidate;
        //cout<<"AREA 2: "<< many_item.size() <<endl;
        for(int i = 0; i < many_item.size(); ++i){
            for(int j = i + 1; j < many_item.size(); ++j){
                vector<int> st;
                int item_size = 0;

                /****** split string by space *****/
                string s1;
                istringstream iss(many_item[i]);
                while ( getline( iss, s1, ' ' ) ) {
                    st.push_back(atoi(s1.c_str()));
                    item_size ++;
                }

                istringstream iss2(many_item[j]);
                string s2;
                while ( getline( iss2, s2, ' ' ) ) {
                        st.push_back(atoi(s2.c_str()));
                        }
                sort(st.begin(), st.end());
                st.erase( unique( st.begin(), st.end() ), st.end() );
                if(st.size()> item_size+1) continue;
                string candidate;
                /*** concatinate string *****/
                int k = 0;
                for(k = 0; k != st.size()-1; ++k){
                    string temp = to_string(st[k]) + " " ;
                    candidate = candidate + temp;
                }

                candidate = candidate + to_string(st[k]);  
                
                many_item_candidate[candidate]++;

            }
            //cout << "i: "<< i<< endl;
        }
        Trie trie2;
        for(auto it = many_item_candidate.begin(); it != many_item_candidate.end();){
				int val = it->second;
				if(val<k_item){
					many_item_candidate.erase(it++);
				}
				else{
                                    trie2.addWord(it->first);
                                    //cout<<"candidate: "<<it->first<<"e"<<endl;
					++it;
				}

			}
        

            //count_frequency(many_item_candidate)
        ifstream in(input_filename);
        if (!in.is_open() ) {
        // handle error.
        cout << "input file not found!"<< endl;	
        }
    //Utils utils;
    string trans;
    int tid = 0;
    while (std::getline(in, trans))
	{
    	istringstream iss(trans);
    	string s;
    	vector<int> st;    
        //cout << "tid = " << tid<< endl;
        
    	while ( getline( iss,s, ' ' ) ) 
    	{
            st.push_back(atoi(s.c_str()));
            }
            sort(st.begin(), st.end());
            vector<string> sorted_trans;
            int k;
            for( k = 0; k < st.size(); k++){
            string temp = to_string(st[k]);
            sorted_trans.push_back(temp);
            }
            //cout << "vec: ";
            //for(int m = 0; m < sorted_trans.size(); m ++)
        	//cout << sorted_trans.at(m) << " ";
            //cout << endl;
            vector<strset> cursubsets = utils.subsets(k_item, sorted_trans, tid);
            tid++;
            //utils.printVecOfStrset(cursubsets);
            for(int sub = 0; sub < cursubsets.size(); sub ++)
            {
                string subsetStr = "";
                for (int submem = 0; submem < cursubsets.at(sub).size(); submem++)
                {
                    subsetStr = subsetStr + cursubsets.at(sub).at(submem).c_str() + " ";
                }
                subsetStr = subsetStr.substr(0, subsetStr.length() - 1);
                //cout << "afterSubStr = " << subsetStr << "e" << endl;
                int support = trie2.searchWord(subsetStr);
                many_item_candidate[subsetStr] = support;             
                //cout << "support = " << support << endl;
                //cout<< "support: " << many_item_candidate[subsetStr] << endl;
//                cout<< "CANDIDATE: " << many_item_candidate["39 120 205"] << endl;
            }
	}		
    in.close();
        
            /*** check which many-item-candidate are frequent ****/
        for (auto it = many_item_candidate.begin(); it != many_item_candidate.end(); ){
            if (it->second < min_st){
                many_item_candidate.erase(it++);
            }
            else{
                ++it;
            }
        }

        //vector <string> many_item;
        many_item.clear();
        /****** write many-item sets into the output file ****/
        for (item_freq_map::iterator it = many_item_candidate.begin(); it != many_item_candidate.end(); ++it) {
            //cout << "$%^" <<it->first << " ("<< it->second << ")\n";
            output << it->first << " ("<< it->second << ")\n";
            many_item.push_back(it->first);
        }
        //cout<<"size_many_2: "<<many_item.size()<<endl;

        count ++;
        k_item ++;
    }




    output.close();
    cout << "Done!\n";



    //set <int> items;
    //vector <vector<int> > transactions;
    //string line;
    /***** another way to read input file and save it as 2D vector ****/
    //while(getline(input, line)){
    //stringstream ss(line);
    //istream_iterator<int> begin(ss), end;
    //transactions.push_back(vector<int>(begin, end));
    //items.insert(transactions.end())
    //}

    //cout << two_item[0]<<endl;

    /**** stop timer *****/
    e = clock();
    float diff ((float)e-(float)s);
    cout << diff << endl;
    return 0;
}
