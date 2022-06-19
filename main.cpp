//
// =========================================================
// File: main.cpp
// Author: Eliuth Balderas Neri
// Date: 18/06/2022
// Description: This is the implementation of the main file, in which other functions are implemented
// To compile: g++ -std=c++11 main.cpp -o app
// To execute: ./app input_file output_file
// =========================================================
//
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Bill.h"
#include "Operator.h"
#include "VoxOperator.h"
#include "InternetOperator.h"
#include "Customer.h"

using namespace std;

int main(int argc, char* argv[]) {

    ifstream inputFile;
    ofstream outputFile;
/*
    if (argc != 3) {
        
        cout << "usage: " << argv[0] << " input_file output_file\n";
        
     
     return -1;
    }
    */

    inputFile.open(argv[1]);
    
    outputFile.open(argv[2]);
    
    int C, O, N;

    inputFile >> C >> O >> N;

    vector<Customer*> customers(C);
    vector<Operator*> operators(O);

    Bill* bill = nullptr;
    Operator* op;
   
    double discountRate, type,time, quantity, talkingCharge, messageCost, networkCharge, amount, limite;
    int idCustomer1, idCustomer2, id, age, totalSpentTalkingTime, totalInternetUsage;
    string name;
    int option;

    int total = 0, total1 = 0;

    inputFile >> option;
    
    for (int i = 0; i < N; i++) {

        switch (option) {

        case 1:

            inputFile >> id >> name >> age >> time >> discountRate >> talkingCharge >> messageCost >> networkCharge >> type >> limite;

            total++;

            op = new VoxOperator(id, discountRate, talkingCharge, messageCost, networkCharge, type);

            bill = new Bill(limite);

            customers[total] = new Customer(id, name, age, 0, 0, op, bill);

            break;

        case 2:

            inputFile >> id >> talkingCharge >> messageCost >> networkCharge >> discountRate >> type;

            if (type == 1) {

                total1++;

                operators[total1] = new VoxOperator(id, talkingCharge, messageCost, networkCharge, discountRate, VOX);

            }
            else {

                total1++;

                operators[total1] = new InternetOperator(id, talkingCharge, messageCost, networkCharge, discountRate, INTERNET);

            }

            break;

        case 3:

            inputFile >> idCustomer1 >> idCustomer2 >> time;


            customers[idCustomer1]->talk(time, *customers[idCustomer2]);

            break;

        case 4:

            inputFile >> idCustomer1 >> idCustomer2 >> quantity;


            customers[idCustomer1]->message(quantity, *customers[idCustomer2]);

            break;


        case 5:

            inputFile >> idCustomer1 >> amount;


            customers[idCustomer1]->connection(amount);

            break;


        case 6:

            inputFile >> idCustomer1 >> amount;

            customers[idCustomer1]->getBill()->pay(amount);

            break;

        case 7:

            inputFile >> idCustomer1 >> id;


            customers[idCustomer1]->setOperator(id);

            break;


        case 8:

            inputFile >> idCustomer1 >> amount;


            customers[idCustomer1]->getBill()->changeTheLimit(amount);

            break;

        }


    }

    for (int i = 0; i < total1; i++) {
            
        cout << operators[i]->toString() << endl;
        
    }
    
    Customer* mostTalk = *(customers.begin()), * mostMess = *(customers.begin()), * mostGb = *(customers.begin());
        
    vector<Customer*>::iterator itrC;

        
    for (itrC = customers.begin(); itrC != customers.end(); itrC++) {
            
       outputFile << (*itrC)->toString() << endl;

            
        if (mostTalk->getTotalSpentTalkingTime() < (*itrC)->getTotalSpentTalkingTime()) {
                
            mostTalk = (*itrC);
            
        }
            
        if (mostMess->getTotalMessageSent() < (*itrC)->getTotalMessageSent()) {
                
            mostMess = (*itrC);
            
        }
            
        if (mostGb->getTotalInternetUsage() < (*itrC)->getTotalInternetUsage()) {
                
            mostGb = (*itrC);
            
        }
        
    }
            
    outputFile << (mostTalk)->getName() << ": " << (mostTalk)->getTotalSpentTalkingTime() << endl;
        
    outputFile << (mostMess)->getName() << ": " << (mostMess)->getTotalMessageSent() << endl;
        
    outputFile << (mostGb)->getName() << ": " << fixed << setprecision(2) << (mostGb)->getTotalInternetUsage() << endl;
    
    outputFile.close();
    
    inputFile.close();
    
    for (int i = 0; i < operators.size(); i++) {
       
        delete operators[i];

    }
        
    for (int i = 0; i < customers.size(); i++) {
     
        delete customers[i];
    
    }

    return 0;
}

