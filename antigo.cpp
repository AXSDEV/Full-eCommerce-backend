#include <iostream>  // biblioteca padrão de entrada e saída
#include <iomanip>   // para usar manipuladores de entrada e saida para controlar a formatação dos dados
#include <string>    // para usar strings
#include <ctime>     // para adicionar horas e datas (talao)
#include <sstream>   // para poder usar setprecision em strings || deixa-me usar manipulador de strings
#include <windows.h> // necessario para usar sleep
#include <algorithm> // necessario para transform
#include <cctype>    // necessario para tolower
#include <conio.h>   // para usar _getch() para esconder a senha no login
// \033 é o escape para iniciar ANSI 27 | [0m é para repor para formatação padrão | [31m é para cor vermelho | [32m é para cor verde
#define RESET "\033[0m"          // Define a cor de texto para padrão
#define RED "\033[31m"           // Define a cor de texto para vermelho
#define GREEN "\033[32m"         // Define a cor de texto para verde
#define BRIGHT_YELLOW "\033[93m" // Define a cor de texto amarelo brilhante
// ASCII é um padrão de codificação de caracteres
// ANSI é para códigos especiais que controlam a aparência do texto no terminal.
using namespace std;

int totalProdutos = 3;
int colunas = 4; // ID, Nome, Quantidade, Preco
int maximoProdutos = 100;
string **produto = new string *[maximoProdutos];
int numeroFatura = 1;
int numeroCliente = 1;
int capacidadeCarrinho = 50;
int linhacarrinho = 0;

// Funções
void inicializarProdutos();
void produtosDisponiveis();
void adicionarCarrinho(string **carrinho);
void adicionarProduto();
void eliminarProduto();
bool sortearVendaGratis();
void processarCheckout(string **carrinho);
void imprimirTalao(string **carrinho, double total, double valorPago, double troco, bool gratis);
void menu(string **carrinho);
void eliminarCarrinho(string **carrinho);
void mostrarCarrinho(string **carrinho);
void modificarPreco(double novoPrecoT, string id);
void printCarrinho(string **carrinho, double total);
void limparCarrinho(string **carrinho);
void asciiart();

bool login()
{
    string utilizador, senha, senhaEscondida;
    char caracter;

    cout << "====== LOGIN ADMIN ======";
    cout << "\n Utilizador: ";
    getline(cin, utilizador); // Lê a linha inteira, mesmo com espaços (ex: "admin arroz")
    cout << "\n Palavra-Passe: ";

    // Ler a senha sem mostrá-la
    while ((caracter = _getch()) != 13) // Repete até carregar ENTER (ASCII 13)
    {
        if (caracter == 8 && !senhaEscondida.empty()) // BACKSPACE (ASCII 8) apaga último char
        {
            senhaEscondida.pop_back();
            cout << "\b \b"; // Apaga último caracteres no terminal
        }
        else if (caracter != 8)
        {
            senhaEscondida.push_back(caracter); // Adiciona os caracteres digitados na string senhaEscondida
            cout << "*";                        // Mostra * por cada caracter digitado
        }
    }

    senha = senhaEscondida;

    if (utilizador == "admin" && senha == "admin123")
    {
        system("CLS");
        cout << GREEN
             << "Bem-Vindo!"
             << RESET;
        asciiart();
        Sleep(3000);

        return true;
    }
    cout << RED << endl
         << "\nAs credenciais sao invalidas!\n"
         << RESET;
    return false;
}

