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
    LinkedList() { head = NULL; }

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

    bool find(Node* node, int target) {
        if (node == NULL) return false;
        if (node->val == target) return true;
        return find(node->next, target);
    }

    bool searchValue(int target) {
        return find(head, target);
    }
};

int main() {
    LinkedList list;
    int n, value, key;

    cout << "enter elemets: ";
    cin >> n;
    cout << "enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insertAtTail(value);
    }

    cout << "enter value to search: ";
    cin >> key;

    if (list.searchValue(key))
        cout << key << " found in list\n";
    else
        cout << key << " not found in list\n";

    return 0;
}


