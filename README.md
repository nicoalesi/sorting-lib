# Sorting lib

***Sorting lib* is a C library containing all major sorting algorithms.**

It is designed to ease the process of understanding and studying sorting algorithms.

## Index
 - [Usage](#usage)
 - [Algorithms](#algorithms)

----
## Usage

To use this library follow these steps:

1. Download all the files from GitHub. <br>
It can be done by clicking on `<> Code` and then `Download ZIP` in the project's main page. You can also use *GitHub desktop* or *git*, the command to execute in the latter case is:

```
git clone https://github.com/nicoalesi/sorting-lib.git
```

2. Edit `Makefile`. <br>
It currently searches for a file named `main.c` in the `src` folder but you can change it modifying `EXECUTABLE`.

## Algorithms

This library contains 15 different sorting algorithms, it comprehends both comparison and non-comparison algorithms.

All comparison algorithms are created to only handle integers from $-2^{31}$ to $2^{31}-1$.

All non-comparison algorithms are implemented in such a way to only handle integers from $0$ to $2^{31}-1$.

List of all algorithms:

| Algorithm       | Time complexity                                    | Space complexity |
| ---             | :---:                                              | :---:            |
| Mergesort       | $\Theta(n\log n)$                                  | $\Theta(n)$      |
| Quicksort       | $\mathcal{O}(n\log n)$ &nbsp; $\Omega(n^2)$        | $\Theta(1)$      |
| Heapsort        | $\Theta(n\log n)$                                  | $\Theta(1)$      |
| Bubblesort      | $\Theta(n^2)$                                      | $\Theta(1)$      |
| Selectionsort   | $\Theta(n^2)$                                      | $\Theta(1)$      |
| Insertionsort   | $\mathcal{O}(n^2)$ &nbsp; $\Omega(n)$              | $\Theta(1)$      |
| Shellsort       | [Unknown](https://en.wikipedia.org/wiki/Shellsort) | $\Theta(1)$      |
| Shakersort      | $\mathcal{O}(n^2)$ &nbsp; $\Omega(n)$              | $\Theta(1)$      |
| Radixsort       | $\Theta(kN)$                                       | $\Theta(n)$      |
| Cyclesort       | $\Theta(n^2)$                                      | $\Theta(1)$      |
| Countingsort    | $\Theta(n+k)$                                      | $\Theta(k)$      |
| Combsort        | $\mathcal{O}(n\log n)$ &nbsp; $\Omega(n)$          | $\Theta(1)$      |
| Bucketsort      | $\Theta(n)$                                        | $\Theta(n)$      |
| Binarysort      | $\mathcal{O}(n^2)$ &nbsp; $\Omega(n\log n)$        | $\Theta(1)$      |
| Bubblectionsort | $\Theta(n^2)$                                      | $\Theta(1)$      |

<br>

**Note:**<br>
*Space complexity is calculated excluding recursion stack*. <br>
*Space complexity refers to additional space*. <br>
*All the information are valid for these exact implementations of the algorithms*.
