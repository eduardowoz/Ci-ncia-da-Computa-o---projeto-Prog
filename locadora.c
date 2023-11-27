#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdio.h>

typedef struct clientes{
    int id;
	char cpf[15];
    char cliente[200];
    char rua[200];
    char filme[200];
    char serie[200];
    float saldo;
    struct clientes *prox;
}lcam;

typedef struct filmes{
    int id;
    char nomef[200];
    char empresa[200];
    char genero[200];
    float vpago;
    struct filmes *prox;
}lcar;

 typedef struct serie{
    int id;
    char nome[200];
    float vc;
    struct serie *prox;
}lcid;


void cad_cam(lcam **cabeca);
void cad_car(lcar **carcabeca);
void cad_cid(lcid **cidcabeca);
void imp_cam(lcam *cabeca);
void imp_car(lcar *carcabeca);
void imp_cid(lcid *cidcabeca);
void salvacam(lcam **cabeca);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    lcam *cabeca = NULL;        
    lcam *noatual;    

    lcar *carcabeca = NULL;
    lcar *carnoatual; 

    lcid *cidcabeca = NULL;
    lcid *cidnoatual;

    int op;


	printf("-----------------------------------------\n");
	printf("--------- Bem Vindo a Locadora ----------\n");
	printf("-----------------------------------------\n");


    printf("[0] - Fechar \n");
    printf("[1] - Cadastrar Cliente \n");
    printf("[2] - Escolher Filme \n");
    printf("[3] - Escolher Serie \n");
	printf("[4] - Consultar CPF\n" );
    printf("[5] - Imprimir Cliente\n" );
    printf("[6] - Imprimir Filmes\n");
    printf("[7] - Imprimir Series\n");
    printf("[8] - Salvar Cliente em Arquivo \n");
	printf("[9] - Desativar um Cliente\n");
    printf("[10] - Excluir Cliente \n");
    

    printf("Digite uma opcao: \n");
    scanf("%d", &op);

    while(op!=0){
    switch(op){
            case 0:{
                op=0;
                break;
             }
             break;
            case 1: cad_cam(&cabeca);
                    break;
            case 2: cad_car(&carcabeca);
                    break;
            case 3: cad_cid(&cidcabeca);
                    break;  
            case 4:
    		{
        	char cpf_consulta[15];

			printf("-----------------------------------------\n");
			printf("----------- Consultar CPF ---------------\n");
			printf("-----------------------------------------\n");

        	printf("Digite o CPF para consulta:\n");
        	scanf("%s", cpf_consulta);
        	consultar_cpf(cabeca, cpf_consulta);
        	break;
    		}

			case 5: imp_cam(cabeca);
                    break;		
            case 6: imp_car(carcabeca);     
                    break;
            case 7:imp_cid(cidcabeca);
                   break;
            case 8:salvacam(&cabeca);
                   break;
			case 9:
    		break;	   
            case 10:
			{
        	int id_excluir;
        	printf("Digite o ID do cliente a ser excluído:\n");
        	scanf("%d", &id_excluir);
        	exclui_cam(&cabeca, id_excluir);
        	break;
   			 }

	   
                     
        }
    printf("[0] - Fechar \n");
    printf("[1] - Cadastrar Cliente \n");
    printf("[2] - Escolher Filme \n");
    printf("[3] - Escolher Serie \n");
	printf("[4] - Consultar CPF\n" );
    printf("[5] - Imprimir Cliente\n" );
    printf("[6] - Imprimir Filmes\n");
    printf("[7] - Imprimir Series\n");
    printf("[8] - Salvar Cliente em Arquivo \n");
	printf("[9] - Desativar um Cliente\n");
    printf("[10] - Excluir Cliente \n");

    printf("Digite uma opcao: \n");
    scanf("%d", &op);
    } 
}


