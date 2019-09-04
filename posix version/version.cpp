#define _POSIX_SOURCE 
#define _POSIX_C_SOURCE 199309L 
#include<iostream>
#include <unistd.h>

int main() { 
#ifdef _POSIX_VERSION 

using namespace std;
using std :: cout;
cout << "System conforms to POSIX: " << _POSIX_VERSION << endl; 
#else 
cout << "_POSIX_VERSION is undefined\n"; 
#endif 
return 0; 
}
