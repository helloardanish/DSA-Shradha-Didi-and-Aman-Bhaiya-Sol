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


// I used extra space for storing set of dictionary using unordered map.


class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> charsetmap = {
          {'(' , ')'},
          {'{' , '}'},
          {'[' , ']'},
        };

        stack<char> charst;
        
        for(char ch:s){
            if(!(charsetmap.find(ch) == charsetmap.end())){
                charst.push(ch);
            }else{
                if(charst.empty() || charsetmap[charst.top()]!=ch){
                    return false;
                }
                charst.pop();
            }
        }
        return charst.empty();
    }
};


// Though this solution isn't optimal as the first one but when we'll have a large of set of characters we can prefer this code. We don't have code out like 10 condition.
// Hope you understand it :)

