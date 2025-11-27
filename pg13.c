#include <stdio.h>

#define SIZE 8   

void displaySet(int set) {
    printf("{ ");
    for (int i = 0; i < SIZE; i++) {
        if (set & (1 << i)) 
            printf("%d ", i);
    }
    printf("}");
}

int createSet() {
    int n, element, set = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements (0 to %d): ", SIZE - 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        if (element >= 0 && element < SIZE)
            set |= (1 << element);  
    }
    return set;
}
int main() {
    int setA, setB, unionSet, interSet, compSet;

    printf("Create Set A:\n");
    setA = createSet();

    printf("\nCreate Set B:\n");
    setB = createSet();

   
    unionSet = setA | setB;

    
    interSet = setA & setB;

  
    compSet = (~setA) & ((1 << SIZE) - 1);

    printf("\nSet A = ");
    displaySet(setA);
    printf("\nSet B = ");
    displaySet(setB);

    printf("\n\nUnion (A ∪ B) = ");
    displaySet(unionSet);

    printf("\nIntersection (A ∩ B) = ");
    displaySet(interSet);

    printf("\nComplement (~A) = ");
    displaySet(compSet);

    printf("\n");
    return 0;
}

