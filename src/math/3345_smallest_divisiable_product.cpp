#include <cassert>

int smallestNumber(int n, int t)
{
  for (int i = n; n <= 100; ++n) {
    int smallest = n;
    int product = 1;
    while (smallest > 0) {
      int digit = smallest % 10;
      product *= digit;
      smallest /= 10;
    }
    
    if (product % t == 0) {
      return n;
    }
  }
  
  return n;
}

int main()
{
  int n = 15, t = 3, expected = 16;
  assert(expected == smallestNumber(n, t));
  return 0;
}