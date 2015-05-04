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
using namespace std;


void printArray(const IntArray& array) {
    for (size_t i = 0; i < 20; i++) {
        cout << array.getValue(i) << " ";
    }
    cout << endl;
}

//___________________________________________________________________________________________________________________________________________________

//===< main >========================================================================================================================================
//---------------------------------------------------------------------------------------------------------------------------------------------------
int main(int argc, const char* argv[])
{
//    default_random_engine generator(static_cast<unsigned>(time(0)));
    default_random_engine generator(random_device{}());

    vector<int> levels = { 5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000 };

//    for (size_t turn = 0; turn < n; turn ++) {
//            fillWithRandomNumbers();
//            timer.start();
//            for (size_t i = 1; i < maxSize; i++) {
//                size_t j = i;
//                while (j > 0 && arr[j - 1] > arr[j]) {
//                    int tmp = arr[j];
//                    arr[j] = arr[j - 1];
//                    arr[j - 1] = tmp;
//                    j--;
//                }
//            }
//            seconds += (timer.stop() / 1000000);
//        }
//        writeToFile("InsertionSort", seconds/n);
//        return seconds/n;

    for (int level : levels){
        cout << "--------------------------------------------------" << endl;
        cout << "Testing sorting algorithms for " << level << " entries." << endl << endl;

        IntArray intArray = IntArray(level);
        intArray.fillWithRandomNumbers(generator);
        printArray(intArray);
        intArray.bubbleSort();
        printArray(intArray);
        intArray.fillWithRandomNumbers(generator);
        printArray(intArray);
        intArray.bubbleSort();
        printArray(intArray);
        intArray.fillWithRandomNumbers(generator);
        printArray(intArray);
        intArray.bubbleSort();
        printArray(intArray);
        intArray.fillWithRandomNumbers(generator);
        printArray(intArray);
        intArray.bubbleSort();
        printArray(intArray);


        cout << "Sorting 10 random arrays with bubble sort..." << endl;
//        cout << "Average result of bubble sort: " <<  intArray.bubbleSort() << " [s]" << endl << endl;

        cout << "Sorting 10 random arrays with insertion sort..." << endl;
//        cout << "Average result of insertion sort: " << intArray.insertionSort() << " [s]" << endl << endl;

        cout << "Sorting 10 random arrays with selection sort..." << endl;
//        cout << "Average result of selection sort: " << intArray.selectionSort() << " [s]" << endl << endl;

        cout << "Sorting 10 random arrays with quick sort..." << endl;
//        cout << "Average result of quick sort: " << intArray.quickSort() << " [s]" << endl;
        cout << "--------------------------------------------------" << endl;
    }
	return 0;
}
