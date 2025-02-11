#include <iostream>
using namespace std ;
int main(){
    int num,i,j ;
    int *arr ;
    cout << "Enter the number of elements: " ;
    cin >> num ;
    arr = new int[num] ;
    for(i=0;i<num;i++){
        cout << "Enter element " << i+1 << ": " ;
        cin >> arr[i] ;
    }
    for(i=0;i<num-1;i++){
        if(arr[i]!='\0'){
        for(j=i+1;j<num;j++){
            if(arr[i]==arr[j]){
                arr[j] = '\0' ;
            }
        }
        }
    }
    cout << "Unique elements in the array are: " ;
    for(i=0;i<num;i++){
        if(arr[i]!='\0'){
            cout << arr[i] << " " ;
        }
    }
}