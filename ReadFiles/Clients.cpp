#include "ReadFiles/Clients.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

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

        for (const string& element : tokens) {
            cout << element << "\t";
        }
        cout << endl;
    }

    inFile.close();

    return NULL;
}
