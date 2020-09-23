%% Part 1
figure (1)
subplot(2,1,1);
plot(theta_1_m);
hold on;
plot(theta_1_e);
grid on;
legend('measurement','estimate');
xlabel('time [s]');
ylabel('angle [rad]');
title({'$\theta_{L1}$'},'Interpreter','latex');

subplot(2,1,2);
plot(theta_2_m);
hold on;
plot(theta_2_e);
grid on;
legend('measurement','estimate');
xlabel('time [s]');
ylabel('angle [rad]');
title({'$\theta_{L2}$'},'Interpreter','latex');

%% Part 2
figure (2)
subplot(5,1,1);
plot(k2_in);
grid on;
ylim([0.75,2.25]);
xlabel('time [s]');
title({'$k_2$'},'Interpreter','latex');

subplot(5,1,2);
plot(k5_in);
grid on;
ylim([0.75,2.25]);
xlabel('time [s]');
title({'$k_5$'},'Interpreter','latex');

subplot(5,1,3);
plot(h1);
grid on;
ylim([-0.25,1.25]);
xlabel('time [s]');
title({'$h_1$'},'Interpreter','latex');

subplot(5,1,4);
plot(h2);
grid on;
ylim([-0.25,1.25]);
xlabel('time [s]');
title({'$h_2$'},'Interpreter','latex');

subplot(5,1,5);
plot(h3);
grid on;
ylim([-0.25,1.25]);
xlabel('time [s]');
title({'$h_3$'},'Interpreter','latex');