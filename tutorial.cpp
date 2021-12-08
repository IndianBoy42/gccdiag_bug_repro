#include stdio

// __forceinline void hello() { printf("%s %s", "Hello World", #__forceinline);
// }
#define xstr(a) str(a)
#define str(a) #a
__forceinline void hello() {
  printf("%s %s %s", "Hello World", xstr(__forceinline), xstr(stdio));
}

int main(int argc, char *argv[]) {
  hello();
  return 0;
}
