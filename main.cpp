#include <stdlib.h>
#include <iostream>
#include <vector>

using std:: cout;
using std:: cin;
using std:: vector;

void entrada_de_dados (struct usuario*); // entrada dos dados do usuário
int calc_tempo_manha (int,struct usuario*); //cálculo do tempo trabalhado de manhã
int calc_atraso_manha (int, struct usuario*); //cálculo do atraso de manhã
int min_entrada_manha (int, struct usuario*); //conversão da hora de entrada da manhã em minutos
int min_saida_manha (int, struct usuario*); //conversão da hora de saída da manhã em minutos
int calc_tempo_tarde (int, struct usuario*); //cálculo do tempo trabalhado de tarde
int calc_atraso_tarde (int, struct usuario*); //cálculo do atraso de tarde
int min_entrada_tarde (int, struct usuario*); //conversão da hora de entrada da tarde em minutos
int min_saida_tarde (int, struct usuario*); //conversão da hora de saída da tarde em minutos
void calculo (); // cálculo total de horas
void impressao (struct usuario*); //impressão dos dados na tela

struct cartao_de_ponto
{
    int dia; //Dia
    int entrada_manha; // Horário de entrada da manhã
    int saida_manha; //Horário de saída da manhã
    int entrada_tarde; //Horário de entrada da tarde
    int saida_tarde; //Horário de saída da tarde
    int total_horas_dia;
    int total_atraso_dia;
};

struct usuario
{
    char nome [20];
    char sobrenome [20];
    char diretoria [20];
    struct cartao_de_ponto cartao[31];
};

bool teste;
int cont = 0;

int main(int argc, char **argv)
{
    cout << "Ola! Bem-vindo(a) ao Módulo de controle de ponto do Fab Lab Belém (Versão 1.0)\n\n";
    
    /*char cod [5];
    
    cout << "Insira o codigo do(a) voluntario(a): ";
    cin >> cod;
    cout << "\n";*/
    
    usuario cod;
    
    cout << "Insira o nome do(a) voluntario(a): ";
    cin >> cod.nome;
    cout << "\n";
    
    cout << "Insira o sobrenome do(a) voluntario(a): ";
    cin >> cod.sobrenome;
    cout << "\n";
    
    cout << "Diretoria onde atua: ";
    cin >> cod.diretoria;
    cout << "\n\n";
    
    entrada_de_dados (&cod);
    
    calculo;
    
    impressao;

    return 0;
}

void entrada_de_dados (struct usuario *user)
{
    teste = false;
    
    char escolha;
    
    while ( teste == false )
    {
        cont += 1;
        
        cout << "Insira o dia do cartão de ponto: ";

        while ( teste == false )
        {
            teste = true;
            
            cin >> user->cartao[cont].dia;
            
            if ( user->cartao[cont].dia < 1 )
                {
                    teste = false;
                    
                    cout << "Data inválida. Insira o dia do cartão de ponto: ";
                }
                else if ( user->cartao[cont].dia > 31 )
                {
                    teste = false;
                    
                    cout << "Data inválida. Insira o dia do cartão de ponto: ";
                }

        }

        cout << "Horário de entrada da manhã (DIA " << user->cartao[cont].dia <<"): ";
        cin >> user->cartao[cont].entrada_manha;
        
        cout << "Horário de saída da manhã (DIA " << user->cartao[cont].dia <<"): ";
        cin >> user->cartao[cont].saida_manha;
        
        cout << "Horário de entrada da tarde (DIA " << user->cartao[cont].dia <<"): ";
        cin >> user->cartao[cont].entrada_tarde;
        
        cout << "Horário de saída da tarde (DIA " << user->cartao[cont].dia <<"): ";
        cin >> user->cartao[cont].saida_tarde;
        
        cout << "Deseja entrar com uma nova data? ( S / N )";
        cin >> escolha;
        
        switch (escolha)
        {
            case 'S': teste = true;
            case 's': teste = true;
            case 'N': teste = false;
            case 'n': teste = false;
        }
    }
}

int calc_tempo_manha (int i, struct usuario *user)
{
    int me;
    int ms;
    
    me = min_entrada_manha (i, user);
    ms = min_saida_manha (i, user);
    return ms - me;
}

int calc_atraso_manha (int i, struct usuario *user)
{
    int me;
    
    me = min_entrada_manha (i, user);
    if ( me > 480 )
    {
       return me - 480;
    }
    else return 0;
}

int min_entrada_manha (int i, struct usuario *user)
{
    return ( user->cartao[i].entrada_manha / 100 ) * 60 + ( user->cartao[i].entrada_manha % 100 );
}

int min_saida_manha (int i, struct usuario *user)
{
    return ( user->cartao[i].saida_manha / 100 ) * 60 + ( user->cartao[i].saida_manha % 100 );
}

int calc_tentrada_manhapo_tarde (int i, struct usuario *user)
{
    int me;
    int ms;
    
    me = min_entrada_tarde (i, user);
    ms = min_saida_tarde (i, user);
    return ms - me;
}

int calc_atraso_tarde (int i, struct usuario *user)
{
    int me;
    
    me = min_entrada_tarde (i, user);
    if ( me > 840 )
    {
       return me - 840;
    }
    else return 0;
}

int min_entrada_tarde (int i, struct usuario *user)
{
    return ( user->cartao[i].entrada_tarde / 100 ) * 60 + ( user->cartao[i].entrada_tarde % 100 );
}

