*This project has been created as part of the 42 curriculum by rgerman-.*

# Push_swap

## Description

**Push_swap** is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations with the minimum number of moves possible.

The project consists of two programs:
- **push_swap**: Takes a list of integers as arguments and outputs the sequence of operations needed to sort them.
- **checker** (bonus): Reads operations from standard input and verifies if they correctly sort the stack.

### The Challenge

You have two stacks (A and B) and a set of instructions to manipulate them:

| Operation | Description |
|-----------|-------------|https://github.com/zer0rg/push_swap
| `sa` | Swap the first 2 elements at the top of stack A |
| `sb` | Swap the first 2 elements at the top of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Take the first element from B and put it at the top of A |
| `pb` | Take the first element from A and put it at the top of B |
| `ra` | Rotate stack A up (first element becomes last) |
| `rb` | Rotate stack B up (first element becomes last) |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack A (last element becomes first) |
| `rrb` | Reverse rotate stack B (last element becomes first) |
| `rrr` | `rra` and `rrb` at the same time |

### Algorithm: Turk Sort

This implementation uses the **Turk algorithm**, an efficient cost-based approach:

1. Push only 2 elements from stack A to stack B (to have elements to compare against)
2. For each element in A, find its **target** in B (the closest smaller number)
3. Calculate the **cost** to rotate the A node and its target B node to the top of their respective stacks
4. Execute the cheapest move (using combined rotations `rr`/`rrr` when both go in the same direction)
5. Push the element from A to B
6. Repeat until A is empty
7. Push all elements back from B to A (starting with the maximum)
8. Final rotation to put the minimum at the top of A

For small cases (≤3 elements), optimized hard-coded solutions are used.

## Project Structure

```
push_swap/
├── main.c                 # Entry point
├── Makefile               # Build system
├── headers/
│   └── push_swap.h        # Header with structures and prototypes
├── src/
│   ├── parse.c            # Argument parsing
│   ├── sort.c             # Main sorting algorithm (Turk)
│   ├── sort_small.c       # Optimized sorting for 2-3 elements
│   ├── operations/        # Stack operations
│   │   ├── push.c         # pa, pb
│   │   ├── swap.c         # sa, sb, ss
│   │   ├── rotate.c       # ra, rb, rr
│   │   └── reverse_rotate.c # rra, rrb, rrr
│   └── utils/
│       ├── stack.c        # Stack initialization and utilities
│       └── free.c         # Memory management
├── checker/               # Bonus: checker program
│   ├── checker.c
│   └── checker.h
└── libft/                 # Custom C library
```

## Instructions

### Requirements

- C compiler
- Make
- Unix-like system (Linux/macOS)

### Compilation

```bash
# Compile push_swap
make

# Compile checker (bonus)
make bonus

# Clean object files
make clean

# Full clean (including executables)
make fclean

# Recompile
make re
```

### Usage

#### push_swap

```bash
# With multiple arguments
./push_swap 3 2 1 5 4

# With a single quoted string
./push_swap "3 2 1 5 4"

# Using with checker
./push_swap 3 2 1 | ./checker 3 2 1

# Count number of operations
./push_swap 3 2 1 5 4 | wc -l
```

#### checker (bonus)

```bash
# Pipe operations to checker
./push_swap 3 2 1 | ./checker 3 2 1
# Output: OK (if sorted) or KO (if not sorted)
```

### Performance Benchmarks

| Stack Size | Target Operations | Algorithm Used |
|------------|-------------------|----------------|
| 3 | ≤ 3 | Hard-coded |
| 5 | ≤ 12 | Hard-coded |
| 100 | ≤ 700 | Turk Sort |
| 500 | ≤ 5500 | Turk Sort |

## Resources

### Documentation & References

- [Push_swap Article - Medium](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Visualizer for Push_swap](https://github.com/o-reo/push_swap_visualizer)
### AI Usage

AI assistance (GitHub Copilot with Claude) was used in this project for:

- **Documentation**: Generating this README.md file
- **Debugging assistance**: Identifying logical errors in rotation calculations

The core algorithm design, data structure choices, and problem-solving approach were developed independently.

## Author

- **rgerman-** - 42 Madrid

---

*Made with ❤️ at 42 Madrid by rgerman-*
