#include "Colas.h"
#include <vector>
#include "LinkedList.h"

linkedClientList* buildClientList(){

    linkedClientList * clientList = new linkedClientList();

    ifstream inFile("Clientes.txt");

    if(!inFile.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        return NULL;
    }

    string line;

    while(getline(inFile, line)) {

        istringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, '\t')) {
            tokens.push_back(token);
        }

        string _clientID = tokens[0];
        string _clientName = tokens[1];
        int _priority = std::stoi(tokens[2]);

        Client client(_clientID, _priority, _clientName);
        clientList->insertFirst(client);

    }

    inFile.close();

    return clientList;
}

linkedProductList* buildProductList(){

    linkedProductList * productList = new linkedProductList();

    ifstream inFile("Productos.txt");

    if(!inFile.is_open()){
        cerr << "Error al abrir el archivo" << endl;
        return NULL;
    }

    string line;

    while (getline(inFile, line)) {
        istringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, '\t')){
            tokens.push_back(token);

        }
        /*for (size_t i = 0; i < tokens.size(); i++) {
        cout << "tokens[" << i << "] = " << tokens[i] << "\t";
        }
        cout << endl;*/

        
        string _productID = tokens[0];
        int _quantity = std::stoi(tokens[1]);
        int _fabricationTime = std::stoi(tokens[2]);
        string _category = tokens[3];
        string _locationInStorage = tokens[4];

        Product product(_productID, _quantity, _fabricationTime, _category, _locationInStorage);
        productList->insertFirst(product);

    }
    inFile.close();
    return productList;
}


int main(int argc, char *argv[])
{
    

linkedClientList* clientList = buildClientList();
clientList->display();

linkedProductList* productList = buildProductList();
productList->display();


return 0;
}



