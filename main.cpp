#include <stdlib.h>
#include <iostream>
#include <vector>

using std:: cout;
using std:: cin;
using std:: vector;

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
int cod;
int cont = 0;

int gerar_cod (); //Gerar ID de identificação
void cadastro(vector< usuario* > &); //cadastro dos dados do usuário
void entrada_de_dados (vector< usuario* > &); // entrada dos dados do usuário
int calc_tempo_manha (int, vector< usuario* > &); //cálculo do tempo trabalhado de manhã
int calc_atraso_manha (int, vector< usuario* > &); //cálculo do atraso de manhã
int min_entrada_manha (int, vector< usuario* > &); //conversão da hora de entrada da manhã em minutos
int min_saida_manha (int, vector< usuario* > &); //conversão da hora de saída da manhã em minutos
int calc_tempo_tarde (int, vector< usuario* > &); //cálculo do tempo trabalhado de tarde
int calc_atraso_tarde (int, vector< usuario* > &); //cálculo do atraso de tarde
int min_entrada_tarde (int, vector< usuario* > &); //conversão da hora de entrada da tarde em minutos
int min_saida_tarde (int, vector< usuario* > &); //conversão da hora de saída da tarde em minutos
void calculo (int &, int &, double &, double &, vector< usuario* > &); // cálculo total de horas
void impressao (int &, int &, double &, double &, vector< usuario* > &); //impressão dos dados na tela

int main(int argc, char **argv)
{        
    int total_horas_mes = 0;
    int total_atrasos_mes = 0;
    double media_horas;
    double media_atrasos;
    
    cout << "Ol" << (char)160 << "! Bem-vindo(a) ao M" << (char)162 << "dulo de controle de ponto do Fab Lab Bel" << (char)130 << "m (Vers" << (char)132 << "o 1.0)\n\n";
    
    vector < usuario * > fabber (20);
    
    cod = gerar_cod();
    
    cout << "C" << (char)162 << "digo atribuido: fab[" << cod << "]\n\n";
    
    cadastro (fabber);
    
    entrada_de_dados (fabber);
    
    calculo (total_horas_mes, total_atrasos_mes, media_horas, media_atrasos, fabber);
    
    impressao (total_horas_mes, total_atrasos_mes, media_horas, media_atrasos, fabber);

    return 0;
}

int gerar_cod ()
{
    static int ID = 0;
    return ID++;
}

void cadastro (vector< usuario* > &user)
{
    cout << "Insira o nome do(a) voluntario(a): ";
    cin >> user[cod]->nome;
    cout << "\n";
    
    cout << "Insira o sobrenome do(a) voluntario(a): ";
    cin >> user[cod]->sobrenome;
    cout << "\n";
    
    cout << "Diretoria onde atua: ";
    cin >> user[cod]->diretoria;
    cout << "\n";
}

