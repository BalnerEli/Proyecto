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
		InternetOperator(int, double, double, double, int, OperatorType);
		InternetOperator(const InternetOperator&);

		//Calculamos
		double calculateTalkingCost(int, int);
		double calculateMessageCost(int, int, int);
		double calculateNetworkCost(double);
};

InternetOperator::InternetOperator(int i, double t, double mC, double nC, int dR, OperatorType ty)
	: Operator(i, t, mC, nC, dR, ty) {

}

InternetOperator::InternetOperator(const InternetOperator& other)
	: Operator(other) {

}

double InternetOperator::calculateTalkingCost(int minute, int age) {

}

double InternetOperator:: calculateMessageCost(int quantity, int thisOpId, int otherOpId) {

}

double InternetOperator::calculateNetworkCost(double amount) {

}

#endif
