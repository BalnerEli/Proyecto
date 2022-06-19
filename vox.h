=========================================================
// File: vox.h
// Author: Eliuth Balderas Neri
// Date: 18/06/2022
// Description: This file implements the class VoxOperator, which is derived from Operator class
// =========================================================

#ifndef VOXOPERATOR_H
#define VOXOPERATOR_H

#include "operator.h"

//Clase VoxOperator, deriva de la clase Operatoe
class VoxOperator : public Operator {

	//Metodos
	public:
		
		//Constructorees
		VoxOperator(){}
		VoxOperator(int, double, double, double, double, int);
		VoxOperator(const VoxOperator&);
		
		std::string toString();

		//Calculamos 
		double calculateTalkingCost(int, int);
		double calculateMessageCost(int, int, int);
		double calculateNetworkCost(double);
};

VoxOperator::VoxOperator(int id, double discountRate, double talkingCharge, double messageCost, double networkCharge, int type): 
	Operator(id, discountRate, talkingCharge, messageCost, networkCharge, type) {

}

VoxOperator::VoxOperator(const VoxOperator& other)
	: Operator(other) {

}

double VoxOperator::calculateTalkingCost(int minute, int age) {

	if (minute < 0 and age < 0) {

		return 0.0;

	}else if (age < 18 or age > 65) {
			
		return (talkingCharge * minute) - ((talkingCharge * minute) * discountRate);
	}
	
}

double VoxOperator::calculateMessageCost(int quantity, int thisOpId, int otherOpId) {
	
	if (quantity < 0.0) {

		return 0.0;

	}else if (thisOpId == otherOpId) {
			
		return (messageCost * quantity) - ((messageCost * quantity) * discountRate);
	
	}else {

		return messageCost * quantity;

	}
	

}

double VoxOperator::calculateNetworkCost(double amount) {
	
	if (totalInternetUsage > 0.0) {

		amount =  totalInternetUsage * networkCharge;
	
	}

	return amount;

}

std::string VoxOperator::toString(){

	std::stringstream aux;

	aux << "Operator: " << id << ": " << std::fixed << std::setprecision(2) << totalSpentTalkingTime << ": "
		<< std::fixed << std::setprecision(2) << totalMessageSent << ": "
		<< std::fixed << std::setprecision(2) << ": ";

	return aux.str();
}

#endif
