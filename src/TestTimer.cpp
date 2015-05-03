//###################################################################################################################################################
// Filnamn: TestTimer.cpp
// Skrivit av : Mikael Nilsson
// Justerad av: Per Ekeroot 2012-02-07
// Skapat datum: 2011-08-03
//###################################################################################################################################################

//===< include >=====================================================================================================================================
#include "Timer.h"
#include "IntArray.h"
#include <iostream>
#include <iomanip>
#include <string>
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

    vector<int> levels = { 5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000 };

    for (size_t i = 0; i < 2; i++){
        int level = levels[i];
        cout << "--------------------------------------------------" << endl;
        cout << "Testing sorting algorithms for " << level << " entries." << endl << endl;

        IntArray intArray = IntArray(level);

        cout << "Sorting 10 random arrays with bubble sort..." << endl;
        cout << "Average result of bubble sort: " <<  intArray.bubbleSort(10) << " [s]" << endl << endl;

        cout << "Sorting 10 random arrays with insertion sort..." << endl;
        cout << "Average result of insertion sort: " << intArray.insertionSort(10) << " [s]" << endl << endl;

        cout << "Sorting 10 random arrays with selection sort..." << endl;
        cout << "Average result of selection sort: " << intArray.selectionSort(10) << " [s]" << endl << endl;

        cout << "Sorting 10 random arrays with quick sort..." << endl;
        cout << "Average result of quick sort: " << intArray.quickSort(10) << " [s]" << endl;
        cout << "--------------------------------------------------" << endl;

//        for (size_t j = 0; j < 10; j++) {
//            intArray.fillWithRandomNumbers();
//            printArray(intArray);

//            cout << "Sorting " << level << " entries with quick sort" << endl;
//            printArray(intArray);
//            timer.start();
//            intArray.quickSort();
//            cout << "Run " << j << ", " <<  level << " entries, " << "Quick sort time = " << timer.stop() / 1000000 << " [s] " << endl << endl;
//            printArray(intArray);

//            cout << "Sorting " << level << " entries with insertion sort" << endl;
//            intArray = tmp;
//            timer.start();
//            intArray.insertionSort();
//            cout << "Insertion sort time = " << timer.stop() / 1000000 << " [s]" << endl << endl;
//
//            cout << "Sorting " << level << " entries with selection sort" << endl;
//            intArray = tmp;
//            timer.start();
//            intArray.selectionSort();
//            cout << "Selection sort time = " << timer.stop() / 1000000 << " [s]" << endl << endl;
//
//            cout << "Sorting " << level << " entries with bubble sort" << endl;
//            intArray = tmp;
//            timer.start();
//            intArray.bubbleSort();
//            cout << "Bubble sort time = " << timer.stop() / 1000000 << " [s]" << endl;
//            cout << "--------------------------------------------------" << endl;
//        }
    }

	return 0;

}
