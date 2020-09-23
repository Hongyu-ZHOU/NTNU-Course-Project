% Initial condition
init_x = 0;
init_y = 100;
init_psi = 0;
init_r = 0;

% Coefficients
T = 20;
K = 0.1;
b = 0.001;
U = 5;
dt = 0.1;
N = 5000;
r2d = 180/pi;
d2r = pi/180;

% PID control
% m = ;
% omega = ;
% k = ;
K_p = 0.00048;
K_i = 0.0000000008;
K_d = 0.051;
K_pid = -[K_p K_d K_i];

delta = zeros(1,N); %input
r_dot = zeros(1,N); 
r = zeros(1,N); % yaw rate
psi = zeros(1,N); % yaw
x = zeros(1,N); % x position
y = zeros(1,N); % y position using equation (11)
y(1,1) = init_y;
y_pid = zeros(3,N); % each coloum is [y ; y_dot ; y_int], using equation (12) for y_dot
y_pid(1,1) = init_y;

for i=1:N-1
    
    delta(i) = K_pid * y_pid(:,i); 
    
    % saturation
    if delta(i) > 10 * d2r
        delta(i) = 10 * d2r;
    end
    if delta(i) < - 10 * d2r
        delta(i) = - 10 * d2r;
    end
    
    r_dot(i) = 1/T * (-r(i)+ K*delta(i) + b); % Nomoto model

    % update
    r(i+1) = r(i) + r_dot(i) * dt;
    psi(i+1) = psi(i) + r(i+1) * dt;
    
    y(1,i+1) = y(1,i) + U * sin(psi(i+1)) * dt; % eq (11)
    x(1,i+1) = x(1,i) + U * cos(psi(i+1)) * dt;
    
    y_pid(2,i+1) = U * psi(i+1); % y_dot from eq (12) 
%     y_pid(1,i+1) = U * sin(psi(i+1)) * dt + y_pid(1,i);
    y_pid(1,i+1) = y(1,i+1); % y
    y_pid(3,i+1) = trapz(y(1,1:i+1)); % integration of y
    
end

plot(y,x);


