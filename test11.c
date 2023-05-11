#define MAX_LIST_SIZE 100

#include <stdio.h>
#include <stdlib.h>

typedef int element ;

typedef struct{
    element array[MAX_LIST_SIZE] ;
    int size ;
} ArrayListType ;

void error(char *message) {
    fprintf(stderr, "%s\n", message) ;
}

void init(ArrayListType *Lptr) {
    Lptr -> size = 0 ;
}

int is_empty(ArrayListType *Lptr) {
    return Lptr -> size == 0 ;
}

int is_full(ArrayListType *Lptr) {
    return Lptr -> size == MAX_LIST_SIZE ;
}

void insert(ArrayListType *Lptr, int pos, element item) {
    if(is_full(Lptr) || pos < 0 || pos > Lptr -> size) {
        error("List is Full") ;
    }
    else {
        for(int i=(Lptr->size-1); i>=pos; i--) {
            Lptr -> array[i+1] = Lptr -> array[i] ;
        }
        Lptr -> array[pos] = item ;
        Lptr -> size++ ;
    }
}

element delete(ArrayListType *Lptr, int pos) {
    element item ;
    int cnt = 0 ;

    if(is_empty(Lptr) || pos < 0 || pos >= Lptr -> size) {
        error("List is Empty") ;
    }
    else {
		for(int i=pos; i<(Lptr->size-1); i++) {
			Lptr -> array[i] = Lptr -> array[i+1] ;
            cnt++ ;
		}
		Lptr -> size-- ;
	}
    return item ;
}
        
void print_list(ArrayListType *Lptr) {
    int i ;
    
    for(i=0; i<Lptr->size; i++) {
        printf("%d -> ", Lptr -> array[i]) ;
    }
    printf("\n") ;
}

int main() {
    int insert_menu ;
    ArrayListType L ;
    init(&L) ;

    while(1) {
        printf("Menu\n") ;
        printf("1. Insert\n") ;
        printf("2. Delete\n") ;
        printf("3. Print\n") ;
        printf("4. Exit\n") ;
        printf("Enter the menu : ") ;

        scanf("%d", &insert_menu) ;

        if(insert_menu == 1) {
            int n, p ;
            printf("Enter the number and position : ") ;
            scanf("%d %d", &n, &p) ;
            if(L.size == 0) {
                while(p != 0) {
                    printf("List size is zero. Please enter again(number, postion) : ") ;
                    scanf("%d %d", &n, &p) ;
                }
            }
            else {
                insert(&L, n, p) ;
            }
        }
        else if(insert_menu == 2) {
            if(is_empty(&L)) {
                error("List is Empty\n") ;
            }
            else {
                int p ;
                printf("Enter the position : ") ;
                scanf("%d", &p) ;
                delete(&L, p) ;
            
            }
        }
        else if(insert_menu == 3) {
            print_list(&L) ;
        }
        else if(insert_menu == 4) exit(1) ;
        else error("Invaild Menu. Please select again") ;
    }


    return 0 ;
}