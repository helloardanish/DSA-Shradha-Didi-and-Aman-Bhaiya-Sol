/*
https://leetcode.com/problems/valid-anagram/
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        
        unordered_map<char, int> charfreq;
        
        for(int i=0; i<s.length(); i++){
            charfreq[s[i]]++;
            charfreq[t[i]]--;
        }
        
        unordered_map<char, int>::iterator it = charfreq.begin();
        while(it!=charfreq.end()){
            if(it->second!=0){
                return false;
            }
            ++it;
        }
        
        return true;        
    }
};
