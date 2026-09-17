#include <bits/stdc++.h>
using namespace std;

int sumofn(int x){
    if(x==0)return 0;
    int summ=0;
    summ=x;
    return summ+sumofn(x-1);
}
int main(){
    cout<<sumofn(10);
    

}


