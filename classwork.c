#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int task1();
int task2();
int task3();

double fa(double x);
double fb(double x);
double cosn(double x, int N);
double coseps(double x, double eps);
float ploshad(float a, float b);
int opred();
int risunok(int a, int b, char c);

int main()
{
    setlocale(LC_ALL, ".UTF8");
    task1();
    task2();
    task3();
    return 0;
}

int task1()
{
    double x, y1, y2;
    int punkt;

    printf("Задание 1:\n");
    printf("Введите x: ");
    scanf("%lf", &x);

    y1 = fa(x);
    y2 = fb(x);
    printf("fa(x)=%.4lf , fb(x)=%.4lf\n", y1, y2);

    do
    {
        printf("\nМеню (1 - произведение, 2 - разность квадратов, 3 - удвоенная сумма, 0 - выход): ");
        scanf("%d", &punkt);

        switch (punkt)
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
    } while (punkt != 0);
    return 0;
}

int task2()
{
    double x, eps, ystd, yn, yeps;
    int N, i;

    printf("\nЗадание 2 (Вариант 3 - cos(x)):\n");
    printf("Введите x: ");
    scanf("%lf", &x);
    printf("Введите количество членов ряда N (N >= 1): ");
    scanf("%d", &N);
    printf("Введите точность eps (например, 0,0001): ");
    scanf("%lf", &eps);

    ystd = cos(x);
    yn = cosn(x, N);
    yeps = coseps(x, eps);

    printf("1) Стандартная функция cos(x) = %.6lf\n", ystd);
    printf("2) Сумма ряда cosn(x, %d)     = %.6lf\n", N, yn);
    printf("3) С точностью coseps(x, eps) = %.6lf\n", yeps);

    printf("\nТаблица сходимости:\n");
    printf("  N |   cos_N   | отклонение\n");
    printf("-----------------------------\n");
    for (i = 1; i <= N; i++)
    {
        yn = cosn(x, i);
        printf("%3d | %9.4lf | %+.4e\n", i, yn, ystd - yn);
    }
    return 0;
}

int task3()
{
    int a, b, punkt;
    float s;
    char c;

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
        scanf("%d", &punkt);

        switch (punkt)
        {
            case 1:
                s = ploshad((float)a, (float)b);
                printf("Площадь прямоугольного треугольника: %.2f\n", s);
                break;
            case 2:
                opred();
                break;
            case 3:
                printf("Введите символ для рисования: ");
                scanf(" %c", &c);
                risunok(a, b, c);
                break;
            case 0:
                printf("Завершение работы.\n");
                break;
            default:
                printf("Ошибка: неверный пункт меню\n");
                break;
        }
    } while (punkt != 0);
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

int opred()
{
    printf("Прямоугольный треугольник - это треугольник, у которого один из углов прямой (равен 90 градусам).\n");
    return 0;
}

int risunok(int a, int b, char c)
{
    int row, col, len;

    for (row = 1; row <= a; row++)
    {
        len = (row * b + a - 1) / a;
        for (col = 1; col <= len; col++)
        {
            putchar(c);
        }
        putchar('\n');
    }
    return 0;
}