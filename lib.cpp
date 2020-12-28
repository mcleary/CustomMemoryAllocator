
#include "lib.h"

#include <iostream>

#ifdef WIN32
#include <Windows.h>
#else
#include <sys/mman.h>
#endif

void* operator new (size_t size)
{
#ifdef WIN32
  void* ptr = HeapAlloc(GetProcessHeap(), HEAP_GENERATE_EXCEPTIONS | HEAP_ZERO_MEMORY, size);
  std::cout << "[Library]: Alloc " << size << " bytes: " << ptr << std::endl;
  return ptr;
#else
  void* ptr = mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_SHARED, 0, 0);
  std::cout << "[Library]: Alloc " << size << " bytes: " << ptr << std::endl;
  return ptr;
#endif
}

void operator delete(void* ptr)
{
  std::cout << "[Library]: Free " << ptr << std::endl;
#ifdef WIN32
  HeapFree(GetProcessHeap(), 0, ptr);
#else
  munmap(ptr, 0);
#endif
}


void property_list::func()
{
  int* n = new int[10];
  delete[]n;
}

