#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void pushByIndexfromBack(Node* head, int index, int data) {
   // In the loop check if temp->next->next index times is NULL
    // If it is NULL then insert the node at that position
    // Else keep on moving the temp pointer
    Node* temp = head;
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    //without taking count
    Node* checker = head;
    for (int i = 0; i < index; i++) {
        checker = checker->next;
        if (checker == NULL) {
            cout << "Index out of bound" << endl;
            return;
        }
    }

    while (checker->next != NULL) {
        temp = temp->next;
        checker = checker->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}


int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 4;
    third->next = fourth;

    fourth->data = 5;
    fourth->next = NULL;

    for (Node* temp = head; temp != NULL; temp = temp->next) {
        cout << temp->data << " ";
    }
    cout << endl;
    pushByIndexfromBack(head, 0, 3);

    for (Node* temp = head; temp != NULL; temp = temp->next) {
        cout << temp->data << " ";
    }
    cout << endl;


}

