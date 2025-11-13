//Carlos Barroca Faria e Jose Davi Silveira Gomes ex6


# include <stdio.h>

typedef struct{
  int codigo;
  char nome[50];
  float preco;
} Produto;


void insere(Produto vet[], int tam){
  for(int i = 0; i < tam; i++){
  	printf("Cadastrando o produto %d: \n\n", i+1);
    printf("Digite o codigo do produto: ");
    scanf(" %d", &vet[i].codigo); 
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", vet[i].nome);
    printf("Digite o preco do produto: ");
    scanf(" %f", &vet[i].preco);
  }

}

void gravar(Produto vet[], int tam){
	FILE *arquivo;
    arquivo = fopen("C:\Users\20251ceca0130\Documents\Produtos.bin", "wb");
    if(arquivo == NULL){
    	printf("Erro ao abrir arquivo!\n");
	}
    
}



int main() {

    int n;
    FILE *arquivo;
    arquivo = fopen("C:\Users\20251ceca0130\Documents\Produtos.bin", "wb");
    printf("Digite o numero de produtos: ");
    scanf(" %d", &n);
    Produto vet[n];
    insere(vet, n);
    
    for(int i = 0; i < n; i++){
    	printf("Codigo %d\n", vet[i].codigo);
    	printf("Nome %s\n", vet[i].nome);
    	printf("Preco %f\n", vet[i].preco);
    	printf("\n\n");
	}
	
	gravar(vet, n);
    return 0;

}
