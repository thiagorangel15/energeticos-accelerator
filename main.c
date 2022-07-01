#include <stdio.h>
#include <string.h>

float calculoICMS (float valorTotal);
float calculoIPI (float valorTotal);
float calculoPIS (float valorTotal);
float calculoCOFINS (float valorTotal);
void app();


float valorEnergetico = 4.5;


int main(void) {
 app();
  return 0;
}

float calculoICMS (float valorTotal){
  return valorTotal*0.18;
}
float calculoIPI (float valorTotal){
  return valorTotal*0.04;
}
float calculoPIS (float valorTotal){
  return valorTotal*0.0186;
}
float calculoCOFINS (float valorTotal){
  return valorTotal*0.0854;
}

void app(){
  char nomeCliente[200];
  int quantidadeComprada;
  printf("Digite o nome do cliente: ");
  gets(nomeCliente);

  printf("Digite a quantidade comprada de produtos: ");
  scanf("%d",&quantidadeComprada);

  float valorTotalSemImposto = valorEnergetico * (float)quantidadeComprada;
  float ICMS = calculoICMS(valorTotalSemImposto);
  float IPI = calculoIPI(valorTotalSemImposto);
  float PIS = calculoPIS(valorTotalSemImposto);
  float COFINS = calculoCOFINS(valorTotalSemImposto);
  float totalImpostos = ICMS + IPI + PIS + COFINS;
  float valorTotal = valorTotalSemImposto + totalImpostos;

  printf("\nNome do cliente: ");
  for(int i=0 ; i<=strlen(nomeCliente); i++){
    printf("%c",nomeCliente[i]);
  }
  printf(";");
  
  printf("\nICMS: R$%.2f;",ICMS);
  printf("\nIPI: R$%.2f;",IPI);
  printf("\nPIS : R$%.2f;",PIS);
  printf("\nCOFINS : R$%.2f;",COFINS);
  printf("\n\nTotal Impostos: R$%.2f",totalImpostos);
  printf("\nTotal Mercadorias: R$%.2f",valorTotalSemImposto);
  printf("\nTotal Geral: R$%.2f",valorTotal);
  if(quantidadeComprada > 1000){
    float desconto = valorTotal * 0.85;
    printf("\nCompras acima de 1000 produtos recebem 15 porcento de desconto no valor total, novo valor: R$%.2f",desconto);
  }
  
  
}
