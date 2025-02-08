# Advent of Code - Day 02

## Problem Overview
[Problem's Description](https://adventofcode.com/2024/day/2)

In this problem, you are given a jagged array containing integers. You must then find how many arrays fit the following condition: 
* The values must either always increase or decrease. 
* Any two adjacent values must differ by at least 1 and at most 3.
   
The part 2 of the challenge then stipulates that at most 1 value of each array can be disconsidered to try to achive the condition.

Example:
```
Input:

7 6 4 2 1
1 2 7 8 9
9 7 6 2 1
1 3 2 4 5
8 6 4 4 1
1 3 6 7 9

Array 1 is Safe since all values only decrease by 1, 2 or 3.
Array 2 and 3 are Unsafe regardless of which value is removed.
Array 4 becomes Safe when removing the value "3".
Array 5 becomes Safe when removing the value "4".
Array 6 is Safe since all values only increase by 1, 2 or 3.
```

## My Solution

First i read the file containing the input and dynamically allocate memory for the 2D Array, storing values. To solve the problem, i iterate through each array and check if it fills the condition N times, first by removing no value, then trying to remove each value until it either satisfies the condition or not.

## Files:
- `Day02.c`: The main C program that solves the Day 2 problem.
