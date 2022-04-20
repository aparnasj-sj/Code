// 210. Course Schedule II
/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
*/


class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        // (b--> a) 
        // kahns algo
        // count indegree of all vtx
        int indegree[n]; // no need vis array , indegree itsefl enough
        for(int i=0;i<n;i++){
            indegree[i]=0;
        }
        vector<vector<int>>g(n);
        queue<int>q;
        
        for(auto it:pre){
            // it --> vector<int> of size 2
           // (a,b)=> b--> a
            
            indegree[it[0]]++;
            g[it[1]].push_back(it[0]);
            
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                 cout<<i<<endl;
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int v=q.front();
            cout<<v<<endl;
            q.pop();
            ans.push_back(v);
            
            for(auto nbr:g[v]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
                
            }
        }
        vector<int>ans2;
        //sometimes a loop may exists between few tasks
        // in tat case certain elms wont evr get pushed to q
        // eg , 0--> 1 , 1--> 0 , 2-->1
        // in this case ans array will [2]
        // but ans should be [] => cannot be perform topo sort 
        if(ans.size()==n){
        return ans;
        }else{
            return ans2;
        }
        
    }
};
