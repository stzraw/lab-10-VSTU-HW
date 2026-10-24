#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

double fa(double x);
double fb(double x);
double cosn(double x, int N);
double coseps(double x, double eps);
float ploshad(float a, float b);
int opred(int a, int b);
char risunok(int row, int col, int a, int b, char c);

int main()
{
    double x1, y1, y2;
    int punkt1;
    double x2, eps, ystd, yn, yeps;
    int N, i;
    int a, b, punkt3, row, col, isravn;
    float s;
    char c, ch;

    setlocale(LC_ALL, ".UTF8");

    printf("Задание 1:\n");
    printf("Введите x: ");
    scanf("%lf", &x1);

    y1 = fa(x1);
    y2 = fb(x1);
    printf("fa(x)=%.4lf , fb(x)=%.4lf\n", y1, y2);

    do
    {
        printf("\nМеню (1 - произведение, 2 - разность квадратов, 3 - удвоенная сумма, 0 - выход): ");
        scanf("%d", &punkt1);

        switch (punkt1)
        {
            case 1:
                printf("произведение: %.4lf\n", y1 * y2);
                break;
            case 2:
                printf("разность квадратов: %.4lf\n", pow(y1, 2) - pow(y2, 2));
                break;
            case 3:
                printf("удвоенная сумма: %.4lf\n", 2.0 * (y1 + y2));
                break;
            case 0:
                printf("Выход из меню задания 1\n");
                break;
            default:
                printf("Ошибка: неверный пункт меню\n");
                break;
        }
    } while (punkt1 != 0);

    printf("\nЗадание 2 (Вариант 3 - cos(x)):\n");
    printf("Введите x: ");
    scanf("%lf", &x2);
    printf("Введите количество членов ряда N (N >= 1): ");
    scanf("%d", &N);
    printf("Введите точность eps (eps > 0, например, 0,0001): ");
    scanf("%lf", &eps);

    if (N < 1 || eps <= 0.0)
    {
        printf("Ошибка: должно выполняться N >= 1 и eps > 0\n");
    }
    else
    {
        ystd = cos(x2);
        yn = cosn(x2, N);
        yeps = coseps(x2, eps);

        printf("1) Стандартная функция cos(x) = %.6lf\n", ystd);
        printf("2) Сумма ряда cosn(x, %d)     = %.6lf\n", N, yn);
        printf("3) С точностью coseps(x, eps) = %.6lf\n", yeps);

        printf("\nТаблица сходимости:\n");
        printf("  N |   cos_N   | отклонение\n");
        printf("-----------------------------\n");
        for (i = 1; i <= N; i++)
        {
            yn = cosn(x2, i);
            printf("%3d | %9.4lf | %+.4e\n", i, yn, ystd - yn);
        }
    }

    printf("\nЗадание 3 (ДЗ - Прямоугольный треугольник):\n");
    printf("Введите катет a (высоту): ");
    scanf("%d", &a);
    printf("Введите катет b (ширину): ");
    scanf("%d", &b);

    if (a <= 0 || b <= 0)
    {
        printf("Ошибка: стороны должны быть положительными\n");
        return 0;
    }

    do
    {
        printf("\nМеню операций:\n");
        printf("1 - рассчитать площадь\n");
        printf("2 - вывести определение фигуры\n");
        printf("3 - нарисовать фигуру\n");
        printf("0 - выход из программы\n");
        printf("Выберите операцию: ");
        scanf("%d", &punkt3);

        switch (punkt3)
        {
            case 1:
                s = ploshad((float)a, (float)b);
                printf("Площадь прямоугольного треугольника: %.2f\n", s);
                break;
            case 2:
                isravn = opred(a, b);
                printf("Прямоугольный треугольник - это треугольник, у которого один из углов прямой (90 градусов).\n");
                printf("Вид по сторонам: %s\n", (isravn == 1) ? "равнобедренный (a = b)" : "разносторонний (a != b)");
                break;
            case 3:
                printf("Введите символ для рисования: ");
                scanf(" %c", &c);
                for (row = 1; row <= a; row++)
                {
                    for (col = 1; col <= b; col++)
                    {
                        ch = risunok(row, col, a, b, c);
                        putchar(ch);
                    }
                    putchar('\n');
                }
                break;
            case 0:
                printf("Завершение работы.\n");
                break;
            default:
                printf("Ошибка: неверный пункт меню\n");
                break;
        }
    } while (punkt3 != 0);
    return 0;
}

double fa(double x)
{
    double y;

    if (x <= 3.0)
    {
        y = pow(x, 2) - 3.0 * x + 9.0;
    }
    else
    {
        y = 1.0 / (pow(x, 3) + 3.0);
    }
    return y;
}

double fb(double x)
{
    double y;

    y = x * exp(sin(pow(x, 2)));
    return y;
}

double cosn(double x, int N)
{
    int k;
    double sum, t;

    sum = 1.0;
    t = 1.0;
    for (k = 1; k < N; k++)
    {
        t = -t * x * x / ((2.0 * k - 1.0) * (2.0 * k));
        sum += t;
    }
    return sum;
}

double coseps(double x, double eps)
{
    int k;
    double sum, t;

    sum = 1.0;
    t = 1.0;
    k = 1;
    while (fabs(t) > eps)
    {
        t = -t * x * x / ((2.0 * k - 1.0) * (2.0 * k));
        sum += t;
        k++;
    }
    return sum;
}

float ploshad(float a, float b)
{
    float s;

    s = 0.5f * a * b;
    return s;
}

int opred(int a, int b)
{
    if (a == b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char risunok(int row, int col, int a, int b, char c)
{
    int len;

    len = (row * b + a - 1) / a;
    if (col <= len)
    {
        return c;
    }
    else
    {
        return ' ';
    }
}
