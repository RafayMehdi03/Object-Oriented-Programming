#include <iostream>
#include <iomanip>
using namespace std ;
class angle{
    int degrees ;
    float minutes ;
    char direction ;
  public:
    angle(int de,float mi,char di){
        degrees = de ;
        minutes = mi ;
        direction = di ;
    }
    int inputData(){
        cout << "Enter Direction: " ;
        cin >> direction ;
        if(direction=='E' || direction == 'W'){
            cout << "Enter degrees between 0-180: " ;
            cin >> degrees ;
        }
        else if(direction=='N' || direction == 'S'){
            cout << "Enter degrees between 0-90: " ;
            cin >> degrees ;
        }
        else{
            cout << "Incorrect direction entered" ;
            return 0 ;
        }
        cout << "Enter minutes: " ;
        cin >> minutes ;
        if(minutes>60.0||minutes<0.0){
            cout << "Invalid minutes entered" ;
            return 0 ;
        }
        return 1;
    }
    void outputData(){
        cout << "Details:" << endl ;
        cout << degrees << "°" << fixed << setprecision(1) << minutes << "' " << direction ;
    }
};
int main(){
    angle a1(0,0.0,'X') ;
    char answer = 'Y' ;
    while(answer == 'Y'){
        a1.inputData() ;
        a1.outputData() ;
        cout << endl << "Do you want to continue Y|N? " ;
        cin >> answer ;
    }
}
