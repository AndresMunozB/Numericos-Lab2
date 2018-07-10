filename = 'DD_f2_0_5.dat';
delimiterIn = ' ';
A = importdata(filename,delimiterIn);

filename = 'DD_f2_1.dat';
delimiterIn = ' ';
B = importdata(filename,delimiterIn);

filename = 'DD_f2_5.dat';
delimiterIn = ' ';
C = importdata(filename,delimiterIn);

filename = 'DD_f2_10.dat';
delimiterIn = ' ';
D = importdata(filename,delimiterIn);


filename = 'Real_f2.dat';   
delimiterIn = ' ';
E = importdata(filename,delimiterIn);


%filename = 'archivo2.txt';
%delimiterIn = ' ';
%B = importdata(filename,delimiterIn);
    


graficarTodos(A,B,C,D,E,'Diferencias Divididas, Función: 2');
%graficar1(A);
%graficar1(B);
%graficar1(C);
%graficar1(D);
%graficar1(E);