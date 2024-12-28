close all, clear all, clc;

arquivos = textread('arquivos.txt', '%s');

for i = 1:length(arquivos)
  figure('visible', 'off');

  data = textread(strcat('dados_vibracao/', arquivos{i}), '%f');
  data = data/1000;
  data = data';
  subplot(2,1,1);
  plot(data);
  title(strcat('Sinal de voz completo - ', arquivos{i}));

  data = textread(strcat('dados_vibracao_recortado/', arquivos{i}), '%f');
  data = data/1000;
  data = data';
  subplot(2,1,2);
  plot(data);
  title(strcat('Sinal de voz recortado - ', arquivos{i}));

  print(strcat('graficos_recortados/', arquivos{i}, '.png'), '-dpng');

##  N = length(data);
##  Ts = 0.000125;

##  Y = abs(fft(data));
##  T = (1:N-1)/(N*Ts);

##  figure('visible', 'off');
##  plot(T, abs(Y(1,2:end)));
##  title(strcat('FFT octave - ', arquivos{i}));
##  print(strcat('graficos/fft_octave_', arquivos{i}, '.png'), '-dpng');

##  [t1, y1] = textread(strcat('fft_window/', arquivos{i}), '%f %f');
##  [t2, y2] = textread(strcat('fft_picos/', arquivos{i}), '%f %f');
##  [t3, y3] = textread(strcat('frequencias/', arquivos{i}), '%f %f');
##
##  figure('visible', 'off');
##  hold on;
##  plot(t1, y1);
##  plot(t2, y2, '-o');
##  plot(t3, y3, '-o', 'Color', 'k');
##  title(strcat('FFT em C - ', arquivos{i}));
##  print(strcat('graficos_fft_window/', arquivos{i}, '.png'), '-dpng');
end

% -------------------------------------

##data = textread('dados_vibracao/Ana2_mode.txt', '%f');
##data = data;
##data = data';

##data = textread('out.txt', '%f');
##figure;
##plot(data);
##
##data = textread('a.txt', '%f');
##data = data;
##data = data';

##data = textread('out.txt', '%f');
##figure;
##plot(data);
##title('Sinal de VPP');
##ylabel("Amplitude");
##xlabel("Amostra");
##axis([0 43000 1900 2400]);
##print('vpp.png', '-dpng');

##N = length(data);
##Ts = 0.000125;
##
##Y = abs(fft(data));
##T = (1:N-1)/(N*Ts);
##
##figure;
##plot(T, Y(2:end));
##title('FFT octave');

% --------------------------------------

##[t1, y1] = textread('dados_vibracao/Gabi1_mode.txt', '%f %f');
##[t2, y2] = textread('amdf_vales/Gabi1_mode.txt', '%f %f');
##
##figure;
##plot(t(11:end-10), y(11:end-10));
##title('FFT em C');
##
##figure;
##hold on;
##plot(t1, y1);
##title('Sinal de VPP');
##for i = 1:length(t2)
##  plot(t2(i)/0.000125, y2(i), '-o', 'Color', 'r');
##end
##ylabel("Amplitude");
##xlabel("Amostra");
##print('amdf.png', '-dpng');
