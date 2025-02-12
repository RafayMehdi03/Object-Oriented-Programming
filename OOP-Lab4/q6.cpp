#include <iostream>
using namespace std ;
class Account{
	int AccNum ;
	string ownerName ;
	double initialBalance ;
  public:
  	Account(int num,string name,double balance){
		AccNum = num ;
		ownerName = name ;
		initialBalance = balance ;
	}
	Account(int num,string name){
		AccNum = num ;
		ownerName = name ;
		initialBalance = 0.0 ;
	}
	void Deposit(double amount){
		initialBalance += amount ;
		cout << "Amount Deposited" << endl ;
	}
	void Withdraw(double amount){
		if(amount<=initialBalance){
			initialBalance -= amount ;
			cout << "Amount Withdrawn" << endl ;
		}
		else{
			cout << "Insufficient Funds" << endl ;
		}
	}
	void displayDetails(){
		cout << "-----Account Details-----" << endl << "Account Number: " << AccNum << endl << "Owner's Name: " << ownerName 
		<< endl << "Balance: " << initialBalance << endl << "-------------------------" << endl;
	}
	  
};
int main(){
	Account acc1(2948,"Najam",1000.0) ;
	Account acc2(4739,"Saim") ;
	cout << "Account 1" << endl ;
	acc1.displayDetails() ;
	acc1.Withdraw(500.0) ;
	acc1.displayDetails() ;
	cout << endl << "For Account 2" << endl ;
	acc2.displayDetails() ;
	acc2.Deposit(500.0) ;
	acc2.displayDetails() ;
}