#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int v) : value(v), next(NULL) {}
};

class LinkedList {
private:
    Node* head;

    void displayReverse(Node* node) {
        if (node == NULL) return;
         displayReverse(node->next);
        cout << node->value << " ";
    }

public:
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

    void displayReverse() {
        displayReverse(head);
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insertAtTail(value);
    }

    cout << "Linked List after reversing: ";
    list.displayReverse();

    return 0;
}
