
#ifdef LIB_EXPORT
  #ifdef WIN32
    #define LIB_API __declspec(dllexport)
  #else
    #define LIB_API
  #endif
#else
  #ifdef WIN32
    #define LIB_API __declspec(dllimport)
  #else
    #define LIB_API
  #endif
#endif

#include <iostream>
#include <string>
#include <vector>

class LIB_API property_list
{
public:
  template<typename... Args>
  property_list(Args&&... args) {
    aaa.reserve(sizeof...(args));
  };

  void func();
private:
  std::vector<int> aaa;
};

class LIB_API my_class
{
public:
  explicit my_class(const property_list& s = {}) : l(s) { l.func(); }

private:
  property_list l;
};
