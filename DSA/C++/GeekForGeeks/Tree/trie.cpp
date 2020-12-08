#include<bits/stdc++.h>

using namespace std;

class Trie
{
public:
    bool isEnd;
    Trie *child[256];
    Trie()
    {
        isEnd = false;
        for (int i = 0; i < 256; i++)
            child[i] = NULL;
        
    }
};

bool isEmpty(Trie *t)
{
    for (int i = 0; i < 256; i++)
        if(t->child[i])
            return false;
    return true;
}

Trie* deleteMember(Trie *t, string s, int ind)
{
    if(!t)
        return NULL;
    if (ind == s.length())
    {
        t->isEnd = false;
        if(isEmpty(t))
        {
            delete(t);
            return NULL;
        }
        return t;
    }
    t->child[s[ind]] = deleteMember(t->child[s[ind]], s, ind+1);
    if(t->isEnd==false && isEmpty(t))
    {
        delete(t);
        return NULL;
    }
    return t;
}

void insertMember(Trie *t, string s)
{
    auto root = t;
    for (int i = 0; i < s.length(); i++)
    {
        if(!root->child[s[i]])
            root->child[s[i]] = new Trie();
        root = root->child[s[i]];
    }
    root->isEnd = true;
}

bool searchMember(Trie *t, string s)
{
    auto root = t;
    for (int i = 0; i < s.length(); i++)
    {
        if(!root)
            return false;
        root = root->child[s[i]];
    }
    return root && root->isEnd;
}

int main()
{
    string words[] = {"bad", "cat", "car", "bat", "geeks", "geek"};
    string searchwords[] = {"bad", "Kumar", "cat", "car", "bat", "geeksforgeeks", "geek"};
    Trie *trie = new Trie();
    for(auto i : words)
        insertMember(trie,i);
    string str = "bat";
    deleteMember(trie, str, 0);
    for(auto i : words)
        if(searchMember(trie,i))
            cout<<"Found"<<endl;
        else
            cout<<"Not Found"<<endl;
    return 0;
}