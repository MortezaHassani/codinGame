#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

string COMP(string& C1,string& C2)
{

char p1=C1[0],p2=C2[0];

if(p1=='A')p1='Z';
if(p2=='A')p2='Z';
if(p1=='K')p1='Y';
if(p2=='K')p2='Y';
if(p1=='1')p1='@';
if(p2=='1')p2='@';

if (p1>p2) return C1;
if(p1<p2) return C2;
if(p1==p2) return "Draw";


}
void WAR(bool& Pat ,queue<string>& P1deck,queue<string>& P2deck ,queue<string>& WarDeck1,queue<string>& WarDeck2 ,string& P1card,string& P2card)
{
if((P1deck.size()<3)||(P2deck.size()<3)) Pat=false;
if(Pat){
WarDeck1.push(P1card);
WarDeck2.push(P2card);
for (int i=0;i<3;i++){
	WarDeck1.push(P1deck.front());
	P1deck.pop();
	WarDeck2.push(P2deck.front());
	P2deck.pop();
}

    string P1WARCARD=P1deck.front();
    P1deck.pop();
    string P2WARCARD=P2deck.front();
    P2deck.pop();
    if(COMP(P1WARCARD,P2WARCARD)==P1WARCARD){
    	WarDeck1.push(P1WARCARD);
    	WarDeck2.push(P2WARCARD);
  	     while (!WarDeck1.empty()){
    		 P1deck.push(WarDeck1.front());
    		 WarDeck1.pop();
    	    	}
   	     while (!WarDeck2.empty()){
   	     		 P1deck.push(WarDeck2.front());
   	     		 WarDeck2.pop();
   	     	    	}
    }
    if(COMP(P1WARCARD,P2WARCARD)==P2WARCARD){
    	WarDeck1.push(P1WARCARD);
    	    	WarDeck2.push(P2WARCARD);
    	  	     while (!WarDeck1.empty()){
    	    		 P2deck.push(WarDeck1.front());
    	    		 WarDeck1.pop();
    	    	    	}
    	   	     while (!WarDeck2.empty()){
    	   	     		 P2deck.push(WarDeck2.front());
    	   	     		 WarDeck2.pop();
    	   	     	    	}
    }
    if(COMP(P1WARCARD,P2WARCARD)=="Draw"){
    return WAR(Pat,P1deck,P2deck,WarDeck1,WarDeck2,P1WARCARD,P2WARCARD);

           }
}
else cout<<"PAT"<<endl;

}

int main()
{

//-------------------------------------------------------------------
	queue<string> P1DECK,P2DECK;
	bool pat =true;
    int n; // the number of cards for player 1
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string cardp1; // the n cards of player 1
        cin >> cardp1; cin.ignore();
        P1DECK.push(cardp1);
    }
    int m; // the number of cards for player 2
    cin >> m; cin.ignore();
    for (int i = 0; i < m; i++) {
        string cardp2; // the m cards of player 2
        cin >> cardp2; cin.ignore();
        P2DECK.push(cardp2);
    }


int c=0;
while(pat){
	queue<string> WARDECK1,WARDECK2;
	string P1card=P1DECK.front();
	P1DECK.pop();
	string P2card=P2DECK.front();
	P2DECK.pop();
	string CardWin=COMP(P1card,P2card);

	if(CardWin==P1card){
		P1DECK.push(P1card);
		P1DECK.push(P2card);
	}
	if(CardWin==P2card){
		P2DECK.push(P1card);
		P2DECK.push(P2card);
		}
	if(CardWin=="Draw"){

		WAR(pat,P1DECK,P2DECK,WARDECK1,WARDECK2,P1card,P2card);
	}
	c++;
	if(P1DECK.empty()) break;
	if(P2DECK.empty()) break;
	
	}


//---------------------------------------------------------------------

if (pat) {
    if(P1DECK.empty()) cout<<2<<" ";
    if(P2DECK.empty()) cout<<1<<" ";
    cout<<c<<endl;
   }
///else  cout<<"PAT"<<endl;


}
