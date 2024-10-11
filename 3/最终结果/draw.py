import subprocess
import re
import matplotlib.pyplot as plt

# 定义存储N值、WM时间和AC时间的列表
N_values = range(5, 50)  # N从5到50
wm_times = []
ac_times = []

# 正则表达式模式，用于提取时间
wm_pattern = r'\[WM\] Search_time=(\d+)ms'
ac_pattern = r'\[AC\] Search_time=(\d+)ms'

memory_pattern = r'进程 \d+ 的虚拟内存使用 \(VSize\): (\d+\.\d+) MB'

result_string  = ""

for N in N_values:
    # 构建命令
    command = ['./StringMatch', 'pattern3w.txt', 'text.txt', '3', str(N)]
    try:
        # 执行命令并捕获输出
        result = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        output = result.stdout + result.stderr

        result_string += output + "\r\n"

        # 提取WM算法的搜索时间
        wm_search_time = re.search(wm_pattern, output)
        if wm_search_time:
            wm_time = int(wm_search_time.group(1))
            wm_times.append(wm_time)
            print(f"N={N}时候，wm的算法的搜索时间是{wm_time}")
        else:
            wm_times.append(None)
            print(f"N={N}时未找到WM算法的搜索时间。")

        # 提取AC算法的搜索时间
        ac_search_time = re.search(ac_pattern, output)
        if ac_search_time:
            ac_time = int(ac_search_time.group(1))
            ac_times.append(ac_time)
            print(f"N={N}时候，ac的算法的搜索时间是{ac_time}")
        else:
            ac_times.append(None)
            print(f"N={N}时未找到AC算法的搜索时间。")

    except Exception as e:
        wm_times.append(None)
        ac_times.append(None)
        print(f"N={N}时执行命令出错：{e}")



# 绘制图形
plt.figure(figsize=(10, 6))
plt.plot(N_values, wm_times, label='WM Search Time', marker='o')
plt.plot(N_values, ac_times, label='AC Search Time', marker='s')
plt.xlabel('length N')
plt.ylabel('time (ms)')
plt.title('Search Time Between AC and WM')
plt.legend()
plt.grid(True)
plt.savefig('./fig.png')
with open('./result.txt') as f:
    f.write(result_string)