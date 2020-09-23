%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% init()                                                                  %
%                                                                         %              
% Set initial parameters for part1.slx and part2.slx                      %
%                                                                         %
% Created:      2018.07.12	Jon Bjørnø                                    %
%                                                                         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear all;

load('S175.mat');
load('S175ABC.mat');
load('thrusters.mat')

% Initial position x, y, z, theta, phi, psi
eta0 = [0,0,0,0,0,0]';
% Initial velocity u, v, w, p, q, r
nu0 = [0,0,0,0,0,0]';

phi=3/8;
omegab=0.05;
omegan=2*pi/135;

%Set points
ref0=[0 0 0];
ref=[10 10 -pi/2];

damping=1;
Omegan=2*damping*omegan;
omega=omegab/sqrt(1-2*damping^2+sqrt(4*damping^4-4*damping^2+2));
Omega=2*damping*omega;
Vc=1;

%Control plant model
H=[1 0 0 0 0 0; 0 1 0 0 0 0; 0 0 0 0 0 1];
M=inv(vesselABC.Minv);
M3=H*M*transpose(H);

zero=[ 0 0 0; 0 0 0 ; 0 0 0];

getPos=[0; 0; 1];
getVel=[0;1;0];

%PID gains
Kd=7*[M3(1)*Omega 0 0; 0 M3(2,2)*Omega 0; 0 0 20*M(3,3)*Omega];
Kp=50*[M3(1)*omega^2 0 0;0 M3(2,2)*omega^2 0; 0 0 15*M3(3,3)*omega^2 ];
Ki=100*(omega/10)*[M3(1)*omega^2 0 0;0 M3(2,2)*omega^2 0; 0 0 M3(3,3)*omega^2 ]*2;