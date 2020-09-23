%% Information 
% This file is only an example of how you can start the simulation. The
% sampling time decides how often you store states. The execution  time
% will increase if you reduce the sampling time.

% Please note that the file "pathplotter.m" (only used in the second part
% of the assignment) shows the ship path during the path following and
% target tracking part of the assignment. It can be clever to adjust the sampling
% time when you use that file because it draws a sketch of the ship in the
% North-East plane at each time instant. Having a small sampling time will
% lead to multiple ship drawings on top of each other. 

% You should base all of your simulink models on the MSFartoystyring model
% and extend that as you solve the assignment. For your own sake, it is
% wise to create a new model and run file for each task.

% The msfartoystyring.m file includes the ship model. You are not allowed
% to change anything within that file. You need to include that file in
% every folder where you have a simulink model based on
% "MSFartoystyring.slx". 

% WP.mat is a set of six waypoints that you need to use in the second part of
% the assignment. The north position is given in the first row and the east
% position in the second row. 


%%
tstart=0;           % Sim start time
tstop=10000;        % Sim stop time
tsamp=10;           % Sampling time for how often states are stored. (NOT ODE solver time step)
       
d2r = pi/180;
p0=zeros(1000,700);      % Initial position (NED)
v0=[6.63 0]';       % Initial velocity (body)
psi0=60*d2r;             % Inital yaw angle
r0=0;               % Inital yaw rate
c=1;                % Current on (1)/off (0)

K_p = -2.2816;
K_i = -0.0023;
K_d = -161.6429;

sat = 25*ones(1001,1);

a1 = 6145;
a2 = -0.0075;
a3 = 1.0384;
K_u_i = 1e-5;
K_u_p = 0.2;
omega = 0.05;
delta = 0.8;

load('WP.mat');
WP_x = WP(1,:);
WP_y = WP(2,:);

sim MSFartoystyring_TargetTracking % The measurements from the simulink model are automatically written to the workspace.
% pathplotter(x, y,  psi, tsamp, 2, tstart, tstop, 0, WP)


% figure (1)
% subplot(3,1,1);
% plot(psi*180/pi);
% hold on;
% plot(psi_d*180/pi);
% hold on;
% plot(psi_tilde*180/pi);
% grid on;
% legend({'$\psi$','$\psi_d$','$\tilde{\psi}$'},'Interpreter','latex');
% title('True, desired and estimated yaw angle');
% xlabel('time [t]');
% ylabel('angle [deg]');
% % set(gcf,'Position',[50 50 1500 500]);
% 
% subplot(3,1,2);
% plot(r*180/pi);
% hold on;
% plot(r_d*180/pi);
% hold on;
% plot(r_tilde*180/pi);
% grid on;
% legend({'$\psi$','$\psi_d$','$\tilde{\psi}$'},'Interpreter','latex');
% title('True, desired and estimated yaw rate');
% xlabel('time [t]');
% ylabel('angle rate [deg/s]');
% % set(gcf,'Position',[50 50 1500 500]);
% 
% subplot(3,1,3);
% plot(delta_c*180/pi);
% hold on;
% plot(t,sat,'k--');
% hold on;
% plot(t,-sat,'k--');
% grid on;
% ylim([-30 30]);
% legend({'$\delta_c$','saturation limits'},'Interpreter','latex');
% title('Rudder input');
% xlabel('time [t]');
% ylabel('angle [deg]');
% set(gcf,'Position',[100 100 800 500]);