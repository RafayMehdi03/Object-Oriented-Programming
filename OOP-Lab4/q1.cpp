#include <iostream>
using namespace std ;
class Student{
	int studentID ;
	string name ;
	int age ;
	char grade ;
  public:
  	Student(){
  		grade = 'N' ;
	  }
	Student(int pID,string pName,int pAge,char pGrade){
		studentID = pID ;
		name = pName ;
		age = pAge ;
		grade = pGrade ;
	}
	void promoteStudent(){
		if(grade!='A'){
		    grade -= 1;
		    cout << "Grade increased" << endl ;
	    }
	    else{
	    	cout << "Already Has Max Grade" << endl ;
		}
	}
	bool isEligibleForScholarship(){
		if(grade=='A'){
			return true ;
		}
		else{
			return false ;
		}
	}
	void displayDetails(){
		cout << "- Name: " << name << endl << "- ID: " << studentID << endl << "- Age: " << age << endl << "- Grade: " << grade << endl ;
	}
};
int main(){
	Student student1(866,"Rafay",19,'B') ;
    Student student2(808,"Saim",17,'A') ;
    Student student3(572,"Ali",18,'B') ;
    Student student4(382,"Haider",20,'C') ;
    student1.promoteStudent() ;
    student4.promoteStudent() ;
    bool ans = false ;
	ans = student2.isEligibleForScholarship() ;
    if(ans){
    	cout << "Student 2 is eligible for scholarship" << endl ;
	}
	else{
		cout << "Student 2 is not eligible for scholarship" << endl ;
	}
	cout << "Student 1" << endl ;
	student1.displayDetails() ;
	cout << "Student 2" << endl ;
	student2.displayDetails() ;
	cout << "Student 3" << endl ;
	student3.displayDetails() ;
	cout << "Student 4" << endl ;
	student4.displayDetails() ;
}