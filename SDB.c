#include "std.h"
#include "SDB.h"
#include <stdio.h>
#include <stdlib.h>


// define max number of students
#define MAX_STUDENTS   10
// define min number of studets
#define MIN_STUDENTS   3
// define counter of student in data base
uint8 STUDENT_COUNT=0;


 // create first node
student *head;


bool SDB_isfull ()
{
	printf("\n\n");
// if student number in data base is equal to Max_STUDENT return full
if (STUDENT_COUNT==MAX_STUDENTS)
{
	printf("Full\n");
printf("\n\n");
	return true;

}
// else return itis not full
else
{
	printf("Not Full\n");
printf("\n\n");
	return false;
}
}

void SDB_GetUsedSize ()
{
		printf("\n\n");
// print number of students using student Counter
printf("There are %d students\n",STUDENT_COUNT);
printf("\n\n");
}
bool SDB_AddEntry ()
{
		printf("\n\n");
    if(STUDENT_COUNT==MAX_STUDENTS)
    {
        //if the data base is full
        printf("Sorry Full\n");
        printf("\n\n");    
    return false;
	
    }
    else
    {
    // if no students start with first node scan all items
    if(STUDENT_COUNT==0)
    {
         // allocate the frist node
head=malloc(sizeof(student));

        // make sure that first node allocated succesfully
        if(head==NULL)
        {
            printf("Memory Allocated Failed");
            return false;
        }
        // if it succesfully read data of the node
        else{
        printf("Please Enter Student ID\n");
        scanf ("%u",&head->Student_ID);
		         printf("Please Enter Student Year\n");
        scanf ("%u",&head->Student_year);
          printf("Please Enter Course 1 ID\n");
        scanf ("%u",&head->Course1_ID);
          printf("Please Enter Course 1 Grade\n");
        scanf ("%u",&head->Course1_grade);
         printf("Please Enter Course 2 ID\n");
        scanf ("%u",&head->Course2_ID);
         printf("Please Enter Course 2 Grade\n");
        scanf ("%u",&head->Course2_grade);
          printf("Please Enter Course 3 ID\n");
        scanf ("%u",&head->Course3_ID);
         printf("Please Enter Course 3 Grade\n");
        scanf ("%u",&head->Course3_grade);
		
    // no node after till now
        head->next=NULL;
        // increas the number of student to one
        STUDENT_COUNT++;
		printf("Added Succesfully\n");
        printf("\n\n");
		return true;
        }

    }
    else
    {
        //allocate another student
    student *newnode,*temp;
    newnode=malloc(sizeof(student));
// make sure that the node sucessfully allocated
    if(newnode==NULL)
    {
printf("Memory Allocated Failed");
return false;
    }
    else
    {
        // read the data of the new student
               printf("Please Enter Student ID\n");
        scanf ("%u",&newnode->Student_ID);
         printf("Please Enter Student Year\n");
        scanf ("%u",&newnode->Student_year);
          printf("Please Enter Course 1 ID\n");
        scanf ("%u",&newnode->Course1_ID);
          printf("Please Enter Course 1 Grade\n");
        scanf ("%u",&newnode->Course1_grade);
         printf("Please Enter Course 2 ID\n");
        scanf ("%u",&newnode->Course2_ID);
         printf("Please Enter Course 2 Grade\n");
        scanf ("%u",&newnode->Course2_grade);
          printf("Please Enter Course 3 ID\n");
        scanf ("%u",&newnode->Course3_ID);
         printf("Please Enter Course 3 Grade\n");
        scanf ("%u",&newnode->Course3_grade);
     //no node till now
        newnode->next=NULL;
        // increase the number of students
        STUDENT_COUNT++;
        //check for the last node
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        //the last node succesfully reached then link the new node
        temp->next =newnode;
		printf("Added Succesfully\n");
printf("\n\n");      
	  return true;
    }

    }
    }
}
void SDB_DeleteEntry ()
{
printf("\n\n");
uint32 id;
 //check if the data base is emptyy
if(STUDENT_COUNT==0)
{
    printf("Database Empty\n");
	printf("\n\n");
}
else
{		
printf("Please Enter The ID Needed to be delete\n");
    scanf("%u",&id);
student *del=head,*previous;
// if the head node is the target
if(del!=NULL && del->Student_ID==id)
{
head=del->next;
free (del);
printf("Succesfully Deleted\n");
// dereasing the number of student
STUDENT_COUNT--;
printf("\n\n");
}
// if the head is not the target
else
{
// looping until find the target node by id
while(del!=NULL && del->Student_ID!=id)
{

previous=del;
del=del->next;
}
// if the node didnt find
if(del==NULL)
{
printf("Sorry Not Found\n");
printf("\n\n");
}
// make the previous node link with next of the deleted node to unlink the target node
previous->next=del->next;
// delete the target node
free(del);
 printf("Succesfully Deleted\n");
 printf("\n\n");
// decreasing the number of student
STUDENT_COUNT--;
}
}
}
bool SDB_ReadEntry ()
{
		printf("\n\n");
	if(STUDENT_COUNT==0)
	{
		printf("Database Empty\n");
		printf("\n\n");
	}
else
{
uint32 id;
printf("Please Enter The Required ID\n ");
scanf("%u",&id);
student *target=head;
//linear search for ID
while(target!=NULL)
{
// if student found	
if(target->Student_ID==id)
{
printf("Founded\n");
printf ("Student ID= %u\n",target->Student_ID);
printf ("Student Year= %u\n",target->Student_year);
printf ("Course 1 ID= %u\n",target->Course1_ID);
printf ("Course 1 Grade= %u\n",target->Course1_grade);
printf ("Course 2 ID= %u\n",target->Course2_ID);
printf ("Course 2 Grade= %u\n",target->Course2_grade);
printf ("Course 3 ID= %u\n",target->Course3_ID);
printf ("Course 3 Grade= %u\n",target->Course3_grade);
printf("\n\n");
return true;	
}
else
{
target=target->next;
}
}
// if the entered id didnt match
if(target==NULL)
{
printf("Sorry Not Found\n");
printf("\n\n");
return false;
}
}
}
void SDB_GetList ()
{
		printf("\n\n");
    // define array to store the IDs
   uint32 arr[MAX_STUDENTS];
   // Make a Pointer To find all nodes
    student *current=head;
    // if no student break the loop
    if(STUDENT_COUNT==0)
    {
        printf("NO Students\n");
		printf("\n\n");
    }
    else
    {
        //store all IDs in Array
        for (int i=0;i<=STUDENT_COUNT;i++)
        {
            arr[i]=current->Student_ID;
            current=current->next;
            //if the last node reached break the loop
            if(current==NULL)
            {
                break;
            }
        }
        printf("All IDs\n");
        // loop the array to print all IDs stored
        for(int j=0;j<STUDENT_COUNT;j++)
        {
            printf("%u\n",arr[j]);
        }
		printf("\n\n");
    }
}
bool SDB_IsIdExist ()
{
		printf("\n\n");
	if(STUDENT_COUNT==0)
	{
		printf("Database Empty\n");
		printf("\n\n");
	}
	else
	{	
uint32 id;
printf("Please Enter The ID\n ");
scanf("%u",&id);

    student *target=head;
//linear search for ID
while(target!=NULL)
{
	// if student found
	if(target->Student_ID==id)
	{
		printf("Founded\n");
		printf("\n\n");
		return true;
		
	}
	else
	{
target=target->next;
}
}
// if the entered id didnt match
if(target==NULL)
{
printf("Sorry Not Found\n");
printf("\n\n");
return false;
}
}
}









