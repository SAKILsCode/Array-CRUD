
// CRUD Array Project - (Requirements)

//  1. Create
//      1. Create a new array
//          1. Size
//          2. Value
//          3. Position
//      2. Insert value
//          1. value
//          2. position
//  2. Read
//      1. Full array
//      2. Index
//      3. Search
//          1. value
//          2. index
//  3. Update
//      1. Position
//      2. value
//  4. Delete
//      1. value
//      2. index

#include <stdio.h>
#include <stdlib.h>

int i, array_size, array_value;
int arr[0];

void create_array()
{
    int position;
    printf("-->> Enter Array Size_ ");
    scanf("%d", &array_size);
    // int arr[array_size];
    for (i = 0; i < array_size; i++)
    {
        printf("-->> Enter Value_ ");
        scanf("%d", &array_value);

        arr[i] = array_value;
    }

    printf("\n\n");
}

void print_array()
{
    int has_array = 0;
    for (i = 0; i < array_size; i++)
    {
        has_array++;
        if (i == array_size - 1)
        {
            printf("%d", arr[i]);
        }
        else
        {
            printf("%d, ", arr[i]);
        }
    }
    if (has_array < 1)
    {
        printf(">> Array not Found <<");
    }
    printf("\n\n");
}

void linear_search()
{
    int value, storeIndex = -1, storeVal;
    printf("-->> Enter Value_ ");
    scanf("%d", &value);
    for (i = 0; i < array_size; i++)
    {
        if (arr[i] == value)
        {
            storeIndex = i;
            storeVal = arr[i];
            break;
        }
    }
    if (storeIndex >= 0)
    {
        printf("%d is found on index %d", storeVal, storeIndex);
    }
    else
    {
        printf("%d is not found", value);
    }

    printf("\n\n");
}

void read_index()
{
    int i;
    printf("-->> Enter index number_ ");
    scanf("%d", &i);

    if (array_size - 1 == i)
    {
        printf("\nArr[%d] = %d\n\n", i, arr[i]);
    }
    else if (array_size - 1 > i)
    {
        printf("Index number is greater than %d\n\n", i);
    }
    else if (array_size - 1 < i)
    {
        printf("Index number is less than %d\n\n", i);
    }
    else
    {
        printf("Index Number Isn't Valid!\n\n");
    }
}

void update_array()
{
    if (array_size != 0)
    {
        int position, value;
        printf("-->> Enter Position (Not Index)_ ");
        scanf("%d", &position);
        printf("-->> Enter Value_ ");
        scanf("%d", &value);
        arr[position - 1] = value;
        printf("\n\n");
    }
    else
    {
        printf("\n>> Array Not Found <<\n\n");
    }
}

void deleteAVal()
{
    int j, x;
    if (array_size != 0)
    {
        printf("-->> Enter Index Number to Delete_ ");
        scanf("%d", &x);
        if (x < 0 || x >= array_size)
        {
            printf(">> Invalid Position! Enter position between 0 to %d <<", array_size - 1);
        }
        else
        {
            for (i = x; i < array_size - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            array_size--;
            printf("\nDeleted Successfully!!");
        }
    }
    else
    {
        printf("\n>> Array Not Found <<");
    }

    printf("\n\n");
}

int main()
{

    do
    {
        printf("Press [1] to Create\n");
        printf("Press [2] to Read\n");
        printf("Press [3] to Update\n");
        printf("Press [4] to Delete\n");
        printf("Press [5] to Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Create
            printf("[1] Create a new Array.\n");
            printf("[2] Insert Value.\n");
            create_array();
            break;

        case 2:
            // Read
            if (array_size != 0)
            {
                printf("[1] Read full array.\n");
                printf("[2] Search Value.\n");
                printf("[3] Read from index.\n");

                int readChoice;
                scanf("%d", &readChoice);

                if (readChoice == 1)
                {
                    // Print Full Array
                    print_array();
                }
                else if (readChoice == 2)
                {
                    // Linear Search
                    linear_search();
                }
                else if (readChoice == 3)
                {
                    // Read From Index
                    read_index();
                }
            }
            else
            {
                printf(">> Array Not Found <<\n\n");
            }
            break;

        case 3:
            // Update
            update_array();
            break;

        case 4:
            // Delete
            deleteAVal();
            break;

        case 5:
            // Exit
            exit(0);
            break;

        default:
            printf(">>>>> Please enter number between [1] - [5] <<<<<");
            printf("\n\n");
            break;
        }
    } while (1);

    return 0;
}
