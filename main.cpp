#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct product
{
    int id;
    struct product *pre_product;
    struct product *next_product;
} product;

product *p_last_product = NULL;
const int lock_product_close = 1;
const int lock_product_open = 0;
int lock_product = lock_product_open;
int id_product = 0;

void add_product(int id)
{
    while (lock_product)
        ;
    lock_product = lock_product_close;
    printf("Add Product %d...\n", id);
    product *new_product = (product *)malloc(sizeof(product));
    new_product->id = id;
    if (!p_last_product)
    {
        new_product->pre_product = new_product->next_product = NULL;
        p_last_product = new_product;
    }
    else
    {
        new_product->pre_product = p_last_product;
        new_product->next_product = NULL;
        p_last_product->next_product = new_product;
        p_last_product = new_product;
    }
    lock_product = lock_product_open;
}

void remove_product()
{
    while (lock_product)
        ;
    lock_product = lock_product_close;
    if (p_last_product)
    {
        printf("Remove Product %d...\n", p_last_product->id);
        product *pre_product = p_last_product->pre_product;
        if (pre_product)
            pre_product->next_product = NULL;
        p_last_product->pre_product = NULL;
        free(p_last_product);
        p_last_product = pre_product;
    }
    lock_product = lock_product_open;
}

void *producer(void *argv)
{
    while (++id_product <= 10)
    {
        add_product(id_product);
        sleep(1);
    }
}

void *customer(void *argv)
{
    while (p_last_product)
    {
        remove_product();
        sleep(1);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t thread_producer, thread_customer;
    pthread_create(&thread_producer, NULL, producer, NULL);
    sleep(2);
    pthread_create(&thread_customer, NULL, customer, NULL);
    pthread_exit(NULL);
    return 0;
}