#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>


int main()
{
  std::cout << "Hello Sanitizer Worlds!" << std::endl;

 char *x = (char*)malloc(10 * sizeof(char*));
  free(x);
  return x[5];


}
