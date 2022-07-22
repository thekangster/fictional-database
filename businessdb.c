#include "map.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUM_BUCKETS 100

int main(void) {

  CustomerNode* buckets[NUM_BUCKETS] = {NULL};

  char email[50];
  char name[50];
  int shoe_size;
  char fav_food[50];

  char line[150];

  FILE *infile = fopen("customers.tsv", "r");
  if (infile == NULL) {
    printf("no such file\n");
  }

  while (fgets(line, 150, infile) != NULL) {
    if (sscanf(line, " %50[^\t]\t%50[^\t]\t%d\t%50[^\n]", email, name, &shoe_size, fav_food) == 4) {
      add_to_hashtable(email, name, shoe_size, fav_food, buckets, NUM_BUCKETS);
      
    } else {
      printf("ERROR: missing email, name, shoe_size, or fav_food\n"); 
    }
  }

  fclose(infile);

  while (1) {
    printf("command: ");
    char command[10];
    scanf("%s", command);
    
    if (strcmp(command, "quit") == 0) {
      delete_hashtable(buckets, NUM_BUCKETS);
      break;
    } else if (strcmp(command, "add") == 0) {

      printf("email address? ");
      scanf(" %[^\n\t]s", email);
      printf("name? ");
      scanf(" %[^\n\t]s", name);
      printf("shoe size? ");
      scanf("%d", &shoe_size);
      printf("favorite food? ");
      scanf(" %[^\n\t]s", fav_food);
      add_to_hashtable(email, name, shoe_size, fav_food, buckets, NUM_BUCKETS);
      
    } else if (strcmp(command, "save") == 0) {
      FILE *writefile = fopen("customers.tsv", "w");
      if (writefile == NULL) {
        printf("error opening file\n");
      }
      CustomerNode *node;
      for (int i = 0; i < (int)NUM_BUCKETS; i++) {
        node = buckets[i];
        while(node != NULL) {
          fprintf(writefile, "%s\t%s\t%d\t%s\n", node->email, node->name, node->shoe_size, node->fav_food);
          node = node->next;
        }
      }
      fclose(writefile);
    } else if (strcmp(command, "lookup") == 0) {
      printf("email address? ");
      scanf(" %[^\n\t]s", email);
      lookup_customer(email, buckets, NUM_BUCKETS);
    } else if (strcmp(command, "delete") == 0) {
      printf("email address? ");
      scanf(" %[^\n\t]s", email);
      delete_customer(email, buckets, NUM_BUCKETS);
    } else if (strcmp(command, "list") == 0) {
      list_customers(buckets, NUM_BUCKETS);
    }
  }

  return 0;
}

