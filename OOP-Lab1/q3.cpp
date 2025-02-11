#include <iostream>
using namespace std;
int main(){
	int length,target,i,j,found=0 ;
	cout << "enter the length of array: " ;
	cin >> length ;
	int arr[length] ;
	for(i=0;i<length;i++){
		cout<<"Enter element "<<i+1<<endl ;
		cin>>arr[i] ;
	}
	int result[2] ;
	cout<<"enter target: " ;
	cin >> target ;
	for(i=0;i<length-1;i++){
		for(j=i+1;j<length;j++){
			if((arr[i]+arr[j])==target){
				result[0] = i ;
				result[1] = j ;
				found = 1 ;
				break;
			}
		}
		if(found==1){
			break ;
		}
	}
	if(found==1){
		cout<<"["<<result[0]<<","<<result[1]<<"]"<<endl ;
	}
	else{
		cout<<"No Solution Found"<<endl ;
	}
}