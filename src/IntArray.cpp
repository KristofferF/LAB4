/*
 * IntArray.cpp
 *
 *  Created on: apr 27, 2015
 *      Author: Kristoffer Freiholtz
 */

#include "IntArray.h"
#include <random>
#include <time.h>
#include <fstream>

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
            << endl << endl;
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

void IntArray::fillWithRandomNumbers() {
    default_random_engine generator(random_device{}());
    uniform_int_distribution<int> random(0, maxSize - 1);
    for (size_t i = 0; i < maxSize; i++) {
        int temp = random(generator);
        arr[i] = temp;
    }
}

double IntArray::quickSort(int n) {
    double seconds = 0;
    for (size_t turn = 0; turn < n; turn ++) {
        fillWithRandomNumbers();
        timer.start();
        quickSortArray(arr, 0, maxSize);
        seconds += (timer.stop() / 1000000);
    }
    writeToFile("QuickSort", seconds/n);
    return seconds/n;
}

void IntArray::quickSortArray(int a[], int first, int last) {
    if (first < last) {
        int low = first;
        int high = last;
        if (a[first] > a[last]) {
            swap(a[first], a[last]);
        }
        do {
            // Gå från från början och sök första värdet som är större än a[first]
            do {
                low++;
            } while (a[low] < a[first]);

            // Gå från från början och sök första värdet som är större än a[first]
            do {
                high--;
            } while (a[high] > a[first]);

            // Byt plats på a[low] och a[high] om low < high
            if (low < high) {
                swap(a[low], a[high]);
            }
        } while (low <= high);        // Fortsätt tills low > high

        swap(a[first], a[high]);    // Placera a[first] i sorterad position

        quickSortArray(a, first, high - 1);   // Sortera vänster dellista
        quickSortArray(a, high + 1, last);    // Sortera höger dellista
    }
}

double IntArray::insertionSort(int n) {
    double seconds = 0;
    for (size_t turn = 0; turn < n; turn ++) {
        fillWithRandomNumbers();
        timer.start();
        for (size_t i = 1; i < maxSize; i++) {
            size_t j = i;
            while (j > 0 && arr[j - 1] > arr[j]) {
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
                j--;
            }
        }
        seconds += (timer.stop() / 1000000);
    }
    writeToFile("InsertionSort", seconds/n);
    return seconds/n;
}

double IntArray::selectionSort(int n) {
    double seconds = 0;
    for (size_t turn = 0; turn < n; turn ++) {
        fillWithRandomNumbers();
        timer.start();
        size_t smallIdx = 0;
        for (size_t i = 0; i < maxSize - 1; i++) {
            smallIdx = i; //Index för det minsta elementet till höger om pos i
            for (size_t j = i + 1; j < maxSize; j++) { // Sök det minsta "osorterade" elementet
                if (arr[j] < arr[smallIdx]) {
                    smallIdx = j; // Spara index för det minsta elementet
                }
            }
            if (smallIdx != i) { // Byt plats om det fanns något mindre än a[i]
                swap(arr[i], arr[smallIdx]);
            }
        }
        seconds += (timer.stop() / 1000000);
    }
    writeToFile("SelectionSort", seconds/n);
    return seconds/n;
}

double IntArray::bubbleSort(int n) {
    double seconds = 0;
    for (size_t turn = 0; turn < n; turn ++) {
        fillWithRandomNumbers();
        timer.start();
        for (size_t pass = 0; pass < maxSize - 1; pass++) {
            for (size_t i = 0; i < maxSize - 1; i++) {
                if (arr[i] > arr[i + 1]) // Jämför elementen i och i+1
                {
                    swap(arr[i], arr[i + 1]); // Byt plats om element i > element i+1
                }
            }
        }
        seconds += (timer.stop() / 1000000);
    }
    writeToFile("BubbleSort", seconds/n);
    return seconds/n;
}

void IntArray::swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void IntArray::writeToFile(string output, double seconds){
    std::ofstream outFile;

    outFile.open(fileName, std::ios_base::app);
    outFile << output << ", " << maxSize << " entries sorted in: " << seconds << " [s]" << endl;
    outFile.close();
}
