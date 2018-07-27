disp('   MENU');

disp('1) Graficar resultados de Diferencias Finitas');
disp('2) Graficar resultados de Diferencias Divididas');
disp('3) Graficar resultados de Mínimos Cuadrados');
disp('4) Graficar resultados de Spline Cubico');
metodo = input('Ingrese método : ','s');


disp('1) Función 1');
disp('2) Funcion 2');
funcion = input('Ingrese función: ','s');

if(strcmp(metodo,'3'))
   if(strcmp(funcion,'1'))
        MS_f1();
   elseif(strcmp(funcion,'2'))
        MS_f2()
   end
elseif(strcmp(metodo,'2'))
    if(strcmp(funcion,'1'))
        DD_f1();
   elseif(strcmp(funcion,'2'))
        DD_f2()
    end
elseif(strcmp(metodo,'1'))
    if(strcmp(funcion,'1'))
        DF_f1();
   elseif(strcmp(funcion,'2'))
        DF_f2()
    end
elseif(strcmp(metodo,'4'))
    if(strcmp(funcion,'1'))
        CS_f1();
   elseif(strcmp(funcion,'2'))
        CS_f2()
   end
end
   
