function MS_f1

A = loadData('../resultados/MS/MS_f1_0_5.dat');
B = loadData('../resultados/MS/MS_f1_1.dat');
C = loadData('../resultados/MS/MS_f1_5.dat');
D = loadData('../resultados/MS/MS_f1_10.dat');
E = loadData('../resultados/Real_f1.dat');

graficarTodos(A,B,C,D,E,'Mínimos Cuadrados, Función: 1');
%graficar(A);
%graficar(B);
%graficar(C);
%graficar(D);
%graficar(E);

end