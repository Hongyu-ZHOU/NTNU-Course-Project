%% Thruster Allocation
% position
Lx1=-0.4574;
Lx2=-0.4574;
Lx3=0.3875;
Ly1=-0.055;
Ly2=0.055;
Ly3=0;

% C1
B1 = [ 1 0 1 0 0;
       0 1 0 1 1;
       -Ly1 Lx1 -Ly2 Lx2 Lx3];
K1 = diag( [1.03, 1.03, 1.03, 1.03, 2.629]);
C1 = pinv(B1*K1);

% C2
alpha1 = 0;
alpha2 = 3*pi/4;
B2 = [ cos(alpha1) cos(alpha2) 0;
       sin(alpha1) sin(alpha2) 1;
       Lx1*sin(alpha1)-Ly1*cos(alpha1) Lx2*sin(alpha2)-Ly2*cos(alpha2) Lx3];
K2 = diag( [1.03, 1.03, 2.629]);
C2=inv(K2)*inv(B2);    



%% Observor
% M-matrix:
m    = 14.11;
I_z  =  1.7600;  
x_g = 0.0375;  % x_g  =  0.0460; % Table B.1

% Added mass
X_ud  =   -2.0;									
Y_vd =    -10.0;	
N_vd =    -0.0;		
Y_rd =    -0.0;
N_rd =    -1.0;		
                    
% Total mass matrix
m_11 = m-X_ud;
m_22 = m-Y_vd;
m_23 = m*x_g-Y_rd;
m_32 = m*x_g-N_vd;
m_33 = I_z-N_rd;

M    = [m_11 0    0
        0    m_22 m_23
        0    m_32 m_33];
    
inv_M = inv(M);
	
% Damping coefficients
X_u	= -0.6555;		
X_v	= 0;
Y_v	= -1.33;
Y_r	= -7.250; 
N_v	= 0;
N_r	= -1.900; 
					

% Assembly of the damping matrix
% should be abs(u), abs(v) some places, only positive values? 

d_11 = -X_u ;
d_22 = -Y_v;
d_33 = -N_r;
 
d_12 = -X_v;
d_23 = -Y_r;
d_32 = -N_v;
 
 D    = [d_11 0 0
         0 d_22 d_23
         0 d_32 d_33];
    
% Defining L's
L_1 = diag([12 12 12]);
L_2 = diag([8 8 8]);
L_3 = diag([1 1 1]);
 



%% Maneuvering
% maneuvering_straight line
Umax_1 = 0.1; 
pd_initial = [0;0]; %the initial position 
pd_final = [10;4]; % the final position
mu = 10e-4; % for tracking update law: mu = 0;% for unit-tangent gradient update law,tune

% maneuvering_ellipsoid
Umax_2 = 0.05; 
center = [0; 0];
R = [2; 3];

% tuning parameters
K_1 = 10*diag([2 2 2]);
K_2 = 10*diag([2 2 2]);
b = [0;0;0]; % constant bias
 



plot(simout.signals.values(:,1),simout.signals.values(:,2));
close all;





