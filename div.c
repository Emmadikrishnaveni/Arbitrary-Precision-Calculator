/*
Name : E.Krishnaveni
Date 21-08-2026
File name : div.c
*/
#include "apc.h"

/* Function to perform division */
void division(node *head1, node *head2, node **headR, node **tailR)
    
{
    //Initialize quotient count to zero
    int count = 0;

    node *temp1 = NULL;//Initialize temporary divided head
    node *temp1_tail = NULL;//Initialize temporary divided tail

    node *temp2 = NULL;//Intialize temporary divisor head
    node *temp2_tail = NULL;//Initialize temporary divisor tail

    node *res = NULL;//Initialize result head
    node *res_tail = NULL;//Initialize result tail

    /* Division by zero */
    if (head2 != NULL && head2->data == 0 && head2->next == NULL)//Check whether divisor is zero
    {
        printf("Erro:Division by zero\n");//Display division by zero error
        return;
    }

    /* 0 / non-zero = 0 */
    if (head1 != NULL && head1->data == 0 && head1->next == NULL)//Check whether divided is zero
    {
        insert_first(headR, tailR, 0);//Store zero as the result
        return;
    }

    /* Copy dividend */
    node *temp = head1;//Create temporary pointer to traverse divided

    while (temp != NULL)//Traverse the divided list
    {
        insert_last(&temp1, &temp1_tail, temp->data);//Copy each digit into temporary dividend list

        temp = temp->next;//Move to the next digit
    }

    /* Copy divisor */
    temp = head2;//Reset temporary pointer to the divisor

    while (temp != NULL)//Traverse the divisor list
    {
        insert_last(&temp2, &temp2_tail, temp->data);//copy each digit into temporary divisor list

        temp = temp->next;//move to the next digit
    }

    /*
     * Repeatedly subtract divisor from dividend
     * until dividend becomes smaller.
     */
    while (compare_list(temp1, temp2) != OPERAND2)//Continue subtraction while dividend is greater than or equal to divisor
    {
        node *sub_head = NULL;//Initialize subtraction result head
        node *sub_tail = NULL;//Initialize subtraction result tail

        subtraction(temp1_tail,temp2_tail, &sub_head, &sub_tail);//Subtract divisor from dividend

        delete_list(&temp1, &temp1_tail);//Delete the old divided list

        temp1 = sub_head;//Store subtraction result as new dividend
        temp1_tail = sub_tail;//update new dividend tail

        count++;//Increment quotient count
    }

    /* Delete divisor copy */
    delete_list(&temp2, &temp2_tail);

    /* Store quotient */
    if (count == 0)//Check whether divisor is greater than dividend
    {
        insert_first(&res, &res_tail, 0);//Store zero as quotient
    }
    else
    {
        while (count != 0)//Convert quotient count into digits
        {
            insert_first(&res, &res_tail, count % 10);//Extract and insert the last digit of quotient

            count = count / 10;//Remove the last digit from quotient count
        }
    }
    delete_list(&temp1, &temp1_tail);//Free memory allocated for temporary dividend

    *headR = res;//Store result head address
    *tailR = res_tail;//Store result tail address
}