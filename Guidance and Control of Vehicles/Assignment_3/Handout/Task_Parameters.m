% % Task 1.2
% x = [T K]
fun = @(x,t)((1-exp(-t/x(1)))*x(2));
x0 = [150,-0.001];
x = lsqcurvefit(fun,x0,t,r)

plot(t,r);
hold on;
plot(t,(1-exp(-t/x(1)))*x(2));
grid on;
xlabel('Time(s)');
ylabel('r(rad/s)');
title('Nonlinear least?squares curve-fitting of the model');

% % Task 1.4
T = x(1);
K = x(2);
omega_b = 1/T;
zeta = 0.8;
omega_n = omega_b / sqrt(1-2*zeta^2+sqrt(4*zeta^4-4*zeta^2+2));
K_p = omega_n^2*T / K;
K_i = (omega_n^3*T) /(10*K);
K_d = (2*zeta*omega_n*T-1) / K;

% % Task 1.6
% y = [B C]
n_c = [1:8 , (85*2*pi)/60]
n_c_2 = n_c.*n_c;
u_ss = [1.0391 1.9665 2.9455 3.9272 4.9091 5.8909 6.8727 7.8545 8.7393]

fun = @(y,u_ss)(y(1)*u_ss + y(2)*u_ss.*abs(u_ss));
y0 = [0, 0];
y = lsqcurvefit(fun,y0,u_ss,n_c_2)
B = y(1);
C = y(2);
plot(n_c,u_ss);
hold on;
plot(n_c,sqrt(B*u_ss + C*u_ss.*abs(u_ss)));
grid on;
xlabel('Commanded shaft speed(rad/s)');
ylabel('steady state surge speed(m/s)');
title('Nonlinear least squares curve-fitting of the surge model');

% value = zeros(1,1001)
% surge = [u, u_dot];
Y = 25 - B*u - C*u*u;
Y_data = getdatasamples(Y,[1:1001])';
u_dot_data = getdatasamples(u_dot,[1:1001])';
fun = @(A,u_dot_data)(A*u_dot_data);
A0 = [5000];
A = lsqcurvefit(fun,A0,u_dot_data,Y_data)


