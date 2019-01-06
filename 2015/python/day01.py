#!/usr/bin/env python3

"""
Day 1: Not Quite Lisp
https://adventofcode.com/2015/day/1
"""

from inputlines import inputLines


def main():
    lines = inputLines('../inputs/day01input.txt')
    line = lines[0]

    # part 1
    print(line.count('(') - line.count(')'))

    # part 2
    floor = 0
    for (i, c) in enumerate(line, 1):
        if c == '(':
            floor += 1
        elif c == ')':
            floor -= 1

        if floor == -1:
            break

    print(i)


if __name__ == '__main__':
    main()
