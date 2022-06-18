// =========================================================
// File: bill.h
// Author: 
// Date: 18/06/2022
// Description:
// =========================================================

#ifndef BILL_H
#define BILL_H


class Bill {
private:
  double limitAmount, currentDebt, totalMoneySpent;

public:
  Bill();
  Bill(double);
  Bill(const Bill&);

  double getLimitAmount() const;
  double getCurrentDebt() const;
  double getTotalMoneySpent() const;

  void add(double);
  void pay(double);
  void changeTheLimit(double);
  bool check(double) const;
};

Bill::Bill() {
    limitAmount = 0;
    currentDebt = 0;
    totalMoneySpent = 0;
}

// check Bill method
Bill::Bill(double limit) {
    if (limit <= 0) {
        limit = 0;
    }
    limitAmount = limit;
    currentDebt = 0;
    totalMoneySpent = 0;
}

Bill::Bill(const Bill& other) {
    limitAmount = other.limitAmount;
    currentDebt = other.currentDebt;
    totalMoneySpent = other.totalMoneySpent;
}

double Bill::getLimitAmount() const {
    return limitAmount;
}

double Bill::getCurrentDebt() const {
    return currentDebt;
}

double Bill::getTotalMoneySpent() const {
    return totalMoneySpent;
}

void Bill::add(double amount) {
    if (amount <= 0) {
        return currentDebt;
    }
    else return(currentDebt += amount);
}

void Bill::pay(double amount) {
    if (amount <= 0) {
        return currentDebt;
     }
    else return (currentDebt -= amount);
}

void Bill::changeTheLimit(double amount) {
    if (limit > 0 && amount >= currentDebt) {
        limitAmount = amount;
    }
}

bool Bill::check(double amount) const {
    return (amount + currentDebt ) <= limitAmount;
}
#endif
