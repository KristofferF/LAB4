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

//___________________________________________________________________________________________________________________________________________________

//===< main >========================================================================================================================================
//---------------------------------------------------------------------------------------------------------------------------------------------------
int main(int argc, const char* argv[])
{
    vector<int> levels = { 5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000 };

    for (int level : levels){
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
    }

	return 0;

}
