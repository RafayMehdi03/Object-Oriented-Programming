#include <iostream>
using namespace std ;
class Calender{
	string January[31] ;
	string February[28] ;
	string March[31] ;
	string April[30] ;
	string May[31] ;
	string June[30] ;
	string July[31] ;
	string August[31] ;
	string September[30] ;
	string October[31] ;
	string November[30] ;
	string December[31] ;
	int year ;
  public :
  	Calender(int y) {
        year = y;
        int i ;
	  	for(i=0;i<31;i++){
	  		January[i]="\0";
		}
		for(i=0;i<31;i++){
	  		February[i]="\0" ;
		}
		for(i=0;i<31;i++){
	  		March[i] ="\0" ;
		}
		for(i=0;i<31;i++){
	  		April[i]="\0" ;
		}
		for(i=0;i<31;i++){
	  		May[i]="\0" ;
		}
		for(i=0;i<31;i++){
	  		June[i]="\0" ;
		}
		for(i=0;i<31;i++){
	  		July[i]="\0" ;
		}
		for(i=0;i<31;i++){
	  		August[i]="\0" ;
		}
		for(i=0;i<31;i++){
	  		September[i]="\0" ;
		}
		for(i=0;i<31;i++){
	  		October[i]="\0" ;
		}
		for(i=0;i<31;i++){
	  		November[i]= "\0" ;
		}
		for(i=0;i<31;i++){
	  		December[i] = "\0" ;
		}
    }
  	int addTask(string task,int day,int month){
  		switch(month){
  			case 1 :
  				January[day] = task ;
  				return 0;
  			case 2 :
  				February[day] = task ;
  				return 0;
  			case 3 :
  				March[day] = task ;
  				return 0;
  			case 4 :
  				April[day] = task ;
  				return 0;
  			case 5 :
  				May[day] = task ;
  				return 0;
  			case 6 :
  				June[day] = task ;
  				return 0;
  			case 7 :
  				July[day] = task ;
  				return 0;
  			case 8 :
  				August[day] = task ;
  				return 0;
  			case 9 :
  				September[day] = task ;
  				return 0;
  			case 10 :
  				October[day] = task ;
  				return 0;
  			case 11 :
  				November[day] = task ;
  				return 0;
  			case 12 :
  				December[day] = task ;
  				return 0;
  			default :
  				cout << "Invalid Month" << endl ;
  				return 0 ;
		  }
	  }
	  int removeTask(int day,int month){
	  	switch(month){
  			case 1 :
  				January[day] = "\0" ;
  				return 0;
  			case 2 :
  				February[day] = "\0" ;
  				return 0;
  			case 3 :
  				March[day] = "\0" ;
  				return 0;
  			case 4 :
  				April[day] = "\0" ;
  				return 0;
  			case 5 :
  				May[day] = "\0" ;
  				return 0;
  			case 6 :
  				June[day] = "\0" ;
  				return 0;
  			case 7 :
  				July[day] = "\0" ;
  				return 0;
  			case 8 :
  				August[day] = "\0" ;
  				return 0;
  			case 9 :
  				September[day] = "\0" ;
  				return 0;
  			case 10 :
  				October[day] = "\0" ;
  				return 0;
  			case 11 :
  				November[day] = "\0" ;
  				return 0;
  			case 12 :
  				December[day] = "\0" ;
  				return 0;
  			default :
  				cout << "Invalid Month" << endl ;
  				return 0 ;
		  }	
	  }
	  void displayTasks(){
	  	int i ;
	  	for(i=0;i<31;i++){
	  		if(January[i] != "\0"){
	  			cout << January[i] << endl ;
			  }
		}
		for(i=0;i<31;i++){
	  		if(February[i]!="\0"){
	  			cout << February[i] << endl ;
			  }
		}
		for(i=0;i<31;i++){
	  		if(March[i]!="\0"){
	  			cout << March[i] << endl ;
			  }
		}
		for(i=0;i<31;i++){
	  		if(April[i]!="\0"){
	  			cout << April[i] << endl ;
			  }
		}
		for(i=0;i<31;i++){
	  		if(May[i]!="\0"){
	  			cout << May[i] << endl ;
			  }
		}
		for(i=0;i<31;i++){
	  		if(June[i]!="\0"){
	  			cout << June[i] << endl ;
			  }
		}
		for(i=0;i<31;i++){
	  		if(July[i]!="\0"){
	  			cout << July[i] << endl ;
			  }
		}
		for(i=0;i<31;i++){
	  		if(August[i]!="\0"){
	  			cout << August[i] << endl ;
			  }
		}
		for(i=0;i<31;i++){
	  		if(September[i]!="\0"){
	  			cout << September[i] << endl ;
			  }
		}
		for(i=0;i<31;i++){
	  		if(October[i]!="\0"){
	  			cout << October[i] << endl ;
			  }
		}
		for(i=0;i<31;i++){
	  		if(November[i]!="\0"){
	  			cout << November[i] << endl ;
			  }
		}
		for(i=0;i<31;i++){
	  		if(December[i]!="\0"){
	  			cout << December[i] << endl ;
			  }
		}
	  }
};
int main(){
	Calender y2025(2025) ;
	y2025.addTask("Jogging",25,1) ;
	y2025.addTask("Running",14,3) ;
	y2025.addTask("Sleeping",5,4) ;
	y2025.addTask("Walking",21,7) ;
	y2025.addTask("Excercising",25,10) ;
	y2025.addTask("Reading",31,11) ;
	y2025.removeTask(25,1) ;
	y2025.displayTasks() ;
}