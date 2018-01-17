#include <stdlib.h>
#include <iostream>
#include <vector>

using std:: cout;
using std:: cin;
using std:: vector;

int gerar_cod (); //Gerar ID de identificação
void cadastro(struct usuario*); //cadastro dos dados do usuário
void entrada_de_dados (struct usuario*); // entrada dos dados do usuário
int calc_tempo_manha (int,struct usuario*); //cálculo do tempo trabalhado de manhã
int calc_atraso_manha (int, struct usuario*); //cálculo do atraso de manhã
int min_entrada_manha (int, struct usuario*); //conversão da hora de entrada da manhã em minutos
int min_saida_manha (int, struct usuario*); //conversão da hora de saída da manhã em minutos
int calc_tempo_tarde (int, struct usuario*); //cálculo do tempo trabalhado de tarde
int calc_atraso_tarde (int, struct usuario*); //cálculo do atraso de tarde
int min_entrada_tarde (int, struct usuario*); //conversão da hora de entrada da tarde em minutos
int min_saida_tarde (int, struct usuario*); //conversão da hora de saída da tarde em minutos
void calculo (double &, double &, struct usuario*); // cálculo total de horas
void impressao (double &, struct usuario*); //impressão dos dados na tela

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
    double media_horas;
    double media_atrasos;
    
    cout << "Ol" << (char)160 << "! Bem-vindo(a) ao M" << (char)162 << "dulo de controle de ponto do Fab Lab Bel" << (char)130 << "m (Vers" << (char)132 << "o 1.0)\n\n";
    
    vector < usuario * > fab (20);
    
    int cod = gerar_cod();
    
    cout << "C" << (char)162 << "digo atribuido: fab[" << cod << "]\n\n";
    
    cadastro (fab[cod]);
    
    entrada_de_dados (fab[cod]);
    
    calculo (media_horas, media_atrasos, fab[cod]);
    
    impressao (media_horas, media_atrasos, &fab[cod]);

    return 0;
}

int gerar_cod ()
{
    static int ID = 1;
    return ID++;
}

void cadastro (struct usuario *user)
{
    cout << "Insira o nome do(a) voluntario(a): ";
    cin >> user->nome;
    cout << "\n";
    
    cout << "Insira o sobrenome do(a) voluntario(a): ";
    cin >> user->sobrenome;
    cout << "\n";
    
    cout << "Diretoria onde atua: ";
    cin >> user->diretoria;
    cout << "\n\n";
}

