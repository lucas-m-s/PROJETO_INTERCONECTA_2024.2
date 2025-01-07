#!/bin/bash

# Esse script compila um arquivo em C e o executa para cada sinal de VPP que está na pasta de seu interesse
# O resultado do código para cada sinal é adicionado no final do arquivo frequencias.txt
# Basta apenas executá-lo: ./script.sh

# pasta="./dados_vibracao_sem_silencio"
pasta="./dados_vibracao"

gcc fft.c -lm
# gcc corte.c -lm

ls $pasta | while read arq; do
  # ./a.out < $pasta/$arq > ./dados_vibracao_recortado/$arq
  ./a.out < $pasta/$arq >> frequencias.txt
done