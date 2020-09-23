a_phi_1 = 2.87;
a_phi_2 = -0.65;
delta_a_max = 30;
e_phi_max = 15;
g = 9.81;
V_g = 580/3.6;

zeta_phi = 0.707;
omega_n_phi = sqrt(abs(a_phi_2)*delta_a_max/e_phi_max);

k_p_phi = delta_a_max/e_phi_max*sign(a_phi_2);
k_d_phi = (2*zeta_phi*omega_n_phi-a_phi_1)/a_phi_2;

sys = tf([0, 0, k_p_phi*a_phi_2],[1, a_phi_1+k_d_phi*a_phi_2, k_p_phi*a_phi_2]);
H = tf(-a_phi_2,[1, a_phi_1+k_d_phi*a_phi_2, k_p_phi*a_phi_2, 0]);
% rlocus(H);

k_i_phi = -0.6;

W_chi = 10;
zeta_chi = 0.8;
omega_n_chi = omega_n_phi/W_chi;

k_p_chi = 2*zeta_chi*omega_n_chi*V_g/g;
k_i_chi = omega_n_chi^2*V_g/g;

a_phi2 = -0.65;
a_phi1 = 2.87;
k_pphi = k_p_phi;
k_iphi = k_i_phi;
k_dphi = k_d_phi;
k_px = k_p_chi;
k_ix = k_i_chi;
g = 9.81;
V_a = 580/3.6;
V_g = V_a;
k_g = g/V_g;
deg2rad = pi/180;

