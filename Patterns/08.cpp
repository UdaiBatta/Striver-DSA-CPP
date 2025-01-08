#include<iostream>
using namespace std;
void pattern7(int n) {
    // Write your code here.
    for(int i = 0;i<n;i++){
        //Space
        for(int j=0;j<i;j++){
        cout<<" ";
        }
        //Star
        for(int j = 0;j<2*n-(2*i+1);j++){
            cout<<"*";
        }
        
        //Space 
        for(int j=0;j<i;j++){
            cout<<" ";
    }
    cout<<endl;
}
}

int main(){
    int t;
    cin>> t;
    for(int i = 0;i<t;i++){
        int n;
        cin>>n;
         pattern7(n);
    }
}