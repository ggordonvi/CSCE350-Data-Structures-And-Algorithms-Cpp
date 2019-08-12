/*
* Copyright 2018
* Created by George E Gordon
* CSCE 350 - Project 2
*/

#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
typedef std::string String;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::swap;

long long comparisons;

/*
 *  Helper function used in main.
 *  Builds a vector based on cin input, and reutrns the vector.
 *  Only takes in positive integers, and the input stream
 *   is stopped when '0' is entered.
 */
vector<int> inputVector() {
  vector<int> intVector;
  int n;
  bool quitInput = false;
  while (!quitInput) {
      cin >> n;
      if (n > 0) {
        intVector.push_back(n);
      } else if (n == 0) {
        quitInput = true;
      }
    }
  return intVector;
}

/*
 *  Selection Sort Algorithm
 *  Like example used in book.
 */
vector<int> selectionSort(vector<int> unsortedVector) {
  int vectorSize = unsortedVector.size();
  for (int i = 0; i < vectorSize - 1; ++i) {
    int min = i;
    for (int j = i + 1; j < vectorSize; ++j) {
      comparisons++;
      if (unsortedVector.at(min) > unsortedVector.at(j)) {
        min = j;
      }
    }
    if (min != i) {
      swap(unsortedVector.at(i), unsortedVector.at(min));
    }
  }
  return unsortedVector;
}

/*
 *  QSort Algorithm
 *  qsortCompare: Given
 *  qSort: Uses qsort function with the help of our given compare function.
 *    Takes in an array, so we made a pointer to an array
 *      referencing our vector.
 *    After vector is sorted, return the now sorted vector.
 */
int qsortCompare(const void *a, const void *b) {
  comparisons++;
  if (*(int*)a < *(int*)b) return -1;
  if (*(int*)a == *(int*)b) return 0;
  return 1;
}

vector<int> qSort(vector<int> unsortedVector) {
  int vectorSize = unsortedVector.size();
  int* linkVector = &unsortedVector[0];

  qsort(linkVector, vectorSize, sizeof(int), qsortCompare);

  return unsortedVector;
}

/*
 *  STL Sort Algorithm
 *  stlSortCompare: Given
 *  stlSort: Uses sort function with the help of 
 *    our given compare function then return the newly
 *    sorted vetor.
 */
bool stlSortCompare(int i, int j) {
  comparisons++;
  return i < j;
}

vector<int> stlSort(vector<int> unsortedVector) {
  sort(unsortedVector.begin(), unsortedVector.end(), stlSortCompare);
  return unsortedVector;
}

/*
 *  Initalize and input string, and take in input
 *  IF (sorting algorithm*) then:
 *      1. Create the vector on cin input
 *      2. Run (sorting algorithm*) on vector
 *      3. Print sorted vector
 *      4. Print comparisons
 */
int main(int argc, char** argv) {
  String inputSort = "";
  cin >> inputSort;

  if (inputSort.compare("selection") == 0) {
    vector<int> selectionVector;
    selectionVector = inputVector();
    vector<int> sortedVector = selectionSort(selectionVector);

    for (int p : sortedVector) {
      cout << "\n" << p;
    }
    cout << endl;
    cout << "Comparisons: " << comparisons << endl;
  } else if (inputSort.compare("qsort") == 0) {
    vector<int> qsortVector;
    qsortVector = inputVector();
    vector<int> sortedVector = qSort(qsortVector);

    for (int p : sortedVector) {
      cout << "\n" << p;
    }
    cout << endl;
    cout << "Comparisons: " << comparisons << endl;
  } else if (inputSort.compare("stl") == 0) {
    vector<int> stlVector;
    stlVector = inputVector();
    vector<int> sortedVector = stlSort(stlVector);

    for (int p : sortedVector) {
      cout << "\n" << p;
    }
    cout << endl;
    cout << "Comparisons: " << comparisons << endl;
  } else {
    return 0;
  }
  return 0;
}
