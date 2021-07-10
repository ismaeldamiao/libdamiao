# My c header

This repository contains the header file were I use in my programs
and implementations for functions declared in the header.

## Good pratices

* Use pure and only C99 features.
  * If any extension is good, implement this.
* Do not use `tgmath.h` library.
* Use `I` as `const` imaginary unit.
* Prefers operators as functions.
* If the compiler is `gcc` then hability `-Wall`, `-Wextra` and `-Wpedantic` flags.
* Use the mathematical constants from `POSIX` extension.

Repository with many `c` function and utilities in computational physics,
mathematics and engineering.

To learn about c see [...](...).

To learn about macros see [macros.md](/MarkDown/macros.md).

## Install

You can download this repository using a terminal as:
```bash
wget https://github.com/ismaeldamiao/my_c_header/archive/refs/heads/main.zip
```

And install the scrit `newc` as:
```bash
unzip main.c && cd my_c_header-main/ && bash install.sh
```

Allways if you want to start a new c project use:
```bash
newc
```

and all contents of this directoty are copied to a current directory
(see as `ls`!) and you can edit `main.c` file.
