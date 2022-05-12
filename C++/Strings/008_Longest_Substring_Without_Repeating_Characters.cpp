// First solution, TLE.

/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;

int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        unordered_set<char> us;
        int l=0;
        int len = s.length();
        int max=1;
        int currmax=0;
        while(l<len){
            int index=l;
            while(index<len){
                if(us.find(s[index])==us.end()){
                    us.insert(s[index]);
                    ++currmax;
                    if(currmax>max){
                        max=currmax;
                    }
                }else{
                    us.clear();
                    currmax=1;
                    us.insert(s[index]);
                }
                ++index;
            }
            cout << "for index " << l << " , max is " << max <<endl;
            currmax=0;
            us.clear();
            ++l;
        }
        
        return max;
    }
int main()
{
  

  string s = "abcdefgahijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
  //string s = "asjrgapa";

  cout << "Length of input is " << s.length();
  
  int ans = lengthOfLongestSubstring(s); 
  cout <<ans << endl;
  return 0;
}


// check test cases here = https://leetcode.com/submissions/detail/697963981/testcase/










// I also coded out this solution but it wasn't correct. Use this for logic only, somewhere it might be useful :p.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        unordered_set<char> us;
        int max=1;
        int currmax=0;
        for(char ch:s){
            if(us.find(ch)==us.end()){
                us.insert(ch);
                ++currmax;
                if(currmax>max){
                    max=currmax;
                }
            }else{
                us.clear();
                currmax=1;
                us.insert(ch);
            }
        }
        return max;
    }
};


// failed for input dvdf >> output 2, expected 3.

