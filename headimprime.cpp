#include <iomanip>
#include <iostream>
using namespace std;

template<typename T> void imprime(T t)
{
  const int width     = 6;
  const char separator    = ' ';
    cout << left << setw(width) << setfill(separator) << t;
}
