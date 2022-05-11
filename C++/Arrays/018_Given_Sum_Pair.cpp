/*
https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/
*/

#include <iostream>
#include <vector>

using namespace std;

bool ifPairExist(vector<int>& height, int target) {
  int len=height.size();
  int pivot;
  for(int i=0; i<height.size(); i++){
    if(height[i]>height[i+1]){
      pivot =i;
      break;
    }
  }

  int l=(pivot+1)%len;
  int r = pivot;
  while(l != r){
    if((height[l]+height[r])==target){
      return true;
    }
    if((height[l]+height[r])<target){
      l = (l+1)%len;
    }else{
      r=(len+r-1)%len;
    }
  }
  return false;
}
int main()
{
  
  vector<int> myarr1 {11, 15, 6, 8, 9, 10};
  //vector<int> myarr1 {4,5,6,7,0,1,2};
  int target = 18;

  
  bool ans = ifPairExist(myarr1, target); 
  cout <<boolalpha << ans << endl;
  return 0;
}
