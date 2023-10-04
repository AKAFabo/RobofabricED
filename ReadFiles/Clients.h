#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Client {

    string clientID;
    int priority;
    string clientName;
};

struct Node {
    Client client;
    Node* next;
    Node* prev;

    Node(Client cliente) : client(cliente), next(nullptr), prev(nullptr) {}
};

struct linkedClientList {
    
    Node* head;
    Node* tail;

    linkedClientList() : head(nullptr), tail(nullptr) {}

    void insertLast(Client client) {
        Node* newNode = new Node(client);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertFirst(Client client) {
        Node* newNode = new Node(client);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void deleteClient(string clientID) {
        Node* current = head;
        while (current != nullptr) {
            if (current->client.clientID == clientID) {
                if (current == head) {
                    head = current->next;
                }
                if (current == tail) {
                    tail = current->prev;
                }
                if (current->prev) {
                    current->prev->next = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    // Function to print the list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->client.clientID << "\t";
            cout << current->client.clientName << "\t";
            cout << current->client.priority << "\t";
            cout << endl;
            current = current->next;
        }
        std::cout << std::endl;
    }

};

