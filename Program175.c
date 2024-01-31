// Singly Linear LL
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int  data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head,int No)
{
  PNODE newn=NULL;
  // PNODE newn=(PNODE )malloc (sizeof(NODE));  --- we can write in these way
  newn=(PNODE)malloc(sizeof(NODE));
  newn->data=No;
  newn->next=NULL;
  if(*Head==NULL)
  {
    *Head=newn;
  }
  else
  {
    newn->next=*Head;
    *Head=newn;
  }
}
void InsertLast(PPNODE Head,int No)
{
    //Temporary pointer for LL traversal
    PNODE Temp=*Head;
    PNODE newn=NULL;
  // PNODE newn=(PNODE )malloc (sizeof(NODE));  --- we can write in these way
  newn=(PNODE)malloc(sizeof(NODE));
  newn->data=No;
  newn->next=NULL;
  if(*Head==NULL)
  {
    *Head=newn;
  }
  else
  {
    //Travel the address of new node at the end of last node
    while(Temp->next!=NULL)
    {
        Temp=Temp->next;
    }
    //add the address of new node at end of last node
    Temp->next=newn;
  }
}
void Display(PNODE Head)
{
   while(Head!=NULL)
   {
        printf(" |%d |-> ",Head->data);
        Head=Head->next;
   }
   printf("Null \n");
}
int Count(PNODE Head)
{
    int iCnt=0;
    while(Head!=NULL)
   {
        iCnt++;
        Head=Head->next;
   }
   return iCnt;
}
void DeleteFirst(PPNODE Head)
{
  PNODE Temp=*Head;
   if(*Head==NULL)
   {
      return ;
   }
   else if((*Head)->next==NULL)
   {
      free(*Head);
      *Head=NULL;
   }
   else
   {
      *Head=(*Head)->next;
      free(Temp);
   }

}
void DeleteLast(PPNODE Head)
{
   PNODE Temp=*Head;
      if(*Head==NULL)
   {
      return ;
   }
   else if((*Head)->next==NULL)
   {
      free(*Head);
      *Head=NULL;
   }
   else
   {
     while(Temp->next->next!=NULL)
     {
      Temp=Temp->next;
     } 
     free(Temp->next);
     Temp->next=NULL;
   }
}
void InsertAtPos(PPNODE Head,int No,int iPos)
{
   int Size=Count(*Head);
   PNODE newn=NULL;
   int i=0;
   PNODE Temp=*Head;

   // case 1 :Invalid position
   if((iPos <1) || (iPos >Size+1))
   {
      printf("Invalid Position\n");
      return;
   }
   // case 2: First Position
   if(iPos==1)
   {
      InsertFirst(Head,No);
   }
   // case 3: Last Position
   else if(iPos==Size+1)
   {
      InsertLast(Head,No);
   }
   // case 4: Position is in between first and last
   else
   {
       newn=(PNODE)malloc(sizeof(NODE));
      newn->data=No;
      newn->next=NULL;

      for(i=1;i<iPos-1;i++)
      {
         Temp=Temp->next;
      }
      newn->next=Temp->next;
      Temp->next=newn;
   }
}
void DeleteAtPos(PPNODE Head,int iPos)
{
   int Size=Count(*Head);
   PNODE newn=NULL;
   int i=0;
   PNODE Temp=*Head;
   PNODE targatednode=NULL;

   // case 1 :Invalid position
   if((iPos <1) || (iPos >Size))
   {
      printf("Invalid Position\n");
      return;
   }
   // case 2: First Position
   if(iPos==1)
   {
       DeleteFirst(Head);
   }
   // case 3: Last Position
   else if(iPos==Size)
   {
      DeleteLast(Head);
   }
   // case 4: Position is in between first and last
   else
   {
      for(i=1;i<iPos-1;i++)
      {
         Temp=Temp->next;
      }
      targatednode=Temp->next;
      Temp->next=Temp->next->next;
      free(targatednode);
   }
}
int main()
{
     PNODE First=NULL;
    int iRet=0;

    InsertFirst(&First,111);
    InsertFirst(&First,101);
    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);
    InsertLast(&First,121);

    InsertAtPos(&First,105,5);

     Display(First);
     iRet=Count(First);
     printf("number of nodes present in linked list are  %d :\n",iRet);
   
     DeleteAtPos(&First,5);
     Display(First);
     iRet=Count(First);
     printf("number of nodes present in linked list are  %d :\n",iRet);
     
    return 0;

}