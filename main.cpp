// =========================================================
// File: main.cpp
// Author:
// Date:
// Description:
// To compile: g++ -std=c++11 main.cpp -o app
// To execute: ./app input_file output_file
// =========================================================
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bill.h"
#include "operator.h"
#include "vox.h"
#include "internet.h"
#include "customer.h"

using namespace std;

int main(int argc, char* argv[]) {
    ifstream inputFile;
    ofstream outputFile;

    int C, O, N, operation, opId, age, discountRate, type, idC1, idC2, time, quantity;
    double limitingAmount, talkingCharge, messageCost, networkCharge, amount;
    string name;
    int j = 0, k = 0;

    if (argc != 3) {
        cout << "usage: " << argv[0] << " input_file output_file\n";
        return -1;
    }

    inputFile.open(argv[1]);
    if (!inputFile.is_open()) {
        cout << argv[0] << ": File \"" << argv[1] << "\" not found\n";
        return -1;
    }

    outputFile.open(argv[2]);

  
    inputFile >> C >> O >> N;

    vector<Customer*> customers(C);
    vector<Operator*> operators(0);


    for (int i = 0; i < N; i++) {
        inputFile >> operation;
        switch (operation) {
        case 1:
            inputFile>>name>>age>>operatorId>>limitingAmount;
            
            break;

        case 2:
            inputFile >> type >> talkingCharge >> messageCost >> networkCharge >> discountRate;
            break;

        case 3:
            inputFile >> idCustomer1 >> idCustomer2 >> time;
            break;

        case 4:
            inputFile >> idCustomer1 >> idCustomer2 >> quantity;
            break;

        case 5:
            inputFile >> idCustomer >> amount;
            break;

        case 6:
            inputFile >> idCustomer >> amount;
            break;

        case 7:
            inputFile >> idCustomer >> idOperator;
            break;

        case 8:
            inputFile >> idCustomer >> amount;
            
        }
    }

    vector<Operator*>::iterator itr;
    for (itr = operators.begin(); itr != operators.end(); itr++) {
        outputFile << (*itr)->toString();
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
  return 0;
}
