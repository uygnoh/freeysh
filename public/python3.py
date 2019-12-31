#!/usr/bin/env python3

print("Hello World")

def fibonacci(var):
    a, b = 0, 1
    while b < var:
        print(b, end=',')
        a, b = b, a+b
fibonacci(1000)
print()
