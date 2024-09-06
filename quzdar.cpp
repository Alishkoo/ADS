#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int index;
    int power;
    vector <Node*> children;
public:
    Node(int index, int power, vector<Node*> children){
        this->index = index;
        for(int i = 0; i < children.size(); i++){
            this->children.push_back(children[i]);
        }
        this->power = power;
    }
};

class Tree{
public:
    Node root;
    

};

int main{

}