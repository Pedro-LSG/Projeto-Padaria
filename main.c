/*
 * DEMANDA:
 * A padaria solicita um sistema de controle financeiro para algumas rotinas. A padaria efetua as vendas e as mesmas são anotadas em um caderno.
 * O cliente precisa ter um sistema de gerenciamento para controlar suas vendas e seu estoque. É necessário um relatório contendo os valores totais de vendas diárias e mensal.
 * É necessário registrar a quantidade de produtos produzidos e a quantidade em estoque.
 *
 * FUNCIONALIDADES:
 * Menu e submenu para registro de clientes e relatórios de vendas, produtos e clientes.
 *
 * CREDITOS DE CRIACAO:
 * Pedro Couto;
 * Pedro Luis.
 *
 * IMPORTANTE - MANUTENÇÃO
 * Para um perfeito funcionamento, esta aplicação deve ser limpa mensalmente. Contate seu técnico para efetuar o registro no banco de dados antes de reiniciar o sistema.
 *
 */
// Bibliotecas padrões
#include <stdio.h>
#include <stdlib.h>

// Bibliotecas personalizadas
#include <ctype.h>
#include <string.h>
#include <conio.h>

int i,j,tam; // Variáveis globais para controle de repetição

void logo(){ // Logo personalizado da padaria
    printf("%c             Padaria - No c%cu tem P%co              %c\n",186,130,198,186);
}
void cabecalho(){ // Cabeçalho da interface em ASCII;
    printf("%c",201);
    for (tam=0;tam<=50;tam++){
        printf("%c",205);
    }
    printf("%c\n",187);
}
void linhaDiv(){ // Divisão da interface em ASCII sem separador;
    printf("%c",204);
    for (tam=0;tam<=50;tam++){
        printf("%c",205);
    }
    printf("%c\n",185);
}
void linhaSep(){ // Divisão da interface em ASCII com separador;
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
           201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
}
void rodape(){ // Rodapé da interface em ASCII;
    printf("%c",200);
    for (tam=0;tam<=50;tam++){
        printf("%c",205);
    }
    printf("%c\n",188);
}
void invalida(){ // Validação de dados inseridos pelo usuário
    system("cls");
    cabecalho();
    logo();
    rodape();cabecalho();
    printf("%c         DADOS INV%cLIDOS, TENTE NOVAMENTE          %c\n",186,181,186);
    linhaDiv();
}

