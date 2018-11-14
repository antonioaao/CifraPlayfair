#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
void maiusc_space(char chave[])
{
    int j,i,y;
    char chave_aux[256];

    strupr(chave);
    for(i=0, j=0; chave[i]!='\0'; i++,j++)
    {
        for(y=0; chave[y]!='\0'; y++)
        {
            if(chave[j]==' ')
            {
                j++;
            }
        }
        chave_aux[i]=chave[j];
    }
    chave_aux[i]='\0';

    strcpy(chave, chave_aux);

}
void trocar_j(char chave[]) 
{
    int i;
    for (i = 0; chave[i] != '\0'; i++)
    {
        if(chave[i]=='J')
            chave[i]='I';
    }
}
void letra_repetida(char chave[])
{
    char chave_aux[256];
    int x, y= 0,i,j,a;
    for (x = 0; chave[x] != '\0'; x++)
    {
        i = 0;
        j = 0;
        a = 0;
        for (i; chave_aux[i] != '\0'; i++)
        {
            if (chave_aux[i] == chave[x])
            {
                j++;
            }
        }
        if (j > 0)
            a = 0;
        else
            a = 1;

        if (a==1)
        {
            chave_aux[y] = chave[x];
            chave_aux[y+1] = '\0';
            y++;
        }
    }
    strcpy(chave,chave_aux);
}
void concatenar(char chave[])
{
    strcat(chave,"ABCDEFGHIKLMNOPQRSTUVWXYZ");
}
void matriz(char chave[], char matriz[5][5])
{
    int i=0, j=0,k=0,x;
    
        for(j=0; j<5; j++) 
        {
            matriz[i][j]=chave[k];
            k++; 
        }
        for(j=0; j<5; j++)
        {
            matriz[i+1][j]=chave[k];
            k++;
        }
        for(j=0; j<5; j++)
        {
            matriz[i+2][j]=chave[k];
            k++;
        }
        for(j=0; j<5; j++)
        {
            matriz[i+3][j]=chave[k];
            k++;
        }
        for(j=0; j<5; j++)
        {
            matriz[i+4][j]=chave[k];
            k++;
        }
    for(i=0; i<5; i++) 
    {
        printf("        ");
        for(j=0; j<5; j++)
            printf("%c ", matriz[i][j]);
        printf("\n");
    }
}
void separa_dois(char frase[], char auxiliar[256][2]) 
{
    int i = 0, j = 0, k = 0;
    for (i; i < 256; i++)
    {
        auxiliar[i][0] = '\0';
        auxiliar[i][1] = 'X';
    }
	i=0;
    while (frase[k] != '\0')
    {
        if (j == 0)
        {
            auxiliar[i][j] = frase[k];
            j++;
            k++;
        }
        else
        {
            if (frase[k] == auxiliar[i][0])
            {
                i++;
                j--;
            }
            else 
            {
                auxiliar[i][j] = frase[k];
                i++;
                j--;
                k++;
            }
        }
    }
    printf("\n      %s", auxiliar);
}
void encriptar(char auxiliar[256][2], char chave[5][5], char matriz_saida[256]) 
{

    int auxlinha = 0, posx1 = 0, posy1 = 0, posx2 = 0, posy2 = 0, i = 0, j = 0, posmatrizsaida = 0, k = 0, x = 0;
    char a, b;

    for (auxlinha; auxiliar[auxlinha][0] != '\0'; auxlinha++) 
    {
        a = auxiliar[auxlinha][0]; 
        b = auxiliar[auxlinha][1]; 
        for(i = 0; i < 5; i++) 
        {
            for(j = 0; j < 5; j++)
            {
                if (chave[i][j] == a) 
                {
                    posx1 = i;
                    posy1 = j;
                }
                else if (chave[i][j] == b) 
                {
                    posx2 = i;
                    posy2 = j;
                }
            }
        }

        if (posx1 == posx2) 
        {
            if (posy1 == 4)
                posy1 = -1;
            if (posy2 == 4)
                posy2 = -1;
            matriz_saida[posmatrizsaida] = chave[posx1][posy1+1];
            posmatrizsaida++;
            matriz_saida[posmatrizsaida] = chave[posx2][posy2+1];
            posmatrizsaida++;
        }
        else if (posy1 == posy2)
        {
            if (posx1 == 4) 
                posx1 = -1;
            if (posx2 == 4)
                posx2 = -1;
            matriz_saida[posmatrizsaida] = chave[posx1+1][posy1];
            posmatrizsaida++;
            matriz_saida[posmatrizsaida] = chave[posx2+1][posy2];
            posmatrizsaida++;
        }
        else
        {
            matriz_saida[posmatrizsaida] = chave[posx1][posy2];
            posmatrizsaida++;
            matriz_saida[posmatrizsaida] = chave[posx2][posy1];
            posmatrizsaida++;
        }
        matriz_saida[posmatrizsaida] = '\0';
    }
    printf("Frase encriptada: %s\n", matriz_saida);

}
void desencriptar(char auxiliar[256][2], char chave[5][5], char matriz_saida[256])
{

    int auxlinha = 0, posx1 = 0, posy1 = 0, posx2 = 0, posy2 = 0, i = 0, j = 0, posmatrizsaida = 0;
    char a, b;

    for (auxlinha; auxiliar[auxlinha][0] != '\0'; auxlinha++) 
    {
        a = auxiliar[auxlinha][0];
        b = auxiliar[auxlinha][1]; 
        for(i = 0; i < 5; i++) 
        {
            for(j = 0; j < 5; j++)
            {
                if (chave[i][j] == a) 
                {
                    posx1 = i;
                    posy1 = j;
                }
                else if (chave[i][j] == b) 
                {
                    posx2 = i;
                    posy2 = j;
                }
            }
        }

        if (posx1 == posx2) 
        {
            if (posy1 == 0) 
                posy1 = 5;
            if (posy2 == 0)
                posy2 = 5;
            matriz_saida[posmatrizsaida] = chave[posx1][posy1-1];
            posmatrizsaida++;
            matriz_saida[posmatrizsaida] = chave[posx2][posy2-1];
            posmatrizsaida++;
        }
        else if (posy1 == posy2)
        {
            if (posx1 == 0) 
                posx1 = 5;
            if (posx2 == 0)
                posx2 = 5;
            matriz_saida[posmatrizsaida] = chave[posx1-1][posy1];
            posmatrizsaida++;
            matriz_saida[posmatrizsaida] = chave[posx2-1][posy2];
            posmatrizsaida++;
        }
        else 
        {
            matriz_saida[posmatrizsaida] = chave[posx1][posy2];
            posmatrizsaida++;
            matriz_saida[posmatrizsaida] = chave[posx2][posy1];
            posmatrizsaida++;
        }
        matriz_saida[posmatrizsaida] = '\0';
    }
    printf("Frase descriptada: %s", matriz_saida);
}
int main()
{
    int opcao, i, j, x, k=0;
    char chave[256],frase[256], matriz_chave[5][5], matriz_frase[256][2], chaveb[256], fraseb[256], encrip[256], descrip[256];
    chaveb[0]='\0';
    fraseb[0]='\0';
    encrip[0]='\0';
    descrip[0]='\0'; 
    setlocale (LC_ALL, "Portuguese");
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            matriz_chave[i][j]=' ';
        }
    }
    do
    {
        system("cls");
        printf( " --------------MENU-------------- \n"
                "| Escolha uma opção:             |\n"
                "| 1 - Inserir uma nova chave.    |\n"
                "| 2 - Inserir uma nova frase.    |\n"
                "| 3 - Criptografar a frase.      |\n"
                "| 4 - Descriptografar a frase.   |\n"
                "| 5 - Limpar todos os dados.     |\n"
                "| 6 - Sair do Programa.          |\n"
                " -------------------------------- \n\n");
        printf("	    -----------\n");
		for(i=0; i<5; i++)
        {
            printf("	   | ");
            for(j=0; j<5; j++)
            {
                printf("%c ", matriz_chave[i][j]);
            }
            printf("|\n");
        }
        printf("	    -----------\n");
        printf("\nChave digitada: %s", chaveb);
        printf("\nFrase digitada: %s", fraseb);
        printf("\nResultado encriptografado: %s", encrip);
        printf("\nResultado desencriptografado: %s", descrip);
        printf("\n\nOpção: ");
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            system("cls");
            printf("Digite sua chave: ");
            fflush(stdin);
            gets(chave);
            for(i=0; chave[i]!='\0'; i++)
            {
                chaveb[i]=chave[i];
            }
            chaveb[i]='\0';
            maiusc_space(chave);
            trocar_j(chave);
            concatenar(chave);
            letra_repetida(chave);
            matriz(chave,matriz_chave);
            getch();
            break;
        case 2:
            system("cls");
            printf("Digite sua frase: ");
            fflush(stdin);
            gets(frase);
            for(i=0; frase[i]!='\0'; i++)
            {
                fraseb[i]=frase[i];
            }
            fraseb[i]='\0';
            maiusc_space(frase);
            separa_dois(frase, matriz_frase);
            getch();
            break;
        case 3:
            system("cls");
            encriptar(matriz_frase, matriz_chave, encrip);
            getch();
            break;
        case 4:
            system("cls");
            desencriptar(matriz_frase, matriz_chave, descrip);
            getch();
            break;
        case 5:
            for(i=0; i<5; i++)
            {
                for(j=0; j<5; j++)
                {
                    matriz_chave[i][j]=' ';
                }
            }
            chaveb[0]='\0';
            fraseb[0]='\0';
            break;
        case 6:
            system("cls");
            return 0;
        default:
            if(opcao <1 || opcao>6)
            {
                printf("\nOPÇÃO INVÁLIDA, INSIRA UM NÚMERO VÁLIDO DO MENU.");
                getch();
            }
            break;
        }
    }
    while(1);
    return 0;
}

