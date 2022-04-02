int nCr(int n, int r){

        long long C[r+1]={0};

        C[0]=1;

        for(int i=1;i<=n;i++)

        {

            for(int j=min(i,r);j>0;j--)

                C[j]= (C[j]+C[j-1])%1000000007;

        }

        return C[r];

    }
////////////////////////////////////////////////////////////////////////////////////////////
class Solution:
    def fun(self, n, r, dp):
        if n==0 or r==0:
            if r:
                return 0
            else:
                return 1 
        if dp[n][r]!=-1:
            return dp[n][r]
        
        dp[n][r] = (self.fun(n-1,r-1,dp)+self.fun(n-1,r,dp))%1000000007
        return dp[n][r]
    def nCr(self, n, r):
        dp = []
        for i in range(n+1):
            t = [-1]*(r+1)
            dp.append(t)
        if r==n:
            return 1 
        elif r>n:
            return 0
        return self.fun(n,r,dp)

