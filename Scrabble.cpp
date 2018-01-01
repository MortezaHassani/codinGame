
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <set>
using namespace std;
//calculating the point for each letter-------------------------------
int points(map<char,int>&point, string& s)
{
	set<char> setlet;
	set<char>::iterator it_setlet;
	int sum=0;
	map<char,int>::iterator it_calc;
	for (int i=0 ; i<s.size(); i++) {
		setlet.insert(s[i]);
			}
	for (it_setlet =setlet.begin() ;it_setlet!=setlet.end() ;it_setlet++) {
		it_calc=point.find(*it_setlet);
		sum=sum+(it_calc->second);
	}
	return sum;
}
int main()
{
//giving point to alphabet--------------------------------------------------
	map<char,int> let_points;
//	map<char,int>::iterator it_point;
	string alp;
	alp="eaionrtlsudgbcmpfhvwykjxqz";

	int point[]={1,1,1,1,1,1,1,1,1,1,
				2,2,
				3,3,3,3,
				4,4,4,4,4,
				5,
				8,8,
				10,10};
for(int i=0; i<26; i++){
	let_points[alp[i]]=point[i];
}
//-----------------------------------------------------------------------
    map<pair<int , int>, set<char> > graph ;
    map<pair<int , int>, set<char> >::iterator it ;
    map<int , string> dict;
    map<int , string>::iterator it_dict;
    set<char> sug;
    set<char>::iterator it2;
    string letter;
    int index;
    int letterscore,N;
    char s;
    cin>>N;cin.ignore();
    //2 maps :1-map of letter(char) and score and index,2-letter and index---------
      for (int k=0 ; k <N ; k++){
        getline(cin, letter);
        dict[k]=letter;
        letterscore=points(let_points, letter);
      	vector<char> let(letter.begin(),letter.end());
      	for (int i=0 ; i < let.size() ; i++) {
       		graph[make_pair(k,letterscore)].insert(let[i]);
          	}
      }
     //--------------------------------------------------
    //======the 7 letters available=================================
      string ave_let;
      getline(cin, ave_let);
      for (int i=0 ; i < ave_let.size() ; i++){
    	  	sug.insert(ave_let[i]);
    }
    //==============================================================
 

    int maxpoint=0;
    string word;
    for (it=graph.begin() ; it !=graph.end();it++ ) {

    	if (includes(sug.begin(),sug.end(),it -> second.begin(),it -> second.end())){
   

    		if (it->first.second> maxpoint) {
    			maxpoint=it->first.second;
    			index=it->first.first;
    			
    		}//if_maxpoint

    	}//if_include
    }//for_include

//  cout<<index<<":"<<word<<":"<<maxpoint<<endl;
  it_dict=dict.find(index);
  cout<<it_dict->second<<endl;


}//main


