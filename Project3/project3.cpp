/*
* Copyright 2018
* Created by George E Gordon
* CSCE 350 - Project 3
*/

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
typedef std::string String;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::transform;
using std::plus;
using std::floor;
using std::ceil;

/*
 *  parseVector - Helper Function
 *    Parses a line of integers into a vector of integers
 */
vector<int> parseVector() {
  String longInt = "";
  vector<int> inputVector;
  cin >> longInt;
  for (unsigned int i = 0; i < longInt.size(); ++i) {
    inputVector.push_back(longInt[i] - '0');
  }
  return inputVector;
}

/*
 *  printVector - Helper Function
 *    Prints vector of integers
 */
void printVector(vector<int> aVector) {
  vector<int>::iterator itbegin = aVector.begin();
  vector<int>::iterator itend = aVector.end();
  for (auto it = itbegin; it < itend; ++it) {
    cout << *it;
  }
  cout << endl;
}

/*
 *  bruteForceMultiply
 *    Takes in two vectors and does brute force multiplication
 *    Iterates through the vectors, multiplying the last
 *     digit of the second vector by every digit of the first
 *     vector.
 *    Takes into account the carrying digit from each multiplication
 *    Then sums each of the multiplications, accouting for the
 *      extra zeros added on each increase in position (ones, tens, etc).
 *    Prints out resulting multiplication.
 */
void bruteForceMultiply(vector<int> a, vector<int> b) {
  int position = 0;
  vector<int> totalVector;
  vector<int>::iterator aBegin = a.begin();
  vector<int>::iterator aEnd = a.end()-1;
  vector<int>::iterator bBegin = b.begin();
  vector<int>::iterator bEnd = b.end()-1;
  vector<int>::iterator it;
  for (auto bIt = bEnd; bIt >= bBegin; --bIt) {
  vector<int> sumVector;
  int carry = 0;
  for (auto aIt = aEnd; aIt >= aBegin; --aIt) {
    it = sumVector.begin();
    int sumMult = *bIt * *aIt;
    sumMult = sumMult + carry;
    sumVector.insert(it, sumMult % 10);
    carry = sumMult / 10 % 10;
  }
  if (position > 0) {
    for (int i = 0; i < position; ++i) {
      sumVector.push_back(0);
    }
  }
  if (totalVector.empty()) {
    totalVector = sumVector;
  } else {
    vector<int> newTotalVector;
    int x = totalVector.size()-1;
    int secCarry = 0;
    for (int i = sumVector.size()-1; i >= 0; --i) {
      it = newTotalVector.begin();
      int sumAdd = 0;
      if (x >= 0) {
        sumAdd = sumVector.at(i) + totalVector.at(x);
        sumAdd = sumAdd + secCarry;
        secCarry = sumAdd / 10 % 10;
        x--;
      } else {
        sumAdd = sumVector.at(i);
        sumAdd = sumAdd + secCarry;
        secCarry = sumAdd / 10 % 10;
      }
      newTotalVector.insert(it, sumAdd % 10);
    }
    totalVector.swap(newTotalVector);
  }
  position++;
  }
  cout << "Brute Force: ";
  for (auto eIt = totalVector.begin(); eIt < totalVector.end(); ++eIt) {
  cout << *eIt;
  }
  cout << endl;
}

/*
 *  multiplySingleVects - Helper Function
 *    Multiply single length vectors together
 */
vector<int> multiplySingleVects(vector<int> a, vector<int> b) {
  vector<int> singleVectSum;
  int one = a.at(0);
  int two = b.at(0);
  singleVectSum.push_back(one * two);
  return singleVectSum;
}

/*
 *  addVectorBits - Helper Function
 *    Adds two vector sequences together
 */
vector<int> addVectorBits(vector<int> a, vector<int> b) {
  vector<int> sumVectorBits;
  int carry = 0;
  for (int i = a.size()-1; i >= 0; --i) {
    int firstBit = a.at(i);
    int secBit = b.at(i);
    int sum = (firstBit + secBit + carry);
    cout << "Sum: " << sum << "\n";
  }
  return sumVectorBits;
}

/*
 *  karatsubaMultiply
 *    Multiplies two vectors.
 */
vector<int> karatsubaMultiply(vector<int> a, vector<int> b) {
  vector<int> finalKaratVect;
  int aLength = a.size();
  int bLength = b.size();
  vector<int>::iterator it;
  int N;
  int zero = 0;
  if (aLength > bLength) {
    N = aLength;
    for (int i = aLength - bLength; i > 0; --i) {
      it = b.begin();
      b.insert(it, zero);
    }
  } else if (aLength < bLength) {
    N = bLength;
    for (int i = bLength - aLength; i > 0; --i) {
      it = a.begin();
      a.insert(it, zero);
    }
  } else {
    N = aLength;
  }

  // Showing padding of zero
  cout << "\nA Pad Vector: ";
  for (auto xIt = a.begin(); xIt < a.end(); ++xIt) {
    cout << *xIt << " ";
  }
  cout << "\nB Pad Vector: ";
  for (auto yIt = b.begin(); yIt < b.end(); ++yIt) {
    cout << *yIt << " ";
  }
  cout << endl;
  // End of padding info

  if (N == 0) return finalKaratVect;
  if (N == 1) return multiplySingleVects(a, b);

  int firstHalf = floor(N/2);
  int secondHalf = ceil(N/2);

  // First half and second half of vector a
  vector<int> fhA;
  for (int i = 0; i < firstHalf; ++i) {
    fhA.push_back(a.at(i));
  }
  vector<int> shA;
  for (int i = secondHalf; i < a.size(); ++i) {
    shA.push_back(a.at(i));
  }

  // First half and second half of vector b
  vector<int> fhB;
  for (int i = 0; i < firstHalf; ++i) {
    fhB.push_back(b.at(i));
    }
  vector<int> shB;
  for (int i = secondHalf; i < b.size(); ++i) {
    shB.push_back(b.at(i));
  }

  // Visual
  cout << "\n(A) First Half Vector: ";
  for (auto xIt = fhA.begin(); xIt < fhA.end(); ++xIt) {
    cout << *xIt << " ";
  }
  cout << "\n(A) Second Half Vector: ";
  for (auto xIt = shA.begin(); xIt < shA.end(); ++xIt) {
    cout << *xIt << " ";
  }
  cout << "\n(B) First Half Vector: ";
  for (auto xIt = fhB.begin(); xIt < fhB.end(); ++xIt) {
    cout << *xIt << " ";
  }
  cout << "\n(B) Second Half Vector: ";
  for (auto xIt = shB.begin(); xIt < shB.end(); ++xIt) {
    cout << *xIt << " ";
  }
  cout << endl;
  // End visual

  vector<int> P1 = karatsubaMultiply(fhA, fhB);
  vector<int> P2 = karatsubaMultiply(shA, shB);
  vector<int> P3 = karatsubaMultiply(addVectorBits(fhA, shA),
      addVectorBits(fhB, shB));

  return finalKaratVect;
}

int main(int argc, char** argv) {
  vector<int> a = parseVector();
  vector<int> b = parseVector();
  /**
  printVector(a);
  printVector(b);
  **/
  bruteForceMultiply(a, b);
  vector<int> finalKaratsuba = karatsubaMultiply(a, b);
  cout << "\nKaratsuba: ";
  for (auto zIt = finalKaratsuba.begin(); zIt < finalKaratsuba.end(); ++zIt) {
  cout << *zIt << " ";
  }
  return 0;
}
