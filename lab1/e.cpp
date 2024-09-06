#include <iostream>

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
        for(; node != tail; node = node->next); // этот форик для того чтобы передвинуть наш node до предпоследнего элемента и удалить послед
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
    int temp;
    int cnt = 0;

    OneLinkedList Boris;
    OneLinkedList Nursik;

    for(int i = 0; i < 5; i++){
        cin >> temp;
        Boris.push_back(temp);
    }

    for(int i = 0; i < 5; i++){
        cin >> temp;
        Nursik.push_back(temp);
    }

    while(!Boris.empty() && !Nursik.empty()){
        cnt++;
        if((Boris.front() == 0 && Nursik.front() == 9) || (Boris.front() == 9 && Nursik.front() == 0)){
            if (Boris.front() == 0){
                Boris.push_back(Boris.front());
                Boris.push_back(Nursik.front());
                Boris.pop_front();
                Nursik.pop_front();
            }
            else{
                Nursik.push_back(Boris.front());
                Nursik.push_back(Nursik.front());
                Boris.pop_front();
                Nursik.pop_front();
            }
        }
        else{
            if (Boris.front() > Nursik.front()){
                Boris.push_back(Boris.front());
                Boris.push_back(Nursik.front());
                Boris.pop_front();
                Nursik.pop_front();
            }
            else{
                Nursik.push_back(Boris.front());
                Nursik.push_back(Nursik.front());
                Boris.pop_front();
                Nursik.pop_front();

            }
        }

        if (cnt > 1000000){
            cout << "blin nichya" << endl;
            return 0;
        }
    }

    if(Boris.empty()){
        cout << "Nursik " << cnt;
    }
    else{
        cout << "Boris " << cnt;
    }

    return 0;
}