#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int v) : val(v), next(NULL) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    int lengthfind(Node* node, int count) {
        if (node == NULL)
            return count;
        return lengthfind(node->next, count + 1);
    }

    int length() {
        return lengthfind(head, 0);
    }
};

int main() {
    LinkedList l1;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " numbers";
    for (int i = 0; i < n; i++) {
        cin >> value;
        l1.insertAtTail(value);
    }

    cout << "the length of linked list is: " << l1.length() << endl;

    return 0;
}
