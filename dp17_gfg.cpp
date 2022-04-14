// Buying Vegetables 

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    int dp[100001][4];
public:
    int minCost(int n, vector<int> cost[]) {
        // code here
        for(int i=0;i<100001;i++){
            for(int j=0;j<4;j++){
                dp[i][j]=INT_MAX;
            }
        }
        for(int i=0;i<3;i++){
            dp[0][i]=cost[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(k!=j){
                dp[i][j]=min(dp[i][j],
                cost[i][j]+dp[i-1][k]);
                    }// if
                }
            }
        }// for i
        int ans=INT_MAX;
        for(int i=0;i<3;i++){
            ans=min(dp[n-1][i],ans);
            
            
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> cost[N];
        int x, y, z;
        for(int i = 0;i < N;i++){
            cin>>x>>y>>z;
            cost[i].push_back(x);
            cost[i].push_back(y);
            cost[i].push_back(z);
        }
        
        Solution ob;
        cout<<ob.minCost(N, cost)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
