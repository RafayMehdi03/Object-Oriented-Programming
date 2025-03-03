#include <iostream>
using namespace std ;
class LoanHelper{
	static const float interestRate ;
	float amount ;
	int months ;
  public:
  	LoanHelper(float loanAmount,int Months):amount(loanAmount),months(Months) {} 
	void loanCalculate(){
		float perMonth ;
		perMonth = (amount / months) ;
		perMonth = perMonth * (1+(interestRate/100)) ;
		cout << "You have to pay " << perMonth << " every month for " << months <<  " to repay your loan" << endl ;
	}
};
const float LoanHelper :: interestRate = 0.5 ; 
int main(){
	LoanHelper loan1(1000.0,12) ;
	LoanHelper loan2(500.0,12) ;
	LoanHelper loan3(700.0,6) ;
	loan1.loanCalculate() ;
	loan2.loanCalculate() ;
	loan3.loanCalculate() ;
}