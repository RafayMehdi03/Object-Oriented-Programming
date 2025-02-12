#include <iostream>
using namespace std ;
class Employee{
	int employeeID ;
	string name ;
	string department ;
	double salary ;
  public :
  	Employee(){
  		salary = 0.0 ;
	}
	Employee(int id,string name,string department,double salary){
		this->employeeID = id ;
		this->name = name ;
		this->department = department ;
		this->salary = salary ;
	}
	void giveBonus(double amount){
		salary += amount ;
		cout << "Bonus Given" << endl ;
	}
	bool isManager(){
		if(department=="Management"||department=="management"){
			return true ;
		}
		else{
			return false ;
		}
	}
	void displayDetails(){
		cout << "Name: " << name << endl << "Employee ID: " << employeeID << endl 
		<< "Department Name: " << department << endl << "Salary: " << salary << endl ;
	}
};
int main(){
	bool ans ;
	Employee e1(1234,"Ali","HR",400.0) ;
	Employee e2(2345,"Daud","Finance",300.0) ;
	Employee e3(3456,"Ubaid","Management",500.0) ;
	cout << "For Employee 1" << endl ;
	e1.displayDetails() ;
	ans = e1.isManager() ;
	if(ans){
		cout << "This employee is a manager" << endl ;
	}
	else{
		cout << "This employee is not a manager" << endl ;
	}
	cout << endl <<"For Employee 2" << endl ;
	e2.displayDetails() ;
	e2.giveBonus(500) ;
	e2.displayDetails() ;
	cout << endl << "For Employee 3" << endl ;
	e3.displayDetails() ;
	ans = e3.isManager() ;
	if(ans){
		cout << "This employee is a manager" << endl ;
	}
	else{
		cout << "This employee is not a manager" << endl ;
	}
}