#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <queue>
#include <memory>
#include <windows.h>
#include <psapi.h>
#include <iostream>


#define MAX_PATTERNS 100000 // 假设模式集中最多有100000个模式
#define MAX_PATTERN_LENGTH 500  //假设每个模式的最大长度为500
#define ALPHABET_SIZE 256 // ASCII字符集大小

template<typename T>
class AhoCorasick {
public:
// trie 树
    struct Node {
        //存储指向子节点的指针，每个子节点对应一个字母
        std::unique_ptr<Node> children[ALPHABET_SIZE];
        Node* fail;  // 匹配失败时跳转到另一个节点
        bool is_end_of_word; // 是否是某个模式串的结尾
        std::string pattern; // 存储与当前节点关联的字符串

        Node() : fail(nullptr), is_end_of_word(false) {} //constructor
    };
 // AC自动机的构造函数
    AhoCorasick() : root(std::make_unique<Node>()) {}
 // 
    void insert_pattern(const std::string& pattern) {
        Node* current = root.get(); // from the root node 
        for (char ch : pattern) { // 遍历每一个字符 
        // 这里面用static_cast要更安全 static_cast可以用来做基本数据之间的转换
        // 也可以用来做指针类型之间的转换
        // 还可以做downcast 和 upcast
            if (!current->children[static_cast<unsigned char>(ch)]) {
                current->children[static_cast<unsigned char>(ch)] = std::make_unique<Node>();
            }
            // 有就利用原来的 没有就开一个新的节点
            current = current->children[static_cast<unsigned char>(ch)].get();
        }
        current->is_end_of_word = true;
        current->pattern = pattern;
    }

    void build_fail_pointers() {
        // 用来做bfs
        std::queue<Node*> q;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (root->children[i]) {
                root->children[i]->fail = root.get();
                q.push(root->children[i].get());
            }
        }

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
        // 裤裤就是往下遍历
            for (int i = 0; i < ALPHABET_SIZE; ++i) {
                if (current->children[i]) {
                    Node* fail_node = current->fail;
                    while (fail_node && !fail_node->children[i]) {
                        fail_node = fail_node->fail;
                    }
                    if (fail_node) {
                        current->children[i]->fail = fail_node->children[i].get();
                    } else {
                        current->children[i]->fail = root.get();
                    }
                    q.push(current->children[i].get());
                }
            }
        }
    }

    int search_text(const std::string& text) {
        Node* current = root.get();
        int match_count = 0;

        for (char ch : text) {
            while (current && !current->children[static_cast<unsigned char>(ch)]) {
                current = current->fail;
            }
            if (!current) {
                current = root.get();
            } else {
                current = current->children[static_cast<unsigned char>(ch)].get();
            }

            Node* temp = current;
            while (temp != root.get() && temp->is_end_of_word) {
                std::cout << "找到模式串: " << temp->pattern << std::endl;
                match_count++;
                temp = temp->fail;
            }
        }

        return match_count;
    }

private:
    std::unique_ptr<Node> root;
};

int main() {
    AhoCorasick<char> ac; // 单字符作为template的ac
    std::string pattern;
    std::ifstream pattern_file;
    std::ifstream text_file;
    std::string text_data;
    int match_count;
    clock_t start_time_p, end_time_p, start_time_t, end_time_t;
    int p = 0;

    while (p != 1 && p != 2 && p != 3) {
        std::cout << "请输入模式文件序号(1~3)：\n";
        std::cin >> p;
        if (p == 1) {
            pattern_file.open("pattern1w.txt");
            if (!pattern_file) {
                std::cerr << "无法打开 'pattern1w.txt'\n";
                return 1;
            }
        } else if (p == 2) {
            pattern_file.open("pattern2w.txt");
            if (!pattern_file) {
                std::cerr << "无法打开 'pattern2w.txt'\n";
                return 1;
            }
        } else if (p == 3) {
            pattern_file.open("pattern3w.txt");
            if (!pattern_file) {
                std::cerr << "无法打开 'pattern3w.txt'\n";
                return 1;
            }
        }
    }

    start_time_p = clock(); // 记录一下开始时间
    while (std::getline(pattern_file, pattern)) { // 一行一行读取
        pattern.erase(pattern.find_last_not_of("\r\n") + 1);
        ac.insert_pattern(pattern);
    }
    ac.build_fail_pointers();
    end_time_p = clock();
    pattern_file.close();

    text_file.open("text.txt");
    if (!text_file) {
        std::cerr << "无法打开 'text.txt'\n";
        return 1;
    }

    text_data.assign((std::istreambuf_iterator<char>(text_file)), std::istreambuf_iterator<char>());
    text_file.close();

    start_time_t = clock();
    match_count = ac.search_text(text_data);
    end_time_t = clock();

    if (p == 1) {
        std::cout << "初始化pattern1w耗时: " << static_cast<double>(end_time_p - start_time_p) / CLOCKS_PER_SEC << " 秒\n";
        std::cout << "搜索 pattern1w 的时间：" << static_cast<double>(end_time_t - start_time_t) / CLOCKS_PER_SEC << " 秒\n";
    } else if (p == 2) {
        std::cout << "初始化pattern2w耗时: " << static_cast<double>(end_time_p - start_time_p) / CLOCKS_PER_SEC << " 秒\n";
        std::cout << "搜索 pattern2w 的时间：" << static_cast<double>(end_time_t - start_time_t) / CLOCKS_PER_SEC << " 秒\n";
    } else if (p == 3) {
        std::cout << "初始化pattern3w耗时: " << static_cast<double>(end_time_p - start_time_p) / CLOCKS_PER_SEC << " 秒\n";
        std::cout << "搜索 pattern3w 的时间：" << static_cast<double>(end_time_t - start_time_t) / CLOCKS_PER_SEC << " 秒\n";
    }

    std::cout << "找到的总匹配数: " << match_count << std::endl;

    return 0;
}
