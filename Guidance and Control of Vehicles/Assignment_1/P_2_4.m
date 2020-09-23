clear all;
% close all;

% constants
b = 0.001;                   % bias
U = 5;                       % total speed
h = 0.1;                     % sample time
N  = 10000;                  % number of samples

% constants
deg2rad = pi/180;   
rad2deg = 180/pi;

% Nomoto gians and constants
T = 20;
k = 0.1;

% PID controller gians
kp = 0.00048;
ki = 0.00000008;
kd = 0.051;

% memory allocation
x = zeros(N+1,1);
y = zeros(N+1,1);
% ypid = zeros(N+1,1);
psi = zeros(N+1,1);
xdot = zeros(N+1,1);
ydot = zeros(N+1,1);
% ydotpid = zeros(N+1,1);
r = zeros(N+1,1);
rdot = zeros(N+1,1);
delta = zeros(N+1,1);
t = zeros(N+1,1);

% initial conditions
x(1) = 0;
y(1) = 100;
% ypid(1) = 100;
psi(1) = 0;
xdot(1) = 0;
ydot(1) = 0;
% ydotpid(1) = 0;
r(1) = 0;
t(1) = 0;

% % transfer function
% sys = tf(0.5,[20 1 0 0]);
% bode(sys)

% for-end loop
for i = 1:N+1
    t(i) = (i-1)*h;
    
    delta(i) = -kp*y(i)-kd*U*psi(i)-ki*trapz(y);          % PID controller
    if delta(i) > 20*deg2rad                              % input saturation
        delta(i) = 20*deg2rad;
    end
    if delta(i) < -20*deg2rad
        delta(i) = -20*deg2rad;
    end
    
    rdot(i+1) = -r(i)/T+k*delta(i)/T+b/T;                 % Nomoto model
    r(i+1) = r(i)+rdot(i+1)*h;
    psi(i+1) = psi(i)+r(i+1)*h;
    
    xdot(i+1) = U*cos(psi(i+1));
    ydot(i+1) = U*sin(psi(i+1));
%     ydotpid(i+1) = U*psi(i+1);
    
    x(i+1) = x(i)+xdot(i+1)*h;
    y(i+1) = y(i)+ydot(i+1)*h;
%     ypid(i+1) = ypid(i)+ydotpid(i+1)*h;
    
end

psi = psi*rad2deg;
r = r*rad2deg;
psi(N+1) = [];
r(N+1) = [];


% plot figures
figure (1); clf;
hold on;
plot(x,y);
hold off;
grid on;
title('North-East positions');
xlabel('x [m]'); 
ylabel('y [m]');

figure (2); clf;
hold on;
plot(t, psi);
hold off;
grid on;
title('Yaw angle');
xlabel('time [s]'); 
ylabel('yaw angle [deg]');

figure (3); clf;
hold on;
plot(t, r);
hold off;
grid on;
title('Yaw rate');
xlabel('time [s]'); 
ylabel('Yaw rate [deg/s]');

figure (4); clf;
hold on;
plot(t, delta);
hold off;
grid on;
title('Input');
xlabel('time [s]'); 
ylabel('Input');