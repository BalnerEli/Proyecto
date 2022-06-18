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

}

double VoxOperator::calculateMessageCost(int quantity, int thisOpId, int otherOpId) {

}

double VoxOperator::calculateNetworkCost(double amount) {

}

#endif
