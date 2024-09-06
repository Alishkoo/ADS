#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
public:
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Binarytree{
private:
    Node* root;

    // Симметричный обход LNR left and right 
    void _inorder(Node* node){
        if(!node){
            return;
        }
        _inorder(node->left);
        cout << node->data << " ";
        _inorder(node->right);
    }

    // Прямой обход сначала корень потом левое дерев, потом правое 
    void _preorder(Node* node){
        if(!node){
            return;
        }

        cout << node->data << " ";
        _preorder(node->left);
        _preorder(node->right);
    }

    // Обратный обход
    void _postorder(Node *node)
	{
		if (!node)
			return;
		_postorder(node->left);
		_postorder(node->right);
		cout << node->data << " ";
	}

    Node* _insert(Node* cur, int data){
        if (!cur){
            return new Node(data);
        }

        if(data < cur->data){
            cur->left = _insert(cur->left, data);
        }
        else if(data > cur->data){
            cur->right = _insert(cur->right, data);
        }

        return cur;
    }

    
    int _rightmost(Node* cur){
        if(!cur){
            return -1;
        }

        if(!cur->right){
            return cur->data;
        }
        return _rightmost(cur->right);
    }

    int _leftmost(Node* cur){
        if(!cur){
            return -1;
        }

        if(cur->left){
            return _leftmost(cur->left);
        }
        return cur->data;
    }

    Node* _remove(Node* cur, int target){
        if(!cur){
            return nullptr;
        }
        if(cur->data == target){
            if(!cur->left && !cur->right){
                delete cur;
                return nullptr;
            }

            else if(!cur->left && cur->right){
                Node *temp = cur->right;
				delete cur;
				return temp;
            }

            else if(cur->left && !cur->right){
                Node* temp = cur->left;
                delete cur;
                return temp;
            }

            else if(cur->left && cur->right){
                cur->data = _rightmost(cur->left);
                cur->left = _remove(cur->left, cur->data);
            }
        }

        if(target > cur->data){
            cur->right = _remove(cur->right, target);
            return cur;
        }
        else if(target < cur->data){
            cur->left = _remove(cur->left, target);
            return cur;
        }   

        return cur;
    }

    Node *_search(Node *cur, int target)
	{
		if (!cur)
			return nullptr;
		if (cur->data == target)
			return cur;
		if (cur->data > target)
			return _search(cur->left, target);
		if (cur->data < target)
			return _search(cur->right, target);
	}

public:
    Binarytree(){
        this->root = nullptr;
    }

    Node *getRoot()
	{
		return root;
	}

	void inorder()
	{
		_inorder(root);
		cout << endl;
	}

	void preorder()
	{
		_preorder(root);
		cout << endl;
	}

	void postorder()
	{
		_postorder(root);
		cout << endl;
	}

    void insert(int data)
	{
		Node *newNode = _insert(root, data);
		if (!root)
			root = newNode;
	}

    void remove(int target)
	{
		_remove(root, target);
	}

    Node *search(int target)
	{
		return _search(root, target);
	}

    bool routeFound(string route)
	{
		Node *cur = root;
		for (auto c : route)
		{
			if (c == 'L')
				cur = cur->left;
			else
				cur = cur->right;
			if (!cur)
			{
				return false;
			}
		}
		return true;
	}

    int get_size(Node* node){
        if (!node)
            return 0;
        return get_size(node->left) + get_size(node->right) + 1;
    }   

};

int main(){
    int n;
    cin >> n;

    Binarytree bst;

    while(n--){
        int k;
        cin >> k;
        bst.insert(k);
    }
    int t;
    cin >> t;

    cout << bst.get_size(bst.search(t));

}