void entrada_de_dados (vector< usuario* > &user)
{
    teste = false;
    
    char escolha;
    
    while ( teste == false )
    {
        cont += 1;
        
        cout << "\nInsira o dia do cart" << (char)132 << "o de ponto: ";

        while ( teste == false )
        {
            teste = true;
            
            cin >> user[cod]->cartao[cont].dia;
            
            if ( user[cod]->cartao[cont].dia < 1 )
                {
                    teste = false;
                    
                    cout << "Data inv" << (char)160 << "lida. Insira o dia do cart" << (char)132 << "o de ponto: ";
                }
                else if ( user[cod]->cartao[cont].dia > 31 )
                {
                    teste = false;
                    
                    cout << "Data inv" << (char)160 << "lida. Insira o dia do cart" << (char)132 << "o de ponto: ";
                }

        }

        cout << "Hor" << (char)160 << "rio de entrada da manh" << (char)132 << " (DIA " << user[cod]->cartao[cont].dia <<"): ";
        cin >> user[cod]->cartao[cont].entrada_manha;
        
        cout << "Hor" << (char)160 << "rio de saida da manh" << (char)132 << " (DIA " << user[cod]->cartao[cont].dia <<"): ";
        cin >> user[cod]->cartao[cont].saida_manha;
        
        cout << "Hor" << (char)160 << "rio de entrada da tarde (DIA " << user[cod]->cartao[cont].dia <<"): ";
        cin >> user[cod]->cartao[cont].entrada_tarde;
        
        cout << "Hor" << (char)160 << "rio de saida da tarde (DIA " << user[cod]->cartao[cont].dia <<"): ";
        cin >> user[cod]->cartao[cont].saida_tarde;
        
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

int calc_tempo_manha (int i, vector< usuario* > &user)
{
    int me;
    int ms;
    
    me = min_entrada_manha (i, user);
    ms = min_saida_manha (i, user);
    return ms - me;
}

int calc_atraso_manha (int i, vector< usuario* > &user)
{
    int me;
    
    me = min_entrada_manha (i, user);
    if ( me > 480 )
    {
       return me - 480;
    }
    else return 0;
}

int min_entrada_manha (int i, vector< usuario* > &user)
{
    return ( user[cod]->cartao[i].entrada_manha / 100 ) * 60 + ( user[cod]->cartao[i].entrada_manha % 100 );
}

int min_saida_manha (int i, vector< usuario* > &user)
{
    return ( user[cod]->cartao[i].saida_manha / 100 ) * 60 + ( user[cod]->cartao[i].saida_manha % 100 );
}

int calc_tempo_tarde (int i, vector< usuario* > &user)
{
    int me;
    int ms;
    
    me = min_entrada_tarde (i, user);
    ms = min_saida_tarde (i, user);
    return ms - me;
}

int calc_atraso_tarde (int i, vector< usuario* > &user)
{
    int me;
    
    me = min_entrada_tarde (i, user);
    if ( me > 840 )
    {
       return me - 840;
    }
    else return 0;
}

int min_entrada_tarde (int i, vector< usuario* > &user)
{
    return ( user[cod]->cartao[i].entrada_tarde / 100 ) * 60 + ( user[cod]->cartao[i].entrada_tarde % 100 );
}

int min_saida_tarde (int i, vector< usuario* > &user)
{
    return ( user[cod]->cartao[i].saida_tarde / 100 ) * 60 + ( user[cod]->cartao[i].saida_tarde % 100 );
}

void calculo (int &total_h, int &total_a, double &media_h, double &media_a, vector< usuario* > &user)
{
    int atraso_manha;
    int atraso_tarde;
    int horas_manha;
    int horas_tarde;
    
    for ( int i = 1; i < cont+1; i++ )
    {
        horas_manha = calc_tempo_manha (i, user);
        horas_tarde = calc_tempo_tarde (i, user);
        atraso_manha = calc_atraso_manha (i, user);
        atraso_tarde = calc_atraso_tarde (i, user);         
        
        user[cod]->cartao[i].total_horas_dia = horas_manha + horas_tarde;
        user[cod]->cartao[i].total_atraso_dia = atraso_manha + atraso_tarde;

        total_h += user[cod]->cartao[i].total_horas_dia;
        total_a += user[cod]->cartao[i].total_atraso_dia;
    }

    media_h = total_h / cont;
    media_a = total_a / cont;
}

void impressao (int &total_h, int &total_a, double &media_h, double &media_a, vector< usuario* > &user)
{
    cout << "\nRELAT" << (char)224 << "RIO DE PONTO DO M" << (char)210 << "S \n";
    cout << "Nome: " << user[cod]->nome << " " << user[cod]->sobrenome << "\n";
    cout << "Diretoria: " << user[cod]->diretoria << "\n\n";
    
    for ( int i = 1; i < cont+1; i++ )
    {
        cout << "DIA " << user[cod]->cartao[i].dia << "\n";
        
        if (( user[cod]->cartao[i].entrada_manha % 100) < 9)
        {
            cout << "Entrada Manh" << (char)132 << ": " << (user[cod]->cartao[i].entrada_manha / 100) << ":0" << (user[cod]->cartao[i].entrada_manha % 100) << "\n";
        }
        else cout << "Entrada Manh" << (char)132 << ": " << (user[cod]->cartao[i].entrada_manha / 100) << ":" << (user[cod]->cartao[i].entrada_manha % 100) << "\n";    
            
        if ((user[cod]->cartao[i].saida_manha % 100) < 10)
        {
            cout << "Saida Manh" << (char)132 << ": " << (user[cod]->cartao[i].saida_manha / 100) << ":0" << (user[cod]->cartao[i].saida_manha % 100) << "\n";
        }
        else cout << "Saida Manh" << (char)132 << ": " << (user[cod]->cartao[i].saida_manha / 100) << ":" << (user[cod]->cartao[i].saida_manha % 100) << "\n";
        
        if ((user[cod]->cartao[i].entrada_tarde % 100) < 10)
        {
            cout << "Entrada Tarde: " << (user[cod]->cartao[i].entrada_tarde / 100) << ":0" << (user[cod]->cartao[i].entrada_tarde % 100) << "\n";
        }
        else cout << "Entrada Tarde: " << (user[cod]->cartao[i].entrada_tarde / 100) << ":" << (user[cod]->cartao[i].entrada_tarde % 100) << "\n";    
        
        if ((user[cod]->cartao[i].saida_tarde % 100) < 10)
        {
            cout << "Saida Tarde: " << (user[cod]->cartao[i].saida_tarde / 100) << ":0" << (user[cod]->cartao[i].saida_tarde % 100) << "\n";
        }
        else cout << "Saida Tarde: " << (user[cod]->cartao[i].saida_tarde / 100) << ":" << (user[cod]->cartao[i].saida_tarde % 100) << "\n";
                
        if ((user[cod]->cartao[i].total_horas_dia % 60) < 10)
        {
            cout << "Total de horas trabalhadas no dia: " << ((user[cod]->cartao[i].total_horas_dia) / 60) << "h0" << ((user[cod]->cartao[i].total_horas_dia) % 60) << "min" << "\n";
        }
        else cout << "Total de horas trabalhadas no dia: " << ((user[cod]->cartao[i].total_horas_dia) / 60) << "h" << ((user[cod]->cartao[i].total_horas_dia) % 60) << "min" << "\n";
        
        if ((user[cod]->cartao[i].total_atraso_dia % 60) < 10)
        {
            cout << "Tempo de atraso no dia: " << ((user[cod]->cartao[i].total_atraso_dia) / 60) << "h0" << ((user[cod]->cartao[i].total_atraso_dia) % 60) << "min" << "\n";
        }
        else cout << "Tempo de atraso no dia: " << ((user[cod]->cartao[i].total_atraso_dia) / 60) << "h" << ((user[cod]->cartao[i].total_atraso_dia) % 60) << "min" << "\n";
    }

    cout << "\n\n";
    
   if ((total_h % 60) < 10)
    {
        cout << "Tempo de horas trabalhadas no m" << (char)136 << "s: " << ((total_h) / 60) << "h0" << ((total_h) % 60) << "min \n";
    }
    else cout << "Tempo de horas trabalhadas no m" << (char)136 << "s: " << ((total_h) / 60) << "h" << ((total_h) % 60) << "min \n";
    
    if ((total_a % 60) < 10)
    {
        cout << "Tempo de atraso no m" << (char)136 << "s: " << ((total_a) / 60) << "h0" << ((total_a) % 60) << "min \n";
    }
    else cout << "Tempo de atraso no m" << (char)136 << "s: " << ((total_a) / 60) << "h" << ((total_a) % 60) << "min \n";
    
    if (((int)media_h % 60) < 10)
    {
        cout << "M" << (char)130 << "dia de horas trabalhadas por dia: " << (((int)media_h) / 60) << "h0" << (((int)media_h) % 60) << "min \n";
    }
    else cout << "M" << (char)130 << "dia de horas trabalhadas por dia: " << (((int)media_h) / 60) << "h" << (((int)media_h) % 60) << "min \n";
    
    if (((int)media_a % 60) < 10)
    {
        cout << "M" << (char)130 << "dia de atraso por dia: " << (((int)media_a) / 60) << "h0" << (((int)media_a) % 60) << "min \n";
    }
    else cout << "M" << (char)130 << "dia de atraso por dia: " << (((int)media_a) / 60) << "h" << (((int)media_a) % 60) << "min \n";
}
