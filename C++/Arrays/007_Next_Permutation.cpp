/*
Problem: https://leetcode.com/problems/next-permutation/

Idea:

Step1, from right to left, find the first number which not increase in a ascending order. In this case which is 3.
Step2, here we can have two situations:

We cannot find the number, all the numbers increasing in a ascending order. This means this permutation is the last permutation, we need to rotate back to the first permutation. So we reverse the whole array, for example, 6,5,4,3,2,1 we turn it to 1,2,3,4,5,6.

We can find the number, then the next step, we will start from right most to leftward, try to find the first number which is larger than 3, in this case it is 4.
Then we swap 3 and 4, the list turn to 2,4,6,5,3,1.
Last, we reverse numbers on the right of 4, we finally get 2,4,1,3,5,6.

*/



#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


vector<int> nextPermutation(vector<int>& nums) {
  int len = nums.size();
  int p=-1;// pointer to track indexes, if no value found smaller than next value, it will always be -1
  int pv; // pointer value

  for(int i=len-2; i>=0; i--){
    if(nums[i]<nums[i+1]){
      p=i;
      pv=nums[i];
      break;
    }
  }

  // if array already in decreasing order, just reverse the array
  if(p==-1){
    int s=0, e = len-1;
    while(s<e){
      int temp = nums[s];
      nums[s] = nums[e];
      nums[e] = temp;
      ++s;
      --e;
    }
    return nums;
  }

  for(int i=len-1; i>=0; i--){
    if(nums[i] > pv){
      int temp = nums[p];
      nums[p] = nums[i];
      nums[i] = temp;
      break;
    }
  }
  int s=p+1,e=len-1;
  while(s<e){
    int temp = nums[s];
    nums[s] = nums[e];
    nums[e] = temp;
    ++s;
    --e;
  }
  
  return nums;
}


int main()
{
  
  vector<int> myarr1 {1,2,3};
  //vector<int> myarr1 {3,2,1};
  //vector<int> myarr1 {1,1,5};
  
  vector<int> ans = nextPermutation(myarr1);
    
  for(int x:ans){
    cout << x << " ";
  }
  cout <<endl;
    
    return 0;
}


// Runtime error


//Another solution
// Builtin library

/*
https://leetcode.com/problems/next-permutation/
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
  
  vector<int> myarr1 {1,2,3};
  //vector<int> myarr1 {3,2,1};
  //vector<int> myarr1 {1,1,5};
  
  next_permutation(begin(myarr1), end(myarr1));  
  for(int x:myarr1){
    cout << x << " ";
  }
  cout <<endl;
    
    return 0;
}



// Another solution, similar to first one with little extra condition


/*
https://leetcode.com/problems/next-permutation/
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


vector<int> nextPermutation(vector<int>& nums) {
  int i = nums.size() - 1, k = i, tmp;
    while (i > 0 && nums[i-1] >= nums[i])
        i--;
    for (int j=i; j<k; j++, k--)
        tmp = nums[j], nums[j] = nums[k], nums[k] = tmp;
    if (i > 0) {
        k = i--;
        while (nums[k] <= nums[i])
            k++;
        tmp = nums[i], nums[i] = nums[k], nums[k] = tmp;
    }
  return nums;
}


int main()
{
  
  vector<int> myarr1 {1,2,3};
  //vector<int> myarr1 {3,2,1};
  //vector<int> myarr1 {1,1,5};
  
  vector<int> ans = nextPermutation(myarr1);
    
  for(int x:ans){
    cout << x << " ";
  }
  cout <<endl;
    
    return 0;
}



// Using is_sorted_until library


/*
https://leetcode.com/problems/next-permutation/
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


vector<int> nextPermutation(vector<int>& nums) {
    auto i = is_sorted_until(nums.rbegin(), nums.rend());
    if (i != nums.rend())
        swap(*i, *upper_bound(nums.rbegin(), i, *i));
    reverse(nums.rbegin(), i);
    return nums;
}


int main()
{
  
  vector<int> myarr1 {1,2,3};
  //vector<int> myarr1 {3,2,1};
  //vector<int> myarr1 {1,1,5};
  
  vector<int> ans = nextPermutation(myarr1);
    
  for(int x:ans){
    cout << x << " ";
  }
  cout <<endl;
    
    return 0;
}
