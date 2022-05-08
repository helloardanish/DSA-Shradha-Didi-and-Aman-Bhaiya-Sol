#include <bits/stdc++.h>

using namespace std;
struct Pair{
  int min;
  int max;
};


Pair getMinMax(vector<int> arr){
  struct Pair pair;

  if(arr.size()==1){
    pair.min=arr[0];
    pair.max=arr.at(0);
  }

  if(arr[0]>arr[1]){
    pair.min = arr[1];
    pair.max = arr[0];
  }else{
    pair.min = arr[0];
    pair.max = arr[1];
  }

  int i;
  for(i=2; i<arr.size(); ++i){
    if(arr[i]>pair.max){
      pair.max = arr[i];
    }else if(arr[i]<pair.min){
      pair.min = arr[i];
    }
  }
  
  return pair;
}

int main()
{
    vector<int> myarr1 {2,3,5,4,100,6,2,3,3};
    //vector<int> myarr1 {2,3,4,1,4,5};
    

    struct Pair ans = getMinMax(myarr1);
    
    cout<<"Min : " << ans.min << ", Max : " << ans.max<<endl;
     
    return 0;
}
