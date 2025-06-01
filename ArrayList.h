#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <algorithm>
#include <stdexcept>

template <typename T>
class ArrayList {
public:
    // Default constructor
    ArrayList() : mSize(0), mReserved(10), mElements(new T[10]) {}

    // Constructor with reserved size
    ArrayList(int reserved) : mSize(0), mReserved(reserved), mElements(new T[reserved]) {
        if (reserved < 0) throw std::invalid_argument("Reserved size cannot be negative");
    }

    // Copy constructor
    ArrayList(const ArrayList<T>& c) : mSize(c.mSize), mReserved(c.mReserved), mElements(new T[c.mReserved]) {
        std::copy(c.mElements, c.mElements + c.mSize, mElements);
    }

    // Move constructor
    ArrayList(ArrayList<T>&& c) noexcept : mSize(c.mSize), mReserved(c.mReserved), mElements(c.mElements) {
        c.mSize = 0;
        c.mReserved = 0;
        c.mElements = nullptr;
    }

    // Destructor
    virtual ~ArrayList() {
        delete[] mElements;
    }

    // Copy assignment operator
    ArrayList<T>& operator=(const ArrayList<T>& a) {
        if (this != &a) {
            T* newElements = new T[a.mReserved];
            std::copy(a.mElements, a.mElements + a.mSize, newElements);
            delete[] mElements;
            mElements = newElements;
            mSize = a.mSize;
            mReserved = a.mReserved;
        }
        return *this;
    }

    // Move assignment operator
    ArrayList<T>& operator=(ArrayList<T>&& a) noexcept {
        if (this != &a) {
            delete[] mElements;
            mElements = a.mElements;
            mSize = a.mSize;
            mReserved = a.mReserved;
            a.mElements = nullptr;
            a.mSize = 0;
            a.mReserved = 0;
        }
        return *this;
    }

    // Add element to dynamic array
    void add(const T& element) {
        if (mSize == mReserved)
            extendStorage();
        mElements[mSize] = element;
        ++mSize;
    }

    // Add element at specific index
    void add(int idx, const T& element) {
        if (idx < 0 || idx > mSize) throw std::out_of_range("Index out of bounds");
        if (mSize == mReserved)
            extendStorage();
        for (int i = mSize; i > idx; --i)
            mElements[i] = mElements[i-1];
        mElements[idx] = element;
        ++mSize;
    }

    // Remove element at index
    void remove(int idx) {
        if (idx < 0 || idx >= mSize) throw std::out_of_range("Index out of bounds");
        for (int i = idx; i < mSize-1; ++i)
            mElements[i] = mElements[i+1];
        --mSize;
    }

    // Get const reference to element
    const T& operator[](int idx) const {
        if (idx < 0 || idx >= mSize) throw std::out_of_range("Index out of bounds");
        return mElements[idx];
    }

    // Get reference to element
    T& operator[](int idx) {
        if (idx < 0 || idx >= mSize) throw std::out_of_range("Index out of bounds");
        return mElements[idx];
    }

    // Get current size
    int size() const {
        return mSize;
    }

    // Get reserved size
    int reserved() const {
        return mReserved;
    }

    // Trim to current size
    void trimToSize() {
        if (mSize < mReserved) {
            T* newElements = new T[mSize];
            std::copy(mElements, mElements + mSize, newElements);
            delete[] mElements;
            mElements = newElements;
            mReserved = mSize;
        }
    }

    // Get subarray
    ArrayList<T> subArrayList(int from, int to) const {
        if (from < 0 || to > mSize || from > to) throw std::out_of_range("Invalid range");
        ArrayList<T> result(to - from);
        for (int i = from; i < to; ++i)
            result.add(mElements[i]);
        return result;
    }

    // Convert to C-style array
    T* toArray() const {
        T* result = new T[mSize];
        std::copy(mElements, mElements + mSize, result);
        return result;
    }

private:
    int mSize;
    int mReserved;
    T* mElements;

    // Extend storage capacity
    void extendStorage() {
        int newReserved = (mReserved == 0) ? 10 : mReserved * 2;
        T* newElements = new T[newReserved];
        std::copy(mElements, mElements + mSize, newElements);
        delete[] mElements;
        mElements = newElements;
        mReserved = newReserved;
    }
};

#endif // ARRAYLIST_H
