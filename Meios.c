//
//  TrabalhoPraticoa.c
//  Trabalho_EDA
//
//  Created by Margarida Rodrigues on 03/03/2023.
//
#include "TrabalhoPratico.h"

/* Metodo que mostra na consola o conteúdo da lista ligada de meios de mobilidade eletrica */
void listarMeios(Meio * inicio){
    while (inicio != NULL){
        printf("%d %s %.2f %.2f %s %s\n",inicio->codigo,inicio->tipo,inicio->bateria, inicio->autonomia, inicio->geocod, inicio->status);
        inicio = inicio->seguinte;
    }
}

/* Metodo que determina a existência do 'codigo' na lista ligada de meios de mobilidade elétrica */
int existeMeio(Meio* inicio, int cod){
    while(inicio!=NULL){
        if (inicio->codigo == cod) return(1);
        inicio = inicio->seguinte;
    }
    return(0);
}

/*ALINEA 2 - Armazenamento/leitura dos dados em ficheiro de texto */
/* Metodo para armazenamento de dados de meios de mobilidade eletrica */
int guardarMeios(Meio* inicio){
    FILE* fp;
    fp = fopen("meios.txt","w");
    if (fp!=NULL){
        Meio* aux= inicio;
        while (aux != NULL){
            fprintf(fp,"%d;%s;%.2f;%.2f;%s;%s\n", aux->codigo, aux->tipo,aux->bateria, aux->autonomia, aux->geocod, aux->status);
            aux = aux->seguinte;
        }
        fclose(fp);
        return(1);
    }
    else return(0);
}

/* Metodo para leitura de dados de meios de mobilidade eletrica */
Meio* lerMeios(){
    FILE* fp;
    int cod;
    char tipo[TAM], geo[TAM], status[TAM];
    float bat, aut;
    Meio* aux=NULL;
    fp = fopen("meios.txt","r");
    if (fp!=NULL){
        while (!feof(fp)){
            fscanf(fp,"%d;%[^\n]s;%f;%f;%[^\n]s;%[^\n]s\n", &cod, tipo, &bat, &aut, geo, status);
            aux = inserirMeio(aux, cod, tipo, bat, aut, geo, status);
        }
        fclose(fp);
    }
    return(aux);
}

/* ALINEA 3 - Inserção de novos dados */
/* Metodo que permite inserir um meio de mobilidade elétrica */
Meio* inserirMeio(Meio* inicio, int cod, char tipo[], float bat, float aut, char geo[],char status[]){
    if (!existeMeio(inicio, cod)){
        Meio * novo = malloc(sizeof(struct Meio));
        if (novo != NULL){
            novo->codigo = cod;
            strcpy(novo->tipo,tipo);
            novo->bateria = bat;
            novo->autonomia = aut;
            strcpy(novo->geocod,geo);
            strcpy(novo->status,status);
            novo->seguinte = inicio;
            return(novo);
        }
    }
    return inicio;
}

