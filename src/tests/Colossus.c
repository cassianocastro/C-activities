#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iso646.h>
#include <string.h>
#include <locale.h>

bool isMulher, cardinal, flag;
char frase[200];

inline char* sufixo_ordinal(char* palavra)
{
	(isMulher) ? strcat(palavra, "a ") : strcat(palavra, "o ");
	return palavra;
}

inline char* sufixo_cardinal(char* palavra)
{
	(isMulher) ? strcat(palavra, "as ") : strcat(palavra, "os ");
	return palavra;
}

void Auxiliar(char* palavra1, char* palavra2)
{
	if (flag) {
		if (not cardinal) {
			strcpy (palavra1, palavra2);
			sufixo_ordinal(palavra1);
		}
	}
}

void centenas(char* palavra, char* palavra2, char* centena, short d)
{
	strcpy (centena, palavra);
	sufixo_cardinal(centena);

	if (d not_eq 0)
		strcat(centena, "e ");
	Auxiliar(centena, palavra2);
}

void dezenas(char* palavra, char* palavra2, char* dezena, short u)
{
	strcpy (dezena, palavra);

	if (u not_eq 0)
		strcat (dezena, " e ");
	Auxiliar(dezena, palavra2);
}

void casade10(char* palavra, char* palavra2, char* dezena)
{
	strcpy (dezena, palavra);
	if (flag) {
		if (not cardinal) strcpy(dezena, palavra2);
	}
}

void unidades(char* palavra, char* palavra2, char* unidade)
{
	strcpy(unidade, palavra);
	Auxiliar(unidade, palavra2);
}

void numext(int num)
{
    short c, d, u;
    char centena [20] = "", dezena[20] = "", unidade[20] = "", texto[15] = "";
    {
    	c =  (short) num / 100;
	    d =  (short) ((num % 100) / 10);
	    u =  (short) ((num % 100) % 10);
	}
    switch (c)
    {
	    case 1:
	    	(d == 0 and u == 0) ? strcpy (centena, "Cem") : strcpy (centena, "Cento e ");
	    	if (flag) {
	    		if (not cardinal) {
					strcpy (centena, "Centésim");
					sufixo_ordinal(centena);
				}
			}
	    	break;
	    case 2:
	    	centenas("Duzent", "Ducent�sim", centena, d);
			break;
	    case 3:
	    	centenas("Trezent", "Tricent�sim", centena, d);
	    	break;
	    case 4:
	    	centenas("Quatrocent", "Quadrigent�sim", centena, d);
	    	break;
	    case 5:
	    	centenas("Quinhent", "Quingent�sim", centena, d);
	    	break;
	    case 6:
	    	centenas("Seiscent", "Seiscent�sim", centena, d);
	    	break;
	    case 7:
	    	centenas("Setecent", "Septigent�sim", centena, d);
			break;
	    case 8:
	    	centenas("Oitocent", "Octigent�sim", centena, d);
	    	break;
	    case 9:
	    	centenas("Novecent", "Nongent�sim", centena, d);
    }
    switch (d)
    {
	    case 2:
	    	dezenas("Vinte","Vig�sim", dezena, u);
	    	break;
	    case 3:
	    	dezenas("Trinta","Trig�sim", dezena, u);
	    	break;
	    case 4:
	    	dezenas("Quarenta","Quadrag�sim", dezena, u);
	    	break;
	    case 5:
	    	dezenas("Cinquenta","Quinquag�sim", dezena, u);
	    	break;
	    case 6:
	    	dezenas("Sessenta","Sexag�sim", dezena, u);
	    	break;
	    case 7:
	    	dezenas("Setenta","Septuag�sim", dezena, u);
	    	break;
	    case 8:
	    	dezenas("Oitenta","Octag�sim", dezena, u);
	    	break;
	    case 9:
	    	dezenas("Noventa","Nonag�sim", dezena, u);
	    	break;
	    case 1:
	    	switch(u)
            {
	    		case 0:
	    			(isMulher) ? strcpy (texto, "D�cima") : strcpy (texto, "D�cimo");
	    			casade10("Dez ", texto, dezena);
	    			break;
	    		case 1:
	    			(isMulher) ? strcpy (texto, "D�cima Primeira") : strcpy (texto, "D�cimo Primeiro");
	    			casade10("Onze ", texto, dezena);
	    			break;
	    		case 2:
	    			(isMulher) ? strcpy (texto, "D�cima Segunda") : strcpy (texto, "D�cimo Segundo");
	    			casade10("Doze ", texto, dezena);
	    			break;
	    		case 3:
	    			(isMulher) ? strcpy (texto, "D�cima Terceira") : strcpy (texto, "D�cimo Terceiro");
	    			casade10("Treze ", texto, dezena);
	    			break;
	    		case 4:
	    			(isMulher) ? strcpy (texto, "D�cima Quarta") : strcpy (texto, "D�cimo Quarto");
	    			casade10("Catorze ", texto, dezena);
	    			break;
	    		case 5:
	    			(isMulher) ? strcpy (texto, "D�cima Quinta") : strcpy (texto, "D�cimo Quinto");
	    			casade10("Quinze ", texto, dezena);
	    			break;
	    		case 6:
	    			(isMulher) ? strcpy (texto, "D�cima Sexta") : strcpy (texto, "D�cimo Sexto");
	    			casade10("Dezesseis ", texto, dezena);
	    			break;
	    		case 7:
	    			(isMulher) ? strcpy (texto, "D�cima S�tima") : strcpy (texto, "D�cimo S�timo");
	    			casade10("Dezesete ", texto, dezena);
	    			break;
	    		case 8:
	    			(isMulher) ? strcpy (texto, "D�cima Oitava") : strcpy (texto, "D�cimo Oitavo");
	    			casade10("Dezoito ", texto, dezena);
	    			break;
	    		case 9:
	    			(isMulher) ? strcpy (texto, "D�cima Nona") : strcpy (texto, "D�cimo Nono");
	    			casade10("Dezenove ", texto, dezena);
			}
    }
    if (d not_eq 1) {
        switch (u)
        {
	        case 1:
	        	if (cardinal)
	        		(isMulher) ? strcpy(unidade, "Uma ") : strcpy(unidade, "Um ");
				else
					(isMulher) ? strcpy(unidade, "Primeira") : strcpy(unidade, "Primeiro");
	        	break;
	        case 2:
	        	if (cardinal)
	            	(isMulher) ? strcpy(unidade, "Duas ") : strcpy(unidade, "Dois ");
	            else
	            	(isMulher) ? strcpy(unidade, "Segunda") : strcpy(unidade, "Segundo");
	        	break;
	        case 3:
	        	unidades("Tr�s ", "Terceir", unidade);
	        	break;
	        case 4:
	        	unidades("Quatro ", "Quart", unidade);
	        	break;
	        case 5:
	        	unidades("Cinco ", "Quint", unidade);
	        	break;
	        case 6:
	        	unidades("Seis ", "Sext", unidade);
	        	break;
	        case 7:
	        	unidades("Sete ", "S�tim", unidade);
	        	break;
	        case 8:
	        	unidades("Oito ", "Oitav", unidade);
	        	break;
	        case 9:
	        	unidades("Nove ", "Non", unidade);
        }
    }
    strcat(frase, centena);
    strcat(frase, dezena);
    strcat(frase, unidade);
}

