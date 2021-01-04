#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;         // each node holds a single character
    struct node *next; // pointer to next node in linked list
} node;

//display the list
void reverse_print(struct node *list) {
   if(list == NULL) {
      //printf("[null] => ");
      return;
   }
   
   reverse_print(list->next);
   printf("%c ",list->data);
   
}

int main(int argc, char** argv) {

	if(argc!=2)
	{
		perror("argFail");
		printf("Format: ./a.out Your_String \n");
		return 0;
	}
    int i;

    node *top = NULL;
    node *cur = NULL;
    char c[30];
	int count,count1;
	int len;
	strcpy(c,argv[1]);
	len=strlen(argv[1]);
	count=len;
	count1=0;
    while ( count> 0 && count1<len) 
    {
        node *item = malloc(sizeof(node));
        item->data = c[count1];
        item->next = NULL;
        if (!cur) 
		{
            // first time, store top.
            top = cur = item;
        } 
		else
		{
            // chain nexts.
            cur->next = item;
            cur = item;
        }
		count--;
		count1++;
    }
    // print datas

    cur = top;
    printf("As in List\n");
    while (len>0) {
        printf("%c ", cur->data);
        cur = cur->next;
        len--;
    }
    printf("\n");
    printf("Reverse of List\n");
    reverse_print(top);
    printf("\n");

    // free datas
    cur = top;
    while (cur) {
        node *item = cur->next;
        free(cur);
        cur = item;
    }
    return 0;
}
