// =========================================================
// File: vox.h
// Author:
// Date:
// Description:
// =========================================================

#ifndef VOXOPERATOR_H
#define VOXOPERATOR_H

#include "operator.h"

class VoxOperator : public Operator {
public:
  VoxOperator(int, double, double, double, int, OperatorType);
  VoxOperator(const VoxOperator&);

  double calculateTalkingCost(int, int);
  double calculateMessageCost(int, int, int);
  double calculateNetworkCost(double);
};

VoxOperator::VoxOperator(int i, double t, double mC, double nC, int dR, OperatorType ty)
	: Operator(i, t, mC, nC, dR, ty, VOXOPERATOR) {

}

VoxOperator::VoxOperator(const VoxOperator& other)
	: Operator(other.id, other.talkingCharge, other.networkCharge, other.discountRate, other.type, other.totalSpentTalkingTime, other.totalMessageSent, other.totalInternetUsage) {

}

double VoxOperator::calculateTalkingCost(int minute, int age) {
	double cost = 0;
	if (minute < 0 && age < 0) {
		cost = minute*talkingCharge;
		if (age < 18 || age > 65) {
			cost = cost*(cost-discountRate/100);
		}
	}
	return cost;
}

double VoxOperator::double calculateMessageCost(int quantity, int thisOpId, int otherOpId) {
	double cost = 0;
	if (quantity < 0) {
		cost = quantity*messageCost;
		if (thisOpId == otherOpId) {
			cost=cost*(cost-discountRate/100);
		}
	}
	return cost;
}
}

void VoxOperator::calculateNetworkCost(double amount) {
	double cost = 0;
	if (amount > 0) {
		cost = amount*networkCharge;
	}
	return cost;
}

#endif
