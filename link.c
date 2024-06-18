#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int info;
  struct Node*next;
};
typedef struct Node node;
node*newnode()
{
  node*p=(node*)malloc(sizeof(node));
  return p;
  }
node*head=NULL;
node*curr=NULL;
node*prev=NULL;
void insertfirst(int ele)
{
  node*p=newnode();
  p->info=ele;
  if(head==NULL)
  {
    head=p;
    p->next=NULL;
   }
   else
   {
     p->next=head;
     head=p;
    }
    }
void insertlast(int ele)
{
  node*p=newnode();
  p->info=ele;
  p->next=NULL;
  if(head==NULL)
  {
    head=p;
    }
    else
    {
    node*curr=head;
    while(curr->next!=NULL)
    {
      curr=curr->next;
      }
    curr->next=p;
    }
    }
void insertafter(int val,int ele)
{
  node*curr=head;
  while(curr!=NULL&&curr->info!=val)
  {
    curr=curr->next;
    }
  if(curr==NULL)
  printf("No such node");
  else
  {
    node*p=newnode();
    p->info=ele;
    p->next=curr->next;
    curr->next=p;
    }
    }
void insertbefore(int val,int ele)
{
  node*curr=head;
  while(curr!=NULL&&curr->info!=val)
  {
    prev=curr;
    curr=curr->next;
    }
    if(curr==NULL)
    {
      printf("No suh node");
      }
      else
      {
        node*p=newnode();
        p->info=ele;
        p->next=curr;
        if(head==curr)
        {
          head=p;
          }
          else
          {
            prev->next=p;
           }
       }
       }
 void delete(int ele)
 {
   node*curr=head;
   while(curr!=NULL&&curr->info!=ele)
   {
     prev=curr;
     curr=curr->next;
     }
   if(curr==NULL)
   { 
    printf("No mode");
    }
    else
    {
      if(head==curr)
        head=curr->next;
        else
          prev->next=curr->next;
         free(curr);
         }
    }
 int count()
 {
   curr=head;
   int count=0;
   while(curr!=NULL)
    {
      curr=curr->next;
      count++;
      }
      return(count);
   }
  void display()
  {
    curr=head;
    while(curr!=NULL)
    {
      printf("%d",curr->info);
      curr=curr->next;
      }
      }
 void main()
 {
   int ch,ele,val;
      do
      {
        printf("\nChose\n\n1.insertfirst\n2.insertlast\n3.insertafter\n4.insertbefore\n5.delete\n6.count\n7.display\n8.exit");
        scanf("%d",&ch);
        switch(ch)
        {
          case 1: printf("Enter the elem to be inserted");
                  scanf("%d",&ele);
                  insertfirst(ele);
                  break;
            case 2:printf("Enter the elem to be inserted");
                  scanf("%d",&ele);
                  insertlast(ele);
                  break;
              case 3:printf("Enter the element after which inserted");
                     scanf("%d",&val);
                     printf("Enter the new element");
                     scanf("%d",&ele);
                     insertafter(val,ele);
                     break;
               case 4:printf("Enter the element before which inserted");
                     scanf("%d",&val);
                     printf("Enter the new element");
                     scanf("%d",&ele);
                     insertbefore(val,ele);
                     break;
                 case 5:printf("The element to be deleted");
                        scanf("%d",&ele);
                        delete(ele);
                        break;
                   case 6:int c=count();
                          printf("THe no of elelents is%d",c);
                          break;
                      case 7:printf("THe elemenst are");
                       display();
                       break;
                  case 8:break;
                  default:printf("invlalid");
                  }
                  }while(ch!=8);
               }
               
                        
  
    
  
