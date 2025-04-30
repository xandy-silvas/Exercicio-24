#include <stdio.h>

int particionar(int arr[], int baixo, int alto) {
    int pivo = arr[alto];
    int i = (baixo - 1);
    
    for (int j = baixo; j <= alto - 1; j++) {
        if (arr[j] <= pivo) {
            i++;
            
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[i + 1];
    arr[i + 1] = arr[alto];
    arr[alto] = temp;
    
    return (i + 1);
}

void quick_sort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto);
        
        quick_sort(arr, baixo, pi - 1);
        quick_sort(arr, pi + 1, alto);
    }
}

int main() {
    int n, i;
    
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int arr[n];
    
    printf("Digite os %d elementos do array:\n", n);
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
  
    
    quick_sort(arr, 0, n - 1);
    
    printf("Array ordenado: [");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
    
    return 0;
}
