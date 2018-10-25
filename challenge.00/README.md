# Challenge 00

Given:
Array of integers

Find:
Subsequence defined as indicies of head (1) and tail (2)  with maximal sum of elements (3).
Result is three numbers (1, 2, 3). Algorithm must have liear complexity of number of elements in array.

# Approaches
I did not invented the algorithm by muself but took two here: http://e-maxx.ru/algo/maximum_average_segment
My intentions were in building proper project structure with tests like a nice guy.
As a result, I played with templates (hello STL!) and bechmarking those two approaches with google benchmark.

The first approach is function ```find_subsequence``` (aka *first\_finder*), the second one is ```find_subsequence_advanced``` (aka *second\_finder*).

#### Comparison
The second approach looks a little bit better (in **1.03** times) without optimization (but who would do that?).
With optimization enabled (-O2) first approach gives better reults in about **1.52** times.
Environment:
- CPU: ```Intel(R) Core(TM) i5-4670K CPU @ 3.40GHz``` x 4
- OS: ```Linux mint 4.15.0-36-generic```
- Compiler: ```clang 6.0.0```
- Optimization: ```-O0``` and ```-O2```

# Usage
##### Play with example

```
mkdir build; cd build
cmake ..
cmake --build . --target challenge.00.task.exe [-j 4]
./challenge.00/challenge.00.task.exe
```
##### Benchmark solutions
```
mkdir build; cd build
cmake .. -DPERFORM_BENCHMARK
cmake --build . --target challenge.00.task.exe [-j 4]a
./challenge.00/challenge.00.task.exe
```
# Further researches
- Different containers.
    All benchmarkings were made on sequences of ```std::vector```. Other containers were not taken into account. There may be interesting results in case of ```std::list``` and cache misses.
- Multithreading.
    I was too lazy to think much about algorithms and possibilty to bring multithreading into the algorithms. An idea was split array into subsequence and apply algo separatly (with some minimal size of subsequence, e.g. 1Kb), and then try to merge edges of threaded subsequences.
- Big data.
    What if array cannot be places in memory at once? I do not want to even think about it.
