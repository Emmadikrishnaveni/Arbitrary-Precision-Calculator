/*
Name : E.Krishnaveni
Date : 21-08-2026
File name:main.c
Description : "My project is an Arditrary precision Calculator implemented in c.
               The main purpose is to perform arithetic operations on very large integers
               that cannot be handled by normal c data types. i used a doubly linked list to 
               store each digit and implemented addition,subtraction,multiplication,and division
               using linked - list operations. I also implemented input validation, number comparison, 
               leading-zero removal and dynamic memory management.
*/
#include "apc.h"    // Include APC header file

/* Function to print the result with its sign */
// Function to print the final result along with its sign
void print_signed_result(node *headR, char sign)
{
    if (headR == NULL)    // Check whether result list is empty
    {
        printf("0\n");    // Print zero if result is empty
        return;    // Exit the function
    }

    /* Zero should never be printed as -0 */
    if (headR->data == 0 && headR->next == NULL)    // Check whether result is exactly zero
    {
        printf("0\n");    // Print zero without a negative sign
        return;    // Exit the function
    }

    if (sign == '-')    // Check whether result is negative
    {
        printf("-");    // Print negative sign
    }

    print_list(headR);    // Print the result stored in the linked list
}


/* Function to subtract only the magnitudes of two numbers */
// Function to perform subtraction based on the larger magnitude
void magnitude_subtraction(node *head1, node *tail1, node *head2, node *tail2, node **headR, node **tailR)
                           
{
    int result;    // Store comparison result

    result = compare_list(head1, head2);    // Compare the magnitudes of two numbers

    if (result == OPERAND1)    // Check whether first operand is greater
    {
        subtraction(tail1, tail2, headR, tailR);    // Perform first operand minus second operand
    }
    else if (result == OPERAND2)    // Check whether second operand is greater
    {
        subtraction(tail2, tail1, headR, tailR);    // Perform second operand minus first operand
    }
    else    // Execute when both operands are equal
    {
        insert_first(headR, tailR, 0);    // Store zero as the result
    }
}


