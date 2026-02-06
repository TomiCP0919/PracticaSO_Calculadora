#include "stdio.h"
#include "math.h"
#include "stdbool.h"

float pila[8];
int Tope_pila = -1;

void ImprimirStack(void)
{
    int i = 0;
    for (i = 0; i < 8; i++)
    {
        printf("%d", 8 - i);
        printf(") ");
        printf("%f", pila[i]);
        printf("\n");
    }
}

void push(float numero_ingreso_pila)
{
    if (Tope_pila < 7)
        pila[++Tope_pila] = numero_ingreso_pila;
    else
        printf("Error: pila llena\n");
}
float pop(void)
{

    if (Tope_pila >= 0)
        return pila[Tope_pila--];
    else
    {
        printf("Error: pila vacia\n");
        return 0;
    }
}

float suma(void)
{
}

int main()
{
    int seleccion_proceso;
    bool entrada = true;

    while (entrada)
    {
        ImprimirStack();
        printf("\n Bienvenido a tu Calculadora RPM (Pila), escoge que quieres realizar dentro de la claculadora: \n");
        printf("1. Añadir valor a la pila de la calculadora \n");
        printf("2. Escoger una operación de calculadora \n");
        printf("3. Limpiar ultimo valor de de la pila de la calculadora \n");
        printf("4. Limpiar todos los valores de la pila de la calculadora \n");
        printf("5. Salir de la calculadora\n");
        scanf("%d", &seleccion_proceso);

        if (seleccion_proceso == 1)
        {
            float valor;
            printf("Ingrese el valor que quiere agregar a la pila de la calculadora: \n");
            scanf("%f", &valor);
            push(valor);
            int seleccion_proceso;
        }
        else if (seleccion_proceso == 2)
        {
            char operacion;
            float a;
            float b;
            float valor_grados;
            float valor_radianes;
            float PI;

            printf("Seleccione que operación desea realizar con los ultimos dos valores de la calculadora de pila: \n");
            printf("+ para suma \n");
            printf("- para resta \n");
            printf("/ para division \n");
            printf("* para multiplicación \n");
            printf("r para raíz cuadrada \n");
            printf("p para potencia \n");
            printf("c para coseno \n");
            printf("s para seno \n");
            printf("t para tangente \n");
            scanf(" %c", &operacion);

            switch (operacion)
            {
            case '+':
                if (Tope_pila < 1)
                {
                    printf("Error: no hay suficientes operandos \n");
                    break;
                }
                else
                {
                    b = pop();
                    a = pop();

                    push(a + b);
                    break;
                }

            case '-':
                if (Tope_pila < 1)
                {
                    printf("Error: no hay suficientes operandos \n");
                    break;
                }
                else
                {

                    b = pop();
                    a = pop();
                    push(a - b);
                    break;
                }

            case '*':

                if (Tope_pila < 1)
                {
                    printf("Error: no hay suficientes operandos \n");
                    break;
                }
                else
                {
                    b = pop();
                    a = pop();
                    push(a * b);
                    break;
                }

            case '/':

                if (Tope_pila < 1)
                {
                    printf("Error: no hay suficientes operandos \n");
                    break;
                }
                else
                {
                    if (b == 0)
                    {
                        printf("Error: Division por 0");
                    }
                    else
                    {
                        b = pop();
                        a = pop();
                        push(a / b);
                        break;
                    }
                }

            case 'r':
                if (Tope_pila < 0)
                {
                    printf("Error: pila vacia \n");
                    break;
                }
                else
                {

                    a = pop();
                    if (a < 0)
                    {
                        printf("Error: Raiz de numero negativo \n");
                        push(a);
                    }
                    else
                    {
                        push(sqrt(a));
                        break;
                    }
                }
                break;

            case 'p':
                if (Tope_pila < 1)
                {
                    printf("Error: no hay suficientes operandos \n");
                    break;
                }
                else
                {
                    b = pop(); // exponente
                    a = pop(); // base
                    push(pow(a, b));
                    break;
                }

            case 'c':
                PI = 3.1416;

                if (Tope_pila < 0)
                {
                    printf("Error: pila vacia\n");
                    break;
                }
                valor_grados = pop();
                valor_radianes = valor_grados * (PI / 180.0);
                push(cos(valor_radianes));
                break;

            case 's':
                PI = 3.1416;

                if (Tope_pila < 0)
                {
                    printf("Error: pila vacia\n");
                    break;
                }
                valor_grados = pop();
                valor_radianes = valor_grados * (PI / 180.0);
                push(sin(valor_radianes));
                break;

            case 't':
                PI = 3.1416;
                if (Tope_pila < 0)
                {
                    printf("Error: pila vacia\n");
                    break;
                }
                valor_grados = pop();

                if (fmod(valor_grados, 180) == 90)
                {
                    printf("Error: tangente indefinida\n");
                    push(valor_grados);
                }
                else
                {
                    valor_radianes = valor_grados * (PI / 180.0);
                    push(tan(valor_radianes));
                }
                break;

            default:
                printf("La operación que seleccionó no esta disponible en la calculadora RPM \n");
                break;
            }
        }
        else if (seleccion_proceso == 3)
        {
            pop();
        }
        else if (seleccion_proceso == 4)
        {
            Tope_pila = -1;
        }
        else if (seleccion_proceso == 5)
        {
            printf("Gracias por utilizar la calculadora RPM \n");
            entrada = false;
        }
        else
        {
            printf("Esta no es una opcion dentro de la calculadora \n");
            entrada;
        }
    }
    return 0;
}
