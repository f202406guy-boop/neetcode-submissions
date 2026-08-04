class NODE{
public:
    NODE *children[26];
    bool eow;
    NODE()
    {
        
        for(int i=0;i<26;i++)
        {
            children[i]=nullptr;
        }
        eow=false;
    }
};
class WordDictionary {
    NODE *n;
public:
    WordDictionary() {
        n=new NODE();
    }
    
    void addWord(string word) {
        NODE *temp=n;
        for (char c:word)
        {
            int i=c-'a';
            if(temp->children[i]==nullptr)
            {
                temp->children[i]=new NODE();
            }
            temp=temp->children[i];
            
        }
        temp->eow=true;
    }
    
    bool solve(NODE *t, string &word, int idx)
    {
        if(t==nullptr) return false;
        if(idx==word.size()) return t->eow;

        char c=word[idx];
        if(c=='.')
        {
            for(int i=0;i<26;i++)
            {
                if(solve(t->children[i],word,idx+1)) return true;
            }
            return false;
        }

        int i=c-'a';
        return solve(t->children[i],word,idx+1);
    }

    bool search(string word) {
        return solve(n,word,0);
    }
};