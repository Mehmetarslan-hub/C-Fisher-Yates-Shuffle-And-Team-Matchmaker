# C Fisher-Yates Shuffle & Team Matchmaker

A C application that implements the $O(n)$ **Fisher-Yates Shuffle Algorithm** to randomly randomize student/employee lists and partition them into dynamic teams without bias.

## Key Features
- **Fisher-Yates Algorithm**: Unbiased $O(n)$ random permutation swapping string pointers directly.
- **Dynamic Pointer Allocation**: Heap allocation for array of strings (`char **`) with safe deallocation.
- **Automated Group Matchmaking**: Configurable group sizing with formatted team outputs.

## How to Run

1. Compile:
   ```bash
   gcc main.c -o matchmaker