#include <stdio.h>

long long combination(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    if (k > n)
        return 0;
    return combination(n - 1, k - 1) + combination(n - 1, k);   
}

long long ticket(int totalTickets, int winningTickets, int drawCount, int minWinning)
{
    long long totalWays = 0;

    for (int i = minWinning; i <= drawCount; i++)
    {
        totalWays += combination(winningTickets, i) * combination(totalTickets - winningTickets, drawCount - i);
    }

    return totalWays;
}

void menu()
{
    int totalTickets = 0;
    int winningTickets = 0;
    int drawCount = 0;
    int minWinning = 0;
    int h = -1;
    long long result;

    int totalTicketsSet = 0;
    int winningTicketsSet = 0;
    int drawCountSet = 0;
    int minWinningSet = 0;

    while (h != 0)
    {
        printf("Меню:\n");
        printf("1. Встановити загальну кількість квитків\n");
        printf("2. Встановити кількість виграшних квитків\n");
        printf("3. Встановити кількість квитків для витягування\n");
        printf("4. Встановити мінімальну кількість виграшних квитків\n");
        printf("5. Обчислити кількість способів\n");
        printf("0. Вихід\n");
        printf("Виберіть номер: ");
        scanf("%d", &h);

        switch (h)
        {
        case 1:
            printf("Введіть загальну кількість квитків: ");
            scanf("%d", &totalTickets);
            totalTicketsSet = 1;
            break;
        case 2:
            if (!totalTicketsSet)
            {
                printf("Спочатку задайте загальну кількість квитків.\n");
                break;
            }
            do
            {
                printf("Введіть кількість виграшних квитків: ");
                scanf("%d", &winningTickets);
                if (winningTickets > totalTickets)
                {
                    printf("Кількість виграшних квитків не може бути більше за загальну кількість.\n");
                }
            } while (winningTickets > totalTickets);
            winningTicketsSet = 1;
            break;
        case 3:
            if (!totalTicketsSet)
            {
                printf("Спочатку задайте загальну кількість квитків.\n");
                break;
            }
            do
            {
                printf("Введіть кількість квитків для витягування: ");
                scanf("%d", &drawCount);
                if (drawCount > totalTickets)
                {
                    printf("Кількість квитків для витягування не може бути більше за загальну кількість.\n");
                }
            } while (drawCount > totalTickets);
            drawCountSet = 1;
            break;
        case 4:
            if (!winningTicketsSet)
            {
                printf("Спочатку задайте кількість виграшних квитків.\n");
                break;
            }
            do
            {
                printf("Введіть мінімальну кількість виграшних квитків: ");
                scanf("%d", &minWinning);
                if (minWinning > winningTickets)
                {
                    printf("Мінімальна кількість виграшних квитків не може бути більше за кількість виграшних квитків.\n");
                }
            } while (minWinning > winningTickets);
            minWinningSet = 1;
            break;
        case 5:
            if (totalTicketsSet && winningTicketsSet && drawCountSet && minWinningSet)
            {
                result = ticket(totalTickets, winningTickets, drawCount, minWinning);
                printf("Кількість способів витягнути %d квитків, щоб принаймні %d з них були виграшними: %lld\n", drawCount, minWinning, result);
            }
            else
            {
                printf("Задайте всі параметри перед обчисленням.\n");
            }
            break;
        case 0:
            printf("Вихід з програми.\n");
            break;
        default:
            printf("Неправильний вибір\n");
            break;
        }
    }
}

int main()
{
    menu();

    return 0;
}
