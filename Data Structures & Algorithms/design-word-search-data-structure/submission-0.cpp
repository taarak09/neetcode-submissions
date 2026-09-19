class node{
public:
bool flag= false;
node * links[26]={NULL};
bool contains(char t)
{
    return (links[t-'a']!=NULL);
}
void put(char t,node * node)
{
    links[t-'a']=node;
}
node * get(char t)
{
    return links[t-'a'];
}
void setend()
{
    flag=true;
}
};

class WordDictionary {
    private:
    node * root;
public:
    WordDictionary() {
        root=new node();
    }
     bool solve (node * p,string word)
     {
        node * node=p;
        
        for(int i=0;i<word.length();i++)
        {
            if(word[i]=='.')
            {
                string h="";
                for(int k=i+1;k<word.length();k++)
                {
                 h+=word[k];   
                }
                for(int j=0;j<26;j++)
                {
                    if(node->links[j]!=NULL)
                    {
                       
                        if(solve(node->links[j],h))
                        {
                          return true;
                        }
                    }
                }
                return false;

            }else{
            if(node->contains(word[i]))
            {

            }
            else{
                return false;
            }
            }
            node=node->get(word[i]);
        }
        if(node->flag==true)
        {
            return true;
        }
      
     return false;}
    void addWord(string word) {
        node* node1=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node1->contains(word[i]))
            {
                node1->put(word[i],new node ());
            }
            else{

            }
            node1=node1->get(word[i]);
        }
        node1->setend();
        
    }
    
    bool search(string word) {
       return solve(root,word);
       }
};
