///Hashing [Chaining Methods] 
#include <bits/stdc++.h>
#define SIZE 20

using namespace std;

struct DataItem {
    int data;
    int key;
};

struct DataItem* dataList[SIZE][SIZE];
struct DataItem* singleItem;
struct DataItem* item;

int getHashCode(int key) {
    return key % SIZE;
}

struct DataItem *search(int key) {
    //get the hash
    int hashIndex = getHashCode(key);
    int i = 0;
    //move in array until an empty
    while(dataList[hashIndex][i]!=NULL)
    {
        if(dataList[hashIndex][i]->key == key)
            return dataList[hashIndex][i];

        //go to next
        ++i;
        //wrap around
        i %= SIZE;

    }
    return NULL;
};

void insert (int key, int data) {
    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item->data = data;
    item->key = key;

    //get the hash
    int hashIndex = getHashCode(key);
    int i = 0;

    //move in array until an empty or deleted cell
    while(dataList[hashIndex][i] != NULL && dataList[hashIndex][i]->key != -1) {
        //while(dataList[hashIndex][i] != NULL)

        //go to next
        ++i;
        //wrap around
        i %= SIZE;

    }

    dataList[hashIndex][i] = item;

}

struct DataItem* del(struct DataItem* item) {
    int key = item->key;
    int i = 0;
    //get the hash
    int hashIndex = getHashCode(key);

    //move in array until an empty
    while(dataList[hashIndex][i] != NULL) {
        if(dataList[hashIndex][i]->key == key) {
            struct DataItem* temp = dataList[hashIndex][i];

            //assign a dummy item at deleted position
            dataList[hashIndex][i] = singleItem;
            return temp;
        }

        //go to next
        ++i;

        //wrap around
        i %= SIZE;
    }
    return NULL;
};

void display() {
    int i = 0, j = 0;

    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(dataList[i][j] != NULL)
                printf(" (%d%d)", dataList[i][j]->key, dataList[i][j]->data);
            else
                printf(" ~~ ");
        }
        printf("\n");
    }

    printf("\n");
}

int main()
{
    singleItem = (struct DataItem*) malloc(sizeof(struct DataItem));
    singleItem->data = -1;
    singleItem->key = -1;

    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(13, 78);
    insert(37, 97);

    display();

    item = search(37);

    if(item != NULL)
        printf("Element found: %d\n", item->data);
    else
        printf("Element not found");

    del(item);
    item = search(37);

    if(item != NULL)
        printf("Element found: %d\n", item->data);
    else
        printf("Element not found\n");

    return 0;
}
