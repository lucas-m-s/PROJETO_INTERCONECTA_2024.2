Este repositório inclui os dados, arquivos e códigos de programação utilizados/desenvolvidos a fim de identificar a frequência fundamental (f0) de um sinal de vibração da pele do pescoço (VPP) e apresentar este valor de f0 em uma plataforma web.

# Sinal de VPP

Utilizou-se uma base de dados com 128 sinais de VPP de 32 voluntárias. Em [dados_vibracao](./dados_vibracao) há os sinais de VPP brutos. Em [dados_vibracao_filtrado](./dados_vibracao_filtrado) há os sinais de VPP brutos após um filtro Butterworth passa-faixa de 70Hz a 900Hz. Em [dados_vibracao_recortado](./dados_vibracao_recortado) há apenas um recorte dos sinais de VPP brutos originais, a fim de reduzir a quantidade de amostras para um valor fixo (p.e. 1024 amostras). Em [dados_vibracao_sem_silencio](./dados_vibracao_sem_silencio) há os sinais de VPP brutos com os perídos de silêncio quase completamente retirados.

> **Observação**: os sinais de VPP brutos possuem um offset.

Para maiores informações sobre como os sinais de VPP foram adquiridos consulte a [dissertação de mestrado](./IGORFORCELLI_dissertacao_mestrado_eng_eletrica.pdf) de Igor Forcelli.