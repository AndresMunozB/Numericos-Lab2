function graficar(x,y)
figure1 = figure;

% Create axes
axes1 = axes('Parent',figure1);
box(axes1,'on');
hold(axes1,'on');
hold on;
grid on

% Create xlabel
plot([x],[y],'-k.','MarkerSize',5,'MarkerFaceColor','b'); 

title('grafico');
ylabel('y'); % y-axis label
xlabel('x'); % x-axis label
legend('function');

%saveas(figure1,strcat('imagenes/valores', name) , 'jpg');

end