/*
https://leetcode.com/problems/valid-palindrome/
*/
// Using two pointer

class Solution {
public:
    bool isPalindrome(string s) {
        int l=0;
        int r = s.length()-1;
        
        while(l<r){
            
            // if left get greater than right, it will overflowed so using l<r condition here as well
            while(!isalnum(s[l]) && l<r){
                ++l;
            }
            while(!isalnum(s[r]) && l<r){
                --r;
            }
            if(toupper(s[l])!=toupper(s[r])){
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};
