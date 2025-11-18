#include <stdio.h>
#include <math.h>
#include <locale.h>
#define N 1000  


double* full_elements(double* ptr_array, int n) {
    printf("Заполнение массива...\n");
    for (int i = 0; i < n; i++) {
        
        double x = i * 0.1;  
        ptr_array[i] = x * x + sin(x);
    }
    return ptr_array;
}


int put_elements(double* ptr_array, int n) {
    printf("Элементы массива:\n");
    for (int i = 0; i < n; i++) {
        printf("array[%d] = %.3f\n", i, ptr_array[i]);
    }
    return n;  
}


double* calc_elements(double* ptr_array, int n) {
    printf("Обработка элементов массива...\n");

    
    double sum_positive = 0.0;
    double sum_negative = 0.0;
    int count_positive = 0;
    int count_negative = 0;

    for (int i = 0; i < n; i++) {
        if (ptr_array[i] > 0) {
            sum_positive += ptr_array[i];
            count_positive++;
        }
        else if (ptr_array[i] < 0) {
            sum_negative += ptr_array[i];
            count_negative++;
        }
    }

    printf("Сумма положительных элементов: %.3f\n", sum_positive);
    printf("Сумма отрицательных элементов: %.3f\n", sum_negative);
    printf("Количество положительных элементов: %d\n", count_positive);
    printf("Количество отрицательных элементов: %d\n", count_negative);

    if (count_positive > 0) {
        printf("Среднее положительных: %.3f\n", sum_positive / count_positive);
    }

    return ptr_array;
}

int main() {
    setlocale(LC_CTYPE, "RUS");
    double array[N];
    int size;

    printf("Введите размер массива > ");
    scanf("%d", &size);

    
    if (size <= 0 || size > N) {
        printf("Ошибка: размер должен быть от 1 до %d\n", N);
        return 1;
    }

    
    full_elements(array, size);
    put_elements(array, size);

    
    calc_elements(array, size);

    return 0;
}