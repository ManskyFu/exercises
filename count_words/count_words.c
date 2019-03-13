#include "count_words.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_new_file(char *str)
{
    char c;
    char *tmp = "tmp";

    FILE *fp  = fopen(str, "r+");
    FILE *ftp = fopen(tmp, "w+");

    while ((c = fgetc(fp)) != EOF)
    {
        if (c >= 'a' && c <= 'z') 
        {
            fputc(c, ftp);
        }
        else if (c >= 'A' && c <= 'Z')
        {
            fputc(c+32, ftp);
        }
        else
            fputc(' ', ftp);
    }
    fclose(fp);
    fclose(ftp);

    return tmp;
}
struct cwords*save_words(char *str)
{
    char tword[50];
    FILE *fp = fopen(str, "r+");
    struct cwords *phead = (struct cwords*)malloc(sizeof(struct cwords));
    phead->next = NULL;
    struct cwords *prev = phead, *rear;

    while (fscanf(fp, "%s", tword) != EOF)
    {
        rear = (struct cwords*)malloc(sizeof(struct cwords));
        rear->next = NULL;
        rear->times = 0;
        strncpy(rear->word, tword, 50);
        prev->next = rear;
        prev = rear;
    }

    return phead;
}
void count_times(struct cwords *phead)
{
    int cnt = 0;
    char tword[50];
    struct cwords *rear;
    struct cwords *tail = phead->next;

    while (tail)
    {
       for (rear = tail; rear != NULL; rear = rear->next)
       {
           if (!rear->times)
           {
               strncpy(tword, rear->word, 50);
               rear->times = -1;
               cnt++;
               break;
           }
       }
       for (rear = tail; rear != NULL; rear = rear->next)
       {
           if ((!strncmp(tword, rear->word, 50)) && (rear->times != -1))
           {
               cnt++;
               rear->times = -1;
           }
       }

       for (rear = tail; rear != NULL; rear = rear->next)
       {
           if (!strncmp(tword, rear->word, 50))
           {
               rear->times = cnt;
               cnt = 0;
               break;
           }
       }
        
        tail = tail->next;
    }
}

void sort_words(struct cwords *phead)
{
    struct cwords *prev, *rear;
    int tmp;
    char tword[50];
    for (prev = phead->next; prev != NULL; prev = prev->next)
    {
        for (rear = phead->next; rear->next != NULL; rear = rear->next)
        {
            if (rear->times < rear->next->times)
            {
                tmp = rear->times;
                rear->times = rear->next->times;
                rear->next->times = tmp;

                strncpy(tword, rear->word, 50);
                strncpy(rear->word, rear->next->word, 50);
                strncpy(rear->next->word, tword, 50);
            }
        }
    }
}

void print_result(struct cwords *phead)
{
    struct cwords *tail = phead->next;

    while (tail)
    {
        if (tail->times > 0)
        {
            printf("%s--%d\t", tail->word, tail->times);
        }
        
        tail = tail->next;
    }
}
