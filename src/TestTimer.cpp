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
using namespace std;
//___________________________________________________________________________________________________________________________________________________

//===< main >========================================================================================================================================
//---------------------------------------------------------------------------------------------------------------------------------------------------
int main(int argc, const char* argv[])
{
	Timer timer;                                                  // Skapa ett Timer-objekt

	timer.start();                                                // Starta tidtagningen
//	cout << "Tryck ENTER!!" << endl;
//	string s;
//	while(!getline(cin,s));                                       // Vänta på att användaren trycker på ENTER
//	cout << fixed << setprecision(6);
    IntArray intArray(5000);
    intArray.fillWithRandomNumbers();

    for(size_t i = 0; i < intArray.getSize(); i++){
        cout << i << ": " << intArray.getValue(i) << " ";
        if(i%10 == 0 && i != 0){
            cout << endl;
        }
    }
//    intArray.quickSort();
//    for(size_t i = 0; i < intArray.getSize(); i++){
//        cout << i << ": " << intArray.getValue(i) << " ";
//        if(i%10 == 0 && i != 0){
//            cout << endl;
//        }
//    }
	cout << "Tid = " << timer.stop()/1000000 << " [s]" <<  endl;  // Läs av stopptiden och beräkna skillnaden till starttiden

	timer.start();
    cout << "Tid = " << timer.stop()/1000000 << " [s]" <<  endl;  // Läs av stopptiden och beräkna skillnaden till starttiden

	timer.start();                                                // Starta tidtagningen

	IntArray intArray2(5000);

	intArray2.fillWithRandomNumbers();
    for(size_t i = 0; i < intArray2.getSize(); i++){
        cout << i << ": " << intArray2.getValue(i) << " ";
        if(i%10 == 0 && i != 0){
            cout << endl;
        }
    }

//    intArray.bubbleSort();
//
//    for(size_t i = 0; i < intArray.getSize(); i++){
//        cout << i << ": " << intArray.getValue(i) << " ";
//        if(i%10 == 0 && i != 0){
//            cout << endl;
//        }
//    }
    cout << "Tid = " << timer.stop()/1000000 << " [s]" <<  endl;  // Läs av stopptiden och beräkna skillnaden till starttiden

	return 0;

}
//___________________________________________________________________________________________________________________________________________________
