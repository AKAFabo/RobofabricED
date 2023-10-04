#include "estructuras.h"
#include <vector>
#include "ReadFiles/Clients.h"

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

        //for (const string& element : tokens) {
        //   cout << element << "\t";
        //}

        Client client;

        client.clientID = tokens[0];
        client.clientName = tokens[1];
        client.priority = std::stoi(tokens[2]);

        clientList->insertFirst(client);
        cout << endl;
    }

    inFile.close();

    return clientList;
}

int main(int argc, char *argv[])
{
    

linkedClientList* clientList = buildClientList();
clientList->display();

return 0;
}



