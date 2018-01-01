
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

bool delet_node(map<int, vector<int> >& graph,map<int, vector<int> >::iterator& it1,vector<int>::iterator& it2)
{

	map<int, vector<int> >::iterator it=graph.find(*it2);
   	vector<int> ::iterator itt=find(it->second.begin() ,it->second.end(),it1->first);
	if(it1->second.size()==1) graph.erase(it1);
	else it1->second.erase (it2);
	if(it ->second.size()==1) graph.erase(it);
	else it ->second.erase (itt);
	return false;

}


int main()
{
    map<int, vector<int> > graph;
    vector<int> exits;
    vector<int> ::iterator it_v , it_e;
    map<int, vector<int> >::iterator it , it_a;

    	int N; // the total number of nodes in the level, including the gateways
        int L; // the number of links
        int E; // the number of exit gateways
        cin >>N>>L>>E ; cin.ignore();
        for (int i = 0; i < L; i++) {
            int N1; // N1 and N2 defines a link between these nodes
            int N2;
            cin >> N1 >> N2; cin.ignore();
            graph[N1].push_back(N2);
            graph[N2].push_back(N1);
        }
/*
        for (it=graph.begin(); it!=graph.end(); ++it) {
               	for(int i=0 ; i < it->second.size();i++)
               	cout << it->first << " => " << it->second[i] << '\n';
               }
*/
        for (int i = 0; i < E; i++) {
            int EI; // the index of a gateway node
            cin >> EI; cin.ignore();
            exits.push_back(EI);
        }

   while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        bool check=true;
        //**********************************************************************
       if(check){
        for (int i=0;i<graph[SI].size();i++ ) {
        	for(int j=0 ; j<exits.size();j++) {
        		if (graph[SI][i] == exits[j]) {
        			cerr<<"1"<<graph[SI][i]<<exits[j]<<endl;
        			cout<<SI<<" "<<graph[SI][i]<<endl;
        			it_a=graph.find(SI);
        			it_e=find(it_a->second.begin() ,it_a->second.end(),graph[SI][i]);
        			check=delet_node(graph,it_a,it_e);

        			break;
        		}//if
        	}//exits_v for
        }//agent_v for
       }//bool check
       if (check){
        if (graph.find(SI)->second.size() == 1 ){
        	cerr<<"2"<<endl;
        	cout<<SI<<" "<<graph.find(SI)->second[0]<<endl;
        	it_a=graph.find(SI);
        	it_e=find(it_a->second.begin() ,it_a->second.end(),it_a->second[0]);
       		check=delet_node(graph,it_a,it_e);
       		break;
        }//if
       }//bool check
       if (check) {
        for (int i=0 ; i<exits.size();i++){
        	if (graph.find(exits[i])->second.size() == 1 ){
        		cerr<<"3"<<endl;
        				cout<<exits[i]<<" "<<graph.find(exits[i])->second[0]<<endl;
        	        	it_a=graph.find(exits[i]);
        	        	it_e=find(it_a->second.begin() ,it_a->second.end(),it_a->second[0]);
        	       		check=delet_node(graph,it_a,it_e);
        	          	break;
        	}//if
        }//exits_v for
       }//bool check

       	   if (check){
        		cerr<<"4"<<endl;
        		cout<<SI<<" "<<graph[SI][0]<<endl;
        		it_a=graph.find(SI);
        		it_e=find(it_a->second.begin() ,it_a->second.end(),graph[SI][0]);
        		check=delet_node(graph,it_a,it_e);

       	   }//bool check



        /*
        for (it=graph.begin(); it!=graph.end(); ++it) {
        	for(int i=0 ; i < it->second.size();i++)
        	cout << it->first << " => " << it->second[i] << '\n';
        }
*/

  }//while


}//main


