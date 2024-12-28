import numpy as np
import argparse

def remove_silence(input_file, frame_size=1024, hop_size=1024, energy_threshold=0.1):
    """
    Remove partes de silêncio de um sinal de áudio baseado na energia de janelas.
    
    :param input_file: Caminho para o arquivo de entrada (TXT) contendo as amplitudes do áudio.
    :param frame_size: Tamanho da janela para cálculo de energia.
    :param hop_size: Passo entre janelas consecutivas.
    :param energy_threshold: Fração da energia máxima considerada como silêncio.
    """
    # Ler as amplitudes do arquivo
    with open(input_file, 'r') as file:
        amplitudes = np.array([int(line.strip()) for line in file], dtype=float)

    # Normalizar o sinal para trabalhar com valores entre 0 e 1
    amplitudes = amplitudes - 2140
    mx = max(amplitudes)
    mn = min(amplitudes)
    amplitudes /= mx

    # Dividir o sinal em janelas
    num_samples = len(amplitudes)
    energies = []  # Lista para armazenar energias das janelas
    active_segments = []  # Lista para armazenar segmentos de fala

    # Cálculo de energia por janela
    for start in range(0, num_samples - frame_size + 1, hop_size):
        frame = amplitudes[start:start + frame_size]
        energy = np.sum(frame ** 2) / frame_size  # Energia média da janela
        energies.append(energy)
        # print(energy)

    # Determinar o limiar de silêncio
    max_energy = max(energies)
    silence_threshold = energy_threshold * max_energy

    # Identificar janelas ativas
    for i, energy in enumerate(energies):
        if energy > silence_threshold:
            # Adicionar janela ativa ao segmento final
            start = i * hop_size
            end = start + frame_size
            active_segments.extend(amplitudes[start:end])

    # Desnormalizar para valores inteiros entre 0 e 4096
    active_segments = np.clip(np.array(active_segments) * mx, mn, mx).astype(int)

    # Imprimir os valores filtrados
    for amp in active_segments:
        print(amp)

if __name__ == "__main__":
    # Configurar o parser de argumentos
    parser = argparse.ArgumentParser(description="Remover silêncio de um arquivo de áudio.")
    parser.add_argument("input_file", help="Caminho para o arquivo de entrada contendo as amplitudes do áudio.")
    # parser.add_argument("--frame_size", type=int, help="Tamanho da janela para cálculo de energia (padrão: 1024).")
    # parser.add_argument("--hop_size", type=int, help="Tamanho do passo entre janelas consecutivas (padrão: 512).")
    # parser.add_argument("--energy_threshold", type=float, help="Limiar de energia para silêncio (padrão: 0.1).")

    # Ler argumentos da linha de comando
    args = parser.parse_args()

    # Chamar a função principal
    remove_silence(args.input_file)
