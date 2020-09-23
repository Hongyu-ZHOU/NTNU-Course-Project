%%%%%%%%%%% Paramaters
syms K_1 K_2 K_11 K_12 K_13 K_21 K_22 K_23;

%%%%%%%%%%% Matrix
B=[0 0;0 K_1;K_2 0];
K=[K_11 K_12 K_13;K_21 K_22 K_23];
A=[0 1 0;0 0 0;0 0 0];

%%%%%%%%%%% Computation
P_0=inv(B*K-A)*B; % Dimension of P_0: 3¡Á2. With second row as zeros
P_0(2,:)=[]; % Delete second row

%%%%%%%%%%% Expression of P using elements of K
P=inv(P_0);
