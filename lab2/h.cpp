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
            cout << -1 << endl;
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
    void shift_left(int k){
        while(k--){
            this->tail->next = this->head;
            this->tail = this->head;
            this->head = this->head->next;
            this->tail->next = NULL;

        }
    }

    // task from the lab
    void shift_right(int k){
        if (head == nullptr || k == 0){
            return;
        }

        int length = 1; 
        Node* cur = head;

        while(cur->next){
            cur = cur->next;
            length++;
        }

        k = k % length;

        if(k == 0){
            return;
        }

        Node* new_tail = head;

        for(int i = 1; i < length - k; i++){
            new_tail = new_tail->next;
        }

        Node* new_head = new_tail->next;
        new_tail->next = nullptr;
        cur->next = head;
        head = new_head;
        tail = new_tail;
    }

    // task from the lab
    void insertAt(int pos, int data){
        Node* newNode = new Node(data);

        if (pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
        }   

        Node* prev = nullptr;
        Node* current = head;
        int curpos = 0;

        while(curpos < pos && current != nullptr){
            prev = current;
            current = current->next;
            curpos++;
        }

        if(curpos == pos){
            prev->next = newNode;
            newNode->next = current;
        }
        else{
            delete newNode;
            cout << "ERROR OUT OF BOUNDS" << endl;
        }

    }

    void removeAt(int pos) {
        if (pos < 0 || head == nullptr) {
            return; // Nothing to remove
        }

        if (pos == 0) {
            this->pop_front(); // Handle removal of the first node
            return;
        }

        Node* cur = head;
        Node* prev = nullptr;
        int currentPos = 0;

        while (cur != nullptr && currentPos < pos) {
            prev = cur;
            cur = cur->next;
            currentPos++;
        }

        if (cur == nullptr) {
            return; // Position is out of bounds
        }

        prev->next = cur->next;
        delete cur;
    }

    void reverse(){
        Node* prev = nullptr;
        Node* cur = head;
        Node* next = nullptr;

        while(cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        head = prev;
    }

    void replace(int p1, int p2){
        if (p1 == p2 || this->head == NULL) return;

        Node* prevP1 = nullptr;
        Node* curP1 = this->head;
        int countP1 = 0;

        while(curP1 && countP1 < p1){
            prevP1 = curP1;
            curP1 = curP1->next;
            countP1++;
        }

        
        if(prevP1 == nullptr){
            // if the prev in the first position
            head = curP1->next;
        }
        else{
            prevP1->next = curP1->next;
        }

        Node* prevP2 = nullptr;
        Node* curP2 = this->head;
        int countP2 = 0;

        while (curP2 && countP2 < p2) {
            prevP2 = curP2;
            curP2 = curP2->next;
            countP2++;
        }

        if (prevP2 == nullptr) {
            // Update head if p2 is the first element.
            curP1->next = head;
            head = curP1;
        } else {
            curP1->next = curP2;
            prevP2->next = curP1;
        }
    }

};

int main(){
    OneLinkedList lst;

     while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, pos; cin >> x >> pos;
            lst.insertAt(pos, x);
        }else if (command == 2){
            int pos; cin >> pos;
            lst.removeAt(pos);
        }else if (command == 3){
            lst.getALL();
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            lst.replace(p1,p2);
        }else if (command == 5){
            lst.reverse();
        }else if (command == 6){
            int x; cin >> x;
            lst.shift_left(x);
        }else if (command == 7){
            int x; cin >> x;
            lst.shift_right(x);
        }   
    }
    return 0;
}