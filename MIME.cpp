#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
      
      int N; // Number of elements which make up the association table.
      cin >> N; cin.ignore();
      int Q; // Number Q of file names to be analyzed.
      cin >> Q; cin.ignore();
      string EXT[N] ;
      string ex=""; // file extension
      string MT[N] ; // MIME type.
    for (int i = 0; i < N; i++) {

        cin >> EXT[i] >> MT[i]; cin.ignore();

        }
    for (int i = 0 ; i<N ; i++) {
         ex=ex+"."+EXT[i];
         }
    for (int i=0; i<ex.size(); i++) {
         ex[i]=toupper(ex[i]);
         }
    for (int i = 0; i < Q; i++) {
        string s; // One file name per line.
        getline(cin, s);
        for (int i=0; i<s.size(); i++) {
         s[i]=toupper(s[i]);
         }
        int dot = s.rfind(".");
        string type;
        if (dot == -1 ) {
            type="@@@";
           }
        else {
            type = s.substr (dot,s.size());
        	if (s.size() - dot ==1) type="@@@";
        }
       	int count=0;
    	int f=ex.find(type);
    	if (f==-1) {
    	    		cout<<"UNKNOWN"<<endl;

    	        	}
    	else {
    	for (int j=0 ; j<f ; j++) {
    		if (ex[j]=='.') count++;
    	    }
    	    cout<<MT[count]<<endl;
         	}

         }

}

