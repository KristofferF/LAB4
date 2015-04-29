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
    for (size_t i = 0; i < array.getSize(); i++) {
        cout << array.getValue(i) << " ";
        if (i % 10 == 0 && i != 0) {
            cout << endl;
        }
    }
    cout << endl;
}

//___________________________________________________________________________________________________________________________________________________

//===< main >========================================================================================================================================
//---------------------------------------------------------------------------------------------------------------------------------------------------
int main(int argc, const char* argv[])
{

    Timer timer;
    vector<int> levels = { 5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000 };
    vector<IntArray> arrays;
    IntArray intArray;

    for (int level : levels){
        cout << "--------------------------------------------------" <<  endl;
        cout << "Testing sorting algorithms for " << level << " entries." <<  endl <<  endl;
        IntArray tmp(level);
        tmp.fillWithRandomNumbers();

        cout << "Sorting " << level << " entries with quick sort" <<  endl;
        intArray = tmp;
        timer.start();
        intArray.quickSort();
        cout << "Quick sort time= " << timer.stop()/1000000 << " [s]" <<  endl <<  endl;

        cout << "Sorting " << level << " entries with insertion sort" <<  endl;
        intArray = tmp;
        timer.start();
        intArray.insertionSort();
        cout << "Insertion sort time = " << timer.stop()/1000000 << " [s]" <<  endl <<  endl;

        cout << "Sorting " << level << " entries with selection sort" <<  endl;
        intArray = tmp;
        timer.start();
        intArray.selectionSort();
        cout << "Selection sort time = " << timer.stop()/1000000 << " [s]" <<  endl <<  endl;

        cout << "Sorting " << level << " entries with bubble sort" <<  endl;
        intArray = tmp;
        timer.start();
        intArray.bubbleSort();
        cout << "Bubble sort time = " << timer.stop()/1000000 << " [s]" <<  endl;
        cout << "--------------------------------------------------" << endl;
    }

	return 0;

}
