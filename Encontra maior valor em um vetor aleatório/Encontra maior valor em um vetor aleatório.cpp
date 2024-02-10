#include <iostream>
#include <omp.h>
#include <time.h>
#include <conio.h>
#include <locale.h>

constexpr auto TAM = 10000000;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    printf("-----------ATIVIDADE 6 - CC0021-----------\n");
    printf("-----BUSCA DE MAIOR VALOR EM UM VETOR ALEATÓRIO-----\n\n");
    printf("Alocando vetor de tamanho %d\n\n", TAM);
    int* v = (int*)malloc(sizeof(int) * TAM);
    char b;
    if (v == NULL)
    {
        wprintf(L"Não foi possível alocar o vetor!\n");
        b = _getch();
        exit(0);
    }

    time_t secs;
    printf("Preenchendo vetor com valores aleatórios.\n\n");

    for (int i = 0; i < TAM; i++)
    { //preenche o vetor com valores aleatórios
        secs = time(NULL);
        v[i] = rand() % secs;
    }

    int maior = v[0]; //inicialmente, vamos assumir que o primeiro elemento do vetor é o maior
    int indice;
    clock_t inicio, fim;
    double tempo;
    inicio = clock_t();
    #pragma omp parallel
    {
        for (int i = 0; i < TAM; i++)
        {
            if (v[i] > maior) maior = v[i];
        }
    }
    fim = clock_t();
    tempo = double(fim - inicio) / double(CLOCKS_PER_SEC);
    tempo *= 1000;
    free(v);
    printf("Maior elemento encontrado: %d\n", maior);
    printf("Tempo gasto na busca: %.2lf\n", tempo);
    b = _getch();
}
