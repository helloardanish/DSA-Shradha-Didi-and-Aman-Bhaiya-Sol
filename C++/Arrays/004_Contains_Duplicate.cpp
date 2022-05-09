/*
https://leetcode.com/problems/contains-duplicate/
*/


#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;

bool containsDuplicate(vector<int>& nums) {
  unordered_set<int> numset;
  for(int i=0; i<nums.size(); i++){
    if(numset.find(nums[i])==numset.end()){
      numset.insert(nums[i]);
    }else{
      return true;
    }
  }
  return false;
}
int main()
{
    //vector<int> myarr1 {1,2,3,1};
    //vector<int> myarr1 {1,1,1,3,3,4,3,2,4,2};
    vector<int> myarr1 {2,3,4,1,4,5};
    

    bool ans = containsDuplicate(myarr1);
    cout << boolalpha << ans<<endl;
  /*
    for(auto x:ans){
      cout << x << " ";
    }*/
  
    return 0;
}


// Above time is O(n), Space is O(n)


// another method sort and check with previous value

/*
https://leetcode.com/problems/contains-duplicate/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>


using namespace std;

bool containsDuplicate(vector<int>& nums) {
  if(nums.size()==1){
    return false;
  }
  sort(nums.begin(), nums.end());
  for(int i=1; i<nums.size(); i++){
    if(nums[i]==nums[i-1]){
      return true;
    }
  }
  return false;
}
int main()
{
    //vector<int> myarr1 {1,2,3,1};
    vector<int> myarr1 {1,1,1,3,3,4,3,2,4,2};
    //vector<int> myarr1 {2,3,4,1,4,5};
    

    bool ans = containsDuplicate(myarr1);
    cout << boolalpha << ans<<endl;
  /*
    for(auto x:ans){
      cout << x << " ";
    }*/
  
    return 0;
}



// Time O(nlongn) for sorting, Space O(1)
