/*
https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
  int len = nums.size();
  sort(nums.begin(), nums.end());
  
  int index = len-2;
  int klarge;
  
  if(k==1){
    return nums[len-1];
  }
  --k;// last element is always greater  after sort. Don't compare just decrement  index
  
  while(index>=0 && k>0){
    if(nums[index] < nums[index+1]){
      klarge = nums[index];
      --k;
    }
    --index;
  }
  return klarge;
}
int main()
{
  
  //vector<int> myarr1 {7,1,5,3,6,4};
  //vector<int> myarr1 {3, 1, 2, 5, 3};
  vector<int> myarr1 {3,2,3,1,2,4,5,5,6};
  //vector<int> myarr1 {1,2,3,4,2,6,7};
  int k=4;

  
  int ans = findKthLargest(myarr1,k);

  cout << ans << endl;
    return 0;
}



// Not correct.
// Mistake I did was I was returning distict 4th largest but it was supposed to be the 4 largest index in the sorted array
// Here is the implementation


/*
https://www.interviewbit.com/problems/repeat-and-missing-number-array/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
  sort(nums.begin(), nums.end());
  return (nums[nums.size()-k]);
}
int main()
{
  
  //vector<int> myarr1 {7,1,5,3,6,4};
  //vector<int> myarr1 {3, 1, 2, 5, 3};
  vector<int> myarr1 {3,2,3,1,2,4,5,5,6};
  //vector<int> myarr1 {1,2,3,4,2,6,7};
  int k=4;

  
  int ans = findKthLargest(myarr1,k);

  cout << ans << endl;
    return 0;
}



// Another solution
// Using priority queue

/*
https://www.interviewbit.com/problems/repeat-and-missing-number-array/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int findKthLargest(vector<int> nums, int k) {
  priority_queue<int> pq;
  for(int i=0; i<nums.size();i++){
    pq.push(nums[i]);
  }
  
  while(k>1){
    pq.pop();
    --k;
  }
  return pq.top();
}
int main()
{
  
  //vector<int> myarr1 {7,1,5,3,6,4};
  //vector<int> myarr1 {3, 1, 2, 5, 3};
  vector<int> myarr1 {3,2,3,1,2,4,5,5,6};
  //vector<int> myarr1 {1,2,3,4,2,6,7};
  int k=4;

  
  int ans = findKthLargest(myarr1,k);

  cout << ans << endl;
    return 0;
}


// Using STL, built in two methods nth_element and partial_sort


// nth_element

/*
https://www.interviewbit.com/problems/repeat-and-missing-number-array/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findKthLargest(vector<int> nums, int k) {
  nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
  return nums[k - 1];
}
int main()
{
  
  //vector<int> myarr1 {7,1,5,3,6,4};
  //vector<int> myarr1 {3, 1, 2, 5, 3};
  vector<int> myarr1 {3,2,3,1,2,4,5,5,6};
  //vector<int> myarr1 {1,2,3,4,2,6,7};
  int k=4;

  
  int ans = findKthLargest(myarr1,k);

  cout << ans << endl;
    return 0;
}




// partial_sort

/*
https://www.interviewbit.com/problems/repeat-and-missing-number-array/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findKthLargest(vector<int> nums, int k) {
  partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
  return nums[k - 1];
}
int main()
{
  
  //vector<int> myarr1 {7,1,5,3,6,4};
  //vector<int> myarr1 {3, 1, 2, 5, 3};
  vector<int> myarr1 {3,2,3,1,2,4,5,5,6};
  //vector<int> myarr1 {1,2,3,4,2,6,7};
  int k=4;

  
  int ans = findKthLargest(myarr1,k);

  cout << ans << endl;
    return 0;
}
