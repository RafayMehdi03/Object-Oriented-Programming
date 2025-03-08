#include <iostream>
using namespace std ;
class BankAccount{
	double accountNumber ;
	string accountHolderName ;
	double balance ;
  public:
    BankAccount():accountNumber(0),accountHolderName(""),balance(0) {}
  	BankAccount(double accNum,string name,double amount):accountNumber(accNum),accountHolderName(name),balance(amount) {}
    
    void deposit(double amount){
    	balance += amount ;
    	cout << amount << "$ deposited in account : " << accountNumber << endl ;
	}
	void withdraw(double amount){
		if(balance>=amount){
			balance -= amount ;
			cout << amount << "$ withdrawn from account : " << accountNumber << endl ;
		}
		else{
			cout << "Insufficient Funds" << endl ;
		}
	}
	void display(){
		cout << "Account Information" << endl << "Account Number : " << accountNumber << " || Account Title : " 
		<< accountHolderName << " || Balance : " << balance << endl ;
	}
};
int main(){
	BankAccount accountList[3] ;
	accountList[0] = BankAccount(98763,"Shuja",55002.67) ;
	accountList[1] = BankAccount(87652,"Rafay",10383.67) ;
	accountList[2] = BankAccount(76549,"Fizza",19381.67) ;
    for(int i=0;i<3;i++){
    	accountList[i].deposit(500) ;
    	accountList[i].display() ;
    	accountList[i].withdraw(200) ;
    	accountList[i].display() ;
	}
}