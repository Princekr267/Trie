#include<iostream>
#include<string>
#include<unordered_map>
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
    bool starsWith(string prefix){
        Node* temp=root;
        for(int i=0; i<prefix.size(); i++){
            if(temp->children[prefix[i]]){
                temp=temp->children[prefix[i]];
            } else{
                return false;
            }
        }
        return true;
    }
    int countHelper(Node* root){
        int ans=0;
        for(pair<char, Node*> child : root->children){
            ans+=countHelper(child.second);
        }
        return ans+1;
    }
    int countNodes(){
        return countHelper(root);
    }
    void longestHelper(Node* root, string &ans, string temp){
        for(pair<char, Node*> child : root->children){
            if(child.second->endOfWord){
                temp+=child.first;
                if((temp.size()==ans.size() && temp<ans) || (temp.size() > ans.size())){
                    ans=temp;
                }
                longestHelper(child.second, ans, temp);
                temp=temp.substr(0, temp.size()-1);
            }
        }
    }
    string longestStringEOW(){
        string ans=" ";
            longestHelper(root, ans, "");
            return ans;
    }
};
int countUniqueSubstr(string str){
    Trie trie;
    for(int i=0; i<str.size(); i++){
        string suffix=str.substr(i);
        trie.insert(suffix);
    }
    return trie.countNodes();
   
}
string longestString(vector<string> dict){
    Trie trie;
    for(int i=0; i<dict.size(); i++){
        trie.insert(dict[i]);
    }
    return trie.longestStringEOW();
}
int main(){
    vector<string> words={"apple", "app", "mango", "man", "woman"};
    Trie trie;
    for(int i=0; i<words.size(); i++){
        trie.insert(words[i]);
    }
    cout<<trie.starsWith("ma")<<endl;
    cout<<"\nCount unique sub string: ";
    string str="abc";
    cout<<countUniqueSubstr(str)<<endl;
    vector<string> dict={"a", "banana", "app", "appl", "ap", "apply"};
    cout<<longestString(dict)<<endl;
    return 0;
}