// leetcode counting bits 
vector<int> countBits(int num) {

        vector<int> dp(num+1);

        dp[0]=0;

        for(int i=1;i<=num;i++)

        {

            int x=log2(i); // log base 2 (i) 

            dp[i]=1+dp[i-(1<<x)] ; // 1<<x => 2^x => msb 

        }

        return dp;

    }




