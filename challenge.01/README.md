# Challenge 01

Children in a kindergarten got apples for a photo session.
The problem is that the children stand shoulder to shoulder, and a frame can contain only fixed number of kids. The photographer shoots each group of children sequentially from left to right moving by one person.

The task is to find a person with maximal number of apples in each frame and print the number of he has.
+: analyze the complexity of a given algorithm.

INPUT:
The first line contains two numbers: number of children in line and number of children in frame.
The second line contains number of apples children have from left to right.

OUTPUT:
Print maximal number of apples separated with whitespace.

RESTRICTIONS:
Line's size: [1; 1e5]
Frame size: [1; line size]
Apples number: [1; 1e5]

|Sample in|Sample out|
|:-------:|:--------:|
| 5 3 <br> 4 1 5 7 2 | 5 7 7 |
| 4 2 <br> 3 4 9 12 | 4 9 12 |
# Approach
See doxygen or source code

# Usage
##### Play with example

```
mkdir build; cd build
cmake ..
cmake --build . --target challenge.01.example [-j 4]
./challenge.01/challenge.01.example
```
##### Benchmark solutions

```
mkdir build; cd build
cmake ..
cmake --build . --target challenge.01.bench [-j 4]
./challenge.01/challenge.01.bench
```
##### Tests

```
mkdir build; cd build
cmake ..
cmake --build . --target challenge.01.test [-j 4]
./challenge.01/test/challenge.01.test
```
