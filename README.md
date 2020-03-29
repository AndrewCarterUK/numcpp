# numcpp

![C++ Test](https://github.com/AndrewCarterUK/numcpp/workflows/C++%20Test/badge.svg)

A C++ library with a [numpy](https://numpy.org/) like interface for handling large, multi-dimensional arrays and matrices

This project is a learning exercise for the author. It is not intended as a production library for other users.

## Current API

### Template Aliasing

The `numcpp` library is designed to be used with a type alias to make the syntax simpler without reducing flexibility.

```cpp
using nc = numcpp::numcpp<>;
```

The default `numcpp` template type is `double`. Thus, the above is equivalent to:

```cpp
using nc = numcpp::numcpp<double>;
```

Other available types include:

| Floating Point | Integers | Unsigned Integers |
| - | - | - |
| float | char | unsigned char |
| double | short | unsigned short |
| long double | int | unsigned int |
| | long | unsigned long |
| | long long | unsigned long long |


### Array Creation

| Method | Description |
| - | - |
| `nc::empty(int n)` | Create an uninitialised one dimensional array of length `n` |
| `nc::empty({ n1, n2, ... })` | Create an uninitialised multi dimensional array of shape `{ n1, n2, ... }` |
| `nc::zeros(int n)` | Create a one dimensional array of length `n` initialised to `0` |
| `nc::zeros({ n1, n2, ... })` | Create a multi dimensional array of shape `{ n1, n2, ... }` initialised to `0` |
| `nc::ones(int n)` | Create a one dimensional array of length `n` initialised to `1` |
| `nc::ones({ n1, n2, ... })` | Create a multi dimensional array of shape `{ n1, n2, ... }` initialised to `1` |
| `nc::full(int n, double v)` | Create a one dimensional array of length `n` initialised to `v` |
| `nc::full({ n1, n2, ... }, double v)` | Create a multi dimensional array of shape `{ n1, n2, ... }` initialised to `v` |
| `nc::eye(int N, int M = 0, int k = 0)` | Create a two dimensional array with ones on the diagonal and zeros elsewhere (`M` is number of columns and `k` is the index of the diagonal) |
| `nc::identity(int n)` | Create a two dimensional (square) array with ones on the main diagonal and zeros elsewhere |
