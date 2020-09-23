clear
load('wave.mat');

% parameters
fs=10;
window=4096;
noverlap=[];
nfft=[];

% fndd estimated PSD
[pxx,f]=pwelch(psi_w(2,:).*(pi/180),window,noverlap,nfft,fs);

% convert the outputs to the required units
pxx = pxx./(2*pi);
Omega = f.*2*pi;

% find maximun value and place of pxx
[PSDMax,place] = max(pxx);
Omega_0 = Omega(place);

% fitting curve
Sigma = sqrt(PSDMax);
Lambda = 1;

P_psi_w = @(Lambda,Omega)(4.*Lambda^2.*Omega_0^2.*Sigma^2.*Omega.^2)./(Omega.^4+Omega_0^4+2.*Omega_0^2.*Omega.^2.*(2.*Lambda^2-1));
x = lsqcurvefit(P_psi_w,Lambda,Omega,pxx);
P_psi = (4.*x^2.*Omega_0^2.*Sigma^2.*Omega.^2)./(Omega.^4+Omega_0^4+2.*Omega_0^2.*Omega.^2.*(2.*x^2-1));

%plot
plot(Omega,pxx)
hold on;
plot(Omega,P_psi);
ylabel('S_{\psi_\omega}(\omega),P_{\psi_\omega}(\omega)[rad]');
xlabel('\omega[rad/s]');
legend('S_{\psi_\omega}(\omega)','P_{\psi_\omega}(\omega)');
title(['\lambda=',num2str(x)]);
axis([0 1.6 0 8e-4]);
grid on;