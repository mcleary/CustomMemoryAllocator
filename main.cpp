
#include <iostream>
#include <memory>

#ifdef WIN32
#include <Windows.h>
#endif

#include "lib.h"

void* operator new (size_t size)
{
  void* ptr = malloc(size);
  std::cout << "[Application]: Alloc " << size << " bytes: " << ptr << std::endl;
  return ptr;
}

void operator delete(void* ptr)
{
  std::cout << "[Application]: Free " << ptr << std::endl;
  free(ptr);
}

int main()
{
  std::cout << __FUNCTION__ << std::endl;

  std::cout << "Calling my_class ctor" << std::endl;
  my_class c;

  std::cout << "All Good!" << std::endl;

  return 0;
}