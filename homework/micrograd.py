#又是ChatGPT生成出來的,但看了後半懂,該如何執行懂,但不知道為甚麼要這麼執行
#謝謝GPT
from micrograd.engine import Value
import numpy as np

def gradient_descent(f, initial_guess, learning_rate, tolerance, max_iterations):
    p = [Value(x) for x in initial_guess]  #轉換成Value,用來執行反向傳播和自動微分
    for iteration in range(max_iterations):
        grad_f = grad(f, p)
        p = [pi - learning_rate * gi for pi, gi in zip(p, grad_f)]
        if np.linalg.norm(grad_f, ord=2) < tolerance:  #檢查梯度的歐幾里得範數有沒有小於收斂標準
            print(f"在第 {iteration + 1} 次迭代收斂。")
            return np.array([pi.data for pi in p])

    print("警告：達到最大迭代次數。")
    return np.array([pi.data for pi in p])

def rosenbrock(x):  #測式用函數
    return sum(100.0 * (x[1:] - x[:-1]**2)**2 + (1 - x[:-1])**2)

def grad(f, p):
    gp = []
    for pi in p:
        pi.backward()
        gp.append(pi.grad)
        pi.zero_grad()
    return gp

def df(f, p, k):
    p1 = [pi.data for pi in p]
    p1[k] = p1[k] + step
    return (f(p1) - f([pi.data for pi in p])) / step

if __name__ == "__main__":
    initial_guess = np.array([0.0, 0.0])
    learning_rate = 0.001
    tolerance = 1e-6
    max_iterations = 10000
    step = 1e-6
    result = gradient_descent(rosenbrock, initial_guess, learning_rate, tolerance, max_iterations)
    print(f"找到的最小值：{rosenbrock(result)}")
    print(f"對應的 x 值：{result}")
