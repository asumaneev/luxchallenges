# Challenge 02
Cyclic buffer is used to exchange messages between **Producer** and **Consumer**.
**Consumer** reads, **Producer** writes.

**How long it takes to transfer a message of known length with known reading rate, writing rate and buffer's size?**
A field can be accessed either to read or to write.

##### Example
Buffer size: 20, reading rate: 10 elements per second, writing rate: 10 elements per second, message length: 20 elements.

Second 0: buffer is empty
Second 1: Producer writes 10 elements
Second 2: Consumer reads 10 elements. Producer writes 10 elements.
Second 3: Consumer reads 10 elements.

Result: 3 seconds

# Approach
See doxygen or source code

# Usage
##### Play with example

```
mkdir build; cd build
cmake ..
cmake --build . --target challenge.02.example [-j 4]
./challenge.02/challenge.01.example
```
##### Benchmark

```
mkdir build; cd build
cmake ..
cmake --build . --target challenge.02.bench [-j 4]
./challenge.01/challenge.02.bench
```
##### T

##### Tests

```
mkdir build; cd build
cmake ..
cmake --build . --target challenge.02.test [-j 4]
./challenge.02/test/challenge.02.test
```
