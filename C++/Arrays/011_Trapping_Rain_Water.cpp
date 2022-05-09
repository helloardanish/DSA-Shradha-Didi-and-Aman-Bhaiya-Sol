/*

Idea:

For each element in the array, we find the maximum level of water it can trap after the rain, 
which is equal to the minimum of maximum height of bars on both the sides minus its own height.

*/

/*
https://leetcode.com/problems/trapping-rain-water/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) {
  int ans=0;
  int len=height.size();
  int currmin;
  int left_max, right_max;
  
  for(int i=0; i<len; ++i){
    //set left max and right max to 0
    left_max=0, right_max=0;

    // find left max from the beginning
    for(int j=i; j>=0; j--){
      if(height[j]>left_max){
        left_max=height[j];
      }
    }

    //find right max till the end
    for(int j=i; j<len; j++){
      if(height[j]>right_max){
        right_max=height[j];
      }
    }

    // find minimum height
    if(left_max<right_max){
      currmin=left_max;
    }else{
      currmin=right_max;
    }

    ans+=currmin-height[i];
    
  }
  
  
  return ans;
}


int main()
{
  
  //vector<int> myarr1 {7,1,5,3,6,4};
  //vector<int> myarr1 {3, 1, 2, 5, 3};
  //vector<int> myarr1 {0,1,0,2,1,0,1,3,2,1,2,1};
  vector<int> myarr1 {4,2,0,3,2,5};

  
  int ans = trap(myarr1);

  cout << ans << endl;
    return 0;
}

// TLE : Time limit exceeded



// We can use double pointer concepts


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& height)
{
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        }
        else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
}

int main()
{
  
  //vector<int> myarr1 {7,1,5,3,6,4};
  //vector<int> myarr1 {3, 1, 2, 5, 3};
  //vector<int> myarr1 {0,1,0,2,1,0,1,3,2,1,2,1};
  vector<int> myarr1 {4,2,0,3,2,5};

  
  int ans = trap(myarr1);

  cout << ans << endl;
    return 0;
}


/*
Check other solutions

Here : https://leetcode.com/problems/trapping-rain-water/solution/

*/
