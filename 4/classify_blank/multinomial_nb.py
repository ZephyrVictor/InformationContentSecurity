import numpy as np
from scipy import sparse

__author__ = "Zephyr#3"

class MultinomialNaiveBayes:
    def __init__(self, alpha=1.0):
        """
        初始化多项朴素贝叶斯分类器。

        参数:
        alpha: 拉普拉斯平滑参数
        """
        self.alpha = alpha
        # 添加所需的属性
        self.classes_ = None  # 类别标签 ["spam", "not spam"]
        self.class_log_prior_ = None  # 类别先验概率的对数 
        self.feature_log_prob_ = None  # 特征条件概率的对数
        self.feature_count_ = None  # 特征在每个类别中的出现次数
        self.class_count_ = None  # 每个类别的样本数
        self.n_features_ = None  # 特征数量

    def fit(self, X, y):
        """
        训练模型。

        参数:
        X: 训练数据，稀疏矩阵（样本数 x 特征数） 每一行是一个样本 每一列是同一个特征
        y: 训练标签，数组
        """
        # 实现多项朴素贝叶斯训练
        self.classes_ = np.unique(y) # 先去重
        n_classes = len(self.classes_)
        n_samples, n_features = X.shape
        self.n_features_ = n_features

        # 初始化
        self.class_count_ = np.zeros(n_classes, dtype=np.float64) # N_c
        self.feature_count_ = np.zeros((n_classes, n_features), dtype=np.float64) # count

        # 每个类别的样本数和特征
        for index, c in enumerate(self.classes_):
            c_indices = np.where(y == c)[0] # 找到训练集中属于类别c的样本 也就是按照类别将他们归类好
            X_c = X[c_indices] #  # 提取出来属于同一类别 构成子矩阵
            self.class_count_[index] = X_c.shape[0] # N_c
            # 特征计数
            if sparse.issparse(X_c):
                self.feature_count_[index, :] = X_c.sum(axis=0).A1 # 计算每个特征在类别 c 中的总和。对于稀疏矩阵使用 .A1 将结果转换为一维数组。
            else:
                self.feature_count_[index, :] = X_c.sum(axis=0)

            class_prior = self.class_count_ / n_samples # P(c)
            self.class_log_prior_ = np.log(class_prior)
            # 按照实验要求来取个对数先
            # if np.any(class_prior == 0):
            #     raise ValueError("Class prior probabilities contain zero, which will cause issues with log calculations.")
            # else:
            #     self.class_log_prior_ = np.log(class_prior) # log(P(c))
            #     # 计算条件概率 就是 4.2.2.3的拉普拉斯平滑公式
            #     smooth_fc = self.feature_count_ + self.alpha # count(x_j, c) + alpha
            #     smooth_cc = smooth_fc.sum(axis=1) + self.alpha * self.n_features_ # 分母

            # # 下面计算log(P(x_j|c))
            # self.feature_log_prob_ = np.log(smooth_fc) - np.log(smooth_cc.reshape(-1, 1))
            # 计算特征条件概率（先计算分子分母，然后再取对数） 要不会有warning 而且上面代码确实有异常
            smoothed_fc = self.feature_count_ + self.alpha  # count(x_j, c) + alpha (分子)
            smoothed_cc = smoothed_fc.sum(axis=1, keepdims=True) + self.alpha * self.n_features_  # Σ(count(x_j, c)) + alpha * m (分母)

            # 计算 log(P(x_j | c))，先计算分子/分母，然后整体取log
            self.feature_log_prob_ = np.log(smoothed_fc / smoothed_cc)


    def predict(self, X):
        """
        预测样本的类别。

        参数:
        X: 测试数据，稀疏矩阵（样本数 x 特征数）

        返回:
        预测的类别数组
        """
        # 实现多项朴素贝叶斯预测
        if sparse.issparse(X): # 对于稀疏矩阵，使用 X @ self.feature_log_prob_.T 计算；对于非稀疏矩阵，使用 np.dot。
            # 稀疏矩阵运算
            jll = X @ self.feature_log_prob_.T
        else:
            jll = np.dot(X, self.feature_log_prob_.T)

        jll += self.class_log_prior_  # 加上先验概率的对数
        # 选择得分最高的类别
        predicted_class_indices = np.argmax(jll, axis=1)
        return self.classes_[predicted_class_indices]