#!/usr/bin/python3
"""Permiter of an island calc."""


def island_perimeter(grid):
    """Calculate the permiter of an island."""
    permi = 0
    if len(grid) == 0:
        return permi

    for i in range(0, len(grid)):
        for j in range(0, len(grid[i])):
            if grid[i][j] == 1:
                permi += 4
                if (i - 1) >= 0 and grid[i - 1][j] == 1:
                    permi -= 1
                if (i + 1) < len(grid) and grid[i + 1][j] == 1:
                    permi -= 1
                if (j - 1) >= 0 and grid[i][j - 1] == 1:
                    permi -= 1
                if (j + 1) < len(grid[i]) and grid[i][j + 1] == 1:
                    permi -= 1

    return permi
