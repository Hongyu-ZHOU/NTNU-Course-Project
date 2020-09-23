% % % % omega=0.005
% 
% plot(omega1);
% title('omega=0.005')
% xlabel('Time(seconds)');
% ylabel('Heading(deg)');

% a=min(find(omega1.time>1000));
% b=max(find(omega1.time<1500));
% 
% for i=1:1000
%     x(i)=omega1.data(2007+i);
% end
% 
% MIN=min(x);
% MAX=max(omega1);
% Amp=(MAX-MIN)/2;



% % % % omega=0.05
plot(omega2);
title('omega=0.05')
xlabel('Time(seconds)');
ylabel('Heading(deg)');
% 
% a=min(find(omega2.time>1000));
% b=max(find(omega2.time<1500));
% 
% for i=1:1000
%     x(i)=omega2.data(2007+i);
% end
% 
% MIN=min(x);
% MAX=max(omega2);
% Amp=(MAX-MIN)/2;


