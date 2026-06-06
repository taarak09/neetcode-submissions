class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
          vector<int>visited(n,0);
          vector<vector<int>>adj(n);
          for(int i=0;i<edges.size();i++)
          {
            for(int j=0;j<1;j++)
            {
                adj[edges[i][j]].push_back(edges[i][j+1]);
                adj[edges[i][j+1]].push_back(edges[i][j]);
            }
          }
          //graph making questions are same as course schedule 2
          int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                bfs(n,adj,visited,i);
                count++;
            }
        }
          
          
    return count;}
    void bfs(int n, vector<vector<int>>& adj,vector<int> & visited,int node)
    {
       queue<int>q;
       q.push(node);
       visited[node]=1;
       while(!q.empty())
       {
         int t1=q.front();
         q.pop();
         for(int next:adj[t1])
         {
            if(!visited[next]){
            q.push(next);
            visited[next]=1;}
         }

       }








    }
};
