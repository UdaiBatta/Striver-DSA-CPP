#include<iostream>
using namespace std;
void pattern13(int n) {  
    int start = 1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=i;j++){
            cout<<start<<" ";
            start = start + 1;
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
         pattern13(n);
    }
}