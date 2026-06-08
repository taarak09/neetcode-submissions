class Solution {
public:
int findparent ( vector<int>&parent,int node)
{
  // finding the ultimate parent
  if(parent[node]==node)
  {
    return node;
  }
  return findparent(parent,parent[node]);
}

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<int>parent(edges.size()+1);
        for(int i=0;i<parent.size();i++)
        {
               parent[i]=i;

        }
        for(int i=0;i<edges.size();i++)
        {
            int u=findparent(parent,edges[i][0]);
            int v= findparent(parent,edges[i][1]);
            if(u==v)
         {
            return edges[i];
         }
         parent[u]=v;

        }
    return {};}
}; 