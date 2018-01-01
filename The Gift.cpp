
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main()
{
//-----------------------------------------------------
	 int N;
	 vector<int> Numbs,Ans;
	    cin >> N; cin.ignore();
	    int C;
	    cin >> C; cin.ignore();
	    for (int i = 0; i < N; i++) {
	        int B;
	        cin >> B; cin.ignore();
	        Numbs.push_back(B);
	    }
//-----------------------------------------------------
	    int b=0;
	    int a= accumulate(Numbs.begin(),Numbs.end(),b);
	    if (C>a) cout<<"IMPOSSIBLE"<<endl;
	    else{
	    	sort(Numbs.begin(),Numbs.end());
	    	while(C!=0){
	    		int sig=C/Numbs.size();
	    			if(sig<Numbs.front()){
	    			Ans.push_back(sig);
	    			C=C-sig;
	    		}
	    		else{
	    			Ans.push_back(Numbs.front());
	    			C=C-Numbs.front();
	    		}
	    		Numbs.erase(Numbs.begin());
	    	}
	    }
	    for(int i=0 ; i<Ans.size();i++) cout<<Ans[i]<<endl;
}//main


