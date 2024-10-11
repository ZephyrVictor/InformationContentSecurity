```
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ .
/StringMatch 
Usage: ./StringMatch <pattern_file> <text_file> <method_choice> [length_threshold]
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test
$ ./StringMatch pattern1w.txt text.txt 1
[AC] Initialization_time=7209ms
进程 109257 的虚拟内存使用 (VSize): 191.50 MB
[AC] Search_time=2907ms Hit_num=267377
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/sr
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/sr
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/sr
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/sr
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/sr
zephyr@zephyr-virtual-machine:/mnt/hgfs/字 zephyr@zephyr-virtual-machine:/mnt/hgfs/字
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern2w.txt text.txt 1
[AC] Initialization_time=5954ms
进程 110098 的虚拟内存使用 (VSize): 355.48 MB
[AC] Search_time=2934ms Hit_num=451305
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern3w.txt text.txt 1
[AC] Initialization_time=10370ms
进程 110182 的虚拟内存使用 (VSize): 722.21 MB
[AC] Search_time=3707ms Hit_num=467021
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern3w.txt text.txt 1
^C
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern1w.txt text.txt 2
[WM] Initialization_time=308ms
进程 110517 的虚拟内存使用 (VSize): 4.30 MB
[WM] Search_time=2343ms Hit_num=267377
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern2w.txt text.txt 2
[WM] Initialization_time=2340ms
进程 110560 的虚拟内存使用 (VSize): 5.61 MB
[WM] Search_time=3522ms Hit_num=451305
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern3w.txt text.txt 2
[WM] Initialization_time=6354ms
进程 110627 的虚拟内存使用 (VSize): 7.15 MB
[WM] Search_time=5377ms Hit_num=467021
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern1w.txt text.txt 3
Usage: ./StringMatch <pattern_file> <text_file> <method_choice> [length_threshold]
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern1w.txt text.txt 3 15
[WM] Initialization_time=71ms
进程 110852 的虚拟内存使用 (VSize): 3.72 MB
[WM] Search_time=993ms Hit_num=23127
[AC] Initialization_time=845ms
进程 110852 的虚拟内存使用 (VSize): 72.19 MB
[AC] Search_time=1821ms Hit_num=244250
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern1w.txt text.txt 3 30
[WM] Initialization_time=10ms
进程 110992 的虚拟内存使用 (VSize): 3.60 MB
[WM] Search_time=613ms Hit_num=3784
[AC] Initialization_time=1267ms
进程 110992 的虚拟内存使用 (VSize): 123.72 MB
[AC] Search_time=2012ms Hit_num=263593
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern1w.txt text.txt 3 5
[WM] Initialization_time=350ms
进程 111061 的虚拟内存使用 (VSize): 4.30 MB
[WM] Search_time=2386ms Hit_num=267377
[AC] Initialization_time=0ms
进程 111061 的虚拟内存使用 (VSize): 3.95 MB
[AC] Search_time=763ms Hit_num=0
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern3w.txt^Ctxt text.txt 3 5
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ^C
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ^C
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ^C
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern3w.txt text.txt 3 5
[WM] Initialization_time=5731ms
进程 111355 的虚拟内存使用 (VSize): 7.15 MB
[WM] Search_time=5118ms Hit_num=467021
[AC] Initialization_time=0ms
进程 111355 的虚拟内存使用 (VSize): 6.46 MB
[AC] Search_time=760ms Hit_num=0
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern3w.txt text.txt 3 15
[WM] Initialization_time=2265ms
进程 111477 的虚拟内存使用 (VSize): 6.29 MB
[WM] Search_time=1677ms Hit_num=89102
[AC] Initialization_time=1142ms
进程 111477 的虚拟内存使用 (VSize): 116.96 MB
[AC] Search_time=2085ms Hit_num=377919
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern3w.txt text.txt 3 20
[WM] Initialization_time=1080ms
进程 112510 的虚拟内存使用 (VSize): 5.86 MB
[WM] Search_time=1207ms Hit_num=34598
[AC] Initialization_time=2678ms
进程 112510 的虚拟内存使用 (VSize): 212.04 MB
[AC] Search_time=2567ms Hit_num=432423
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern3w.txt text.txt 3 25
[WM] Initialization_time=1165ms
进程 112594 的虚拟内存使用 (VSize): 5.86 MB
[WM] Search_time=1080ms Hit_num=34598
[AC] Initialization_time=2617ms
进程 112594 的虚拟内存使用 (VSize): 212.04 MB
[AC] Search_time=2591ms Hit_num=432423
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern3w.txt text.txt 3 30
[WM] Initialization_time=269ms
进程 112695 的虚拟内存使用 (VSize): 5.36 MB
[WM] Search_time=792ms Hit_num=15716
[AC] Initialization_time=4280ms
进程 112695 的虚拟内存使用 (VSize): 356.65 MB
[AC] Search_time=2439ms Hit_num=451305
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ awk '{ print length, $0 }' text.txt | awk '{ count[$1]++ } END { for (len in count) print len, count[len] }'
1 1
5 2206
6 2332
7 2388
8 2647
9 5120
10 5078
11 5111
12 14394
13 14540
14 14771
15 14780
16 14829
17 14926
18 15022
19 15145
20 15081
21 15164
22 12383
23 12416
24 12442
25 12481
26 12539
27 12497
28 12516
29 12558
30 12530
31 12533
32 12529
33 12490
34 12480
35 12479
36 12489
37 12511
38 12529
39 12484
40 12449
41 12461
42 7583
43 7610
44 7649
45 7609
46 3273
47 348
48 347
49 365
50 360
51 365
52 181
53 189
54 186
55 190
56 171
57 162
58 211
59 214
60 184
61 190
62 3
63 2
64 2
65 2
66 4
67 4
68 1
69 2
70 2
71 2
72 4
73 3
74 2
75 2
76 3
77 7
78 4
79 5
80 4
81 3
82 5
83 5
84 2
85 3
86 4
87 3
88 4
89 2
90 3
91 1
92 1
93 1
94 5
95 1
96 2
97 4
98 3
99 3
100 1
101 1
102 1
103 2
104 4
105 1
106 6
107 2
108 1
109 1
110 2
111 6
112 3
113 3
114 6
115 3
116 7
117 1
118 7
119 2
120 2
121 3
122 3
123 1
124 3
125 2
126 3
127 6
128 3
129 4
130 1
131 3
132 3
133 7
134 3
136 2
137 3
138 3
139 4
140 3
141 1
142 3
143 2
145 4
146 3
147 2
148 4
149 6
150 2
151 2
152 3
154 2
155 5
156 4
157 3
158 1
159 6
160 3
161 3
162 2
163 1
164 2
165 4
166 5
167 3
168 6
169 2
170 3
171 3
172 2
173 2
174 7
175 3
177 6
178 2
179 3
180 1
181 3
182 3
183 2
184 2
185 1
186 1
187 1
188 2
189 5
190 4
191 2
192 6
193 4
194 1
195 3
196 1
197 2
198 6
199 3
200 4
201 2
202 2
203 2
204 3
205 3
206 6
207 2
208 2
209 2
210 3
211 3
212 3
213 2
214 5
215 4
216 1
217 1
218 2
219 4
220 1
221 4
222 2
223 2
224 2
225 6
226 3
227 4
228 3
229 2
230 3
231 2
232 1
233 2
234 5
235 1
236 2
237 4
238 7
239 3
240 1
241 1
242 5
243 4
244 4
245 3
246 2
247 2
248 4
249 2
250 3
251 2
252 3
253 1
254 3
255 3
256 2
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern3w.txt text.txt 3 250
[WM] Initialization_time=0ms
进程 113287 的虚拟内存使用 (VSize): 4.35 MB
[WM] Search_time=582ms Hit_num=0
[AC] Initialization_time=8180ms
进程 113287 的虚拟内存使用 (VSize): 722.13 MB
[AC] Search_time=2473ms Hit_num=467021
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern3w.txt text.txt 3 10
[WM] Initialization_time=5319ms
进程 113919 的虚拟内存使用 (VSize): 7.15 MB
[WM] Search_time=3179ms Hit_num=466817
[AC] Initialization_time=0ms
进程 113919 的虚拟内存使用 (VSize): 6.46 MB
[AC] Search_time=837ms Hit_num=204
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern3w.txt text.txt 3 20
[WM] Initialization_time=896ms
进程 114008 的虚拟内存使用 (VSize): 5.86 MB
[WM] Search_time=998ms Hit_num=34598
[AC] Initialization_time=1786ms
进程 114008 的虚拟内存使用 (VSize): 212.04 MB
[AC] Search_time=2241ms Hit_num=432423
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern3w.txt text.txt 3 30
[WM] Initialization_time=341ms
进程 114067 的虚拟内存使用 (VSize): 5.36 MB
[WM] Search_time=518ms Hit_num=15716
[AC] Initialization_time=3860ms
进程 114067 的虚拟内存使用 (VSize): 356.65 MB
[AC] Search_time=2185ms Hit_num=451305
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern3w.txt text.txt 3 40
[WM] Initialization_time=1ms
进程 114143 的虚拟内存使用 (VSize): 4.35 MB
[WM] Search_time=459ms Hit_num=0
[AC] Initialization_time=6992ms
进程 114143 的虚拟内存使用 (VSize): 722.13 MB
[AC] Search_time=2541ms Hit_num=467021
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern3w.txt text.txt 3 50
[WM] Initialization_time=0ms
进程 114213 的虚拟内存使用 (VSize): 4.35 MB
[WM] Search_time=673ms Hit_num=0
[AC] Initialization_time=7072ms
进程 114213 的虚拟内存使用 (VSize): 722.13 MB
[AC] Search_time=2521ms Hit_num=467021
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern1w.txt text.txt 1
[AC] Initialization_time=1703ms
进程 114348 的虚拟内存使用 (VSize): 191.50 MB
[AC] Search_time=2141ms Hit_num=267377
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern2w.txt text.txt 1
[AC] Initialization_time=3578ms
进程 114394 的虚拟内存使用 (VSize): 355.48 MB
[AC] Search_time=2139ms Hit_num=451305
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern3w.txt text.txt 1
[AC] Initialization_time=6903ms
进程 114475 的虚拟内存使用 (VSize): 722.21 MB
[AC] Search_time=3110ms Hit_num=467021
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern1w.txt text.txt 2
[WM] Initialization_time=303ms
进程 114573 的虚拟内存使用 (VSize): 4.30 MB
[WM] Search_time=2432ms Hit_num=267377
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern2w.txt text.txt 2
[WM] Initialization_time=2054ms
进程 114613 的虚拟内存使用 (VSize): 5.61 MB
[WM] Search_time=3189ms Hit_num=451305
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern3w.txt text.txt 2
[WM] Initialization_time=5608ms
进程 114660 的虚拟内存使用 (VSize): 7.15 MB
[WM] Search_time=4727ms Hit_num=467021
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ tmux new
[exited]
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ tmux ls
0: 1 windows (created Thu Oct  3 23:35:12 2024)
1: 1 windows (created Sun Oct  6 18:50:14 2024)
2: 1 windows (created Thu Oct 10 16:12:33 2024)
3: 1 windows (created Thu Oct 10 17:17:43 2024) (attached)
4: 1 windows (created Fri Oct 11 00:35:47 2024) (attached)
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern3w.txt text.txt 3 15
[WM] Initialization_time=1948ms
进程 116808 的虚拟内存使用 (VSize): 6.29 MB
[WM] Search_time=1576ms Hit_num=89102
[AC] Initialization_time=1339ms
进程 116808 的虚拟内存使用 (VSize): 116.96 MB
[AC] Search_time=1922ms Hit_num=377919
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern3w.txt text.txt 3 30
[WM] Initialization_time=257ms
进程 116948 的虚拟内存使用 (VSize): 5.36 MB
[WM] Search_time=704ms Hit_num=15716
[AC] Initialization_time=3372ms
进程 116948 的虚拟内存使用 (VSize): 356.65 MB
[AC] Search_time=2282ms Hit_num=451305
zephyr@zephyr-virtual-machine:/mnt/hgfs/字符串匹配/src/test$ ./StringMatch pattern3w.txt text.txt 3 5
[WM] Initialization_time=5300ms
进程 117021 的虚拟内存使用 (VSize): 7.15 MB
[WM] Search_time=4893ms Hit_num=467021
[AC] Initialization_time=0ms
进程 117021 的虚拟内存使用 (VSize): 6.46 MB
[AC] Search_time=763ms Hit_num=0
```