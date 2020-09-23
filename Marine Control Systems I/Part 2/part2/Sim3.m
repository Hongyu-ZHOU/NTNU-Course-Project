%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% init()                                                                  %
%                                                                         %              
% Set initial parameters for part1.slx and part2.slx                      %
%                                                                         %
% Created:      2018.07.12	Jon Bjørn?                                    %
%                                                                         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear all;
clc;
load('S175.mat');
load('S175ABC.mat');
load('thrusters.mat')

% Initial position x, y, z, theta, phi, psi
eta0 = [0,0,0,0,0,0]';
% Initial velocity u, v, w, p, q, r
nu0 = [0,0,0,0,0,0]';

%% PID
omegab=0.05;
omegan=2*pi/135;
damping=1;
Omegan=2*damping*omegan;
omega=omegab/sqrt(1-2*damping^2+sqrt(4*damping^4-4*damping^2+2));
Omega=2*damping*omega;

% Control plant model
H=[1 0 0 0 0 0; 0 1 0 0 0 0; 0 0 0 0 0 1];
M=inv(vesselABC.Minv);
M3=H*M*transpose(H);

getPos=[0;0;1];
getVel=[0;1;0];

% PID gains
Kd=7*[2*M3(1)*Omega 0 0; 0 3*M3(2,2)*Omega 0; 0 0 20*M(3,3)*Omega];
Kp=50*[6*M3(1)*omega^2 0 0;0 M3(2,2)*omega^2 0; 0 0 10*M3(3,3)*omega^2 ];
Ki=100*(omega/10)*[M3(1)*omega^2 0 0;0 0.05*M3(2,2)*omega^2 0; 0 0 M3(3,3)*omega^2 ]*2;

%% Simulation 3
V_mean=0.5;
W_mean=15;
mu_w=0.001;
mu2_w=0.001;
mu2_c=0.001;
w=0.005;
% current coming from east; waves from southeast; wind from north
phi_c=-pi/2;
h=0.1;

% reference model
ref=[0;0;0];
ref1=[50;0;0];
ref2=[50;-50;0];
ref3=[0 -50 -pi/2];
ref4=[0 0 -pi/2];


%% Wind coefficients
C_w=[0 1000.308 0 0
10 1017.407 494.0309 -22019.7
20 1094.354 1093.926 -45874.3
30 1111.453 1834.972 -65141.5
40 1034.506 2505.442 -75233.8
50 931.9108 3105.337 -73398.9
60 760.918 3599.368 -60554.1
70 547.177 3952.247 -44956.8
80 307.787 4093.399 -25689.6
90 68.39712 4234.55 -4587.43
100 -170.993 4199.262 12844.8
110 -401.833 4022.823 30277.04
120 -572.826 3740.52 44956.81
130 -786.567 3281.777 52296.7
140 -974.659 2576.018 54131.67
150 -1068.71 1834.972 47709.27
160 -1085.8 1093.926 36699.44
170 -1043.06 494.0309 20184.69
180 -1008.86 0 0
190 -1043.06 -494.031 -20184.7
200 -1085.8 -1093.93 -36699.4
210 -1068.71 -1834.97 -47709.3
220 -974.659 -2576.02 -54131.7
230 -786.567 -3281.78 -52296.7
240 -572.826 -3740.52 -44956.8
250 -401.833 -4022.82 -30277
260 -170.993 -4199.26 -12844.8
270 68.39712 -4234.55 4587.43
280 307.787 -4093.4 25689.61
290 547.177 -3952.25 44956.81
300 760.918 -3599.37 60554.07
310 931.9108 -3105.34 73398.87
320 1034.506 -2505.44 75233.85
330 1111.453 -1834.97 65141.5
340 1094.354 -1093.93 45874.3
350 1017.407 -494.031 22019.66
360 1000.308 0 0];

% lookup block
psi_r=C_w(:,1);
C_wx=C_w(:,2);
C_wy=C_w(:,3);
C_wn=C_w(:,4);


%% Wind gust
nfreq = 100;
L = 1800;
k = 0.0026;
U10 = 12;

