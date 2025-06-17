#pragma once

import std;

#include "DynamicArray.h"

#define TEST_CASE(Name) inline void Name()

#define ASSERT_EQ(Actual, Expected)                                                                                    \
    if ((Actual) != (Expected))                                                                                        \
        std::cout << "FAIL___" << __func__ << std::endl;                                                               \
    else                                                                                                               \
        std::cout << "PASS___" << __func__ << std::endl;

#define RUN_TEST(TestFunc) TestFunc()

TEST_CASE(TestAddAndGet)
{
    DynamicArray<int> arr;
    arr.Add(1);
    arr.Add(2);
    ASSERT_EQ(arr.GetSize(), 2);
    ASSERT_EQ(arr[0], 1);
    ASSERT_EQ(arr[1], 2);
}

TEST_CASE(TestResize)
{
    DynamicArray<int> arr;
    arr.Resize(5);
    ASSERT_EQ(arr.GetSize(), 5);
    arr.Resize(10);
    ASSERT_EQ(arr.GetSize(), 10);
    arr.Resize(5);
    ASSERT_EQ(arr.GetSize(), 5);
}

TEST_CASE(TestRemove)
{
    DynamicArray<int> arr;
    arr.Add(1);
    arr.Add(2);
    arr.Add(3);
    arr.Remove(1);
    ASSERT_EQ(arr.GetSize(), 2);
    ASSERT_EQ(arr[1], 3);
}

struct VectorPoint
{
    int X{};
    int Y{};
};

inline bool operator==(const VectorPoint& A, const VectorPoint& B) { return A.X == B.X && A.Y == B.Y; }

TEST_CASE(TestString)
{
    DynamicArray<std::string> arr;
    arr.Add("Hello");
    arr.Add("World");
    ASSERT_EQ(arr[0], "Hello");
    ASSERT_EQ(arr[1], "World");
}

TEST_CASE(TestFloat)
{
    DynamicArray<float> arr;
    arr.Add(3.14f);
    arr.Add(2.71f);
    arr.Add(1);
    ASSERT_EQ(arr[0], 3.14f);
    ASSERT_EQ(arr[1], 2.71f);
    ASSERT_EQ(arr[2], 1.f);
}

TEST_CASE(TestStruct)
{
    DynamicArray<VectorPoint> arr;
    arr.Add({1, 2});
    arr.Add({3, 3});
    ASSERT_EQ(arr.GetSize(), 2);
    VectorPoint point1 = {1, 2};
    ASSERT_EQ(arr[0], point1);
    VectorPoint point2 = {3, 3};
    ASSERT_EQ(arr[1], point2);
}