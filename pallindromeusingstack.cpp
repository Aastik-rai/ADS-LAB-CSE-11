#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (isalnum(s[i])) {
                st.push(tolower(s[i]));
            }
        }
        for (int i = 0; i < n; i++) {
            if (!isalnum(s[i])) {
                continue;
            }
            if (tolower(s[i]) != st.top()) {
                return false;
            }
            st.pop();
        }
        return true;
    }
};
int main() {
    string s = "A man, a plan, a canal: Panama";

    Solution obj;
    bool ans = obj.isPalindrome(s); 
    if(ans==1){
        cout<<"true";
    }
    else cout<<"false";


    return 0;
}