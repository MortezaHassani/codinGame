#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int main ()

{

	int index_r , index;
	int j=1 ;
	vector<int> v;
	vector<int>::iterator itt , itt_r,itt_0;
	set<int> z;
	set<int>::iterator it;
	//--------------------------------
	    int n; // the number of adjacency relations
	    cin >> n; cin.ignore();
	    int x[n],y[n];
	    for (int i = 0; i < n; i++) {
	     //   char xi; // the ID of a person which is adjacent to yi
	     //   char yi; // the ID of a person which is adjacent to xi
	        cin >> x[i] >> y[i]; cin.ignore();
	        z.insert(x[i]);
	        z.insert(y[i]);
	    }

	//-------------------------------


	for (int i=0 ; i<n ;i++) {
		v.push_back(x[i]);
	}
		v.push_back(0);
	for (int i=0 ; i<n ;i++) {
		v.push_back(y[i]);
		}
	/*
	for (int i=0 ; i<v.size() ;i++) {
			cerr<<"v("<<i<<")="<<v[i]<<endl;
					}
	cerr<<"size:"<<v.size()<<endl;
	*/
	itt_0=find (v.begin(), v.end(), 0);

while(v.size()!=3){
		for (it=z.begin(); it!=z.end(); ++it){
		int cnt = count(v.begin(),v.end(), *it);
		itt_0=find (v.begin(), v.end(), 0);
    	if (cnt==1){
    		 itt=find (v.begin(), v.end(), *it);
    		if (itt<=(itt_0)) {
    			itt_r=itt+n+1;
       	    	v.erase(itt_r);
    			v.erase(itt);
    			n=n-1;
    		}
    		 if (itt>(itt_0)) {
    			itt_r=itt-(n+1);
    			v.erase(itt);
    			v.erase(itt_r);
    			n=n-1;
    		}



    	}
	}
	/*
		for (int i=0 ; i<v.size() ;i++) {
					cerr<<"v("<<i<<")="<<v[i]<<endl;
							}
			cerr<<"size:"<<v.size()<<endl;
	*/
		j++;
}

   	cout<<j<<endl;

}//end of main

