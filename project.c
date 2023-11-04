#include <stdio.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>
struct node
{
	char name[20];
	long int contact;
	struct node *link;
}*first,*new_node,*save;
void add()
{
	new_node=(struct node*)malloc(sizeof(struct node));
	if(new_node==NULL)
	{
		printf("\nNot Enough Memory...");
		return;
	}
	printf("Enter the Name:");
	scanf("%s",new_node->name);
	printf("Enter the Contact Number:");
	scanf("%ld",&new_node->contact);
	new_node->link=NULL;
	if(first==NULL)
	{
		first=new_node;
		return;
	}
	save=first;
	while(save->link!=NULL)
	{
		save=save->link;
	}
	save->link=new_node;
	return;
}
void search()
{
}
void view()
{
	system("cls");
	if(first == NULL) 
	{
        printf("\nEmpty List");
        return;
    }
    save = first;
    printf("Name\t\tContact");
    while(save != NULL) 
	{
        printf("\n%s\t\t",save->name);
        printf("%ld",save->contact);
        //printf("\n Link: %d",save->link);
        //printf("\n Add of node: %d",save);
        save = save->link;
    }
    getch();
}
void update()
{
}
void delete()
{
}
void main()
{
	int choice;
	system("color F0");
	system("cls");
	printf("\n\n\n\n\n\n\t\t*****Welcome to our Contact Directiory*****\n");
	printf("\n1. Add New Contact\n2. Search Contact\n3. View All Contact List\n4. Update Contact List\n5. Delete Contact List\n6. Exit\n");
	printf("Enter Your Choice ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			add();
			main();
		break;
		case 2:
			search();
			main();
		break;
		case 3:
			view();
			main();
		break;
		case 4:
			update();
			main();
		break;
		case 5:
			delete();
			main();
		break;
		case 6:
			printf("Existing......");
			exit(0);
		break;
		default:
			//printf("Enter the Valid Choice....\n");
			main();
		break;
	}
	getch();
}
