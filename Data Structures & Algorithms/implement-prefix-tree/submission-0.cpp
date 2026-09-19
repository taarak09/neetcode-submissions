class node{
    public:
    node * links[26]={NULL};
    bool flag=false;
    bool contains (char c)
    {
        return (links[c-'a']!=NULL);
    }
    void put (char t,node * node)
    {
        links[t-'a']=node;
    }
    node * get(char t)
    {
        return links[t-'a'];
    }
    void setend(){
        flag=true;
    }
};

class PrefixTree {
    private:
    node * root;


public:

    PrefixTree() {
        root=new node ();
    }
    
    void insert(string word) {
        node * node1=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node1->contains(word[i]))
            {
               node1->put(word[i],new node());       
            }
            node1 =node1->get(word[i]);
        }
     node1->setend();
    }
    
    bool search(string word) {
        node * node=root;
        for(int i=0;i<word.length();i++)
        {
            if(node->contains(word[i]))
            {
                 
            }
            else{
                return false;
            }
           node= node->get(word[i]);
        }
        if(node->flag==true)
        {
            return true;
        }
    return false;}
    
    bool startsWith(string prefix) {
        string word=prefix;
        node * node=root;
        for(int i=0;i<word.length();i++)
        {
            if(node->contains(word[i]))
            {

            }
            else{
                return false;
            }
           node= node->get(word[i]);
        }
       
    return true;}
};