/* ALINEA 4 - Remoção de um determinado dado */
/* Remover um meio de mobilidade eletrica a partir do seu código */
Meio* removerMeio(Meio* inicio, int cod){
    Meio *anterior=inicio, *atual=inicio, *aux;
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
/* Metodos que alteram cada um dos parametros da estrutura de meios de mobilidade elétrica */
Meio* alteraTipoMeio(Meio *inicio, int codigo, char novoTipo[]){
    Meio *atual = inicio;
    while (atual != NULL) {
        if (atual->codigo == codigo) {
            strcpy(atual->tipo, novoTipo);
            return(atual);
        }
        atual = atual->seguinte;
    }
    return(inicio);
}
Meio* alteraBateriaMeio(Meio *inicio, int codigo, float novaBateria){
    Meio *atual = inicio;
    while (atual != NULL) {
        if (atual->codigo == codigo) {
            atual->bateria = novaBateria;
            return(atual);
        }
        atual = atual->seguinte;
    }
    return(inicio);
}
Meio* alteraAutonomiaMeio(Meio *inicio, int codigo, float novaAutonomia){
    Meio *atual = inicio;
    while (atual != NULL) {
        if (atual->codigo == codigo) {
            atual->autonomia = novaAutonomia;
            return(atual);
        }
        atual = atual->seguinte;
    }
    return(inicio);
}
Meio* alteraGeoMeio(Meio *inicio, int codigo, char novoGeocod[]){
    Meio *atual = inicio;
    while (atual != NULL) {
        if (atual->codigo == codigo) {
            strcpy(atual->geocod, novoGeocod);
            return(atual);
        }
        atual = atual->seguinte;
    }
    return(inicio);
}
Meio* alteraStatusMeio(Meio *inicio, int codigo, char novoStatus[]){
    Meio *atual = inicio;
    while (atual != NULL) {
        if (atual->codigo == codigo) {
            strcpy(atual->status, novoStatus);
            return(atual);
        }
        atual = atual->seguinte;
    }
    return(inicio);
}

/* ALINEA 6 - Registo do aluguer de um determinado meio de mobilidade elétrica */
/*Metodo que permite registar o aluguer de um meio de mobilidade eletrica alterando o seu STATUS de Disponivel para Alugado*/
void alugarMeio(Meio* inicio, char tipoMeio[]){
    Meio *atual = inicio;
    while (atual != NULL && strcmp(inicio->tipo, tipoMeio) != 0){
        atual = atual->seguinte;
    }
    if (atual == NULL) return;
    else if (strcmp(atual->status, "DISPONIVEL") == 0){
        strcpy(atual->status, "ALUGADO");
    }
}
/*Metodo que permite registar a libertacao de um meio de mobilidade eletrica alterando o seu STATUS de Alugado para Disponivel */
void disponibilizarMeio(Meio*inicio, int cod){
    Meio*atual = inicio;
    while(atual != NULL && inicio->codigo == cod){
        atual = atual->seguinte;
        }
    if (atual == NULL) return;
    else if (strcmp(atual->status, "ALUGADO") == 0){
        strcpy(atual->status, "DISPONIVEL");
    }
}

/* ALINEA 7 - Listagem dos meios de mobilidade elétrica por ordem decrescente de autonomia */
/*Metodo que troca os meios de mobilidade entre si*/
void troca(Meio *a, Meio *b){
    Meio aux = *a;
    *a = *b;
    *b = aux;
}
/* Metodo recursivo que ordena os meios existentes por ordem decrescente de autonomia, utilizando o metodo "troca" para construir a lista ordenada */
void ordenaMeiosDecrescente(Meio *inicio){
    int aux = 1;
    Meio *atual;
    Meio *seguinte = NULL;
    while (aux) {
        aux = 0;
        atual = inicio;
        while (atual->seguinte != seguinte) {
            if (atual->autonomia < atual->seguinte->autonomia) {
                troca(atual, atual->seguinte);
                aux = 1;
            }
            atual = atual->seguinte;
        }
        seguinte = atual;
    }
}

/*Alinea 8 - Listagem dos meios de mobilidade elétrica existentes numa localização com determinado geocódigo */
/* Metodo que cria uma nova lista ligada de meios de mobilidade presentes num determinado geocodigo */
Meio* procuraMeioGeo(Meio* inicio, char geo[]){
    Meio* mesmoGeo = NULL;
    Meio* atual = inicio;
    while (atual != NULL) {
        if (strcmp(atual->geocod, geo) == 0) {
            // cria um novo nó na lista de meios encontrados
            Meio* novo = malloc(sizeof(Meio));
            if (novo != NULL) {
                novo->codigo = atual->codigo;
                strcpy(novo->tipo, atual->tipo);
                novo->bateria = atual->bateria;
                novo->autonomia = atual->autonomia;
                strcpy(novo->geocod, atual->geocod);
                strcpy(novo->status, atual->status);
                novo->seguinte = mesmoGeo;
                mesmoGeo = novo;
            }
        }
        atual = atual->seguinte;
    }
    return mesmoGeo;
}
