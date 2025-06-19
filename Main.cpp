import std;

#include "MacrosTest.h"
#include "DynamicArray.h"

int main()
{
    RUN_TEST(TestAddAndGet);
    RUN_TEST(TestResize);
    RUN_TEST(TestRemove);
    RUN_TEST(TestString);
    RUN_TEST(TestFloat);
    RUN_TEST(TestStruct);
    RUN_TEST(TestCapacity);
    return 0;
}