void cad_cam (lcam **cabeca)
{
    setlocale(LC_ALL, "Portuguese");

    lcam *noatual, *novono;

    int id;
    char cli[200];
	char cpf[15];
    char mar[200];
    char loca[200];
    char lisd[200];
    float kml;

	printf("-----------------------------------------\n");
	printf("-----------Cadastrar Cliente-------------\n");
	printf("-----------------------------------------\n");

    printf("ID:\n");
    scanf("%d", &id);
    setbuf(stdin, NULL);
    printf("Cliente:\n");
    scanf("%[^\n]s", &cli);
    setbuf(stdin, NULL);
	printf("CPF:\n");
    scanf("%[^\n]s", cpf);
    setbuf(stdin, NULL);
    printf("Rua :\n");
    scanf("%[^\n]s", &mar);
    setbuf(stdin, NULL);
    printf("Sua Cidade:\n");
    scanf("%[^\n]s", &loca);
    setbuf(stdin, NULL);
    printf("Seu Bairro:\n");
    scanf("%[^\n]s", &lisd);
    setbuf(stdin, NULL);
    printf("Dinheiro para depositar:\n");
    scanf("%f", &kml);
    setbuf(stdin, NULL);

    if (*cabeca == NULL)   
    {
        *cabeca = malloc(sizeof(lcam));
        (*cabeca)->id = id;
        strcpy((*cabeca)->cliente, cli);
		strcpy((*cabeca)->cpf, cpf);
        strcpy((*cabeca)->rua, mar);
        strcpy((*cabeca)->filme, loca);
        strcpy((*cabeca)->serie, lisd);
        (*cabeca)->saldo = kml;
        (*cabeca)->prox = NULL;
    }
        else{
        noatual = *cabeca;
        while(noatual->prox != NULL)
            noatual = noatual->prox;    
        novono =  malloc(sizeof(lcam));
        novono->id = id;
        strcpy(novono->cliente, cli);
		strcpy(novono->cpf, cpf);
        strcpy(novono->rua,mar);
        strcpy(novono->filme,loca);
        strcpy(novono->serie,lisd);
        novono->saldo = kml;
        novono->prox = NULL;
        noatual->prox = novono;
    }
}

void cad_car (lcar **carcabeca)
{
    setlocale(LC_ALL, "Portuguese");

    lcar *carnoatual, *carnovono;

    int id;
    char prod[200];
    char ori[200];
    char dest[200];
    float vf;

	printf("-----------------------------------------\n");
	printf("----------- Escolher Filme --------------\n");
	printf("-----------------------------------------\n");

    printf("ID:\n");
    scanf("%d", &id);
    setbuf(stdin, NULL);
    printf("Filme:\n");
    scanf("%[^\n]s", &prod);
    setbuf(stdin, NULL);
    printf("Empresa:\n");
    scanf("%[^\n]s", &ori);
    setbuf(stdin, NULL);
    printf("Genero:\n");
    scanf("%[^\n]s", &dest);
    setbuf(stdin, NULL);
    printf("Valor disposto a ser pago:\nR$");
    scanf("%f", &vf);
    setbuf(stdin, NULL);
    if (*carcabeca == NULL)   
    {
        *carcabeca = malloc(sizeof(lcar));
        (*carcabeca)->id = id;
        strcpy((*carcabeca)->nomef, prod);
        strcpy((*carcabeca)->empresa, ori);
        strcpy((*carcabeca)->genero, dest);
        (*carcabeca)->vpago = vf;
        (*carcabeca)->prox = NULL;
    }
        else{
        carnoatual = *carcabeca;
        while(carnoatual->prox != NULL)
            carnoatual = carnoatual->prox;    
        carnovono =  malloc(sizeof(lcar));
        carnovono->id = id;
        strcpy(carnovono->nomef, prod);
        strcpy(carnovono->empresa,ori);
        strcpy(carnovono->genero,dest);
        carnovono->vpago = vf;
        carnovono->prox = NULL;
        carnoatual->prox = carnovono;
    }
}

