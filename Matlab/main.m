filename = 'archivo.txt';
delimiterIn = ' ';
A = importdata(filename,delimiterIn);
y = A(1:end,2);
x = A(1:end,1);
exp(10)
graficar(x,y);