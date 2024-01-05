
import numpy as np

def gradient_descent(f, initial_guess, learning_rate, tolerance, max_iterations):
    """
    梯度下降法算法
    """
    p = initial_guess.copy()  # 複製初始猜測，以避免原地修改
    for iteration in range(max_iterations):
        # 計算梯度
        grad_f = grad(f, p)
        # 使用學習率和負梯度更新參數
        p = p - learning_rate * np.array(grad_f)

        # 檢查算法是否收斂
        if np.linalg.norm(grad_f, ord=2) < tolerance:
            print(f"在第 {iteration + 1} 次迭代收斂。")
            return p

    print("警告：達到最大迭代次數。")
    return p

# 測試函數，這裡以 Rosenbrock 函數為例
def rosenbrock(x):
    return sum(100.0 * (x[1:] - x[:-1]**2)**2 + (1 - x[:-1])**2)

# 使用數值偏微分計算梯度
def grad(f, p):
    gp = p.copy()
    for k in range(len(p)):
        gp[k] = df(f, p, k)
    return gp

# 數值偏微分函式
def df(f, p, k):
    p1 = p.copy()
    p1[k] = p[k] + step
    return (f(p1) - f(p)) / step

if __name__ == "__main__":
    # 設定初始猜測值、學習率、容忍誤差和最大迭代次數
    initial_guess = np.array([0.0, 0.0])
    learning_rate = 0.001
    tolerance = 1e-6
    max_iterations = 10000
    step = 1e-6  # 用於數值偏微分的步長

    # 使用梯度下降法尋找 Rosenbrock 函數的谷底
    result = gradient_descent(rosenbrock, initial_guess, learning_rate, tolerance, max_iterations)

    print(f"找到的最小值：{rosenbrock(result)}")
    print(f"對應的 x 值：{result}")
