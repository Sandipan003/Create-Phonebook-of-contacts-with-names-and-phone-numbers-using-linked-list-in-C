#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct record
{
unsigned long long phno;
char name[40];
struct record *next;
}NODE;
NODE *start=NULL;
unsigned long long pno;
char nm[40];
void append()
{
NODE *temp, *curr;
temp =(NODE*)malloc(sizeof(NODE));
if (temp==NULL)
{
printf("\n\nCan\'t Allocate Node!!");
system("pause");
return;
}
printf("\nEnter Phone Number:");
scanf("%llu",&pno); fflush(stdin);
printf("\nEnter Name:");
scanf("%[^\n]s",nm);
temp->phno = pno;
strcpy(temp->name,nm);
temp->next = NULL;
if(start==NULL)
  {
  printf("\n***FIRST NODE OF THE LIST CREATED***\n");
  start = temp;
  }
  else
  {
  curr = start;
  while(curr->next !=NULL)
  {
  curr = curr-> next;}
  curr->next = temp;
  printf("\n****Node Created***\n");
  }
  }
  void display()
  {
  NODE* curr = start;
  printf("\nCURRENT LIST\n\n\n");
  if(curr == NULL)
  {printf("\n**EMPTY LIST...Press any key to return**");
  system("pause");
  return;
  }
  while(curr !=NULL)
  {
  printf("%llu->",  curr->phno);
  printf("%s->",  curr->name);
  curr = curr->next;
  }
printf("END OF LIST");
  }
void del_begin()
{
if (start==NULL)	{
	printf("\nList Empty....Press any key to return..");
	return ;
	 }
	 
NODE *temp = start;
start = start->next;
free(temp);
}
void del_value(unsigned long long data)
{
	if (start==NULL)	{
	printf("\nList Empty....Press any key to return..");
	return ;
	 }
NODE *curr, *temp;
if( start->phno == data )
{
del_begin();
return;
}
curr = start;
while( (curr->next !=NULL) && (curr->next->phno !=data) )
{
curr = curr->next;
}
if( curr->next!= NULL )
{
temp = curr->next;
curr->next = temp->next;
free(temp);
}
else
printf("\nValue not found is list!");
}
void search(unsigned long long data)
{
NODE *curr = start;
unsigned long long check =0, count =0;
if (start==NULL)	{
	printf("\nList Empty....Press any key to return..");
	return ;
	 }
while( curr != NULL )
{
count++;
if(data==curr->phno)
{
printf("\nData %llu found in position %llu", data,count);
check++;
}
curr = curr->next;
}
if( check == 0 )
printf("\nValue not found");
}
void end()
{
while(start!= NULL)
del_begin();
display();
printf("Exiting...");

}
int main()
{
fflush(stdin);
unsigned long long prompt,pno,num,pos;
char nm[40];
do
{

printf("\n *********************");
printf("\n ****************");
printf("\n * <1> To ADD a new node to list                              *");
printf("\n * <7> TO DELETE a GIVEN VALUE in the list                    *");
printf("\n * <10> TO SEARCH for a value in  the list                    *");
printf("\n * <11> TO DISPLAY the list                                   *");
printf("\n * <0> TO END operation                                       *");
printf("\n ********************");
printf("\n ********************\n");
printf("\n ENTER choice:  ");
fflush(stdin);
scanf("%llu",&prompt);
switch(prompt)
{
case 1:printf("%d",sizeof(unsigned long long));
	 append();
	 break;
case 7 :printf("\nEnter Phone Number to delete: ");
	fflush(stdin);
	scanf("%llu" , &pno);
	del_value(pno);break;

case 10:printf("\nEnter the phone number to search: ");
	 fflush(stdin);
	 scanf("%llu" , &pno);
	 search(pno);break;
case 11 :display();break;
case 0  :end();break;
default: printf("\nEnter a valid choice: ");
}
printf("\n");
system("pause");
}while(prompt!=0);
return 0;
}