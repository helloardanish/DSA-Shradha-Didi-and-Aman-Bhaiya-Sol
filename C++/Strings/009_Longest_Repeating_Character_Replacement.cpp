// Longest Repeating Character Replacement

/*

https://leetcode.com/problems/longest-repeating-character-replacement/

*/


// Using sliding window technique

class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.size(); int ret = 0;
        vector<int> count(26, 0);
        int start = 0; int end = 0; int localMaxFreq = 0; 
        for(; end<size; end++){
            count[s[end]-'A'] += 1;
            localMaxFreq = max(localMaxFreq, count[s[end]-'A']);
            if((end-start+1)-localMaxFreq > k) {
                ret = max(ret, (end-start));
                count[s[start]-'A'] -= 1;
                start += 1;
                localMaxFreq = *(max_element(count.begin(), count.end()));
            }
        }
        return max(ret, end-start);
    }
};




// Track only max val


class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.size(); int ret = 0;
        vector<int> count(26, 0);
        int start = 0; int end = 0; int globalMaxFreq = 0; 
        for(; end<size; end++){
            count[s[end]-'A'] += 1;
            globalMaxFreq = max(globalMaxFreq, count[s[end]-'A']);
            if((end-start+1)-globalMaxFreq > k) {
                ret = max(ret, (end-start));
                count[s[start]-'A'] -= 1;
                start += 1;
            }
        }
        return max(ret, end-start);
    }
};




// or concise code 


class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.size(), i = 0, j = 0, same = 0;
        vector<int> m(128, 0);
        while(j < size) {
            same = max(same, ++m[s[j++]]); // Update table, count for maximum character in window, and increment right bound
            if(j - i - same > k) --m[s[i++]]; // If criteria is not satisfied, increment left bound, update table
        }
        return j-i;
    }
};
