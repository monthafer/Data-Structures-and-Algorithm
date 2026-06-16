#include <iostream>
#include <cstdlib>  // For atoi (string to int)
#include <string>

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert new node at the end
    void insert(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        std::cout << "Inserted: " << value << std::endl;
    }

    // Delete a node by value
    void deleteNode(int value) {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        
        // Delete head if it matches
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            std::cout << "Deleted: " << value << std::endl;
            return;
        }

        // Search for the node to delete
        Node* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }

        if (current->next) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            std::cout << "Deleted: " << value << std::endl;
        } else {
            std::cout << "Value not found: " << value << std::endl;
        }
    }

    // Display the list
    void display() const {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

// Main function to handle command-line arguments
int main(int argc, char* argv[]) {
    static LinkedList list;

    if (argc > 1) {
        std::string command = argv[1];
        
        if (command == "insert" && argc == 3) {
            int value = std::atoi(argv[2]);
            list.insert(value);
        } else if (command == "delete" && argc == 3) {
            int value = std::atoi(argv[2]);
            list.deleteNode(value);
        } else if (command == "display") {
            list.display();
        } else {
            std::cerr << "Invalid command or arguments." << std::endl;
        }
    } else {
        std::cerr << "No command provided!" << std::endl;
    }

    return 0;
}