// Main function to perform APC operations
int main(int argc, char *argv[])
{
    node *head1 = NULL;    // Initialize head pointer for first operand
    node *tail1 = NULL;    // Initialize tail pointer for first operand

    node *head2 = NULL;    // Initialize head pointer for second operand
    node *tail2 = NULL;    // Initialize tail pointer for second operand

    node *headR = NULL;    // Initialize head pointer for result
    node *tailR = NULL;    // Initialize tail pointer for result

    /* Validation */
    if (cla_validation(argc, argv) == FAILURE)    // Validate command-line arguments
    {
        printf("Usage: %s <num1> <operator> <num2>\n", argv[0]);    // Display correct usage format
        return FAILURE;    // Exit if validation fails
    }

    /* Get signs */
    char sign1 = '+';    // Initialize sign of first operand as positive
    char sign2 = '+';    // Initialize sign of second operand as positive

    if (argv[1][0] == '-')    // Check whether first operand is negative
    {
        sign1 = '-';    // Set first operand sign as negative
    }

    if (argv[3][0] == '-')    // Check whether second operand is negative
    {
        sign2 = '-';    // Set second operand sign as negative
    }

    /* Create lists */
    create_list(argv[1], &head1, &tail1);    // Create linked list for first operand
    create_list(argv[3], &head2, &tail2);    // Create linked list for second operand

    /* Remove leading zeros */
    remove_pre_zeros(&head1);    // Remove leading zeros from first operand
    remove_pre_zeros(&head2);    // Remove leading zeros from second operand

    /* Find tail1 */
    tail1 = head1;    // Start traversing first list from head

    while (tail1 != NULL && tail1->next != NULL)    // Traverse until the last node
    {
        tail1 = tail1->next;    // Move to the next node
    }

    /* Find tail2 */
    tail2 = head2;    // Start traversing second list from head

    while (tail2 != NULL && tail2->next != NULL)    // Traverse until the last node
    {
        tail2 = tail2->next;    // Move to the next node
    }

    char oper = argv[2][0];    // Store the arithmetic operator

    switch (oper)    // Select the operation based on the operator
    {

        case '+':    // Handle addition operation

            /* +A + +B = +(A+B) */
            if (sign1 == '+' && sign2 == '+')    // Check whether both operands are positive
            {
                addition(tail1, tail2, &headR, &tailR);    // Add both operands

                print_signed_result(headR, '+');    // Print positive result
            }

            /* -A + -B = -(A+B) */
            else if (sign1 == '-' && sign2 == '-')    // Check whether both operands are negative
            {
                addition(tail1, tail2, &headR, &tailR);    // Add the magnitudes

                print_signed_result(headR, '-');    // Print negative result
            }

            /* +A + (-B) = A-B */
            else if (sign1 == '+' && sign2 == '-')    // Check whether first is positive and second is negative
            {
                int result = compare_list(head1, head2);    // Compare magnitudes of both operands

                if (result == OPERAND1)    // Check whether first magnitude is greater
                {
                    subtraction(tail1, tail2, &headR, &tailR);    // Subtract second magnitude from first

                    print_signed_result(headR, '+');    // Print positive result
                }
                else if (result == OPERAND2)    // Check whether second magnitude is greater
                {
                    subtraction(tail2, tail1, &headR, &tailR);    // Subtract first magnitude from second

                    print_signed_result(headR, '-');    // Print negative result
                }
                else    // Execute when both magnitudes are equal
                {
                    printf("0\n");    // Print zero
                }
            }

            /* -A + B = B-A */
            else if (sign1 == '-' && sign2 == '+')    // Check whether first is negative and second is positive
            {
                int result = compare_list(head1, head2);    // Compare magnitudes of both operands

                if (result == OPERAND1)    // Check whether first magnitude is greater
                {
                    subtraction(tail1, tail2, &headR, &tailR);    // Subtract second magnitude from first

                    print_signed_result(headR, '-');    // Print negative result
                }
                else if (result == OPERAND2)    // Check whether second magnitude is greater
                {
                    subtraction(tail2, tail1, &headR, &tailR);    // Subtract first magnitude from second

                    print_signed_result(headR, '+');    // Print positive result
                }
                else    // Execute when both magnitudes are equal
                {
                    printf("0\n");    // Print zero
                }
            }

            break;    // Exit addition case


        case '-':    // Handle subtraction operation

            /* +A - +B = A-B */
            if (sign1 == '+' && sign2 == '+')    // Check whether both operands are positive
            {
                int result = compare_list(head1, head2);    // Compare magnitudes of both operands

                if (result == OPERAND1)    // Check whether first magnitude is greater
                {
                    subtraction(tail1, tail2, &headR, &tailR);    // Calculate A-B

                    print_signed_result(headR, '+');    // Print positive result
                }
                else if (result == OPERAND2)    // Check whether second magnitude is greater
                {
                    subtraction(tail2, tail1, &headR, &tailR);    // Calculate B-A

                    print_signed_result(headR, '-');    // Print negative result
                }
                else    // Execute when both operands are equal
                {
                    printf("0\n");    // Print zero
                }
            }

            /* +A - (-B) = A+B */
            else if (sign1 == '+' && sign2 == '-')    // Check positive minus negative
            {
                addition(tail1, tail2, &headR, &tailR);    // Add both magnitudes

                print_signed_result(headR, '+');    // Print positive result
            }

            /* -A - B = -(A+B) */
            else if (sign1 == '-' && sign2 == '+')    // Check negative minus positive
            {
                addition(tail1, tail2, &headR, &tailR);    // Add both magnitudes

                print_signed_result(headR, '-');    // Print negative result
            }

            /* -A - (-B) = B-A */
            else if (sign1 == '-' && sign2 == '-')    // Check negative minus negative
            {
                int result = compare_list(head1, head2);    // Compare magnitudes of both operands

                if (result == OPERAND1)    // Check whether A is greater than B
                {
                    /* A > B => -(A-B) */
                    subtraction(tail1, tail2, &headR, &tailR);    // Calculate A-B

                    print_signed_result(headR, '-');    // Print negative result
                }
                else if (result == OPERAND2)    // Check whether B is greater than A
                {
                    /* B > A => +(B-A) */
                    subtraction(tail2, tail1, &headR, &tailR);    // Calculate B-A

                    print_signed_result(headR, '+');    // Print positive result
                }
                else    // Execute when both magnitudes are equal
                {
                    printf("0\n");    // Print zero
                }
            }

            break;    // Exit subtraction case


        case 'x':    // Handle lowercase multiplication operator
        case 'X':    // Handle uppercase multiplication operator

            multiplication(tail1, tail2, &headR, &tailR);    // Multiply both operands

            /* Different signs = negative, same signs = positive */
            if (sign1 != sign2)    // Check whether operand signs are different
            {
                print_signed_result(headR, '-');    // Print negative result
            }
            else    // Execute when both signs are the same
            {
                print_signed_result(headR, '+');    // Print positive result
            }

            break;    // Exit multiplication case


        case '/':    // Handle division operation

            division(head1, head2, &headR, &tailR);    // Divide first operand by second operand

            /* Different signs = negative, same signs = positive */
            if (sign1 != sign2)    // Check whether operand signs are different
            {
                print_signed_result(headR, '-');    // Print negative result
            }
            else    // Execute when both signs are the same
            {
                print_signed_result(headR, '+');    // Print positive result
            }

            break;    // Exit division case


        default:    // Handle invalid operator
            printf("Invalid operator\n");    // Display invalid operator message
            return FAILURE;    // Return failure status
    }

    return SUCCESS;    // Return success status
}