void cad_cid (lcid **cidcabeca)
{
    setlocale(LC_ALL, "Portuguese");

    lcid *cidnoatual, *cidnovono;

    int id;
    char nome[200];
    char viz[200];
    char dist[200];
    float vac;

	printf("-----------------------------------------\n");
	printf("----------- Escolher Serie --------------\n");
	printf("-----------------------------------------\n");

    printf("ID:\n");
    scanf("%d", &id);
    setbuf(stdin, NULL);
    printf("Nome da Serie:\n");
    scanf("%[^\n]s", &nome);
    setbuf(stdin, NULL);
    printf("Digite o valor disposto a pagar:\nR$");
    scanf("%f", &vac);
    setbuf(stdin, NULL);


    if (*cidcabeca == NULL)   
    {
        *cidcabeca = malloc(sizeof(lcid));
        (*cidcabeca)->id = id;
        strcpy((*cidcabeca)->nome, nome);
        (*cidcabeca)->vc = vac;
        (*cidcabeca)->prox = NULL;
    }
        else{
        cidnoatual = *cidcabeca;
        while(cidnoatual->prox != NULL)
            cidnoatual = cidnoatual->prox;    
        cidnovono =  malloc(sizeof(lcid));
        cidnovono->id = id;
        strcpy(cidnovono->nome, nome);
        cidnovono->vc = vac;
        cidnovono->prox = NULL;
        cidnoatual->prox = cidnovono;
    }
}

void imp_cam(lcam *cabeca) {
    setlocale(LC_ALL, "Portuguese");

    
    lcam *atual, *proximo;
    int temp;

    for (atual = cabeca; atual != NULL; atual = atual->prox) {
        for (proximo = atual->prox; proximo != NULL; proximo = proximo->prox) {
            if (atual->id > proximo->id) {
                
                temp = atual->id;
                atual->id = proximo->id;
                proximo->id = temp;

                char temp_cliente[200];
                char temp_cpf[15];
                char temp_rua[200];
                char temp_filme[200];
                char temp_serie[200];
                float temp_saldo;

                strcpy(temp_cliente, atual->cliente);
                strcpy(atual->cliente, proximo->cliente);
                strcpy(proximo->cliente, temp_cliente);

                strcpy(temp_cpf, atual->cpf);
                strcpy(atual->cpf, proximo->cpf);
                strcpy(proximo->cpf, temp_cpf);

                strcpy(temp_rua, atual->rua);
                strcpy(atual->rua, proximo->rua);
                strcpy(proximo->rua, temp_rua);

                strcpy(temp_filme, atual->filme);
                strcpy(atual->filme, proximo->filme);
                strcpy(proximo->filme, temp_filme);

                strcpy(temp_serie, atual->serie);
                strcpy(atual->serie, proximo->serie);
                strcpy(proximo->serie, temp_serie);

                temp_saldo = atual->saldo;
                atual->saldo = proximo->saldo;
                proximo->saldo = temp_saldo;
            }
        }
    }


		printf("-----------------------------------------\n");
		printf("------------ Lista Cadastro -------------\n");
		printf("-----------------------------------------\n");

    while (cabeca != NULL) {
        printf("\nID:%d\n", cabeca->id);
        printf("Cliente:%s\n", cabeca->cliente);
        printf("CPF:%s\n", cabeca->cpf);
        printf("Rua:%s\n", cabeca->rua);
        printf("Cidade:%s\n", cabeca->filme);
        printf("Bairro:%s\n", cabeca->serie);
        printf("Saldo:%.2f\n", cabeca->saldo);
        cabeca = cabeca->prox;
    }
}

void imp_car(lcar *carnoatual)
{
    setlocale(LC_ALL, "Portuguese");

		printf("-----------------------------------------\n");
		printf("------------- Lista Filmes --------------\n");
		printf("-----------------------------------------\n");

    while( carnoatual != NULL)    
    {
        printf("\nID:%d\n", carnoatual->id);
        printf("Filme:%s\n", carnoatual->nomef);
        printf("Empresa:%s\n", carnoatual->empresa);
        printf("Genero:%s\n", carnoatual->genero);
        printf("Valor do filme:R$%.2f\n", carnoatual->vpago);
        carnoatual = carnoatual->prox; 
    }
}

