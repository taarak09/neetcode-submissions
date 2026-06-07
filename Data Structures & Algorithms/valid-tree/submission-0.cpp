class matrix{
public:
int a;
int parent;
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
          vector<vector<int>>adj(n);

          for(int i=0;i<edges.size();i++)
          {
            for ( int j =0; j<1;j++)
            {
                adj[edges[i][j]].push_back(edges[i][j+1]);
                adj[edges[i][j+1]].push_back(edges[i][j]);
            }
          }
          for(int i=0;i<n;i++)
          {

          }
          // graph has been built now check if it is a valid tree
          //graph must not be cyclic and every part of graph must be connected
          vector<int>visited(n,0);
          
          queue<matrix>q;
          q.push({0,-1});
          visited[0]=1;
          while(!q.empty())
          {
            int t1=q.front().a;
            int l= q.front().parent;
            q.pop();
            
            for(int g : adj[t1])
            {
                if(!visited[g]){
                q.push({g,t1});
                visited[g]=1;
                }
                else if (g!=l)
                {
                    return false;
                }
            }
//concept man concept
          }
          if(find(visited.begin(),visited.end(),0)!=visited.end())
          {
              return false;
          }

   return true; }
};
