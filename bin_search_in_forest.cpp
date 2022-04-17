/*
There are n trees in a forest. The heights of the trees is stored in array tree[], where tree[i] denotes the height of the ith tree in the forest.
If the ith tree is cut at a height H, then the wood collected is tree[i] - H, provided tree[i] > H. If the total woods that needs to be collected is 
exactly equal to k, find the height H at which every tree should be cut (all trees have to be cut at the same height). If it is not possible then return -1 else 
return H.
*/
 int find_height(int tree[], int n, int k)
    {
        // code here
        int maxv=INT_MIN;
        for(int i=0;i<n;i++){
            if(tree[i]>maxv){
                maxv=tree[i];
            }
        }
        if(k==0){return maxv;}
        // the H may any from 1 --> maxv 
        // the lower u cut , more wood u get 
        int low=1;
        int high=maxv;
        while(low<=high){
            int mid=(low+high)/2;
            int wood=0;
        for(int i=0;i<n;i++){
            if(mid<tree[i]){
                wood+=(tree[i]-mid);
                
            }
           
            
        }// for
       // cout<<wood<<" "<<mid<<endl;
            if(wood==k){return mid;}
            
            // less wood--> u cut too high
            if(wood<k){
                high=mid-1;
            }else{
                low=mid+1;
            }
            
        }
        return -1;
    }
