#include <iostream>

using namespace std;

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
        for(; node != tail; node = node->next){
            cout << node->data << " ";
        }
        cout << tail->data << endl;

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
};

int main(){

    OneLinkedList lst1;


    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        while(!lst1.empty() && lst1.front() > arr[i]){
            lst1.pop_front();
        }
        if(lst1.empty()){
            cout << -1 << " ";
        }
        else{
            cout << lst1.front() << " ";
        }
        lst1.push_front(arr[i]);
    }
    return 0;
}