//
//  Clientes.c
//  Trabalho_EDA
//
//  Created by Margarida Rodrigues on 06/03/2023.
//
#include "TrabalhoPratico.h"
/* Menu cliente */
void menuCliente(){
    printf("\nSelecione uma opcao:\n");
    printf("1 - Alugar um meio de mobilidade eletrica\n");
    printf("2 - Terminar a utilização de um meio de mobilidade eletrica\n");
    printf("3 - Listar meios de mobilidade eletrica por ordem decrescente de autonomia\n");
    printf("4 - Listar meios de mobilidade eletrica existentes num determinado geocodigo\n");
    printf("5 - Alterar dados pessoais\n");
    printf("0 - Sair\n");
}

/* Metodo que mostra na consola o conteúdo da lista ligada de clientes */
void listarClientes(Cliente * inicio){
    while (inicio != NULL){
        printf("%ld %s %s %.2f\n",inicio->nif,inicio->nome,inicio->morada, inicio->saldo);
        inicio = inicio->seguinte;
    }
}

/* Metodo que determina a existência do codigo de cliente(NIF) na lista ligada de clientes */
int existeCliente(Cliente* inicio, int nif){
    while(inicio!=NULL){
        if (inicio->nif == nif) return(1);
        inicio = inicio->seguinte;
    }
    return(0);
}

/* ALINEA 2 - Armazenamento/leitura dos dados em ficheiro de texto */
/* Metodo para armazenamento de dados de meios de clientes */
int guardarClientes(Cliente* inicio){
    FILE* fp;
    fp = fopen("clientes.txt","w");
    if (fp!=NULL){
        Cliente* aux= inicio;
        while (aux != NULL){
            fprintf(fp,"%ld %s %s %.2f\n",inicio->nif,inicio->nome,inicio->morada, inicio->saldo);
            aux = aux->seguinte;
        }
        fclose(fp);
        return(1);
    }
    else return(0);
}

/* Metodo para leitura de dados de clientes */
Cliente* lerClientes(){
    FILE* fp;
    long nif;
    char nome[TAM], morada[TAM];
    float saldo;
    Cliente* aux=NULL;
    fp = fopen("clientes.txt","r");
    if (fp!=NULL){
        while (!feof(fp)){
            fscanf(fp,"%ld;%[^\n]s;%[^\n]s,%f\n", &nif, nome, morada, &saldo);
            aux = inserirCliente(aux, nif, nome, morada, saldo);
        }
        fclose(fp);
    }
    return(aux);
}

/* ALINEA 3 - Inserção de novos dados */
/* Metodo que permite inserir um cliente */
Cliente* inserirCliente(Cliente * inicio, int nif, char nome[], char morada[], float saldo){
    if (!existeCliente(inicio, nif)){
        Cliente * novo = malloc(sizeof(struct Cliente));
        if (novo != NULL){
            novo->nif = nif;
            strcpy(novo->nome,nome);
            strcpy(novo->morada,morada);
            novo->saldo = saldo;
            novo->seguinte = inicio;
            return(novo);
        }
    }return(inicio);
}

/* ALINEA 4 - Remoção de um determinado dado */
/* Remover um cliente a partir do seu código de identificação (NIF) */
Cliente* removerCliente(Cliente* inicio, int nif){
    Cliente *anterior=inicio, *atual=inicio, *aux;
    if (atual==NULL) return(NULL);
    else if (atual->nif == nif){ // remoção do 1º registo
        aux = atual->seguinte;
        free(atual);
        return(aux);
    }
    else{
        while ((atual!=NULL)&&(atual->nif!=nif)){
            anterior = atual;
            atual = atual->seguinte;
        }
        if (atual==NULL) return(inicio);
        else{
            anterior->seguinte = atual->seguinte;
            free(atual);
            return(inicio);
        }
    }
}

/* ALINEA 5 - Alteração de um determinado dado */
/* Metodos que alteram os dados da estrutura de clientes, exceptuando o NIF que é o identificador pessoal */
Cliente* alteraNomeCliente(Cliente *inicio, int nif, char novoNome[]){
    Cliente *atual = inicio;
    while (atual != NULL) {
        if (atual->nif == nif) {
            strcpy(atual->nome, novoNome);
            return(atual);
        }
        atual = atual->seguinte;
    }
    return(inicio);
}
Cliente* alteraMoradaCliente(Cliente *inicio, int nif, char novaMorada[]){
    Cliente *atual = inicio;
    while (atual != NULL) {
        if (atual->nif == nif) {
            strcpy(atual->morada, novaMorada);
            return(atual);
        }
        atual = atual->seguinte;
    }
    return(inicio);
}
Cliente* alteraSaldoCliente(Cliente *inicio, int nif, float novoSaldo){
    Cliente *atual = inicio;
    while (atual != NULL) {
        if (atual->nif == nif) {
            atual->saldo = novoSaldo;
            return(atual);
        }
        atual = atual->seguinte;
    }
    return(inicio);
}
