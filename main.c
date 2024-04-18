#include <stdio.h>
#include <stdlib.h>

struct Product{
    char name[51];
    int units_in_stock;
    double price;
    union{
        struct{
            double dimensions[3];
        };
        struct{
            char description[101];
        }details;
    };
    struct Product *next;
};

void add_product(struct Prodcut *ptr){
    while (ptr->next != NULL){
        ptr = ptr->next;
    }
    int dim_or_desc;
    ptr->next = (struct Product *) malloc(sizeof(struct Product));
    printf("Enter Product Name: ");
    scanf("%s", ptr->name);
    printf("Enter Quantity: ");
    scanf("%d", &ptr->units_in_stock);
    printf("Enter Price: ");
    scanf("%lf", &ptr->price);
    do{
        printf("Does this product have dimensisons (1 for YES or 0 for NO): ");
        scanf("%i", &dim_or_desc);
    }while(dim_or_desc != 0 or dim_or_desc != 1);
    if (dim_dim_or_desc == 1){
        printf("Enter length, width, and height: ");
        scanf("%lf %lf %fl", &ptr->details.dimensions[0],  &ptr->details.dimensions[1],  &ptr->details.dimensions[2]);
    }else{
        printf("Enter Product description: ");
        fgets(ptr->details.description, sizeof(ptr->details.description), stdin);
    }
}

void display_products(struct Prodcut *ptr){
    
}

void update_product_quantity(struct Prodcut *ptr){
}

void update_product_price(struct Prodcut *ptr){
}

void delete_product(struct Prodcut *ptr){
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
            printf("Enter your choice: ");
            scanf("%d", &choice);
        }while(choice != 1 or choice != 2 or choice != 3 or choice != 4 or choice != 5 || choice != 6);

        switch (choice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            break;
        }
    } while(choice != 6);

    return 0;
}