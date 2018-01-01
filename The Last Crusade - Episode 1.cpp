#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int W; // number of columns.
    int H; // number of rows.
    cin >> W >> H; cin.ignore();
    string S_type[H][W];
    int type[H][W];
    for (int i = 0; i < H; i++) {
        string LINE; // represents a line in the grid and contains W integers. Each integer represents one room of a given type.
        for (int j=0; j<W-1 ; j++) {
            getline(cin,S_type[i][j],' ');
            type[i][j]=stoi(S_type[i][j]);
       //     cerr<<type[i][j]<<endl;
        }
        getline(cin, S_type[i][W-1]);
        type[i][W-1]=stoi(S_type[i][W-1]);
       // cerr<<type[i][W-1]<<endl;
    }
    int EX ; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
    cin >> EX; cin.ignore();

    // game loop
    while (1) {
        int XI;
        int YI;
        string POS;
        cin >> XI >> YI >> POS; cin.ignore();
        switch (type[YI][XI]) {
            case 0 : 
            cout << YI <<" "<<XI <<endl;
            break;
            case 1:
            cout <<XI << " "<< YI+1 <<endl;
            break;
            case 2: {
                if (POS=="TOP") {cout <<XI<< " "<< YI  <<endl;}
                if (POS=="LEFT") {cout <<XI+1<< " "<< YI  <<endl;}
                if (POS=="RIGHT") {cout <<XI-1<< " "<< YI  <<endl;}
                break;
            }
            case 3: {
                if (POS=="TOP") {cout <<XI<< " "<< YI+1  <<endl;}
                else {cout <<XI<< " "<< YI  <<endl;}
                break;
            }
            case 4: {
                if (POS=="TOP") {cout <<XI-1<< " "<< YI  <<endl;}
                if (POS=="LEFT") {cout <<XI<< " "<< YI  <<endl;}
                if (POS=="RIGHT") {cout <<XI<< " "<< YI+1  <<endl;}
                break;
            }
            case 5: {
                if (POS=="TOP") {cout <<XI+1<< " "<< YI  <<endl;}
                if (POS=="LEFT") {cout <<XI << " "<< YI+1  <<endl;}
                if (POS=="RIGHT") {cout <<XI<< " "<< YI  <<endl;}
                break;
            }
            case 6: {
                if (POS=="TOP") {cout <<XI<< " "<< YI  <<endl;}
                if (POS=="LEFT") {cout<<XI+1 << " "<< YI  <<endl;}
                if (POS=="RIGHT") {cout <<XI-1<< " "<< YI  <<endl;}
                break;
            }
            case 7: {
                if (POS=="TOP") {cout <<XI<< " "<< YI+1  <<endl;}
                if (POS=="LEFT") {cout <<XI << " "<< YI <<endl;}
                if (POS=="RIGHT") {cout  <<XI<< " "<< YI+1 <<endl;}
                break;
            }
            case 8: {
                if (POS=="TOP") {cout<<XI << " "<< YI  <<endl;}
                if (POS=="LEFT") {cout  <<XI<< " "<< YI+1 <<endl;}
                if (POS=="RIGHT") {cout  <<XI<< " "<< YI+1 <<endl;}
                break;
            }
            case 9: {
                if (POS=="TOP") {cout  <<XI<< " "<< YI+1 <<endl;}
                if (POS=="LEFT") {cout <<XI<< " " << YI+1 <<endl;}
                if (POS=="RIGHT") {cout  <<XI<< " "<< YI <<endl;}
                break;
            }
            case 10: {
                if (POS=="TOP") {cout <<XI-1<< " "<< YI  <<endl;}
                if (POS=="LEFT") {cout  <<XI<< " "<< YI <<endl;}
                if (POS=="RIGHT") {cout <<XI<< " "<< YI  <<endl;}
                break;
            }
            case 11: {
                if (POS=="TOP") {cout <<XI+1 << " "<< YI <<endl;}
                if (POS=="LEFT") {cout << XI << " "<<YI <<endl;}
                if (POS=="RIGHT") {cout << XI << " "<<YI <<endl;}
                break;
            }
            case 12: {
                if (POS=="TOP") {cout << XI << " "<<YI <<endl;}
                if (POS=="LEFT") {cout << XI << " "<<YI <<endl;}
                if (POS=="RIGHT") {cout<<XI  << " "<< YI+1 <<endl;}
                break;
            }
            case 13: {
                if (POS=="TOP") {cout << XI << " "<<YI <<endl;}
                if (POS=="LEFT") {cout <<XI << " "<< YI+1 <<endl;}
                if (POS=="RIGHT") {cout << XI << " "<<YI <<endl;}
                break;
            }
        }//End of switch
        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // One line containing the X Y coordinates of the room in which you believe Indy will be on the next turn.
       // cout << "0 0" << endl;
    }
}
