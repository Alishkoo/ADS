#include <bits/stdc++.h>
using namespace std;

// template <class T>
// Need to solve problem with type of data

class Node{
public:
    int data;
    Node* next;
public:
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


class OneLinkedList{
public:
    Node* head; // front  
    Node* tail; // back
    int size = 0;
public:
    OneLinkedList(){
        this->head = this->tail = NULL;
        this-> size = 0;
    }

    ~OneLinkedList(){
        while(head != NULL) pop_front();
    }

    void pop_front(){
        if (head == NULL) return;
        if (head == tail){
            delete tail;
            head = tail = NULL;
            size = 0;
            return;
        }

        Node* node = head;
        head = head->next;
        delete node;
    }

    void push_back(int data){
        Node* node = new Node(data);

        if (head == NULL) head = node;
        if (tail != NULL) {
            tail->next = node;
        }
        tail = node;
    }

    void push_front(int data){
        Node* node = new Node(data);
        node->next = head;
        head = node;
        if (tail == NULL) tail = node;

    }

    void pop_back(){
        if (tail == NULL) return;
        if (head == tail){
            delete tail;
            head = tail = NULL;
            return;
        }

        Node* node = head;
        for(; node->next != tail; node = node->next); // этот форик для того чтобы передвинуть наш node до предпоследнего элемента и удалить послед
        delete tail;
        tail->next = NULL;
        tail = node;
    }

    Node* getAt(int k){
        if (k < 0) return NULL;

        Node* node = head;
        int n = 0;
        while(node && n != k && node ->next){
            node = node->next;
            n++;
        }

        return (n == k) ? node : NULL;
    }

    void getALL(){
        Node* node = head;

        if (head == NULL){
            cout << "lIST IS EMPTY" << endl;
            return;
        }
        
        while(node){
            cout << node->data << " ";
            node = node->next;
        }
        cout << "\n";

    }

    int front(){
        if (head != NULL){
            return head->data;
        }
    }

    int back(){
        if (tail != NULL){
            return tail->data;
        }
    }

    bool empty(){
        return head == NULL || tail == NULL;
    }

    // task from the lab
    void shift(int k){
        while(k--){
            this->tail->next = this->head;
            this->tail = this->head;
            this->head = this->head->next;
            this->tail->next = NULL;

        }
    }

    // task from the lab
    void insertAt(int pos, int data){
        Node* prev = head;
        Node* cur = head->next;
        Node* node = new Node(data);

        if(pos == 0){
            node->next = prev;
            head = node;
            return;
        }
        
        pos--;
        while (pos--){
            prev = prev->next;
            cur = cur->next;
        }


        prev->next = node;
        node->next = cur;

        return;        
    }
};

int main(){
    int n, temp, data, pos;
    OneLinkedList lst;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> temp;
        lst.push_back(temp);
    }

    cin >> data >> pos;

    lst.insertAt(pos, data);

    lst.getALL();

}