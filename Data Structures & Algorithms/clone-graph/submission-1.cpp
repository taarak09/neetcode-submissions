/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        {
            return NULL;
        }
      
        unordered_map<Node *,Node *>mpp;
        mpp[node]=new Node (node->val);
        queue<Node *>q;
        q.push(node);
        while(!q.empty())
       {
          for(Node * i:q.front()->neighbors)
          {
            if(mpp.find(i)==mpp.end())
            {
                Node * t1=new Node (i->val);
                mpp[i]=t1;
                q.push(i);
                mpp[q.front()]->neighbors.push_back(mpp[i]);
            }
            else{
                mpp[q.front()]->neighbors.push_back(mpp[i]);
            }
          }
          q.pop();
       }
   return mpp[node]; }
};
