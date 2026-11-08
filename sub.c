/*
Name : E.Krishnaveni
Date 21-08-2026
File name : sub.c
*/
#include "apc.h"    // Include APC header file

// Function to determine the larger operand and perform subtraction accordingly
void subtraction_operation(node *head1, node *tail1, node *head2, node *tail2,
                           node **headR, node **tailR)
{
    int len1;    // Store length of first operand
    int len2;    // Store length of second operand
    int result;    // Store comparison result

    len1 = list_len(head1);    // Find the number of digits in first operand
    len2 = list_len(head2);    // Find the number of digits in second operand

    if (len1 > len2)    // Check whether first operand has more digits
    {
        subtraction(tail1, tail2, headR, tailR);    // Subtract second operand from first operand
    }
    else if (len1 < len2)    // Check whether second operand has more digits
    {
        printf("-");    // Print negative sign
        subtraction(tail2, tail1, headR, tailR);    // Subtract first operand from second operand
    }
    else    // Execute when both operands have the same number of digits
    {
        result = compare_list(head1, head2);    // Compare both operands

        if (result == OPERAND1)    // Check whether first operand is greater
        {
            subtraction(tail1, tail2, headR, tailR);    // Perform first operand minus second operand
        }
        else if (result == OPERAND2)    // Check whether second operand is greater
        {
            printf("-");    // Print negative sign
            subtraction(tail2, tail1, headR, tailR);    // Perform second operand minus first operand
        }
        else    // Execute when both operands are equal
        {
            insert_first(headR, tailR, 0);    // Store zero as the result
        }
    }
}


// Function to subtract two large numbers using borrow
void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *temp1 = tail1;    // Create temporary pointer for first operand
    node *temp2 = tail2;    // Create temporary pointer for second operand

    int borrow = 0;    // Initialize borrow to zero

    while (temp1 != NULL || temp2 != NULL)    // Continue until all digits are processed
    {
        int digit1 = 0;    // Initialize first digit as zero
        int digit2 = 0;    // Initialize second digit as zero

        if (temp1 != NULL)    // Check whether first operand has a digit
        {
            digit1 = temp1->data;    // Get digit from first operand
        }

        if (temp2 != NULL)    // Check whether second operand has a digit
        {
            digit2 = temp2->data;    // Get digit from second operand
        }

        digit1 = digit1 - borrow;    // Subtract previous borrow from first digit

        borrow = 0;    // Reset borrow for current subtraction

        if (digit1 < digit2)    // Check whether borrowing is required
        {
            digit1 = digit1 + 10;    // Add 10 to the first digit
            borrow = 1;    // Set borrow for the next digit
        }

        int data = digit1 - digit2;    // Calculate the current result digit

        if (insert_first(headR, tailR, data) == FAILURE)    // Insert result digit at the beginning
        {
            return;    // Exit if insertion fails
        }

        if (temp1 != NULL)    // Check whether first operand has more digits
        {
            temp1 = temp1->prev;    // Move to the previous digit
        }

        if (temp2 != NULL)    // Check whether second operand has more digits
        {
            temp2 = temp2->prev;    // Move to the previous digit
        }
    }

    // Remove leading zeros from the subtraction result
    while (*headR != NULL && (*headR)->data == 0 && *headR != *tailR)
    {
        node *temp = *headR;    // Store the current head temporarily

        *headR = (*headR)->next;    // Move head to the next node

        (*headR)->prev = NULL;    // Remove previous link from the new head

        free(temp);    // Free memory of the removed node
    }
}