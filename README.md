# Arbitrary Precision Calculator in C

## Project Overview

The Arbitrary Precision Calculator is a command-line application developed using C programming. It performs arithmetic operations on large numbers beyond the limitations of standard integer data types.

## Features

- Addition of large numbers
- Subtraction of large numbers
- Multiplication of large numbers
- Division of large numbers
- Command-line input handling
- Input validation

## Technologies Used

- Programming Language: C
- Compiler: GCC
- Build Tool: Make
- Platform: Linux (Ubuntu)

## Project Structure

| File | Description |
|---|---|
| main.c | Main program and command-line arguments |
| apc.c | Core calculator functionality |
| apc.h | Header file |
| add.c | Addition operation |
| sub.c | Subtraction operation |
| mul.c | Multiplication operation |
| div.c | Division operation |
| validation.c | Input validation |
| makefile | Build configuration |

## Compilation

Clone the repository:

    git clone https://github.com/Emmadikrishnaveni/Arbitrary-Precision-Calculator.git

Navigate to the project directory:

    cd Arbitrary-Precision-Calculator

Compile the project:

    make

## Execution

Run the calculator using:

    ./apc <operand1> <operator> <operand2>

Example:

    ./apc 453 + 3

Expected output:

    456
## Sample Operations

| Operation | Command | Expected Result |
|---|---|---|
| Addition | `./apc 453 + 3` | 456 |
| Subtraction | `./apc 453 - 3` | 450 |
| Multiplication | `./apc 453 x 3` | 1359 |
| Division | `./apc 453 / 3` | 151 |
## Author

**Emmadi Krishnaveni**

GitHub: [Emmadikrishnaveni](https://github.com/Emmadikrishnaveni)
