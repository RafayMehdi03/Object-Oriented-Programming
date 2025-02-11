#include <iostream>
#include <conio.h>
using namespace std;

class tollBooth {
  private :
	unsigned int numCars ;
	double totalMoney ;
  public :
  	tollBooth() : numCars(0) , totalMoney(0.0) {}
  	
  	void payingCar(){
  		numCars ++ ;
  		totalMoney += 0.5 ;
	}
	void nopayCar(){
  		numCars ++  ;
	}
	void display(){
		cout << "Number Of Cars: " << numCars << endl ;
		cout << "Total Money: " << totalMoney << endl ;
	}
} ;
int main(){
	tollBooth booth1 ;
	char choice ;
	while(true){
		cout << "Choose an option" << endl << "Press A to count a paying car" << endl << "Press B to count a non-paying car" << endl << "Press ESC to display the cars and exit" << endl ;
		choice = _getch() ;
		if (choice == 27) {
            booth1.display() ;
            break;
        }
        else if (choice == 'A') {
            booth1.payingCar() ;
        }
        else if (choice == 'B') {
            booth1.nopayCar() ;
        }
	}
}