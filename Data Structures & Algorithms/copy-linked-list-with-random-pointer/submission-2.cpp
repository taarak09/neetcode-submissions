/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//abhi isme thoda alag concept lagega

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
        {
            return NULL;
        }
       
        unordered_map<Node *,Node *>mpp;
        Node * p=head;
        Node * u= new Node(p->val);
        mpp[p]=u;
       
        while(p!=NULL)
        {
           if(mpp.find(p)==mpp.end())
           {
             Node * f = new Node(p->val);
             mpp[p]=f;

           }
           else{

           }
          p=p->next;
        }
        p=head;
        while(p!=NULL)
        {
            mpp[p]->next=mpp[p->next];
            mpp[p]->random=mpp[p->random];
            p=p->next;
        }
   return u; }
};
