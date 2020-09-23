load('wave.mat');

% Parameters of ship
T=72.4391;
K=0.1561;

% T_d cancles transfer time constant
T_d=T;

% Desired phase margine and crossover frequency;
w_c=0.1;
phi=50;
T_f=tan(40/180*pi)/w_c;
K_pd=w_c*abs(1+w_c*T_f*i)/K;
% K_pd=w_c*abs(1+w_c*T_f*i)/K-0.2;
num=[K*K_pd];
den=[T_f 1 0];
H=tf(num,den);
bode(H);
grid on;

sim('PD_b.slx');
sim('PD_c.slx');
sim('PD_d.slx');

figure(1);
plot(b_Rudder);
hold on;
plot(b_Compass);
hold on;
plot(b_Reference,'--k');
hold on;
xlabel('t[s]');
ylabel('Angle[deg]');
grid on;
% ylabel('\psi_r(t),\psi(t),\delta(t)');
legend('\delta','\psi(t)','\psi_r(t)');
hleg=legend('\delta(t)','\psi(t)','\psi_r','Orientation','vertical');
set(hleg,'Position',[.75,.20,.14,.05]);
title('Autopilot with only measurement noise');

figure(2);
plot(c_Rudder);
hold on;
plot(c_Compass);
hold on;
plot(c_Reference,'--k');
hold on;
xlabel('t[s]');
ylabel('Angle[deg]');
grid on;
% ylabel('\psi_r(t),\psi(t),\delta(t)');
legend('\delta','\psi(t)','\psi_r(t)');
hleg=legend('\delta(t)','\psi(t)','\psi_r','Orientation','vertical');
set(hleg,'Position',[.75,.20,.14,.05]);
title('Autopilot with current disturbances');

figure(3);
plot(d_Rudder);
hold on;
plot(d_Compass);
hold on;
plot(d_Reference,'--k');
hold on;
xlabel('t[s]');
ylabel('Angle[deg]');
grid on;
% ylabel('\psi_r(t),\psi(t),\delta(t)');
legend('\delta','\psi(t)','\psi_r(t)');
hleg=legend('\delta(t)','\psi(t)','\psi_r','Orientation','vertical');
set(hleg,'Position',[.75,.20,.14,.05]);
title('Autopilot with wave disturbances');


figure(4);
plot(b_Rudder);
hold on;
plot(c_Rudder);
hold on;
xlabel('t[s]');
ylabel('Angle[deg]');
grid on;
% ylabel('\psi_r(t),\psi(t),\delta(t)');
legend('\delta without disturbance','\delta with current disturbances');
title('Rudder input with and without current');

figure(5);
plot(d_Rudder);
xlabel('t[s]');
ylabel('Angle[deg]');
grid on;
legend('\delta with wave disturbances');
title('Rudder input with waves');

