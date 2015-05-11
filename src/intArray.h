/*
 * IntArray.h
 *
 *  Created on: apr 27, 2015
 *      Author: Kristoffer Freiholtz
 */

#ifndef INT_ARRAY_H_
#define INT_ARRAY_H_

#include <iostream>
#include <functional>
#include "Timer.h"
#include <random>

using namespace std;

class IntArray
{
	private:
		int *arr;  // Pekare till arrayen
		size_t maxSize; // Arrayens maximala storlek
		size_t size; // IntArrayens aktuella storlek
        string fileName = "results.txt";
		default_random_engine generator;


	void quickSortArray(int a[], int first, int last);
		void swap(int &a, int &b);


	public:
		// ---------------- Konstruktorer och destruktor
		IntArray();
		IntArray(int pNum);
		IntArray(const IntArray &a);
		~IntArray();

		//------------------ Get- och set-funktioner
		size_t getMaxSize() const {return maxSize;}
		size_t getSize() const {return size;}
		int getValue( int idx) const;
		bool addValue(int value);

		// ----------------- Överlagra tilldelningsoperatorn
		const IntArray &operator=(const IntArray &a);

		// ----------------- Slump generator funktion
		void fillWithRandomNumbers(default_random_engine generator);

		// ----------------- Sorteringsfunktioner
		void quickSort();
		void insertionSort();
		void selectionSort();
		void bubbleSort();

        void writeToFile(string output, double seconds);
};

#endif /* INT_ARRAY_H_ */
