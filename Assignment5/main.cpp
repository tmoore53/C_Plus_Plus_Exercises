#include "threadedbst.h"
#include <iostream>
using namespace std;
int main() {
  ThreadedBST test;
  test.removeEvens(test.getRoot());
  cout << test;
  // ThreadedBST test2;
  // // test2.removeEvens(test.getRoot());
  // cout << test2;

  return 0;
}