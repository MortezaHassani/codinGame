#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int num[20] , j;
    string s_num[20];
    map <string , int> m_num;
    int L;
    int H;
    cin >> L >> H; cin.ignore();
    string p_num[20][L];
    for (int i = 0; i < H; i++) {
        string numeral;
        cin >> numeral; cin.ignore();
        for(j=0 ; j<L*20 ; j=j+L) {
           s_num[j/L]=s_num[j/L]+numeral.substr(j,L); 
           p_num[j/L][i]=numeral.substr(j,L);
      //     cerr<<j<<endl;
      //    cerr<<s_num[j/L]<<endl;
        }//for j loop
    }
    //cerr<<p_num[19][3]<<endl;
    for (int i=0;i<20;i++) {
        m_num[s_num[i]]=i;
    }//map fulling

//------------------------------------------------------------------------
    int S1;
    cin >> S1; cin.ignore();
    int I1=S1/L;
    long long int N1=0;
    string num1[I1];
    vector <long long int> vecN1;
   // cerr <<I1<<endl;
    for(int l=0 ;l<I1;l++) {
        for (int i = 0; i < L; i++) {
            string num1Line;
            cin >> num1Line; cin.ignore();
            num1[l]=num1[l]+num1Line;
            
         }
  //      N1[l] =m_num.find(num1[l])->second;
        vecN1.push_back(m_num.find(num1[l])->second);
        }//first for
    reverse(vecN1.begin(),vecN1.end());
    for (int c=0 ; c<vecN1.size();c++) {
     N1=N1+(vecN1[c]*(pow(20,c))) ;
     
    }
   
    int S2;
    cin >> S2; cin.ignore();
    int I2=S2/L;
    long long int N2=0;
    string num2[I2];
    vector <long long int> vecN2;
    for(int l2=0 ;l2<I2;l2++) {
        for (int i = 0; i < L; i++) {
             string num2Line;
             cin >> num2Line; cin.ignore();
             num2[l2]=num2[l2]+num2Line;
        }
  //    N2[l2] =m_num.find(num2[l2])->second;
        vecN2.push_back(m_num.find(num2[l2])->second);
    }//first for
    reverse(vecN2.begin(),vecN2.end());
    for (int c2=0 ; c2<vecN2.size();c2++) {
     N2=N2+(vecN2[c2]*(pow(20,c2))) ;
    
    }
    string operation;
    cin >> operation; cin.ignore();
    long long int result;
    if (operation=="+") result=N1+N2;
    if (operation=="-") result=N1-N2;
    if (operation=="*") result=N1*N2;
    if (operation=="/") result=N1/N2;
     //cerr<<21%20;  
     vector<int> ans;
     
     do {
       ans.push_back(result%20);
       result=result / 20;
          } while (result!=0);
 //         cerr<<ans[0];
          reverse(ans.begin(),ans.end());
//   
    for (int m=0 ; m<ans.size(); m++) {
     for (int i=0 ; i<H ; i++) {
        cout<<p_num[ans[m]][i]<<endl;
         }
     }//printing the answer

    //cout << "result" << endl;
}
