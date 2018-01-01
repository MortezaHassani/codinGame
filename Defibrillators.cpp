#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <iterator>  // std::begin, std::end
using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
int main()
{
    cout.precision(20);
    long double C=0.017453293;
   // vector<float> vec;
    map <long double , string > mymap;
    long double LON0_f , LAT0_f  ;
    string LON0,LAT0,E;
    cin >> LON0; cin.ignore();
    replace( LON0.begin(), LON0.end(), ',', '.' );
    LON0_f=stof(LON0)* C ;
   // cout<<"LON0_f "<<LON0_f<<endl;
    cin >> LAT0; cin.ignore();
    replace( LAT0.begin(), LAT0.end(), ',', '.' );
    LAT0_f=stof(LAT0) * C;
   // cout<<"LAT0_f "<<LAT0_f<<endl;
    int N;
    cin >> N; cin.ignore();
    long double LON_f[N],LAT_f[N],d[N],x[N],y[N] ;
    string address[N],a[N][6],s,LON[N],LAT[N];
	
    for (int i = 0; i < N; i++) {
        for (int j=0 ; j<5 ; j++) {
            getline(cin,a[i][j],';');
        }
        getline(cin,a[i][5]);
        address[i]=a[i][1];
        LON[i]=a[i][4];
        replace( LON[i].begin(), LON[i].end(), ',', '.' );
        LON_f[i]=stof(LON[i]) * C;
    //    cout<<"LON_f i "<<LON_f[i]<<endl;
        LAT[i]=a[i][5];
        replace( LAT[i].begin(), LAT[i].end(), ',', '.' );
        LAT_f[i]=stof(LAT[i])* C;
  //      cout<<"LAT_fi "<<LAT_f[i]<<endl;
        long double H = (LON_f[i] - LON0_f);
        long double H2 = cos((LAT0_f + LAT_f[i]) / 2.0);
         x[i] = H*H2;
  //       cout<<"Hi "<<H<<endl;
   //      cout<<"H2i "<<H2<<endl;
   //      cout<<"xi "<<x[i]<<endl;
        y[i] = (LAT_f[i] - LAT0_f);
   //     cout<<"yi "<<y[i]<<endl;
        d[i] = sqrt((pow(x[i],2)+pow(y[i],2))) ;
 //       cout<<d[i]<<endl;
       // vec[i]=d[i];
        mymap.insert(pair<long double,string>(d[i],address[i]));
       }

    //  pair<float,string> min = *min_element(mymap.begin(), mymap.end());
    
   pair <long double,string>  min_d = *min_element(mymap.begin(),mymap.end()); 
   cout<< min_d.second<<endl;
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
 //     cout << min.second << endl;
      
}
