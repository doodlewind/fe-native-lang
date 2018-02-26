# 重温 Hello World

编写 Hello World 是使用一门语言最简单的方式。在这里，我们除了编写出最简单的 C 代码以外，还会介绍与**编译环境**相关的基础知识，以及我们的**编码风格**所对应的约定。


## 运行示例
在 [main.c](./main.c) 中 Hello World 的代码示例如下：

``` c
#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("Hello World!\n");
  return 0;
}
```

在终端里，我们可以通过 `gcc` 命令编译 C 代码：

``` bash
gcc main.c
```

这会默认在同目录下生成名为 `a.out` 的文件。如何运行呢？

``` bash
./a.out
```

这就足够了！这样看来 C 语言并不比 `npm run dev` 更麻烦吧 :)


## 编译环境
和 JS 这样可通过解释器直接执行源码的**解释型语言**不同，C 语言是需要通过编译器编译到到机器码的**编译型语言**。这个过程和 babel 的转译过程有些接近，但一大区别是 C 编译器生成的是平台相关的**原生机器码**。故而与 babel 生成的 JS 代码可以在各类兼容的 JS 解释器里运行不同，但 C 机器码只能在编译的目标平台下运行：Linux 下的 `a.out` 和 macOS 下的 `a.out` 是不兼容的。

Linux 上的 `gcc` 命令背后是 GCC 编译器，而 macOS 上同样的命令背后其实是 Clang 编译器。不过对于我们的简单示例，这点区别可以忽略。

当然，编译过程从简单的 `.c` 源码到可执行文件的背后，是有大量的幕后工作的。如果对这个过程感兴趣，下面这条命令会是个不错的开始：

``` bash
gcc main.c -S
```


## 基础概念
在我们的 Hello World 中，除了 `"Hello World"` 字符串之外的内容初看起来也许会有些让人摸不着头脑，但对于一个最小可用的 C 应用而言，它们都是必要的。下面整理出我们现在所涉及到的关键语法：

### Include 与库函数
在第一行代码中，我们使用 include 指令导入了 stdio.h 头文件：

``` c
#include <stdio.h>
```

这很自然地会让我们联想到 ES6 的 import 语法：

``` js
import fs from 'fs'
```

二者有何异同呢？它们确实有着相近的目标，即让用户导入并复用库函数。但 C 的 include 语法并没有 import 那么方便。目前我们只需要知道，include 导入的是 `.h` 格式的**头文件**，其中仅包含了各个库函数的**声明**，而没有**定义**。如何区分二者呢？不妨类比下面的代码段：

``` js
// 函数声明
const fn

// 函数定义
fn = () => 123
```

你可以粗略地认为，C 的库函数名已经**声明**在了头文件中，只需 include 后即可在你的代码中使用。而 stdio.h 就是 C 标准库中与 IO 相关的头文件（stdio 即 **St**andar**d** **I**nput **O**utput 的缩写），其中包含了 `printf` 函数的声明。因此在 include 后我们就能够使用这些函数，进而在终端输出 Hello World 了。

思考题：为什么在 JavaScript 中不需要导入任何模块就能调用 `console.log`，而 C 要把 `printf` 设计成导入库函数后才能使用呢？

### Main 函数
对于 JS 文件而言，它的内容即便只有一行简单的 `console.log(123)`，也能在浏览器和 Node 中顺利执行。但 C 语言中你并不能这么写：

``` c
#include <stdio.h>

printf("Hello World!\n");
```

而是需要将代码放在 `main` 函数之中。这又是为什么呢？

请注意我们现在使用 C 语言编写的，实际上已经是原生的**应用**了。在浏览器中进行应用开发时，我们有 React 和 Vue 等框架提供的一套生命周期 API：例如在 Vue 中，我们可以将组件的 `mounted` 方法作为应用代码的入口；类似地在 React 中，这样的入口则是 `componentDidMount` 方法。对原生应用而言，POSIX 规范就相当于一套这样的编程框架，而 C 中的 `main` 函数则是我们的原生应用完成初始化后的入口位置。

就好像前端框架的初始化过程中会在背后做大量杂活一样，C 应用在 `main` 函数执行前也会做许多工作。如果希望对原生应用的编译和执行过程有更深的了解，推荐参阅 CSAPP 和《程序员的自我修养：链接、装载与库》等经典书籍。


## 代码风格
熟悉某门语言的开发者在编写这门语言的代码时，一般都有个人所偏好的代码风格。而在学习一门新语言时，相应的代码风格常常会带来一些困惑：这样的命名符合这门语言的约定吗？这门语言代码的组织与排版的最佳实践是怎样的呢？网上搜索到的代码片段往往风格各异，这更加大了代码风格上的困惑。

在 JavaScript 社区，已经有 ESLint 等工具能帮助我们自动化格式化代码。在 C 中，我们选择 `clang-format` 作为自动化格式代码的工具，相应的风格则是默认的 [LLVM Coding Standard](https://llvm.org/docs/CodingStandards.html)。在前端同学熟悉的 VSCode 中，这个工具也有现成的[插件支持](https://marketplace.visualstudio.com/items?itemName=xaver.clang-format)。在插件安装后即可通过 option-shift-F 快捷键格式化 C / C++ / Objective-C 代码。

> ClangFormat 的 2 空格缩进和目前的前端主流风格很接近，并且类似的风格已经在 Google Chrome 等大型项目中应用。希望它不会让你感觉太别扭 :)
