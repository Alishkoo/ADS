#include <iostream> 
using namespace std;

// template <class T>
// Need to solve problem with type of data

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
    OneLinkedList lst;
    string s;
    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++){
        cin >> s;
        lst.push_back(s);
    }

    lst.shift(k);
    lst.getALL();
    return 0;

}