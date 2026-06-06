class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //cyclic graph questions
         //solve by using adjacency list 
         vector<int>indegree(numCourses,0);
         vector<vector<int>>adj(numCourses);
         for(int i=0;i<prerequisites.size();i++)
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
        while(!q.empty())
        {
           int temp=q.front();
           q.pop();
           completed++;
           for(int next: adj[temp])
           {
             indegree[next]--;
             if(indegree[next]==0){
             q.push(next);
             }
           }
          
        }
    return completed==numCourses;}
};
