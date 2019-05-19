//
// Created by admin on 19.05.2019.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ARR.h"

using testing::Eq;
namespace {
    class ClassDeclaration:public testing::Test{
    public:
        ARR <int >listInt;
        ARR <float >listFloat;
        ClassDeclaration(){
            listInt;
            listFloat;
        }
    };
}

TEST_F(ClassDeclaration, nameOfTheTest1){
    listInt.push_back(1);
    listInt.push_back(2);
    listInt.push_back(3);
    ASSERT_EQ(listInt.get_size(),3);
}

TEST_F(ClassDeclaration, nameOfTheTest2){
    listInt.push_back(1);
    listInt.push_back(2);
    listInt.push_back(3);
    if (listInt.getForIndex(1)== listInt.getHead())
        SUCCEED();
    else
        FAIL();
}

TEST_F(ClassDeclaration, nameOfTheTest3){
    listInt.push_back(1);
    listInt.push_back(2);
    listInt.push_front(3);
    if (!listInt.isEmpty())
        SUCCEED();
    else
        FAIL();
}

TEST_F(ClassDeclaration, nameOfTheTest4){
    listInt.push_back(1);
    listInt.push_back(2);
    listInt.push_front(3);
    listInt.clear();
    if (listInt.isEmpty())
        SUCCEED();
    else
        FAIL();
}

TEST_F(ClassDeclaration, nameOfTheTest5){
    listInt.push_back(1);
    listInt.push_back(2);
    listInt.push_front(3);
    listInt.set(2, 8);
    if (listInt.getHead()->next==listInt.getForIndex(2))
        SUCCEED();
    else
        FAIL();
}
TEST_F(ClassDeclaration, nameOfTheTest6){
    listInt.push_back(1);
    listInt.push_back(2);
    listInt.push_front(3);
    listInt.insert(2, 8);
    if (listInt.getHead()->next==listInt.getForIndex(2))
        SUCCEED();
    else
        FAIL();
}
TEST_F(ClassDeclaration, nameOfTheTest7){
    listInt.push_back(1);
    listInt.push_back(2);
    listInt.push_front(3);
    listInt.remove(2);
    if (listInt.get_size()==2)
        SUCCEED();
    else
        FAIL();
}
TEST_F(ClassDeclaration, nameOfTheTest8){
    listInt.push_back(1);
    listInt.push_back(2);
    listInt.push_front(3);
    listInt.pop_front();
    if (listInt.get_size()==2)
        SUCCEED();
    else
        FAIL();
}
TEST_F(ClassDeclaration, nameOfTheTest9){
    listInt.push_back(1);
    listInt.push_back(2);
    listInt.push_front(3);
    listInt.pop_back();
    if (listInt.get_size()==2)
        SUCCEED();
    else
        FAIL();
}

