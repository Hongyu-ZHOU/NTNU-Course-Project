from matplotlib import pyplot as plt
from gridWorld import gridWorld
from pendulum import pendulum
import numpy as np

def show_action_value_function(env, Q):
    pos = {"U": (-0.15, -0.3), "D": (-0.15, 0.4), "L": (-0.45, 0.1), "R": (0.05, 0.1)}
    fig = env.render(show_state = False, show_reward = False)            
    for k in env.states():
        s = env.legal_states[k]
        for i, a in enumerate(env.actions(k)):
            fig.axes[0].annotate("{0:.2f}".format(Q[k, i]), (s[1] + pos[a][0], s[0] + pos[a][1]), size = 40/env.board_mask.shape[0], color = "r" if Q[k, i] == max(Q[k, :]) else "k")
    plt.savefig('Q_action_value_func_0',dpi = 400)
    plt.show()
    
def show_policy(env, Q):
    fig = env.render(show_state = False, show_reward = False)
    action_map = {"U": "↑", "D": "↓", "L": "←", "R": "→"}
    for k in env.states():
        s = k if isinstance(k, tuple) else env.legal_states[k]
        if not env.terminal(s):
            fig.axes[0].annotate(action_map[env.actions(s)[np.argmax(Q[k, :])]], (s[1] - 0.1, s[0] + 0.1), size = 100/env.board_mask.shape[0])
    plt.savefig('Q_policy_0',dpi = 400)
    plt.show()


####################  Problem 1: Q-Learning #################### 
def Q_Learning(env, gamma, Q, alpha, epsilon):
    # Reset environment
    s, r, done = env.reset()

    while True:
        actions = env.actions() 
        if len(actions) == 0:
            break        
        
        a = np.random.choice(actions)
        rand_a = actions.index(a)
        
        best_a = np.argmax(Q[s,:])
        print('rand_a:',rand_a,'best_a:',best_a)
        
        rand_num = np.random.uniform(0,1)
        print('random number', rand_num)
        
        if rand_num > epsilon:
            a_index = rand_a
        else:
            a_index = best_a
            a = actions[best_a]
            print(a,a_index)
                
        s_next, r, done = env.step(a)
        print('s_next',s_next)
     
        best_a_next = np.argmax(Q[s_next,:])
        Q[s,a_index] = Q[s,a_index] + alpha * (r + gamma*Q[s_next,best_a_next] - Q[s,a_index])
        s = s_next
        
        if done == 1:
            break        

    return Q
    """
    YOUR CODE HERE:
    Problem 1a) Implement Q-Learning
    
    Input arguments:
        - env     Is the environment
        - gamma   Is the discount rate
        - Q       Is the Q table
        - alpha   Is the learning rate
        - epsilon Is the probability of choosing greedy action
    
    Some usefull functions of the grid world environment
        - s_next, r, done = env.step(a)  Take action a and observe the next state, reward and environment termination
        - actions = env.actions()        List available actions in current state (is empty if state is terminal)
    """
    

####################  Problem 2: SARSA #################### 
def SARSA(env, gamma, Q, alpha, epsilon):
    # Reset environment
    s, r, done = env.reset()
    
    actions = env.actions() 
    if len(actions) == 0:
        return Q
                 
    a = np.random.choice(actions)   # Greedy policy
    rand_a = actions.index(a)            
    best_a = np.argmax(Q[s,:])
           
    rand_num = np.random.uniform(0,1)            
    if rand_num > epsilon:
        a_index = rand_a
    else:
        a_index = best_a
        a = actions[best_a]
        print(a,a_index)

    
    while True:
        s_next, r, done = env.step(a)            
        actions_next = env.actions() 
        
        if done:   # Terminal state
            Q[s,a_index] = Q[s,a_index] + alpha * (r - Q[s,a_index])
            break
        
        else:      # Greedy policy
            a_next = np.random.choice(actions_next)
            rand_a_next = actions_next.index(a_next)
            best_a_next = np.argmax(Q[s_next,:])
                
            rand_num_next = np.random.uniform(0,1)            
            if rand_num_next > epsilon:
                a_next_index = rand_a_next
            else:
                a_next_index = best_a_next
                a_next = actions_next[best_a_next]
                        
            Q[s,a_index] = Q[s,a_index] + alpha * (r + gamma*Q[s_next,a_next_index] - Q[s,a_index])  # Update
        s = s_next
        a = a_next
        a_index = a_next_index
            
        if done == 1:
            break        

    return Q

    """
    YOUR CODE HERE:
    Problem 2a) Implement SARSA
    
    Input arguments:
        - env     Is the environment
        - gamma   Is the discount rate
        - Q       Is the Q table
        - alpha   Is the learning rate
        - epsilon Is the probability of choosing greedy action
    
    Some usefull functions of the grid world environment
        - s_next, r, done = env.step(a)  Take action a and observe the next state, reward and environment termination
        - actions = env.actions()        List available actions in current state (is empty if state is terminal)
    """



