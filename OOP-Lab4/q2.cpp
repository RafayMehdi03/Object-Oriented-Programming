#include <iostream>
using namespace std ;
class Book{
	int ID ;
	string title ;
	string author ;
	bool availibility ;
  public:
  	Book(){
  		availibility = true ;
	  }
	Book(int id,string ptitle,string pAuthor,bool available){
		ID = id ;
		title = ptitle ;
		author = pAuthor ;
		availibility = available ;
	}
	void setId(int id){
		ID = id ;
	}
	void setTitle(string t){
		title = t ;
	}
	void setAuthor(string a){
		author = a ;
	}
	void setAvailibility(bool av){
		availibility = av ;
	}
	int getId(){
		return ID ;
    }
	string getTitle(){
		return title ;
	}
	string getAuthor(){
		return author ;
	}
	bool getAvailibility(){
		return availibility ;
	}
	
};
class Library{ 
	    Book *Books = new Book[100] ;
	    int currentIndex = 0 ;
	    bool duplicate ;
	public:
		void addBook(int id,string ptitle,string pAuthor,bool availible){
			duplicate = false ;
			for(int i=0;i<currentIndex-1;i++){
				if(Books[i].getId()==id){
					duplicate = true ;
					break ;
				}
			}
			if(!duplicate){
			    Books[currentIndex].setId(id) ;
			    Books[currentIndex].setTitle(ptitle) ;
			    Books[currentIndex].setAuthor(pAuthor) ;
			    Books[currentIndex].setAvailibility(availible) ;
			    cout << "Book stored" << endl ;
			    currentIndex ++ ;
		    }
		    else{
		    	cout << "A book with this ID already exist" << endl ;
			}
		}
		void borrowBook(int id){
            int i ;
			for(i=0;i<100;i++){
				if(Books[i].getId()==id){
					Books[i].setAvailibility(false) ;
					cout <<"Book With Title: "<< Books[i].getTitle() << " is borrowed"<< endl ;
					break ;
				}
			}			
		}
		void returnBook(int id){
            int i ;
			for(i=0;i<100;i++){
				if(Books[i].getId()==id){
					Books[i].setAvailibility(true) ;
					cout << "Book With Title: "<< Books[i].getTitle() << " is returned" << endl ;
					break ;
				}
			}			
		}
		void displayBooks(){
			int i ;
			for(i=0;i<currentIndex;i++){
				cout << endl <<"Book " << i+1 << endl << "Title: " << Books[i].getTitle() << endl << "ID: " << Books[i].getId() << 
				endl << "Author: " << Books[i].getAuthor() << endl << "Availibility: " << Books[i].getAvailibility() << endl ;
			}
		}
        ~Library(){
        	delete []Books ;
		}
};
int main(){
	Library FASTlibrary ;
	FASTlibrary.addBook(1,"Harry Potter","Richard",true) ;
	FASTlibrary.addBook(2,"Diary Of The Wimpy Kid","William",true) ;
	FASTlibrary.addBook(3,"1984","George",true) ;
	FASTlibrary.addBook(4,"Calculus","Anton",true) ;
	FASTlibrary.borrowBook(3) ;
	FASTlibrary.borrowBook(4) ;
	FASTlibrary.returnBook(4) ;
	FASTlibrary.displayBooks() ;
}