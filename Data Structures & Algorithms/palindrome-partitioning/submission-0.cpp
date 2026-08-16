class Solution {
public:
    vector<vector<string>> ans;
    bool is_palindrome(string s)
    {
       for(int i=0;i<s.size();i++)
       {
        if(s[i]!=s[s.size()-i-1]) return false;
       }
       return true;
    }
    void back(string s,vector<string>res){
       if(s.size()==0) {ans.push_back(res);return;}
       if(s.size()==1) {res.push_back(s);ans.push_back(res); return;}
       for (int i=1;i<=s.size();i++)
       {
          if(is_palindrome(s.substr(0,i))){
            res.push_back(s.substr(0,i));
            back(s.substr(i),res);
            res.pop_back();
          }
       }
    }
   vector<vector<string>> partition(string s) {
    vector<string> res;
        back(s,res);
        return ans;
    }

};
