# 整篇程式碼都是ChatGPT生出來的(我有給它偏微分的函式),生出來後我有看懂
import numpy as np

def gradient_descent(f, initial_guess, learning_rate, tolerance, max_iterations):  #梯度下降法,f是要最小化的目標,learning_rate是步長,tolerance是收斂的標準,max_iterations是次數上限
    p = initial_guess.copy()  # 複製一份,怕被改到
    for iteration in range(max_iterations):
        # 計算梯度
        grad_f = grad(f, p)   #用學習率和負梯度更新參數
        p = p - learning_rate * np.array(grad_f)
        if np.linalg.norm(grad_f, ord=2) < tolerance:  #檢查有沒有收斂
            print(f"在第 {iteration + 1} 次迭代收斂。")
            return p

    print("警告：達到最大迭代次數。")
    return p

def rosenbrock(x): #測試用的函數
    return sum(100.0 * (x[1:] - x[:-1]**2)**2 + (1 - x[:-1])**2)

def grad(f, p): #用偏微分計算梯度
    gp = p.copy()
    for k in range(len(p)):
        gp[k] = df(f, p, k)
    return gp

def df(f, p, k): #偏微分的函式
    p1 = p.copy()
    p1[k] = p[k] + step
    return (f(p1) - f(p)) / step

if __name__ == "__main__":
    initial_guess = np.array([0.0, 0.0])
    learning_rate = 0.001
    tolerance = 1e-6
    max_iterations = 10000
    step = 1e-6  

    result = gradient_descent(rosenbrock, initial_guess, learning_rate, tolerance, max_iterations)

    print(f"找到的最小值：{rosenbrock(result)}")
    print(f"對應的 x 值：{result}")
