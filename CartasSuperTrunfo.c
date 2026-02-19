#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

// Função para Calcular o PIB per Capita
float calcularPIBperCapita(float PIB, int populacao) {
    return (float) PIB / populacao;
}
 
// Função para Calcular a Densidade Populacional
float calcularDensidade(int populacao, float area) {
    return (float) populacao / area;
}

// Função para exibir comparação entre as cartas
void exibirComparacao(float C1densidade, float C2densidade, float C1area, float C1PIB, 
    float C2area, float C2PIB, float C1perCapita, float C2perCapita,
    int C1populacao, int C2populacao, int C1pontosTuristico, int C2pontosTuristico)
    {
    
    double somaC1 = C1populacao + C1area + C1PIB +
               C1pontosTuristico + C1densidade + C1perCapita;

    double somaC2 = C2populacao + C2area + C2PIB +
                C2pontosTuristico + C2densidade + C2perCapita;

    double resultadoSoma = (somaC1 > somaC2) ? somaC1 : somaC2;

    printf("\nComparação de Cartas: Carta %d Venceu\n",
          (somaC1 > somaC2) ? 1 : 2);
    printf("População: Carta %d venceu\n",
           (C1populacao > C2populacao) ? 1 : 2);
    printf("Área: Carta %d venceu\n",
           (C1area > C2area) ? 1 : 2);
    printf("PIB: Carta %d venceu\n",
           (C1PIB > C2PIB) ? 1 : 2);
    printf("Pontos Turísticos: Carta %d venceu\n",
           (C1pontosTuristico > C2pontosTuristico) ? 1 : 2);
    printf("Densidade Populacional: Carta %d venceu\n",
           (C1densidade < C2densidade) ? 1 : 2);
    printf("PIB per Capita: Carta %d venceu\n",
           (C1perCapita > C2perCapita) ? 1 : 2);
    printf("Super Poder: %.f, carta %d venceu\n", resultadoSoma, 
           (somaC1 > somaC2) ? 1 : 2);
}

int main() {
  // Área para definição das variáveis para armazenar as propriedades das cidades
  char C1estado[4], C1cidade[20], C1letra, C2estado[4], C2cidade[20], C2letra;
  int C1pontosTuristico, C2pontosTuristico;
  unsigned long int C1populacao, C2populacao;
  float C1area, C1PIB, C2area, C2PIB, C1perCapita, C2perCapita, C1densidade, C2densidade; 
  
  // Área para entrada de dados
  // CARTA 1
  printf("Digite a letra do Estado de 'A' a 'H' da carta 1: ");
  scanf(" %c", &C1letra);

  printf("Digite o código do Estado de 01 a 04 (ex: A01, B03) da carta 1: ");
  scanf("%s", C1estado);
  getchar();  // limpa o ENTER do buffer

  printf("Digite o nome da cidade da carta 1: ");
  fgets(C1cidade, 20, stdin); // pegar cidades que não só um nome
  C1cidade[strcspn(C1cidade, "\n")] = 0; // removendo a quebra de linha do fgets

  printf("Digite a população da cidade de acordo com o último senso da carta 1: ");
  scanf("%d", &C1populacao);

  printf("Quantos pontos turístico tem na cidade da carta 1? ");
  scanf("%d", &C1pontosTuristico);

  printf("Qual área (em km²) na cidade da carta 1? ");
  scanf("%f", &C1area);

  printf("Qual é o PIB da cidade da carta 1? ");
  scanf("%f", &C1PIB);
  
  // CARTA 2
  printf("Digite a letra do Estado de 'A' a 'H' da carta 2: ");
  scanf(" %c", &C2letra);

  printf("Digite o código do Estado de 01 a 04 (ex: A01, B03) da carta 2: ");
  scanf("%s", C2estado);
  getchar();  // limpa o ENTER do buffer

  printf("Digite o nome da cidade da carta 2: ");
  fgets(C2cidade, 20, stdin); // pegar cidades que não só um nome
  C2cidade[strcspn(C2cidade, "\n")] = 0; // removendo a quebra de linha do fgets

  printf("Digite a população da cidade de acordo com o último senso da carta 2: ");
  scanf("%d", &C2populacao);

  printf("Quantos pontos turístico tem na cidade da carta 2? ");
  scanf("%d", &C2pontosTuristico);

  printf("Qual área (em km²) na cidade da carta 2? ");
  scanf("%f", &C2area);

  printf("Qual é o PIB da cidade da carta 2? ");
  scanf("%f", &C2PIB);

  // informações de Renda per capita e densidade da carta 1
  C1densidade = calcularDensidade(C1populacao, C1area);
  C1perCapita = calcularPIBperCapita(C1PIB, C1populacao);

  // informações de Renda per capita e densidade da carta 2
  C2densidade = calcularDensidade(C2populacao, C2area);
  C2perCapita = calcularPIBperCapita(C2PIB, C2populacao);


  // Área para exibição dos dados da cidade
  // PRINTs DA CARTA 1
  printf("\nCarta 1\n");
  printf("Estado: %c\n", C1letra);
  printf("Código: %c%s\n", C1letra, C1estado);
  printf("Cidade: %s\n", C1cidade);
  printf("População: %d\n", C1populacao);
  printf("Área: %.2f km²\n", C1area);
  printf("PIB: %.2f bilhões de reais\n", C1PIB);
  printf("Número de Pontos Turísticos: %d\n", C1pontosTuristico);
  printf("Densidade Populacional: %.2f hab/km²\n", C1densidade);
  printf("PIB per Capita: %.2f reais\n", C1perCapita);

  // PRINTs DA CARTA 2
  printf("\nCarta 2\n");
  printf("Estado: %c\n", C2letra);
  printf("Código: %c%s\n", C2letra, C2estado);
  printf("Cidade: %s\n", C2cidade);
  printf("População: %d\n", C2populacao);
  printf("Área: %.2f km²\n", C2area);
  printf("PIB: %.2f bilhões de reais\n", C2PIB);
  printf("Número de Pontos Turísticos: %d\n", C2pontosTuristico);
  printf("Densidade Populacional: %.2f hab/km²\n", C2densidade);
  printf("PIB per Capita: %.2f reais\n", C2perCapita);

  // chamando função para exibir comparação entre as cartas
  exibirComparacao(C1densidade, C2densidade, C1area, C1PIB, C2area, C2PIB,
    C1perCapita, C2perCapita, C1populacao, C2populacao, C1pontosTuristico, C2pontosTuristico);

  return 0;
} 
