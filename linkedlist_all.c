#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}nd;
void insertFirst(nd **str)
{
    nd *temp;
    temp=(nd*)malloc(sizeof(nd));
    printf("Enter the data : ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    
    if(*str==NULL)
     *str=temp;
    else
    {
        temp->link=*str;
        *str=temp;
    }
}
void insertLast(nd **str,int item)
{
    nd *temp, *ptr;
    temp=(nd*)malloc(sizeof(nd));
    temp->data=item;
    temp->link=NULL;
    
    if(*str==NULL)
     *str=temp;
    else
    {
        
        ptr=*str;
        while(ptr->link!=NULL)       
          ptr=ptr->link;
          
        ptr->link=temp;
    }
}
void insertpos(nd **str)
{
	nd *temp,*ptr;
	int i,k,pos;
	temp=(nd*)malloc(sizeof(nd));
	temp->link=NULL;
	printf("\n Enter position you want to enter new element : ");
	scanf("%d",&pos);
	if(*str==NULL && pos==1)
	{
		printf(" Enter data : ");
		scanf("%d",&temp->data);
		*str=temp;
	}
	else if(*str==NULL && pos!=1)
	printf("\n List is empty. Cannot enter element at specified location.");
	else
	{
		ptr=*str;
		for(i=1;i<pos-1;i++)
		{
			ptr=ptr->link;
			if(ptr==NULL)
			{
				printf("\n Number of nodes in the list less than the specified position. Cannot enter!");
				break;
			}
		}
		printf("Enter data : ");
		scanf("%d",&temp->data);
		temp->link=ptr->link;
		ptr->link=temp;
	}
}
void searchInsert(nd **str)
{
    int num,f=0;
    nd *ptr,*temp;
    if(*str==NULL)
     printf("\n List is Empty. ");
    else
    {
        printf("\n Enter the search number : ");
        scanf("%d",&num);
        ptr=*str;
        while(ptr!=NULL)
        {
            if(ptr->data==num)
            {
                f=1;
                break;
            }
            ptr=ptr->link;
        }
        if(f==0)
         printf("\n Number not present. ");
        else
        {
            temp=(nd*)malloc(sizeof(nd));
            printf("Enter the new data : ");
            scanf("%d",&temp->data);
            temp->link=NULL;
            
            temp->link=ptr->link;
            ptr->link=temp;
        }
    }
}
void deleteFirst(nd **str)
{
	nd *temp;
    if(*str==NULL)
     printf("\n U N D E R F L O W ");
    else
    {
    	temp=*str;
        printf("\n Deleted : %d",temp->data);
        temp=temp->link;
        *str=temp;
    }
}
void deleteLast(nd **str)
{
    nd *ptr,*temp=*str;
    if(*str==NULL)
     printf("\n U N D E R F L O W ");
    else if(temp->link==NULL)
    {
        printf("\n Deleted : %d",temp->data);
        *str=NULL;
        
    }
    else
    {
        ptr=*str;
        while(ptr->link->link!=NULL)
         ptr=ptr->link;
        
        printf("\n Deleted : %d",ptr->link->data);
        ptr->link=NULL;
    }
}
void delpos(nd **str)
{
	int pos,i;
	nd *ptr,*temp=*str;
	if(*str==NULL)
	printf("\n U N D E R F L O W ");
	else if(temp->link==NULL)
	{
		printf("\n Only one element present.");
		printf("\n Deleted : %d",temp->data);
		*str=NULL;
	}
	else
	{
		printf("\n Enter position to delete element.");
		scanf("%d",&pos);
		ptr=*str;
		for(i=1;i<pos-1;i++)
		{
			ptr=ptr->link;
			if(ptr==NULL)
			{
				printf("\n Number of nodes in the list less than the specified position. Cannot enter!");
				break;
			}
		}
		printf("\n Deleted : %d.",ptr->link->data);
		ptr->link=ptr->link->link;
	}
}
void searchDelete(nd **str)
{
    int num,f=0;
    nd *ptr,*temp=*str;
    if(*str==NULL)
     printf("\n List is Empty");
    else
    {
        printf("\n Enter the search number : ");
        scanf("%d",&num);
        
        if(temp->data==num)
         {
         	temp=temp->link;
         	*str=temp;
		 }
         
        else
        {
            ptr=*str;
            while(ptr!=NULL)
            {
                if(ptr->link->data==num)
                {
                    f=1;
                    break;
                }
                ptr=ptr->link;
            }
            if(f==0)
             printf("\n Number not present. ");
            else
            ptr->link=ptr->link->link;
        }
    }
}
int count(nd **str)
{
	nd *ptr;
	int c=0;
	if(*str==NULL)
	c=0;
	else
	{
		ptr=*str;
		while(ptr!=NULL)
		{
			c++;
			ptr=ptr->link;
		}
		return c;
	}
}
void search(nd **str)
{
    int num,f=0,c=0;
    nd *ptr;
    if(*str==NULL)
     printf("\n List is Empty. ");
    else
    {
        printf("\n Enter the search number : ");
        scanf("%d",&num);
        ptr=*str;
        while(ptr!=NULL)
        {
            if(ptr->data==num)
            {
                f=1;
                break;
            }
            c++;
            ptr=ptr->link;
        }
        if(f==0)
		printf("\n Number not present. ");
		else
		printf("\n Number %d present at = %d.",num,c);
	}
}
void reverse(nd **str)
{
	nd *ptr,*prev,*next;
	prev=NULL;
	ptr=*str;
	next=NULL;
	if(*str==NULL)
	printf("\n List is Empty.");
	else
	{
		while(ptr!=NULL)
		{
			next=ptr->link;
			ptr->link=prev;
			prev=ptr;
			ptr=next;
		}
		*str=prev;
	}	
}
void divi(nd **str,nd **n1,nd **n2)
{
	nd *ptr,*ptr1,*ptr2,*temp=*str,*t1;
	int c,t=0;
	c=count(str);
	if(c%2!=0)
	printf("\n Odd number of elements. Thus uneven division into 2 different lists.");
	if(*str==NULL)
		printf("\n List is Empty.");
	else if(temp->link==NULL)
		printf("\n Minimum 2 elements required to divide, thus both sublists empty.\n");
	else
	{
		ptr=*str;
		ptr2=*n2;
		while(ptr!=NULL)
		{
			if(t<c/2)
			insertLast(n1,ptr->data);
			else
			insertLast(n2,ptr->data);
			t++;
			ptr=ptr->link;
		}
	}
}
void ascendsort(nd **str)
{
	int t;
	nd *ptr1,*ptr2;
	ptr1=*str;
	while(ptr1->link!=NULL)
	{
		ptr2=ptr1->link;
		while(ptr2!=NULL)
		{
			if(ptr1->data>ptr2->data)
			{
				t=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=t;
			}
			ptr2=ptr2->link;
		}
		ptr1=ptr1->link;
	}
}
void descendsort(nd **str)
{
	int t;
	nd *ptr1,*ptr2;
	ptr1=*str;
	while(ptr1->link!=NULL)
	{
		ptr2=ptr1->link;
		while(ptr2!=NULL)
		{
			if(ptr1->data<ptr2->data)
			{
				t=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=t;
			}
			ptr2=ptr2->link;
		}
		ptr1=ptr1->link;
	}
}
void merge(nd **n1,nd **n2,nd **str)
{
	int t,i;
	nd *ptr1,*ptr2,*ptr;
	ptr1=*n1;
	ptr2=*n2;
	for(i=0;i<count(n1)+count(n2);i++)
	{
		if(i<count(n1))
		{
			insertLast(str,ptr1->data);
			ptr1=ptr1->link;
		}
		else
		{
				insertLast(str,ptr2->data);
				ptr2=ptr2->link;
		}
	}
}
void display(nd *str)
{
    nd *ptr;
    if(str==NULL)
     printf("\n List is empty.");
    else
     {
         ptr=str;
         while(ptr!=NULL)
         {
             printf("\n %d",ptr->data);
             ptr=ptr->link;
         }
     }
}
int main()
{
	int ch,c,item;
	nd *start,*new1,*new2,*strn;
    start=NULL;
    new1=NULL;
    new2=NULL;
    strn=NULL;
    while(1)
    {
        printf("\n \n 1 for Insert First. ");
        printf("\n 2 for Insert Last. ");
        printf("\n 3 for Insert at any place based on position. ");
        printf("\n 4 for Insert at any place based on data. ");
        printf("\n 5 for Delete First. ");
        printf("\n 6 for Delete Last. ");
        printf("\n 7 for Delete at any place based on position. ");
        printf("\n 8 for Delete at any place based on data. ");
        printf("\n 9 to Count number of nodes. ");
        printf("\n 10 for Searching a particular element in the list. ");
        printf("\n 11 to Reverse the List. ");
        printf("\n 12 to divide main list into two sub lists. ");
        printf("\n 13 to Sorting in Ascending order. ");
        printf("\n 14 to Sorting in Descending order. ");
        printf("\n 15 to Merge two sublists. ");
        printf("\n 16 for Display ");
        printf("\n 17 for Exit ");
        printf("\n\n Enter the choice : ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
                insertFirst(&start);
                display(start);
                break;
            
            case 2:
            	printf("Enter the data : ");
            	scanf("%d",&item);
                insertLast(&start,item);
                display(start);
                break;
            
            case 3:
                insertpos(&start);
                display(start);
                break;
                
            case 4:
				 searchInsert(&start);
				 display(start);
				 break;
                
            case 5:
                deleteFirst(&start);
                display(start);
                break;
            
            case 6:
                deleteLast(&start);
                display(start);
                break;
            
            case 7:
                delpos(&start);
                display(start);
                break;
                
            case 8:
            	searchDelete(&start);
            	display(start);
            	break;
                
            case 9:
            	c=count(&start);
            	printf("Number of elements in the list : %d.",c);
            	break;
            
            case 10:
            	search(&start);
            	break;
            	
            case 11:
                reverse(&start);
                display(start);
                break;
                
            case 12:
            	divi(&start,&new1,&new2);
            	printf("\n 1st new sublist: \n");
            	display(new1);
            	printf("\n 2nd new sublist: \n");
            	display(new2);
            	break;
            	
            case 13:
            	printf("\n Initial start list in ascending order : \n");
            	ascendsort(&start);
            	display(start);
            	printf("\n 1st sublist in ascending order : \n");
            	ascendsort(&new1);
            	display(new1);
            	printf("\n 2nd sublist in ascending order : \n");
            	ascendsort(&new2);
            	display(new2);
            	break;
            	
            case 14:
            	printf("\n Initial start list in descending order : \n");
            	descendsort(&start);
            	display(start);
            	printf("\n 1st sublist in descending order : \n");
            	descendsort(&new1);
            	display(new1);
            	printf("\n 2nd sublist in descending order : \n");
            	descendsort(&new2);
            	display(new2);
            	break;
            
            case 15:
            	merge(&new1,&new2,&strn);
            	printf("\n New list after merging 2 sublists : \n");
            	display(strn);
            	break;
            	
            case 16:
            	printf("\n Final start list : \n");
            	display(start);
            	break;
            
            case 17:
                exit(1);
                
            default:
                printf("\n Wrong choice. ");                
        }
    }
}
