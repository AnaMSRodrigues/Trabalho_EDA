//
//  main.c
//  Trabalho_EDA
//
//  Created by Margarida Rodrigues on 03/03/2023.
//
#include "TrabalhoPratico.h"

void menuIniciar(){
    printf("-------------MENU-------------\n ");
    printf("Tipo de utilizador:\n");
    printf("1 - Gestor\n");
    printf("2 - Cliente\n");
}

int main(){
    Meio* meios = NULL; // Lista ligada vazia de meios
    Cliente* clientes = NULL; // Lista ligada vazia de clientes
    Gestor* gestores = NULL; // Lista ligada vazia de gestores
    
    meios = inserirMeio(meios,1,"bicicleta",55,30,"RPG","DISPONIVEL");
    meios = inserirMeio(meios,2,"bicicleta",85,70,"GFS","ALUGADO");
    meios = inserirMeio(meios,3,"trotinete",85,50,"LKD","DISPONIVEL");
    
    clientes = inserirCliente(clientes, 2354674, "Gabriel", "Rua de Baixo", 35.90);
    clientes = inserirCliente(clientes, 4956823, "Ana", "Rua do Areal", 25.79);
    clientes = inserirCliente(clientes, 3456764, "Bruno", "Rua de Cima", 20.87);
    
    gestores = inserirGestor(gestores, 1, "Sara","Rua da Luz");
    gestores = inserirGestor(gestores, 2, "Maria", "Rua do entroncamento");
    gestores = inserirGestor(gestores, 3, "Rui", "Rua do Raio");
    
    int opcao,opAlt,tipoUtilizador,cod;
    long nif;
    float bat, aut, saldo, tipoAlteracaoNum;
    char tipo[TAM], geo[TAM], estado[TAM],tipoAlteracao[TAM], nome[TAM], morada[TAM];
    
    // Pergunta se o utilizador é um cliente ou gestor
    menuIniciar();
    scanf("%d", &tipoUtilizador);
    
    while (1){
        if (tipoUtilizador == 1){
            menuGestor();
            scanf("%d", &opcao);
            switch (opcao){
                case 1:
                    printf("Codigo:\n");
                    scanf("%d",&cod);
                    scanf("%*c");
                    printf("Tipo:\n");
                    scanf("%[^\n]s",tipo);
                    printf("Nivel da bateria (em percentagem) :\n");
                    scanf("%f",&bat);
                    printf("Autonomia (em Km) :\n");
                    scanf("%f",&aut);
                    printf("Geocodigo (Codigo de 3 letras) :\n");
                    scanf("%*c");
                    scanf("%[^\n]s\n",geo);
                    printf("Estado (disponivel ou alugado) :\n");
                    scanf("%*c");
                    scanf("%[^\n]s\n",estado);
                    meios = inserirMeio(meios,cod,tipo,bat,aut,geo,estado);
                    break;
                case 2:
                    printf("Codigo do meio de mobilidade a remover?\n");
                    scanf("%d",&cod);
                    meios = removerMeio(meios, cod);
                    printf("Meio removido com sucesso\n");
                    break;
                case 3:
                    listarMeios(meios);
                    break;
                case 4:
                    guardarMeios(meios);
                    break;
                case 5:
                    meios = lerMeios();
                    break;
                case 6:
                    printf("Qual o parametro a alterar no meio de mobilidade eletrica?\n");
                    printf("1 - Tipo\n");
                    printf("2 - Nivel de bateria\n");
                    printf("3 - Autonomia\n");
                    printf("4 - Geocodigo\n");
                    printf("5 - Estado\n");
                    printf("0 - Sair\n");
                    scanf("%d", &opAlt);
                    printf("Introduza o codigo do meio que quer alterar:\n");
                    scanf("%d", &cod);
                    printf("Introduza o parametro atualizado:\n");
                    switch (opAlt){
                        case 1:
                            scanf("%s", tipoAlteracao);
                            alteraTipoMeio(meios,cod,tipoAlteracao);
                            printf("Meio alterado com sucesso no parametro Tipo\n");
                            break;
                        case 2:
                            scanf("%f", &tipoAlteracaoNum);
                            alteraBateriaMeio(meios,cod,tipoAlteracaoNum);
                            printf("Meio alterado com sucesso no parametro Nivel de Bateria\n");
                            break;
                        case 3:
                            scanf("%f", &tipoAlteracaoNum);
                            alteraAutonomiaMeio(meios,cod,tipoAlteracaoNum);
                            printf("Meio alterado com sucesso no parametro Autonomia\n");
                            break;
                        case 4:
                            scanf("%s", tipoAlteracao);
                            alteraGeoMeio(meios,cod,tipoAlteracao);
                            printf("Meio alterado com sucesso no parametro Geocodigo\n");
                            break;
                        case 5:
                            scanf("%s", tipoAlteracao);
                            alteraStatusMeio(meios, cod, tipoAlteracao);
                            printf("Meio alterado com sucesso no parametro Estado\n");
                            break;
                    }
                    break;
                case 7:
                    printf("NIF:\n");
                    scanf("%ld",&nif);
                    scanf("%*c");
                    printf("Nome:\n");
                    scanf("%[^\n]s",nome);
                    printf("Morada:\n");
                    scanf("%*c");
                    scanf("%[^\n]s\n",morada);
                    printf("Saldo:\n");
                    scanf("%f",&saldo);
                    clientes = inserirCliente(clientes,nif,nome,morada,saldo);
                    printf("Cliente inserido com sucesso\n");
                    listarClientes(clientes);
                    break;
                case 8:
                    printf("NIF do cliente a remover?\n");
                    scanf("%ld",&nif);
                    clientes = removerCliente(clientes,nif);
                    printf("Cliente removido com sucesso\n");
                    listarClientes(clientes);
                    break;
                case 9:
                    printf("Qual o parametro a alterar no cliente?\n");
                    printf("1 - Nome\n");
                    printf("2 - Morada\n");
                    printf("3 - Saldo\n");
                    printf("0 - Sair\n");
                    scanf("%d", &opAlt);
                    printf("Introduza o nif do cliente que quer alterar:\n");
                    scanf("%ld", &nif);
                    printf("Introduza o parametro atualizado:\n");
                    switch (opAlt){
                        case 1:
                            scanf("%s", tipoAlteracao);
                            alteraNomeCliente(clientes,nif,tipoAlteracao);
                            printf("Cliente alterado com sucesso no parametro Nome\n");
                            break;
                        case 2:
                            scanf("%s", tipoAlteracao);
                            alteraMoradaCliente(clientes,nif,tipoAlteracao);
                            printf("Cliente alterado com sucesso no parametro Morada\n");
                            break;
                        case 3:
                            scanf("%f", &tipoAlteracaoNum);
                            alteraSaldoCliente(clientes,nif,tipoAlteracaoNum);
                            printf("Meio alterado com sucesso no parametro Saldo\n");
                            break;
                    }
                    break;
                case 10:
                    listarClientes(clientes);
                    break;
                case 11:
                    printf("Codigo:\n");
                    scanf("%d",&cod);
                    scanf("%*c");
                    printf("Nome:\n");
                    scanf("%[^\n]s",nome);
                    scanf("%*c");
                    printf("Morada:\n");
                    scanf("%[^\n]s",morada);
                    gestores = inserirGestor(gestores,cod,nome,morada);
                    break;
                case 12:
                    printf("Codigo do gestor a remover?\n");
                    scanf("%d",&cod);
                    gestores = removerGestor(gestores, cod);
                    printf("Gestor removido com sucesso\n");
                case 13:
                    printf("Qual o parametro a alterar no gestor?\n");
                    printf("1 - Nome\n");
                    printf("2 - Morada\n");
                    scanf("%d", &opAlt);
                    printf("Introduza o codigo do gestor que quer alterar:\n");
                    scanf("%d", &cod);
                    printf("Introduza o parametro atualizado:\n");
                    switch (opAlt){
                        case 1:
                            scanf("%s", tipoAlteracao);
                            alteraNomeGestor(gestores,cod,tipoAlteracao);
                            printf("Gestor alterado com sucesso no parametro Nome\n");
                            break;
                        case 2:
                            scanf("%s", tipoAlteracao);
                            alteraMoradaGestor(gestores,cod,tipoAlteracao);
                            printf("Gestor alterado com sucesso no parametro Morada\n");
                            break;
                    }
                    break;
                case 14:
                    listarGestores(gestores);
                    break;
            }
        } else if (tipoUtilizador == 2){
            menuCliente();
            scanf("%d", &opcao);
            switch(opcao){
                case 1:
                    printf("Que tipo de meio de mobilidade eletrica deseja alugar?\n");
                    scanf("%s", tipo);
                    alugarMeio(meios,tipo);
                    printf("Aluguer concluido com sucesso\n");
                    break;
                case 2:
                    printf("Qual o codigo do meio de mobilidade eletrica que deseja libertar?\n");
                    scanf("%d", &cod);
                    disponibilizarMeio(meios, cod);
                    printf("Termino do aluguer realizado com sucesso\n");
                    break;
                case 3:
                    ordenaMeiosDecrescente(meios);
                    listarMeios(meios);
                    break;
                case 4:
                    printf("Insira o geocodigo onde deseja procurar meios:\n");
                    scanf("%s", geo);
                    procuraMeioGeo(meios,geo);
                    listarMeios(meios);
                    break;
                case 5:
                    printf("Qual o parametro a alterar?\n");
                    printf("1 - Nome\n");
                    printf("2 - Morada\n");
                    printf("3 - Saldo\n");
                    printf("0 - Sair\n");
                    scanf("%d", &opAlt);
                    printf("Introduza o seu nif:\n");
                    scanf("%ld", &nif);
                    printf("Introduza o novo parametro:\n");
                    switch (opAlt){
                        case 1:
                            scanf("%s", tipoAlteracao);
                            alteraNomeCliente(clientes,nif,tipoAlteracao);
                            printf("Cliente alterado com sucesso no parametro Nome\n");
                            break;
                        case 2:
                            scanf("%s", tipoAlteracao);
                            alteraMoradaCliente(clientes,nif,tipoAlteracao);
                            printf("Cliente alterado com sucesso no parametro Morada\n");
                            break;
                        case 3:
                            scanf("%f", &tipoAlteracaoNum);
                            alteraSaldoCliente(clientes,nif,tipoAlteracaoNum);
                            printf("Meio alterado com sucesso no parametro Saldo\n");
                            break;
                    }
                    break;
                }
        } else printf("Utilizador invalido\n");
        menuIniciar();
        scanf("%d", &tipoUtilizador);
    }
}
