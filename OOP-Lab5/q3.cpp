#include <iostream>
#include <string>
using namespace std ;
class validateString{
	string String;
  public:
  	validateString(string setString){
  		String = setString ;
	}
	const void validate(){
		bool valid = true ;
		int i ;
		for(i=0;String[i]!='\0';i++){
			if((String[i]>='A' && String[i] <= 'Z')||(String[i]>='a' && String[i] <= 'z')||(String[i]==' ')){
				valid = true ;
			}
			else{
				cout << "String is Invalid" << endl ;
				valid = false ;
				break ;
			}
		}
		if(valid){
			cout << "String is Valid" << endl ;
		}
	}
};
int main(){
	validateString s1("Hello World") ;
	validateString s2("k24-0866") ;
	validateString s3("OOP lab") ;
	s1.validate() ;
	s2.validate() ;
	s3.validate() ;
}