void asciiart()
{

    // R(...) é uma raw string (texto puro), útil para desenhar ASCII sem escapar caracteres
    cout << BRIGHT_YELLOW << endl
         << R"(
.------------------------------------------------------------------------------------------.
|                       ___           ___           ___           ___                      |
|                      /\__\         /\  \         /\  \         /\  \                     |
|                     /::|  |       /::\  \        \:\  \       /::\  \                    |
|                    /:|:|  |      /:/\:\  \        \:\  \     /:/\:\  \                   |
|                   /:/|:|  |__   /:/  \:\  \       /::\  \   /::\~\:\  \                  |
|                  /:/ |:| /\__\ /:/__/ \:\__\     /:/\:\__\ /:/\:\ \:\__\                 |
|                  \/__|:|/:/  / \:\  \ /:/  /    /:/  \/__/ \:\~\:\ \/__/                 |
|                      |:/:/  /   \:\  /:/  /    /:/  /       \:\ \:\__\                   |
|                      |::/  /     \:\/:/  /     \/__/         \:\ \/__/                   |
|                      /:/  /       \::/  /                     \:\__\                     |
|                      \/__/         \/__/                       \/__/                     |
|                       ___           ___           ___           ___                      |
|                      /\  \         /\  \         /\  \         /\__\                     |
|                     /::\  \       /::\  \       /::\  \       /:/  /                     |
|                    /:/\:\  \     /:/\:\  \     /:/\:\  \     /:/__/                      |
|                   /::\~\:\__\   /:/  \:\  \   /:/  \:\  \   /::\__\____                  |
|                  /:/\:\ \:|__| /:/__/ \:\__\ /:/__/ \:\__\ /:/\:::::\__\                 |
|                  \:\~\:\/:/  / \:\  \ /:/  / \:\  \ /:/  / \/_|:|~~|~                    |
|                   \:\ \::/  /   \:\  /:/  /   \:\  /:/  /     |:|  |                     |
|                    \:\/:/  /     \:\/:/  /     \:\/:/  /      |:|  |                     |
|                     \::/__/       \::/  /       \::/  /       |:|  |                     |
|                      ~~            \/__/         \/__/         \|__|                     |
'------------------------------------------------------------------------------------------'
    )" << endl
         << RESET;
}

void inicializarProdutos()
{
    for (int i = 0; i < maximoProdutos; i++)
    {
        produto[i] = new string[colunas];
    }
    // produto 1
    produto[0][0] = "1";
    produto[0][1] = "Lapis";
    produto[0][2] = "20";
    produto[0][3] = "0.20";

    // produto 2
    produto[1][0] = "2";
    produto[1][1] = "Caneta";
    produto[1][2] = "20";
    produto[1][3] = "0.40";

    // produto 3
    produto[2][0] = "3";
    produto[2][1] = "Caderno";
    produto[2][2] = "20";
    produto[2][3] = "1.50";
}

// Imprime os produtos default
void produtosDisponiveis()
{
    cout << "Produtos Disponiveis " << endl;

    // Cabeçalho
    cout << left << setw(5) << "ID"
         << setw(20) << "Nome"
         << setw(10) << "Qnt"
         << setw(10) << "Preco" << endl;

    // Lista de produtos
    for (int i = 0; i < totalProdutos; i++)
    {
        cout << left << setw(5) << produto[i][0]
             << setw(20) << produto[i][1]
             << setw(10) << produto[i][2]
             << setw(10) << produto[i][3];

        cout << endl;
    }
}

// Inicialização do toLower
string toLower(string nomeProduto)
{
    transform(nomeProduto.begin(), nomeProduto.end(), nomeProduto.begin(), ::tolower); // transforma em lowercase
    return nomeProduto;                                                                // envia o nome em lowercase para variavel
}

