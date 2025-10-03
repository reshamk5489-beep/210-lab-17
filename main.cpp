#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
Node *addNodeToFront(Node *head, Node *newNode, int nodeVal);
void deleteNode(Node *current, Node *head, Node *prev, int entry);
void deleteNodeList(Node *head, Node *current);
void insertNode(Node *current, Node *prev);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        head = addNodeToFront(head, newVal, tmp_val);
    }
    output(head);

    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    deleteNode(current, head, prev, entry);
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
    if (i == 0)
        current = current->next;
    else {
        current = current->next;
        prev = prev->next;
    }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;    output(head);

    // deleting the linked list
    deleteNodeList(head, current);
    head = nullptr;
    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

Node *addNodeToFront(Node *head, Node *newNode, int nodeVal)
{
    // adds node at head
    if (!head) { // if this is the first node, it's the new head
        head = newNode;
        newNode->next = nullptr;
        newNode->value = nodeVal;
    }
    else { // its a second or subsequent node; place at the head
        newNode->next = head;
        newNode->value = nodeVal;
        head = newNode;
    }
    return head;
}

void deleteNode(Node *current, Node *head, Node *prev, int entry)
{
    current = head;
    for (int i = 0; i < (entry-1); i++)
    if (i == 0)
    {
        current = current->next;
    }
    else {
        current = current->next;
        prev = prev->next;
    }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
}

void deleteNodeList(Node *head, Node *current)
{
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
}

void insertNode(Node *current, Node *prev, Node *head, int entry)
{
    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
    if (i == 0)
    {
        current = current->next;
    }
    else {
        current = current->next;
        prev = prev->next;
    }
}