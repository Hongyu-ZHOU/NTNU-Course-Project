% Parameters of ship
T=0;
K=0.1742;

% T_d cancles transfer time constant
T_d=T;

% Desired phase margine and crossover frequency;
w_c=0.1;
phi=50;
T_f=tan(40/180*pi)/w_c;
K_pd=w_c*abs(1+w_c*T_f*i)/K;

num=[K*K_pd];
den=[T_f 1 0];
H=tf(num,den);
bode(H);
grid on;
saveas(gcf,['E:\大学\NTNU\研一\Linear System Theory and Design\Boat lab\Boatfiles\5.3\Bode Diagram','.png'])





