#include <iostream>
using namespace std;

struct node {
    int info;
    node* next;
};


struct node* top = NULL;
node* curr, * pre;

void push(int item) {
    node* newnode = new node;
    newnode->info = item;
    newnode->next = top;
    top = newnode;

}

int pop() {
    int item = top->info;
    node* t = top;
    top = top->next;
    delete t;
    return item;
}

void enqueue(int item) {
    node* newnode = new node;
    newnode->info = item;
    newnode->next = NULL;

    if (top == NULL) {
        top = newnode;
        return;
    }
    for (curr = top; curr != NULL; curr = curr->next) {
        pre = curr;
    }
    pre->next = newnode;
}

int dequeue() {

    int item = top->info;
    node* t = top;
    top = top->next;
    delete t;
    return item;
}

bool isEmpty() {
    if (top == NULL)
        return true;
    return false;
}

void traverse() {
    for (curr = top; curr != NULL; curr = curr->next)
        cout << curr->info << " ";
}

int main()
{
    int c;
    int item;
    while (1) {
        cout << "\nSelect \n1 to push\n2 to pop\n"
             <<"3 to enqueue\n4 to dequeue\n"
             <<"5 to traverse \n\n\t-->";
        cin >> c;
        switch (c) {
        case 1:
            cout << "enter the item: ";
            cin >> item;
            push(item);
            break;
        case 2: if (isEmpty()) { cout << "the stack/queue is empty\n"; break; }
              else {
            cout << "the elemnt " << pop() << " has been poped\n"; break;
        }
        case 3:cout << "enter the item: ";
            cin >> item;
            enqueue(item);
            break;
        case 4:if (isEmpty()) { cout << "the stack/queue is empty\n"; break; }
              else {
            cout << "the elemnt " << dequeue() << " has been dequeued\n"; break;
        }
        case 5:if (isEmpty()) { cout << "the stack/queue is empty\n"; break; }
              else {
            cout << "the stack/queue is :\n"; traverse(); break;
        }
        }
    }
    return 0;
}
