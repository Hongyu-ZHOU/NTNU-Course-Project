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
A_c = [0 1 0 0 0 0; 
       0 0 -K_2 0 0 0;
       0 0 0 1 0 0; 
       0 0 -K_1* K_pp -K_1* K_pd 0 0;
       0 0 0 0 0 1; 
       0 0 0 0 -K_3*K_ep -K_3*K_ed];
B_c = [0 0; 0 0; 0 0; K_1*K_pp 0; 0 0; 0 K_3*K_ep];
delta_t = 0.25;
A = eye(6) + delta_t*A_c;
B = delta_t*B_c;

%% Number of states and inputs
nx = size(A,2);
nu = size(B,2);

%% Time horizon and initialization
N = 65;
z0 = zeros(N*(nx+nu),1);
z0(1) = pi;
x0_1 = pi;
x0_2 = 0;
x0_3 = 0;
x0_4 = 0;
x0_5 = 0;
x0_6 = 0;
x0 = [x0_1 x0_2 x0_3 x0_4 x0_5 x0_6]';
xf = [0 0 0 0 0 0]';

%% Upper and lower bounds
u_l = [-30*pi/180 -inf]';
u_u = [30*pi/180 inf]';
x_l = [-inf -inf -30*pi/180 -inf -inf -inf]';
x_u = [inf inf 30*pi/180 inf inf inf]';

LB_x = repmat( x_l, N, 1);
UB_x = repmat( x_u, N, 1);
LB_u = repmat( u_l, N, 1);
UB_u = repmat( u_u, N, 1);
LB = [LB_x; LB_u];
UB = [UB_x; UB_u];


%% Solve QP
Q = zeros(nx);
Q(1,1) = 1;
R = diag([1,1]);
G = blkdiag(kron(eye(N),Q),kron(eye(N),R));

A_eq = [eye(N*nx)+kron(diag(ones(N-1,1),-1),-A), kron(eye(N), -B)];
b_eq = [A*x0; zeros(nx*(N-1),1)];

f = @(z) z'*G*z;


options=optimoptions('fmincon','Display','iter','Algorithm','sqp');
[z,fval] = fmincon(f,z0,[],[],A_eq,b_eq,LB,UB,@nonlcon,options);


%% Extract states and control input 
x = [reshape(z(1:N*nx),[nx,N])];
u = [reshape(z(N*nx+1:end),[nu,N])];

%% Prep input sequence
padding_time = 5;
padding_input = [zeros(2,floor(padding_time/delta_t)),u,zeros(2,floor(padding_time/delta_t))]';
time = [(0:length(padding_input)-1)*delta_t]';
heli_input = [time padding_input];

travel_opt = [x0_1*ones(1,floor(padding_time/delta_t)), x(1,:), zeros(1,floor(padding_time/delta_t))];
travel_rate_opt = [zeros(1,floor(padding_time/delta_t)), x(2,:), zeros(1,floor(padding_time/delta_t))];
pitch_opt = [zeros(1,floor(padding_time/delta_t)), x(3,:), zeros(1,floor(padding_time/delta_t))];
pitch_rate_opt = [zeros(1,floor(padding_time/delta_t)), x(4,:), zeros(1,floor(padding_time/delta_t))];
ele_opt = [zeros(1,floor(padding_time/delta_t)), x(5,:), zeros(1,floor(padding_time/delta_t))];
ele_rate_opt = [zeros(1,floor(padding_time/delta_t)), x(6,:), zeros(1,floor(padding_time/delta_t))];

state_opt = [travel_opt; travel_rate_opt; pitch_opt; pitch_rate_opt; ele_opt; ele_rate_opt];
heli_state = [time state_opt'];




% plot
figure(1)
plot(time,travel_opt,'-o',Output.time,Output.signals.values(:,1));
axis([0 25 -1 4]);
legend('\lambda*','\lambda');
xlabel('time(s)');
ylabel('Travel angle(rad)');

figure(2)
plot(time,pitch_opt,'-o',Output.time,Output.signals.values(:,3));
axis([0 25 -0.6 0.6]);
legend('p*','p');
xlabel('time(s)');
ylabel('Pitch angle(rad)');

figure(3)
plot(time,ele_opt,'-o',Output.time,Output.signals.values(:,5));
axis([0 25 0 0.2]);
legend('e*','e');
xlabel('time(s)');
ylabel('Elevation angle(rad)');








