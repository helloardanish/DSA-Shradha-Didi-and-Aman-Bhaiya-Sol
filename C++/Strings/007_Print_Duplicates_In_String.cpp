/*
https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/
*/

#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

string printDuplicates(string s){

  string ans; // we can also take array

  unordered_map<char, int> charfreqmap;
  for(int i=0; i<s.length(); i++){
    charfreqmap[s[i]]++;
  }

  for(auto x:charfreqmap){
    if(x.second>1){
      ans+=x.first;
    }
  }
  return ans;
}

int main()
{
  
  //vector<string> s = {"flower","flow","flight"};

  //string s = "GEEKSFORGEEKS";
  string s = "geeksforgeeks";
  
  
  string ans = printDuplicates(s); 
  cout <<ans << endl;
  return 0;
}
