
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	int R;
	cin >> R; cin.ignore();
	int L;
	cin >> L; cin.ignore();
	vector<vector<int>> total;
	vector<int> tc;
	string ANS="";
	tc.push_back(R);
	total.push_back(tc);
for(int j=0 ; j<L ; j++){
	    tc.clear();
		for (int i=0;i<total[j].size();i++){
		int count=0;
		int a=total[j][i];
		int b=a;
		while(a==b){
			count++;
			i++;
			b=total[j][i];

		}

		tc.push_back(count);
		tc.push_back(a);
		a=total[j][i];
		i--;
		}

	total.push_back(tc);
/*
	for (int i=0;i<total[j].size();i++)
	cout<<total[j][i]<<" ";
	cout<<endl<<"----------"<<endl;
*/
}
int count = total[L-1].size();
for (int i=0;i<total[L-1].size();i++){
cout<<total[L-1][i];
if(--count != 0){
   std::cout << " ";
}
}
/* string ans="";
for (int i=0;i<total[L-1].size();i++)
ans=ans +to_string(total[L-1][i])+" ";
ans.pop_back();
cout<<ans;
*/
}


