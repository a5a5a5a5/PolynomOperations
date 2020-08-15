#include "Polynom.h"
#include <iostream>
#include <sstream>
#include <deque>
#include <algorithm>
#include <numeric>

namespace Polynom {
PolynomOperations::PolynomOperations(std::pair<std::deque<int>,std::deque<int>> constructor,int input_field) {
    numerator=constructor.first;
    divisor=constructor.second;
    field=input_field;
}

PolynomOperations::PolynomOperations() {};
    
void PolynomOperations::SetNumerator(std::stringstream& input) {
    while(input) {
        int local;
        input>>local;
        numerator.push_back(local);
        input.ignore(1);
    }
}

void PolynomOperations::SetDivisor(std::stringstream& input) {
    while(input) {
        int local;
        input>>local;
        divisor.push_back(local);
        input.ignore(1);
    }
}

void PolynomOperations::SetField(int field_value) {
    field=field_value;
};

std::deque<int> PolynomOperations::GetNumerator() const {return numerator;}

std::deque<int> PolynomOperations::GetDivisor() const {return divisor;}

int PolynomOperations::GetField() const {return field;}

std::pair<std::deque<int>,std::deque<int>> PolynomOperations::Devide() const {
    std::deque<int> quotient;
    std::deque<int> excess;
    excess=numerator;
    unsigned long number_of_divisions=excess.size()-divisor.size()+1 ;
    for (int i=0;i<number_of_divisions;i++) {
        int buf=FindReverseNumber(excess[0]);
        quotient.push_back(buf);
        for (int i=0;i<divisor.size();i++) {
            excess[i]-=(divisor[i]*buf)%field;
            if (excess[i]<0) {
                excess[i]+=field;
            }
        }
        excess.pop_front();
        while(true) {
            if (excess[0]==0&&accumulate(excess.begin(),excess.end(),0)!=0) {
                excess.pop_front();
                quotient.push_back(0);
            } else break;
        }
        if (excess.size()<divisor.size()) {
            break;
        }
    }
    if (accumulate(excess.begin(),excess.end(),0)==0) {
        return {quotient,{0}};
    }
    return {quotient,excess};
}

int PolynomOperations::FindReverseNumber(int number) const{
    int step=1;
    while ((divisor[0]*step)%field!=number) {
        step++;
    }
    return step;
}

void PolynomOperations::PrintPolynom(std::deque<int> polynom) const {
    unsigned long polynom_degree=polynom.size()-1;
    std::cout<<polynom[0]<<"x^"<<polynom_degree;
    polynom_degree--;
    for (int i=1;i<polynom.size();i++) {
        std::cout<<"+"<<polynom[i]<<"x^"<<polynom_degree;
        polynom_degree--;
    }
    std::cout<<std::endl;
}

void PolynomOperations::PrintDivisionResult(std::pair<std::deque<int>,std::deque<int>> input) const {
    std::cout<<"Quotient: ";
    PrintPolynom(input.first);
    if (input.second.size()==1&&input.second[0]==0) {
        std::cout<<"Excess: 0"<<std::endl;
    } else {
        std::cout<<"Excess: ";
        PrintPolynom(input.first);
        }
}

void PolynomOperations::PrintDeque(std::deque<int> deque) const {
    for(auto elem:deque) {
        std::cout<<elem<<" ";
    }
    std::cout<<std::endl;
}


std::deque<int>PolynomOperations::GCF() const {
    PolynomOperations step({numerator,divisor},field);
    std::deque<int> empty={0};
    if (step.Devide().second==empty) {
        return step.divisor;
    } else {
        while (true) {
            std::deque<int> excess=step.Devide().second;
            step.numerator=step.divisor;
            step.divisor=excess;
            if (step.Devide().second==empty) {
                break;
            }
        }
    }
    return step.divisor;
}

}
