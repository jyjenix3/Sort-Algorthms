# Sort

**Merge Sort vs Quick Sort – Comparison Analysis and Sorted Array Merging in C**

## About the Project

Sort is a C-based sorting algorithm project that compares the performance of Merge Sort and Quick Sort using an integer dataset.

The program takes an unsorted batch of records and sorts it in ascending order using both algorithms. It also counts the number of element comparisons performed during sorting.

After sorting, a second batch of already-sorted records is provided. Instead of sorting all the records again, the program uses a merging technique to combine both sorted arrays into one final sorted dataset.

## Features

- Implements Merge Sort.
- Implements Quick Sort using the last element as the pivot.
- Counts element comparisons in both sorting algorithms.
- Combines two sorted arrays using the Merge technique.
- Reads input from a text file.
- Supports duplicate values.
- Displays the final array in ascending order.

## Algorithms Used

| Algorithm | Purpose |
|---|---|
| Merge Sort | Sorts the original dataset |
| Quick Sort | Sorts using the last element as pivot |
| Merge Technique | Combines two sorted arrays |

## Project Structure

```text
SortMetrics/
├── main.c
├── input.txt
└── README.md
```

## Input Format

The program reads data from `input.txt`.

### Sample Input

```text
8 4
7 2 9 1 5 3 4 6
0 2 8 10
```

### Input Explanation

- `8` – Number of records in the original batch.
- `4` – Number of records in the new batch.
- `7 2 9 1 5 3 4 6` – Original unsorted records.
- `0 2 8 10` – New records already sorted in ascending order.

## Expected Output

```text
Merge Sort: 1 2 3 4 5 6 7 9
Quick Sort: 1 2 3 4 5 6 7 9
Merge Comparisons: 16
Quick Comparisons: 15
Updated Array: 0 1 2 2 3 4 5 6 7 8 9 10
```

## How to Run

**1. Clone the repository**

```bash
git clone https://github.com/your-username/SortMetrics.git
```

**2. Open the project directory**

```bash
cd Sort
```

**3. Compile the program**

```bash
gcc main.c -o sort -std=c99
```

**4. Run the program**

```bash
./sort
```

For Windows:

```bash
sort.exe
```

Make sure `input.txt` is in the same working directory as the executable.

## Concepts Covered

- Sorting Algorithms
- Divide and Conquer
- Array Manipulation
- Element Comparison Counting
- File Handling
- Merging Sorted Arrays

## Learning Objectives

The main objective of this project is to understand how Merge Sort and Quick Sort work and compare their element comparison counts. It also demonstrates how a new sorted dataset can be combined with an existing sorted dataset without sorting the entire collection again.
