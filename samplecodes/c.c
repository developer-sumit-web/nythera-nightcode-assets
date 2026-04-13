#include <stdio.h>
#include <string.h>

typedef struct
{
      int id;
      char name[32];
      int active;
} User;

User find_by_email(User users[], int size, const char *name)
{
      for (int i = 0; i < size; i++)
      {
            if (strcmp(users[i].name, name) == 0)
            {
                  return users[i];
            }
      }
      User empty = {0, "", 0};
      return empty;
}

void print_user(User u)
{
      if (u.active && strlen(u.name) > 0)
      {
            printf("User: %s (%d)\n", u.name, u.id);
      }
      else
      {
            printf("Inactive or not found\n");
      }
}

void process_users(User users[], int size)
{
      for (int i = 0; i < size; i++)
      {
            User u = users[i];
            if (u.active)
            {
                  printf("Active: %s\n", u.name);
            }
            else
            {
                  printf("Inactive: %s\n", u.name);
            }
      }
}

int main()
{
      User users[] = {
          {1, "Sumit", 1},
          {2, "Alex", 0},
          {3, "Dev", 1}};

      int size = sizeof(users) / sizeof(users[0]);

      User result = find_by_email(users, size, "Sumit");
      print_user(result);

      process_users(users, size);

      return 0;
}
