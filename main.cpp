#include <stdlib.h>
#include <iostream>
#include <vector>

using std:: cout;
using std:: cin;
using std:: vector;

void entrada_de_dados (struct usuario*); // entrada dos dados do usuário
void tempo_manha (); //cálculo do tempo trabalhado de manhã
void min_entrada_manha (); //conversão da hora de entrada da manhã em minutos
void min_saida_manha (); //conversão da hora de saída da manhã em minutos
void tempo_tarde (); //cálculo do tempo trabalhado de tarde
void min_entrada_tarde (); //conversão da hora de entrada da tarde em minutos
void min_saida_tarde (); //conversão da hora de saída da tarde em minutos
void calculo (); // cálculo total de horas
void impressao (); //impressão dos dados na tela

struct cartao_de_ponto
{
    int dia; //Dia
    int em; // Horário de entrada da manhã
    int sm; //Horário de saída da manhã
    int et; //Horário de entrada da tarde
    int st; //Horário de saída da tarde
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
            
            cin >> user.cartao[cont].dia;
            
            if ( user.cartao[cont].dia < 1 )
                {
                    teste = false;
                    
                    cout << "Data inválida. Insira o dia do cartão de ponto: ";
                }
                else    if ( user.cartao[cont].dia > 31 )
                {
                    teste = false;
                    
                    cout << "Data inválida. Insira o dia do cartão de ponto: ";
                }

        }

        cout << "Horário de entrada da manhã (DIA " << user.cartao[cont].dia <<"): ";
        cin >> *user.cartao[cont].em;
        
        cout << "Horário de saída da manhã (DIA " << user.cartao[cont].dia <<"): ";
        cin >> user.cartao[cont].sm;
        
        cout << "Horário de entrada da tarde (DIA " << user.cartao[cont].dia <<"): ";
        cin >> user.cartao[cont].et;
        
        cout << "Horário de saída da tarde (DIA " << user.cartao[cont].dia <<"): ";
        cin >> user.cartao[cont].st;
        
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

void tempo_manha ()
{
    min_entrada_manha ( );
    min_saida_manha ( );
    tm = ms - me;
    if ( me > 480 )
    {
       am = me - 480;
    }
    else am = 0;
}

void min_entrada_manha ()
{
    me = ( cartao[i].em / 100 ) * 60 + ( cartao[i].em % 100 );
}

void min_saida_manha ()
{
    ms = ( cartao[i].sm / 100 ) * 60 + ( cartao[i].sm % 100 );
}

void tempo_tarde ()
{
    min_entrada_tarde ( );
    min_saida_tarde ( );
    tt = ms - me;
    if ( me > 840 )
    {
        at = me - 840;
    }
    else  at:= 0;
}

void min_entrada_tarde ()
{
    me = ( cartao[i].et / 100 ) * 60 + ( cartao[i].et % 100 );
}

void min_saida_tarde ()
{
    ms = ( cartao[i].st / 100 ) * 60 + ( cartao[i].st % 100 );
}

void calculo ()
{
    for ( int i = 1; i < cont; i++ )
    {
        tempo_manha;
        tempo_tarde;
        total_dia[i].atrasos = am + at;
        total_dia[i].horas = tm + tt;
        total_horas += total_dia[i].horas;
        total_atrasos += total_dia[i].atrasos;
    }

    media_horas = (total_horas) / (cont);
    media_atrasos = (total_atrasos) / (cont);
}

void impressao ()
{
    cout << "RELATÓRIO DE PONTO DO MÊS \n";
    
    for ( int i = 1; i < cont; i++ )
    {
        cout << "DIA " << cartao[i].dia << "\n";
        
        if (cartao[i].em % 100) < 10
        {
            cout << "Entrada Manhã: " << (cartao[i].em / 100) << ":0" << (cartao[i].em % 100) << "\n";
        }
        else cout << "Entrada Manhã: " << (cartao[i].em / 100) << ":" << (cartao[i].em % 100)) << "\n";    
            
        If (cartao[i].sm % 100) < 10
        {
            cout << "Saída Manhã: " << (cartao[i].sm / 100) << ":0" << (cartao[i].sm % 100) << "\n";
        }
        else cout << "Saída Manhã: " << (cartao[i].sm / 100) << ":" << (cartao[i].sm % 100) << "\n";
        
        if (cartao[i].et % 100) < 10
        {
            cout << "Entrada Tarde: " << (cartao[i].et / 100) << ":0" << (cartao[i].et % 100) << "\n";
        }
        else cout << "Entrada Tarde: " << (cartao[i].et / 100) < ":" << (cartao[i].et % 100) << "\n";    
        
        if (cartao[i].st % 100) < 10
        {
            cout << "Saída Tarde: " << (cartao[i].st / 100) << ":0" << (cartao[i].st % 100) << "\n";
        }
        else cout << "Saída Tarde: " << (cartao[i].st / 100) << ":" << (cartao[i].st % 100) << "\n";
                
        if (total_dia[i].horas % 60) < 10
        {
            cout << "Total de horas trabalhadas no dia: " << ((total_dia[i].horas) / 60) << "h0" << ((total_dia[i].horas) % 60) << "min" << "\n";
        }
        else cout << "Total de horas trabalhadas no dia: " << ((total_dia[i].horas) / 60) << "h" << ((total_dia[i].horas) % 60) << "min" << "\n";
        
        if (total_dia[i].atrasos % 60) < 10
        {
            cout << "Tempo de atraso no dia: " << ((total_dia[i].atrasos) / 60) << "h0" << ((total_dia[i].atrasos) % 60) << "min" << "\n";
        }
        else cout << "Tempo de atraso no dia: " << ((total_dia[i].atrasos) / 60) << "h" << ((total_dia[i].atrasos) % 60) << "min" << "\n";
    }

    cout << "\n\n";
    
    if (total_horas % 60) < 10
    {
        cout << "Tempo de atraso no mês: " << ((total_horas) / 60) << "h0" << ((total_horas) % 60) << "min \n";
    }
    else cout << "Tempo de atraso no mês: " << ((total_horas) / 60) << "h" << ((total_horas) % 60) << "min \n";
    
    if (total_atrasos % 60) < 10
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