int main(){ // Bloco principal de instruções
    // Registro para dados de clientes
    struct cliente{
        char nome[50],endereco[200],telefone[20];
        int cpf,compra;
    };
    struct cliente vetorCliente[100];

    // Registro para dados de vendas
    struct venda{
        char nomeVendedor[50];
        int codVenda,quantProduto,quantVenda,codProduto,vendaCliente[100];
        float valorVenda,valorProduto[20],vendaDiaria[31];
    };
    struct venda vetorVenda[1000];

    // Registro para dados de produtos
    struct produto{
        char nomeProduto[50];
        int codProduto,quantEstoque,vendaProduto,lote;
        float valorProduto;
    };
    struct produto vetorProduto[100];

    // Variáveis para controle dos blocos de instruções
    char exe,ctrlData[15],ctrlNomeProduto[2][50];
    int contCliente=0,contVenda=0,contProduto=0,ctrlCPF,ctrlMensal=0,ctrlQuant,ctrlProduto,ctrlCodProduto,ctrlVendaProduto[2]={0,100};
    int menu,subMenu;
    float pago;

    // Variáveis para registro de dados dos relatórios
    char dataVenda[31][15];
    float vendaDiaria[31],vendaMensal=0,totalVenda,vendaMed=0,vendaMin=1000,vendaMax=0;

    // Inicialização da execução
    cabecalho();
    logo();
    rodape();cabecalho();
    printf("%c             INICIALIZA%c%cO DO SISTEMA              %c\n",186,128,199,186); // Menu de inicialização
    rodape();
    cabecalho();
    printf("%c Deseja iniciar o sistema? (S)im/(N)%co             %c\n",186,198,186);
    printf("%c > ",186);
    scanf("%s",&exe);
    exe = toupper(exe);
    rodape();
    for (i=0;i<100;i++){ // Bloco para zerar registros que serão usados para contagem
        vetorProduto[i].codProduto = 0;
        vetorProduto[i].vendaProduto = 0;
        vetorCliente[i].compra = 0;
    }
    while ((exe != 'S')&&(exe != 'N')){ // Tratamento de erros na execução inicial
        invalida();
        printf("%c Deseja iniciar o sistema? (S)im/(N)%co             %c\n",186,198,186);
        printf("%c > ",186);
        scanf("%s",&exe);
        exe = toupper(exe);
        rodape();
    }
    while (exe == 'S'){ // Bloco de repetição do programa completo
        system("cls");
        cabecalho();
        logo();
        rodape();
        cabecalho();
        printf("%c                  MENU PRINCIPAL                   %c\n",186,186);
        rodape();
        linhaSep();
        printf("%c 1. Cadastrar    %c 2. Relat%crio  %c 3. Finalizar    %c\n",186,186,162,186,186); // Opções iniciais oferecidas ao usuário
        printf("%c > ",186);
        scanf("%i",&menu); // Variável para leitura da opção escolhida
        rodape();
        system("cls");
        cabecalho();
        logo();
        rodape();cabecalho();
        switch (menu){ // Bloco condicional para seleção do menu principal
            case 1: // Caso o usuário queira realizar novos cadastros no sistema
                printf("%c                 SUBMENU CADASTRO                  %c\n",186,186);
                rodape();linhaSep();
                printf("%c 1. Cliente      %c 2. Produto    %c 3. Venda        %c\n",186,186,186,186); // Opções de cadastro
                printf("%c > ",186);
                scanf("%i",&subMenu); // Variável para leitura dos submenus
                rodape();
                system("cls");
                switch (subMenu){ // Bloco condicional para o menu de cadastro
                    case 1: // Cadastro de novos clientes
                        cabecalho();
                        logo();
                        rodape();cabecalho();
                        printf("%c                 CADASTRO CLIENTE                  %c\n",186,186);
                        linhaDiv();
                        printf("%c Insira o nome                                     %c\n",186,186);
                        printf("%c > ",186);
                        fflush(stdin);fgets(vetorCliente[contCliente].nome,50,stdin); // Registro do nome do cliente
                        linhaDiv();
                        printf("%c Insira o CPF (somente n%cmeros)                    %c\n",186,163,186);
                        printf("%c > ",186);
                        scanf("%i",&vetorCliente[contCliente].cpf); // Registro do documento
                        linhaDiv();
                        printf("%c Insira o endere%co                                 %c\n",186,135,186);
                        printf("%c > ",186);
                        fflush(stdin);fgets(vetorCliente[contCliente].endereco,200,stdin); // Registro do endereço
                        linhaDiv();
                        printf("%c Insira o telefone                                 %c\n",186,186);
                        printf("%c > ",186);
                        fflush(stdin);fgets(vetorCliente[contCliente].telefone,20,stdin);  // Registro do contato
                        rodape();
                        contCliente++; // Contador para controle do cadastro (aumenta uma posição a cada cliente novo);
                        break;
                    case 2: // Cadastro de produtos (novos ou já registrados)
                        cabecalho();
                        logo();
                        rodape();cabecalho();
                        printf("%c                 CADASTRO PRODUTO                  %c\n",186,186);
                        linhaDiv();
                        printf("%c Quantos produtos ser%co cadastrados (cada tipo)?   %c\n",186,198,186);
                        printf("%c > ",186);
                        scanf("%i",&ctrlProduto); // Controle de quantidade cadastrada de acordo com a nota
                        for (i=0;i<ctrlProduto;i++){ // Bloco para registro dos produtos, repetição controlada pelo usuário
                            system("cls");
                            cabecalho();
                            logo();
                            rodape();cabecalho();
                            printf("%c                CADASTRO %i%c PRODUTO                %c\n",186,(i+1),248,186);
                            linhaDiv();
                            printf("%c Insira o c%cdigo do produto                        %c\n",186,162,186);
                            printf("%c > ",186);
                            scanf("%i",&ctrlCodProduto); // Recebe o código do produto
                            linhaDiv();
                            for (j=0;j<100;j++){ // Bloco para verificação do produto
                                if (ctrlCodProduto == vetorProduto[j].codProduto){ // Valida se é um código já existente na base de dados
                                    printf("%c Produto selecionado                               %c\n",186,186);
                                    printf("%c > %s",186,vetorProduto[j].nomeProduto,186); // Exibe o produto selecionado de acordo com o código
                                    printf("%c Insira o valor do produto                         %c\n",186,186);
                                    printf("%c > ",186);
                                    scanf("%f",&vetorProduto[j].valorProduto); // Pede um valor atualizado do produto
                                    printf("%c Quantidade a ser somada                           %c\n",186,186);
                                    printf("%c > ",186);
                                    scanf("%i",&ctrlQuant); // Pede a quantidade comprada para ser somada ao estoque
                                    vetorProduto[j].quantEstoque += ctrlQuant; // Faz a soma ao valor já existente no estoque
                                    printf("%c Insira o lote do produto (somente n%cmeros)        %c\n",186,163,186);
                                    printf("%c > ",186);
                                    scanf("%i",&vetorProduto[j].lote); // Pede o número do novo lote
                                    ctrlCodProduto = 0; // Controle de registro do produto
                                    break;
                                }
                            }
                            if (ctrlCodProduto != 0){ // Caso o registro não tenha recebido 0, irá iniciar o cadastro de um novo produto
                                vetorProduto[contProduto].codProduto = ctrlCodProduto; // Recebe o código da variável de controle inserido pelo usuário
                                printf("%c Insira o nome do produto                          %c\n",186,186);
                                printf("%c > ",186);
                                fflush(stdin);fgets(vetorProduto[contProduto].nomeProduto,50,stdin); // Recebe o nome do novo produto cadastrado
                                linhaDiv();
                                printf("%c Insira o valor do produto                         %c\n",186,186);
                                printf("%c > ",186);
                                scanf("%f",&vetorProduto[contProduto].valorProduto); // Recebe o valor do novo produto
                                linhaDiv();
                                printf("%c Insira a quantidade                               %c\n",186,186);
                                printf("%c > ",186);
                                scanf("%i",&vetorProduto[contProduto].quantEstoque); // Recebe a quantidade comprada
                                linhaDiv();
                                printf("%c Insira o lote do produto (somente n%cmeros)        %c\n",186,163,186);
                                printf("%c > ",186);
                                scanf("%i",&vetorProduto[contProduto].lote); // Recebe o número do lote
                            }
                            rodape();
                            contProduto++; // Conta o registro do produto, para controlar quantos têm na base
                        }
                        break;
                    case 3: // Cadastro de vendas
                        totalVenda = 0;  // Zera o valor final da venda para soma
                        cabecalho();
                        logo();
                        rodape();cabecalho();
                        printf("%c                  REGISTRO VENDA                   %c\n",186,186);
                        linhaDiv();
                        printf("%c Insira o nome do vendedor                         %c\n",186,186);
                        printf("%c > ",186);
                        fflush(stdin);fgets(vetorVenda[contVenda].nomeVendedor,50,stdin); // Registra o vendedor responsável pela venda
                        linhaDiv();
                        printf("%c Produtos vendidos de cada tipo (m%cx. 20)          %c\n",186,160,186);
                        printf("%c > ",186);
                        scanf("%i",&vetorVenda[contVenda].quantProduto); // Recebe a quantidade de produtos vendidos, por tipo
                        while ((vetorVenda[contVenda].quantProduto<1)||(vetorVenda[contVenda].quantProduto>20)){ // Valida se a quantidade é válida (entre 1 e 20 produtos)
                            invalida();
                            printf("%c Produtos vendidos de cada tipo (m%cx. 20)          %c\n",186,160,186);
                            printf("%c > ",186);
                            scanf("%i",&vetorVenda[contVenda].quantProduto); // Caso não seja, solicita  novamente o valor
                        }
                        for (i=0;i<vetorVenda[contVenda].quantProduto;i++){ // Caso seja, inicia-se o registro da venda com os produtos
                            system("cls");
                            cabecalho();
                            logo();
                            rodape();cabecalho();
                            printf("%c            REGISTRO VENDA - PRODUTO %02i            %c\n",186,(i+1),186);
                            linhaDiv();
                            printf("%c Insira o c%cdigo do produto vendido                %c\n",186,162,186);
                            printf("%c > ",186);
                            scanf("%i",&ctrlCodProduto); // Solicita ao usuário o código do produto
                            while (ctrlCodProduto != 0){ // Bloco para tratamento de validação e exceções
                                for (j=0;j<100;j++){ // Valida por repetição se o produto já existe na base
                                    if (ctrlCodProduto == vetorProduto[j].codProduto){ // Caso identifique o código, exibe os valores
                                        vetorVenda[contVenda].codProduto = ctrlCodProduto;
                                        linhaDiv();
                                        printf("%c Produto selecionado                               %c\n",186,186);
                                        printf("%c > %s",186,vetorProduto[j].nomeProduto); // Exibe o produto que foi selecionado pelo usuário
                                        printf("%c Insira a quantidade vendida                       %c\n",186,186);
                                        printf("%c > ",186);
                                        scanf("%i",&vetorVenda[contVenda].quantVenda); // Solicita a quantidade que foi vendida (todas as unidades)
                                        vetorVenda[contVenda].valorProduto[i] = vetorProduto[j].valorProduto * vetorVenda[contVenda].quantVenda; // Cálculo do valor do produto de acordo com a quantidade e seu preço
                                        vetorProduto[j].vendaProduto += vetorVenda[contVenda].quantVenda; // Contagem dos produtos que foram mais e menos vendidos
                                        vetorProduto[j].quantEstoque -= vetorVenda[contVenda].quantVenda; // Controle de estoque, fazendo a subtração dos produtos vendidos
                                        totalVenda += vetorVenda[contVenda].valorProduto[i]; // Soma do valor final da venda de acordo com os produtos inseridos
                                        if (vetorProduto[j].vendaProduto > ctrlVendaProduto[0]){ // Posição 0 guarda o produto mais vendido até o momento
                                            ctrlVendaProduto[0] = vetorProduto[j].vendaProduto; // Repassa o valor para outra variável de registro
                                            strcpy(ctrlNomeProduto[0],vetorProduto[j].nomeProduto); // Repassa o nome do produto para variável de registro
                                        }
                                        if (vetorProduto[j].vendaProduto < ctrlVendaProduto[1]){ // Posição 1 guarda o produto menos vendido até o momento
                                            ctrlVendaProduto[1] = vetorProduto[j].vendaProduto; // Repassa o valor para outra variável de registro
                                            strcpy(ctrlNomeProduto[1],vetorProduto[j].nomeProduto); // Repassa o nome para variável de registro
                                        }
                                        ctrlCodProduto = 0; // Recebe 0 para demonstrar que o código do produto estava correto e foi feito o registro
                                        break;
                                    }
                                }
                            }
                            if (ctrlCodProduto != 0){ // Faz o tratamento de erro, o código esteja errado e a variável não tenha recebido 0
                                invalida();
                                printf("%c            REGISTRO VENDA - PRODUTO %02i            %c\n",186,(i+1),186);
                                linhaDiv();
                                printf("%c Insira o c%cdigo do produto vendido                %c\n",186,162,186);
                                printf("%c > ",186);
                                scanf("%i",&ctrlCodProduto); // Recebe novamente o código do produto
                            }
                            rodape();
                        }
                        system("cls");
                        cabecalho();
                        logo();
                        rodape();cabecalho();
                        printf("%c                  REGISTRO VENDA                   %c\n",186,186);
                        linhaDiv();
                        printf("%c Data da venda (DD/MM/AAAA)                        %c\n",186,186);
                        printf("%c > ",186); // Recebe uma data de venda, podendo ser personalizada (DD/MM/AAAA - recomendado)
                        scanf("%s",&ctrlData); // Recebe uma data de venda inserida pelo vendedor
                        while (strcmp(ctrlData,"") != 0){ // Bloco WHILE para verificação
                            for (i=0;i<31;i++){ // Bloco de repetição para comparar se a data já existe
                                if (strlen(dataVenda[i]) == 0){ // Caso não exista, o valor retornado no tamanho será igual a 0
                                    strcpy(dataVenda[i],ctrlData); // Recebe a data inserida pelo vendedor
                                    vendaDiaria[i] += totalVenda; // Faz a soma de todas as vendas daquela data
                                    vendaMensal += vendaDiaria[i]; // Faz a soma de todas as vendas do mês
                                    ctrlMensal++; // Contador para controle de vendas realizadas
                                    strcpy(ctrlData,""); // Recebe um valor vazio para saída do bloco WHILE
                                    break;
                                } else if (strcmp(ctrlData,dataVenda[i]) == 0){ // Caso a data já exista na base
                                    strcpy(ctrlData,""); // Recebe um valor vazio para saída do bloco WHILE
                                }
                            }
                            if (strcmp(ctrlData,"") != 0){ // Tratamento de erro, caso o sistema não identifique nenhuma data inserida
                                invalida();
                                printf("%c                  REGISTRO VENDA                   %c\n",186,186);
                                linhaDiv();
                                printf("%c Data da venda (DD/MM/AAAA)                        %c\n",186,186);
                                printf("%c > ",186);
                                scanf("%s",&ctrlData); // Recebe uma nova data de venda inserida pelo vendedor
                            }
                        }
                        strcpy(ctrlData,dataVenda[i]); // Faz a cópia do valor recebido após passar pelo tratamento do bloco WHILE
                        linhaDiv();
                        printf("%c Insira o CPF do cliente                           %c\n",186,186);
                        printf("%c > ",186);
                        scanf("%i",&ctrlCPF); // Recebe o CPF do cliente comprador
                        while (ctrlCPF != 0){ // Bloco WHILE para verificação
                            for (i=0;i<100;i++){ // Repetição para verificação dos clientes registrados na base
                                if (ctrlCPF == vetorCliente[i].cpf){ // Ao identificar um CPF válido, registra e finaliza a venda
                                    printf("%c Nome do cliente                                   %c\n",186,186);
                                    printf("%c > %s",186,vetorCliente[i].nome); // Exibe o comprador
                                    linhaDiv();
                                    printf("%c > Total: %-6.2f                                   %c\n",186,totalVenda,186); // Exibe o total da venda
                                    linhaDiv();linhaDiv();
                                    printf("%c          Pressione ENTER para continuar           %c\n",186,186); // Prossegue para a tela de pagamento
                                    rodape();
                                    getch();
                                    vetorCliente[i].compra++;
                                    ctrlCPF = 0;
                                    break;
                                }
                            }
                            if (ctrlCPF != 0){ // Tratamento de erros, para casos em que o CPF foi inserido errado
                                invalida();
                                printf("%c                  REGISTRO VENDA                   %c\n",186,186);
                                linhaDiv();
                                printf("%c Insira o CPF do cliente                           %c\n",186,186);
                                printf("%c > ",186);
                                scanf("%i",&ctrlCPF); // Recebe novamente o CPF
                            }
                        }
                        if (totalVenda<vendaMin){ // Registra as menores vendas
                            vendaMin = totalVenda;
                        }
                        if (totalVenda>vendaMax){ // Registra as maiores vendas
                            vendaMax = totalVenda;
                        }
                        vetorVenda[contVenda].codVenda = contVenda+1; // Prossegue com os registros das vendas
                        contVenda++; // Contador para controle do cadastro (aumenta uma posição a cada cliente novo)
                        system("cls");
                        cabecalho();
                        logo();
                        rodape();cabecalho();
                        printf("%c                  REGISTRO VENDA                   %c\n",186,186);
                        linhaDiv();
                        printf("%c Insira o valor de pagamento                       %c\n",186,186);
                        printf("%c > ",186);
                        scanf("%f",&pago); // Recebe o valor fornecido pelo cliente para pagamento de sua compra
                        linhaDiv();
                        printf("%c Troco para %s",186,vetorCliente[i].nome,186); // Informa ao usuário qual será o troco do cliente, com identificação personalizada
                        printf("%c > %-6.2f                                          %c\n",186,(pago-totalVenda),186); // Informa o valor do troco
                        linhaDiv();linhaDiv();
                        printf("%c          Pressione ENTER para continuar           %c\n",186,186);
                        rodape();
                        getch();
                        break;
                    default: // Tratamento de exceção do menu de cadastro
                        invalida();
                        printf("%c          Pressione ENTER para continuar           %c\n",186,186);
                        rodape();
                        getch();
                }
                system("cls");
                break;
            case 2: // Caso o usuário queira verificar os relatórios existentes
                printf("%c                 SUBMENU RELAT%cRIO                 %c\n",186,224,186);
                rodape();linhaSep();
                printf("%c  1. Cliente     %c 2. Produto    %c 3. Venda        %c\n",186,186,186,186); // Opções de relatórios
                printf("%c > ",186);
                scanf("%i",&subMenu); // Recebe a opção escolhida
                rodape();
                system("cls");
                cabecalho();
                logo();
                rodape();cabecalho();
                switch (subMenu){ // Bloco condicional para seleção do menu de relatórios
                    case 1: // Exibe o relatório dos clientes já registrados
                        printf("%c                 RELAT%cRIO CLIENTE                 %c\n",186,224,186);
                        linhaDiv();
                        printf("%c Insira o CPF do cliente                           %c\n",186,186);
                        printf("%c > ",186);
                        scanf("%i",&ctrlCPF); // Recebe o CPF do cliente escolhido
                        while (ctrlCPF != 0){ // Bloco WHILE para verificação
                            for (i=0;i<100;i++){ // Bloco para verificação de todos os clientes registrados
                                if (ctrlCPF == vetorCliente[i].cpf){ // Identificando o CPF digitado, inicia-se a apresentação dos dados
                                    linhaDiv();
                                    printf("%c Nome do cliente                                   %c\n",186,186);
                                    printf("%c > %s",186,vetorCliente[i].nome,186); // Exibe o nome do cliente
                                    linhaDiv();
                                    printf("%c Telefone do cliente                               %c\n",186,186);
                                    printf("%c > %s",186,vetorCliente[i].telefone,186); // Exibe o telefone
                                    linhaDiv();
                                    printf("%c Endere%co do cliente                               %c\n",186,135,186);
                                    printf("%c > %s",186,vetorCliente[i].endereco,186); // Exibe o endereço
                                    linhaDiv();
                                    printf("%c Compras realizadas pelo cliente                   %c\n",186,186);
                                    printf("%c > %-5i                                           %c\n",186,vetorCliente[i].compra,186); // Exibe quantas vezes o cliente comprou na padaria
                                    linhaDiv();linhaDiv();
                                    printf("%c          Pressione ENTER para continuar           %c\n",186,186);
                                    rodape();
                                    getch();
                                    ctrlCPF = 0; // Recebe 0 para controle, identificando que o CPF já foi identificado
                                    break;
                                }
                            }
                            if (ctrlCPF != 0){ // Caso não receba 0 para controle, entra no tratamento de erro
                                invalida();
                                printf("%c                 RELAT%cRIO CLIENTE                 %c\n",186,224,186);
                                linhaDiv();
                                printf("%c Insira o CPF do cliente                           %c\n",186,186);
                                printf("%c > ",186);
                                scanf("%i",&ctrlCPF); // Recebe um novo CPF para verificação
                            }
                        }
                        break;
                    case 2: // Exibe o relatório dos produtos já registrados
                        printf("%c                 RELAT%cRIO PRODUTO                 %c\n",186,224,186);
                        linhaDiv();
                        printf("%c Insira o c%cdigo do produto                        %c\n",186,162,186);
                        printf("%c > ",186);
                        scanf("%i",&ctrlCodProduto); // Recebe o código do produto
                        while (ctrlCodProduto != 0){ // Bloco WHILE para verificação
                            for (i=0;i<100;i++){ // Bloco  para verificação de todos os produtos registrados
                                if (ctrlCodProduto == vetorProduto[i].codProduto){ // Sendo identificado o código inserido, inicia-se a apresentação do relatório
                                    linhaDiv();
                                    printf("%c Nome do produto                                   %c\n",186,186);
                                    printf("%c > %s",186,vetorProduto[i].nomeProduto,186); // Informa o nome do produto
                                    linhaDiv();
                                    printf("%c Valor do produto                                  %c\n",186,186);
                                    printf("%c > %-6.2f                                          %c\n",186,vetorProduto[i].valorProduto,186); // O valor registrado na base
                                    linhaDiv();
                                    printf("%c Quantidade em estoque                             %c\n",186,186);
                                    printf("%c > %-5i                                           %c\n",186,vetorProduto[i].quantEstoque,186); // A quantidade mais recente registrada em estoque
                                    linhaDiv();
                                    printf("%c Lote do produto                                   %c\n",186,186);
                                    printf("%c > %010i                                      %c\n",186,vetorProduto[i].lote,186); // O último lote de recebimento
                                    linhaDiv();
                                    printf("%c Total de unidades vendidas                        %c\n",186,186);
                                    printf("%c > %-5i                                           %c\n",186,vetorProduto[i].vendaProduto,186); // O total de unidades vendidas até o momento
                                    linhaDiv();linhaDiv();
                                    printf("%c          Pressione ENTER para continuar           %c\n",186,186);
                                    rodape();
                                    getch();
                                    ctrlCodProduto = 0; // Recebe 0 para demonstrar que já houve a identificação do código inserido
                                    break;
                                }
                            }
                            if (ctrlCodProduto != 0){ // Caso não tenha recebido 0, passa pelo tratamento de erro
                                invalida();
                                printf("%c                 RELAT%cRIO PRODUTO                 %c\n",186,224,186);
                                linhaDiv();
                                printf("%c Insira o c%cdigo do produto                        %c\n",186,162,186);
                                printf("%c > ",186);
                                scanf("%i",&ctrlCodProduto); // Recebe um novo código para verificação
                            }
                        }
                        break;
                    case 3: // Exibe o relatório das vendas já registradas
                        printf("%c                  RELAT%cRIO VENDA                  %c\n",186,224,186);
                        linhaDiv();
                        printf("%c Insira a data da venda                            %c\n",186,186);
                        printf("%c > ",186);
                        scanf("%s",&ctrlData); // Recebe uma data de venda, podendo ser personalizada (DD/MM/AAAA - recomendado)
                        while (strcmp(ctrlData,"") != 0){ // Bloco WHILE para verificação
                            for (i=0;i<31;i++){ // Bloco de repetição para verificação de todas as datas
                                if (strcmp(ctrlData,dataVenda[i]) == 0){ // Sendo identificado a data desejada, são apresentados os dados na base
                                    vendaMed = vendaMensal / ctrlMensal; // Faz o registro da venda média de acordo com o controle mensal de vendas
                                    linhaDiv();
                                    printf("%c M%cdia de vendas                                   %c\n",186,130,186);
                                    printf("%c > %-6.2f                                          %c\n",186,vendaMed,186); // Exibe a média de vendas registradas
                                    printf("%c Maior venda                                       %c\n",186,186);
                                    printf("%c > %-6.2f                                          %c\n",186,vendaMax,186); // Exibe a maior venda registrada
                                    printf("%c Menor venda                                       %c\n",186,186);
                                    printf("%c > %-6.2f                                          %c\n",186,vendaMin,186); // Exibe a menor venda registrada
                                    linhaDiv();
                                    printf("%c Produto mais vendido                              %c\n",186,186);
                                    printf("%c > %s",186,ctrlNomeProduto[0],186); // Exibe o produto mais vendido e sua quantidade
                                    printf("%c Quantidade: %05i                                 %c\n",186,ctrlVendaProduto[0],186);
                                    linhaDiv();
                                    printf("%c Produto menos vendido                             %c\n",186,186);
                                    printf("%c > %s",186,ctrlNomeProduto[1],186); // Exibe o produto menos vendido e sua quantidade
                                    printf("%c Quantidade: %05i                                 %c\n",186,ctrlVendaProduto[1],186);
                                    linhaDiv();
                                    printf("%c Total vendido no dia - %-15s            %c\n",186,dataVenda[i],186); // Exibe o total vendido no dia inserido
                                    printf("%c > %-6.2f                                          %c\n",186,vendaDiaria[i],186);
                                    printf("%c Total vendido este m%cs                            %c\n",186,136,186); // Exibe o total em reais vendido no mês
                                    printf("%c > %-6.2f                                          %c\n",186,vendaMensal,186);
                                    printf("%c Quantidade de vendas deste m%cs                    %c\n",186,136,186); // Exibe a quantidade de vendas do mês
                                    printf("%c > %-5i                                           %c\n",186,ctrlMensal,186);
                                    linhaDiv();linhaDiv();
                                    printf("%c          Pressione ENTER para continuar           %c\n",186,186);
                                    rodape();
                                    getch();
                                    strcpy(ctrlData,""); // Recebe um espaço vazio para demonstrar que já foi identificada a data
                                    break;
                                }
                            }
                            if (strcmp(ctrlData,"") != 0){ // Caso não tenha recebido um espaço vazio, inicia-se o tratamento de erro
                                invalida();
                                printf("%c                  RELAT%cRIO VENDA                  %c\n",186,224,186);
                                linhaDiv();
                                printf("%c Insira a data da venda                            %c\n",186,186);
                                printf("%c > ",186);
                                scanf("%s",&ctrlData); // Recebe uma nova data para verificação
                            }
                        }
                        break;
                    default: // Tratamento de exceção do menu de relatório
                        invalida();
                        printf("%c          Pressione ENTER para continuar           %c\n",186,186);
                        rodape();
                        getch();
                }
                break;
            case 3: // Caso o usuário deseje finalizar o sistema
                exe = 'N';
                break;
            default: // Tratamento de exceção do menu principal
                invalida();
                printf("%c          Pressione ENTER para continuar           %c\n",186,186);
                rodape();
                getch();
        }
    }
    if (exe == 'N'){ // Se o usuário desejar finalizar, o programa é encerrado e é solicitado ao mesmo que feche a aplicação
        system("cls");
        cabecalho();
        logo();
        rodape();cabecalho();
        printf("%c             Programa sendo encerrado              %c\n",186,186);
        linhaDiv();linhaDiv();
        printf("%c          Pressione ENTER para finalizar           %c\n",186,186);
        rodape();
        getch();
    }
    return 0;
}
