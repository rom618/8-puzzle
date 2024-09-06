# 8-Puzzle Solver

This project is an implementation of an 8-puzzle solver in C. It offers two different approaches to solve random 8-puzzle configurations:
1. **Brute Force Approach**: A simple, exhaustive method that explores all possible moves until the solution is found.
2. **Heuristic Approach**: An optimized method that utilizes heuristics to solve the puzzle more efficiently.

## Table of Contents

- [Introduction](#introduction)
- [Getting Started](#getting-started)
- [Brute Force Approach](#brute-force-approach)
- [Heuristic Approach](#heuristic-approach)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The 8-puzzle is a classic problem in computer science and artificial intelligence, where the goal is to move tiles on a 3x3 grid to achieve a desired end configuration. This repository contains an 8-puzzle solver that offers two approaches for solving the puzzle: a brute force search and a heuristic-based search.

## Getting Started

### Prerequisites

To compile and run this project, you need:
- A C compiler (e.g., `gcc`)

### Installation

Clone the repository:

```bash
git clone https://github.com/rom618/8-puzzle.git
cd 8-puzzle
```

Build the project:

```bash
gcc -o 8_puzzle *.c
```

Or use the appropriate script for [Windows](compile.bat) or [Linux](compile.sh).

## Brute Force Approach

The brute force method explores all possible moves from a given configuration to find a solution. This approach is straightforward but may not be efficient for puzzles that are far from the solution.

### Features

- Exhaustive search of all possible configurations
- Guaranteed to find a solution (if one exists)

## Heuristic Approach

The heuristic approach uses intelligent algorithms, such as A* (A-star) search, combined with heuristics like the Manhattan Distance or Misplaced Tiles to solve the puzzle more efficiently.

### Features

- Optimized search using heuristics
- Faster solution finding for complex puzzles
- Supports multiple heuristics

## Usage

To solve a random 8-puzzle using brute force:

```bash
./8-puzzle --mode brute-force
```

To solve a random 8-puzzle using heuristics:

```bash
./8-puzzle --mode heuristic --heuristic manhattan
```

Available heuristics:
- `manhattan`: Uses the Manhattan Distance heuristic.
- `misplaced`: Uses the Misplaced Tiles heuristic.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request for any improvements or new features.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
