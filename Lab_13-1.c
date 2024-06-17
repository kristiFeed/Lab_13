#include <stdio.h>
#include <stdlib.h>

int *num(int n)
{
    int *mas = (int *)malloc(n * sizeof(int));
    if (mas == NULL)
    {
        fprintf(stderr, "Помилка виділення пам'яті\n");
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        printf("mas[%d] = ", i);
        scanf("%d", &mas[i]);
    }
    return mas;
}

int Mult(int *mas, int n)
{
    if (n == 1)
    {
        return mas[0];
    }
    
    return Mult(mas, n - 1) * mas[n - 1];

}

void menu()
{
    int h, n;
    int *mas = NULL;
    do
    {
        printf("1. Задайте натуральне число n\n");
        printf("2. Обчислити добуток n чисел\n");
        printf("0. Вихід з програми\n");
        scanf("%d", &h);
        if (h == 1)
        {
            do
            {
                printf("Введіть кількість чисел; n = ");
                scanf("%d", &n);
                if (n <= 0)
                {
                    printf("Чисел повинно бути більше 0\n");
                }
            } while (n <= 0);

            if (mas != NULL)
            {
                free(mas);
            }

            mas = num(n);
        }
        else if (h == 2)
        {
            if (mas == NULL)
            {
                printf("Спочатку введіть числа\n");
            }
            else
            {
                int prod = Mult(mas, n);
                printf("Добуток чисел = %d\n", prod);
            }
        }
    } while (h != 0);
    if (mas != NULL)
    {
        free(mas);
    }
}

int main()
{
    menu();
    return 0;
}
