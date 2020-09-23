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

%%%%%%%%%%% part 2.1
omega=2.5;
damping=1;
K_pd=2*omega*damping/K_1;
K_pp=omega^2/K_1;

%%%%%%%%%%% part 3.3
Q=[90 0 0 0 0;0 25 0 0 0;0 0 90 0 0;0 0 0 50 0;0 0 0 0 80];
R=[1 0;0 1];
A=[0 1 0 0 0;0 0 0 0 0;0 0 0 0 0;1 0 0 0 0;0 0 1 0 0];
B=[0 0;0 K_1; K_2 0;0 0;0 0];
K=lqr(A,B,Q,R);
P=[K(1,1) K(1,3);K(2,1) K(2,3)]; % Expression of P using elements of K



plot(Y_joystick.time,Y_joystick.signals.values,'linewidth',2);hold on;
plot(elevation.time,elevation.signals.values,'linewidth',2);hold on;
plot(Inteffect_elevation.time,Inteffect_elevation.signals.values,'linewidth',2);
legend('Y_ joystick','elevation without integral effect','elevation with integral effect')
xlabel('time/s');

