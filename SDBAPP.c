#include "SDB.h"
#include <stdio.h>
#include <stdbool.h>

void SDB_APP()
{
    uint8_t choice;
    while (true)
    {
        printf("Choose an option:\n");
        printf("1. To add entry, enter 1\n");
        printf("2. To get used size in database, enter 2\n");
        printf("3. To read student data, enter 3\n");
        printf("4. To get the list of all student IDs, enter 4\n");
        printf("5. To check if ID is existed, enter 5\n");
        printf("6. To delete student data, enter 6\n");
        printf("7. To check if database is full, enter 7\n");
        printf("8. To exit, enter 0\n");
        scanf("%hhu", &choice);

        if (choice == 0)
        {
            break;
        }

        SDB_action(choice);
    }
}

void SDB_action(uint8_t choice)
{
    switch (choice)
    {
    case 1:
    {
        bool success = SDB_AddEntry();
        if (success)
        {
            printf("Student added successfully\n");
        }
        else
        {
            printf("Error adding student\n");
        }
        break;
    }
    case 2:
    {
        uint8_t size = SDB_GetUsedSize();
        printf("Used size: %hhu\n", size);
        break;
    }
    case 3:
    {
        uint32_t id;
        printf("Enter student ID: ");
        scanf("%u", &id);
        bool success = SDB_ReadEntry(id);
        if (!success)
        {
            printf("Student not found\n");
        }
        break;
    }
    case 4:
    {
        uint8_t count;
        uint32_t list[10];
        SDB_GetList(&count, list);
        printf("Student IDs: ");
        for (uint8_t i = 0; i < count; i++)
        {
            printf("%u ", list[i]);
        }
        printf("\n");
        break;
    }
    case 5:
    {
        uint32_t id;
        printf("Enter student ID: ");
        scanf("%u", &id);
        bool exists = SDB_IsIdExist(id);
        if (exists)
        {
            printf("Student exists\n");
        }
        else
        {
            printf("Student not found\n");
        }
        break;
    }
    case 6:
    {
      uint32_t id;
      printf("Enter student ID: ");
      scanf("%u", &id);
      SDB_DeleteEntry(id);
      break;
    }
    case 7:
    {
      bool full = SDB_IsFull();
      if (full)
      {
          printf("Database is full\n");
      }
      else
      {
          printf("Database is not full\n");
      }
      break;
    }
    default:
      break;
   }
}
