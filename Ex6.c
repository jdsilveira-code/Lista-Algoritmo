//Carlos Barroca Faria e Jose Davi Silveira Gomes ex6

# include <stdio.h>
# include <stdlib.h>

typedef struct{
  int codigo;
  char nome[50];
  float preco;
} Produto;


void insere(Produto vet[], int tam){
  for(int i = 0; i < tam; i++){
  	printf("\nCadastrando o produto %d: \n\n", i+1);
    printf("Digite o codigo do produto: ");
    scanf(" %d", &vet[i].codigo); 
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", vet[i].nome);
    printf("Digite o preco do produto: ");
    scanf(" %f", &vet[i].preco);
  }

}

void gravar(int tam) {
    FILE *arquivo;
    int itens_escritos;

    // 1. Abertura do Arquivo
    arquivo = fopen("Produtos.bin", "wb");
    if (arquivo == NULL) {
        printf("\nErro ao abrir arquivo para escrita!\n");
        exit(1);
    }

    // 2. Grava o inteiro 'tam'
    itens_escritos = (int)fwrite(&tam, sizeof(int), 1, arquivo);

    // 3. Checagem de Erro CORRIGIDA: Verifica se o retorno NÃO foi 1 (sucesso)
    if (itens_escritos != 1) { 
        printf("\nErro ao escrever o tamanho do array no cabecalho. Escrito: %d\n", itens_escritos);
    } else {
        // Mensagem opcional de sucesso
        printf("\nTamanho (%d) gravado com sucesso no cabecalho.\n", tam);
    }

    // 4. Fechamento do Arquivo
    int resultado = fclose(arquivo);
    if (resultado != 0) {
        printf("\nErro ao fechar arquivo.");
    }
}


int main() {
    int n;
    printf("Digite o numero de produtos: ");
    scanf(" %d", &n);
    Produto vet[n];
    //insere(vet, n);
    gravar(n);
    
    for(int i = 0; i < n; i++){
    	printf("\nCodigo %d\n", vet[i].codigo);
    	printf("Nome %s\n", vet[i].nome);
    	printf("Preco %.2f\n", vet[i].preco);
    	printf("\n\n");
	}
	
  return 0;

}
