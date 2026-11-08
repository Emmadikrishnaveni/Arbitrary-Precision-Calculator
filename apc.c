/*
Name : E.Krishnaveni
Date 21-08-2026
File name : apc.c
*/
#include "apc.h"

// Function definition
//Function to create a linked list from the given operand
void create_list(char *opr, node **head, node **tail)
{
    int i=0;//Initialize index to zero
    if(opr[0] == '+' || opr[0] == '-')//check whether operand has a sign
    i = 1;//Skip the sign character
    while (opr[i]!='\0')//Traverse the operand until null character
    {
        int digit = opr[i] - '0';//convert character digit into integer
        
        if(insert_last(head, tail, digit)==FAILURE)//Insert digit at the end of the linked list
        {
            return;//Return if insertion fails
        }
        i++;//move to the next character
    }
}
//Function to insert a new node at the beginning of the list
int insert_first(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));//Allocate memory for a new node
    if (new==NULL)//check whether memory allocation failed
    {
         return FAILURE;//Return failure if memory allocation fails
    } 
    
    new->data = data;//Store data in the new node
    new->prev = NULL;//set next pointer of new node to NULL
    new->next = *head;//Link new node to the current tail
    if(*head!=NULL)//Check whether the list is not empty
    {
        (*head)->prev=new;//Link current tail to the new node
    }
    else
    {
        *tail = new;//Set new node as tail when list is empty
    }
    *head= new;//update tail to the new node
    return SUCCESS;
}
//Function to insert a new node at the end of the list
int insert_last(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));//Allocate memory for a new node
    if (new==NULL)//Check whether memory allocation failed
    {
        return FAILURE;//Return failure if memory allocation fails
    }

    new->data = data;//Store data in the new node
    new->next = NULL;//Set next pointer of new node to NULL
    new->prev = *tail;//Link new node to the current tail

    if (*tail !=NULL)//Check whether the list is not empty
    {
        (*tail)->next=new;//Link current tail to the new node
    }
    else
    {
        *head=new;//Set new node as head when list is empty
    }
    *tail = new;//Update tail to the new node
    return SUCCESS;
}
//function to delete all nodes from the linked list
int delete_list(node **head, node **tail)
{
    while (*head!=NULL) //continue until all nodes are deleted
    {
        node *temp = *head;//Store the current head temporarily
        *head = (*head)->next;//move head to the node
        free(temp);//Free memory of the current node
    }
    *tail = NULL;//Set tail to NULL after deleting the list
    return SUCCESS;
}
//Function to display all elements of the linked lists
void print_list(node *head)
{
    while (head!=NULL) //Traverse the linked list
    {
        printf("%d", head->data);//print the data stored in the current node
        head = head->next;//move to the next node
    }
    printf("\n");
}
//Function to compare two linked lists representing large numbers
int compare_list(node *head1, node *head2)
{
    int len1 = 0;//Initialize length of first list
    int len2 = 0;//Initialize length of second list
    node *temp1 = head1;//Create temporary pointer for first list
    node *temp2 = head2;//Create temporary pointer for second list
    while(temp1 !=NULL)//Count nodes in the first list
    {
        len1++;//Increment first list length
        temp1 = temp1->next;//move to the next node
    }
    while(temp2 !=NULL)//Count nodes in the second list
    {
        len2++;//Increment second list length
        temp2 = temp2->next;//move to the next node
    }
    if(len1 > len2)//Check whether first number has more digits
    {
        return OPERAND1;//First number is greater
    }
    if(len1 < len2)//Check whether second number has more digits
    {
        return OPERAND2;//Second number is greater
    }
    temp1 = head1;//Reset pointer to the first list
    temp2 = head2;//Reset pointer to the second list
    while(temp1 !=NULL && temp2 !=NULL)//Compare digits of both lists
    {
        if(temp1->data>temp2->data)//Check whether first digit is greater
        {
            return OPERAND1;//first number is greater
        }
        if(temp1->data < temp2->data)//Check whether second digit is greater
        {
            return OPERAND2;//second number is greater
        }
        temp1 = temp1->next;//Move to the next list digit of first number
        temp2=temp2->next;//move to the next digit of second number
    }
    return SAME;
    
}
//Function to find the number of nodes in a linked list
int list_len(node *head)
{
    int len = 0;//INitialize list length to zero
    while (head) //Traverse the linked list
    {
        len++;//Increment the length
        head = head->next;//move to the next node
    }
    return len;
}
//Function to remove leading zeros from a linked list
void remove_pre_zeros(node **head)
{
    //Remove zeros until the last digit remains
    while (*head !=NULL &&(*head)->data == 0 && (*head)->next!=NULL) 
    {
        node *temp = *head;//Store the current head temporarily
        *head = (*head)->next;//Move head to the next node
        (*head)->prev = NULL;//Remove previous link of the new head
        free(temp);//Free memory of the removed node
    }
}
