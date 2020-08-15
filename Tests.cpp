//
//  tests.cpp
//  PolynomDivision
//
//  Created by Павел Дмитриев on 09.08.2020.
//

#include <stdio.h>
#include "tests.h"
#include "Polynom.h"
#include "test_runner.h"

using namespace Polynom;

void DivisionAndGcfTest1() {
    PolynomOperations item;
    std::stringstream input_numerator("2 4 4 2 3");
    item.SetNumerator(input_numerator);
    std::stringstream input_divisor("2 2 1");
    item.SetDivisor(input_divisor);
    item.SetField(5);
    std::deque<int> expected_quotient={1,1,3};
    std::deque<int> expected_excess={0};
    std::deque<int> expected_gcf={2,2,1};
//    std::pair<std::deque<int>,std::deque<int>> result=item.Devide();
//    item.PrintDivisionResult(result);
//    std::cout<<"GCF: ";
//    item.PrintPolynom(item.GCF());
    ASSERT_EQUAL(expected_quotient, item.Devide().first);
    ASSERT_EQUAL(expected_excess, item.Devide().second);
    ASSERT_EQUAL(expected_gcf, item.GCF());
}

void DivisionAndGcfTest2() {
    PolynomOperations item;
    std::stringstream input_numerator("1 0 2 1 2 3 0");
    item.SetNumerator(input_numerator);
    std::stringstream input_divisor("1 0 0 1 4 1");
    item.SetDivisor(input_divisor);
    item.SetField(5);
    std::deque<int> expected_quotient={1,0};
    std::deque<int> expected_excess={2,0,3,2,0};
    std::deque<int> expected_gcf={1,0,4,1};
    std::pair<std::deque<int>,std::deque<int>> result=item.Devide();
    //item.PrintDivisionResult(result);
    //std::cout<<"GCF: ";
    //item.PrintPolynom(item.GCF());
    //ASSERT_EQUAL(expected_quotient, item.Devide().first);
//    item.PrintPolynom(result.first);
//    item.PrintPolynom(result.second);
    ASSERT_EQUAL(expected_quotient, item.Devide().first);
    ASSERT_EQUAL(expected_excess, item.Devide().second);
    ASSERT_EQUAL(expected_gcf, item.GCF());
}

void DivisionAndGcfTest3() {
    PolynomOperations item;
    std::stringstream input_numerator("1 2 4 4");
    item.SetNumerator(input_numerator);
    std::stringstream input_divisor("3 3 1");
    item.SetDivisor(input_divisor);
    item.SetField(5);
    std::deque<int> expected_quotient={2,2};
    std::deque<int> expected_excess={1,2};
    std::deque<int> expected_gcf={2};
//    std::pair<std::deque<int>,std::deque<int>> result=item.Devide();
//    item.PrintDivisionResult(result);
//    std::cout<<"GCF: ";
//    item.PrintPolynom(item.GCF());
    ASSERT_EQUAL(expected_quotient, item.Devide().first);
    ASSERT_EQUAL(expected_excess, item.Devide().second);
    ASSERT_EQUAL(expected_gcf, item.GCF());
}

void DivisionAndGcfTest4() {
    PolynomOperations item;
    std::stringstream input_numerator("1 1 1 2 0 2 4");
    item.SetNumerator(input_numerator);
    std::stringstream input_divisor("1 0 0 3 3 2");
    item.SetDivisor(input_divisor);
    item.SetField(5);
    std::deque<int> expected_quotient={1,1};
    std::deque<int> expected_excess={1,4,4,2,2};
    std::deque<int> expected_gcf={2};
//    std::pair<std::deque<int>,std::deque<int>> result=item.Devide();
//    item.PrintDivisionResult(result);
//    std::cout<<"GCF: ";
//    item.PrintPolynom(item.GCF());
    ASSERT_EQUAL(expected_quotient, item.Devide().first);
    ASSERT_EQUAL(expected_excess, item.Devide().second);
    ASSERT_EQUAL(expected_gcf, item.GCF());
}

void DivisionAndGcfTest5() {
    PolynomOperations item;
    std::stringstream input_numerator("3 0 3 3 0 3");
    item.SetNumerator(input_numerator);
    std::stringstream input_divisor("2 2 0 2 2");
    item.SetDivisor(input_divisor);
    item.SetField(5);
    std::deque<int> expected_quotient={4,1};
    std::deque<int> expected_excess={1,0,0,1};
    std::deque<int> expected_gcf={1,0,0,1};
//    std::pair<std::deque<int>,std::deque<int>> result=item.Devide();
//    item.PrintDivisionResult(result);
//    std::cout<<"GCF: ";
//    item.PrintPolynom(item.GCF());
    ASSERT_EQUAL(expected_quotient, item.Devide().first);
    ASSERT_EQUAL(expected_excess, item.Devide().second);
    ASSERT_EQUAL(expected_gcf, item.GCF());
}

void DivisionAndGcfTest6() {
    PolynomOperations item;
    std::stringstream input_numerator("1 0 1 0 1 0");
    item.SetNumerator(input_numerator);
    std::stringstream input_divisor("1 0 0 1 1");
    item.SetDivisor(input_divisor);
    item.SetField(5);
    std::deque<int> expected_quotient={1,0};
    std::deque<int> expected_excess={1,4,0,0};
    std::deque<int> expected_gcf={3};
//    std::pair<std::deque<int>,std::deque<int>> result=item.Devide();
//    item.PrintDivisionResult(result);
//    std::cout<<"GCF: ";
//    item.PrintPolynom(item.GCF());
    ASSERT_EQUAL(expected_quotient, item.Devide().first);
    ASSERT_EQUAL(expected_excess, item.Devide().second);
    ASSERT_EQUAL(expected_gcf, item.GCF());
}

void TestsStart() {
    TestRunner tr;
    RUN_TEST(tr, DivisionAndGcfTest1);
    RUN_TEST(tr, DivisionAndGcfTest2);
    RUN_TEST(tr, DivisionAndGcfTest3);
    RUN_TEST(tr, DivisionAndGcfTest4);
    RUN_TEST(tr, DivisionAndGcfTest5);
    RUN_TEST(tr, DivisionAndGcfTest6);
}
