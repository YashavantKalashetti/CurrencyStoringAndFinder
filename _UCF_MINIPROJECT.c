#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COLOR_RESET  "\x1b[0m"
#define COLOR_PURPLE  "\033[0;35m"
#define COLOR_GREEN  "\033[0;32m"
#define COLOR_BLUE  "\033[0;34m"
#define COLOR_RED "\033[0;31m"


#define MAX_NAME_LENGTH 100
char searchName[MAX_NAME_LENGTH];

int login() {
    
// you can create your own user name and password by changing the values 

char iname[15],ipass[15];
char uname[15]="username";
char upass[15]="pass123";

do{
printf("\n------------------- LOGIN FORM ---------------------");
printf ("\nEnter user name : ");
scanf("%s", iname) ;
printf ("\nEnter password : " ) ;
scanf("%s", ipass) ;
if(   (strcmp(uname,iname) && strcmp(upass,ipass) )==0)
{
printf("\nLogged in successfully") ;
return 0;
}
printf("\nWrong user name or password ") ;
printf ("\nEnter the details again") ;

}while(1) ;

}

typedef struct Currency_t {
    char name[MAX_NAME_LENGTH];
    char dynasty[MAX_NAME_LENGTH];
    char king[MAX_NAME_LENGTH];
    int buyValue;

    struct Currency_t *next;
    struct Currency_t *prev;
} Currency;

Currency *head = NULL;

Currency *createCurrency(char *name, char *dynasty, char *king, int buyValue) {
    Currency *newCurrency = malloc(sizeof(Currency));
    strcpy(newCurrency->name, name);
    strcpy(newCurrency->dynasty, dynasty);
    strcpy(newCurrency->king, king);
    newCurrency->buyValue = buyValue;
    newCurrency->prev = NULL;
    newCurrency->next = NULL;
    return newCurrency;
}



void insertCurrency(Currency *currency) {
    if (head == NULL) {
        head = currency;
    } else {
        Currency *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = currency;
        currency->prev = temp;
    }
}

Currency *findCurrency(char *name) {
    Currency *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void printCurrency(Currency *currency) {
    printf("\nName: %s\n", currency->name);
    printf("Dynasty: %s\n", currency->dynasty);
    printf("King: %s\n", currency->king);
    printf("Buy value: %d", currency->buyValue);
}

void addCurrencyToFile(char *name, char *dynasty, char *king, int buyValue) {
    FILE *file = fopen("currencies.txt", "a");
    fprintf(file, "%s %s %s %d\n", name, dynasty, king, buyValue);
    fclose(file);
}

void printCurrencies() {
    int i=0;
    Currency *temp = head;
    while (temp != NULL) {
        i++;
        printCurrency(temp);
        printf("\n");
        temp = temp->next;
    }
    // printf("\nThe total number of coins in the collection are : %d \n",i);
}

void coin_count() {
    int i=0;
    Currency *temp = head;
    while (temp != NULL) {
        i++;
        temp = temp->next;
    }
    printf(COLOR_BLUE"\nThe total number of coins in the collection are : %d \n",i);
    printf(COLOR_RESET);
}


int main(void) {
    login();
    printf(COLOR_GREEN"\n\nWelcome to Unique Currency Finder"COLOR_RESET) ;

    FILE *file = fopen("currencies.txt", "r");
    char name[MAX_NAME_LENGTH], dynasty[MAX_NAME_LENGTH], king[MAX_NAME_LENGTH];
    int buyValue;
    while (fscanf(file, "%s %s %s %d", name, dynasty, king, &buyValue) == 4) {
        Currency *currency = createCurrency(name, dynasty, king, buyValue);
        insertCurrency(currency);
    }
    fclose(file);

    int operation=1;
    while(operation!=0){

        printf("\nWhat operatio do you want to perform : ");
        printf("\n1.Search for a coin");
        printf("\n2.Add a new coin to the collection");
        printf("\n3.Print all the coins in the collection.");
        printf("\n4.Give the Count of coins in the collection");
        printf("\n5.EXIT");
        printf(COLOR_RED"\nEnter your choice : "COLOR_RESET);
        scanf("%d",&operation);

            switch(operation){
                case (1):
                    
                    printf("\n\nEnter the name of the currency to search for: ");
                    scanf("%s", searchName);
                    Currency *foundCurrency = findCurrency(searchName);
                    if (foundCurrency != NULL) {
                        printf(COLOR_GREEN"\nCOIN IS PRESENT IN YOUR COLLECTION.\n"COLOR_RESET);

                        int details;
                        printf("Press 1 to know the deatails of the coin : ");
                        scanf("%d",&details);
                        if(details==1)
                        {
                            printf("\nThe details of the coins are:");
                            printf(COLOR_PURPLE);
                            printCurrency(foundCurrency);
                            printf(COLOR_RESET);
                        }
                    } else {
                        printf(COLOR_RED"\t\t\t\t\tCURRENCY NOT FOUND in your collection.\n"COLOR_RESET);
                        printf(COLOR_GREEN"\t\t\t\t\t<<<---  FOUND A UNIQUE CURRENCY  --->>>");
                        printf("\n\t\t\t\t\tIF YOU ARE ADDING IT TO COLLECTION THEN YOU CAN ADD IT"COLOR_RESET);
                    }

                    break;

                case(2):
                    printf("\n\nEnter the name of the currency you want to add : ");
                    scanf("%s", searchName);
                    printf("\n\nDo you want to add this coin to your collection.");
                    printf("\nPress 1 for Yes and 2 for No: ");
                    int yes;
                    scanf("%d",&yes);

                    if(yes==1)
                    {
                    printf("Enter the name of the dynasty the currency belongs to : ");
                    scanf("%s", dynasty);
                    printf("Enter the name of the king the currency belongs to: ");
                    scanf("%s", king);
                    printf("Enter the buy value of the currency: ");
                    scanf("%d", &buyValue);
                    Currency *newCurrency = createCurrency(searchName, dynasty, king, buyValue);
                    addCurrencyToFile(searchName, dynasty, king, buyValue);
                    insertCurrency(newCurrency);
                    printf(COLOR_GREEN"CURRENCY ADDED TO THE LIST.\n"COLOR_RESET);
                    }

                    break;
                
                case(3):
                printf("\nDo you want to print all the elements in the collection ");
                int yes1;
                printf("\nPress 1 for Yes and 2 for No: ");
                scanf("%d",&yes1);

                if(yes1==1)
                {
                    printf(COLOR_BLUE);
                    printCurrencies();
                    printf(COLOR_RESET);
                }
                else
                {
                    printf("\nInvalid response");
                    // printf("\nThanks for using UNIQUE CURRENCY FINDER\n");
                }
                break;

                case(4):
                    coin_count();
                    break;
                
                case(5):
                    operation=operation*0;
                    printf("\nThanks for using UNIQUE CURRENCY FINDER\n");
                    return 0;

            }
    }

return 0;
}
