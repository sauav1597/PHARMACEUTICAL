// this is project 2021/12/17
// time-10:02 AM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MYFILE "medicine.txt"

struct Medical_store
{
    char name[100];
    char composition[100];
    int stock;
    int price;
    char location[100];
    int retail;
    int profit;
};

int i;
int count = 0;

struct Medical_store medicine[1000];

char nametosearch[100];

char sell_medi[100];
float dis, dis_amount;
int stock_out;

void add_medi();
void search_medi();
void checkout_medi();
void show_medi();

int main()
{
    FILE *count_ptr;
    count_ptr = fopen("medicine.txt", "r");
    if (count_ptr == NULL)
    {
        printf("!!!INVALID!!!\n");
        exit(0);
    }

    else
    {

        for (i = getc(count_ptr); i != EOF; i = getc(count_ptr))
        {
            if (i == '\n')
            {
                count++;
                // fflush(stdin);
            }
        }
    }
    while (1)
    {
        int choose;

        printf("\n\t\t\t\t\t\t*************** MAIN MENU ***************\n");
        printf("\n\t\t\t\t\t\tPRESS 1 : TO ADD MEDICINE DETAILS \n");
        printf("\n\t\t\t\t\t\tPRESS 2 : TO SEARCH MEDICINE \n");
        printf("\n\t\t\t\t\t\tPRESS 3 : TO CHECKOUT MEDICINE \n");
        printf("\n\t\t\t\t\t\tPRESS 4 : TO CHECK ALL LIST OF MEDICINE\n");
        printf("\n\t\t\t\t\t\tPRESS 5 : EXIT\n");
        printf("\n\t\t\t\t\t\t****************************************\n\n");
        printf("\n\t\t\t\t\t\tENTER YOUR CHOICE : ");
        scanf("%d", &choose);

        fclose(count_ptr);

        switch (choose)
        {
        case 1:
        {

            add_medi();
            break;
        }

        case 2:
        {

            search_medi();
            break;
        }

        case 3:
        {

            checkout_medi();
            break;
        }

        case 4:
        {

            show_medi();
            break;
        }
        case 5:
        {

            printf("EXIT");
            exit(0);
        }

        default:
            printf("!!!INVALID NUMBER !!!");
            break;
        }
        // }
    }

    return 0;
}

void add_medi()
{

    int n_add;

    FILE *medi_add;
    medi_add = fopen("medicine.txt", "a");

    printf("How many medicine do you want to add :\n");
    scanf("%d", &n_add);

    if (medi_add == NULL)
    {
        printf("Memory allocation failed \n");
        exit(0);
    }
    else
    {
        printf("NAME\t\tCOMPOSITION\t\tSTOCKS\tRETAIL_PRICE\tPRICE_TO_SELL\tFROM\t\n");

        for (i = 0; i < n_add; i++)
        {
            scanf("%s %s %d %d %d %s", medicine[i].name, medicine[i].composition, &medicine[i].stock, &medicine[i].retail, &medicine[i].price, medicine[i].location);

            fprintf(medi_add, "\n%s\t\t%s\t\t%d\t%d\t%d\t%s", medicine[i].name, medicine[i].composition, medicine[i].stock, medicine[i].retail, medicine[i].price, medicine[i].location);

            // fprintf(medi_add, "\n%s %20s %20d %10d\t\t%10d\t\t%10s", medicine[i].name, medicine[i].composition, medicine[i].stock, medicine[i].retail, medicine[i].price, medicine[i].location);
        }
    }
    fclose(medi_add);
    printf("Adding of medicine is complete\n");
    printf("File is close \n");
}

