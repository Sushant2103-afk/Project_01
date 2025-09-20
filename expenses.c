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
