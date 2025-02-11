#include <iostream>
#include <string>
using namespace std ;
class stationaryShop{
	string items[100] ;
	float prices[100] ;
	int itemCount = 0 ;
  public:
  	void addItems(){
  		if(itemCount < 100){
  		string item ;
  		float price ;
  		cout << "Enter item name: " ;
  		cin.ignore() ;
  		getline(cin,item) ;
  		cout << "Enter price: " ;
  		cin >> price ;
  		items[itemCount] = item ;
  		prices[itemCount] = price ;
  		itemCount ++ ;
  		cout << "Item Added" << endl ;
	    }
	    else{
	    	cout << "Max Items Already Stored" << endl ;
		}
  	}
	void fetchList(){
		if(itemCount>0){
			for(int i=0;i<itemCount;i++){
				cout << i+1 << ". " << items[i] << endl ;
			}
		}
		else{
			cout << "No Items Stored" << endl ;
		}
	}
	void editPrice(){
		int index ;
		float newPrice ;
		cout << "Enter index of the item you want to edit ( start from 0 ): " ;
		cin >> index ;
		cout << "Enter the new price: " ;
		cin >> newPrice ;
		if(index>=0&&index<itemCount){
			prices[index] = newPrice ;
			cout << "Price Edited" << endl ;
		}
		else{
			cout << "Invalid Index" ;
		}
	}
	void viewItems(){
		if(itemCount>0){
			for(int i=0;i<itemCount;i++){
				cout << i+1 << ". " << items[i] << "     " << prices[i] << endl ; 
			}
		}
		else{
			cout << "No items" << endl ;
		}
	}
};
int main(){
	stationaryShop shop1 ;
	for(int a=0;a<5;a++){
	    shop1.addItems() ;
	}
	char answer = 'Y';
	string cartItems[100] ;
	float cartPrices[100] ;
	int cartIndex = 0;
	float totalprice = 0 ;
	while(answer=='Y'){
		shop1.viewItems() ;
		cout << "Enter the name of the item you want to buy: " ;
		cin.ignore() ;
		getline(cin,cartItems[cartIndex]) ;
		cout << "Enter the price of this item: " ;
		cin >> cartPrices[cartIndex] ;
		totalprice += cartPrices[cartIndex] ;
		cartIndex ++ ;
		cout << "Do you want to continu Y|N ? " ;
		cin >> answer ;
	}
	cout << "Reciept" << endl ;
	for(int i=0;i<cartIndex;i++){
		cout << i+1 << ". " << cartItems[i] << "----" << cartPrices[i] << endl ;
	}
	cout << "Total Price : " << totalprice ;
}