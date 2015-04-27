/*
 * IntArray.cpp
 *
 *  Created on: apr 27, 2015
 *      Author: Kristoffer Freiholtz
 */

#include "IntArray.h"
#include <random>
#include <time.h>

IntArray::IntArray() :
        maxSize(0), size(0) {
    arr = nullptr;
}

IntArray::IntArray(int pMaxSize) :
        maxSize(pMaxSize), size(0) {
    arr = new int[maxSize];
}

IntArray::IntArray(const IntArray &a) :
        maxSize(a.maxSize), size(a.size) {
    arr = new int[a.maxSize];
    for (size_t i = 0; i < a.size; i++)
        arr[i] = a.arr[i];
}

IntArray::~IntArray() {
    delete[] arr;
    arr = NULL;
    cout << endl << "Running destructor for IntArray with maxSize= " << maxSize
            << endl;
}

int IntArray::getValue(int idx) const {
    return arr[idx];
}

bool IntArray::addValue(int value) {
    bool valueAdded = false;
    if (size < maxSize) {
        arr[size] = value;
        size++;
        valueAdded = true;
    }
    return valueAdded;
}

const IntArray &IntArray::operator=(const IntArray &a) {
    if (this != &a) {
        delete[] arr;
        arr = new int[a.maxSize];
        maxSize = a.maxSize;
        size = a.size;
        for (size_t i = 0; i < a.size; i++)
            arr[i] = a.arr[i];
    }
    return *this;
}

void IntArray::fillWithRandomNumbers(){
    default_random_engine generator(static_cast<unsigned>(time(0)));
    uniform_int_distribution<int> random(0,maxSize-1);
    for(size_t i = 0; i < maxSize; i++){
        int temp = random(generator);
        addValue(temp);
    }
}

void IntArray::quickSort(){

}

void IntArray::insertionSort(){

}

void IntArray::selectionSort(){

}

void IntArray::bubbleSort(){

}
