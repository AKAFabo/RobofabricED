//Double linkedList, used for loading clients and products in memory

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Client {

    string clientID;
    int priority;
    string clientName;

    Client(string _clientID, int _priority, string _clientName){
        clientID = _clientID;
        priority = _priority;
        clientName = _clientName;
    }
};

struct Product {

    string productID;
    int quantity;
    int fabricationTime;
    string category; //A, B or C
    string locationInStorage;

    Product(string _productID, int _quantity, int _fabricationTime, string _category, string _locationInStorage){
        productID = _productID;
        quantity = _quantity;
        fabricationTime = _fabricationTime;
        category = _category;
        locationInStorage = _locationInStorage;

        /*if (quantity < 0){
            cerr << "Articulo " + productID + " tiene cantidad menor a 0" << endl;
        }
        if (category != "A" || category != "B" || category != "C"){
            cerr << "Articulo " + productID + " tiene una categoria diferente a A,B o C" << endl;
        }*/
    }

    void updateQuantity(int _quantity){
        quantity = quantity - _quantity;
    }
};

struct ClientNode {
    Client client;
    ClientNode* next;
    ClientNode* prev;

    ClientNode(Client cliente) : client(cliente), next(nullptr), prev(nullptr) {}
};

struct linkedClientList {
    
    ClientNode* head;
    ClientNode* tail;

    linkedClientList() : head(nullptr), tail(nullptr) {}

    void insertLast(Client client) {
        ClientNode* newNode = new ClientNode(client);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertFirst(Client client) {
        ClientNode* newNode = new ClientNode(client);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void deleteClient(string clientID) {
        ClientNode* current = head;
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
        ClientNode* current = head;
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

struct ProductNode {
    Product product;
    ProductNode* next;
    ProductNode* prev;

    ProductNode(Product _product) : product(_product), next(nullptr), prev(nullptr) {}
};


struct linkedProductList {
    
    ProductNode* head;
    ProductNode* tail;

    linkedProductList() : head(nullptr), tail(nullptr) {}

    void insertLast(Product product) {
        ProductNode* newNode = new ProductNode(product);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertFirst(Product product) {
        ProductNode* newNode = new ProductNode(product);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void deleteProduct(string _productID) {
        ProductNode* current = head;
        while (current != nullptr) {
            if (current->product.productID == _productID) {
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
        ProductNode* current = head;
        while (current != nullptr) {
            cout << current->product.productID << "\t";
            cout << current->product.quantity << "\t";
            cout << current->product.fabricationTime << "\t";
            cout << current->product.category << "\t";
            cout << current->product.locationInStorage << "\t";
            cout << endl;
            current = current->next;
        }
        std::cout << std::endl;
    }

};