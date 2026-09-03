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

 string infixtoprefix(string s){
    reverse(s.begin(),s.end());
    int i=0;
    stack<int>st;
    string ans="";
    int n=s.size();
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(')
            s[i] = ')';
        else if(s[i] == ')')
            s[i] = '(';
    }

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
        else if(s[i]=='^'){
            while(!st.empty()&&precedence(s[i])<=precedence(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);

        } 
            
        else{
            while(!st.empty()&&precedence(s[i])<precedence(st.top())){
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
    reverse(ans.begin(),ans.end());
    return ans;

}
int main(){
    string s="A/B*C-D+E/F/(G+H)";
    string sol=infixtoprefix(s);
    for(int i=0;i<sol.size();i++){
        cout<<sol[i]<<" ";

    }
    