int min_saida_tarde (int i, struct usuario *user)
{
    return ( user->cartao[i].saida_tarde / 100 ) * 60 + ( user->cartao[i].saida_tarde % 100 );
}

void calculo (struct usuario *user)
{
    int atraso_manha;
    int atraso_tarde;
    int horas_manha;
    int horas_tarde;
    int total_horas_mes;
    int total_atrasos_mes;
    double media_horas;
    double media_atrasos;
    
    for ( int i = 1; i < cont; i++ )
    {
        horas_manha = calc_tempo_manha (i, user);
        horas_tarde = calc_tempo_tarde (i, user);
        atraso_manha = calc_atraso_manha (i, user);
        atraso_tarde = calc_atraso_manha (i, user);         
        
        user->cartao[i].total_horas_dia = horas_manha + horas_tarde;
        user->cartao[i].total_atraso_dia = atraso_manha + atraso_tarde;

        total_horas_mes += user->cartao[i].total_horas_dia;
        total_atrasos_mes += user->cartao[i].total_atraso_dia;
    }

    media_horas = total_horas_mes / (cont);
    media_atrasos = total_atrasos_mes / (cont);
}

void impressao (struct usuario *user)
{
    cout << "RELATÓRIO DE PONTO DO MÊS \n";
    
    for ( int i = 1; i < cont; i++ )
    {
        cout << "DIA " << user->cartao[i].dia << "\n";
        
        if (user->cartao[i].entrada_manha) % 100 < 10
        {
            cout << "Entrada Manhã: " << (user->cartao[i].entrada_manha / 100) << ":0" << (user->cartao[i].entrada_manha % 100) << "\n";
        }
        else cout << "Entrada Manhã: " << (user->cartao[i].entrada_manha / 100) << ":" << (user->cartao[i].entrada_manha % 100)) << "\n";    
            
        If (user->cartao[i].saida_manha % 100) < 10
        {
            cout << "Saída Manhã: " << (user->cartao[i].saida_manha / 100) << ":0" << (user->cartao[i].saida_manha % 100) << "\n";
        }
        else cout << "Saída Manhã: " << (user->cartao[i].saida_manha / 100) << ":" << (user->cartao[i].saida_manha % 100) << "\n";
        
        if (user->cartao[i].entrada_tarde % 100) < 10
        {
            cout << "Entrada Tarde: " << (user->cartao[i].entrada_tarde / 100) << ":0" << (user->cartao[i].entrada_tarde % 100) << "\n";
        }
        else cout << "Entrada Tarde: " << (user->cartao[i].entrada_tarde / 100) < ":" << (user->cartao[i].entrada_tarde % 100) << "\n";    
        
        if (user->cartao[i].saida_tarde % 100) < 10
        {
            cout << "Saída Tarde: " << (user->cartao[i].saida_tarde / 100) << ":0" << (user->cartao[i].saida_tarde % 100) << "\n";
        }
        else cout << "Saída Tarde: " << (user->cartao[i].saida_tarde / 100) << ":" << (user->cartao[i].saida_tarde % 100) << "\n";
                
        if (user->cartao[i].total_horas_dia % 60) < 10
        {
            cout << "Total de horas trabalhadas no dia: " << ((total_dia[i].horas) / 60) << "h0" << ((total_dia[i].horas) % 60) << "min" << "\n";
        }
        else cout << "Total de horas trabalhadas no dia: " << ((total_dia[i].horas) / 60) << "h" << ((total_dia[i].horas) % 60) << "min" << "\n";
        
        if (user->cartao[i].total_atrasos_dia % 60) < 10
        {
            cout << "Tempo de atraso no dia: " << ((total_dia[i].atrasos) / 60) << "h0" << ((total_dia[i].atrasos) % 60) << "min" << "\n";
        }
        else cout << "Tempo de atraso no dia: " << ((total_dia[i].atrasos) / 60) << "h" << ((total_dia[i].atrasos) % 60) << "min" << "\n";
    }

    cout << "\n\n";
    
    if (total_horas_mes % 60) < 10
    {
        cout << "Tempo de horas trabalhadas no mês: " << ((total_horas) / 60) << "h0" << ((total_horas) % 60) << "min \n";
    }
    else cout << "Tempo de horas trabalhadas no mês: " << ((total_horas) / 60) << "h" << ((total_horas) % 60) << "min \n";
    
    if (total_atrasos_mes % 60) < 10
    {
        cout << "Tempo de atraso no mês: " << ((total_atrasos) / 60) << "h0" << ((total_atrasos) % 60) << "min \n";
    }
    else cout << "Tempo de atraso no mês: " << ((total_atrasos) / 60) << "h" << ((total_atrasos) % 60) << "min \n";
    
    if (media_horas % 60) < 10
    {
        cout << "Média de horas trabalhadas por dia: " << ((media_horas) / 60) << "h0" << ((media_horas) % 60) << "min \n";
    }
    else cout << "Média de horas trabalhadas por dia: " << ((media_horas) / 60) << "h" << ((media_horas) % 60) << "min \n";
    
    if (media_atrasos % 60) < 10
    {
        cout << "Média de atraso por dia: " << ((media_atrasos) / 60) << "h0" << ((media_atrasos) % 60) << "min \n";
    }
    else cout << "Média de atraso por dia: " << ((media_atrasos) / 60) << "h" << ((media_atrasos) % 60) << "min \n";
}