#include "std.h"
#include "SDB.h"
#include <stdio.h>
#include <stdlib.h>


void SDB_APP ();
void SDB_action (uint8 choice);

int main ()
{

        SDB_APP();

    return 0;
}

void SDB_APP ()
{
	 uint8 choice;
 while (1)
 {
    
     printf("Please Choose\n");
     printf("0 To exit the Program\n");
     printf("1 For Add Entery\n");
      printf("2 For How Many Student In Database\n");
       printf("3 For get Student\n");
        printf("4 For getting a list for all Students \n");
         printf("5 To check if ID exist\n");
          printf("6 Delete Student Data\n");
           printf("7 To check if Database is full\n");
           scanf ("%d",&choice);
 SDB_action (choice);


 }
}

void SDB_action (uint8 choice)
{
    if(choice==1)
    {
        SDB_AddEntry ();
    }
       if(choice==2)
       {
            SDB_GetUsedSize ();
       }
           if(choice==3)
           {
              SDB_ReadEntry ();
           }
        if(choice==4)
        {
             SDB_GetList ();
        }
         if(choice==5)
         {
             SDB_IsIdExist ();
         }
           if(choice==6)
           {
               SDB_DeleteEntry ();
           }
          if(choice==7)
          {
              SDB_isfull ();
          }

          if(choice==0)
          {
              exit(0);
          }
		  if(choice>7)
		  {
			  printf("\n\n");
			  printf("Error %u Not From Choices\n",choice);
			  printf("\n\n");
		  }


}