void imp_cid(lcid *cidnoatual)
{
    setlocale(LC_ALL, "Portuguese");

		printf("-----------------------------------------\n");
		printf("------------ Lista Series ---------------\n");
		printf("-----------------------------------------\n");


    while( cidnoatual != NULL)    
    {
        printf("\nID:%d\n", cidnoatual->id);
        printf("Nome da Serie:%s\n", cidnoatual->nome);
        printf("Valor a ser pago:%.2f\n", cidnoatual->vc);
        cidnoatual = cidnoatual->prox; 
    }
}

void salvacam(lcam **cabeca){
    lcam *noatual;

    FILE *arquivo;
    arquivo = fopen("Locadora.txt", "w");
    
    if(arquivo == NULL){
        printf("Erro na Abertura do Arquivo");
    } else {
        noatual = *cabeca;

        if(noatual == NULL){
            fprintf(arquivo,"Lista Vazia!\n");
        } else {
            while(noatual != NULL){
                fprintf(arquivo,"ID:%d\n", noatual->id);
                fprintf(arquivo,"Cliente:%s\n", noatual->cliente);
				fprintf(arquivo,"CPF:%s\n", noatual->cpf);
                fprintf(arquivo,"Rua:%s\n", noatual->rua);
                fprintf(arquivo,"Cidade Atual:%s\n", noatual->filme);
                fprintf(arquivo,"Bairro:%s\n", noatual->serie);
                fprintf(arquivo,"Saldo:%.2f\n", noatual->saldo);
				fprintf(arquivo, "\n");
                noatual = noatual->prox;
            }
        }
    }
    fclose(arquivo);
    printf("Salvo com Sucesso!\n");
}

void exclui_cam(lcam **cabeca, int id) {
    lcam *atual = *cabeca;
    lcam *anterior = NULL;

    while (atual != NULL && atual->id != id) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Cliente com ID %d não encontrado.\n", id);
        return;
    }

    if (anterior == NULL) {
        
        *cabeca = atual->prox;
    } else {
        
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Cliente com ID %d excluído com sucesso.\n", id);
}

void exclui_cid(lcid **cidcabeca, int id) {
    lcid *atual = *cidcabeca;
    lcid *anterior = NULL;

    while (atual != NULL && atual->id != id) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Filme com ID %d não encontrada.\n", id);
        return;
    }

    if (anterior == NULL) {
        
        *cidcabeca = atual->prox;
    } else {
        
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Filme com ID %d excluída com sucesso.\n", id);
}

void exclui_car(lcar **carcabeca, int id) {
    lcar *atual = *carcabeca;
    lcar *anterior = NULL;

    while (atual != NULL && atual->id != id) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Carga com ID %d não encontrada.\n", id);
        return;
    }

    if (anterior == NULL) {
         
        *carcabeca = atual->prox;
    } else {
        
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Carga com ID %d excluída com sucesso.\n", id);
}

void consultar_cpf(lcam *cabeca, char *cpf) {
    lcam *noatual = cabeca;




    while (noatual != NULL) {
        if (strcmp(noatual->cpf, cpf) == 0) {
            printf("\nID:%d\n", noatual->id);
            printf("Cliente:%s\n", noatual->cliente);
            printf("CPF:%s\n", noatual->cpf);
            printf("Rua:%s\n", noatual->rua);
            printf("Filme:%s\n", noatual->filme);
            printf("Serie:%s\n", noatual->serie);
            printf("Saldo:%.2f\n", noatual->saldo);
            return;
        }
        noatual = noatual->prox;
    }

    
    printf("O CPF %s não e valido.\n", cpf);
}
