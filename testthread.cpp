// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <chrono>


void foo()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(3*1000));
 std::cout << "1111111"<< std::endl;
std::this_thread::sleep_for(std::chrono::milliseconds(20*1000));

}

void bar()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(3*1000));
std::cout << "5555555"<< std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(10*1000));
}

int main()
{
  std::thread first (foo);     // spawn new thread that calls foo()
    std::thread second (bar);
  std::cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
  first.join();                // pauses until first finishes
second.join();

  std::cout << "foo and bar completed.\n";

  return 0;
  }
