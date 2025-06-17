#pragma once

import std;

template <typename ElementType>
class DynamicArray
{
private:
    ElementType* Data;
    int ElementCount;
    int CurrentCapacity;

    void IncreaseCapacity(int MinimumCapacity = 0)
    {
        if (MinimumCapacity <= CurrentCapacity)
            return;

        int NewCapacity;
        if (CurrentCapacity == 0)
            NewCapacity = 1;
        else
            NewCapacity = CurrentCapacity;

        while (NewCapacity < MinimumCapacity)
            NewCapacity *= 2;

        ElementType* newData = new ElementType[NewCapacity];
        for (int Index = 0; Index < ElementCount; ++Index)
            newData[Index] = Data[Index];

        delete[] Data;
        Data = newData;
        CurrentCapacity = NewCapacity;
    }

public:
    DynamicArray() : Data(nullptr), ElementCount(0), CurrentCapacity(0) {}

    ~DynamicArray() { delete[] Data; }

    void Resize(int NewSize)
    {
        if (NewSize > CurrentCapacity)
            IncreaseCapacity(NewSize);
        ElementCount = NewSize;
    }

    void Set(int Index, const ElementType& Value, bool AllowResize = false)
    {
        if (Index < 0)
            return;

        if (Index >= ElementCount)
        {
            if (AllowResize)
                Resize(Index + 1);
            else
                return;
        }

        Data[Index] = Value;
    }

    void Add(const ElementType& Value)
    {
        if (ElementCount >= CurrentCapacity)
            IncreaseCapacity(CurrentCapacity * 2 + 1);
        Data[ElementCount++] = Value;
    }

    void Remove(int Index)
    {
        if (Index < 0 || Index >= ElementCount)
            return;

        for (int LocalIndex = Index; LocalIndex < ElementCount - 1; ++LocalIndex)
            Data[LocalIndex] = Data[LocalIndex + 1];

        --ElementCount;
    }

    int GetSize() const { return ElementCount; }

    int GetCapacity() const { return CurrentCapacity; }

    ElementType& operator[](int Index)
    {
        if (Index < 0 || Index >= ElementCount)
            throw std::out_of_range("IndexNotValid");
        return Data[Index];
    }
};
