
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    map<int, vector<int> > graph;
    map<int, vector<int> >::iterator it ;
    int n ; // the number of relationships of influence
    int  distance =1;
        cin >> n; cin.ignore();
        for (int i = 0; i < n; i++) {
            int x; // a relationship of influence between two people (x influences y)
            int y;
            cin >> x >> y; cin.ignore();
            graph[x].push_back(y);
                   }

   while(graph.size() != 0) {
        for (it=graph.begin(); it!=graph.end(); ++it) {
        	for (int i=0; i<it->second.size();i++){
          		if (graph.count(it->second[i])==0) {
        			it->second.erase(it->second.begin()+(i));
        			i--;

        		}
        	}
          }//for

        for (it=graph.begin(); it!=graph.end(); ++it) {
                if (it->second.size()==0){
                	graph.erase(it);
                }//if
           }// for

        distance++;
    }//while

cout<<distance<<endl;

}//main


