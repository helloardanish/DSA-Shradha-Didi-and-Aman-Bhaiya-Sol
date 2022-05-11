/*
https://practice.geeksforgeeks.org/problems/consecutive-elements2306/1
*/


// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends

class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        // code here.
        char prev = S[0];
        string ans;
        ans += S[0];
        for(int i=1; i<S.length(); i++){
            if(S[i]!=prev){
                prev = S[i];
                ans += S[i];
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 



  // } Driver Code Ends
