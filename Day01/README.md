# Advent of Code - Day 01

## Problem Overview
[Problem's Description](https://adventofcode.com/2024/day/1)

In this problem, you are given multiple lines with 2 columns of integers, the left column is the left array and the second the right array. You must then find how often each value from the left array (repeated values included) appear on the right array, and then compute it into a total.
Example:
```
Input:

3   4
4   3
2   5
1   3
3   9
3   3

Total = 3*3 + 4*1 + 2*0 + 1*0 + 3*3 + 3*3 = 31
```

## My Solution

The solution I implemented uses the quicksort algorithm to sort both arrays. Then, I iterate through the left array and use the `checkAdjacents()` function to determine how many times each value appears, ensuring that I only process each unique value once.

Next, I perform a binary search to locate the same value in the right array. From that position, I use `checkAdjacents()` again to determine the range of occurrences in the right array. This approach optimizes the calculation by ensuring each value is processed only once, reducing redundant computations.

## Files:
- `Day01.c`: The main C program that solves the Day 1 problem.
