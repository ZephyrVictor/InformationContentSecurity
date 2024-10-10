#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <queue>
#include <memory>
#include <windows.h>
#include <psapi.h>
#include <iostream>


#define MAX_PATTERNS 100000 // ����ģʽ���������100000��ģʽ
#define MAX_PATTERN_LENGTH 500  //����ÿ��ģʽ����󳤶�Ϊ500
#define ALPHABET_SIZE 256 // ASCII�ַ�����С

template<typename T>
class AhoCorasick {
public:
// trie ��
    struct Node {
        //�洢ָ���ӽڵ��ָ�룬ÿ���ӽڵ��Ӧһ����ĸ
        std::unique_ptr<Node> children[ALPHABET_SIZE];
        Node* fail;  // ƥ��ʧ��ʱ��ת����һ���ڵ�
        bool is_end_of_word; // �Ƿ���ĳ��ģʽ���Ľ�β
        std::string pattern; // �洢�뵱ǰ�ڵ�������ַ���

        Node() : fail(nullptr), is_end_of_word(false) {} //constructor
    };
 // AC�Զ����Ĺ��캯��
    AhoCorasick() : root(std::make_unique<Node>()) {}
 // 
    void insert_pattern(const std::string& pattern) {
        Node* current = root.get(); // from the root node 
        for (char ch : pattern) { // ����ÿһ���ַ� 
        // ��������static_castҪ����ȫ static_cast������������������֮���ת��
        // Ҳ����������ָ������֮���ת��
        // ��������downcast �� upcast
            if (!current->children[static_cast<unsigned char>(ch)]) {
                current->children[static_cast<unsigned char>(ch)] = std::make_unique<Node>();
            }
            // �о�����ԭ���� û�оͿ�һ���µĽڵ�
            current = current->children[static_cast<unsigned char>(ch)].get();
        }
        current->is_end_of_word = true;
        current->pattern = pattern;
    }

    void build_fail_pointers() {
        // ������bfs
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
        // ���������±���
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
                std::cout << "�ҵ�ģʽ��: " << temp->pattern << std::endl;
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
    AhoCorasick<char> ac; // ���ַ���Ϊtemplate��ac
    std::string pattern;
    std::ifstream pattern_file;
    std::ifstream text_file;
    std::string text_data;
    int match_count;
    clock_t start_time_p, end_time_p, start_time_t, end_time_t;
    int p = 0;

    while (p != 1 && p != 2 && p != 3) {
        std::cout << "������ģʽ�ļ����(1~3)��\n";
        std::cin >> p;
        if (p == 1) {
            pattern_file.open("pattern1w.txt");
            if (!pattern_file) {
                std::cerr << "�޷��� 'pattern1w.txt'\n";
                return 1;
            }
        } else if (p == 2) {
            pattern_file.open("pattern2w.txt");
            if (!pattern_file) {
                std::cerr << "�޷��� 'pattern2w.txt'\n";
                return 1;
            }
        } else if (p == 3) {
            pattern_file.open("pattern3w.txt");
            if (!pattern_file) {
                std::cerr << "�޷��� 'pattern3w.txt'\n";
                return 1;
            }
        }
    }

    start_time_p = clock(); // ��¼һ�¿�ʼʱ��
    while (std::getline(pattern_file, pattern)) { // һ��һ�ж�ȡ
        pattern.erase(pattern.find_last_not_of("\r\n") + 1);
        ac.insert_pattern(pattern);
    }
    ac.build_fail_pointers();
    end_time_p = clock();
    pattern_file.close();

    text_file.open("text.txt");
    if (!text_file) {
        std::cerr << "�޷��� 'text.txt'\n";
        return 1;
    }

    text_data.assign((std::istreambuf_iterator<char>(text_file)), std::istreambuf_iterator<char>());
    text_file.close();

    start_time_t = clock();
    match_count = ac.search_text(text_data);
    end_time_t = clock();

    if (p == 1) {
        std::cout << "��ʼ��pattern1w��ʱ: " << static_cast<double>(end_time_p - start_time_p) / CLOCKS_PER_SEC << " ��\n";
        std::cout << "���� pattern1w ��ʱ�䣺" << static_cast<double>(end_time_t - start_time_t) / CLOCKS_PER_SEC << " ��\n";
    } else if (p == 2) {
        std::cout << "��ʼ��pattern2w��ʱ: " << static_cast<double>(end_time_p - start_time_p) / CLOCKS_PER_SEC << " ��\n";
        std::cout << "���� pattern2w ��ʱ�䣺" << static_cast<double>(end_time_t - start_time_t) / CLOCKS_PER_SEC << " ��\n";
    } else if (p == 3) {
        std::cout << "��ʼ��pattern3w��ʱ: " << static_cast<double>(end_time_p - start_time_p) / CLOCKS_PER_SEC << " ��\n";
        std::cout << "���� pattern3w ��ʱ�䣺" << static_cast<double>(end_time_t - start_time_t) / CLOCKS_PER_SEC << " ��\n";
    }

    std::cout << "�ҵ�����ƥ����: " << match_count << std::endl;

    return 0;
}
