=========================================================
// File: internet.h
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

VoxOperator::VoxOperator(int id, double discountRate, double talkingCharge, double messageCost, double networkCharge…
[4:09 p. m., 18/6/2022] Gonzalo Chavez: VoxOperator
[4:09 p. m., 18/6/2022] Gonzalo Chavez: #pragma once
// =========================================================
// File: vox.h
// Author:
// Date:
// Description:
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
		InternetOperator(int, double, double, double, double, OperatorType);
		InternetOperator(const InternetOperator&);

		//Calculamos
		double calculateTalkingCost(int, int);
		double calculateMessageCost(int, int, int);
		double calculateNetworkCost(double);
};

InternetOperator::InternetOperator(int id, double discountRate, double talkingCharge, double messageCost, double networkCharge, OperatorType type)
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
	
#endif
