#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    char name[51];
    int units_in_stock;
    double price;
    union {
        struct {
            int dimensions[3];
        };
        struct {
            char description[101];
        };
    } details;
    int dim_or_desc;
    struct Product *next;
};

void add_product(struct Product **ptr) {
    if (*ptr == NULL) {
        *ptr = (struct Product *)malloc(sizeof(struct Product));
        (*ptr)->next = NULL;
    } else {
        struct Product *current = *ptr;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = (struct Product *)malloc(sizeof(struct Product));
        current->next->next = NULL;
    }

    struct Product *new_product = *ptr;
    while (new_product->next != NULL) {
        new_product = new_product->next;
    }

    printf("Enter Product Name: ");
    fgets(new_product->name, sizeof(new_product->name), stdin);
    strtok(new_product->name, "\n");

    printf("Enter Quantity: ");
    scanf("%d", &new_product->units_in_stock);
    getchar();

    printf("Enter Price: ");
    scanf("%lf", &new_product->price);
    getchar();

    printf("Does this product have dimensions? (1 for YES or 0 for NO): ");
    scanf("%d", &new_product->dim_or_desc);
    getchar();
    if ( new_product->dim_or_desc == 1) {
        printf("Enter length, width, and height: ");
        scanf("%d %d %d", &new_product->details.dimensions[0], &new_product->details.dimensions[1], &new_product->details.dimensions[2]);
        getchar();
    } else {
        printf("Enter Product description: ");
        fgets(new_product->details.description, sizeof(new_product->details.description), stdin);
        strtok(new_product->details.description, "\n");
    }

    printf("Product Added Successfully!\n");
}

void display_products(struct Product *ptr) {
    printf("Name\t\tQuantity\tPrice\tDetails\n");

    while (ptr != NULL) {
        if (ptr->dim_or_desc == 0) {
            printf("%s\t\t%d\t\t%.2lf\t%s\n", ptr->name, ptr->units_in_stock, ptr->price, ptr->details.description);
        }
        else if (ptr->dim_or_desc == 1) {
            printf("%s\t\t%d\t\t%.2lf\t%d x %d x %d\n", ptr->name, ptr->units_in_stock, ptr->price,
                   ptr->details.dimensions[0], ptr->details.dimensions[1], ptr->details.dimensions[2]);
        } else {
            printf("%s\t\t%d\t\t%.2lf\n", ptr->name, ptr->units_in_stock, ptr->price);
        }
        ptr = ptr->next;
    }
}

void update_product_quantity(struct Product *ptr) {
    char productToUpdate[50];
    int quantityToUpdate;

    printf("Enter product name to update quantity: ");
    fgets(productToUpdate, sizeof(productToUpdate), stdin);
    strtok(productToUpdate, "\n");

    printf("Enter new quantity: ");
    scanf("%d", &quantityToUpdate);
    getchar();

    while (ptr != NULL && strcmp(ptr->name, productToUpdate) != 0) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Product with name %s not found!\n", productToUpdate);
    } else {
        ptr->units_in_stock = quantityToUpdate;
        printf("Product quantity updated Successfully!\n");
    }
}

void update_product_price(struct Product *ptr) {
    char productToUpdate[50];
    double priceToUpdate;

    printf("Enter product name to update price: ");
    fgets(productToUpdate, sizeof(productToUpdate), stdin);
    strtok(productToUpdate, "\n");

    printf("Enter new price: ");
    scanf("%lf", &priceToUpdate);
    getchar();

    while (ptr != NULL && strcmp(ptr->name, productToUpdate) != 0) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Product with name %s not found!\n", productToUpdate);
    } else {
        ptr->price = priceToUpdate;
        printf("Product price updated Successfully!\n");
    }
}

void delete_product(struct Product **ptr) {
    char productToDelete[50];
    
    printf("Enter product name to delete: ");
    fgets(productToDelete, sizeof(productToDelete), stdin);
    strtok(productToDelete, "\n");

    while (*ptr != NULL && strcmp((*ptr)->name, productToDelete) != 0) {
        ptr = &((*ptr)->next);
    }
    if (*ptr == NULL) {
        printf("Product with name %s not found!\n", productToDelete);
    } else {
        struct Product *temp = *ptr;
        *ptr = (*ptr)->next;
        free(temp);
        printf("Product deleted Successfully!\n");
    }
}

int main() {
    int choice;
    struct Product *product = NULL;

    do {
        printf("\nInventory Management System\n");
        printf("1. Add Product\n2. Display Products\n3. Update Product Quantity\n4. Update Product Price\n5. Delete Product\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_product(&product);
                break;
            case 2:
                display_products(product);
                break;
            case 3:
                update_product_quantity(product);
                break;
            case 4:
                update_product_price(product);
                break;
            case 5:
                delete_product(&product);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
                break;
        }
    } while (choice != 6);

    while (product != NULL) {
        struct Product *temp = product;
        product = product->next;
        free(temp);
    }

    return 0;
}
