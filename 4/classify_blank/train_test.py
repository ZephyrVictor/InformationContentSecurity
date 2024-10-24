# coding: utf-8
import numpy as np
from sklearn import metrics
import joblib
from sklearn.feature_extraction.text import HashingVectorizer

from multinomial_nb import MultinomialNaiveBayes


def input_data(train_file, test_file):
    train_words = []
    train_tags = []

    with open(train_file, 'r', encoding='utf-8') as f:
        for line in f:
            tks = line.strip().split('\t')
            if len(tks) >= 2:
                train_words.append(tks[0])
                train_tags.append(tks[1])

    test_words = []
    test_tags = []
    with open(test_file, 'r', encoding='utf-8') as f:
        for line in f:
            tks = line.strip().split('\t')
            if len(tks) >= 2:
                test_words.append(tks[0])
                test_tags.append(tks[1])

    return train_words, train_tags, test_words, test_tags


def vectorize(train_words, test_words):
    # 停用词表
    with open('dict/stopwords.txt', 'r', encoding='utf-8') as f:
        stopwords = [w.strip() for w in f if w.strip()]  # 使用列表并过滤空字符串

    v = HashingVectorizer(stop_words=stopwords, n_features=30000, alternate_sign=False)
    train_data = v.fit_transform(train_words)
    test_data = v.transform(test_words)  # 使用 transform 而不是 fit_transform

    return train_data, test_data


def evaluate(actual, pred):
    m_precision = metrics.precision_score(actual, pred, average='weighted', zero_division=0)
    m_recall = metrics.recall_score(actual, pred, average='weighted', zero_division=0)
    m_f1_score = metrics.f1_score(actual, pred, average='weighted', zero_division=0)

    print(u' 准确率:     {0:0.3f}'.format(m_precision))
    print(u' 召回率:     {0:0.3f}'.format(m_recall))
    print(u' F1-score:   {0:0.3f}'.format(m_f1_score))


# Multinomial Naive Bayes Classifier（多项朴素贝叶斯）
def train_clf_MNB(train_data, train_tags):
    clf = MultinomialNaiveBayes(alpha=1.0)
    clf.fit(train_data, np.array(train_tags))
    return clf


def main():
    train_file = 'data/train.txt'
    test_file = 'data/test.txt'
    # 加载数据
    print('\nload =======================================')
    train_words, train_tags, test_words, test_tags = input_data(train_file, test_file)
    print('Step 1: input_data OK')
    train_data, test_data = vectorize(train_words, test_words)
    print('Step 2: vectorize OK')

    # Multinomial Naive Bayes Classifier
    print('\nMNB =======================================')
    # 训练
    clf = train_clf_MNB(train_data, train_tags)
    print('Step 3: train_clf OK')
    # 保存模型
    joblib.dump(clf, 'model/' + str(type(clf))[8:-2] + '.model')
    print('Step 4: model save OK')
    # 预测
    pred = clf.predict(test_data)
    print('Step 5: predict OK')
    # 计算准确率、召回率、F1
    evaluate(np.asarray(test_tags), pred)
    print('Step 6: evaluate OK')


if __name__ == '__main__':
    main()
