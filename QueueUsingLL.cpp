#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

class Queue {
public:
    Node* start;
    Node* end;
    int size = 0;

    Queue() {
        start = NULL;
        end = NULL;
    }

    void push(int x) {
        Node* temp = new Node(x);

        if (start == NULL) {
            start = end = temp;
        }
        else {
            end->next = temp;
            end = temp;
        }

        size++;
    }

    void pop() {
        if (start == NULL) {
            cout << "Empty queue" << endl;
            return;
        }

        Node* temp = start;
        start = start->next;

        delete temp;
        size--;

        if (start == NULL) {
            end = NULL;
        }
    }

    int front() {
        if (start == NULL) {
            cout << "Empty queue" << endl;
            return -1;
        }

        return start->val;
    }

    int rear() {
        if (end == NULL) {
            cout << "Empty queue" << endl;
            return -1;
        }

        return end->val;
    }

    int count() {
        return size;
    }

    void traverse() {
        if (start == NULL) {
            cout << "Empty queue" << endl;
            return;
        }

        Node* temp = start;

        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    Queue q;

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    for (int i = 0; i < 10; i++) {
        q.push(arr[i]);
    }

    q.pop();

    q.traverse();

    cout << "front : " << q.front() << endl;
    cout << "rear : " << q.rear() << endl;

    q.pop();

    cout << "size : " << q.count() << endl;

    return 0;
}