[![Tip Me via PayPal](https://img.shields.io/badge/PayPal-tip%20me-green.svg?logo=paypal)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=D66EM3DGU35EE&source=url)
[![LICENSE](https://img.shields.io/badge/license-MIT-lightgrey.svg)](/LICENSE)

# LibDamiao

This repository contains the header file were I use in my programs
and implementations for functions declared in the header.

## Good pratices

* Use pure and only C99 features.
  * If any extension is good, implement this.
  * Mathematical constants from `POSIX` extension are good extension.
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

it's OK use `#define` to a implementation.

## How to use

You can download this repository using `wget` in a terminal as:
```bash
wget https://github.com/ismaeldamiao/libdamiao/archive/refs/heads/main.zip
```

Uncompress using `unzip` as:
```bash
unzip main.zip
```

And compile using `gcc` running the script [COMPILE](/COMPILE). It
make a library named `libdamiao.a`.

To use the functions you need to put in the directory of your code the files
`damiao.h` and `libdamiao.a`, include the header in your C-CODE
(like `#include "damiao.h"`) and compile using `gcc` with the flags
`-L./ -ldamiao`. For example, if the file `main.c` use the function
`random` you need to add `#include "damiao.h"` header in `main.c`
and compile it with `gcc main.c -lm -L./ -ldamiao`,
since `main.c`, `damiao.h` and `libdamiao.a` are in the same directory.


## Read more

To learn about c see [...](...).

To learn about macros see [macros.md](/MarkDown/macros.md).
