// final code doubly linked list

class Program417
{
    public static void main(String Arg[])
    {
         int iRet=0;
        DoublyLL obj=new DoublyLL();

        obj.InsertFirst(71);
        obj.InsertFirst(61);
        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of elements are: "+iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);
        obj.InsertLast(151);
        obj.InsertLast(201);
        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of elements are: "+iRet);

        obj.InsertAtPos(91,3);
        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of elements are: "+iRet);

        obj.DeleteFirst();
        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of elements are: "+iRet);

        obj.DeleteLast();
        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of elements are: "+iRet);

        obj.DeleteAtPos(91,3);
        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of elements are: "+iRet);



    }
}

class node     
{
   public int data;
   public node next;
   public node prev;    //#

   public node(int no)
   {
     data=no;
     next=null;
     prev=null; //#
   } 
}

class DoublyLL
{
     private node first;
     private int Count;

     public DoublyLL()
     {
        first=null;
        Count=0;
     }

     public void InsertFirst(int no)
     {
        node newn=new node(no);
        if(first==null) //LL is empty
        {
             first=newn;
        }
        else
        {
           newn.next=first;
           first.prev=newn;  //#
           first=newn;
        }
        Count++;
      }

      public void InsertLast(int no)
      {
         node newn=new node(no);
        if(first==null) //LL is empty
        {
             first=newn;
        }
        else
        {
           node temp=first;
           while((temp.next)!=null)
           {
              temp=temp.next;
           }
           temp.next=newn;
           newn.prev=temp;   //#
        }
        Count++;

      }
   
       public void DeleteFirst()
       {
            if(first==null)
            {
                 return;
            }
            else if( first.next==null)
            {
                first=null;
            }
            else
            {
               first=first.next;
               first.prev=null;   //#
            }
           Count--;
       }
       public void DeleteLast()
       {
         if(first==null)
            {
                 return;
            }
            else if( first.next==null)
            {
                first=null;
            }
            else
            {
               node temp=first;
               while((temp.next.next)!=null)
               {
                  temp=temp.next;
               }
               temp.next=null;
            }
           Count--;
       }

       public void Display()
       {
         node temp=first;
         
         System.out.println("Elements of the linked list are: ");

         System.out.print("null <=>");

         while(temp!=null)
         {
            System.out.print("| "+temp.data+" |<=>");
            temp=temp.next;
         }
         System.out.println("null");
       }

       public int Count()
       {
          return Count;
       }

        public void InsertAtPos(int no,int ipos)
       {
         if((ipos<1) ||(ipos>Count+1))
         {
            return;
         }
         if(ipos==1)
         {
            InsertFirst(no);
         }
         else if(ipos==Count+1)
         {
            InsertLast(no);
         }
         else
         {
            node newn=new node(no);
            int i=0;
            node temp=first;

            for(i=1;i<ipos-1;i++)
            {
               temp=temp.next;
            }
            
            newn.next=temp.next;
            temp.next.prev=newn; //#

            temp.next=newn;
            newn.prev=temp;   //#

            Count++;
         }

       }
       public void DeleteAtPos(int no, int ipos)
       {
         if((ipos<1) ||(ipos>(Count)))
         {
            return;
         }
         if(ipos==1)
         {
            DeleteFirst();
         }
         else if(ipos==Count)
         {
            DeleteLast();
         }
         else
         {
            node newn=new node(no);
            int i=0;
            node temp=first;

            for(i=1;i<ipos-1;i++)
            {
               temp=temp.next;
            }
            temp.next=temp.next.next;
            temp.next.prev=temp;        //#
            Count--;
         }
       }
}