// Adiciona Produtos
void adicionarProduto()
{
    int nProdAdicionar;

    cout << "Quantos produtos deseja adicionar? ";
    // Repete até inserir número > 0
    while (!(cin >> nProdAdicionar) || nProdAdicionar < 0)
    {
        // Repete se não for número ou se for ≤ 0 (evita crash ao inserir texto)
        cout << endl
             << RED
             << "Atencao, apenas pode inserir numeros e tem de ser maior que 0.\n"
             << RESET;
        cout << endl
             << "Quantos produtos deseja adicionar? ";
        cin.clear();            // Limpa o erro para permitir nova entrada
        cin.ignore(1000, '\n'); // Ignora até 1000 caracteres ou até o ENTER
    }

    if (nProdAdicionar + totalProdutos >= maximoProdutos)
    {
        cout << RED << "Limite maximo de produtos atingido.\n"
             << RESET;
        return;
    }
    for (int i = 0; i < nProdAdicionar; i++)
    {
        int qnt;
        double precoT; // Preco Temporario
        string nome;
        bool produtoExiste = false;

        cout << "Nome: ";
        cin.ignore();       // Limpa o buffer para evitar ler apenas até o espaço
        getline(cin, nome); // Lê a linha inteira até o ENTER, incluindo espaços

        string nomeInserido = toLower(nome); // Converte o nome para minúsculas para comparação

        for (int j = 0; j < totalProdutos; j++)
        {
            string nomeExistente = toLower(produto[j][1]); // Converte nome do produto para minúsculas para comparação

            // Verifica se o produto já existe, se sim, adiciona à quantidade
            if (nomeExistente == nomeInserido) // Se os nomes coincidirem, o produto já existe
            {
                cout << "Produto ja existe. Que quantidade deseja adicionar?\n";
                // Repete até o utilizador inserir um número maior que 0
                while (!(cin >> qnt) || qnt <= 0)
                {
                    cout << endl
                         << RED
                         << "Atencao, apenas pode inserir numeros e tem de ser maior que 0.\n"
                         << RESET;
                    cout << endl
                         << "Quantidade: ";
                    cin.clear();            // Limpa o erro para permitir uma nova entrada
                    cin.ignore(1000, '\n'); // Ignora até 1000 caracteres ou até o ENTER
                }

                int qntAtual = stoi(produto[j][2]); // Converte a quantidade de produto em string para inteiro
                produto[j][2] = to_string(qntAtual + qnt);
                produtoExiste = true;
                cout << "O estoque foi atualizado.";
                Sleep(2000);
                break;
            }
        }

        // Se não existir, cria um novo
        if (!produtoExiste)
        {
            produto[totalProdutos][0] = to_string(totalProdutos + 1); // Converte o ID para string e incrementa automaticamente
            produto[totalProdutos][1] = nome;

            cout << "Quantidade: ";
            // Repete até o utilizador inserir um número maior que 0
            while (!(cin >> qnt) || qnt < 0)
            {
                cout << endl
                     << RED
                     << "Atencao, apenas pode inserir numeros e tem de ser maior que 0.\n"
                     << RESET;
                cout << endl
                     << "Quantidade: ";
                cin.clear();            // Limpa o erro para permitir uma nova entrada
                cin.ignore(1000, '\n'); // Ignora até 1000 caracteres ou até o ENTER
            }
            produto[totalProdutos][2] = to_string(qnt);

            cout << "Preco: ";
            // Repete até o utilizador inserir um número maior que 0
            while (!(cin >> precoT) || precoT < 0)
            {
                cout << endl
                     << RED
                     << "Atencao, apenas pode inserir numeros e tem de ser maior que 0.\n"
                     << RESET;
                cout << endl
                     << "Preco: ";
                cin.clear();            // Limpa o erro para permitir uma nova entrada
                cin.ignore(1000, '\n'); // Ignora até 1000 caracteres ou até o ENTER
            }

            ostringstream conversao;                         // Permite formatar dados e convertê-los para string
            conversao << fixed << setprecision(2) << precoT; // Formata o preço com 2 casas decimais
            produto[totalProdutos][3] = conversao.str();

            totalProdutos++;
        }
    }
    // Se adicionar apenas 1
    if (nProdAdicionar == 1)
    {
        cout << GREEN << endl
             << "Produto adicionado.\n"
             << RESET;
        Sleep(2000);
    }
    // Se adicionar mais que 1
    if (nProdAdicionar > 1)
    {
        cout << GREEN << endl
             << "Produtos adicionados.\n"
             << RESET;
        Sleep(2000);
    }
    // Imprime autalizacao de estoque
    system("CLS");
    cout << "|=============| ";
    cout << "Atualizacao de estoque "; // Mostra os produtos adicionados.
    cout << " |==============|\n";
    produtosDisponiveis();
}

