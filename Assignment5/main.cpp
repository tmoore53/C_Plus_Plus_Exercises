/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-12
 * 
 * @copyright Copyright (c) 2021
 * 
 * Compile and run with bash ./simplecompile.sh > output.txt 2>&1
 * 
 */

#include "threadedbst.h"
#include <iostream>
using namespace std;
int main() {
  ThreadedBST test;
  // This method is limited to 20 nodes
  // test.removeEvens(test.getRoot());
  cout << test;

  ThreadedBST test2;
  // This method is limited to 20 nodes
  // test2.removeEvens(test2.getRoot());
  cout << test2;

  return 0;
}