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


%% Control plant model
H=[1 0 0 0 0 0; 0 1 0 0 0 0; 0 0 0 0 0 1];
M=inv(vesselABC.Minv);
M3=H*M*transpose(H);


%% Simulation 1
V_mean=0.5;
W_mean=15;
mu_w=0.001;
mu2_w=0.001;
mu2_c=0.001;
w=0.005;
% current coming from east; waves from southeast; wind from north
phi_c=-pi/2; 
h=0.1;

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

% plot(Ug)
% xlabel('Time [s]')
% ylabel('U_{gust}(t)');

%% Simulation
sim('simulation1.slx');

figure(1)
plot(eta_east.data,eta_north.data);
xlabel('East');
ylabel('North');
title('NE position');
hold on;
plot(0,0,'*');
legend('Position','Origin');
grid on;

figure(2)
plot(eta_east);
xlabel('time[s]');
ylabel('x[m]');
title('East');
grid on;

figure(3)
plot(eta_north);
xlabel('time[s]');
ylabel('y[m]');
title('North');
grid on;

figure(4)
plot(eta_yaw);
xlabel('time[s]');
ylabel('angle[deg]');
title('heading');
grid on;

