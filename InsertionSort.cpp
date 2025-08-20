#include <iostream>
#include <string>
using namespace std;




int input(int array[] , int size){
   for(int i = 0; i < size ; i++){
       int number = array[i] ;
       int j = i - 1 ;
     
    while(j >= 0 && array[j] > number){
        array[j + 1] = array[j];
        j--;
    }
    array[j + 1] = number;
   }
   return 0;
}
int display(int array[] , int size){
   for(int i = 0 ; i<size ; i++){
       cout<<array[i]<<" ";
   }
   cout<<""<<endl;
 




   return 0;
}
int main(){
   int size;
   int array[100];
   cout<<"Enter the size of the cards in Hand:";
   cin>>size;
   cout<<"Enter the cards number (enter 1 for ace , 11 for jack , 12 for queen , 13 for king): "<<endl;
       for (int i = 0; i < size; i++) {
       cin >> array[i];
   }
   display(array , size);
   input(array , size);
   cout<<"sorted Deck of Cards"<<" "<<endl;
   display(array , size);
   return 0 ;
}
