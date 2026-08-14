class Solution {
public:
    void backtrack(int n, string &ans,vector<string> &final,int o, int c)
    {
        if(o==n&&c==n){
            final.push_back(ans);
            
        }
        if(o<n){
            ans+='(';
            backtrack(n,ans,final,o+1,c);
            ans.pop_back();
        }
        if(c<o){
            ans+=')';
            backtrack(n,ans,final,o,c+1);
            ans.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string a="";
        vector<string> v;
        backtrack(n,a,v,0,0);
        return v;
        

    }
};
