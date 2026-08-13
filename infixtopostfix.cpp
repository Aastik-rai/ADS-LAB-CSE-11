#include <bits/stdc++.h>
using namespace std;
 int precedence(char op){
    if(op=='+'||op=='-'){
        return 1;
    }
    if(op=='*'||op=='/'){
        return 2;
    }
    if(op=='^'){
        return 3;
    }
    return  0;

}

 string infixtopostfix(string s){
    int i=0;
    stack<int>st;
    string ans="";
    int n=s.size();

    while(i<n){
        if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);   
        }
        else if(s[i]==')'){
            while(!st.empty()&&st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty()&&precedence(s[i])<=precedence(st.top())){
                ans+=st.top();
                st.pop();

            }
            st.push(s[i]);
        }
        i++;

    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;

}
int main(){
    string s="(A+B/C+D*(E-F)^G)";
    string sol=infixtopostfix(s);
    for(int i=0;i<sol.size();i++){
        cout<<sol[i]<<" ";

    }
    
    
}