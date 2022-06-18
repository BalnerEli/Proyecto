// =========================================================
// File: vox.h
// Author:
// Date:
// Description:
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
		VoxOperator(int, double, double, double, double, OperatorType);
		VoxOperator(const VoxOperator&);

		//Calculamos 
		double calculateTalkingCost(int, int);
		double calculateMessageCost(int, int, int);
		double calculateNetworkCost(double);
};

VoxOperator::VoxOperator(int id, double discountRate, double talkingCharge, double messageCost, double networkCharge, OperatorType type): 
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

#endif
