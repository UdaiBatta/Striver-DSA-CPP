#include<bits/stdc++.h>
using namespace std;

void func(int i , int sum){
    if(i<1){
        cout<<sum<<endl;
        return;
    }
     func(i-1,sum+i);
}
int main(){
    int n= 3;
    func(n,0);
    return 0;
}