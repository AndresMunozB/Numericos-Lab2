function MS_f1
filename = 'MS_f1_0_5.dat';
delimiterIn = ' ';
A = importdata(filename,delimiterIn);

filename = 'MS_f1_1.dat';
delimiterIn = ' ';
B = importdata(filename,delimiterIn);

filename = 'MS_f1_5.dat';
delimiterIn = ' ';
C = importdata(filename,delimiterIn);

filename = 'MS_f1_10.dat';
delimiterIn = ' ';
D = importdata(filename,delimiterIn);


filename = 'Real_f1.dat';
delimiterIn = ' ';
E = importdata(filename,delimiterIn);


%filename = 'archivo2.txt';
%delimiterIn = ' ';
%B = importdata(filename,delimiterIn);
    


graficarTodos(A,B,C,D,E,'Mínimos Cuadrados, Función: 1');
%graficar1(A);
%graficar1(B);
%graficar1(C);
%graficar1(D);
%graficar1(E);
end