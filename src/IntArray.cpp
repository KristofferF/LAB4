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
    quickSort1(arr, 0, maxSize);
}


void IntArray::quickSort1(int a[], int first, int last){
    if(first < last){
        int low  = first;
        int high = last;
        if(a[first] > a[last]){
            swap(a[first], a[last]);
        }
        do {
            // Gå från från början och sök första värdet som är större än a[first]
            do{ low++; }while(a[low] < a[first]);

            // Gå från från början och sök första värdet som är större än a[first]
            do{ high--;}while(a[high] > a[first]);

            // Byt plats på a[low] och a[high] om low < high
            if(low < high){
                swap(a[low], a[high]);
            }
        }while(low <= high);        // Fortsätt tills low > high

        swap(a[first], a[high]);    // Placera a[first] i sorterad position

        quickSort1(a, first, high-1);   // Sortera vänster dellista
        quickSort1(a, high+1, last);    // Sortera höger dellista
    }
}

void IntArray::insertionSort(){

}

void IntArray::selectionSort(){

}

void IntArray::bubbleSort(){

}
