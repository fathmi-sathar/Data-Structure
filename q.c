#include<stdio.h>
#define size 10
int Q[size],F=-1,R=-1;
int isfull()
{
  if(F==(R+1)%size)
  return 1;
  else
  return 0;
  }
  int isempty()
  {
    if(F==-1&&R==-1)
    {
     return 1;
     }
     else
     {
      return 0;
      }
    }
void insertrear(int ele)
{
  if(isfull())
  {
    printf("Full");
    }
  else
  {
    if(F==-1)
    { 
     F=0;
     }
    R=(R+1)%size;
   Q[R]=ele;
   }
  }
  void insertfront(int ele)
  {
    if(isfull())
    {
      printf("FULL");
      }
      else
    {
      if(F==-1)
      {
        F=R=0;
        }
        else
        {
          if(F==0)
          F=size-1;
          else
          F=F-1;
          }
        Q[F]=ele;
        }
       }
  int deleterear()
  {
    if(isempty())
    {
      printf("Empty");
      }
     else
     {
       int ele=Q[R];
       if(F==R)
       {
         F=R=-1;
         }
       else
       {
         if(R==0)
         R=size-1;
         else
         R=R-1;
         }
        return(ele);
       }
       }   
 int deletefront()
 {
   if(isempty())
   {
     printf("Empty");
     }
   else
   {
     int ele=Q[F];
     if(F==R)
     {
       F=R=-1;
       }
     else
     {
       F=(F+1)%size;
       }
    return(ele);
    }
    }
   void display()
   {
     if(isempty())
     {
       printf("empty");
       }
       else
       {
         for(int i=F;i!=R;i=(i+1)%size)
         {
           printf("\n%d",Q[i]);
          }
         printf("\n%d",Q[R]);
       }
       }
    void main()
    {
      int ch,ele;
      do
      {
        printf("\nChose\n\n1.insertrear\n2.deletefront\n3.insertfront\n4.deleterear\n5.display\n6.full\n7.empty\n8.exit");
        scanf("%d",&ch);
        switch(ch)
        {
          case 1: printf("Enter the elem to be inserted");
                  scanf("%d",&ele);
                  insertrear(ele);
                  break;
            case 2: ele=deletefront();
                    printf("The deleted element is %d",ele);
                    break;
               case 3:   printf("Enter the elem to be inserted");
		          scanf("%d",&ele);
		          insertfront(ele);
		          break;
		 case 4: ele=deleterear();
		            printf("The deleted element is %d",ele);
		            break;
                  case 5:printf("THe elemenst are");
                       display();
                       break;
                case 6: if(isfull())
                        printf("FULL");
                        else
                        printf("space available");
                        break;
                 case 7:if(isempty())
                        printf("EMPTY");
                        else
                        printf("elements present");
                        break;
                  case 8:break;
                  default:printf("invlalid");
                  }
                  }while(ch!=8);
               }
               
                        
                    