void entrada_de_dados (struct usuario *user)
{
    teste = false;
    
    char escolha;
    
    while ( teste == false )
    {
        cont += 1;
        
        cout << "Insira o dia do cart" << (char)132 << "o de ponto: ";

        while ( teste == false )
        {
            teste = true;
            
            cin >> user->cartao[cont].dia;
            
            if ( user->cartao[cont].dia < 1 )
                {
                    teste = false;
                    
                    cout << "Data inv" << (char)160 << "lida. Insira o dia do cart" << (char)132 << "o de ponto: ";
                }
                else if ( user->cartao[cont].dia > 31 )
                {
                    teste = false;
                    
                    cout << "Data inv" << (char)160 << "lida. Insira o dia do cart" << (char)132 << "o de ponto: ";
                }

        }

        cout << "Hor" << (char)160 << "rio de entrada da manh" << (char)132 << " (DIA " << user->cartao[cont].dia <<"): ";
        cin >> user->cartao[cont].entrada_manha;
        
        cout << "Hor" << (char)160 << "rio de saida da manh" << (char)132 << " (DIA " << user->cartao[cont].dia <<"): ";
        cin >> user->cartao[cont].saida_manha;
        
        cout << "Hor" << (char)160 << "rio de entrada da tarde (DIA " << user->cartao[cont].dia <<"): ";
        cin >> user->cartao[cont].entrada_tarde;
        
        cout << "Hor" << (char)160 << "rio de saida da tarde (DIA " << user->cartao[cont].dia <<"): ";
        cin >> user->cartao[cont].saida_tarde;
        
        cout << "Deseja entrar com uma nova data? ( S / N )";
        cin >> escolha;
        
        switch (escolha)
        {
            case 'S':
            {
                teste = false;
                break;
            }
            case 's':
            {
                teste = false;
                break;
            }
            case 'N':
            {
                teste = true;
                break;
            }
            case 'n':
            {
                teste = true;
                break;
            }
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

int calc_tempo_tarde (int i, struct usuario *user)
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


void calculo (double &media_h, double &media_a, struct usuario *user)
{
    int atraso_manha;
    int atraso_tarde;
    int horas_manha;
    int horas_tarde;
    int total_horas_mes;
    int total_atrasos_mes;
    
    for ( int i = 1; i < cont+1; i++ )
    {
        horas_manha = calc_tempo_manha (i, user);
        horas_tarde = calc_tempo_tarde (i, user);
        atraso_manha = calc_atraso_manha (i, user);
        atraso_tarde = calc_atraso_tarde (i, user);         
        
        user->cartao[i].total_horas_dia = horas_manha + horas_tarde;
        user->cartao[i].total_atraso_dia = atraso_manha + atraso_tarde;

        total_horas_mes += user->cartao[i].total_horas_dia;
        total_atrasos_mes += user->cartao[i].total_atraso_dia;
    }

    media_h = total_horas_mes / cont;
    media_a = total_atrasos_mes / cont;
}

void impressao (double &media_h, double &media_a, struct usuario *user)
{
    cout << "\nRELAT" << (char)224 << "RIO DE PONTO DO M" << (char)210 << "S \n";
    cout << "Nome: " << user->nome << " " << user->sobrenome << "\n";
    cout << "Diretoria: " << user->diretoria << "\n\n";
    
    for ( int i = 1; i < cont+1; i++ )
    {
        cout << "DIA " << user->cartao[i].dia << "\n";
        
        if (( user->cartao[i].entrada_manha % 100) < 9)
        {
            cout << "Entrada Manh" << (char)132 << ": " << (user->cartao[i].entrada_manha / 100) << ":0" << (user->cartao[i].entrada_manha % 100) << "\n";
        }
        else cout << "Entrada Manh" << (char)132 << ": " << (user->cartao[i].entrada_manha / 100) << ":" << (user->cartao[i].entrada_manha % 100) << "\n";    
            
        if ((user->cartao[i].saida_manha % 100) < 10)
        {
            cout << "Saida Manh" << (char)132 << ": " << (user->cartao[i].saida_manha / 100) << ":0" << (user->cartao[i].saida_manha % 100) << "\n";
        }
        else cout << "Saida Manh" << (char)132 << ": " << (user->cartao[i].saida_manha / 100) << ":" << (user->cartao[i].saida_manha % 100) << "\n";
        
        if ((user->cartao[i].entrada_tarde % 100) < 10)
        {
            cout << "Entrada Tarde: " << (user->cartao[i].entrada_tarde / 100) << ":0" << (user->cartao[i].entrada_tarde % 100) << "\n";
        }
        else cout << "Entrada Tarde: " << (user->cartao[i].entrada_tarde / 100) << ":" << (user->cartao[i].entrada_tarde % 100) << "\n";    
        
        if ((user->cartao[i].saida_tarde % 100) < 10)
        {
            cout << "Saida Tarde: " << (user->cartao[i].saida_tarde / 100) << ":0" << (user->cartao[i].saida_tarde % 100) << "\n";
        }
        else cout << "Saida Tarde: " << (user->cartao[i].saida_tarde / 100) << ":" << (user->cartao[i].saida_tarde % 100) << "\n";
                
        if ((user->cartao[i].total_horas_dia % 60) < 10)
        {
            cout << "Total de horas trabalhadas no dia: " << ((user->cartao[i].total_horas_dia) / 60) << "h0" << ((user->cartao[i].total_horas_dia) % 60) << "min" << "\n";
        }
        else cout << "Total de horas trabalhadas no dia: " << ((user->cartao[i].total_horas_dia) / 60) << "h" << ((user->cartao[i].total_horas_dia) % 60) << "min" << "\n";
        
        if ((user->cartao[i].total_atraso_dia % 60) < 10)
        {
            cout << "Tempo de atraso no dia: " << ((user->cartao[i].total_atraso_dia) / 60) << "h0" << ((user->cartao[i].total_atraso_dia) % 60) << "min" << "\n";
        }
        else cout << "Tempo de atraso no dia: " << ((user->cartao[i].total_atraso_dia) / 60) << "h" << ((user->cartao[i].total_atraso_dia) % 60) << "min" << "\n";
    }

    cout << "\n\n";
    
   if ((total_horas_mes % 60) < 10)
    {
        cout << "Tempo de horas trabalhadas no m" << (char)136 << "s: " << ((total_horas_mes) / 60) << "h0" << ((total_horas_mes) % 60) << "min \n";
    }
    else cout << "Tempo de horas trabalhadas no m" << (char)136 << "s: " << ((total_horas_mes) / 60) << "h" << ((total_horas_mes) % 60) << "min \n";
    
    if ((total_atrasos_mes % 60) < 10)
    {
        cout << "Tempo de atraso no m" << (char)136 << "s: " << ((total_atrasos_mes) / 60) << "h0" << ((total_atrasos_mes) % 60) << "min \n";
    }
    else cout << "Tempo de atraso no m" << (char)136 << "s: " << ((total_atrasos_mes) / 60) << "h" << ((total_atrasos_mes) % 60) << "min \n";
    
    if ((media_horas % 60) < 10)
    {
        cout << "M" << (char)130 << "dia de horas trabalhadas por dia: " << ((media_h) / 60) << "h0" << ((media_h) % 60) << "min \n";
    }
    else cout << "M" << (char)130 << "dia de horas trabalhadas por dia: " << ((media_h) / 60) << "h" << ((media_h) % 60) << "min \n";
    
    if ((media_atrasos % 60) < 10)
    {
        cout << "M" << (char)130 << "dia de atraso por dia: " << ((media_a) / 60) << "h0" << ((media_a) % 60) << "min \n";
    }
    else cout << "M" << (char)130 << "dia de atraso por dia: " << ((media_a) / 60) << "h" << ((media_a) % 60) << "min \n";
}
