function [c,c_eq] = nonlcon(z)
%Nonlinear constraints

alpha = 0.2;
beta = 20;
lambda_t = 2*pi/3;
n_x = 6;
N = 65;

lambda_k = z(1:n_x:N*n_x );
e_k = z(5:n_x:N*n_x );

c = zeros(N,1);

for i = 1:N
c(i) = alpha*exp(-beta *(lambda_k(i)-lambda_t)^2)-e_k(i);
end

c_eq= [];

end


