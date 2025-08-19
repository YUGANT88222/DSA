#include <iostream> 
using namespace std; 
int main() { 
float arr[3][7]; 
for(int i=0;i<3;i++){ 
cout<<"city"<<i+1<<"\n"; 
for(int j=0;j<7;j++){ 
cout<<"enter temp "<<j+1<<":"; 
cin>>arr[i][j]; 
} 
cout<<"\n"; 
} 
cout<<"Temperature Tracker B24CE1018 \n"; 
cout<<"cities day1 day2 day3 day4 day5 day6 day7 average \n"; 
for(int i=0;i<3;i++){ 
cout<<"----------------------------------------------------------------------------\n"; cout<<"city"<<i+1; 
float avg =0; 
for(int j=0;j<7;j++){ 
cout<<" "<<arr[i][j]; 
avg+=arr[i][j]; 
} 
cout<<" "<<avg/7; 
cout<<"\n"; 
} 
return 0; 
}