for i = 1:nfreq
    f(i) = 0.01 + (i-1)/(nfreq-1) * 0.99;
    ftilde = L*f(i)/U10;
    S(i) = (4*k*L*U10) / ((2+ftilde^2)^(5/6));
end
    
phi = 2*pi * rand(nfreq,1);
    
for t = 0:3000
    Ug(t+1) = 0;
    for i = 1:nfreq
        Ug(t+1) = Ug(t+1) + sqrt(2*S(i)*(f(2)-f(1))) * cos(2*pi*f(i)*t + phi(i));
    end
end
W_gust=Ug;
t=0:1:3000;

plot(Ug)
xlabel('Time [s]')
ylabel('U_{gust}(t)');


%% Thruster Allocation
% position
Lx1=77;
Lx2=74;
Lx3=70;
Lx4=-65;
Lx5=-72;
Lx6=-72;
Ly1=0;
Ly2=0;
Ly3=0;
Ly4=0;
Ly5=5;
Ly6=-5;

% Weight
K_1=2;
K_2=2;
K_3=1;
K_4=5;
K_5=1;
K_6=1;
W=diag([K_1 K_2 K_3 K_3 K_4 K_5 K_5 K_6 K_6]);

% Ce
t1=[0;1;Lx1];
t2=[0;1;Lx2];
t3=[1;0;Ly3];
t4=[0;1;Lx3];
t5=[0;1;Lx4];
t6=[1;0;Ly5];
t7=[0;1;Lx5];
t8=[1;0;Ly6];
t9=[0;1;Lx6];
Be=[t1 t2 t3 t4 t5 t6 t7 t8 t9];
Ce=inv(W)*Be'/(Be/W*Be');    


%% Thruster Dynamics
xposition=[77, 74, 70, -65, -72, -72];
yposition=[0, 0, 0, 0, 5, -5];

thrust_1=420000;
thrust_2=420000;
thrust_3=500000;
thrust_4=260000;
thrust_5=1100000;
thrust_6=1100000;

thrustrate_1=420000/8;
thrustrate_2=420000/8;
thrustrate_3=500000/8;
thrustrate_4=260000/8;
thrustrate_5=1100000/12;
thrustrate_6=1100000/12;

rotationspeed_3=4*pi;
rotationspeed_5=4*pi;
rotationspeed_6=4*pi;


%% Simulation
sim('simulation3.slx');
% 
ren=[0 50 50 0];
ree=[0 0 -50 -50];
figure(1)
plot(eta_east.data,eta_north.data);
hold on;
plot(ree,ren,'*');
xlabel('East');
ylabel('North');
title('NE position');

figure(2)
plot(eta_east);
hold on;
plot(ref_east)
xlabel('time[s]');
ylabel('x[m]');
title('East');
legend('Actual position','Reference position');
grid on;

figure(3)
plot(eta_north);
hold on;
plot(ref_north);
xlabel('time[s]');
ylabel('y[m]');
title('North');
legend('Actual position','Reference position');
grid on;

figure(4)
plot(eta_yaw);
hold on;
plot(ref_yaw);
xlabel('time[s]');
ylabel('angle[deg]');
title('heading');
legend('Actual position','Reference position');
grid on;


figure(5)
plot(nu_x);
xlabel('time[s]');
ylabel('u[m/s]');
title('x velocity');
grid on;

figure(6)
plot(nu_y);
xlabel('time[s]');
ylabel('v[m/s]');
title('y velocity');
grid on;

figure(7)
plot(nu_phi);
xlabel('time[s]');
ylabel('$\dot{\psi}$[rad/s]','Interpreter','latex');
title('$\dot{\psi}(t)$','Interpreter','latex');
grid on;

% figure(5)
% plot(thruster_u);
% xlabel('time[s]');
% ylabel('u[N]');
% title('thruster_u');
% grid on;
% 
% figure(6)
% plot(thruster_alpha);
% xlabel('time[s]');
% ylabel('angle[rad]');
% title('thruster_alpha');
% grid on;
% 
% figure(7)
% plot(force_bd);
% xlabel('time[s]');
% ylabel('force[N]');
% title('force_bd');
% grid on;