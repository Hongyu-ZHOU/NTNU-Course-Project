K=0.174;
T=86.3;
syms s h;
h=K/(s*s*(s*T+1));
f=ilaplace(h);
ezplot(f,[0,2000]);
hold on;
plot(model,'r');
title('step responce of model and ship')
xlabel('Time(seconds)');
ylabel('Heading(deg)');
legend('ship','model');
axis([0,1000,0,200])