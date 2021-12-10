#include "threadedbst.h"
#include <iostream>
using namespace std;
int main() {
  ThreadedBST test;
  test.removeEvens(test.getRoot());
  cout << test;
  ThreadedBST test2;
  // test2.removeEvens(test.getRoot());

  cout << test2;
  // ThreadedBST test3;
  // cout << test3;
  // ThreadedBST test4;
  // cout << test4;
  // ThreadedBST test5;
  // cout << test5;
  // ThreadedBST test6;
  // cout << test6;
  // ThreadedBST test7;
  // cout << test7;

  return 0;
}