#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "system.h"

st *get_data(void)
{
    FILE *fp = fopen("data.txt", "r+");
    char  tname[20];
    float tscore;
    st   *phead, *prev, *rear;
    phead = (st *)malloc(sizeof(st));
    phead->next = NULL;
    prev = phead;

    while (fscanf(fp, "%s%f", tname, &tscore) != EOF)
    {
        rear = (st *)malloc(sizeof(st));
        if (rear == NULL)
        {
            puts("Error : no more memory!");
            return NULL;
        }
        rear->next  = NULL;
        rear->score = tscore;
        strncpy(rear->name, tname, 20);
        prev->next = rear;
        prev       = rear;
    }
    fclose(fp);
    return phead;
}

int log_in(void)
{
    FILE *fp = fopen("passwd.txt", "r+");
    char usrname[20], tname[20];
    char passwd[10], tpasswd[10];
    char ch = fgetc(fp);
    fclose(fp);
    
    if (ch == EOF)
    {
        fp = fopen("passwd.txt", "w+");
        puts("Please enter new username:");
        scanf("%20s", usrname);
        puts("Please enter new password(within 10 characters):");
        scanf("%10s", passwd);
        fputs(usrname, fp);
        fputs(" ", fp);
        fputs(passwd, fp);
        fputs(" ", fp);
        return RIGHT_INFOR;
    }
    else
    {
        fp = fopen("passwd.txt", "r+");
        puts("Please enter your username:");
        scanf("%20s", usrname);
        puts("Please enter your password:");
        scanf("%10s", passwd);

        while (fscanf(fp, "%s %s", tname, tpasswd) != EOF)
        {
            if ((!strncmp(usrname, tname, 20)) && (!strncmp(passwd, tpasswd, 10)))
            {
                return RIGHT_INFOR;
            }
        }
    }
    fclose(fp);
    return WRONG_INFOR;
}

int print_menu(void)
{
    int choice;

    printf("\t\tWelcom to Use System\n\n");
    printf("\t1.Add information\t2.Delete information\n");
    printf("\t3.Search informaion\t4.Print information\n");
    printf("\t5.Exit system\n\n");
    printf("**********************\n");
    do
    {
        printf("Please enter your choice:   \n");
        scanf("%d", &choice);
        if (choice <= 0 || choice > 5)
            puts("Error: input your choice correctly!");
    } while(choice <= 0 || choice > 5);

    return choice;
}

void del_data(st *phead)
{
    char tname[20], choice;
    st *prev, *rear;

    do
    {
        prev = phead;
        rear = phead->next;
        puts("Please enter student's name you want to delete:");
        scanf("%20s", tname);

        while (rear)
        {
            if (!strncmp(tname, rear->name, 20))
                break;
            prev = prev->next;
            rear = rear->next;
        }
        if (phead->next == NULL)
        {
            puts("No information now!");
            return ;
        }
        if (strncmp(tname, rear->name, 20) && rear == NULL)
        {
            puts("There is no information about the student!");
        }
        prev->next = rear->next;
        free(rear);
        printf("Done! continue(y/n)? :\n");
        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');
}

void add_data(st *phead)
{
    st *prev, *rear;
    char choice;

    do
    {
        prev = phead;
        rear = (st*)malloc(sizeof(st));
        if (rear == NULL)
        {
            puts("No memory left!");
            return;
        }
        printf("Please enter student's name you want to add:\n");
        scanf("%20s", rear->name);
        puts("Please enter the student's score:");
        scanf("%f", &rear->score);
        rear->next = prev->next;
        prev->next =rear;
        printf("Done! continue(y/n)? :\n");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}

void search_data(st *phead)
{
    st *rear;
    char choice;
    char tname[20];

    do
    {
        rear = phead->next;
        puts("Please enter the student's name you want to search:");
        scanf("%20s", tname);

        while (rear)
        {
            if (!strncmp(tname, rear->name, 20))
            {
                printf("The student's score is %.2f.\n", rear->score);
                break;
            }
            rear = rear->next;
        }
        if ((rear == NULL) && strncmp(tname, rear->name, 20))
        {
            printf("There is no information about the student!\n");
        }
        printf("Done! continue(y/n)? :\n");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}

void sort_data(st *phead)
{
    st *rear, *tail = phead->next;
    char tname[20];
    float tscore;

    while (tail)
    {
        for (rear = phead->next; rear->next != NULL; rear = rear->next)
        {
            if (rear->score < rear->next->score)
            {
                strncpy(tname, rear->name, 20);
                strncpy(rear->name, rear->next->name, 20);
                strncpy(rear->next->name, tname, 20);

                tscore = rear->score;
                rear->score = rear->next->score;
                rear->next->score = tscore;
            }
        }
        tail = tail->next;
    }
}

void print_data(st *phead)
{
    st *rear = phead->next;

    puts("All Information:");
    printf("%20s\t%10s\n", "Name", "Score");
    while (rear)
    {
        printf("%20s\t%10.2f\n", rear->name, rear->score);
        rear = rear->next;
    }
}

void save_data(st *phead)
{
    st *rear = phead->next;
    FILE *fp = fopen("tmp.txt", "w+");

    while (rear)
    {
        fprintf(fp, "%s %f ", rear->name, rear->score);
        rear = rear->next;
    }
    fclose(fp);
    remove("data.txt");
    rename("tmp.txt", "data.txt");
}

void del_list(st *phead)
{
    st *prev, *rear = phead->next;
    
    while (rear)
    {
        prev = rear;
        rear = rear->next;
        free(prev);
    }
    free(phead);
}
