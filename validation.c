/*
Name : E.Krishnaveni
Date 21-08-2026
File name : validation.c
*/
#include "apc.h"    // Include APC header file

// Function to validate command-line arguments, operands, and operator
int cla_validation(int argc, char *argv[])
{
    if (argc != 4)    // Check whether exactly four command-line arguments are provided
    {
        printf("Usage: ./a.out <operand1> <operator> <operand2>\n");    // Display correct usage format
        return FAILURE;    // Return failure for invalid argument count
    }

    int i = 0;    // Initialize index for operand validation

    if (argv[1][0] == '+' || argv[1][0] == '-')    // Check whether first operand contains a sign
    {
        i = 1;    // Skip the sign character
    }

    if (argv[1][i] == '\0')    // Check whether first operand contains only a sign
    {
        printf("Invalid operand1\n");    // Display invalid first operand message
        return FAILURE;    // Return failure
    }

    while (argv[1][i] != '\0')    // Traverse all characters of first operand
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')    // Check whether character is not a digit
        {
            printf("Invalid operand1\n");    // Display invalid first operand message
            return FAILURE;    // Return failure
        }

        i++;    // Move to the next character
    }

    if (argv[2][0] != '+' && argv[2][0] != '-' &&
        argv[2][0] != 'x' && argv[2][0] != 'X' &&
        argv[2][0] != '/')    // Check whether operator is valid
    {
        printf("Invalid operator\n");    // Display invalid operator message
        return FAILURE;    // Return failure
    }

    if (argv[2][1] != '\0')    // Check whether operator contains more than one character
    {
        printf("Invalid operator\n");    // Display invalid operator message
        return FAILURE;    // Return failure
    }

    i = 0;    // Reset index for second operand

    if (argv[3][0] == '+' || argv[3][0] == '-')    // Check whether second operand contains a sign
    {
        i = 1;    // Skip the sign character
    }

    if (argv[3][i] == '\0')    // Check whether second operand contains only a sign
    {
        printf("Invalid operator2\n");    // Display invalid second operand message
        return FAILURE;    // Return failure
    }

    while (argv[3][i] != '\0')    // Traverse all characters of second operand
    {
        if (argv[3][i] < '0' || argv[3][i] > '9')    // Check whether character is not a digit
        {
            printf("Invalid operand2\n");    // Display invalid second operand message
            return FAILURE;    // Return failure
        }

        i++;    // Move to the next character
    }

    return SUCCESS;    // Return success when all validations pass
}