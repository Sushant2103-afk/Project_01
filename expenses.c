#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Expense{
    char date[11];
    char category[64];
    float amount;
    char note[256];

}Expense;

#define DATA_FILE "expenses.txt"

void addExpenses();
void viewExpenses();

int main(){
    int choice;
    while(1)
    {
        printf("1.Add Expenses\n 2.View Expenses\n 3.Exit\n Enter choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:addExpenses();
                    break;
            case 2:viewExpenses();
                    break;
            case 3:exit(0);
                    break;
            default: printf("Invalid choice!\n");
            

        }
        
        
        
    }
    return 0;
}

void addExpenses()
{
    Expense e;
    printf("Enter date (DD-MM-YYYY):");
    scanf("%10s",e.date);
    printf("Enter Category:");
    scanf("%s",e.category);
    printf("Enter amount:");
    scanf("%f",&e.amount);
   
    getchar();
    printf("Enter note:");
    fgets(e.note,sizeof(e.note),stdin);
    e.note[strcspn(e.note,"\n")]=0;
    
    FILE *ptr=fopen(DATA_FILE,"a");

    if (ptr==NULL)
    {
        printf("Error opening file:");
        return;

        
    }
    fprintf(ptr,"%s|%s|%.2f|%s\n",e.date,e.category,e.amount,e.note);
    fclose(ptr);
    printf("Expense added successfully! \n");
    
}

void viewExpenses()
{
    FILE *ptr=fopen(DATA_FILE,"r");
    if(!ptr)
    {
        printf("No expenses found.\n");
        return;
    }
    char line[200];

    printf("Date    | Category    |  Amount     | Note\n");
    printf("--------------------------------------------- \n");
    while(fgets(line,sizeof(line),ptr))
    {
        printf("%s",line);
    }
    fclose(ptr);
    
}