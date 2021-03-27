#include <stdio.h> /**diz ao compilador que ele deve incluir o arquivo-cabeçalho*/
#include <stdlib.h>/**iclui uma biblioteca no projeto*/
#include <conio.h>
#include <string.h>/**declara uma string*/
#include <ctype.h>
#include <math.h>

void menu();

void voltaMenu(int *);

void quebra(int);
void tabula(int);

void DecParaBin();/**declarações*/
void BinParaDec();

void PedeNumero();
void PedeBinario();

char valor[50];

int main (void)
{
    menu();
    quebra(2);

    system ("pause");
    return 0;
}

void quebra (int n)
{
     for (int i=0; i<n;i++)
     {
         printf ("\n");
     }
}

void tabula (int n)
{
     for (int i=0; i<n;i++)
     {
         printf ("\t");
     }
}

void menu()
{
     int opc;

     printf ("Programa para conversao entre sistemas numericos");quebra(2);/**faz um print da mensage*/
     printf ("Escolha a conversao:");quebra(2);tabula(1);/** permite o usuario escolher a conversão */
     printf ("1 - Decimal p/ binario");quebra(1);tabula(1);/** quebra o texto para a proxima linha*/
     printf ("2 - Binario p/ decimal");quebra(1);tabula(1);
     printf ("9 - Sair"); quebra(2);/** opção sair*/

     printf ("Opcao: ");
     scanf ("%d", &opc);

     switch (opc)/**é comparado com um valor constante, e caso a comparação seja verdadeira, um determinado comando é executado.*/
     {
            case 1:
                 DecParaBin();
                 voltaMenu(&opc);
                 break;
            case 2:
                 BinParaDec();
                 voltaMenu(&opc);
                 break;
            case 9:
                 exit(1);
            default:
                    system ("cls");
                    menu();
     }
}

void voltaMenu(int * op)/** Declaração voltar*/
{
     quebra(2);
     printf ("Deseja voltar ao menu? (1-sim / 2-nao) ");
     scanf ("%d", op);
     if (*op==1){
        system ("cls");
        menu();
     }
}

void DecParaBin()
{
     char binario[33];
     char buffer[33];

     int divisor = 2;

     int resto = 0;
     int quociente = 0;
     int temp = 0;

     quebra(2);
     printf ("Informe um numero inteiro para ser convertido: ");
     PedeNumero();

     quociente = atoi(valor);/** formulas que irão executar o calculo*/
     strcpy(binario, "");
     while (quociente >= divisor)
     {
           resto = quociente%divisor;
           temp = quociente/divisor;
           quociente = temp;
           sprintf (buffer, "%d", resto);
           strcat (binario, buffer);
     }
     sprintf (buffer, "%d", quociente);
     strcat (binario, buffer);

     quebra(2);
     printf ("Convertido em binario: %s", strrev(binario));
     quebra(2);
}

void BinParaDec()
{
     int tamanho = 0;
     int result = 0;
     int temp = 0;
     int i = 0;

     quebra(2);
     printf ("Informe um valor binario para ser convertido: ");
     PedeBinario ();

     tamanho = strlen(valor);
     tamanho--;
     while (tamanho >= 0)
     {
           temp = pow (2, tamanho);
           result += ((valor[i] - 48) * temp);
           tamanho--;
           i++;
     }

     quebra(2);
     printf ("Convertido em decimal: %d", result);
     quebra(2);
}

void PedeNumero()
{
     char c;
     int i;

     i=0;
     do
     {
       c=getch();
       if (isdigit(c)!=0)
       {
          valor[i] = c;
          i++;
          printf ("%c", c);
       }
       else if(c==8&&i)
       {
          valor[i]='\0';
          i--;
          printf("\b \b");
       }
    }while(c!=13);

    valor[i]='\0';
}

void PedeBinario()
{
     char c;
     int i;

     i=0;
     do
     {
       c=getch();
       if (c=='0' || c=='1')
       {
          valor[i] = c;
          i++;
          printf ("%c", c);
       }
       else if(c==8&&i)
       {
          valor[i]='\0';
          i--;
          printf("\b \b");
       }
    }while(c!=13);

    valor[i]='\0';
}
