# Myth

## Background

Myth is an ADD/SUB encoder for generating alphanumeric shellcode. It takes user-supplied shellcode and outputs the assembly instructions, in a Python-friendly format, necessary to push that shellcode onto the stack by iteratively manipulating the EAX register.

This was mainly an excercise in exploring C++ and trying to make something useful at the same time. Hopefully some CTP/OSCE students get some use out of the tool. 

Inspired by [Slink](https://github.com/ihack4falafel/Slink) and [z3ncoder](https://github.com/marcosValle/z3ncoder).

## Use

Myth accepts shellcode input in the following formats: `545b81ebb90d0000ffd3` or `545B81EBB90D0000FFD3`.

## Example

![](/myth.gif)

## Compiling

`g++ myth.cpp -o myth`
