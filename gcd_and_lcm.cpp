class Solution {
  public:
  long long gcdFun(int a,int b){
      if(b==0){return a;}
      return gcdFun(b,a%b);
  }
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        vector<long long>ans;
        ans.push_back(gcdFun(A,B));
        long long lcm=(A*B)/ans[0];
        ans.insert(ans.begin(), lcm);
        return ans;
    }
};
////////////////////////////////
class Solution:
    def lcmAndGcd(self, A , B):
        
        arr=[0]*2 
        
        g = math.gcd(A,B)   # gcd of 2 numbers.
        l = (A*B)//g        # product of 2 numbers divided by their gcd gives their lcm.
        
        arr[0],arr[1] = l,g
        
        return arr
