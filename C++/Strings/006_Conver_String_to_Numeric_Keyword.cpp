/*
https://www.geeksforgeeks.org/convert-sentence-equivalent-mobile-numeric-keypad-sequence/
*/


#include <iostream>
#include <vector>

using namespace std;

string sentenceToNumKeypad(string str){
  string ans="";
  vector<string> numkeyarr = {
    "2", "22", "222",
    "3", "33", "333",
    "4", "44", "444",
    "5", "55", "555",
    "6", "66", "666",
    "7", "77", "777", "7777",
    "8", "88", "888",
    "9", "99", "999", "9999"
  };

  if(str.length()==0){
    return ans;
  }
  
  int len = str.length();
  for(int i=0; i<str.length(); i++){
    if(str[i]==' '){
      ans+='0';
    }else{
      int index = str[i]-'A';
      ans+=numkeyarr[index];
    }
  }
  return ans;
}

int main()
{
  
  //vector<string> s = {"flower","flow","flight"};

  //string s = "GEEKSFORGEEKS";
  string s = "HELLO WORLD";
  
  
  string ans = sentenceToNumKeypad(s); 
  cout <<ans << endl;
  return 0;
}
