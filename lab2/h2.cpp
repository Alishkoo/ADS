#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *next;
    Node() : value(0), next(nullptr) {}
    Node(int x) : value(x), next(nullptr) {}
    Node(Node *next) : value(0), next(next) {}
    Node(int x, Node *next) : value(x), next(next) {}
};

Node *insert(Node *head, Node *node, int p)
{
    if (p == 0)
    {
        node->next = head;
        head = node;
        return head;
    }
    else
    {
        Node *cur = head;
        for (int i = 0; i < p - 1; i++)
        {
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
        return head;
    }
};
Node *remove(Node *head, int p)
{
    if (p == 0)
    {
        Node *cur = head;
        head = head->next;
        delete (cur);
        return head;
    }
    else
    {
         Node *cur = head;
        for (int i = 1; i < p; i++)
        {
            cur = cur->next;
        }
        Node *toDel = cur->next;
        cur->next = cur->next->next;
        delete (toDel);
        cur = cur->next->next;
        return head;
    }
};

Node *replace(Node *head, int p1, int p2)
{
    if (p1 == 0)
    {
        Node *toRep = head;
        head = head->next;
        return insert(head, toRep, p2);
    }
    else
    {
        Node *cur = head;
        for (int i = 1; i < p1; i++)
        {
            cur = cur->next;
        }
        Node *toReplace = cur->next;
        cur->next = cur->next->next;
        return insert(head, toReplace, p2);
    }
}

Node *reverse(Node *head)
{
    Node *prev = nullptr, *cur = head, *next;
    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

void print(Node *head)
{
    if (head == nullptr)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        Node *cur = head;
        while (cur)
        {
            cout << cur->value << ' ';
            cur = cur->next;
        }
        cout << endl;
    }
};

Node *cyclic_left(Node *head, int x)
{
    Node *tail = nullptr, *cur = head;
    if (x == 0)
    {
        return head;
    }
    while (cur->next)
    {
        cur = cur->next;
    }
    tail = cur;
    tail->next = head;
    while (x--)
    {
        head = head->next;
        tail = tail->next;
    }
    tail->next = nullptr;

    return head;
};

Node *cyclic_right(Node *head, int x)
{
    int size = 1;
    if (x == 0)
    {
        return head;
    }
    Node *tail = nullptr, *cur = head;
    while (cur->next)
    {
        cur = cur->next;
        size++;
    }
    tail = cur;
    tail->next = head;
    int y = size - x;
    while (y--)
    {
        head = head->next;
        tail = tail->next;
    }
    tail->next = nullptr;

    return head;
};

int main()
{
    Node *head = nullptr;
    while (true)
    {
        int command;
        cin >> command;
        if (command == 0)
        {
            break;
        }
        else if (command == 1)
        {
            int x, p;
            cin >> x >> p;
            head = insert(head, new Node(x), p);
        }
        else if (command == 2)
        {
            int p;
            cin >> p;
            head = remove(head, p);
        }
        else if (command == 3)
        {
            print(head);
        }
        else if (command == 4)
        {
            int p1, p2;
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }
        else if (command == 5)
        {
            head = reverse(head);
        }
        else if (command == 6)
        {
            int x;
            cin >> x;
            head = cyclic_left(head, x);
        }
        else if (command == 7)
        {
            int x;
            cin >> x;
            head = cyclic_right(head, x);
        }
    }
    return 0;
}