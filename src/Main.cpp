/*
 * Main.cpp
 *
 *  Created on: may 01, 2015
 *      Author: Kristoffer Freiholtz
 */

//===< include >=====================================================================================================================================
#include "Timer.h"
#include "IntArray.h"
#include <iomanip>
#include <vector>
#include <random>
using namespace std;


void printArray(const IntArray& array) {
    for (size_t i = 0; i < 20; i++) {
        cout << array.getValue(i) << " ";
    }
    cout << endl;
}

default_random_engine generator(random_device{}());

//___________________________________________________________________________________________________________________________________________________

//===< main >========================================================================================================================================
//---------------------------------------------------------------------------------------------------------------------------------------------------
int main(int argc, const char* argv[])
{
//    default_random_engine generator(static_cast<unsigned>(time(0)));
//    default_random_engine generator(random_device{}());

    vector<int> levels = { 5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000 };
    Timer timer;
    double seconds;

    for (int level : levels){
        cout << "--------------------------------------------------" << endl;
        cout << "Testing sorting algorithms for " << level << " entries." << endl << endl;

        IntArray intArray = IntArray(level);

        cout << "Sorting 10 random arrays with bubble sort..." << endl;
        seconds = 0;
        for (size_t i = 0; i < 10; i++){
            intArray.fillWithRandomNumbers(generator);
            timer.start();
            intArray.bubbleSort();
            seconds += (timer.stop() / 1000000);
        }
        intArray.writeToFile("BubbleSort", seconds/10);
        cout << "Average result of bubble sort: " <<  seconds/10 << " [s]" << endl << endl;

        cout << "Sorting 10 random arrays with insertion sort..." << endl;
        seconds = 0;
        for (size_t i = 0; i < 10; i++){
            intArray.fillWithRandomNumbers(generator);
            timer.start();
            intArray.insertionSort();
            seconds += (timer.stop() / 1000000);
        }
        intArray.writeToFile("InsertionSort", seconds/10);
        cout << "Average result of insertion sort: " <<  seconds/10 << " [s]" << endl << endl;

        cout << "Sorting 10 random arrays with selection sort..." << endl;
        seconds = 0;
        for (size_t i = 0; i < 10; i++){
            intArray.fillWithRandomNumbers(generator);
            timer.start();
            intArray.selectionSort();
            seconds += (timer.stop() / 1000000);
        }
        intArray.writeToFile("SelectionSort", seconds/10);
        cout << "Average result of selection sort: " <<  seconds/10 << " [s]" << endl << endl;

        cout << "Sorting 10 random arrays with quick sort..." << endl;
        seconds = 0;
        for (size_t i = 0; i < 10; i++){
            intArray.fillWithRandomNumbers(generator);
            timer.start();
            intArray.quickSort();
            seconds += (timer.stop() / 1000000);
        }
        intArray.writeToFile("QuickSort", seconds/10);
        cout << "Average result of quick sort: " <<  seconds/10 << " [s]" << endl << endl;

//        printArray(intArray);
//        intArray.bubbleSort();
//        printArray(intArray);
//        intArray.fillWithRandomNumbers(generator);
//        printArray(intArray);
//        intArray.bubbleSort();
//        printArray(intArray);
//        intArray.fillWithRandomNumbers(generator);
//        printArray(intArray);
//        intArray.bubbleSort();
//        printArray(intArray);
//        intArray.fillWithRandomNumbers(generator);
//        printArray(intArray);
//        intArray.bubbleSort();
//        printArray(intArray);

    }
	return 0;
}
