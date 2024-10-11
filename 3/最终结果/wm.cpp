#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>

/*
 * Wu-Manber算法的C++类实现，包含详细注释。
 * 该算法用于多模式字符串匹配。
 */

typedef unsigned short HASH_TYPE;

const int HASHTABLESIZE = 65536;   // 哈希表大小
const int SHIFTTABLESIZE = 65536;  // 移位表大小

class WuManber {
private:
    struct Pattern {
        std::string pat;    // 模式串
        size_t length;      // 模式串长度

        Pattern(const std::string& p) : pat(p), length(p.length()) {}
    };

    int msNumPatterns;                   // 模式串数量
    size_t msSmallest;                   // 最短模式串长度
    std::vector<Pattern> patterns;       // 模式串列表
    std::vector<unsigned short> msNumArray;  // 每个组中模式串的数量
    std::vector<HASH_TYPE> msHash;           // 模式串组的哈希表
    std::vector<HASH_TYPE> msPrefix;         // 模式串的前缀哈希值
    std::vector<unsigned char> msShift;      // 坏字符规则的移位表

    // 计算两个字符的16位哈希值
    static unsigned short HASH16(const unsigned char* T) {
        return static_cast<unsigned short>(((T[0] << 8) | T[1]));
    }

    // 根据模式串末尾两个字符的哈希值对模式串进行排序
    void sortPatterns() {
        size_t m = msSmallest;
        std::sort(patterns.begin(), patterns.end(), [m](const Pattern& a, const Pattern& b) {
            return HASH16(reinterpret_cast<const unsigned char*>(a.pat.c_str() + m - 2)) <
                   HASH16(reinterpret_cast<const unsigned char*>(b.pat.c_str() + m - 2));
        });
    }

    // 准备模式串组的哈希表
    void prepHashedPatternGroups() {
        msHash.resize(HASHTABLESIZE, static_cast<HASH_TYPE>(-1));
        msNumArray.resize(msNumPatterns, 0);

        size_t m = msSmallest;
        for (size_t i = 0; i < patterns.size(); ) {
            unsigned short hindex = HASH16(reinterpret_cast<const unsigned char*>(patterns[i].pat.c_str() + m - 2));
            size_t sindex = i;
            msHash[hindex] = static_cast<HASH_TYPE>(i);
            size_t ningroup = 1;

            while (++i < patterns.size() &&
                   hindex == HASH16(reinterpret_cast<const unsigned char*>(patterns[i].pat.c_str() + m - 2))) {
                ningroup++;
            }
            msNumArray[sindex] = static_cast<unsigned short>(ningroup);
        }
    }

    // 准备坏字符规则的移位表
    void prepShiftTable() {
        size_t m = msSmallest;
        msShift.resize(SHIFTTABLESIZE, static_cast<unsigned char>(m - 2 + 1));

        for (const auto& pattern : patterns) {
            for (size_t k = 0; k < m - 1; k++) {
                unsigned short shift = static_cast<unsigned short>(m - 2 - k);
                unsigned short cindex = (pattern.pat[k] << 8) | pattern.pat[k + 1];

                if (shift < msShift[cindex]) {
                    msShift[cindex] = static_cast<unsigned char>(shift);
                }
            }
        }
    }

    // 准备模式串的前缀哈希表
    void prepPrefixTable() {
        msPrefix.resize(msNumPatterns);

        for (size_t i = 0; i < patterns.size(); i++) {
            msPrefix[i] = HASH16(reinterpret_cast<const unsigned char*>(patterns[i].pat.c_str()));
        }
    }

    // 当找到可能的匹配时，进行组匹配
    void groupMatch(size_t lindex, const std::string& text, size_t pos) {
        size_t m = msSmallest;
        size_t index = lindex;
        unsigned short text_prefix = HASH16(reinterpret_cast<const unsigned char*>(text.c_str() + pos));

        size_t ningroup = msNumArray[lindex];

        for (size_t i = 0; i < ningroup; i++, index++) {
            if (msPrefix[index] != text_prefix) {
                continue;
            }

            const std::string& pat = patterns[index].pat;
            if (text.compare(pos, pat.length(), pat) == 0) {
                // 匹配成功，输出匹配信息
                std::cout << "匹配到模式串 \"" << pat << "\" 在位置 " << pos << std::endl;
            }
        }
    }

public:
    WuManber() : msNumPatterns(0), msSmallest(SIZE_MAX) {}

    ~WuManber() {}

    // 添加模式串到模式串集
    void addPattern(const std::string& pattern) {
        patterns.emplace_back(pattern);
        msNumPatterns++;
        if (pattern.length() < msSmallest) {
            msSmallest = pattern.length();
        }
    }

    // 准备模式串（预处理）
    void prepPatterns() {
        sortPatterns();
        prepHashedPatternGroups();
        prepShiftTable();
        prepPrefixTable();
    }

    // 在给定的文本中搜索模式串
    void search(const std::string& text) {
        size_t n = text.length();
        size_t m = msSmallest;

        if (n < m) {
            // 文本长度小于最短模式串，无法匹配
            return;
        }

        size_t pos = 0;
        while (pos <= n - m) {
            unsigned short cindex = (text[pos + m - 2] << 8) | text[pos + m - 1];
            unsigned char tshift = msShift[cindex];

            if (tshift == 0) {
                unsigned short hindex = HASH16(reinterpret_cast<const unsigned char*>(text.c_str() + pos + m - 2));
                size_t lindex = msHash[hindex];

                if (lindex != static_cast<HASH_TYPE>(-1)) {
                    groupMatch(lindex, text, pos);
                }
                pos++;
            } else {
                pos += tshift;
            }
        }
    }
};

int main() {
    WuManber wm;
    int n;
    std::string pattern, text;

    std::cout << "请输入模式串的数量：" << std::endl;
    std::cin >> n;

    std::cout << "请输入模式串：" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> pattern;
        wm.addPattern(pattern);
    }

    wm.prepPatterns();

    std::cout << "请输入要搜索的文本：" << std::endl;
    std::cin >> text;

    wm.search(text);

    return 0;
}
