#ifndef EXERCICIOS_LISTA_1_H

#define EXERCICIOS_LISTA_1_H

#include <ctype.h>
#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char Byte;

/**
 *
 */
typedef enum
{
    SAIR,
    EXERCICIO1,
    EXERCICIO2,
    EXERCICIO3,
    EXERCICIO4,
    EXERCICIO5,
    EXERCICIO6,
    EXERCICIO7,
    EXERCICIO8,
    EXERCICIO9,
    EXERCICIO10
} Opcoes;

/**
 * Faça um programa que converta a moeda real em dólar,
 * informando-se apenas a cotação do dólar e o valor em reais.
 */
void exercicio1(void);

/**
 * Faça um programa em que ao digitar um valor de temperatura em graus
 * Celcius o sistema converta em Fahrenheit e Kelvin,
 * sabendo se que para conversão Celcius X Fahrenheit a fórmula
 * aplicada será Fahrenheit = Celcius × 1,8 + 32 e para
 * conversão Celcius X Kelvin a fórmula aplicada
 * será Kelvin = Celcius + 273,15
 */
void exercicio2(void);

/**
 * Faça um programa que leia o sexo da pessoa e o valor de uma compra.
 * Se a pessoa for do sexo masculino, indicado pela letra 'm',
 * então ela recebe um desconto de 10% sobre o valor da compra,
 * se for do sexo feminino, indicado pela letra 'f',
 * então é concedido um desconto de 15% sobre o valor da compra.
 * O programa deverá exibir o valor bruto, o desconto concedido e o
 * valor líquido.
 */
void exercicio3(void);

/**
 * Faça um programa que leia um valor. Se o valor for menor que R$ 100,00,
 * então é concedido um desconto de 5%,
 * se o valor for superior a R$ 100,00,
 * então há um acréscimo de 7% sobre o valor.
 * O programa deverá exibir o valor bruto, o desconto concedido e o
 * valor líquido.
 */
void exercicio4(void);

/**
 * Faça um programa que leia a série que o aluno estuda.
 * Se o aluno estuda entre a 1 e a 4 série, então o programa deverá
 * escrever “Turno da manhã”, se o aluno estuda da 5 a 8 série,
 * então o programa deverá escrever “Turno da tarde”.
 */
void exercicio5(void);

/**
 * Faça um programa que leia 3 valores. Se a soma dos 3 valores for
 * superior a R$ 1000,00, então o programa desconta 10% da soma dos 3 valores,
 * senão o desconto será de 8%. O programa deverá exibir o valor
 * bruto(soma dos 3 valores), o desconto concedido e o valor líquido.
 */
void exercicio6(void);

/**
 * Faça um programa que leia 4 números. Se a soma dos dois primeiros números
 * for maior que a soma dos 2 últimos números, então será concedido um
 * desconto sobre o total bruto(soma dos 4 valores) de 20%, se a soma dos
 * dois últimos números for maior que a soma dos 2 primeiros números,
 * então há uma acréscimo sobre o total bruto(soma dos 4 valores) de 20%.
 * O programa deverá exibir a soma dos 2 primeiros números, a soma dos 2
 * últimos números, o valor bruto(soma dos 4 valores), o desconto ou acréscimo
 * concedidos e o valor líquido.
 */
void exercicio7(void);

/**
 * Faça um programa que leia 5 números, em seguida,
 * demonstre qual o maior número digitado.
 */
void exercicio8(void);

/**
 * Faça um programa que leia 5 números, em seguida,
 * demonstre qual o maior e o menor número digitado.
 */
void exercicio9(void);

/**
 * Faça um programa que leia 10 números, em seguida, mostre quantos dos
 * números digitados é par e quantos números digitados é ímpar.
 */
void exercicio10(void);

#endif