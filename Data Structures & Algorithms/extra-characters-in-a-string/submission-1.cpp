class NODE {
public:
    bool eow;
    NODE *children[26];
    NODE()
    {
      for(int i=0;i<26;i++){
        children[i]=nullptr;
      }
      eow=false;
    }
    
};
class Solution {
public:
vector<int> mem;
bool starts(string s, NODE  * &temp)
{
    NODE *t=temp;
    for(char c:s)
    {
        int i=c-'a';
        if(t->children[i]==nullptr) return false;
        t=t->children[i];
    }
    temp=t;
    return true;
}
int dp(NODE *t,vector<string> &dict,string &str,int idx)   
    {
        if(idx==str.size()) return 0; 
        if(mem[idx]!=-1) return mem[idx];

        int best = 1 + dp(t->children[str[idx]-'a'], dict, str, idx+1);  

        for(string s:dict)
        {
            NODE *temp=t;
            if(starts(s,temp)){
               best = min(best, dp(temp, dict, str, idx+s.size()));
            }
        }
        return mem[idx]=best;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        mem.assign(s.size(),-1);
        NODE *root=new NODE();
        NODE *t=root;
        for(char c:s){
        int i=c-'a';
        if(t->children[i]==nullptr){t->children[i]=new NODE();}
        t=t->children[i];
    }
    
    //cout<< (bool)starts("neet",root);
    return dp(root,dictionary,s,0);
    }
    
    
};