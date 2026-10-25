# 工作流参考文件

这里保存整理前位于 `.github/workflows/` 的五个配置文件。

这些配置引用了本仓库尚未提供的内容，包括：

- `make prepare`。
- `unit_tests`、`coverage`、`docs` 等 CMake 目标及测试输出目录。
- pre-commit 配置。
- 文档构建及 GitHub Pages 发布目录。

因此将它们作为参考文件保存，不放在 GitHub Actions 的自动执行目录中。当前推送不会启用这些工作流。

需要启用时，先补齐并验证实际构建或检查流程，再将适用的配置放回 `.github/workflows/`。两个 `run-clang-*.py` 脚本仍保留在 `tools/`，原有版权说明不变。
