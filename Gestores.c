//
//  Gestores.c
//  Trabalho_EDA
//
//  Created by Margarida Rodrigues on 06/03/2023.
//
#include "TrabalhoPratico.h"
/* Menu gestores */
void menuGestor(){
    printf("\nSelecione uma opcao:\n");
    printf("1 - Inserir meio de mobilidade eletrica\n");
    printf("2 - Remover meio de mobilidade eletrica\n");
    printf("3 - Listar meio de mobilidade eletrica\n");
    printf("4 - Guardar meio de mobilidade eletrica\n");
    printf("5 - Ler meios de mobilidade eletrica\n");
    printf("6 - Alterar meio de mobilidade eletrica\n");
    printf("7 - Inserir Cliente\n");
    printf("8 - Remover Cliente\n");
    printf("9 - Alterar parametro do cliente\n");
    printf("10 - Listar Clientes\n");
    printf("11 - Inserir Gestor\n");
    printf("12 - Remover Gestor\n");
    printf("13 - Alterar parametro do gestor\n");
    printf("14 - Listar Gestores\n");
    printf("0 - Sair\n");
}
/* Metodo que mostra na consola o conteúdo da lista ligada de gestores */
void listarGestores(Gestor * inicio){
    while (inicio != NULL){
        printf("%d %s %s\n",inicio->codigo,inicio->nome, inicio->morada);
        inicio = inicio->seguinte;
    }
}

/* Metodo que determina a existência do codigo de gestor na lista ligada de gestores */
int existeGestor(Gestor* inicio, int cod){
    while(inicio!=NULL){
        if (inicio->codigo == cod) return(1);
        inicio = inicio->seguinte;
    }
    return(0);
}

/* ALINEA 2 - Armazenamento/leitura dos dados em ficheiro de texto */
/* Metodo para armazenamento de dados de gestores */
int guardarGestores(Gestor* inicio){
    FILE* fp;
    fp = fopen("gestores.txt","w");
    if (fp!=NULL){
        Gestor* aux= inicio;
        while (aux != NULL){
            fprintf(fp,"%d %s %s\n",inicio->codigo,inicio->nome,inicio->morada);
            aux = aux->seguinte;
        }
        fclose(fp);
        return(1);
    }
    else return(0);
}

/* Metodo para leitura de dados de gestores */
Gestor* lerGestores(){
    FILE* fp;
    int codigo;
    char nome[TAM], morada[TAM];
    Gestor* aux=NULL;
    fp = fopen("gestores.txt","r");
    if (fp!=NULL){
        while (!feof(fp)){
            fscanf(fp,"%d;%s;%s\n", &codigo, nome, morada);
            aux = inserirGestor(aux, codigo, nome, morada);
        }
        fclose(fp);
    }
    return(aux);
}

/* ALINEA 3 - Inserção de novos dados */
/* Metodo que permite inserir um gestor */
Gestor* inserirGestor(Gestor * inicio, int codigo, char nome[], char morada[]){
    if (!existeGestor(inicio, codigo)){
        Gestor * novo = malloc(sizeof(struct Gestor));
        if (novo != NULL){
            novo->codigo = codigo;
            strcpy(novo->nome,nome);
            strcpy(novo->morada,morada);
            novo->seguinte = inicio;
            return(novo);
        }
    } else {
        return(inicio);
    }
    return inicio;
}

/* ALINEA 4 - Remoção de um determinado dado */
/* Remover um gestor a partir do seu código de identificação */
Gestor* removerGestor(Gestor* inicio, int cod){
    Gestor *anterior=inicio, *atual=inicio, *aux;
    if (atual==NULL) return(NULL);
    else if (atual->codigo == cod){
        aux = atual->seguinte;
        free(atual);
        return(aux);
    }
    else{
        while ((atual!=NULL)&&(atual->codigo!=cod)){
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
/* Metodos que alteram os dados da estrutura de gestores, exceptuando o codigo que e o identificador pessoal*/
Gestor* alteraNomeGestor(Gestor *inicio, int cod, char novoNome[]){
    Gestor *atual = inicio;
    while (atual != NULL) {
        if (atual->codigo == cod) {
            strcpy(atual->nome, novoNome);
            return(atual);
        }
        atual = atual->seguinte;
    }
    return(inicio);
}
Gestor* alteraMoradaGestor(Gestor *inicio, int cod, char novaMorada[]){
    Gestor *atual = inicio;
    while (atual != NULL) {
        if (atual->codigo == cod) {
            strcpy(atual->morada, novaMorada);
            return(atual);
        }
        atual = atual->seguinte;
    }
    return(inicio);
}



