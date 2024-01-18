#include "../includes/ExerciciosLista1.h"

/**
 *
 */
int main(void)
{
    setlocale(LC_ALL, "");

    Opcoes opcao;

    while ( true )
	{
        printf(
            "\nEscolha a opção:"
            "\n0. Sair"
            "\n1. Exercício nº 01"
            "\n2. Exercício nº 02"
            "\n3. Exercício nº 03"
            "\n4. Exercício nº 04"
            "\n5. Exercício nº 05"
            "\n6. Exercício nº 06"
            "\n7. Exercício nº 07"
            "\n8. Exercício nº 08"
            "\n9. Exercício nº 09"
            "\n10.Exercício nº 10"
            "\nOpção? "
        );
        scanf("%d", &opcao);
        getchar();

        system("clear");

        switch ( opcao )
		{
            case EXERCICIO1:
                exercicio1();
                break;
            case EXERCICIO2:
                exercicio2();
                break;
            case EXERCICIO3:
                exercicio3();
                break;
            case EXERCICIO4:
                exercicio4();
                break;
            case EXERCICIO5:
                exercicio5();
                break;
            case EXERCICIO6:
                exercicio6();
                break;
            case EXERCICIO7:
                exercicio7();
                break;
            case EXERCICIO8:
                exercicio8();
                break;
            case EXERCICIO9:
                exercicio9();
                break;
            case EXERCICIO10:
                exercicio10();
                break;
            case SAIR:
                exit(EXIT_SUCCESS);
                break;
            default:
                puts("Opção inválida!");
        }
    }

    return EXIT_SUCCESS;
}

void exercicio1(void)
{
    float cotacao_dolar = 0.0f, valor_reais = 0.0f;

    printf("Cotação em Dólar: ");
    scanf("%f", &cotacao_dolar);

    printf("Valor em Reais: ");
    scanf("%f", &valor_reais);

    printf("O valor em dólares é: U$ %.2f", ( valor_reais / cotacao_dolar ));
}

void exercicio2(void)
{
    float celsius = 0.0f;

    printf("Temperatura em Graus Celsius: ");
    scanf("%f", &celsius);

    printf(
		"A temperatura em..."
        "\nGraus Farenheit..: %.2f"
        "\nGraus Kelvin.....: %.2f",
        (celsius * 1.8 + 32),
        (celsius + 273.15)
	);
}

void exercicio3(void)
{
    float valor_compra = 0.0f, desconto = 0.0f, valor_liquido = 0.0f;
    char sexo = '\0';

    printf("Valor da Compra: ");
    scanf("%f", &valor_compra);

    do {
        printf("Sexo: ");
        scanf(" %c", &sexo);

        sexo = tolower(sexo);
    } while ( sexo != 'm' and sexo != 'f' );

    if ( sexo == 'm' )
    {
        desconto      = valor_compra * 0.1;
        valor_liquido = valor_compra - desconto;
    }
    else
    {
        desconto      = valor_compra * 0.15;
        valor_liquido = valor_compra - desconto;
    }

    printf(
		"\nValor Bruto......: R$ %.2f"
        "\nValor Líquido....: R$ %.2f"
        "\nDesconto.........: R$ %.2f",
        valor_compra,
        valor_liquido,
        desconto
	);
}

void exercicio4(void)
{
    float valor = 0.0f, valor_liquido = 0.0f;

    printf("Valor: ");
    scanf("%f", &valor);

    if ( valor < 100.0f )
    {
        float desconto = valor * 0.05f;
        valor_liquido  = valor - desconto;

        printf(
			"\nValor Bruto......: R$ %.2f"
            "\nValor Líquido....: R$ %.2f"
            "\nDesconto.........: R$ %.2f",
            valor,
            valor_liquido,
            desconto
		);
    }
    else
    {
        float acrescimo = valor * 0.07f;
        valor_liquido   = valor + acrescimo;

        printf(
			"\nValor Bruto......: R$ %.2f"
            "\nValor Líquido....: R$ %.2f"
            "\nAcréscimo........: R$ %.2f",
            valor,
            valor_liquido,
            acrescimo
		);
    }
}

void exercicio5(void)
{
    Byte serie_informada = 0;

    printf("Informe a série: ");
    scanf("%hhu", &serie_informada);

    if ( serie_informada >= 1 and serie_informada <= 4 )
    {
        puts("Turno da Manhã.");
    }
    else if ( serie_informada >= 5 and serie_informada <= 8 )
    {
        puts("Turno da Tarde.");
    }
    else
    {
        puts("Dígito inválido.");
    }
}

