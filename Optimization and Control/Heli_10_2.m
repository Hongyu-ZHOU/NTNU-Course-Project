% Initialization for the helicopter assignment in TTK4135.
% Run this file before you execute QuaRC -> Build.

% Updated spring 2018, Andreas L. Flåten
% Updated Spring 2019, Joakim R. Andersen

clear all;
close all;
clc;

% The encoder for travel for Helicopter 2 is different from the rest.
travel_gain = -2; %


%% Physical constants
m_h = 0.4; % Total mass of the motors.
m_g = 0.03; % Effective mass of the helicopter.
l_a = 0.65; % Distance from elevation axis to helicopter body
l_h = 0.17; % Distance from pitch axis to motor

% Moments of inertia
J_e = 2 * m_h * l_a *l_a;         % Moment of interia for elevation
J_p = 2 * ( m_h/2 * l_h * l_h);   % Moment of interia for pitch
J_t = 2 * m_h * l_a *l_a;         % Moment of interia for travel

% Identified voltage sum and difference
V_s_eq = 6.0; % Identified equilibrium voltage sum.
V_d_eq = 0.8; % Identified equilibrium voltage difference. Updated Spring 2019. Old: 0.4

% Model parameters
K_p = m_g*9.81; % Force to lift the helicopter from the ground.
K_f = K_p/V_s_eq; % Force motor constant.
K_1 = l_h*K_f/J_p;
K_2 = K_p*l_a/J_t;
K_3 = K_f*l_a/J_e;
K_4 = K_p*l_a/J_e;

%% Pitch closed loop syntesis
% Controller parameters
w_p = 1.8; % Pitch controller bandwidth.
d_p = 1.0; % Pitch controller rel. damping.
K_pp = w_p^2/K_1;
K_pd = 2*d_p*sqrt(K_pp/K_1);
Vd_ff = V_d_eq;

% Closed loop transfer functions
Vd_max = 10 - V_s_eq; % Maximum voltage difference
deg2rad = @(x) x*pi/180;
Rp_max = deg2rad(15); % Maximum reference step
s = tf('s');
G_p = K_1/(s^2);
C_p = K_pp + K_pd*s/(1+0.1*w_p*s);
L_p = G_p*C_p;
S_p = (1 + L_p)^(-1);

plot_pitch_response = 0;
if plot_pitch_response
    figure()
    step(S_p*Rp_max); hold on;
    step(C_p*S_p*Rp_max/Vd_max);
    legend('norm error', 'norm input')
    title('Pitch closed loop response')
end

%% Elevation closed loop analysis
% Controller parameters
w_e = 0.8; % Elevation controller bandwidth.
d_e = 1.0; % Elevation controller rel. damping.
K_ep = w_e^2/K_3;
K_ed = 2*d_e*sqrt(K_ep/K_3);
K_ei = K_ep*0.1;
Vs_ff = V_s_eq;

% Closed loop transfer functions
Vs_max = 10 - V_s_eq; % Maximum voltage sum
Re_max = deg2rad(10); % Maximum elevation step
G_e = K_3/(s^2);
C_e = K_ep + K_ed*s/(1+0.1*w_e*s) + K_ei/s;
L_e = G_e*C_e;
S_e = (1 + L_e)^(-1);

plot_elev_response = 0;
if plot_elev_response
    figure()
    step(S_e*Re_max);
    hold on;
    step(C_e*S_e*Re_max/Vs_max);
    legend('norm error', 'norm input')
    title('Elevation closed loop response')
end

%% Initial matrix
A_c = [0 1 0 0; 0 0 -K_2 0; 0 0 0 1; 0 0 -K_1*K_pp -K_1*K_pd];
B_c = [0;0;0;K_1*K_pp];
delta_t = 0.25;
A = eye(4) + delta_t*A_c;
B = delta_t*B_c;

%% Number of states and inputs
nx = size(A,2);
nu = size(B,2);

%% Time horizon and initialization
N = 100;
z = zeros(N*(nx+nu),1);
x0_1 = pi;
x0_2 = 0;
x0_3 = 0;
x0_4 = 0;
x0 = [x0_1 x0_2 x0_3 x0_4]';
xf = [0 0 0 0]';

%% Upper and lower bounds
u_l = -30*pi/180;
u_u = 30*pi/180;
x_l = [-inf -inf -30*pi/180 -inf]';
x_u = [inf inf 30*pi/180 inf]';

LB_x = repmat( x_l, N, 1);
UB_x = repmat( x_u, N, 1);
LB_u = repmat( u_l, N, 1);
UB_u = repmat( u_u, N, 1);
LB = [LB_x; LB_u];
UB = [UB_x; UB_u];


%% Solve QP
Q = zeros(nx);
Q(1,1) = 1;
q = 1;
R = q;
G = blkdiag(kron(eye(N),Q),kron(eye(N),R));

A_eq = [eye(N*nx)+kron(diag(ones(N-1,1),-1),-A), kron(eye(N), -B)];
b_eq = [A*x0; zeros(nx*(N-1),1)];

[z,fval,exitflag,output,lambda] = quadprog(G, [], [], [], A_eq, b_eq, LB, UB);

%% Extract states and control input 
x = [reshape(z(1:N*nx),[nx,N])];
u = [reshape(z(N*nx+1:end),[nu,N])];

%% Prep input sequence
padding_time = 5;
padding_input = [zeros(1,floor(padding_time/delta_t)),u,zeros(1,floor(padding_time/delta_t))]';
time = [(0:length(padding_input)-1)*delta_t]';
heli_input = [time padding_input];

travel_opt = [x0_1*ones(1,floor(padding_time/delta_t)), x(1,:), zeros(1,floor(padding_time/delta_t))];
travel_rate_opt = [zeros(1,floor(padding_time/delta_t)), x(2,:), zeros(1,floor(padding_time/delta_t))];
pitch_opt = [zeros(1,floor(padding_time/delta_t)), x(3,:), zeros(1,floor(padding_time/delta_t))];
pitch_rate_opt = [zeros(1,floor(padding_time/delta_t)), x(4,:), zeros(1,floor(padding_time/delta_t))];


figure(1)
subplot(511)
stairs(time,padding_input);
ylabel('u');
subplot(512);
plot(time,travel_opt,'-o');
ylabel('lambda');
subplot(513);
plot(time,travel_rate_opt,'-o');
ylabel('r');
subplot(514);
plot(time,pitch_opt,'-o');
ylabel('p');
subplot(515);
plot(time,pitch_rate_opt,'-o');
xlabel('time(s)');
ylabel('p_c');
grid on;


d2r = pi/180;
travel_offset = 180;
load('Output_10_2');
figure(2)
plot(time,travel_opt,'-o');
hold on;
plot(Output.time,Output.signals.values(:,1)*d2r + pi,'-')
axis([ 0 35 -0.5 3.5]);
legend('\lambda*','\lambda');
xlabel('time(s)');
ylabel('Travel angle(rad)');


figure(3)
plot(time,pitch_opt,'-o');
hold on;
plot(Output.time,Output.signals.values(:,3)*d2r,'-')
axis([ 0 35 -0.6 0.6]);
legend('p*','p');
xlabel('time(s)');
ylabel('Pitch angle(rad)');
