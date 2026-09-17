#include <bits/stdc++.h>
using namespace std;

int sumofdigitn(int x){
    if(x==0)return 0;
    int num=0;
    num+=x%10;
    return num+sumofdigitn(x/10);   
}
int main(){
    cout<<sumofdigitn(123);
}


