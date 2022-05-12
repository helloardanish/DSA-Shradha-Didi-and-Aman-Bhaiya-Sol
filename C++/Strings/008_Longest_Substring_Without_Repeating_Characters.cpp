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





// Accepted, found from people comments. It is hard to get it fast but if you run below program and debug, 
//you'll get the idea how it works. I've put a print so you don't have to do that. Just run on local or online IDE.


/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

int lengthOfLongestSubstring(string s) {
        int n = s.length();
        
        unordered_map<int, int>m;
        int c = 0, maxlen = -1;
        //pwwkew
        for (int i = 0; i < n; i++) {
            cout << "i is " << i << endl;
            if (m.find(s[i]) == m.end() || (i - m[s[i]] > c)){
                cout << "Inside if ch : "<<s[i] << endl;
                c++;
              }else {
                cout << "Inside else ch : "<<s[i] << endl;
                maxlen = max(maxlen, c);
                c = i-m[s[i]];
            }
            m[s[i]] = i;
            cout << "c: "<< c << ", maxlen " << maxlen << ", ch : " << s[i] << ", val: "<< m[s[i]] << endl;
          cout << "\n\n\n" << endl;
        }
        
        return max(maxlen, c);
    }
int main()
{
  

  //string s = "abcabcbb";
  string s = "pwwkew";
  
  int ans = lengthOfLongestSubstring(s); 
  cout <<ans << endl;
  return 0;
}



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

