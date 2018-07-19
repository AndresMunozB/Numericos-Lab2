metodo = input('Ingrese método : ','s');
funcion = input('Ingrese función: ','s');

if(strcmp(metodo,'MS'))
   if(strcmp(funcion,'1'))
        MS_f1();
   elseif(strcmp(funcion,'2'))
        MS_f2()
   end
elseif(strcmp(metodo,'DD'))
    if(strcmp(funcion,'1'))
        DD_f1();
   elseif(strcmp(funcion,'2'))
        DD_f2()
    end
elseif(strcmp(metodo,'DF'))
    if(strcmp(funcion,'1'))
        DF_f1();
   elseif(strcmp(funcion,'2'))
        DF_f2()
    end
elseif(strcmp(metodo,'CS'))
    if(strcmp(funcion,'1'))
        CS_f1();
   elseif(strcmp(funcion,'2'))
        CS_f2()
   end
end
   
