clear all;
clc;
close all;
load('wave.mat');
load('c_Compass');
load('c_Rudder');
load('d_Compass');
load('d_Rudder');

%% Parameters
T=72.4391;
K=0.1561;
% K=0.17;
omega_0=0.7823;
lamda=0.0791;
sigma=0.0281;
K_w=2*lamda*omega_0*sigma;


%% PD controller
% T_d cancles transfer time constant
T_d=T;

% Desired phase margine and crossover frequency;
w_c=0.1;
phi=50;
T_f=tan(40/180*pi)/w_c;
K_pd=w_c*abs(1+w_c*T_f*i)/K-0.2;
num=[K*K_pd];
den=[T_f 1 0];
H=tf(num,den);
bode(H);
grid on;

%% Discretization
% Matrices from Task 5.4.a
A=[0 1 0 0 0;-omega_0^2 -2*lamda*omega_0 0 0 0;0 0 0 1 0;0 0 0 -1/T -K/T;0 0 0 0 0];
B=[0; 0; 0; K/T; 0];
C=[0 1 1 0 0];
D=0;
E=[0 0; K_w 0; 0 0; 0 0; 0 1];

% Sample time
F_s=10;
T_s=1/F_s;

% Discretization
[Ad,Bd]=c2d(A,B,T_s);
[Ad,Ed]=c2d(A,E,T_s);
Cd=C;
Dd=D;

%% Variance R & Q
% sim('VarCal.slx');
% R=var(Compass.data*pi/180)/T_s;
R=6.0666e-6;

% Q is the Process noise covariance
% Q = [30 0; 0 10e-6];

% Larger Q
Q = [300 0; 0 10e-2];
% Smaller Q
% Q = [3 0; 0 10e-10];

% Initial value
P_0 = diag([1 0.013 pi^2 1 2.5e-3]);
x_0 = [zeros(5,1)];
I = eye(5);
data = struct('Ad',Ad,'Bd',Bd,'Cd',Cd,'Ed',Ed,'Q',Q,'R',R,'P_0',P_0,'x_0',x_0,'I',I);


sim('KF_e.slx');

figure(1);
plot(bias,'LineWidth',1);
hold on;
plot(rudder,'LineWidth',1);
xlabel('t[s]');
ylabel('Angle[deg]');
grid on;
legend('Bias','Rudder input');
title('Bias and rudder input');

figure(2);
plot(d_Rudder);
xlabel('t[s]');
ylabel('Angle[deg]');
grid on;
legend('Rudder without Kalman filter');
title('Rudder input wiouth Kalman filter');

figure(3);
plot(psi_est,'LineWidth',1);
hold on;
plot(compass,'LineWidth',1);
hold on;
plot(reference,'--k');
xlabel('t[s]');
ylabel('Angle[deg]');
grid on;
legend('Estimated heading','Measurement with Kalman filter');
title('Compass course with Kalman filter');

figure(4);
plot(compass,'LineWidth',1);
hold on;
plot(d_Compass,'LineWidth',1);
hold on;
plot(reference,'--k');
xlabel('t[s]');
ylabel('Angle[deg]');
grid on;
legend('Measurement with Kalman filter','Measurement without Kalman filter');
title('Compass course with and without Kalman filter');

% Wave influence
for i=1:5005
    time(i)=psi_w(1,i);
    wave_inf(i)=psi_w(2,i);
end

figure(5);
plot(psi_w_est,'LineWidth',1);
hold on;
plot(time,wave_inf,'LineWidth',1);
xlabel('t[s]');
ylabel('Angle[deg]');
grid on;
legend('Estimated wave influence','Actual wave influence');
title('Wave influence');


