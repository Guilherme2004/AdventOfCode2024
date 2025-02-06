# Advent of Code - Day 01

## Problem Overview
[Problem's Description](https://adventofcode.com/2024/day/1)

In this problem, you are tasked with calculating the distance between the values of two arrays, where the two arrays should be paired up so the smallest value from the first array is in the same position as the second's array smallest value. The challenge involves ordering both arrays and then getting the sum of the distances between the values in each row.

## My Solution

The solution I implemented for this problem is written in C. It solves the problem by utilizing a Quicksort algorithm to sort both arrays, thus getting them aligned, then a for statement to iterate through the arrays and calculate sum of the distances between the corresponding values.

## Files:
- `Day01.c`: The main C program that solves the Day 1 problem.
