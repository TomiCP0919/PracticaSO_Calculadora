#include "stdio.h"
#include "math.h"
#include "stdbool.h"

float pila[8];

void Imprimirpila(void)
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
void vaciarPilacompleta(void)
{
    for (int i = 0; i < 8; i++)
    {
        pila[i] = 0;
    }
}

void push(float numero)
{
    int i;

    for (i = 0; i < 7; i++)
    {
        pila[i] = pila[i + 1];
    }

    pila[7] = numero;
}
float pop(void)
{
    float valor = pila[7];
    int i;

    for (i = 7; i > 0; i--)
    {
        pila[i] = pila[i - 1];
    }

    pila[0] = 0;
    return valor;
}

int main()
{
    int seleccion_proceso;
    bool entrada = true;

    while (entrada)
    {

        printf("\n");
        printf("\n");
        Imprimirpila();
        printf("\n Bienvenido a tu Calculadora RPM (Pila), escoge que quieres realizar dentro de la calculadora: \n");
        printf("1. Añadir valor a la pila de la calculadora \n");
        printf("2. Escoger una operación de calculadora \n");
        printf("3. Limpiar ultimo valor de de la pila de la calculadora \n");
        printf("4. Limpiar todos los valores de la pila de la calculadora \n");
        printf("5. Salir de la calculadora\n");
        printf("Seleccione la opcion a realizar: ");
        scanf("%d", &seleccion_proceso);

        if (seleccion_proceso == 1)
        {
            float valor;
            printf("Ingrese el valor que quiere agregar a la pila de la calculadora: ");
            if (scanf("%f", &valor) == 1)
            {
                push(valor);
            }
            else
            {

                printf("Error: solo se permiten numeros\n");
                while ((seleccion_proceso = getchar()) != '\n' && seleccion_proceso != EOF)
                    ;
            }
        }
        else if (seleccion_proceso == 2)
        {
            char operacion;
            float a;
            float b;
            float valor_grados;
            float valor_radianes;
            float PI = 3.1416;

            printf("\n");
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
            printf("Operación: ");
            scanf(" %c", &operacion);

            switch (operacion)
            {
            case '+':
                if (pila[7] == 0 && pila[6] == 0)
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
                if (pila[7] == 0 && pila[6] == 0)
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

                if (pila[7] == 0 && pila[6] == 0)
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
                if (pila[7] == 0 && pila[6] == 0)
                {
                    printf("Error: no hay suficientes operandos \n");
                    break;
                }

                b = pop();
                if (b == 0)
                {
                    printf("Error: Division por 0\n");
                    push(b);
                    break;
                }

                a = pop();
                push(a / b);
                break;

            case 'r':
                if (pila[7] == 0)
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
                if (pila[7] == 0 && pila[6] == 0)
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

                valor_grados = pop();
                valor_radianes = valor_grados * (PI / 180.0);
                push(cos(valor_radianes));
                break;

            case 's':

                valor_grados = pop();
                valor_radianes = valor_grados * (PI / 180.0);
                push(sin(valor_radianes));
                break;

            case 't':

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
            vaciarPilacompleta();
        }
        else if (seleccion_proceso == 5)
        {
            printf("Gracias por utilizar la calculadora RPM \n");
            entrada = false;
        }
        else
        {
            printf("Esta no es una opcion dentro de la calculadora \n");
            int seleccion_proceso;
            while ((seleccion_proceso = getchar()) != '\n' && seleccion_proceso != EOF)
                ;
        }
    }
    return 0;
}
