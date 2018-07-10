filename = 'archivo1.txt';
delimiterIn = ' ';
A = importdata(filename,delimiterIn);

filename = 'archivo2.txt';
delimiterIn = ' ';
B = importdata(filename,delimiterIn);

    

graficar(A,B);  
graficar1(A);
graficar1(B);