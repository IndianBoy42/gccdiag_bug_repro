# Example Repository for a Bug in `gccdiag`

This is to show that the following compiler definitions are not passed on correctly by `gccdiag`

```sh
gcc -D__forceinline=__attribute__\(\(always_inline\)\) -Dstdio="tutorial.h"
```

Run the project normally:

```sh
cmake -S . -B build # Configure the project
cmake --build build # Build and run
```

You should see

```
Hello World __attribute__((always_inline)) "tutorial.h"
```

Check the project with `gccdiag`

```sh
gccdiag tutorial.cpp
```

The error I get is:

```gcc
<command-line>: warning: missing terminating " character
/home/amedhi/dev/gccdiag_fail/tutorial.cpp:1:10: error: #include expects "FILENAME" or <FILENAME>
    1 | #include stdio
      |          ^~~~~
<command-line>: error: expected unqualified-id before string constant
<command-line>: note: in definition of macro ‘__forceinline’
/home/amedhi/dev/gccdiag_fail/tutorial.cpp: In function ‘int main(int, char**)’:
/home/amedhi/dev/gccdiag_fail/tutorial.cpp:12:3: error: ‘hello’ was not declared in this scope
   12 |   hello();
      |   ^~~~~
/home/amedhi/dev/gccdiag_fail/tutorial.cpp:11:14: warning: unused parameter ‘argc’ [-Wunused-parameter]
   11 | int main(int argc, char *argv[]) {
      |          ~~~~^~~~
/home/amedhi/dev/gccdiag_fail/tutorial.cpp:11:26: warning: unused parameter ‘argv’ [-Wunused-parameter]
   11 | int main(int argc, char *argv[]) {
      |                    ~~~~~~^~~~~~
```

Showing that the definitions are not parsed correctly.

What is passed:

```sh
gccdiag -c ./fakecc tutorial.cpp
```

What I get is:

```sh
gcc -D__forceinline="__attribute__((always_inline))" -Dstdio=\"tutorial.h\" -I/home/amedhi/dev/gccdiag_fail/. -o /dev/null -c /home/amedhi/dev/gccdiag_fail/tutorial.cpp
```

Compiler and CMake versions:

```fish
❯ cmake --version
cmake version 3.21.2

CMake suite maintained and supported by Kitware (kitware.com/cmake).

❯ gcc --version
gcc (Ubuntu 10.3.0-1ubuntu1~20.10) 10.3.0
Copyright (C) 2020 Free Software Foundation, Inc.
This is free software; see the source for copying conditions. There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```
