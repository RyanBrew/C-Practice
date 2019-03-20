// standard library
#include <stdio.h>

// allows us to use the assert() function
// which makes sure something is in memory
#include <assert.h>

// gives us things like NULL and structs
#include <stdlib.h>

// gives us access to string functions
#include <string.h>

// creates a structure Person
struct Person {
  char *name;
  int age;
  int height;
  int weight;
};

// function for creating a person
struct Person *Person_create(char *name, int age, int height, 
			     int weight)
{
  // allocates memory of size Person to who
  struct Person *who = malloc(sizeof(struct Person));

  // makes sure we have valid input
  assert(who != NULL);
  
  // duplicates the string 'name' dynamically
  who->name = strdup(name);
  who->age = age;
  who->height = height;
  who->weight = weight;

  return who;
}

// whenever we create something we must destroy it
void Person_destroy(struct Person *who)
{
  // make sure we have a valid input
  assert(who != NULL);
  
  // deallocates the memory assigned to the name duplicate as well as the struct
  free(who->name);
  free(who);
}

void Person_print(struct Person *who)
{
  printf("Name: %s\n", who->name);
  printf("\tAge: %d\n", who->age);
  printf("\tHeight: %d\n", who->height);
  printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
  // make two people structures
  struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
  
  struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

  // print them out and where they are in memory
  printf("Joe is at memory location %p:\n", joe);
  Person_print(joe);

  printf("Frank is at memory location %p:\n", frank);
  Person_print(frank);

  // make everyone age 20 years and print them again
  joe->age += 20;
  joe->height -= 2;
  joe->weight += 40;
  Person_print(joe);
  
  frank->age += 20;
  frank->weight += 20;
  Person_print(frank);

  // destroy them both so we clean up
  Person_destroy(joe);
  Person_destroy(frank);
  
  return 0;
}
