# 简介
信息内容安全本科生实验四

# 安装环境

## 使用conda安装
```shell
conda env create -f environment.yml
```

## 使用pip安装
```shell
pip install -r requirements.txt
```

# 使用方法
1. 运行 `data_importer.py` 导入数据
2. 运行 `data_spliter.py` 划分数据集
3. 运行 `train_test.py` 训练模型并测试
4. 运行 `classify.py` 对输入的文本进行分类