/*
* Copyright 2018
* Created by George E Gordon
* CSCE 350 - Project 1
*/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char** argv) {
  // Boolean used to stop loop on input of (0 0 0 0)
  bool stop = false;
  // While loop to keep accepting values
  while (!stop) {
    int a, b, c, d;
    // Assign input to variables
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    // Adds all integers together
    int total = a + b + c + d;
    // If total is not equal to 0 then print total
    if (total != 0) {
      cout << total << endl;
    }
    // If total is equal to 0 then all inputs are 0, so stop
    if (total == 0) {
      stop = true;
    }
  }
  return 0;
}
