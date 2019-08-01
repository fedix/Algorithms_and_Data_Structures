import numpy as np
import random as rand


def decreaseTemperature(initialTemperature, i):
    return initialTemperature * 0.1 / i


def getTransitionProbability(dE, T):
    return np.exp(-dE / T)


def isTransition(P):
    return True if rand.random() <= P else False


def generateStateCandidate(path):
    n = len(path) - 1
    i = rand.randint(0, n)
    j = rand.randint(i, n)

    if i == 0:
        path = path[0:i] + path[j:i:-1] + [path[0]] + path[j + 1:]
    else:
        path = path[0:i] + path[j:i - 1:-1] + path[j + 1:]

    return path


def getStateEnergy(state, cities):
    energy = 0
    for i in range(len(state)):
        energy += cities[state[i - 1]][state[i]]
    return energy


def simulatedAnnealing(cities, initialTemperature, endTemperature):
    state = list(range(len(cities)))
    rand.shuffle(state)
    currentEnergy = getStateEnergy(state, cities)
    T = initialTemperature
    i = 1
    while T > endTemperature:
        stateCandidate = generateStateCandidate(state)
        candidateEnergy = getStateEnergy(stateCandidate, cities)
        if candidateEnergy < currentEnergy:
            currentEnergy = candidateEnergy
            state = stateCandidate
        else:
            p = getTransitionProbability(candidateEnergy - currentEnergy, T)
            if isTransition(p):
                currentEnergy = candidateEnergy
                state = stateCandidate
        T = decreaseTemperature(initialTemperature, i)
        i += 1
    return state


def main():
    cities = [[0, 1, 15, 6],
              [2, 0, 7, 3],
              [9, 6, 0, 12],
              [10, 4, 8, 0]]

    path = simulatedAnnealing(cities, 10, 0.00001)
    print(path)
    print(f"path length: {getStateEnergy(path, cities)}")


#
if __name__ == '__main__':
    main()
