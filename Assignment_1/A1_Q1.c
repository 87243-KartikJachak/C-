#include<stdio.h>
#include<stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

void initDate(struct Date *ptrDate)
{
    ptrDate-> day = 25;
    ptrDate-> month = 10;
    ptrDate-> year = 1995;
}

void acceptDateFromConsole(struct Date *ptrDate)
{
    printf("Enter your Date: ");
    scanf("%d%d%d", &ptrDate->day, &ptrDate->month, &ptrDate->year);
}

void printDateOnConsole(struct Date *ptrDate)
{
    printf("Date: %d/ %d/ %d \n", ptrDate->day, ptrDate->month, ptrDate->year);
}

int main() 
{
    struct Date d1;
   // initDate(&d1);
    int choice;
    printf("---------MENU--------------\n");
    printf("\n1. Accept and Display Date");
    printf("\n2. Initial Date ");
    printf("\n3. Exit ");
    printf("\n----------------------------\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);    
        switch (choice)
        {
            case 1: if (choice == 1)
                    {
                        acceptDateFromConsole(&d1);
                        printDateOnConsole(&d1);

                    }      
                break;
            case 2: if (choice == 2)
                    {
                        initDate(&d1);
                        printDateOnConsole(&d1);
                    }      
                break;        
            case 3: if (choice == 2)
                    {
                        exit(0);
                    }      
                break;        

            default:
                printf("PLEASE TRY AGAIN!!");
                break;
        }
    } while(choice!=3);
}