void search_medi()
{
    // struct Medical_store medicine[1000];
    FILE *medi_search;

    if (medi_search == NULL)
    {
        printf("!!! INVALID !!!");
    }
    else
    {

        if (medi_search = fopen(MYFILE, "r"))
        {
            int fountRecord = 0;
            fflush(stdin);
            printf("Enter name to search : ");
            fgets(nametosearch, 100, stdin);
            fflush(stdin);

            nametosearch[strlen(nametosearch) - 1] = '\0';

            while (fgets(medicine[i].name, 100, medi_search))
            {
                if (strstr(medicine[i].name, nametosearch))
                {
                    printf("%s\n", medicine[i].name);

                    fountRecord = 1;
                }
            }
            if (fountRecord == 0)
                printf("%s cannot be found\n", nametosearch);

            fclose(medi_search);
        }
        else
        {
            printf("file %s  cannot be opened\n", MYFILE);
        }
    }

    fclose(medi_search);
}

void checkout_medi()
{

    FILE *count_ptr;
    count_ptr = fopen(MYFILE, "r");
    if (count_ptr == NULL)
    {
        printf("!!!INVALID!!!\n");
        exit(0);
    }

    else
    {

        FILE *medi_checkout;

        if (medi_checkout == NULL)
        {
            printf("!!! INVALID !!!");
        }
        else
        {
            printf("%d\n", count);
            if (medi_checkout = fopen(MYFILE, "r"))
            {
                int fountRecord = 0;
                printf("Enter name to search : ");
                fflush(stdin);
                fgets(nametosearch, 100, stdin);

                printf("Enter a amount you want to buy:");
                scanf("%d", &stock_out);
                fflush(stdin);

                nametosearch[strlen(nametosearch) - 1] = '\0';

                // for (i = 0; i < count; i++)
                for (i = getc(medi_checkout); i != EOF; i = getc(medi_checkout))
                {
                    if (i == '\n')
                    {

                        fscanf(medi_checkout, "%s", medicine[i].name);

                        if (strcmp(medicine[i].name, nametosearch) == 0)
                        {
                            fscanf(medi_checkout, "%d", &medicine[i].stock);

                            if ((medicine[i].stock > stock_out) == 0)
                            {

                                fscanf(medi_checkout, "%s %d %d\n", medicine[i].name, &medicine[i].stock, &medicine[i].price);
                                // printf("%s %d %d\n", medicine[i].name,medicine[i].stock,medicine[i].price);
                                // printf("%s\n",medicine[i].name);
                                printf("%s %d %d\n", nametosearch, medicine[i].stock, medicine[i].price);
                                printf("Medicine available\n");
                                fountRecord = 1;
                                printf("Enter a discount rate: ");
                                scanf("%f", &dis);
                                fflush(stdin);
                                dis_amount = (stock_out * medicine[i].price) - ((stock_out * medicine[i].price) * (dis / 100));
                                printf("After %.0f discount payable amount is %.2f", dis, dis_amount);
                                fprintf(medi_checkout, "%d", (medicine[i].stock - stock_out));
                                printf("!!! SUCESSFULLY !!!");
                            }
                        }
                    }
                }
                if (fountRecord == 0)
                {

                    printf("%s cannot be found\n", nametosearch);
                    exit(0);
                }
            }
        }

        fclose(medi_checkout);
    }
}
void show_medi()
{
    FILE *medi_show;
    medi_show = fopen("medicine.txt", "r");
    printf("NAME\t\tCOMPOSITION\t\tSTOCKS\tRETAIL_PRICE\tPRICE_TO_SELL\tFROM\t\n");
    printf("\n");
    for (i = 0; i < count; i++)
    {
        fscanf(medi_show, "%s\t\t%s\t\t%d\t%d\t%d\t%s\t\n", medicine[i].name, medicine[i].composition, &medicine[i].stock, &medicine[i].retail, &medicine[i].price, medicine[i].location);

        printf("%s\t\t%s\t\t\t%d\t%d\t\t%d\t\t%s\t\n", medicine[i].name, medicine[i].composition, medicine[i].stock, medicine[i].retail, medicine[i].price, medicine[i].location);
    }
    printf("!!! SUCESSFULLY !!!");
    fclose(medi_show);
}
