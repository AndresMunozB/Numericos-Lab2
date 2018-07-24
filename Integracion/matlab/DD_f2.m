function DD_f2

A = loadData('../resultados/DD/DD_f2_0_5.dat');
B = loadData('../resultados/DD/DD_f2_1.dat');
C = loadData('../resultados/DD/DD_f2_5.dat');
D = loadData('../resultados/DD/DD_f2_10.dat');
E = loadData('../resultados/Real_f2.dat');

graficarTodos(A,B,C,D,E,'Diferencias Divididas, Función: 2');
%graficar(A);
%graficar(B);
%graficar(C);
%graficar(D);
%graficar(E);

end