#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;
class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    Node(){
        endOfWord=false;
    }
};
class Trie{
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string key){
        Node* temp=root;
        for(int i=0; i<key.size(); i++){
            if(!temp->children.count(key[i])){
                temp->children[key[i]]=new Node();
            }
            temp=temp->children[key[i]];
        }
        temp->endOfWord=true;
    }
    bool search(string key){
        Node* temp=root;
        for(int i=0; i<key.size(); i++){
            if(temp->children.count(key[i])){
                temp=temp->children[key[i]];
            } else{
                return false;
            }
        }
        return temp->endOfWord;
    }
};
bool helper(Trie &tri, string key){
    if(key.size()==0) return true;
    for(int i=0; i<key.size(); i++){
        string first=key.substr(0, i+1);
        string second=key.substr(i+1);
        if(tri.search(first) && helper(tri, second)){
            return true;
        }
    }
    return false;
}
bool wordBreak(vector<string> dict, string key){
    Trie tri;
    for(int i=0; i<dict.size(); i++){
        tri.insert(dict[i]);
    }
    return helper(tri, key);
}
int main(){
    vector<string> words={"the", "a", "there", "their", "any", "thee"};
    Trie trie;

    for(int i=0; i<words.size(); i++){
        trie.insert(words[i]);
    }
   // cout<<trie.search("any")<<endl;
    vector<string> word={"i", "like", "sam", "samsung", "mobile", "ice"};
    cout<<wordBreak(word, "ilikesung")<<endl;
    return 0;
}