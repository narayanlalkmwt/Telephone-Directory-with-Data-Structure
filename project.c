#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>
#include<stdlib.h>
struct node
{
	char name[20];
	char contact[11];
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
	printf("Enter the Name: ");
	scanf("%s",new_node->name);
	printf("Enter the Contact Number: ");
	scanf("%s",new_node->contact);
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
	char x[20];
    printf("Enter the Name: ");
    scanf("%s", x);
    if (first == NULL)
    {
        printf("\nList is Empty");
        return;
    }
    save = first;
    while (strcmp(save->name, x) != 0 && (save->link != NULL))
    {
        save = save->link;
    }
    if (strcmp(save->name, x) == 0)
    {
        printf("\nData is Found");
    }
    else
    {
        printf("\nData is Not Found");
    }
    getch();
    return;
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
        printf("%s",save->contact);
        save = save->link;
    }
    getch();
}
void update()
{
    char x[20];
    printf("Enter the Old Name: ");
    scanf("%s", x);

    if (first == NULL)
    {
        printf("\nList is Empty");
        return;
    }

    struct node *save = first;
    while (save != NULL && strcmp(save->name, x) != 0)
    {
        save = save->link;
    }
    if (save != NULL)
    {
        printf("Enter the New Name: ");
        scanf("%s", save->name);
        printf("Enter the Contact Number: ");
        scanf("%s", save->contact);
        printf("\nContact Updated Successfully");
    }
    else
    {
        printf("\nData is Not Found");
    }
    getch();
    return;
}
void delete()
{
    char x[20];
    printf("Enter the Name to Delete: ");
    scanf("%s", x);

    if (first == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }

    struct node *current = first;
    struct node *prev = NULL;

    // Search for the node to delete
    while (current != NULL && strcmp(current->name, x) != 0)
    {
        prev = current;
        current = current->link;
    }

    if (current == NULL)
    {
        printf("\nData not found for deletion");
    }
    else
    {
        // If the node to be deleted is the first node
        if (prev == NULL)
        {
            first = current->link;
        }
        else
        {
            prev->link = current->link;
        }

        printf("\nRecord for %s is Successfully Deleted\n", x);
        free(current);
    }
    getch();
    return;
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
