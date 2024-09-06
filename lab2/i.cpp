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

    void clear(){
        Node* temp = head->next;
        Node* prev = head;

        while(temp){
            delete prev;
            prev = temp;
            temp = temp->next;
        }

        head = tail = nullptr;
    }

};

int main(){
    OneLinkedList lst;
    string comnd;

    while(true){
        cin >> comnd;

        if(comnd == "add_front"){
            string temp;
            cin >> temp;
            lst.push_front(temp);
            cout << "ok" << endl;
        }
        else if(comnd == "add_back"){
            string temp;
            cin >> temp;
            lst.push_back(temp);
            cout << "ok" << endl;
        }
        else if(comnd == "erase_front"){
            if (lst.empty()) cout << "error" << endl; 

            else{
                cout << lst.front() << endl;
                lst.pop_front();
            }
            
        }
        else if(comnd == "erase_back"){
            if (lst.empty()) cout << "error" << endl;
            else{
                cout << lst.back() << endl;
                lst.pop_back();
            }
            
        }
        else if(comnd == "front"){
            if (lst.empty()) cout << "error" << endl;
            else cout << lst.front() << endl;
        }
        else if(comnd == "back"){
            if (lst.empty()) cout << "error" << endl;
            else cout << lst.back() << endl;
        }
        else if(comnd == "clear"){
            if (lst.empty()) cout << "ok" << endl;
            else{
                lst.clear();
                cout << "ok" << endl;
            }
            
        }
        else if(comnd == "exit"){
            cout << "goodbye" << endl;
            break;
        }

    }
    return 0;
}