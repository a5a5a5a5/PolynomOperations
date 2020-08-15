#pragma once

#include <sstream>
#include <deque>


namespace Polynom {
class PolynomOperations {
public:
    PolynomOperations(std::pair<std::deque<int>,std::deque<int>>,int);
    PolynomOperations();
    void SetNumerator(std::stringstream&);
    void SetDivisor(std::stringstream&);
    void SetField(int);
    std::deque<int> GetNumerator() const;
    std::deque<int> GetDivisor() const;
    int GetField() const;
    std::pair<std::deque<int>,std::deque<int>> Devide() const;
    int FindReverseNumber(int) const;
    void PrintPolynom(std::deque<int>) const;
    void PrintDivisionResult(std::pair<std::deque<int>,std::deque<int>>) const;
    std::deque<int> GCF() const; //НОД (greatest common factor)
    //
    void PrintDeque(std::deque<int>) const;
    //
private:
    std::deque<int> numerator;
    std::deque<int> divisor;
    int field;
};
}
