#include<iostream>


// Definition of the Node structure for the linked list
struct Node {
int data;
struct Node *next;
};


// Function to add a new node with the given data to the end of the linked list
void appendLinkedList(struct Node **head, int data) {

    struct Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    // If the list is empty, make the new node the head
    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    // Otherwise, traverse to the end of the list
    struct Node *currentNode = *head;
    while(currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }
    // Append the new node at the end of the list
    currentNode->next = newNode;
}


// Function to delete a node at a specific position in the linked list
void delete_with_position(struct Node **head, int position) {
    
    // Check if the position is valid
    if(position < 0) {
        std::cout << "The position you entered is out of the bounds of the linked list!\n";
        return;
    }

    struct Node *deleteNode = *head; // Node to be deleted
    struct Node *preNode = nullptr; // Previous node

    // Traverse to the node just before the position to be deleted
    for(int i = 0; i < position; i++) {
        preNode = deleteNode;
        deleteNode = deleteNode->next; 
        // Check if the position is out of bounds
        if(deleteNode == nullptr) {
            std::cout << "The position you entered is out of the bounds of the linked list!\n";
            return;
        }
    }
    
    // If the node to be deleted is the head
    if(preNode == nullptr) {
        *head = (*head)->next; // Move the head to the next node
        delete preNode; // Delete the old head node
        return;
    }

    // Update the previous node's next pointer to skip the deleted node
    preNode->next = deleteNode->next;
    delete deleteNode;
}


// Function to print all elements of the linked list
void printList(struct Node *head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "\n";
}


int main()
{
    struct Node *head = nullptr;

    appendLinkedList(&head, 10);
    appendLinkedList(&head, 12);
    appendLinkedList(&head, 14);
    appendLinkedList(&head, 16);

    std::cout << "The linked list before delete: ";
    printList(head);

    int positionIndex;
    std::cout << "Enter a position index: \n";
    std::cin >> positionIndex;

    delete_with_position(&head, positionIndex);

    std::cout << "The linked list after delete: ";
    printList(head);

    return 0;
}