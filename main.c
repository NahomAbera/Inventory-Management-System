#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product{
    char name[51];
    int units_in_stock;
    double price;
    union{
        struct{
            int dimensions[3] = {0.0, 0.0, 0.0};
        };
        struct{
            char description[101];
        }
    }details;
    struct Product *next;
};

void add_product(struct Prodcut *ptr){
    while (ptr->next != NULL){
        ptr = ptr->next;
    }
    int dim_or_desc;
    ptr->next = (struct Product *) malloc(sizeof(struct Product));

    printf("Enter Product Name: ");
    fgets(ptr->name);
    
    printf("Enter Quantity: ");
    scanf("%d", &ptr->units_in_stock);
    
    printf("Enter Price: ");
    scanf("%lf", &ptr->price);

    do{
        printf("Does this product have dimensisons (1 for YES or 0 for NO): ");
        scanf("%i", &dim_or_desc);
    }while(dim_or_desc != 0 or dim_or_desc != 1);
    
    if (dim_dim_or_desc == 1){
        do{
            printf("Enter length, width, and height: ");
            scanf("%d %d %d", &ptr->details.dimensions[0],  &ptr->details.dimensions[1],  &ptr->details.dimensions[2]);
        }while(ptr->details.dimensions[0] == 0 & ptr->details.dimensions[1] == 0 & ptr->details.dimensions[2] == 0)
    }else{
        printf("Enter Product description: ");
        fgets(ptr->details.description, sizeof(ptr->details.description), stdin);
    }

    printf("Product Added Successfully!");
}

void display_products(struct Prodcut *ptr){
    printf("Name\t\tQuantity\tPrice\tDetails\n");

    while (ptr != NULL){
        if (ptr->details.description[0] != "/0"){
            printf("%s\t\t%d\t%.2lf\t%s", ptr->name, ptr->units_in_stock, ptr->price,ptr->details.description);
        }else if (ptr->details.dimensions[0] != 0 || ptr->details.dimensions[1] != 0 || ptr->details.dimensions[2] != 0 ||){
            printf("%s\t\t%d\t%.2lf\t%dx%dx%d", ptr->name, ptr->units_in_stock, ptr->price, ptr->details.dimensions[0],  ptr->details.dimensions[1],  ptr->details.dimensions[2]);
        }else{
            printf("%s\t\t%d\t%.2lf", ptr->name, ptr->units_in_stock, ptr->price);
        }
        ptr = ptr->next;
    }
}

void update_product_quantity(struct Prodcut *ptr){
    char productToUpdate[50];
    int quantityToUpdate;
    
    printf("Enter product name to update price: ");
    fgets(productToUpdate, sizeof(productToUpdate), stdin);

    printf("Enter new quantity: ");
    scanf("%d", &quantityToUpdate);

    while (strcmp(ptr->name, productToUpdate) != 0){
        ptr = ptr->next;
    }
    if (ptr == NULL){
        printf("Product with name %s not found!", productToUpdate)
    }else if ((strcmp(ptr->name, productToUpdate) == 0)){
        ptr->units_in_stock = quantityToUpdate;
        printf("Product quantity updated Successfully!");
    }
}

void update_product_price(struct Prodcut *ptr){
    char productToUpdate[50];
    int priceToUpdate;
    
    printf("Enter product name to update price: ");
    fgets(productToUpdate, sizeof(productToUpdate), stdin);

    printf("Enter new price: ");
    scanf("%d", &priceToUpdate);

    while (strcmp(ptr->name, productToUpdate) != 0){
        ptr = ptr->next;
    }
    if (ptr == NULL){
        printf("Product with name %s not found!", productToUpdate)
    }else if ((strcmp(ptr->name, productToUpdate) == 0)){
        ptr->price= priceToUpdate;
        printf("Product price updated Successfully!");
    }
}

void delete_product(struct Prodcut *ptr){
    char productToDelete[50];
    
    printf("Enter product name to delete: ");
    fgets(productToUpdate, sizeof(productToDelete), stdin);
}



int main(){
    int choice;
    struct Product product;
    product->next = NULL;
    
    do{
        choice = -1;
        do{
            printf("Inventory Management System\n");
            printf("1. Add Product\n2. Display Products\n3. Update Product Quantity\n4. Update Product Price\n5. Delete Product\n6. Exit\n");
            printf("Enter your choice: \n");
            scanf("%d", &choice);
        }while(choice != 1 || choice != 2 || choice != 3 || choice != 4 || choice != 5 || choice != 6);

        switch (choice)
        {
        case 1: add_product(&product); break;
        case 2: display_products(&product); break;
        case 3: update_product_qunatity(&product); break;
        case 4: update_product_price(&product); break;
        case 5: delete_product(&product); break;
        default: break;
        }
    } while(choice != 6);

    return 0;
}