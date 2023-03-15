//
//  TrabalhoPraticoa.h
//  Trabalho_EDA
//
//  Created by Margarida Rodrigues on 03/03/2023.
//

#ifndef TrabalhoPratico_h
#define TrabalhoPratico_h

#define TAM 50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Alinea 1 */
/* Definição de uma estrutura de dados dinâmica para a representação dos meios de mobilidade elétrica */
typedef struct Meio{
    int codigo; // código do meio de mobilidade elétrica
    char tipo[TAM]; //bicicleta, trotinete
    float bateria; // em percentagem
    float autonomia; // em Km
    char geocod[TAM];
    char status[TAM];
    struct Meio* seguinte;
} Meio;

/* Definicao de uma estrutura de dados dinâmica para a representação de um cliente*/
typedef struct Cliente{
    long nif; //NIF do cliente
    char nome[TAM]; //Nome do cliente
    char morada[TAM]; //Morada do cliente
    float saldo; //Saldo do cliente em euros
    struct Cliente* seguinte;
} Cliente;

/* Definicao de uma estrutura de dados dinamica para a representação de um gestor */
typedef struct Gestor{
    int codigo;
    char nome[TAM];
    char morada[TAM];
    struct Gestor* seguinte;
} Gestor;

/* Metodos para manipulação da lista ligada de meios de mobilidade eletrica */

void listarMeios(Meio* inicio);
int existeMeio(Meio* inicio, int codigo);
int guardarMeios(Meio* inicio);
Meio* lerMeios(void);
Meio* inserirMeio(Meio * inicio, int cod, char tipo[], float bat, float aut, char geo[], char status[]);
Meio* removerMeio(Meio* inicio, int cod);
Meio* alteraTipoMeio(Meio *inicio, int codigo, char novoTipo[]);
Meio* alteraBateriaMeio(Meio *inicio, int codigo, float novaBateria);
Meio* alteraAutonomiaMeio(Meio *inicio, int codigo, float novaAutonomia);
Meio* alteraGeoMeio(Meio *inicio, int codigo, char novoGeocod[]);
Meio* alteraStatusMeio(Meio *inicio, int codigo, char novoStatus[]);
void alugarMeio(Meio* inicio, char tipoMeio[]);
void disponibilizarMeio(Meio*inicio, int cod);
void troca(Meio *a, Meio *b);
void ordenaMeiosDecrescente(Meio *inicio);
Meio* procuraMeioGeo(Meio* inicio, char geo[]);

/* Metodos para manipulação da lista ligada de clientes */
void menuCliente();
void listarClientes(Cliente * inicio);
int existeCliente(Cliente* inicio, int nif);
int guardarClientes(Cliente* inicio);
Cliente* lerClientes(void);
Cliente* inserirCliente(Cliente * inicio, int nif, char nome[], char morada[], float saldo);
Cliente* removerCliente(Cliente* inicio, int nif);
Cliente* alteraNomeCliente(Cliente *inicio, int nif, char novoNome[]);
Cliente* alteraMoradaCliente(Cliente *inicio, int nif, char novaMorada[]);
Cliente* alteraSaldoCliente(Cliente *inicio, int nif, float novoSaldo);

/* Metodos para manipulação da lista ligada de gestores */
void menuGestor();
void listarGestores(Gestor * inicio);
int existeGestor(Gestor* inicio, int cod);
int guardarGestores(Gestor* inicio);
Gestor* lerGestores(void);
Gestor* inserirGestor(Gestor * inicio, int codigo, char nome[], char morada[]);
Gestor* removerGestor(Gestor* inicio, int cod);
Gestor* alteraNomeGestor(Gestor *inicio, int cod, char novoNome[]);
Gestor* alteraMoradaGestor(Gestor *inicio, int cod, char novaMorada[]);


#endif /* TrabalhoPratico_h */
