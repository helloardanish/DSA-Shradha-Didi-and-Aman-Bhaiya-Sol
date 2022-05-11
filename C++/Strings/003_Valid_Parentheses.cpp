/*

https://leetcode.com/problems/valid-parentheses/

*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> charst;
        
        for(char ch:s){
            if(ch=='(' || ch=='{' || ch=='['){
                charst.push(ch);
            }else{
                if(charst.empty() || (charst.top()=='(' && ch!=')') || (charst.top()=='{' && ch!='}') || (charst.top()=='[' && ch!=']')){
                    return false;
                }
                charst.pop();
            }
        }
      /*
        if(charst.empty()){
          return true;
        }else{
          return false;
        }
        */
      // instead of above code we can simply return charst.empty()
      return charst.empty();
    }
};


