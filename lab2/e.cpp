#include <iostream>

using namespace std; 

class Node{
public:
    string data;
    Node* next;
public:
    Node(string data){
        this->data = data;
        this->next = NULL;
    }
};


class OneLinkedList{
public:
    Node* head; // front  
    Node* tail; // back
public:
    OneLinkedList(){
        this->head = this->tail = NULL;
    }

    ~OneLinkedList(){
        while(head != NULL) pop_front();
    }

    void pop_front(){
        if (head == NULL) return;
        if (head == tail){
            delete tail;
            head = tail = NULL;
            return;
        }

        Node* node = head;
        head = head->next;
        delete node;
    }

    void push_back(string data){
        Node* node = new Node(data);

        if (head == NULL) head = node;
        if (tail != NULL) {
            tail->next = node;
        }
        tail = node;
    }

    void push_front(string data){
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
        for(; node != tail; node = node->next){
            cout << node->data << " ";
        }
        cout << tail->data << endl;

    }

    string front(){
        if (head != NULL){
            return head->data;
        }
    }

    string back(){
        if (tail != NULL){
            return tail->data;
        }
    }

    bool empty(){
        return head == NULL || tail == NULL;
    }
    
    void shift(int k){
        while(k--){
            this->tail->next = this->head;
            this->tail = this->head;
            this->head = this->head->next;
            this->tail->next = NULL;

        }
    }

};

int main(){
    int n, size = 0;
    cin >> n;

    OneLinkedList lst;
    string temp;

    for(int i = 0; i < n; i++){
        cin >> temp;

        if(lst.empty()){
            lst.push_front(temp);
            size++;
        }
        else if(lst.front() != temp){
            lst.push_front(temp);
            size++;
        }
    }

    cout << "All in all: " << size << endl;
    cout << "Students:" << endl;

    for(int i = 0; i < size; i++){
        cout << lst.getAt(i)->data << endl;
    }

    return 0;
}