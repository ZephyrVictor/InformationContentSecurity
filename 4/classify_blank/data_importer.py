import os
import re
import random
import jieba

if __name__ == '__main__':
    pick_num = 2000

    dirNameDict = {
        'C0': 0,  # 汽车
        'C1': 1,  # 财经
        'C2': 2,  # 科技
        'C3': 3,  # 健康
        'C4': 4,  # 体育
    }

    outputPath = 'data/data.txt'
    inputDir = 'data/ClassFile/'
    ofs = open(outputPath, 'w', encoding='utf-8')
    dirnum = 0
    for dirName in dirNameDict.keys():
        newDir = inputDir + dirName + '/'
        if not os.path.exists(newDir):
            continue
        fileList = os.listdir(newDir)
        filenum = -1
        picked = 0

        # 从0-1999中随机抽取500个数
        s = random.sample(range(2000), pick_num)

        for fileName in fileList:
            filenum += 1

            # 只取随机的500个文件，控制数据总量
            if filenum not in s:
                continue

            picked += 1
            filePath = newDir + fileName
            if not os.path.exists(filePath):
                continue

            with open(filePath, 'r', encoding='gbk', errors='ignore') as ifs:
                text = ifs.read()
                # 先构造正则表达式
                text = re.sub(r'[\s+\.\!\/_,$%^*(+\"\')]+|[+——！，。？、~@#￥%……&*（）]+', '', text)
                # 中文分词
                segmented_text = jieba.lcut(text)
                # print(f"segmented_text: {segmented_text}")
                # 用空格连成一个字符串
                segmented_text = "".join(segmented_text)
                ofs.write(segmented_text + '\t' + str(dirNameDict[dirName]) + '\n')
        print(dirnum, picked)
        dirnum += 1

    ofs.close()
