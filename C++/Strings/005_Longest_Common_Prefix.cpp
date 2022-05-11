/*
https://leetcode.com/problems/longest-common-prefix/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string longestCommonPrefix(vector<string> strs) {
        int len = strs.size();
        string ans="";
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[len-1];

        for(int i=0; i<first.size(); i++){
          if(first[i]==last[i]){
            ans+=first[i];
          }else{
            break;
          }
        }
      return ans;
    }

int main()
{
  
  //vector<string> s = {"flower","flow","flight"};

  vector<string> s = {"dog","racecar","car"};
  
  string ans = longestCommonPrefix(s); 
  cout <<ans << endl;
  return 0;
}


// If we don't use sort we have to compare every next array element with last prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string res = strs[0];
        for(auto s: strs) res = match(res, s);
        return res;
    }
    
    string match(const string& pre, const string& s){
        int len = min(pre.size(), s.size());
        for(int i=0; i < len; i++) if(s[i] != pre[i]) break;
        return pre.substr(0, i);
    }
};
