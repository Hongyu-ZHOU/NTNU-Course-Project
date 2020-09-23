% FOR HELICOPTER NR 3-10
% This file contains the initialization for the helicopter assignment in
% the course TTK4115. Run this file before you execute QuaRC_ -> Build 
% to build the file heli_q8.mdl.

% Oppdatert høsten 2006 av Jostein Bakkeheim
% Oppdatert høsten 2008 av Arnfinn Aas Eielsen
% Oppdatert høsten 2009 av Jonathan Ronen
% Updated fall 2010, Dominik Breu
% Updated fall 2013, Mark Haring
% Updated spring 2015, Mark Haring


%%%%%%%%%%% Calibration of the encoder and the hardware for the specific
%%%%%%%%%%% helicopter
Joystick_gain_x = 1;
Joystick_gain_y = -1;


%%%%%%%%%%% Physical constants
g = 9.81; % gravitational constant [m/s^2]
l_c = 0.46; % distance elevation axis to counterweight [m]
l_h = 0.66; % distance elevation axis to helicopter head [m]
l_p = 0.175; % distance pitch axis to motor [m]
m_c = 1.92; % Counterweight mass [kg]
m_p = 0.72; % Motor mass [kg]


%%%%%%%%%%% Moment of inertia 
J_p = 2*m_p*l_p*l_p;  %pitch
J_e = m_c*l_c*l_c + 2*m_p*l_h*l_h; %elevation
J_t = m_c*l_c*l_c + 2*m_p*(l_h^2+l_p^2); %travel 


%%%%%%%%%%% Sum of the motor voltage V_s0 at euqilibrium point, obtained
%%%%%%%%%%% by measurement
V_s0 = 6.6;


%%%%%%%%%%% Pamameters of linearized equations of motion
K_f = (2*m_p*l_h-m_c*l_c)/(V_s0*l_h)*g;
K_1 = K_f*l_p/J_p;
K_2 = K_f*l_h/J_e;
K_3 = (m_c*l_c-2*m_p*l_h)*g/J_t;

omega=2.5;
damping=1;
K_pd=2*omega*damping/K_1;
K_pp=omega^2/K_1;


%%%%%%%%%%% part 3.3
Q=[3 0 0 0 0;0 3 0 0 0;0 0 90 0 0;0 0 0 0.01 0;0 0 0 0 0.01];
R=[250 0;0 250];
A=[0 1 0 0 0;0 0 0 0 0;0 0 0 0 0;1 0 0 0 0;0 0 1 0 0];
B=[0 0;0 K_1; K_2 0;0 0;0 0];
K=lqr(A,B,Q,R);
P=[K(1,1) K(1,3);K(2,1) K(2,3)]; % Expression of P using elements of K

% Q=[75 0 0 0 0;0 20 0 0 0;0 0 75 0 0;0 0 0 0.01 0;0 0 0 0 0.01];
% R=[1 0;0 0.1];
% A=[0 1 0 0 0;0 0 0 0 0;0 0 0 0 0;1 0 0 0 0;0 0 1 0 0];
% B=[0 0;0 K_1; K_2 0;0 0;0 0];
% K=lqr(A,B,Q,R);
% P=[K(1,1) K(1,3);K(2,1) K(2,3)]; % Expression of P using elements of K

%%%%%%%%%%% part 4.3
A_0=[0 1 0 0 0 0;0 0 0 0 0 0;0 0 0 1 0 0;0 0 0 0 0 0;0 0 0 0 0 1;K_3 0 0 0 0 0;];
B_0=[0 0;0 K_1;0 0;K_2 0;0 0;0 0];
C_0=[0 0 1 0 0 0;0 0 0 0 1 0;];
D=eig(A);
O=[B A*B A*A*B A*A*A*B A*A*A*A*B A*A*A*A*A*B];
N=rank(O);

% Pole placement
es=eig(A-B*K);
r0=max(abs(es));
% Radial
fr=8;
% fr=100; % estimated states are poluted by noise
% fr=0.1; % observor is slower than controller (helicopter is not able to keep stable)
% Sector
phi=pi/8;
r=r0*fr;
spread=-phi:(phi/2.5):phi;
poles=-r*exp(1i*spread);

% plot(real(poles),imag(poles),'sb',real(es),imag(es),'rx');grid on;axis equal;
% L=place(transpose(A_0),transpose(C_0),poles).';

poles1=poles;
poles1(1)=-1.5+0.25*i;poles1(6)=-1.5-0.25*i;
plot(real(poles1),imag(poles1),'rx');

L=place(transpose(A_0),transpose(C_0),poles1).';
