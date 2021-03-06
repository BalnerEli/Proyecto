// =========================================================
// File: internet.h
// Author: Eliuth Balderas Neri
// Date: 18/06/2022
// Description: This file implements the class InternetOperator, which is derived from Operator class
// =========================================================

#ifndef InternetOperator_H
#define InternetOperator_H

#include "operator.h"

//Clase InternetOperator, deriva de Operator
class InternetOperator : public Operator {

	//Atributos
	private:
		
		const double LIMITGB = 10.0;

	//Metodos
	public:
		
		//Constructorees
		InternetOperator(int, double, double, double, double, int);
		InternetOperator(const InternetOperator&);

		//
		std::string toString();

		//Calculamos
		double calculateTalkingCost(int, int);
		double calculateMessageCost(int, int, int);
		double calculateNetworkCost(double);
};

InternetOperator::InternetOperator(int id, double discountRate, double talkingCharge, double messageCost, double networkCharge, int type)
	: Operator(id, discountRate, talkingCharge, messageCost, networkCharge, type) {

}

InternetOperator::InternetOperator(const InternetOperator& other)
	: Operator(other) {

}

double InternetOperator::calculateTalkingCost(int minute, int age) {

	if (minute < 0 and age < 0) {

		return 0.0;

	}else if (minute > 0 and minute < 3) {

		return (talkingCharge * minute) - ((talkingCharge * minute) * discountRate);

	}else {

		return talkingCharge * minute;

	}

}

double InternetOperator:: calculateMessageCost(int quantity, int thisOpId, int otherOpId) {

	if (quantity < 0) {

		return 0.0;

	}else if(quantity > 0 and quantity < 4) {

		return (messageCost * quantity) - ((messageCost * quantity) * discountRate);

	}else {

		return messageCost * quantity;
	}

}

double InternetOperator::calculateNetworkCost(double amount) {

	if (totalInternetUsage > 0) {

		amount = totalInternetUsage * networkCharge;

	}
	else {

		amount  = 0.0;

	}

	return amount;
}

std::string InternetOperator::toString() {

	std::stringstream aux;

	aux << "Operator: " << id << ": " << std::fixed << std::setprecision(2) << totalSpentTalkingTime << ": "
		<< std::fixed << std::setprecision(2) << totalMessageSent << ": "
		<< std::fixed << std::setprecision(2) << ": ";

	return aux.str();
}

#endif