void exercicio6(void)
{
    float primeiro_valor = 0.0f, segundo_valor  = 0.0f, terceiro_valor = 0.0f;
    float soma = 0.0f, desconto = 0.0f, valor_liquido = 0.0f;

    printf("Primeiro Valor: ");
    scanf("%f", &primeiro_valor);

    printf("Segundo Valor: ");
    scanf("%f", &segundo_valor);

    printf("Terceiro Valor: ");
    scanf("%f", &terceiro_valor);

    soma = primeiro_valor + segundo_valor + terceiro_valor;

    desconto = ( soma > 1000 ) ? soma * 0.1 : soma * 0.08;

    valor_liquido = soma - desconto;

    printf(
		"\nValor Bruto......: R$ %.2f"
        "\nValor Líquido....: R$ %.2f"
        "\nDesconto.........: R$ %.2f",
        soma,
        valor_liquido,
        desconto
	);
}

void exercicio7(void)
{
    float valor1 = 0.0f, valor2 = 0.0f, valor3 = 0.0f, valor4 = 0.0f, valor_liquido = 0.0f;

    printf("Primeiro valor: ");
    scanf("%f", &valor1);

    printf("Segundo valor: ");
    scanf("%f", &valor2);

    printf("Terceiro valor: ");
    scanf("%f", &valor3);

    printf("Quarto valor: ");
    scanf("%f", &valor4);

    float soma1 = valor1 + valor2;
    float soma2 = valor3 + valor4;
    float total = soma1  + soma2;

    if ( soma1 > soma2 )
    {
        float desconto = total * 0.2;
        valor_liquido  = total - desconto;

        printf(
			"\nSoma dos 2 primeiros valores..: R$ %.2f"
            "\nSoma dos 2 últimos valores....: R$ %.2f"
            "\nValor Bruto...................: R$ %.2f"
            "\nValor Líquido.................: R$ %.2f"
            "\nDesconto......................: R$ %.2f",
            soma1, soma2, total, valor_liquido, desconto
		);
    }
    else
    {
        float acrescimo = total * 0.2;
        valor_liquido   = total + acrescimo;

        printf(
			"\nSoma dos 2 primeiros valores..: R$ %.2f"
            "\nSoma dos 2 últimos valores....: R$ %.2f"
            "\nValor Bruto...................: R$ %.2f"
            "\nValor Líquido.................: R$ %.2f"
            "\nAcréscimo.....................: R$ %.2f",
            soma1, soma2, total, valor_liquido, acrescimo
		);
    }
}

void exercicio8(void)
{
    Byte vetor[5] = {0, 0, 0, 0, 0}, maior_numero = 0;

    for ( Byte indice = 0; indice < 5; indice++ )
	{
        printf("Valor: ");
        scanf("%hhu", &vetor[indice]);

        if ( vetor[indice] > maior_numero )
        {
            maior_numero = vetor[indice];
        }
    }

    printf("O maior número informado foi: %hhu", maior_numero);
}

void exercicio9(void)
{
    Byte vetor[5] = { 0, 0, 0, 0, 0 };
    Byte maior_numero = 0, menor_numero = 0;

    for ( Byte indice = 0; indice < 5; indice++ )
	{
        printf("Valor número %hhu: ", ( indice + 1 ));
        scanf("%hhu", &vetor[indice]);

        if ( vetor[indice] > maior_numero )
        {
            maior_numero = vetor[indice];
        }

        if ( vetor[indice] < menor_numero )
        {
            menor_numero = vetor[indice];
        }
    }

    printf(
		"O maior número informado foi: %hhu\n"
        "O menor número foi: %hhu",
        maior_numero,
        menor_numero
	);
}

void exercicio10(void)
{
    Byte vetor[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    Byte contador_Pares = 0, contador_Impares = 0;

    for ( Byte indice = 0; indice < 10; indice++ )
	{
        printf("Valor número %hhu: ", ( indice + 1 ));
        scanf("%hhu", &vetor[indice]);

        ( vetor[indice] % 2 == 0 ) ? contador_Pares++ : contador_Impares++;
    }

    printf(
		"Quantidade de números..."
        "\nPares......: %hhu"
        "\nÍmpares....: %hhu",
        contador_Pares,
        contador_Impares
	);
}