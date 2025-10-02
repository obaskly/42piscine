# 42 C Piscine Portfolio

## About this Repository
This repository collects my work from the 42 C Piscine. Over four intense weeks I coded exclusively in C and shell, tackling daily exercises, weekend "rush" projects, and the final BSQ algorithm challenge. Every folder in this repo mirrors a checkpoint in that journey, from learning how to print a character to parsing complex input and allocating dynamic memory safely.

## Repository Map
Below is a quick tour of the top-level folders and their focus areas:

| Directory | Focus | Highlights |
| --- | --- | --- |
| `c00` | I/O fundamentals | Printing characters, numbers, and simple combinations without standard library helpers. |
| `c01` | Pointer basics | Manipulating pointers, references, and simple array utilities. |
| `C02` | String sanitizers | Implementations for character class checks and case conversions. |
| `c03` | String operations | Re-creating `strcmp`, `strcat`, substring search, and `strlcat`. |
| `c04` | Basic libc re-creations | Custom `strlen`, `putstr`, `atoi`, and base conversions. |
| `C05` | Recursion drills | Factorial, power, Fibonacci, square root, and prime utilities. |
| `C06` | Command-line handling | Printing program names and sorting parameters from `argv`. |
| `C07` | Dynamic memory | Custom `strdup`, range allocation helpers, and string joining. |
| `bsq/ex00` | Final project | Full solver for the "Biggest Square" problem with parsing, validation, and output rendering. |
| `rush00` | Weekend rush #1 | ASCII-art rectangle generator (`rush00`-`rush04`). |
| `rush01` | Weekend rush #2 | 4x4 Skyscraper puzzle solver with constraint validation. |
| `shell00` | Shell warm-up | File permissions, archives, and simple command-line exercises. |
| `shell01` | Shell scripting | Pipeline and text-processing drills using classic Unix tools. |

> Tip: The mix of lowercase/uppercase folder names follows the Piscine's original naming. I kept them intact to preserve the daily hand-in structure.

## Project Highlights

### BSQ (Biggest Square)
The `bsq/ex00` directory contains my implementation of the final Piscine challenge. It reads a map describing obstacles, computes the largest possible square without obstacles, and prints the map with the solution highlighted. The project is broken down into:

- `parse_utils.c`, `map_utils.c`, and `memory_utils.c` for input parsing and safe memory management.
- `solver.c` with a dynamic-programming approach to identify the biggest square efficiently.
- `file_utils.c` for buffered file loading so the solver can operate on stdin or any file path.
- `Makefile` to build the executable with the Piscine's strict `-Wall -Wextra -Werror` flags.

**Compile & run:**

- macOS/Linux
   ```bash
   cd bsq/ex00
   make
   ./bsq map/example_map
   ```
- Windows (PowerShell)
   ```powershell
   Set-Location bsq/ex00
   make
   .\bsq.exe map\example_map
   ```

Replace `map/example_map` with any valid map file or use standard input (`cat map/example_map | ./bsq` on macOS/Linux, `Get-Content map\example_map | .\bsq.exe` on Windows).

### Rush Projects
- `rush00` focuses on generating framed ASCII rectangles, emphasizing clean structuring and parameter validation under time pressure.
- `rush01` builds a backtracking solver for the Skyscrapers puzzle. The code demonstrates input validation, table generation, and constraint propagation.

### Shell Projects
- `shell00` introduces low-level file manipulation, permissions, and tarball handling.
- `shell01` deepens shell scripting with pipelines, string processing, and command substitution.

## How to Explore the Exercises
1. Each `cXX` and `CXX` directory contains standalone exercises (`ex00`, `ex01`, …). You can compile any file directly with the 42 Piscine flags:
   ```powershell
   cc -Wall -Wextra -Werror <source>.c -o <program>
   ```
2. For folders with multiple sources (like `bsq` or the rushes), use the provided `Makefile` or add the necessary `.c` files to the compile command.
3. Many exercises mirror standard library behavior; comparing outputs with the real libc functions is a great way to test correctness.

## Lessons Learned
- Comfort with pointers, dynamic allocation, and manual memory management.
- Writing reusable utility functions instead of relying on standard library shortcuts.
- Collaborating under strict deadlines during rush weekends.
- Reading and validating complex inputs (maps, puzzles) before processing data.

## IMPORTANT NOTICE
- To my fellow programmers, try to get an idea from my experience, but DON'T copy paste, otherwise you won't learn. **Create your own experience**.
**Good luck**.