void numeroextenso (int n)
{
	int milhao, mil, cent; char texto[14] = "Milhon�sim";
	{
		milhao = (int) n / 1000000;
	    mil = (int) ((n % 1000000) / 1000);
	    cent = (int) ((n % 1000000) % 1000);
	}

    if (milhao not_eq 0) {
        if (milhao == 1) {
            (cardinal) ? strcpy (frase, "Um Milh�o, ") : strcpy (frase, sufixo_ordinal (texto));
        } else {
            numext(milhao);
            (cardinal) ? strcat(frase, "Milh�es, ") : strcat (frase, sufixo_cardinal (texto));
        }
    }
	if (mil not_eq 0) {
        if (mil == 1)
            strcat(frase, "Mil ");
		else {
			numext(mil);
	        if (cardinal)
				strcat(frase, "Mil");
			else
				(not isMulher) ? strcat(frase, "Mil�simos") : strcat(frase, "Mil�simas");
			strcat(frase, ", ");
		}
    }
	if (cent not_eq 0) {
		flag = true;
        numext(cent);
	}
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");

    int valor_is = 0;
    char sexo = '\0', tipo = '\0';

	do {
    	printf("\nDigite um valor entre 0 e 999.999.999: ");
	    scanf("%d", &valor_is);
	    getchar();
	} while ( valor_is <= 0 and valor_is > 999 );

    printf("\nEscolha 1 para feminino ou 0 para masculino. Opção\? ");
    scanf(" %c", &sexo);

    printf("\n1 para cardinal ou 0 para ordinal: ");
    scanf(" %c", &tipo);

    isMulher = (sexo == '1') ? true : false;
    cardinal = (tipo == '1') ? true : false;
    numeroextenso(valor_is);

    printf("\n%s", frase);

    return (EXIT_SUCCESS);
}