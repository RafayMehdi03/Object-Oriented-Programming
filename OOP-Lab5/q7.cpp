#include <iostream>
using namespace std ;
class MenuItems{
	string foodName ;
	float foodPrice ;
  public:
    MenuItems():foodName(""),foodPrice(0) {}
  	MenuItems(string name,float price):foodName(name),foodPrice(price) {}
  	string getName(){
  		return foodName ;
	  }
	float getPrice(){
		return foodPrice ;
	}
};
class Menu{
	MenuItems Items[5] ;
	int itemCount = 0 ; 
  public:
	void addItem(MenuItems item){
		if(itemCount<=5){
		Items[itemCount++] = item ;
		cout << "Item Added" << endl ;
	    }
	    else{
	    cout << "Item limit reached" << endl ;
		}
	}
	void removeItem(int index){
		if(itemCount>0&&index>0&&index<6){
			for(int j=index-1;j<4;j++){
				Items[j] = Items[j+1] ;
			}
			itemCount -- ;
			cout << "Item Removed" << endl ;
		}
		else{
			cout << "Wrong Index or Insufficeint Items" << endl ;
		}
	}
	void displayMenu(){
		for(int i=0;i<itemCount;i++){
			cout << i+1 << ".  Item Name: " << Items[i].getName() << "---Food price: " << Items[i].getPrice() << endl ;
		}
	}
	MenuItems getItem(int i){
		return Items[i] ;
	}
};
class Payment{
	float Bill ;
  public:
  	Payment():Bill(0) {}
  	void setBill(float amount){
  	    Bill = amount ;
  	}
  	float getBill(){
	  return Bill ;
	}
};
class Order{
	MenuItems item[5] ;
	int itemCount ;
	Payment p ;
  public:
    Order():itemCount(0){}
  	Order(MenuItems arr[5],int Count){
  	    float amount = 0 ;
  	    itemCount = Count ;
  		for(int i=0;i<Count;i++){
  			item[i] = arr[i] ;
  			amount += item[i].getPrice() ;
		  }
		p.setBill(amount) ;
	}
	void displayOrderDetails(){
		cout << "Order Items" << endl ;
		for(int i=0;i<itemCount;i++){
			cout << item[i].getName() << "     " << item[i].getPrice() << endl ;
	    }
	    cout << "Total Bill: " << p.getBill() ;
	}
};
class RestaurantOrderingSystem{
	Menu menu ;
	Order orders[10] ;
	int orderCount ;
  public:
  	RestaurantOrderingSystem(Menu m){
  	        menu = m ;
	}
  	void makeOrder(){
  		menu.displayMenu() ;
  		MenuItems list[5] ;
  		int count,itemNum ;
  		cout << "How many items do you want to order: " ;
  		cin >> count ;
  		for(int i=0;i<count;i++){
  			cout << "Enter The Number Of The Item You Want To Order: " ;
  			cin >> itemNum ;
  			list[i] = menu.getItem(itemNum-1) ;
		}
		orders[orderCount] = Order(list,count) ; 
		cout << "Order Placed" << endl ;
		orders[orderCount].displayOrderDetails();
	}
};
int main(){
    Menu m1;
	MenuItems i1("Handi",350);
	MenuItems i2("Karahi",450);
	MenuItems i3("Nihari",300);
	MenuItems i4("Biryani",400);
	MenuItems i5("Mandi",740);
	m1.addItem(i1);
	m1.addItem(i2);
	m1.addItem(i3);
	m1.addItem(i4);
	m1.addItem(i5);
	RestaurantOrderingSystem r1(m1);
	r1.makeOrder();
}
