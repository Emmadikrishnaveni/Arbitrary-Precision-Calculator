/*
Name : E.Krishnaveni
Date 21-08-2026
File name :  mul.c
*/
#include "apc.h"

//function to multiply two large numbers using linked lists
void multiplication(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *temp2 = tail2; //create a temporary pointer to transver the second number

    node *result = NULL; //Initialize result head pointer
    node *result_tail = NULL; // initalize result tail pointer

    int shift = 0;//Initialize shift count for multiply by powers of 10

    insert_first(&result, &result_tail, 0);// initialize result with zero

    while (temp2 != NULL)// Traverse each digit of the second number 
    {
        node *temp1 = tail1;//start traversing the first number from its tail

        node *partial = NULL;
        node *partial_tail = NULL;

        int carry = 0;//initialize carry to zero

        /* Multiply one digit */
        while (temp1 != NULL)//Traverse each digit of the first number
        {
            int product = (temp1->data * temp2->data) + carry;//Multiply two digits and add carry
            int digit = product % 10;//Extract the last digit of the product
            carry = product / 10;//calculate the carry for the next multiplication
            //Insert the calculated digit into partial product
            insert_first(&partial, &partial_tail, digit);

             // move to the previous digit of the first number
            temp1 = temp1->prev;
        }

        /* Remaining carry */
        if (carry != 0)//check whether any carry is remaining
        {
            insert_first(&partial, &partial_tail, carry);//Insert the remaining carry into partial product
        }

        /*
         * Add zeros at the END because they represent
         * multiplication by 10, 100, 1000...
         */
        for (int i = 0; i < shift; i++)
        {
            //Appened zero to shift the partial product
            insert_last(&partial, &partial_tail, 0);
        }

        /* Add partial product to result */
        node *new_result = NULL;//Initialize new result head pointer
        node *new_result_tail = NULL;//Initialize new result tail pointer
        // add partial product to the current result
        addition(result_tail, partial_tail, &new_result, &new_result_tail);

        delete_list(&result, &result_tail);//free the memory used by the old result
        delete_list(&partial, &partial_tail);//free the memory used by the partial product

        result = new_result;//store the new result as the current result
        result_tail = new_result_tail;// update the result tail pointer

        shift++;//Increase the shift for the next digit

        temp2 = temp2->prev;// move to the previous digit of the second number
    }

    /* Remove leading zeros */
    while (result != NULL && result->data == 0 && result->next !=NULL)//Remove unnecessary zeros from the beginning
           
    {
        // store the current first node temporarily
        node *temp = result;
         // move the result head to the next node 
        result = result->next;

        result->prev = NULL; // remove the previous link of the new head

        free(temp);// free the memory of the removed node
    }

    /* Find tail */
    result_tail = result; // start finding the tail from the result head
    // traverse until the last node
    while (result_tail != NULL && result_tail->next !=NULL)
    {
        result_tail = result_tail->next; // move to the next node
    }

    *headR = result; // store the final result head address
    //store the final result tail address
    *tailR = result_tail;
}