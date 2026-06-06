class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(int i=0;i<n;i++)
        {
            for(int j=1;j>=0;j--)
            {
                if(j==1){
                adj[prerequisites[i][j]].push_back(prerequisites[i][j-1]);
                indegree[prerequisites[i][j-1]]++;
                }
            }
        }
        int completed=0;
        queue<int>q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>final;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            final.push_back(temp);
            completed++;
            for(int next: adj[temp])
            {
                indegree[next]--;
                if(indegree[next]==0)
                {
                    q.push(next);
                }
            }
        }
        if(completed==numCourses)
        {
            return final;
        }
   
   return {}; }
};
