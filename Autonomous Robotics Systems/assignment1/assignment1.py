from matplotlib import pyplot as plt
from gridWorld import gridWorld
import numpy as np
from numpy import linalg

def show_value_function(mdp, V):
    fig = mdp.render(show_state = False, show_reward = False)            
    for k in mdp.states():
        s = k if isinstance(k, tuple) else mdp.legal_states[k]
        fig.axes[0].annotate("{0:.3f}".format(V[k]), (s[1] - 0.1, s[0] + 0.1), size = 40/mdp.board_mask.shape[0])
    plt.savefig('P1_c_1_v',dpi = 400)
    plt.show()
    
def show_policy(mdp, PI):
    fig = mdp.render(show_state = False, show_reward = False)
    action_map = {"U": "↑", "D": "↓", "L": "←", "R": "→"}
    for k in mdp.states():
        s = k if isinstance(k, tuple) else mdp.legal_states[k]
        if mdp.terminal[s] == 0:
            fig.axes[0].annotate(action_map[PI[k]], (s[1] - 0.1, s[0] + 0.1), size = 100/mdp.board_mask.shape[0])
    plt.savefig('P1_c_1_p',dpi = 400)
    plt.show()
    
####################  Problem 1: Value Iteration #################### 

def value_iteration(mdp, gamma, theta = 1e-3):
    # Make a valuefunction, initialized to 0
    V = np.zeros((len(mdp.states())))    
    
    error = []
    iterations = 0
    while True: 
        delta = 0
        V_pre = V.copy()
        for s in mdp.states():
            v = V[s]
            V_max = np.zeros((len(mdp.states())))
            i = 0   
            for a in mdp.actions(s):
                next_states = filter(lambda s_next: ( mdp.transition_probability(s, a, s_next) > 0), mdp.states())
                V_max[i] = sum(map(lambda s_next: (mdp.transition_probability(s,a,s_next)*(mdp.reward(s_next)+gamma*V[s_next])), next_states))
                i += 1  
            V[s] = np.max(V_max)
            delta = max(delta, np.abs(v-V[s]))            
        error.append(linalg.norm(V-V_pre,np.inf))
        iterations += 1
        if delta < theta:
#            V[3] = 1
#            V[6] = -1
            E = np.max(error)
            print(E)
            return V, iterations


def policy(mdp, V):
    # Initialize the policy list of crrect length
    PI = np.random.choice(env.actions(), len(mdp.states()))
      
    for s in mdp.states():
        PI_max = np.zeros((len(mdp.states())))
        i = 0       
        if len(mdp.actions(s)) == 0:
            continue       
        for a in mdp.actions(s):
            next_states = filter(lambda s_next: ( mdp.transition_probability(s, a, s_next) > 0), mdp.states())
            PI_max[i] = sum(map(lambda s_next: (mdp.transition_probability(s,a,s_next)*(mdp.reward(s_next)+gamma*V[s_next])), next_states))
            i += 1           
        a_ind = np.argmax(PI_max)
        PI[s] = mdp.actions(s)[a_ind]
         
    return PI

####################  Problem 2: Policy Iteration #################### 
def policy_evaluation(mdp, gamma, PI, V, theta = 1e-3):   

#    V = np.zeros(len(states))
    
    error = []

    while True:
        delta = 0
        V_pre = V.copy()
        for s in mdp.states():
            v = V[s]
            next_states = filter(lambda s_next: ( mdp.transition_probability(s, PI[s], s_next) > 0), mdp.states())
            V[s] = sum(map(lambda s_next: (mdp.transition_probability(s,PI[s],s_next)*(mdp.reward(s_next)+gamma*V[s_next])), next_states))
            delta = max(delta, np.abs(v-V[s]))

        error.append(linalg.norm(V-V_pre,np.inf))
        if delta < theta:
            E = np.max(error)
            print(E)
            return V
        
    
def policy_iteration(mdp, gamma):
    # Make a valuefunction, initialized to 0
    V = np.zeros((len(mdp.states())))
    
    # Create an arbitrary policy PI
    PI = np.random.choice(env.actions(), len(mdp.states()))
    
    iterations = 0
    while True:
        V = policy_evaluation(mdp, gamma, PI, V)
        PI_stable = True
        
        for s in mdp.states():
            pi = PI[s]
            i = 0
            if len(mdp.actions(s)) == 0:
                continue
            V_max = np.zeros((len(mdp.actions(s))))
            for a in mdp.actions(s):
                next_states = filter(lambda s_next: ( mdp.transition_probability(s, a, s_next) > 0), mdp.states())
                V_max[i] = sum(map(lambda s_next: (mdp.transition_probability(s,a,s_next)*(mdp.reward(s_next)+gamma*V[s_next])), next_states))
                i += 1
            PI_ind = np.argmax(V_max)
            PI_best = mdp.actions(s)[PI_ind]
            PI[s] = PI_best
            if pi != PI[s]:
                PI_stable = False
                
        iterations += 1        
        if PI_stable:
            break
#    V[3] = 1
#    V[6] = -1        
    return PI, V, iterations

if __name__ == "__main__":
    """
    Change the parameters below to change the behaveour, and map of the gridworld.
    gamma is the discount rate, while filename is the path to gridworld map. Note that
    this code has been written for python 3.x, and requiers the numpy and matplotlib
    packages

    Available maps are:
        - gridworlds/tiny.json
        - gridworlds/large.json
    """
    gamma   = 1
    filname = "gridworlds/tiny.json"


    # Import the environment from file
    env = gridWorld(filname)

    # Render image
    fig = env.render(show_state = False)
    plt.show()
     
    # Run Value Iteration and render value function and policy
    V, iterations_v_i = value_iteration(mdp = env, gamma = gamma)
    print("Number of outer loop iterations with value iteration: ", iterations_v_i)
    show_value_function(env, V)
    
    PI = policy(env, V)
    show_policy(env, PI)
    
    # Run Policy Iteration and render value function and policy
    PI, V , iterations_p_i = policy_iteration(mdp = env, gamma = gamma)
    print("Number of outer loop iterations with policy iteration: ", iterations_p_i)
    show_value_function(env, V)
    show_policy(env, PI)
