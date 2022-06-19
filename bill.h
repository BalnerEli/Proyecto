// =========================================================
// File: bill.h
// Author: Eliuth Balderas Neri
// Date: 18/06/2022
// Description: This file implements the class Bill
// =========================================================

#ifndef BILL_H
#define BILL_H

//Clase Bill
class Bill {
    
    //Atributod
    private:
        
        double limitAmount, currentDebt, totalMoneySpent;

    //Metodos
    public:
       
        //Constructores
        Bill();
        Bill(double);
        Bill(const Bill&);

        //Obtener valores
        double getLimitAmount() const;
        double getCurrentDebt() const;
        double getTotalMoneySpent() const;

        //Metodos de operaciones
        double add(double);
        double pay(double);
        double changeTheLimit(double);
        bool check(double) const;
};

Bill::Bill() {
    
    limitAmount = 0;
    currentDebt = 0;
    totalMoneySpent = 0;
}

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

double Bill::add(double amount) {
    
    if (amount <= 0) {
        
        return currentDebt;
    
    }else {

        return currentDebt += amount;

    }
}

double Bill::pay(double amount) {
    
    if (amount <= 0) {
    
        return currentDebt;
    }
    else {

        return currentDebt -= amount;

    }

}

double Bill::changeTheLimit(double amount) {

    if (amount <= 0) {

        return currentDebt;

    }else {

        if (limitAmount > currentDebt) {

            limitAmount += amount;

        }
    }

}


bool Bill::check(double amount) const {

    return currentDebt + amount;

}

#endif
