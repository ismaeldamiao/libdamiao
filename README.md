[![Tip Me via PayPal](https://img.shields.io/badge/PayPal-tip%20me-green.svg?logo=paypal)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=D66EM3DGU35EE&source=url)
[![LICENSE](https://img.shields.io/badge/license-MIT-lightgrey.svg)](/LICENSE)

# LibDamiao

This repository contains the header file were I use in my programs
and implementations for functions declared in the header.

## Good pratices

* Use pure and only C99 features.
  * If any extension is good, implement this.
* Do not use `tgmath.h` library.
* Set `I` as `const` to imaginary unit.
* Prefers operators as functions.
* If the compiler is `gcc` then hability `-Wall`, `-Wextra` and `-Wpedantic` flags.
* Define the mathematical constants from `POSIX` extension.
* Define physical constants in [SI base unit](https://en.wikipedia.org/wiki/SI_base_unit).

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

Repository with many `c` function and utilities in computational physics,
mathematics and engineering.

To learn about c see [...](...).

To learn about macros see [macros.md](/MarkDown/macros.md).

## How to use

You can download this repository using a terminal as:
```bash
wget https://github.com/ismaeldamiao/libdamiao/archive/refs/heads/main.zip
```

Uncompress using `unzip` as:
```bash
unzip main.zip
```

And compile using `gcc` using the script [COMPILE](/COMPILE). It
make a library named `libdamiao.a`.

To use the functions put in the directory of your code the files
`damiao.h` and `libdamiao.a`, include the header in your C-CODE
(like `#include "damiao.h"`) and compile using with the flags
`-L./ -ldamiao`. For example, if the file `main.c` use the function
`random` you need to add `#include "damiao.h"` header in `main.c`
and compile it with `gcc main.c -lm -L./ -ldamiao`.
