#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    map <int , int > mymap;
    int nbFloors; // number of floors
    int width; // width of the area
    int nbRounds; // maximum number of rounds
    int exitFloor; // floor on which the exit is found
    int exitPos; // position of the exit on its floor
    int nbTotalClones; // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators; // number of elevators
    int elevatorFloor;
    int elevatorPos;
    cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();
    for (int i = 0; i < nbElevators; i++) {
         // floor on which this elevator is found
        // position of the elevator on its floor
        cin >> elevatorFloor >> elevatorPos; cin.ignore();
        mymap.insert(pair<int,int>(elevatorFloor,elevatorPos));       
    } // elevator place for

    // game loop
       while (1) {
        int cloneFloor; // floor of the leading clone
        int clonePos; // position of the leading clone on its floor
        string direction; // direction of the leading clone: LEFT or RIGHT
        cin >> cloneFloor >> clonePos>> direction; cin.ignore();
        elevatorPos=mymap.find(cloneFloor)->second;
        elevatorFloor = cloneFloor;
        cerr << cloneFloor<<"-"<<clonePos<<"-"<<direction<<endl;
        cerr << exitFloor<<"-"<<exitPos<<endl;
        cerr << elevatorFloor<<"-"<<elevatorPos<<endl;
        if ( cloneFloor !=  exitFloor ) {
            if (clonePos < elevatorPos && direction =="LEFT" ) {
                cout << "BLOCK" << endl;
                cerr << "1BLOCK" << endl;
            } // first if end
            else if (clonePos > elevatorPos && direction =="RIGHT") {
                cout << "BLOCK" << endl;
                cerr << "2BLOCK" << endl;
            } // second if end
            else { cout << "WAIT" << endl; }
                 } // floor if 
    //------------------exit and clone are in the same floor ------------------------------     
          else {
            if (clonePos < exitPos && direction =="LEFT" ) {
                cout << "BLOCK" << endl;
                cerr << "3BLOCK" << endl;
            } // first if end
             else if (clonePos > exitPos && direction =="RIGHT" ) {
                cout << "BLOCK" << endl;  
                cerr << "4BLOCK" << endl;
            } // second if end
            else { cout << "WAIT" << endl; }
          } // checking floor else end 
        //  cout << "WAIT" << endl;
                 }  // game loop end
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

       // cout << "WAIT" << endl; // action: WAIT or BLOCK
    
}  // main end
