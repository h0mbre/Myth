# Myth

## Background

Myth is an ADD/SUB encoder for generating alphanumeric shellcode. It takes user-supplied shellcode and outputs the assembly instructions, in a Python-friendly format, necessary to push that shellcode onto the stack by iteratively manipulating the EAX register. This tool was based upon [Slink](https://github.com/ihack4falafel/Slink) by @ihack4falafel. They are similar looking in the terminal, but I believe the encoding arithmetic is significantly different. Hashim's tool is also much more robust with respect to mitigating potential bad characters. 

This was mainly an excercise in exploring C++ and trying to make something useful at the same time. Hopefully some CTP/OSCE students get some use out of the tool. I intend to implement a 'Tutor' mode which will explain each step in a way that hopefully teaches those interested in the logical steps behind the tool so that they can accomplish the same results by hand. 

## Use

Myth accepts shellcode input in the following formats: `545b81ebb90d0000ffd3` or `545B81EBB90D0000FFD3`.

## Example

![](/Myth/myth.gif)

