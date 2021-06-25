# push_swap

## Introduction :

This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting.

### Stack :

A stack is a data structure that serves as a collection of elements that follows a particular order in which the operations are performed. A stack follows LIFO principle the element inserted at the last is the first element to come out. The elements can be inserted and deleted only from one side of the stack.

### Implementing Stack in C :

A stack can be easily implemented either through an array or a linked list.

## big O notation :

> Big O notation is a mathematical notation that describes the limiting behavior of a function when the argument tends towards a particular value or infinity.

[What is Big O Notation Explained: Space and Time Complexity](https://www.freecodecamp.org/news/big-o-notation-why-it-matters-and-why-it-doesnt-1674cfa8a23c/)

for some examples :

[Big O Notation Explained with Examples](https://www.freecodecamp.org/news/big-o-notation-explained-with-examples/)

## Bucket sort :

Bucket Sort works by distributing the elements of an array into a number of buckets. Each bucket is then sorted individually, either using a different sorting algorithm or by recursively applying the bucket sorting algorithm.

## Approach:

I stored all integers parsed into the stack in an array.

The idea is instead of sorting one large chunk of 100 or 500 numbers, we could actually cut it down to small ones. Push all the elements by chunks to stack B and take back the elements to stack in the correct order.