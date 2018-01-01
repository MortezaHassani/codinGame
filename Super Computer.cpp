#include <iostream>
#include<set>
#include<algorithm>

using namespace std;


int main()
{
	int N;
	cin>>N;cin.ignore();
	set<pair<int,int>> Calc;
	set<pair<int,int>>::iterator it;
    for (int i = 0; i < N; i++) {
        int J;
        int D;
        cin >> J >> D; cin.ignore();
        Calc.insert(make_pair(J,J+D));
    }

    int nextCalc=Calc.begin()->second;
    Calc.erase(Calc.begin());
    int C=1;
    for (it=Calc.begin();it!=Calc.end();it++) {
    	if(nextCalc<=it->first) {
    		C++;
    		nextCalc=it->second;
    	}
    	nextCalc=min(nextCalc,it->second);
    }

    cout<<C<<endl;
}

