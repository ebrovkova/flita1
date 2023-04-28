#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _Node{
    char *bin;
    int dec;
    struct _Node *next;
} Node;


Node *create_node(){
    return (Node *)malloc(sizeof(Node));
}


void clear_mem(Node *s){
    Node *tmp;
    while (s != NULL){
        tmp = s->next;
        free(s);
        s = tmp;
    }
}


int bin_to_dec(char *b){
    int dec = 0;

    while (*b) {
        dec *= 2;
        if (*b++ == '1')
            dec += 1;
    }

    return dec;
}


int bin_check(char* n) {
    int length = (int) strlen(n);
    short bin = 1;
    for (int i = 0; i<length; i++) {
        if (n[i] != '0' && n[i] != '1')
            bin = 0;
    }
    return bin;
}


Node *add(Node *s){
    char *b;
    scanf("%as", &b);
    if (!bin_check(b)) return s;

    Node *t = create_node();
    t->bin = b;
    t->dec = bin_to_dec(b);
    t->next = NULL;

    if (s == NULL) return t;

    Node *h = s;
    while (s->next != NULL){
        if (s->bin == t->bin){
            free(t);
            return h;
        }
        s = s->next;
    }
    if (s->bin == t->bin){
        free(t);
        return h;
    }
    s->next = t;
    return h;
}


void print_set(Node *s){
    while (s != NULL){
        printf("%s %d\n", s->bin, s->dec);
        s = s->next;
    }
}


int main(void){
    printf("Type 1 to add element\nType 2 to print set\nType 0 to exit\n");
    Node *set = NULL;

    int action;
    scanf("%d", &action);
    while (action != 0){
        if (action == 1){
            set = add(set);
        } else if (action == 2){
            print_set(set);
            printf("\n");
        }
        scanf("%d", &action);
    }

    clear_mem(set);
    return 0;
}