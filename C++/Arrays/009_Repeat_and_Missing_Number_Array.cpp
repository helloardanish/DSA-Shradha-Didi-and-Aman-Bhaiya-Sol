/*
https://www.interviewbit.com/problems/repeat-and-missing-number-array/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct Pair{
  int repeat;
  int missing;
};

Pair repeatMissingNumber(vector<int>& nums) {
  struct Pair pair;
  int len = nums.size();
  int expectsum = (len*(len+1))/2;
  int arraysum = 0;

  // calculate sum of array
  for(int i=0; i<len; i++){
    arraysum+=nums[i];
  }
  unordered_set<int> numset;
  for(int i=0; i<len; i++){
    if(numset.find(nums[i])==numset.end()){
      numset.insert(nums[i]);
    }else{
      pair.repeat = nums[i];
      break;
    }
  }

  pair.missing = expectsum-arraysum+pair.repeat;
  
  return pair;
}


int main()
{
  
  //vector<int> myarr1 {7,1,5,3,6,4};
  //vector<int> myarr1 {3, 1, 2, 5, 3};
  //vector<int> myarr1 {1,1,2,3,4};
  vector<int> myarr1 {1,2,3,4,2,6,7};
  
  Pair ans = repeatMissingNumber(myarr1);
    
  cout<< "Repeat : "<< ans.repeat << ", Missing : " << ans.missing<<endl;
    
    return 0;
}

// Using extra O(n) space here for unordered_set but you can solve using bit manipulation(space will be O(1) as mentioned in the question). I haven't revised that so using this solution.
