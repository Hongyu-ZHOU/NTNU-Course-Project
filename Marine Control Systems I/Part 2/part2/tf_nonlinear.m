% Gians for observor
% omega_ci/omega_i
k1 = 1.2;
k2 = 1.2;
k3 = 1.2;
% omega_i
k4 = 2*pi/9;
k5 = 2*pi/9;
k6 = 2*pi/9;
% using typical values
K1=[-1.8*diag([k1 k2 k3]);1.8*diag([k4 k5 k6])];
% omega_ci/omega_i*omega_i
K2=diag([k4*k1 k5*k2 k6*k3]);
% 1/T_i << K_3i/K_4i < omega_i < omega_ci
% k10-k12 should be sufficient high
k10= 0.1;
k11 = 0.01;
k12 = 0.01;
K3=0.1*diag([k10,k11,k12]);
K4=diag([k10 k11 k12]);

T=1000*diag([1 1 1]);

% Transfer function
figure(1)
num_o1=[1 2*0.1*k4 k4*k4];
den_o1=[1 1.8*k4+k4*k1+2*0.1*k4 k4*k4+2*0.1*k4*k4*k1 k4*k4*k4*k1];
h_o1=tf(num_o1,den_o1);
num_b1=[K4(1,1) K4(1,1)/T(1,1)+K3(1,1)];
den_b1=[1 1/T(1,1)];
h_b1=tf(num_b1,den_b1);
h_1=h_o1*h_b1;
bode(h_1);
grid on;

figure(2)
num_o2=[1 2*0.1*k5 k5*k5];
den_o2=[1 1.8*k5+k5*k2+2*0.1*k5 k5*k5+2*0.1*k5*k5*k2 k5*k5*k5*k2];
h_o2=tf(num_o1,den_o1);
num_b2=[K4(2,2) K4(2,2)/T(2,2)+K3(2,2)];
den_b2=[1 1/T(2,2)];
h_b2=tf(num_b2,den_b2);
h_2=h_o2*h_b2;
bode(h_2);
grid on;

figure(3)
num_o3=[1 2*0.1*k6 k6*k6];
den_o3=[1 1.8*k6+k6*k3+2*0.1*k6 k6*k6+2*0.1*k6*k6*k3 k6*k6*k6*k3];
h_o3=tf(num_o3,den_o3);
num_b3=[K4(3,3) K4(3,3)/T(3,3)+K3(3,3)];
den_b3=[1 1/T(3,3)];
h_b3=tf(num_b3,den_b3);
h_3=h_o3*h_b3;
bode(h_3);
grid on;

