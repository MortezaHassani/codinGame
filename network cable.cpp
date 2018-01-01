#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<set>

using namespace std;

int main()
{
   // cout.precision(15);
	vector< long long int> Yn,newY;
	set< long long int> Xn;
	multiset< long long int>::iterator it ,ity;
       int N ;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
         long long int X;
         long long int Y;
        cin >> X >> Y; cin.ignore();
        Xn.insert(X);
        Yn.push_back(Y);
    }
    //----------------------check set of nodes--------------------------------------------------
  //  for ( it=Nodes.begin(); it!=Nodes.end(); ++it)
   //    cout <<"(" << it->first<<","<< it->second<<")"<<endl;
   //-------------------------------------------------------------------------

    long long int dx=abs(*Xn.begin() - *Xn.rbegin());
 //  cout<<*Xn.begin()<<":"<<*Xn.rbegin()<<"//"<<dx<<endl;
   sort(Yn.begin(), Yn.end());
    long long int median=Yn[Yn.size()/2];

  // cout<<Yn.size()/2<<"med:"<<median<<endl;
   for (int i=0; i<Yn.size(); i++ ){
	   newY.push_back(Yn[i]-median);
   }
    long long int dy=0;
   for (int i=0; i<newY.size(); i++){
	   dy=dy+abs(newY[i]);
//	   cout<<newY[i]<<endl;
  }
//  cout<<dx<<":"<<dy<<":"<<endl;
   cout<<dx+dy<<endl;;

}

