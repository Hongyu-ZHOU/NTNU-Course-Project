syms tau;
J = 1;
A_q = [ 
    0 0 0 0 1 0 0 0 0 0;
    0 0 0 0 0 1 0 0 0 0;
    0 0 0 0 0 0 1 0 0 0;
    0 0 0 0 0 0 0 1 0 0;
    -(k1+k2+k3)/J k2/J k3/J 0 -(b1+b2+b3)/J b2/J b3/J 0 1/J 0;
    k2/J -(k2+k4)/J 0 k4/J b2/J -(b2+b4)/J 0 b4/J 0 0;
    k3/J 0 -(k3+k5)/J k5/J b3/J 0 -(b3+b5)/J b5/J 0 0;
    0 k4/J k5/J -(k4+k5)/J 0 b4/J b5/J -(b4+b5)/J 0 1/J;
    0 0 0 0 0 0 0 0 -0.2 0;
    0 0 0 0 0 0 0 0 0 -0.2
    ];
G_q = [0.2, 0; 0, 0.2];
Q_c = diag([1 11]);
expr = expm(A_q*tau)*G_q*Q_c*G_q*expm(A_q*tau);
int(expr,0,0.001)