if __name__ == "__main__":
    """
    Note that this code has been written for python 3.x, and requiers the numpy, matplotlib
    and scipy packages.
    """

    # Import the environment from file
    filename = "gridworlds/tiny.json"
    env = gridWorld(filename)

    # Render image
    fig = env.render(show_state = True)
    plt.show()


    """
    Problem 1 (Run Q-Learning)
    
    Below is the code for running Q-Learning, feel free to change the code, and tweek the parameters.
    """
#    gamma = 1.0     # Discount rate
#    alpha = 0.1     # Learning rate
#    epsilon = 0.9   # Probability of taking greedy action
#    episodes = 5000 # Number of episodes
#
#    Q = np.zeros([len(env.states()), 4])
#    for i in range(episodes):
#        Q_Learning(env, gamma, Q, alpha, epsilon)
#
#    # Render Q-values and policy 
#    show_action_value_function(env, Q)
#    show_policy(env, Q)


    """
    Problem 2 (Run SARSA)
    
    Below is the code for running SARSA, feel free to change the code, and tweek the parameters.
    """
#    gamma = 1.0     # Discount rate
#    alpha = 0.1     # Learning rate
#    epsilon = 0  # Probability of taking greedy action
#    episodes = 5000 # Number of episodes
#
#    Q = np.zeros([len(env.states()), 4])
#    for i in range(episodes):
#        SARSA(env, gamma, Q, alpha, epsilon)
#
#    # Render Q-values and policy 
#    show_action_value_function(env, Q)
#    show_policy(env, Q)


    """
    Problem 3) Pendulum 
    
    For this problem the aim is to use either Q-Learning or SARSA for the pendulum environment. You should be able to
    reuse most of the Q-Learning and SARSA algorithms form the preveous problems, but you may have to make two main 
    changes:
        
        1)  The states of the pendulum environment are continous, you must crteate a discretization of the state so 
            that it can be stored in a Q-table. 
    
        2)  The state of the pendulum has multiple elements (s = [theta, theta_dot]) you must change the code so that
            Q-table is able to store this. The simplest way ofdoing this is to create a three dimensional Q-Table in 
            the following way:  Q[theta, theta_dot, action]
    """

    # Create instance of pendulum environment
    env = pendulum()
    fig = env.render()

    gamma   = 0.99  # Discount rate
    alpha   = 0.2   # Learning rate
    epsilon = 0.9   # Probability of taking greedy action
    episodes = 5000 # Number of episodes
    
    num_d = 80
    Q = np.zeros([num_d+1, num_d+1, 3])
    list_theta = np.arange(-np.pi,np.pi,2*np.pi/num_d) 
    list_theta_dot = np.arange(-10,10,2*10/num_d)    
    
    for i in range(episodes):
        s, r, done = env.reset()            
        while True:
            theta_d = np.digitize(s[0], list_theta)
            theta_dot_d = np.digitize(s[1], list_theta_dot)
            
            actions = env.actions() 
            if len(actions) == 0:
                break        
            
            a = np.random.choice(actions)
            rand_a = actions.index(a)    
            best_a = np.argmax(Q[theta_d, theta_dot_d, :])
      
            rand_num = np.random.uniform(0,1)     
            if rand_num > epsilon:
                a_index = rand_a
            else:
                a_index = best_a
                a = actions[best_a]
                    
            s_next, r, done = env.step(a)
            
            theta_next_d = np.digitize(s_next[0], list_theta)
            theta_dot_next_d = np.digitize(s_next[1], list_theta_dot)            
         
            best_a_next = np.argmax(Q[theta_next_d, theta_dot_next_d,:])
            Q[theta_d, theta_dot_d,a_index] = Q[theta_d, theta_dot_d,a_index] + alpha * (r + gamma*Q[theta_next_d, theta_dot_next_d,best_a_next] - Q[theta_d, theta_dot_d,a_index])
            
            s = s_next.copy()
            
            if done == 1:
                break   

    # Plot the value function
    V = np.max(Q, axis=2)   # Value function is given as V(s) = max_a Q(s, a) 
    V[V==0] = np.nan        # Assume states with zeros are not visited and set them to NAN (gives better plot)

    plt.figure()
    plt.imshow(V, cmap="viridis")
    plt.colorbar()
    plt.savefig('Value_function_80',dpi = 400)
    plt.show()


    # Run greedy policy for 10 second to see how the trained policy behaves
    plt.ion()
    fig = env.render()
    s, _, _ = env.reset([np.pi, 0])
    for i in range(200):
        theta_d = np.digitize(s[0], list_theta)
        theta_dot_d = np.digitize(s[1], list_theta_dot)
        s = [theta_d, theta_dot_d] 
        a = np.argmax(Q[theta_d, theta_dot_d,:])
        s, _, _ = env.step(a)        
        plt.pause(env.step_size)