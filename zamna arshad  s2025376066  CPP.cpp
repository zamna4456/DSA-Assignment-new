#include <iostream>
using namespace std;

// Q5.A.1
// A Singly Linked List is a collection of nodes where each node contains data
// and a pointer to the next node.
// Unlike arrays (which use contiguous memory), linked list nodes are stored
// in non-contiguous memory and connected using pointers.

// Q5.A.2
// Insertion at head: O(1) ? direct insertion, no traversal needed.
// Insertion at tail: O(n) ? must traverse to the last node.
// Deletion by value: O(n) ? must search the node before deleting.

// Q5.A.3
// If we remove a node without calling delete, the memory is not freed.
// This causes a memory leak.
// To avoid it, always use delete on the removed node.

struct Node {
    int data;
    Node* next;
};
class LinkedList {
private:
    Node* head;
public:
    // Constructor
    LinkedList()
	 {
        head = NULL;
    }

    // Q5.B.2 - Insert at Head
    void insertAtHead(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

    // Q5.B.2 - Insert at Tail
    void insertAtTail(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;
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
    // Q5.B.2 - Display list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Q5.B.3 - Delete by value
    void deleteByValue(int val) {

        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        // Case 1: delete head
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted value: " << val << endl;
            return;
        }

        // Case 2: search in list
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != val) {
            temp = temp->next;
        }

        // Value not found
        if (temp->next == NULL) {
            cout << "Value not found: " << val << endl;
            return;
        }

        // Delete node
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << "Deleted value: " << val << endl;
    }
};
int main() {
    LinkedList list;
    // Q5.B.4 - Insert nodes (mix of head and tail)
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtHead(5);
    list.insertAtTail(30);
    list.insertAtHead(1);
    cout << "Initial List: ";
    list.display();
    // Delete existing value
    list.deleteByValue(20);
    // Attempt to delete non-existing value
    list.deleteByValue(100);
    cout << "Final List: ";
    list.display();
    return 0;
}