// Eliminar produto
void eliminarProduto()
{
    int nProdEliminar;
    cout << "Quantos produtos deseja eliminar? ";

    while (!(cin >> nProdEliminar) || nProdEliminar < 0)
    {
        cout << endl
             << RED
             << "Atencao, apenas pode inserir numeros e tem de ser maior que 0.\n"
             << RESET;
        cout << endl
             << "Quantos produtos deseja eliminar? ";
        cin.clear();            // Limpa o erro para permitir uma nova entrada
        cin.ignore(1000, '\n'); // Ignora até 1000 caracteres ou até o ENTER, limpando o buffer
    }

    if (nProdEliminar > totalProdutos)
    {
        cout << RED
             << "Nao existem " << nProdEliminar << " produtos na loja."
             << RESET;
        return;
    }

    bool encontrado = false;

    for (int n = 0; n < nProdEliminar; n++)
    {
        string id;
        produtosDisponiveis();
        cout << "\nDigite o ID do produto a eliminar: ";
        cin >> id;

        for (int i = 0; i < totalProdutos; i++)
        {
            if (produto[i][0] == id)
            {
                for (int j = i; j < totalProdutos - 1; j++)
                {
                    for (int k = 0; k < colunas; k++)
                    {
                        produto[j][k] = produto[j + 1][k]; // Vai colocar a linha vazia em ultimo
                    }
                }
                totalProdutos--; // Elimina a ultima linha que se encontra vazia
                system("CLS");
                cout << RED
                     << "Produto eliminado. \n"
                     << RESET << endl;
                Sleep(2000);
                encontrado = true;
                break;
            }
        }
    }
    if (!encontrado)
    {
        cout << RED << "Produto nao encontrado.\n"
             << RESET;
    }
    cout << "Atualizacao de estoque : \n"; // Exibe os produtos restantes e atualiza o estoque
    produtosDisponiveis();
}

bool sortearVendaGratis() // Sorteio de venda gratis
{
    return (rand() % 10) == 0; // 10% de chance
}

void printCarrinho(string **carrinho)
{
    double total = 0.0;

    if (carrinho[0][0] == "")
    {
        cout << "O carrinho esta vazio." << endl
             << endl;
        return;
    }

    cout << "=== Carrinho de Compras ===\n";
    cout << "----------------------------------------------------------------\n";
    cout << "| ID  | Nome           | Qtd | Preco Unit. |  IVA  | Subtotal   |\n";
    cout << "----------------------------------------------------------------\n";

    for (int i = 0; i < linhacarrinho; i++)
    {
        string id = carrinho[i][0];
        string nome = carrinho[i][1];
        int quantidade = stoi(carrinho[i][2]);
        double precoVenda = stod(carrinho[i][3]);
        double iva = stod(carrinho[i][4]);
        double subtotal = stod(carrinho[i][5]);

        total += subtotal;

        cout << "| " << setw(3) << left << id << " | "
             << setw(14) << left << nome << " | "
             << setw(3) << right << quantidade << " | "
             << setw(11) << fixed << setprecision(2) << precoVenda << " | "
             << setw(5) << fixed << setprecision(2) << iva << " | "
             << setw(10) << fixed << setprecision(2) << subtotal << " |\n";
    }

    cout << "-----------------------------------------------------------------\n";
    cout << "| TOTAL A PAGAR: " << setw(46) << right << fixed << setprecision(2)
         << total << " |\n";
    cout << "-----------------------------------------------------------------\n";
}

