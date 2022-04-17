// Valid Triangle Number (bin search )
//Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

class Solution {
public:
    int triangleNumber(vector<int>& v) {
        sort(v.begin(),v.end());int n=v.size();
        int ans=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int l=j+1;int r=n-1;int mid=(l+r)/2;
                while(l<=r){
                    mid=(l+r)/2;
                    if(v[i]+v[j]>v[mid]){
                        // extend right
                        l=mid+1;
                        
                    }else {
                        r=mid-1;
                        
                    }
                    
                }
                ans+=(r-j); // or ans+=(l-j-1)
                // when v[mid] satisy , we try to move L forward , chance is next index not satify , hence L-1 is subtracted
                // when v[mid] dont satify , move R back , keep moving till index actually satify , hence final R will satify conditon
            }
            
        }
        return ans;
    }
};
