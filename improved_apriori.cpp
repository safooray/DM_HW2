#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <time.h>
#include <map>
#include <algorithm>
#include <unordered_set>

using namespace std;


typedef map <string, pair<int,vector<int> > > item_freq_map_st;
typedef map <int, pair<int,vector<int> > > item_freq_map;
typedef map <string ,int> candidate_freq_map;
  

int main(int argc, char* argv[])
{
	/***** start timer ****/
	clock_t s,e;
    s = clock();

    /**** get inputs ****/
	string input_filename = argv[1];
	string output_filename = argv[3];
	int min_st = atoi(argv[2]);


	ifstream in(input_filename);
    if (!in.is_open() ) 
    {
    	// handle error.
        cout << "input file not found!"<< endl;	
    }

    vector <int> tids;
    vector<vector<string> > trans;

    item_freq_map one_item_candidate;

    string tr;
    int tid = 0;
	while (std::getline(in, tr))
	{	
		cout<<"tid:"<<tid<<endl;
    	istringstream iss(tr);
    	string s;
    	vector<int> st;   
    	//cout<<"AREA:1"<<endl; 
    	while ( getline( iss,s, ' ' ) )
    	{
    	  int key = atoi(s.c_str());
    	  st.push_back(key);
    	  one_item_candidate[key].first ++;
    	  one_item_candidate[key].second.push_back(tid);
    	  //cout << "size:"<<one_item_candidate[s.c_str()].second.size()<<endl;
    	}
        sort(st.begin(), st.end());
        vector<string> sorted_trans;
        int k;
        for( k = 0; k < st.size(); k++)
        {
        	string temp = to_string(st[k]);
        	sorted_trans.push_back(temp);
        }
        tids.push_back(tid);
        trans.push_back(sorted_trans);
        tid ++;

    }

    ofstream output;
	output.open(output_filename);
	vector <int> one_item;
    /****** find one-item sets and write them into the output file ******/
    for (auto it = one_item_candidate.begin(); it != one_item_candidate.end(); )
    {
        if (it->second.first < min_st)
        {
                one_item_candidate.erase(it++);
        }
        else
        {
        	output << it->first << " ("<< it->second.first << ")\n";
        	one_item.push_back((it->first));
            ++it;
        }
    }

    sort(one_item.begin(), one_item.end());

    int low_item;
    int high_item;
    map <string,int> two_item_candidate;
    cout<<"size: "<<one_item.size()<<endl;
    vector<string> two_item;
    for(int i = 0; i < one_item.size(); i++){
		for(int j = i + 1; j < one_item.size(); j++){

			string candidate = to_string(one_item[i])+" "+to_string(one_item[j]);
			//two_item_candidate[candidate].first = 0;
			int temp_j = one_item[j];
			int temp_i = one_item[i];
			if(one_item_candidate[temp_i].first <= one_item_candidate[temp_j].first)
			{
				low_item = temp_i;
				high_item = temp_j;	

			}
			else
			{
				low_item = temp_j;
				high_item = temp_i;
			}
			//cout<<"low_item is: "<<low_item<<endl;
			//vector<int> item_tids = one_item_candidate[low_item].second;
			//cout<<"low_item is in "<<item_tids.size()<<"transactions"<<endl;

			/*unordered_set<int> s(one_item_candidate[low_item].second.begin(), one_item_candidate[low_item].second.end());
			int res = count_if(one_item_candidate[high_item].second.begin(), one_item_candidate[high_item].second.end(), [&](int k) {return s.find(k) != s.end();});
			two_item_candidate[candidate] = res;*/

			vector<int> intersect_of_two;
			set_intersection(one_item_candidate[high_item].second.begin(), one_item_candidate[high_item].second.end(), one_item_candidate[low_item].second.begin(), one_item_candidate[low_item].second.end(), back_inserter(intersect_of_two));
			two_item_candidate[candidate] =  intersect_of_two.size();

			/*vector<int> union_of_two = one_item_candidate[low_item].second;
			union_of_two.insert(union_of_two.end(), one_item_candidate[high_item].second.begin(), one_item_candidate[high_item].second.end());
			int size_union = union_of_two.size();
			sort(union_of_two.begin(), union_of_two.end());
            union_of_two.erase( unique( union_of_two.begin(), union_of_two.end() ), union_of_two.end() );
			two_item_candidate[candidate] = size_union - union_of_two.size();*/


			/*for(int l=0; l< item_tids.size();l++)
			{	
				string h_item = to_string(high_item);
				if(find(trans[tids[item_tids[l]]].begin(), trans[tids[item_tids[l]]].end(), h_item) != trans[tids[item_tids[l]]].end()) 
				{
					two_item_candidate[candidate] ++;
				}
			
				vector<string> transaction =  trans[tids[item_tids[l]]];
				for(int m=0; m<transaction.size();m++)
				{
					if(high_item>stoi(transaction[m])) break;
					else if(high_item==stoi(transaction[m])) {
						two_item_candidate[candidate] ++;
						break;
					}
				}

			}*/

			if(two_item_candidate[candidate]< min_st)
			{
				two_item_candidate.erase(candidate);
			}
			else
			{
				output<<candidate<<" ("<< two_item_candidate[candidate] << ")\n";
				two_item.push_back(candidate);
			}
		}
		cout<<"i: "<<i<<endl;
	}

	/********************************/
	string b = "217 546 661 923 947";
	vector <string> many_item = two_item;
	cout<<"size of 2_itemsets: "<<many_item.size()<<endl;
	int k_item = 3;
	while(k_item <=5)
	{
		map <string ,int> many_item_candidate;
        //cout<<"AREA 2: "<< many_item.size() <<endl;
        for(int i = 0; i < many_item.size(); ++i)
        {
            for(int j = i + 1; j < many_item.size(); ++j)
            {
                vector<int> st;
                int item_size = 0;

                /****** split string by space *****/
                string s1;
                istringstream iss(many_item[i]);
                //cout<<"many_item i= "<<i<<" is "<<many_item[i]<<endl;
                while ( getline( iss, s1, ' ' ) )
                {
                    st.push_back(atoi(s1.c_str()));
                    item_size ++;
                }
                //cout<<"many_item j= "<<j<<" is "<<many_item[j]<<endl;
                istringstream iss2(many_item[j]);
                string s2;
                while ( getline( iss2, s2, ' ' ) )
                {
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
                
                /*char* a = "217 546 661 923 947";
                string b = "217 546 661 923 947";
				if(!strcmp((candidate).c_str(),a))
				{
					cout<<"trans: " << candidate<<endl;
					cout<<"count: "<<many_item_candidate[b];
				}*/

                many_item_candidate[candidate]++;
            }

        }
        

        many_item.clear();
        cout<<"size of"<< k_item<<"_itemsets: "<<many_item_candidate.size()<<endl;
        //string b = "217 546 661 923 947";
        //cout<<"count: "<<many_item_candidate[b]<<endl;

        for(candidate_freq_map::iterator it = many_item_candidate.begin(); it != many_item_candidate.end();)
        {	
        	if(many_item_candidate.size()==10){
        		cout<<"freq: "<<it->second<<" trans: "<<it->first<<endl;
        	}

			int val = it->second;
			char* a = "217 546 661 923 947";
			if(!strcmp((it->first).c_str(),a))
			{
					cout<<"trans: " <<endl;
					cout<<"count: "<<val<<"k_item "<<k_item<<endl;;
			}
			if(val<k_item)
			{
				cout<<"Trans: "<<it->first<<endl;
				many_item_candidate.erase(it++);
			}
			else
			{
            //cout<<"candidate: "<<it->first<<endl;
            string s3;
            istringstream iss3(it->first);
            vector<int> items;
            int item;
            while ( getline( iss3, s3, ' ' ) )
            {
            	item = atoi(s3.c_str());
                items.push_back(item);
            }
                    
            vector<int> intersect_of_many;
            vector<int> set_ = one_item_candidate[items[0]].second;
            for(int l=1;l<items.size();l++)
            {
            	intersect_of_many.clear();
				set_intersection(set_.begin(), set_.end(), one_item_candidate[items[l]].second.begin(), one_item_candidate[items[l]].second.end(), back_inserter(intersect_of_many));
				set_ = intersect_of_many;
				
			}
			
			many_item_candidate[it->first] =  intersect_of_many.size();
			//cout<<"size of intersection: "<<intersect_of_many.size()<<endl;
			if(many_item_candidate[it->first]< min_st)
			{
				many_item_candidate.erase(it);
			}
			else
			{
				output<<it->first<<" ("<< many_item_candidate[it->first] << ")\n";
				many_item.push_back(it->first);
			}
                                
			++it;
			}

		}
		k_item ++;
		many_item_candidate.clear();	

	}

	



	e = clock();
  	float diff ((float)e-(float)s);
    cout << diff/1000000.00 << endl;


}