void mostrarCarrinho(string **carrinho)
{
    int opcao;

    do
    {
        system("CLS");
        printCarrinho(carrinho);
        cout << "[1] Adicionar Produto ao carrinho\n";
        cout << "[2] Eliminar Produto do carrinho\n";
        cout << "[3] Checkout\n";
        cout << "[4] Voltar ao Menu Principal\n";
        cout << "\nEscolha uma opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            system("CLS");
            adicionarCarrinho(carrinho);
            break;
        case 2:
            system("CLS");
            eliminarCarrinho(carrinho);
            break;
        case 3:
            system("CLS");
            processarCheckout(carrinho);
            break;
        case 4:
            break;
        default:
            // Opcao invalida
            cout << endl
                 << "Opcao invalida. Tente novamente.\n";
            break;
        }
        if (opcao != 4)
        {

            cout << endl
                 << "Pressione ENTER para voltar ao menu do carrinho.";
            cin.ignore();
            cin.get();
        }
    } while (opcao != 4);
}

void eliminarCarrinho(string **carrinho)
{

    int nProdEliminarCarrinho;
    cout << "Quantos produtos deseja eliminar? ";

    while (!(cin >> nProdEliminarCarrinho) || nProdEliminarCarrinho < 0)
    {
        cout << endl
             << RED
             << "Atencao, apenas pode inserir numeros e tem de ser maior que 0.\n"
             << RESET;
        cout << endl
             << "Quantos produtos deseja eliminar? ";
        cin.clear();            // Limpa o erro para permitir uma nova entrada
        cin.ignore(1000, '\n'); // Ignora até 1000 caracteres ou até o ENTER, limpando o buffer
    }

    if (nProdEliminarCarrinho > capacidadeCarrinho)
    {
        cout << RED
             << "Nao existem " << nProdEliminarCarrinho << " produtos na loja."
             << RESET;
        return;
    }
    for (int n = 0; n < nProdEliminarCarrinho; n++)
    {
        string id;
        printCarrinho(carrinho);
        cout << "\nDigite o ID do produto a eliminar ou 'SAIR' para retornar ao Menu Principal : ";
        cin >> id;
        id = toLower(id);
        if (id == "sair")
            continue;

        bool encontrado = false;

        for (int i = 0; i < linhacarrinho; i++)
        {
            if (carrinho[i][0] == id)
            {
                for (int p = 0; p < totalProdutos; p++)
                {
                    if (produto[p][0] == id)
                    {
                        int qntEliminada = stoi(carrinho[i][2]);                   // Quantidade que tinha sido adicionado ao carrinho
                        int qntEstoqueAtual = stoi(produto[p][2]);                 // Quantidade no stock
                        produto[p][2] = to_string(qntEstoqueAtual + qntEliminada); // Soma do stock + quantidade eliminada do carrinho
                        break;
                    }
                }
                for (int j = i; j < linhacarrinho - 1; j++)
                {
                    for (int k = 0; k < 6; k++)
                    {
                        carrinho[j][k] = carrinho[j + 1][k]; // Vai colocar a linha vazia em ultimo
                    }
                }
                for (int n = 0; n < 6; n++)
                {
                    carrinho[linhacarrinho - 1][n].clear(); // .clear é usado para limpar o conteudo de uma string tornado-a em ""
                }

                linhacarrinho--; // Elimina a ultima linha que se encontra vazia
                cout << RED << endl
                     << "Produto eliminado. \n"
                     << RESET;
                encontrado = true;
                break;
            }
        }
        if (!encontrado)
        {
            cout << RED
                 << "Produto nao encontrado no carrinho.\n"
                 << RESET;
            return;
        }
    }
}

