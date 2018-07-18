function graficarTodos(A,B,C,D,E,name)
figure1 = figure;

% Create axes
axes1 = axes('Parent',figure1);
box(axes1,'on');
hold(axes1,'on');
hold on;
grid on

% Create xlabel
%plot(A(1:end,1),A(1:end,2),'-+','MarkerSize',1,'MarkerFaceColor','c');
%plot(B(1:end,1),B(1:end,2),'-o','MarkerSize',1,'MarkerFaceColor','m'); 
%plot(C(1:end,1),C(1:end,2),'-*','MarkerSize',1,'MarkerFaceColor','y'); 
plot(D(1:end,1),D(1:end,2),'-x','MarkerSize',1,'MarkerFaceColor','r'); 
plot(E(1:end,1),E(1:end,2),'-s','MarkerSize',1,'MarkerFaceColor','g'); 

title(strcat('Método: ',name));
ylabel('Yi'); % y-axis label
xlabel('Xi'); % x-axis label
legend('0.05','0.5','1','5','10');

%saveas(figure1,strcat('imagenes/valores', name) , 'jpg');

end




