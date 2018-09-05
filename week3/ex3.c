#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node *next;
}Node;

typedef struct LinkedList{
  struct Node *head;
  int size;
}LinkedList;

int main(){
  LinkedList* list = malloc(sizeof(LinkedList));
  list -> size = 0;

  print_list(list);
  insert_node(list, 25);
  insert_node(list, 23);
  insert_node(list, 22);
  insert_node(list, 21);
  insert_node(list, 19);
  insert_node(list, 9);
  printf("%d\n", list -> size );
  print_list(list);
  delete_node(list, 3);
  print_list(list);

  return 0;
}

void print_list(LinkedList *list){

  if(list -> size!=0){
    printf("LinkedList: [");
    print_list_service(list -> head);
    printf(" ]\n");
  }else{
    printf("List is Empty \n");
  }
}

void print_list_service(Node *node){
  printf(" %d ", node -> data);
  if(node -> next != NULL){
    print_list_service(node -> next);
  }
}

void insert_node(LinkedList *list, int new){
  if(list -> size == 0){
    Node *node = malloc(sizeof(Node));
    node -> next = NULL;
    node -> data = new;
    list -> head = node;
  }else{
      insert_node_service(list -> head, new);
  }
  list -> size++;
}

void insert_node_service(Node *curr_node, int new){
    if(curr_node -> next == NULL){
      Node *node = malloc(sizeof(Node));
      node -> next = NULL;
      node -> data = new;
      curr_node-> next = node;
    }else {
      insert_node_service(curr_node-> next, new);
    }
}

void delete_node(LinkedList *list, int index){
  if(list -> size == 0){
    print_list(list);
  }else if(index >=list -> size ){
    printf("Deletion: index is too laarge\n");
  }else if(index == 0 ){
      Node *trash_node = list -> head;
      list -> head = list -> head -> next;
      free(trash_node);
    }else
      delete_node_service(list -> head, index, 1);
}

void delete_node_service(Node *node, int index, int next_index){
      //printf("Check next_index= %d", next_index);
      if(next_index == index){
        Node *trash_node = node -> next;
        node -> next = node -> next -> next;
        free(trash_node);
      }else{
        delete_node_service(node -> next, index, next_index+1);
      }
}

