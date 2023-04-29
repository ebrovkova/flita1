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


void clear_mem(Node *pointer){
    Node *tmp;
    while (pointer != NULL){
        tmp = pointer->next;
        free(pointer);
        pointer = tmp;
    }
}


int bin_to_dec(char *bin_str){
    int dec = 0;
    while (*bin_str) {
        dec *= 2;
        if (*bin_str++ == '1')
            dec += 1;
    }
    return dec;
}


int bin_check(char* number) {
    int length = (int) strlen(number);
    short bin = 1;
    for (int i = 0; i<length; i++) {
        if (number[i] != '0' && number[i] != '1')
            bin = 0;
    }
    return bin;
}


Node *add(Node *pointer){
    char *bin_str;
    scanf("%as", &bin_str);
    if (!bin_check(bin_str)) return pointer;

    Node *new_node = create_node();
    new_node->bin = bin_str;
    new_node->dec = bin_to_dec(bin_str);
    new_node->next = NULL;

    if (pointer == NULL) return new_node;

    Node *head = pointer;
    while (pointer->next != NULL){
        if (pointer->bin == new_node->bin){
            free(new_node);
            return head;
        }
        pointer = pointer->next;
    }
    if (pointer->bin == new_node->bin){
        free(new_node);
        return head;
    }
    pointer->next = new_node;
    return head;
}


void print_set(Node *pointer){
    while (pointer != NULL){
        printf("%s %d\n", pointer->bin, pointer->dec);
        pointer = pointer->next;
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
