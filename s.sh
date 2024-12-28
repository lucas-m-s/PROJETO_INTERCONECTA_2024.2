#!/bin/bash

# Verifica se o arquivo foi passado como argumento
if [ $# -eq 0 ]; then
    echo "Uso: $0 <arquivo>"
    exit 1
fi

# Lê os valores do arquivo passado como argumento
input_file=$1
counter=0
line=""

# Loop através de cada valor no arquivo
while read -r value; do
    # Adiciona o valor à linha atual
    line="$line$value "

    # Incrementa o contador
    counter=$((counter + 1))

    # Quando o contador chega a 4, imprime a linha e reseta o contador
    if [ $counter -eq 4 ]; then
        echo "$line"
        line=""
        counter=0
    fi
done < "$input_file"