void adicionarCarrinho(string **carrinho)
{
    string continuar = "sim";

    do
    {
        system("CLS");
        produtosDisponiveis();
        cout << "ID do produto ou 'SAIR' para retornar ao Menu Principal: ";
        string id;
        cin >> id;
        id = toLower(id);
        if (id == "sair")
            break;

        bool encontrado = false;
        for (int i = 0; i < totalProdutos; i++)
        {
            if (produto[i][0] == id)
            {
                encontrado = true;

                int quantidade;
                int stockAtual = stoi(produto[i][2]);

                cout << endl
                     << "Produto: " << produto[i][1] << endl;
                cout << "Quantidade disponivel: " << produto[i][2] << endl;

                cout << "Digite quantidade desejada: ";
                while (!(cin >> quantidade) || quantidade <= 0)
                {
                    cout << "Atencao, apenas pode inserir numeros e tem de ser maior que 0.\n";
                    cout << "Digite quantidade desejada: ";
                    cin.clear(); // Limpa o erro
                    cin.ignore(1000, '\n');
                }
                if (quantidade > stockAtual)
                {
                    cout << "Quantidade invalida ou insuficiente no estoque! Tente novamente.\n";
                    continue;
                }

                double precoCusto = stod(produto[i][3]);
                double precoVenda = precoCusto * 1.30;
                double iva = precoVenda * 0.23;
                double subtotal = (iva + precoVenda) * quantidade;

                if (linhacarrinho >= capacidadeCarrinho)
                {
                    cout << RED
                         << "Carrinho cheio! Finalize a compra ou limpe o carrinho.\n"
                         << RESET;
                    break;
                }

                carrinho[linhacarrinho][0] = produto[i][0];
                carrinho[linhacarrinho][1] = produto[i][1];
                carrinho[linhacarrinho][2] = to_string(quantidade);
                carrinho[linhacarrinho][3] = to_string(precoVenda);
                carrinho[linhacarrinho][4] = to_string(iva);
                carrinho[linhacarrinho][5] = to_string(subtotal);

                linhacarrinho++;

                produto[i][2] = to_string(stockAtual - quantidade);

                cout << GREEN
                     << "Produto " << produto[i][0] << " adicionado ao carrinho!\n"
                     << RESET;
                break;
            }
        }
        if (!encontrado)
        {
            cout << RED
                 << "Produto nao encontrado!\n"
                 << RESET;
        }

        cout << "Deseja escolher outro produto? (sim/nao): ";
        cin >> continuar;

        continuar = toLower(continuar);

    } while (continuar == "sim");
}

void processarCheckout(string **carrinho)
{
    double total = 0.0;
    if (carrinho[0][0] == "")
    {
        cout << RED
             << "O carrinho encontra-se vazio.\n"
             << RESET;
        return;
    }
    else
    {
        cout << "\nResumo da Compra:\n";
        cout << "----------------------------------------------------------------\n";
        cout << "| ID  | Nome           | Qtd | Preco Unit. |  IVA  | Subtotal   |\n";
        cout << "----------------------------------------------------------------\n";

        for (int i = 0; i < linhacarrinho; i++)
        {
            string id = carrinho[i][0];
            string nome = carrinho[i][1];
            int quantidade = stoi(carrinho[i][2]);
            double precoVenda = stod(carrinho[i][3]);
            double iva = stod(carrinho[i][4]);
            double subtotal = stod(carrinho[i][5]);

            total += subtotal;

            cout << "| " << setw(3) << left << id << " | "
                 << setw(14) << left << nome << " | "
                 << setw(3) << right << quantidade << " | "
                 << setw(11) << fixed << setprecision(2) << precoVenda << " | "
                 << setw(5) << fixed << setprecision(2) << iva << " | "
                 << setw(10) << fixed << setprecision(2) << subtotal << " |\n";
        }

        cout << "-----------------------------------------------------------------\n";
        cout << "| TOTAL A PAGAR: " << setw(46) << right << fixed << setprecision(2)
             << total << " |\n";
        cout << "-----------------------------------------------------------------\n";
    }

    bool gratis = sortearVendaGratis();
    double valorPago = 0.0;
    double troco = 0.0;

    if (gratis)
    {
        cout << "\nParabens! A sua compra foi gratuita!\n";
        total = 0.0;
    }
    else
    {
        cout << "\nTotal a pagar: " << fixed << setprecision(2) << total << " euros\n";

        do
        {
            cout << "Insira o Valor recebido ou escreva 0 voltar ao Menu, se desejar cancelar a compra escreva -1.\n";
            cout << "Valor recebido: ";
            cin >> valorPago;

            if (valorPago == 0)
                return;
            if (valorPago == -1)
            {
                for (int i = 0; i < linhacarrinho; i++)
                {
                    int qntCarrinho = stoi(carrinho[i][2]);

                    for (int j = 0; j < totalProdutos; j++)
                    {
                        if (produto[j][0] == carrinho[i][0])
                        {
                            int stockAtual = stoi(produto[j][2]);

                            produto[j][2] = to_string(stockAtual + qntCarrinho); // Devolver a quantidade do carrinho ao stock
                            break;
                        }
                    }
                }
                limparCarrinho(carrinho);
                system("CLS");
                cout << RED
                     << "A sua compra foi cancelada.\n"
                     << RESET;
                return;
            }

            if (valorPago < total)
            {
                cout << RED
                     << "Valor insuficiente!\n"
                     << RESET;
            }
        } while (valorPago < total);

        troco = valorPago - total;
    }

    imprimirTalao(carrinho, total, valorPago, troco, gratis);

    numeroFatura++;
    numeroCliente++;
    // Limpar o carrinho após o checkout
    limparCarrinho(carrinho);
}

