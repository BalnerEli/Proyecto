=========================================================
// File: customer.h
// Author: 
// Date: 18/06/2022
// Description:
// =========================================================
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <sstream>
#include <iomanip>
#include "bill.h"
#include "operator.h"

//Clase Customer
class Customer {

	//Atributos
	private:
	
		int id, age, totalSpentTalkingTime;
		double totalMessageSent;
		double totalInternetUsage;
		std::string name;
		Operator* op;
		Bill* bill;
	
	//Metodos
	public:

		//Constructores y destructor
		Customer();
		Customer(int, std::string, int);
		Customer(int, std::string, int, int, int, Operator*, Bill*);
		Customer(const Customer&);
		~Customer();

		//Obtener datos
		void addMessage(double);
		void addNetwork(double);
		int getId() const;
		int getAge() const;
		int getTotalSpentTalkingTime() const;
		double getTotalMessageSent() const;
		double getTotalInternetUsage() const;
		std::string getName() const;
		Operator* getOperator() const;
		Bill* getBill() const;

		//Operaciones
		std::string toString() const;
		void talk(int, Customer&);
		void message(int, const Customer&);
		void connection(double);
};

Customer::Customer(){
	
	bill = new Bill();

}

Customer::Customer(int id, std::string name, int age) {

	this->id = id;
	this->name = name;
	this->age = age;
}

Customer::Customer(int id, std::string name, int age, int totalSpentTalkingTime, int totalInternetUsage, Operator* op, Bill* bill) {
	
	this->id = id;
	this->name = name;
	this->age = age;
	this->totalSpentTalkingTime = totalSpentTalkingTime;
	this->op = op;
	this->bill = bill;
}

Customer::Customer(const Customer& other) {
	
	id = other.id;
	name = other.name;
	age = other.age;
	totalSpentTalkingTime = other.totalSpentTalkingTime;
	op = other.op;
	bill = other.bill;
}

Customer::~Customer() {
	
	delete bill;
}

void Customer::addMessage(double totalMessageSent) {

	this->totalMessageSent = totalMessageSent;

}

void Customer::addNetwork(double totalInternetUsage) {

	this->totalInternetUsage = totalInternetUsage;

}

int Customer::getId() const {
	
	return id;
}

int Customer::getAge() const {
	
	return age;
}

int Customer::getTotalSpentTalkingTime() const {
	
	return totalSpentTalkingTime;
}

double Customer::getTotalMessageSent() const {
	
	return totalMessageSent;
}

double Customer::getTotalInternetUsage() const {
	
	return totalInternetUsage;
}

std::string Customer::getName() const {
	
	return name;
}

Operator* Customer::getOperator()const {
	
	return op;
}

Bill* Customer::getBill()const {
	
	return bill;
}

void Customer::talk(int minutes, Customer& other) {
	
	double cost;
	
	if (minutes > 0 && other.getId() != id) {
	
		cost = other.getOperator()->getTalkingCharge() * minutes;
	}
	
	if (other.getBill()->getLimitAmount() > 0) {

		other.getBill()->add(cost);
		other.addMessage(cost);
	}
}

void Customer::message(int quantity, const Customer& other) {
	
	int total = 0;

	if (quantity > 0 && other.getId() != id) {
	
		total = other.getTotalMessageSent() * quantity;
		
	}
	
	if (other.getBill()->getLimitAmount() > 0) {

		other.getBill()->add(total);
		other.getOperator()->addTotalMessageSent(total);
		addMessage(total);
	}

}

void Customer::connection(double amount) {
	
	double cost;

	if (amount > 0) {
	
		cost = op->getNetworkCharge() * amount;
	}
	
	if (bill->getLimitAmount() > 0) {

		bill->add(cost);
		op->addTotalInternetUsage(cost);
		addNetwork(cost);

	}

}

std::string Customer::toString() const {
	
	std::stringstream aux;

	aux << "Customer # " << id << ":" << "totalMoneySpend:" << bill->getTotalMoneySpent() << "currentDebt:" << bill->getCurrentDebt() << std::endl;
	
	return aux.str();
}

#endif
