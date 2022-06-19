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

    int C, O, N, inp, opId, age, discountRate, type, idCustomer1, idCustomer2, time, quantity;
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
        inputFile >> inp;
        switch (inp) {
        case 1:
            inputFile >> name >> age >> operatorId >> limitingAmount;
            customers[customer] = new Customer(customer, name, age, operators[opId], limit);
            customer++;
            break;

        case 2:
            inputFile >> type >> talkingCharge >> messageCost >> networkCharge >> discountRate;
            if (type == 1) {
                operators[op)] = (new VoxOperator(op, talking_charge, message_cost, network_charge, discount_rate, VOX));
                op;
            }
            else if (type == 2) {
                operators[op] = (new InternetOperator(op, talking_charge, message_cost, network_charge, discount_rate, VOX));
                op++;
            }
            break;

        case 3:
            inputFile >> idCustomer1 >> idCustomer2 >> time;
            customers[idCustomer1]->talk(minutes, *customers(idCustomer2));
            break;

        case 4:
            inputFile >> idCustomer1 >> idCustomer2 >> quantity;
            customers[idCustomer1]->message(quantity, *customers(idCustomer2));
            break;

        case 5:
            inputFile >> idCustomer1 >> amount;
            customers(idCustomer1)->connection(amount);
            break;

        case 6:
            inputFile >> idCustomer1 >> amount;
            customers[idCustomer]->pay(amount);
            break;

        case 7:
            inputFile >> idCustomer1 >> idOperator;
            customers[idCustomer1]->setOperator(operators(opId));
            break;

        case 8:
            inputFile >> idCustomer1 >> amount;
            customers[idCustomer1]->getBill()->changeTheLimit(amount);
        default:
            break;
            
        }
    }

    vector<Operator*>::iterator itr;
    for (itr = operators.begin(); itr != operators.end(); itr++) {
        outputFile << (*itr)->toString();

    }

    int mostTime = 0;
    int mostMessages = 0;
    int mostConnection = 0;

    vector<Customer*>::iterator itr;
    for (itr = customers.begin(); itr != customers.end(); itr++) {
        outputFile << (*itr)->toString();

        if ((*itr_c)->getTotalSpentTalkingTime() > mostTime) {
            mostTime = (*itr_c)->getTotalSpentTalkingTime();
            mostTime= (*itr_c)->getId();
        }
        if ((*itr_c)->getTotalMessageSent() > mostMessages) {
            mostMessages = (*itr_c)->getTotalMessageSent();
            mostMessages = (*itr_c)->getId();
        }
        if ((*itr_c)->getTotalInternetUsage() > mostConnection) {
            mostConnection = (*itr_c)->getTotalInternetUsage();
            mostConnection = (*itr_c)->getId();
        }
       

    }
    outputFile << customers[mostTime]->getName() << ": "<< customers[mostTime]->getTotalSpentTalkingTime() << "\n";

    outputFile << customers[mostMessages]->getName() << ":"<< customers[mostMessages]->getTotalMessageSent() << "\n";

    outputFile << customers[mostConnection]->getName() << ": "<< customers[mostConnection]->getTotalInternetUsage() << "\n";


    inputFile.close();
    outputFile.close();


    for (int i = 0; i < customers.size(); ++i) {
        delete customers[i];

    for (int i = 0; i < operators.size(); ++i) {
        delete operators[i];
    }

    customers.clear();
    operators.clear();

    return 0;
}


