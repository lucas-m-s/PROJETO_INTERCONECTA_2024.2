import numpy as np
import sys
from scipy.signal import butter, lfilter

# Função para criar o filtro Butterworth passa-faixa
def butter_bandpass(lowcut, highcut, fs, order=5):
    nyq = 0.5 * fs  # Frequência de Nyquist
    low = lowcut / nyq
    high = highcut / nyq
    b, a = butter(order, [low, high], btype='band')
    return b, a

# Função para aplicar o filtro no sinal
def butter_bandpass_filter(data, lowcut, highcut, fs, order=5):
    b, a = butter_bandpass(lowcut, highcut, fs, order=order)
    y = lfilter(b, a, data)
    return y

# Parâmetros do filtro
lowcut = 70.0   # Freqüência de corte inferior
highcut = 900.0  # Freqüência de corte superior
fs = 8000  # Taxa de amostragem (assumida como 44.1kHz, mas ajuste conforme necessário)

# Lê os dados do sinal da entrada padrão
input_data = sys.stdin.read()

# Converte os dados lidos para uma lista de floats
signal = np.array([float(val) for val in input_data.split()])

# Aplica o filtro passa-faixa
filtered_signal = butter_bandpass_filter(signal, lowcut, highcut, fs, order=6)

# Imprime o sinal filtrado para a saída padrão
for value in filtered_signal:
    print(value)
