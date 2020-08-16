#include <bits/stdc++.h> 
using namespace std; 


class TrieNode{
	public:
    unordered_map<char, TrieNode*> um;
    bool end=false;
};

class Trie{
    TrieNode* root=NULL;
    bool deleteNode(int i, string word, TrieNode* root);
    public:
    Trie(string word){
        insert(word);
    }
    Trie(){
    	root=new TrieNode;
	}
    void insert(string word);
    bool search(string word);
    bool deleteW(string word);
};

void Trie::insert(string word){
	TrieNode* t=root;
    for(char w: word){
        if(t->um.find(w)==t->um.end()){
            t->um[w]=new TrieNode;
        }
        t=t->um[w];
    }
    t->end=true;
}

bool Trie:: search(string word){
    TrieNode* t=root;
    for(char w: word){
        if(t->um.find(w)==t->um.end())
            return false;
        t=t->um[w];
    }
    return t->end;
}
bool Trie::deleteNode(int i, string word, TrieNode* root){
    if(i==word.length()){
        if(root->end && root->um.size()==0){
            delete root;
            return true;
        }
        root->end=false;
        return false;
    }
    if(root->um.find(word[i])==root->um.end())
        return false;
    if(deleteNode(i+1, word, root->um[word[i]])){
        if(!root->end && root->um.size()==1){
            delete root;
            return true;
        }
        root->um.erase(word[i]);
    }
    return false;
}
bool Trie::deleteW(string word){
    return deleteNode(0, word, root);
}

int main(){
	int n;
	string s;
	cin>>n;
	Trie t;
	while(1){
		switch(n){
			case -1: return 0;
			case 1: cin>>s;
			t.insert(s);break;
			case 2: cin>>s;
			cout<<t.search(s)<<endl;break;
			case 3:cin>>s;
			cout<<t.deleteW(s)<<endl;
		}
		cin>>n;
	}
	
}
