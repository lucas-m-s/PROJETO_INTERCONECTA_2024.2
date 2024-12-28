#!/bin/bash

# pasta="./dados_vibracao_sem_silencio"
pasta="./dados_vibracao_recortado"

gcc fft.c -lm
# gcc corte.c -lm

ls $pasta | while read arq; do
  # ./a.out < $pasta/$arq > ./dados_vibracao_recortado/$arq
  ./a.out < $pasta/$arq >> frequencias.txt
done

