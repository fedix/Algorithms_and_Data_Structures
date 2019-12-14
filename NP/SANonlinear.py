import numpy as np
import random
from functools import reduce


def decreaseTemperature(initialTemperature, i):
    return initialTemperature * 0.1 / i


def getTransitionProbability(dE, T):
    return np.exp(-dE / T)


def isTransition(P):
    return True if random.random() <= P else False


def generateStateCandidate(w_state, diap=(-2.1, 2.1)):
    # w = []
    # for i in range(len(w_state)):
    #     w.append(random.random() * reduce(lambda x, y: abs(x) + abs(y), diap) - diap[-1])
    #
    w = w_state
    idx_to_change = random.randint(0, 3)
    w[idx_to_change] = random.random() * reduce(lambda x, y: abs(x) + abs(y), diap) - diap[-1]

    return w


def simulatedAnnealing(func, w, initialTemperature, endTemperature, n_iters=1000):
    w_state = w
    cur_loss = func(w_state)
    T = initialTemperature
    i = 1
    while T > endTemperature and i < n_iters:
        print(f'{i}:, T = {T:.3f},  loss = {cur_loss:.3f}, w = {w_state}')
        w_candidate = generateStateCandidate(w_state)
        candidate_loss = func(w_candidate)
        if candidate_loss < cur_loss:
            cur_loss = candidate_loss
            w_state = w_candidate
        else:
            p = getTransitionProbability(candidate_loss - cur_loss, T)
            if isTransition(p):
                cur_loss = candidate_loss
                w_state = w_candidate
        T = decreaseTemperature(initialTemperature, i)
        i += 1
    return w_state


k = [x for x in range(0, 1001)]
xs = np.array([3 * x / 1000 for x in k])
delta = np.random.normal(0, 1, 1001)
f = lambda x: 1 / (x * x - 3 * x + 2)

ys = []
f = lambda x: 1 / (x * x - 3 * x + 2)
for i, x in enumerate(xs):
    if f(x) < -100:
        ys.append(-100 + delta[i])
    elif f(x) > 100:
        ys.append(100 + delta[i])
    else:
        ys.append(f(x) + delta[i])


def errFunc(w):
    res = 0
    val = lambda x: (w[0] * x + w[1]) / (x * x + w[2] * x + w[3])
    for i, x in enumerate(xs):
        res += (val(x) - ys[i]) ** 2
    return res


def main():
    w = [1.5, 1.5, 1.5, 1.5]
    res = simulatedAnnealing(errFunc, w, 10, 0.001)
    print(res)


if __name__ == '__main__':
    main()
