Este repositório inclui os dados, arquivos e códigos de programação utilizados/desenvolvidos a fim de identificar a frequência fundamental (f0) de um sinal de vibração da pele do pescoço (VPP) e apresentar este valor de f0 em uma plataforma web.

# Sinal de VPP

Utilizou-se uma base de dados com 128 sinais de VPP de 32 voluntárias. Em [dados_vibracao](./dados_vibracao) há os sinais de VPP brutos. Em [dados_vibracao_filtrado](./dados_vibracao_filtrado) há os sinais de VPP brutos após um filtro Butterworth passa-faixa de 70Hz a 900Hz, gerados por [filtro.py](./filtro.py). Em [dados_vibracao_recortado](./dados_vibracao_recortado) há apenas um recorte dos sinais de VPP brutos originais, a fim de reduzir a quantidade de amostras para um valor fixo (p.e. 1024 amostras), gerados por [corte.c](./corte.c). Em [dados_vibracao_sem_silencio](./dados_vibracao_sem_silencio) há os sinais de VPP brutos com os perídos de silêncio quase completamente retirados, gerados por [remove_silence.py](./remove_silence.py).

> **Observação**: os sinais de VPP brutos possuem um offset. Para maiores informações sobre a natureza dos sinais de VPP e como eles foram adquiridos para este projeto consulte a [dissertação de mestrado](./IGORFORCELLI_dissertacao_mestrado_eng_eletrica.pdf) de Igor Forcelli.

Em [graficos_octave](./graficos_octave) há os gráficos do espectro de Fourier de cada sinal e os gráficos do sinais brutos de VPP no domínio do tempo, ambos gerados no Octave pelo script [octave.m](./octave.m). Em [graficos_sem_silencio](./graficos_sem_silencio) há os gráficos dos sinais brutos de VPP após a retirada dos períodos de silêncio.

# Algoritmo AMDF (Average Magnitude Difference Function)

Este algoritmo está implementado nos códigos [amdf.c](./amdf.c), [amdf_mod1.c](./amdf_mod1.c) e [amdf_mod2.c](./amdf_mod2.c) sendo os dois últimos algoritmos modificados. Em [graficos_amdf](./graficos_amdf) há os gráficos do AMDF de cada sinal de VPP.

# Algoritmo FFT

Este algoritimo está implementado em [fft.c](./fft.c)

# Outros

Em [Locutor - Frequência fundamental.xlsx](./Locutor%20-%20Frequência%20fundamental.xlsx) há tabelas com resultados de cada algoritmo para cada sinal. A tabela com título **MODERADO** corresponde aos valores de f0 obtidos por Igor através do software PRAAT.

> **Observação**: f0 de "Gabi A, DIA 4" parece estar errado, o correto seria 255Hz.

Os scripts .sh servem apenas para executar os algoritmos para todos os arquivos de sinal de VPP. Os arquivos freq.txt e frequencias.txt são usados para guardar o resultado dos algoritmos.

Foi apresentado um trabalho na XIX SECT de 2024 sobre o AMDF. O resumo expandido e os slides utilizados são, respectivamente, [resumo_expandido_sect.pdf](./resumo_expandido_sect.pdf) e [slides_sect.pptx](./slides_sect.pptx).