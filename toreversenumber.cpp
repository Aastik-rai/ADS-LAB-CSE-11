#include <bits/stdc++.h>
using namespace std;

int reverseofn(int x,int rev=0){
    
    if(x==0)return rev;
    rev=rev * 10 + x % 10;
    return reverseofn(x/10,rev);
    

}
int main(){
    cout<<reverseofn(123);
}