void limparCarrinho(string **carrinho)
{ // Limpar o carrinho
    for (int i = 0; i < linhacarrinho; i++)
    {

        for (int j = 0; j < 6; j++)
        {

            carrinho[i][j].clear();
        }
    }

    linhacarrinho = 0;
}

void imprimirTalao(string **carrinho, double total, double valorPago, double troco, bool gratis)
{
    system("CLS");
    cout << "\n\n==================== TALAO DE COMPRA ====================\n";
    time_t agora = time(0);
    tm tempoLocal;
    localtime_s(&tempoLocal, &agora);
    cout << "Data: " << tempoLocal.tm_mday << "/" << tempoLocal.tm_mon + 1 << "/" << tempoLocal.tm_year + 1900 << "\n";
    cout << "Fatura n: " << numeroFatura << " | Cliente n: " << numeroCliente << endl;
    cout << "---------------------------------------------------------\n";
    cout << left << setw(15) << "Produto" << setw(10) << "Qtd" << setw(15) << "Preco S/IVA" << setw(10) << "IVA" << setw(10) << "Total" << endl;
    cout << "---------------------------------------------------------\n";

    for (int i = 0; i < linhacarrinho; i++)
    {
        cout << left << setw(15) << carrinho[i][1]
             << setw(10) << carrinho[i][2]
             << setw(15) << fixed << setprecision(2) << stod(carrinho[i][3])
             << setw(10) << fixed << setprecision(2) << stod(carrinho[i][4])
             << setw(10) << fixed << setprecision(2) << stod(carrinho[i][5]) << endl;
    }
    cout << "---------------------------------------------------------\n";

    if (gratis)
    {
        cout << GREEN
             << "COMPRA GRATUITA!\n"
             << RESET;
    }
    else
    {
        cout << "Total: " << fixed << setprecision(2) << total << " euros\n";
        cout << "Valor pago: " << fixed << setprecision(2) << valorPago << " euros\n";
        cout << "Troco: " << fixed << setprecision(2) << troco << " euros\n";
    }

    cout << "=========================================================\n";
    cout << "Obrigado pela sua preferencia!\n";
}

