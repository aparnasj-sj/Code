/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
*/

class Solution {
    int dp[31][31];
public:
    bool fun(string s,string p,int i,int j,int dp[31][31]){
        // base case 
        cout<<i<<j<<endl;
        if(i>=s.length()){
            while(j<p.length()-1 && p[j+1]=='*'){
                j+=2;
            }
            return j>=p.length();
        }
        if(j>=p.length()){
            if(i>=s.length()){
                return true;
            }
            return false;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j]==1;
        }
       
        bool mt=false;
        if(s[i]==p[j] || p[j]=='.'){
           mt=true;
        }
         if( j<=p.length()-2 && p[j+1]=='*'){
            if(fun(s,p,i,j+2,dp)||(mt && fun(s,p,i+1,j,dp))){
                //match 0 OR (match 1 and expect more  
                //third case is needed , 
                return dp[i][j]=1;
            }else{
                return dp[i][j]=0;
            }
        }
        else{
            if(mt && fun(s,p,i+1,j+1,dp)){
                return dp[i][j]=1;
            }else{
                return dp[i][j]=0;
            }
        }
        
    }
    bool isMatch(string s, string p) {
        for(int i=0;i<31;i++){
            for(int j=0;j<31;j++){
                dp[i][j]=-1;
            }
        }
        bool x=fun(s,p,0,0,dp);
        if(x)
            return true;
        
        return false;
    }
};
// python
class Solution(object):
    def isMatch(self, text, pattern):
        memo = {}
        def dp(i, j):
            if (i, j) not in memo:
                if j == len(pattern):
                    ans = i == len(text)
                else:
                    first_match = i < len(text) and pattern[j] in {text[i], '.'}
                    if j+1 < len(pattern) and pattern[j+1] == '*':
                        ans = dp(i, j+2) or first_match and dp(i+1, j)
                    else:
                        ans = first_match and dp(i+1, j+1)

                memo[i, j] = ans
            return memo[i, j]

        return dp(0, 0)
