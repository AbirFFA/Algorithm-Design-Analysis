///Hasing using structure
#include<bits/stdc++.h>
#define SIZE 20

struct info {
    char name[80];
    int age;
    double height;
};

struct DataItem {
    struct info student;
    int key;
};

struct DataItem *dataList[SIZE];
struct DataItem *singleItem;
struct DataItem *item;

int getHashCode(int key) {
    ///get the hash
    return key%SIZE;
}

struct DataItem* search(int key) {
    //get the hash
    int hashIndex = getHashCode(key);

    while(dataList[hashIndex] != NULL) {
        if(dataList[hashIndex]->key == key)
            return dataList[hashIndex];

        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
}

void insert(int key,char name[], int age, double height) {
    struct DataItem *item = (struct DataItem*)malloc(sizeof(struct DataItem));

    strcpy(item->student.name, name);
    item->student.age = age;
    item->student.height = height;
    item->key = key;

    //get the hash
    int hashIndex = getHashCode(key);

    //move  index until find an empty
    while(dataList[hashIndex] != NULL) {

        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;
    }

    dataList[hashIndex] = item;
}

struct DataItem *del(struct DataItem *item) {
    int key = item->key;

    //get the hash
    int hashIndex = getHashCode(key);

    while(dataList[hashIndex] != NULL) {

        if(dataList[hashIndex]->key == key) {
            struct DataItem *temp = dataList[hashIndex];

            ///assign a dummy position
            dataList[hashIndex] = singleItem;
            return temp;

        }
        //go to next cell
        ++hashIndex;
        //wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
}

void display() {
    int i = 0;
    for(i = 0; i < SIZE; i++) {
        if(dataList[i]!=NULL)
            printf("Key: %d, Name: %s, Age: %d, Height: %lf\n",dataList[i]->key,dataList[i]->student.name,dataList[i]->student.age,dataList[i]->student.height);

        else
            printf(" ~~\n");
    }

    printf("\n");
}

int main()
{

    singleItem = (struct DataItem*)malloc(sizeof(struct DataItem));

    singleItem->student.age = -1;
    singleItem->student.height = -1;
    singleItem->key = -1;

    insert(1,"Qwe",12,5.6);
    insert(21,"Asd",20,6.1);
    insert(2,"Zxc",14,5.4);
    insert(22,"Poi",21,5.10);
    insert(4,"Lkj",19, 5.7);
    insert(12,"Rty", 18, 5.4);
    insert(14,"Fgh", 23, 6.2);
    insert(17,"Cvb", 20, 5.10);
    insert(13,"Pql", 54, 5.3);
    insert(37,"KDH", 10, 3.9);

    display();

    item = search(37);


    if(item != NULL)
        printf("Element found: Key: %d, Name: %s, Age: %d, Height: %lf\n",item->key,item->student.name,item->student.age,item->student.height);

    else
        printf("Element not found\n");

    del(item);
    item = search(37);

    if(item != NULL)
        printf("Element found: Key: %d, Name: %s, Age: %d, Height: %lf\n",item->key,item->student.name,item->student.age,item->student.height);
    else
        printf("Element not found\n");


    return 0;
}