void modificarPreco()
{
    double novoPrecoT;
    string id;
    string continuar = "sim";
    bool encontrado = false;

    do
    {
        produtosDisponiveis();
        cout << endl
             << "Insira o ID do produto a qual deseja modificar o preco ou 'SAIR' para retornar ao Menu Principal: ";
        cin >> id;
        id = toLower(id);

        if (id == "sair")
            break;

        for (int i = 0; i < totalProdutos; i++)
        {
            if (id == produto[i][0])
            {
                encontrado = true;
                cout << endl
                     << "Preco atual: " << produto[i][3] << endl;
                cout << endl
                     << "Insira o novo preco do produto: ";

                while (!(cin >> novoPrecoT) || novoPrecoT < 0)
                {
                    cout << RED << endl
                         << "Atencao, apenas pode inserir numeros e tem de ser maior que 0.\n"
                         << RESET;
                    cout << endl
                         << "Preco: ";
                    cin.clear();            // Limpa o erro para permitir uma nova entrada
                    cin.ignore(1000, '\n'); // Ignora até 1000 caracteres ou até o ENTER, limpando o buffer
                }

                ostringstream novoFormatado;                             // Permite formatar números e convertê-los para string
                novoFormatado << fixed << setprecision(2) << novoPrecoT; // Formata o preço com 2 casas decimais
                produto[i][3] = novoFormatado.str();
            }
        }
        if (!encontrado)
        {
            cout << RED
                 << "Produto nao encontrado.\n"
                 << RESET;
            break;
        }
        system("CLS");
        cout << GREEN << "Preco modificado com sucesso." << RESET;
        Sleep(2000);
        cout << endl
             << "Deseja modificar mais algum preco? (sim/nao)\n";
        cin >> continuar;
        system("CLS"); // Limpa a tela
        continuar = toLower(continuar);

    } while (continuar == "sim");

    cout << "|=============| ";
    cout << "Atualizacao de precos ";
    cout << " |==============|\n";
    produtosDisponiveis();
}

void menu(string **carrinho)
{
    int opcao;

    do
    {
        system("CLS"); // Limpa a tela
        cout << endl
             << BRIGHT_YELLOW << "|=============| "
             << "Papelaria Note & Book"
             << " |==============|\n"
             << RESET;
        cout << endl;
        cout << "[1] Produtos Disponiveis\n";
        cout << "[2] Carrinho\n";
        cout << "[3] Checkout\n";
        cout << "[4] Adicionar Produto\n";
        cout << "[5] Eliminar Produto\n";
        cout << "[6] Modificar Preco\n";
        cout << "[7] Sair\n";
        cout << "Escolha uma opcao: ";

        if (!(cin >> opcao))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Apenas pode inserir numeros. Por favor tente novamente.\n";
        }

        switch (opcao)
        {
        case 1:
            // Mostrar produtos disponíveis
            system("CLS"); // Limpa a tela
            produtosDisponiveis();
            break;
        case 2:
            // Comprar produto
            system("CLS"); // Limpa a tela
            mostrarCarrinho(carrinho);
            break;
        case 3:
            // carrinho
            system("CLS"); // Limpa a tela
            processarCheckout(carrinho);
            break;
        case 4:
            // Adicionar produto
            system("CLS"); // Limpa a tela
            adicionarProduto();
            break;
        case 5:
            // Eliminar produto
            system("CLS"); // Limpa a tela
            eliminarProduto();
            break;
        case 6:
            // Modificar preço do produto
            system("CLS"); // Limpa a tela
            modificarPreco();
            break;
        case 7:
            cout << RED << endl
                 << "A desligar o programa...\n"
                 << RESET;
            break;
        default:
            // Opcao invalida
            cout << endl
                 << "Opcao invalida. Tente novamente.\n";
            break;
        }
        if (opcao != 7)
        {
            cout << endl
                 << "Pressione Enter para voltar ao menu.";
            cin.ignore();
            cin.get(); // Espera o utilizador pressionar Enter
        }
    } while (opcao != 7); // Repete o menu até sair do programa
}

int main()
{
    while (login() == false)
    {
        cout << RED
             << "Tente novamente.\n"
             << RESET;
    }

    inicializarProdutos();

    string **carrinho = new string *[capacidadeCarrinho];

    for (int i = 0; i < capacidadeCarrinho; i++)
    {
        carrinho[i] = new string[6]; // 6 colunas: ID, Nome, Quantidade, Preço, IVA, Subtotal
    }
    menu(carrinho);
}
