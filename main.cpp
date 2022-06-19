=========================================================
// File: operator.h
// Author: Eliuth Balderas Neri
// Date: 18/06/2022
// Description: This file implements the main file in which other functions are implemented
// =========================================================
    
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

    inputFile.open("input0.txt", ios::in);
    
    if (!inputFile.is_open()) {

        return -1;
    }

    outputFile.open("output.txt", ios::out);
    
    if (!outputFile.is_open()) {

        return -1;

    }

    int C, O, N;

    inputFile >> C >> O >> N;

    vector<Customer*> customers(C);
    vector<Operator*> operators(O);

    Bill* bill = nullptr;
    Operator* op;
   
    double discountRate, time,  talkingCharge, messageCost, networkCharge, amount, limite;
    int idCustomer1, idCustomer2, type, id, quantity, age, totalSpentTalkingTime, totalInternetUsage, operatorId;
    string name;
    int option;

    int total = 0, total1 = 0;

    inputFile >> option;
    
//    for (int i = 0; i < N; i++) {

        switch (option) {

        case 1:

            inputFile >> name >> age >> operatorId >> limite;

            bill = new Bill(limite);
            

            total++;

            customers[total] = new Customer(name, age, operatorId, limite);

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



      /*
    for (int i = 0; i < total1; i++) {
            
        outputFile << operators[i]->toString() << endl;
        
    }
    */
    /*
    Customer *custo1 = nullptr, *custo2 = nullptr, *custo3 = nullptr;

    for (int i = 0; i < total; i++) {
            
       outputFile << customers[i]->toString() << endl;

            
        if (custo1->getTotalSpentTalkingTime() < customers[i]->getTotalSpentTalkingTime()) {
                
            custo1 = customers[i];
            
        }
            
        if (custo2->getTotalMessageSent() < customers[i]->getTotalMessageSent()) {
                
            custo2 = customers[i];
            
        }
            
        if (custo3->getTotalInternetUsage() < customers[i]->getTotalInternetUsage()) {
                
            custo3 = customers[i];
            
        }
        
    }
            
    outputFile << custo1->getName() << ": " << custo1->getTotalSpentTalkingTime() << endl;
        
    outputFile << custo2->getName() << ": " << custo2->getTotalMessageSent() << endl;
        
    outputFile << custo3->getName() << ": " << fixed << setprecision(2) << custo3->getTotalInternetUsage() << endl;
 
    */
    string texto;

    while (!inputFile.eof()) {

        getline(inputFile, texto);

        cout << texto << endl;

    }

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
