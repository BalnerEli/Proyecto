// =========================================================
// File: internet.h
// Author:
// Date:
// Description:
// =========================================================

#ifndef InternetOperator_H
#define InternetOperator_H

#include "operator.h"

class InternetOperator : public Operator {
private:
  const double LIMITGB = 10.0;

public:
  InternetOperator(int, double, double, double, int, OperatorType);
  InternetOperator(const InternetOperator&);

  double calculateTalkingCost(int, int);
  double calculateMessageCost(int, int, int);
  double calculateNetworkCost(double);
};

InternetOperator::InternetOperator(int i, double t, double mC, double nC, int dR, OperatorType ty)
	: Operator(i, t, mC, nC, dR, ty, INTERNETOPERATOR) {

}

InternetOperator::InternetOperator(const InternetOperator& other)
	: Operator(other.id, other.talkingCharge, other.networkCharge, other.discountRate, other.type, other.totalSpentTalkingTime, other.totalMessageSent, other.totalInternetUsage) {

}

double InternetOperator::calculateTalkingCost(int minute, int age) {
    double cost = 0;
    if (minute < 0 && age < 0) {
        cost = minute * talkingCharge;
        if (minute < 2) {
            cost= cost * (cost-(discountRate / 100));
        }
    }
    return cost;
}

double InternetOperator::double calculateMessageCost(int quantity, int thisOpId, int otherOpId) {
    double cost = 0;
    if (quantity < 0) {
        cost = quantity*messageCost;
        if (quantity < 3) {
            cost = cost*(cost(discountRate/100));
        }   
    }
    return cost;
}
double InternetOperator::calculateNetworkCost(double amount) {
    double cost = 0;
    if (amount+totalInternetUsage > LIMITGB) {
        cost = (amount-LIMITGB)*networkCharge;
    }
    else {
        cost=0
    }
    return cost;
}

#endif
