# ALGORISMIA 25-26

A collection of programming exercises and solutions created while studying algorithms and data structures. The repository is intended as a practical reference for students who are learning problem solving, recursion, backtracking, dynamic programming, graphs, and related topics.

Most problem statements come from [Jutge.org](https://jutge.org/). Problem IDs are included in file names so that the original statement can be found easily.

## Repository contents

- `bck_permutations/` - permutation and arrangement exercises
- `bck_subsets/` - subset and multiset exercises
- `bkt_consolidation/` - consolidated backtracking exercises
- `dp/` - dynamic programming
- `graphs/` - graph algorithms
- `sets_and_maps/` - sets, maps, and associative containers
- `Piles, cues i cues de prioritats/` - stacks, queues, and priority queues
- `contest/` - contest problems organized by year
- `exams/` - exam exercises organized by year
- `codisROURA2024/` - ROURA 2024 material

Some folders contain drafts, alternative solutions, or backup material. Always read the code and test it against the relevant problem statement before relying on it.

## Advice for future students

Do not just copy the solutions. The best way to learn is to understand the problem, try to solve it yourself, and use these solutions afterward to compare approaches, find mistakes, and learn new techniques. The effort you make before looking at a solution is where most of the learning happens.

## File naming

Solutions in the main collection follow this convention:

```text
Pxxxxx_author_problem-name.cc
```

## Building and running a solution

The solutions are standalone C++ programs unless stated otherwise. A typical local compilation command is:

```bash
g++ -std=c++17 -Wall -Wextra -O2 solution.cc -o solution
./solution < input.txt
```

The required C++ standard may vary by exercise. Use the standard library and compiler version expected by the problem platform when submitting to Jutge.org.

## Contributing

Contributions are welcome. When adding a solution:

1. Keep the solution focused on one problem.
2. Include the problem ID and author in the file name.
3. Prefer clear, portable C++ and avoid committing generated binaries.
4. Check the solution with the original problem's sample cases and judge when possible.

If you find an incorrect solution, unclear code, or a broken link, please open an issue or submit a pull request with enough context to reproduce the problem.

## License

This project is available under the [MIT License](LICENSE). Individual problem statements and platform materials remain subject to their original licenses and belong to their respective authors.
