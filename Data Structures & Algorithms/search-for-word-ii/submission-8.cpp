class TrieNODE

{public:
    bool eow;
    map <char,TrieNODE*> children;
    TrieNODE(){eow=false;}
    void add_word(string s)
    {
        TrieNODE* t=this;
       for(char c:s)
       {
         if(!t->children.count(c))
         {
           t->children[c]=new TrieNODE();
         }
         t=t->children[c];
       }
       t->eow=true;
    }
};
set<string>res;


class Solution {
public:
    vector<vector<bool>> visit;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
         res.clear();
        TrieNODE *root=new TrieNODE();
        for(auto i:words)
        {
           root->add_word(i);
        }
        int row=board.size(); int col=board[0].size();
        visit.assign(row,vector<bool>(col,false));
        for(int i =0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                dfs(i,j,board,"",root);
            }
        }
        return vector<string>(res.begin(),res.end());
    }
    private:
    void dfs(int l,int r,vector<vector<char>>& board,string s,TrieNODE *root)
{
   int row=board.size(); int col=board[0].size();
   if(l>=row||l<0||r>=col||r<0||!root->children.count(board[l][r])){return;}
   if(visit[l][r]) return;
   visit[l][r]=true;
   root=root->children[board[l][r]];
   s+=board[l][r];
   if(root->eow==true) res.insert(s);
   
   dfs(l+1,r,board,s,root);
   dfs(l,r+1,board,s,root);
   dfs(l-1,r,board,s,root);
   dfs(l,r-1,board,s,root);
   visit[l][r]=false;

}
};
