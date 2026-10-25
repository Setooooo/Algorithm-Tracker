#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <string>

// 定义哈夫曼树节点结构体
struct HuffmanNode {
    char character;         // 字符
    int frequency;          // 频率
    HuffmanNode* left;      // 左子树
    HuffmanNode* right;     // 右子树
    HuffmanNode(char c, int f) : character(c), frequency(f), left(nullptr), right(nullptr) {}
};

// 定义优先队列的比较函数，按频率从小到大排序
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
      return a->frequency > b->frequency;
    }
};

// 构建哈夫曼树
HuffmanNode* buildHuffmanTree(const std::vector<std::pair<char, int>>& charFreq) {
  std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Compare> pq;
  // 将所有字符和频率加入优先队列
  for (const auto& cf : charFreq) {
    HuffmanNode* node = new HuffmanNode(cf.first, cf.second);
    pq.push(node);
  }
  // 合并节点直到只剩一个
  while (pq.size() > 1) {
    HuffmanNode* left = pq.top();
    pq.pop();
    HuffmanNode* right = pq.top();
    pq.pop();
    HuffmanNode* internal = new HuffmanNode('\0', left->frequency + right->frequency);
    internal->left = left;
    internal->right = right;
    pq.push(internal);
  }
  return pq.top(); // 返回根节点
}

// 生成哈夫曼编码
void generateCodes(HuffmanNode* root, const std::string& code, std::unordered_map<char, std::string>& codes) {
  if (root == nullptr) {
    return;
  }
  // 如果是叶子节点，记录编码
  if (root->character != '\0') {
    codes[root->character] = code.empty() ? "0" : code; // 确保单个节点有编码
  }
  // 递归遍历左子树和右子树
  generateCodes(root->left, code + "0", codes);
  generateCodes(root->right, code + "1", codes);
}

// 删除哈夫曼树，释放内存
void deleteTree(HuffmanNode* node) {
  if (node == nullptr) {
    return;
  }
  deleteTree(node->left);
  deleteTree(node->right);
  delete node;
}

// 主函数
int main() {
  int n;
  std::cout << "请输入字符数量（需大于10）：";
  std::cin >> n;
  if (n <= 10) {
    std::cout << "字符数量必须大于10！" << std::endl;
    return 1;
  }

  std::vector<std::pair<char, int>> charFreq;
  // 输入字符和频率
  for (int i = 0; i < n; ++i) {
    char c;
    int f;
    std::cout << "请输入第" << i + 1 << "个字符：";
    std::cin >> c;
    std::cout << "请输入字符 " << c << " 的频率：";
    std::cin >> f;
    if (f <= 0) {
      std::cout << "频率必须为正整数！" << std::endl;
      return 1;
    }
    charFreq.push_back({c, f});
  }

  // 构建哈夫曼树
  HuffmanNode* root = buildHuffmanTree(charFreq);

  // 生成编码
  std::unordered_map<char, std::string> codes;
  generateCodes(root, "", codes);

  // 输出结果
  std::cout << "\n哈夫曼编码如下：\n";
  for (const auto& cf : charFreq) {
    std::cout << cf.first << ": " << codes[cf.first] << "\n";
  }

  // 清理内存
  deleteTree(root);

  return 0;
}
