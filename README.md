# GetIt / Algorithm Tracker

C++ 与 Python 算法练习归档，包含题目代码、学习模板、草稿和思路图。

每个 `.cpp` 通常是一个独立程序，按文件编译运行。目录中的难度是个人分类；代码归档不表示每个文件都已通过在线评测。

## 目录

| 路径 | 内容 |
| --- | --- |
| [CodeForce](CodeForce/) | Codeforces 练习 |
| [NiuKee](NiuKee/) | 牛客练习，C++ 与 Python 文件按题目归档 |
| [LanQiao](LanQiao/) | 蓝桥杯及课程练习 |
| [LuoGu](LuoGu/) | 洛谷练习 |
| [Leetcode](Leetcode/) | LeetCode 练习与本地运行模板 |
| [String](String/) | 字符串算法练习 |
| [Notes](Notes/) | 学习模板、演示代码和思路图 |
| [TEST](TEST/) | 本地测试输入，使用前确认对应题目 |
| [tools](tools/) | 格式检查与静态分析辅助脚本 |

## 编译与运行

以下命令在仓库根目录的 PowerShell 中执行。

单独编译 C++ 文件，例如 CF438D：

```powershell
g++ -std=c++20 -O2 .\CodeForce\Hard\The_Child_and_Sequence.cpp -o "$env:TEMP\cf438d.exe"
& "$env:TEMP\cf438d.exe"
```

程序运行后，粘贴该题的完整输入。不要把多个带有 `main()` 的题目链接成同一个程序。

Python 文件直接运行，例如：

```powershell
python .\NiuKee\Eazy\TuBao.py
```

`CMakeLists.txt` 用于本机选择当前练习的目标，保留在本地，不纳入版本管理。本机 CLion / PyCharm 工作区设置也各自保留；更换机器时按实际解释器和编译器路径配置。

## 学习入口与未完成内容

| 文件 | 内容或状态 |
| --- | --- |
| [CF438D](CodeForce/Hard/The_Child_and_Sequence.cpp) | 区间和、区间取模、单点赋值；维护 `sum` 与 `mx` |
| [喧嚣](NiuKee/Medium/Clamor.cpp) | 下一次攻击时间与受伤事件调度 |
| [普通线段树练习](Notes/Segment_Tree_Practice.md) | 单点加、区间求和；配套代码保留 TODO |
| [小鸡的排列构造 checker](NiuKee/Medium/Chicken_Permutation_Checker.md) | 主席树练习；配套代码仍是待完成模板 |
| [LeetCode 49](Leetcode/String/Medium/49_group_anagrams.cpp) | 字母异位词分组，本地测试框架已准备，算法留空；当前含 Windows 头文件 |
| [字符串草稿](String/Drafts/README.md) | 两个入口尚未补齐的文件，当前不能独立编译 |
| [哈夫曼编码演示](Notes/Huffman_Coding.cpp) | 原根目录 `a.cpp`，已转为 UTF-8；保留交互式输入逻辑 |
| [owo 思路图](Notes/Diagrams/owo.drawio) | 字符串拼接问题的探索记录 |

模板的占位输出不代表正确答案。语法检查通过也不能替代题目样例、边界检查和在线评测。

## 文件管理约定

- 提交源码、学习说明、思路图以及共享格式配置。
- `.clang-format`、`.idea/codeStyles/` 和 `.idea/inspectionProfiles/` 保存共享代码风格与检查设置。
- 构建目录、可执行文件、Python 缓存、本机 IDE 状态和编辑器备份由 `.gitignore` 排除，仍可保留在本地使用。
- [工作流参考文件](tools/workflow-examples/README.md) 暂未启用。它们依赖本仓库尚未提供的构建目标，需要调整后才能作为 GitHub Actions 使用。
