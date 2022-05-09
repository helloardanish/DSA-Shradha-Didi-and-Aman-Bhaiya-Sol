/*
https://leetcode.com/problems/product-of-array-except-self/
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
  vector<int> lhs(nums.size(),1);
  vector<int> rhs(nums.size(),1);

  for(int i=1; i<nums.size();i++){
    lhs[i] = lhs[i-1]*nums[i-1];
  }

  for(int i=nums.size()-1; i>=1; i--){
    rhs[i-1] = rhs[i]*nums[i];
  }

  for(int i=0; i<nums.size(); i++){
    nums[i] = lhs[i] *rhs[i];
  }
  return nums;
}
int main()
{
  
  //vector<int> myarr1 {7,1,5,3,6,4};
  //vector<int> myarr1 {3, 1, 2, 5, 3};
  //vector<int> myarr1 {0,1,0,2,1,0,1,3,2,1,2,1};
  vector<int> myarr1 {1,2,3,4};

  
  vector<int> ans = productExceptSelf(myarr1);
  for(int x:ans){
    cout << x << " ";
  }
  cout << endl;
  return 0;
}




// minimised using single extra array space


/*
https://leetcode.com/problems/product-of-array-except-self/
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int>res(nums.size(), 1);
    for(int i = 1; i < nums.size(); i++)
        res[i] = res[i-1] * nums[i-1];
    int right = 1;
    for(int i = nums.size() - 1; i >= 0; i--){
        res[i] *= right;
        right *= nums[i];
    }
    return res;
}
int main()
{
  
  //vector<int> myarr1 {7,1,5,3,6,4};
  //vector<int> myarr1 {3, 1, 2, 5, 3};
  //vector<int> myarr1 {0,1,0,2,1,0,1,3,2,1,2,1};
  vector<int> myarr1 {1,2,3,4};

  
  vector<int> ans = productExceptSelf(myarr1);
  for(int x:ans){
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
