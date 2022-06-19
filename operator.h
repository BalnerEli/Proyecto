=========================================================
// File: operator.h
// Author: Eliuth Balderas Neri
// Date: 18/06/2022
// Description: This file implements the class Operator
// =========================================================

#ifndef OPERATOR_H
#define OPERATOR_H

//Bibliotecas
#include <string>
#include <sstream>
#include <iomanip>

//Declaracion de enum
typedef enum { VOX = 1, INTERNET } OperatorType;

//Clase Operator
class Operator {
    
    //Atributos
    protected:
    
        int id;
        double discountRate;
        double talkingCharge;
        double messageCost;
        double networkCharge;
        double totalSpentTalkingTime;
        double totalMessageSent;
        double totalInternetUsage;
        int type;

    //Metodos
    public:
        
        //Constructores
        Operator();
        Operator(int, double, double, double, double, int);
        Operator(const Operator&);

        //Setter de los atributos
        void setId(int);

        //Getters de los atributos
        int getId() const;
        double getDiscountRate() const;
        double getTalkingCharge() const;
        double getMessageCost() const;
        double getNetworkCharge() const;
        double getTotalSpentTalkingTime() const;
        double getTotalMessageSent() const;
        double getTotalInternetUsage() const;
        int getType() const;


        //Agregamos cantidades
        void addTalkingTime(int);
        void addTotalMessageSent(double);
        void addTotalInternetUsage(double);

        //Mostrar datos
        virtual std::string toString() = 0;

        //Metodos abstractos
        virtual double calculateTalkingCost(int, int) = 0;
        virtual double calculateMessageCost(int, int, int) = 0;
        virtual double calculateNetworkCost(double) = 0;

};

//Constructor por defecto
Operator::Operator(){}

//Constructor con parametros
Operator::Operator(int id, double discountRate, double talkingCharge, double messageCost, double networkCharge, int type) {
    
    this->id = id;
    this->discountRate = discountRate;
    this->talkingCharge = talkingCharge;
    this->messageCost = messageCost;
    this->networkCharge = networkCharge;
    this->type = type;
    totalSpentTalkingTime = 0.0;
    totalMessageSent = 0.0;
    totalInternetUsage = 0.0;
}

//Constructor con parametros sobrecargado
Operator::Operator(const Operator& other) {
  
    id = other.id;
    talkingCharge = other.talkingCharge;
    messageCost = other.messageCost;
    networkCharge = other.networkCharge;
    discountRate = other.discountRate;
    type = other.type;
    totalSpentTalkingTime = other.totalSpentTalkingTime;
    totalMessageSent = other.totalMessageSent;
    totalInternetUsage = other.totalInternetUsage;
}

void Operator::setId(int id) {

    this->id = id;

}

//Obtenemos el valor del id
int Operator::getId() const {

    return id;
}

//Obtenemos el valor del discountRate
double Operator::getDiscountRate() const {
    
    return discountRate;
}

//Obtenemos el valor del talkingCharge
double Operator::getTalkingCharge() const {

    return talkingCharge;
}

//Obtenemos el valor del messageCost
double Operator::getMessageCost() const {
    
    return messageCost;
}

//Obtenemos el valor del networkCharge
double Operator::getNetworkCharge() const {
    
    return networkCharge;
}

//Obtenemos el valor del totalSpentTalkingTime
double Operator::getTotalSpentTalkingTime() const {
    
    return totalSpentTalkingTime;
}

//Obtenemos el valor del totalMessageSent
double Operator::getTotalMessageSent() const {
    
    return totalMessageSent;
}

//Obtenemos el valor del totalInternetUsage
double Operator::getTotalInternetUsage() const {
    
    return totalInternetUsage;
}

//Obtenemos el valor del type
int Operator::getType() const {
    
    return type;
}

//Agregamos el total de tiempo en minutos
void Operator::addTalkingTime(int minute) {
   
    if (minute > 0) {
    
        totalSpentTalkingTime += minute;
    
    }

}

//Agregamos el total de mensajes enviados
void Operator::addTotalMessageSent(double quantity) {
  
    if (quantity > 0) {
    
        totalMessageSent += quantity;
    
    }

}

//Agregamos el tota de datos usados
void Operator::addTotalInternetUsage(double amount) {

    if (amount > 0) {

        totalInternetUsage += amount;

    }

}

#endif
