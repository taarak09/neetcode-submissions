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
        if(node->neighbors.empty())
        {
            return new Node(node->val);
        }
        Node* u= new Node (node->val);
        unordered_map<Node*,Node *>mpp;
        mpp[node]=u;
        queue<Node*>q;
        q.push(node);
        vector<Node*>l;
        while(!q.empty())
        {
            for(Node * y : q.front()->neighbors)
            {
                if(mpp.find(y)==mpp.end())
                {
                    Node * temp = new Node (y->val);
                    l.push_back(temp);
                    q.push(y);
                    mpp[y]=temp;

                }
                else{
                    l.push_back(mpp[y]);
                }
               
            }
            mpp[q.front()]->neighbors=l;
                l.clear();
                q.pop();
        }
   return u; }
};
