/*
Name : E.Krishnaveni
Date : 21-08-2026
File name : add.c 
*/
#include "apc.h"
//Functions to add two large numbers using linked lists
void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    int carry = 0;//Initialize carry to zero
     //Continue until all digits and carry are processed
    while (tail1 != NULL || tail2 != NULL || carry != 0)
    {
        int sum = carry;//Intialize carry to zero

        if (tail1 != NULL) //check whether first number has a digit
        {
            sum =sum+ tail1->data;//Add the digits of the first number
            tail1 = tail1->prev;//Move to the previous digit of the first number
        }

        if (tail2 != NULL) //check whether second number has a digit
        {
            sum =sum+ tail2->data;//Add the digits of the second number
            tail2 = tail2->prev;//Move to the previous digit of the second number
        }
        int digit = sum % 10;//Extract the last digit of the sum
         carry = sum/10;//Calculate the carry for the next digit
         //Insert the calculated digit at the beginning
       if(insert_first(headR, tailR, digit)==FAILURE)
       {
        return;//Return if memory allocation or insertion fails
       }
    }
}

