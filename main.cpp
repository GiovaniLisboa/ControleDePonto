#include <stdlib.h>
#include <iostream>

using std:: cout;
using std:: cin;

void selecao (int &); // seleção da origem dos arquivos
void entrada (); // entrada dos dados do usuário
void manha (); //cálculo do tempo trabalhado de manhã
void entrada_manha (); //conversão da hora de entrada da manhã em minutos
void saida_manha (); //conversão da hora de saída da manhã em minutos
void manha (); //cálculo do tempo trabalhado de tarde
void entrada_manha (); //conversão da hora de entrada da tarde em minutos
void saida_manha (); //conversão da hora de saída da tarde em minutos
void calculo (); // cálculo total de horas
void impressao (); //impressão dos dados na tela
void reescreever_arquivo (); //
void ler_arquivo (); //


int main(int argc, char **argv)
{
    cout << "Ola! Bem-vindo(a) ao Módulo de controle de ponto (Versão 1.0)\n\n";
    /*
    int selec;
    
    selecao ( selec );
    
    switch ( selec )
    {
        case 1:
        reescrever_arquivo;
        entrada;
    }
    
    */
    
    entrada;
    
    calculo;
    
    impressao;
		1:	Begin
					Reescrever_arquivo;
					Entrada;
					If cont>0 then
					begin	
						Calculo;
						clrscr;
						Impressao;
					End;
					close(arq_c);
				End;
		2:	Begin
					Ler_arquivo;
					cont:=0;
					While not eof(arq_c) do
					Begin
						cont:=cont+1;
						read(arq_c,cartao_dia[cont]);
					End;
					If cont>0 then
					begin	
						Calculo;
						clrscr;
						Impressao;
					End;
					close(arq_c);
				End;
	End;		 
    return 0;
}

void selecao (int &x)
{
    cout << "MENU\n";
    cout << "1. Criar arquivo\n";
    cout << "2. Ler arquivo\n\n";
    cout << "Insira a opção desejada: ";
    
    cin >> x;
}

void entrada ()
{
    
    
}

void manha ()
{
    
}

void entrada_manha ()
{
    
}

void saida_manha ()
{
    
}

void manha ()
{
    
}

void entrada_manha ()
{
    
}

void saida_manha ()
{
    
}

void calculo ()
{
    
}

void impressao ()
{
    
}

void reescreever_arquivo ()
{
    
}

void ler_arquivo ()
{
    
}