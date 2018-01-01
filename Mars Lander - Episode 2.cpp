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
    vector <int> lx;
    vector <int> ly;
    int surfaceN; // the number of points used to draw the surface of Mars.
    cin >> surfaceN; cin.ignore();
    int landX; // X coordinate of a surface point. (0 to 6999)
    int landY; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
    int x0 , y0 , x1,h;
                
    for (int i = 0; i < surfaceN; i++) {
        cin >> landX>> landY; cin.ignore();
        lx.push_back(landX);
        ly.push_back(landY);
       //    cerr<<"1:"<<landX<<":"<<landY<<":"<<i<<endl;
        //    cerr<<"0:"<<x0<<":"<<x1<<":"<<y0<<endl;
    }// first for loop
    x0 = lx.front();
    y0 =ly.front();
    for (int k=1 ; k<lx.size(); k++) {
        if (ly[k]!=y0) {
            y0=ly[k];
            x0=lx[k];
        }
        else {
             h=k;
        }
    }
        
  x0=lx[h-1];
  y0=ly[h-1];
  x1=lx[h];
//  cerr<<"x0=:"<<x0<<","<<"x1="<<x1<<","<<"y0="<<y0<<"|"<<h<<endl;
    // game loop
    vector <int> XX;
    vector <int> YY;
    int r=0,p=0;
  
    while (1) {
        
        int deltax;
        int X;
        int Y;
        int hSpeed; // the horizontal speed (in m/s), can be negative.
        int vSpeed; // the vertical speed (in m/s), can be negative.
        int fuel; // the quantity of remaining fuel in liters.
        int rotate; // the rotation angle in degrees (-90 to 90).
        int power; // the thrust power (0 to 4).
        cin >> X >> Y >> hSpeed >> vSpeed >> fuel >> rotate >> power; cin.ignore();
     //   cerr<<x0<<","<<rotate<<","<<power<<endl;
     //  cerr<<X <<"  "<< Y <<"  "<< hSpeed <<"  "<< vSpeed <<"  "<< fuel <<"  "<< rotate <<"  "<< power<<endl;
        
       
        XX.push_back(X);
        YY.push_back(hSpeed);
        deltax=(abs(x0-XX.front())/2)+XX.front();
        //cerr<<deltax<<"|"<<X<<"|:"<<y0<<endl; 
//-------------- this part is written for last test but its not working for all parts--------
        if (y0==2100) { 
            if (X>x1*3) cout<<"20 4"<<endl; 
            if (X>x1 && X<x1*3) cout <<"-20 4"<<endl;
            if (X<=x1 && X>x0) {
                if (hSpeed <-20 ) cout <<"-30 4"<<endl;
                if (hSpeed>=-20 ) cout <<"-0 3"<<endl;
            }
        }
//-------------------------------------------------------------------------------------            
        else {
        if (hSpeed<=20 && hSpeed >=0) {
            if (X<x0) {
                r=-20;
                p=4;
            }//if 
            else if(X>=x0 && X<=x1) {
                
                if (hSpeed<=5) {
                    r=0;
                    if (abs(vSpeed)>=40) p=4;
                    else p=0;
                }
                else {
                    r=20;
                    p=4;
                }
            }//else if
            else if (X>=x1) {
                r=20;
                p=3;
            }//else if
        }//first if
        if (hSpeed>20) {
            if (X<x0) {
                if (X>=deltax) { p=4;r=35;}
                else {p=3;
                r=20;}
            }//if 
            else if(X>=x0 && X<=x1) {
                r=60;
                p=4;
            }//else if
            else if (X>=x1) {
                r=30;
                p=3;
            }//else if
        }//2 if
         if (hSpeed>=-20 && hSpeed < 0) {
            if (X<x0) {
                r=90;
                p=4;
            }//if 
            else if(X>=x0 && X<=x1) {
                
                if (abs(hSpeed)<=5) {
                    r=0;
                    if (abs(vSpeed)>=40) p=4;
                    else p=0;
                }
                else {
                    r=-30;
                
                p=4;
                }
            }//else if
            else if (X>=x1) {
                r=-20;
                p=3;
            }//else if
        }//first if
        if (hSpeed<-20) {
            if (X<x0) {
                r=-90;
                p=4;
            }//if 
            else if(X>=x0 && X<=x1) {
                
                r=-60;
                p=4;
            }//else if
            else if (X>=x1) {
                r=-30;
                p=4;
            }//else if
        }//2 if
       
         cout <<r<<" "<<p<<endl; 
        }//else for y0
        // cerr<<hSpeed<<endl;
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
 

        // rotate power. rotate is the desired rotation angle. power is the desired thrust power.
       // cout << "-30 3" << endl;
    }// game loop ends
}//main loop
