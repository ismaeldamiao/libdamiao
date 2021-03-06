[![Tip Me via PayPal](https://img.shields.io/badge/PayPal-tip%20me-green.svg?logo=paypal)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=D66EM3DGU35EE&source=url)
[![LICENSE](https://img.shields.io/badge/license-MIT-lightgrey.svg)](/LICENSE)
![GitHub release (latest by date)](https://img.shields.io/github/v/release/ismaeldamiao/libdamiao)
![GitHub Release Date](https://img.shields.io/github/release-date/ismaeldamiao/libdamiao)
![GitHub last commit](https://img.shields.io/github/last-commit/ismaeldamiao/libdamiao)

# LibDamiao

This repository contains the header file were I use in my programs
and implementations for functions declared in the header.

## Features

* `LibDamiao` ese pure and only C99 features.
  * If any extension is good, implement this.
  * Mathematical constants from `POSIX` extension are good extension.
  * Function `CMPLX` defined in C11 standard is a good feature.
* Do not use `tgmath.h` library.
* If the compiler is `gcc` then hability `-Wall`, `-Wextra` and `-Wpedantic` flags.
* Define some physical constants macros.
  * `CONST_SPEED_OF_LIGHT` expands to the speed of the light in vacuum in metres per second.
  * `CONST_AVOGADRO` expands to the Avogadro constant in mol<sup>-1</sup>.
  * `CONST_PLANCK` expands to the Planck constant in joules per hertz.
  * `CONST_REDUCED_PLANCK` expands to the reduced Planck constant in joules per hertz.
  * `CONST_BOLTZMANN` expands to the Boltzmann constant in joules per kelvin.
  * `CONST_ELEMENTARY_CHARGE` expands to the elementary charge in coulombs.
  * `CONST_GRAVITATIONAL` expands to the gravitational constant in cubic metre per kilogram · square second.
  * `CONST_VACUUM_PERMITTIVITY` expands to the vacuum permittivity in farads per meter.
  * `CONST_VACUUM_PERMEABILITY` expands to the vacuum permeability in henry per meter.

Moreover, the following functions be declared:
* `double random(unsigned int *idum);`
  * **Description:**
The `random` function computes a sequence of pseudo-random integers in the range 0 to
`UINT_MAX` and convert it in pseudo-random reals in the interval [0, 1].
Successive calls must generate the same sequence of numbers if the first
call have the same value. The argument `idum` is a pointer to a
initialized integer, the integer are initialized with
the seed of pseudo-random gererator and after call is changed to a
pseudo-random integer.
  * **Returns:**
The `random` function return the pseudo-random real.
* `double _Complex atoc(const char *str);`
  * **Description:**
The `atoc` function convert the initial portion of the string pointed
to by `str` to `double _Complex` representation.
  * **Returns:**
The `atoc` function return the converted value.
* `double *correlated_w_fourier(double alpha, int N, int seed);`
  * **Description:**
The `correlated_w_fourier` function computes a normalized sequence of correlated
numbers. `alpha >= 0` is the factor that constrols correlations, if
`alpha` is `0` then the sequence is pseudo-randomized. `N` is
the quantity of numbers in the sequence. `seed` is a seed  for the 
pseudo-random numbers generator.
  * **Returns:**
The `correlated_w_fourier` function return a array (pointer to `double`) that
contain the correlated sequence.
* `double *correlated_w_distance(double alpha, int N, int seed);`
  * **Description:**
The `correlated_w_distance` function computes a normalized sequence of correlated
numbers. `alpha > 0` is the factor that constrols correlations, if
`alpha` is much less than `1` then the sequence is pseudo-randomized. `N` is
the quantity of numbers in the sequence. `seed` is a seed  for the 
pseudo-random numbers generator.
  * **Returns:**
The `correlated_w_distance` function return a array (pointer to `double`) that
contain the correlated sequence.
* `double *correlated_w_bernoulli(double alpha, int N, int seed);`
  * **Description:**
The `correlated_w_bernoulli` function computes a sequence of correlated
numbers. `alpha >= 0` is the factor that constrols correlations, if
`alpha` is `0` then the sequence is pseudo-randomized. `N` is
the quantity of numbers in the sequence. `seed` is a seed  for the 
pseudo-random numbers generator.
  * **Returns:**
The `correlated_w_bernoulli` function return a array (pointer to `double`) that
contain the correlated sequence.

In addition, `LibDamiao` provide declaration of Runge-Kutta matrices for
Runge-Kutta methods:
* Runge-Kutta method of order 8:
  * `const long double __rk8_a[11][11]`
  * `const long double __rk8_b[11]`
  * `const long double __rk8_c[11]`
* Runge-Kutta method of order 14:
  * `const long double __rk14_a[35][35]`
  * `const long double __rk14_b[35]`
  * `const long double __rk14_c[35]`

## How to use

You can download this repository using `wget` in a terminal as:
```bash
wget https://github.com/ismaeldamiao/libdamiao/archive/refs/heads/main.zip
```

Uncompress using `unzip` as:
```bash
unzip main.zip
```

And compile using `gcc` running the script [COMPILE](/src/COMPILE). It
make a library named `libdamiao.a`.

To use the functions you need to put in the directory of your code the files
`damiao.h` and `libdamiao.a`, include the header in your C-CODE
(like `#include "damiao.h"`) and compile using `gcc` with the flags
`-L./ -ldamiao`. For example, if the file `main.c` use the function
`random` you need to add `#include "damiao.h"` header in `main.c`
and compile it with `gcc main.c -lm -L./ -ldamiao`,
since `main.c`, `damiao.h` and `libdamiao.a` are in the same directory.

## Donate

You can donate to the creator I. F. F. dos Santos (@ismaeldamiao)
through PayPal by clicking  in the link
[https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=D66EM3DGU35EE&source=url](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=D66EM3DGU35EE&source=url).

Se você possiu conta em algum banco que opera junto ao Banco Central do Brasil
você também pode doar usando o PIX `ismaellxd@gmail.com`.


## Read more

To learn about c see [...](...).

To learn about macros see [macros.md](/MarkDown/macros.md).
