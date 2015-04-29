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
    IntArray intArrayQuick;
    IntArray intArrayInsertion;
    IntArray intArraySelection;
    IntArray intArrayBubble;

    Timer timer;
    vector<int> levels = { 5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000 };
    //vector<IntArray> arrays = { intArrayQuick, intArrayInsertion, intArraySelection, intArrayBubble};

    for (int i = 0; i < 8 ; i++){
        intArrayQuick = IntArray(levels[i]);
        intArrayQuick.fillWithRandomNumbers();
        intArrayInsertion = IntArray(intArrayQuick);
        intArraySelection = IntArray(intArrayQuick);
        intArrayBubble = IntArray(intArrayQuick);



//        printArray(intArrayQuick);
        timer.start();
        intArrayQuick.quickSort();
        cout << "quickSort Tid = " << timer.stop()/1000000 << " [s]" <<  endl;  // Läs av stopptiden och beräkna skillnaden till starttiden
//        printArray(intArrayQuick);

//        printArray(intArrayInsertion);
        timer.start();
        intArrayInsertion.insertionSort();
        cout << "insertionSort Tid = " << timer.stop()/1000000 << " [s]" <<  endl;  // Läs av stopptiden och beräkna skillnaden till starttiden
//        printArray(intArrayInsertion);

//        printArray(intArraySelection);
        timer.start();
        intArraySelection.selectionSort();
        cout << "selectionSort Tid = " << timer.stop()/1000000 << " [s]" <<  endl;  // Läs av stopptiden och beräkna skillnaden till starttiden
//        printArray(intArraySelection);

//        printArray(intArrayBubble);
        timer.start();
        intArrayBubble.bubbleSort();
        cout << "bubbleSort Tid = " << timer.stop()/1000000 << " [s]" <<  endl;  // Läs av stopptiden och beräkna skillnaden till starttiden
//        printArray(intArrayBubble);
    }



    



	
	return 0;

}
//___________________________________________________________________________________________________________________________________________________
