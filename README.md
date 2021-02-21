# MySTL

[toc]

---

## 开发环境

- Windows 10 19041.804
- VS2019 v16.8.5

------

## 文档说明

### 类

#### *LinkedList&lt;type&gt;  : Cloneable- 单向链表*

| 原型                                        | 注释                                       |
| ------------------------------------------- | ------------------------------------------ |
| LinkedList();                               | 初始化一个单项链表                         |
| ~LinkedList();                              | 释放资源                                   |
| **void** add(**int** index,**type** data);  | 在指定位置添加元素                         |
| **void** addFirst(**type** data);           | 在根节点添加元素                           |
| **void** addLast(**type** data);            | 在尾部添加节点（优化）                     |
| **bool** get(**int** index,**type*** data); | 获取指定位置元素，获取成功返回true，反之。 |
| **void** set(**int** index,**type** data);  | 修改指定位置元素（不推荐使用）             |
| **bool** remove(**int** index);             | 删除指定位置元素，删除成功返回true，反之。 |
| **void** clear();                           | 清空链表                                   |
| **int** getCount();                         | 获取链表元素个数                           |
| **Iterator&lt;type&gt;*** getIterator();    | 获取迭代器                                 |
| **void*** clone();                          | 返回实例副本                               |

------

#### *LinkedListNode : Iterable&lt;type&gt; - 单向链表节点*

| 原型                                 | 注释                       |
| ------------------------------------ | -------------------------- |
| **Iterable&lt;type&gt;*** getNext(); | 获取下一个节点的迭代器     |
| **type*** getValue();                | 返回指向当前节点数据的指针 |

------

#### *Queue : LinkedList&lt;type&gt; - 队列*

| 原型                              | 注释                                                         |
| --------------------------------- | ------------------------------------------------------------ |
| Queue();                          | 初始化一个队列                                               |
| **bool** setLimit(**int** limit); | 设置队列长度上限，设置为0则为无限制，设置成功返回true，反之  |
| **void** put(**type** data);      | 将一个元素放入队列末尾，该函数适用于队列长度无限制时         |
| **bool** offer(**type** data);    | 将一个元素放入队列末尾，该函数适用于队列长度有限制时。添加成功返回true，反之 |
| **bool** peek(**type*** data);    | 获取队列第一个元素，如果队列为空则返回false                  |
| **bool** take(**type*** data);    | 获取并删除队列第一个元素，如果队列为空则返回false            |
| **bool** remove();                | 直接删除队列第一个元素，如果队列为空则返回false              |
| **void** clear();                 | 清空队列                                                     |
| **int** getCount();               | 获取队列内元素个数                                           |
| **Queue&lt;type&gt;*** clone()    | 返回实例副本                                                 |

------

#### *Stack : LinkedList&lt;type&gt; - 堆栈*

| 原型                           | 注释                                       |
| ------------------------------ | ------------------------------------------ |
| Stack();                       | 初始化一个堆栈                             |
| **bool** peek(**type*** data); | 获取堆栈顶部元素，成功返回true，反之       |
| **bool** pop(**type*** data);  | 获取并删除堆栈顶部元素，成功返回true，反之 |
| **bool** remove();             | 直接删除堆栈顶部元素，成功返回true，反之   |
| **void** push(**type** data);  | 将元素压入堆栈                             |
| **void** clear();              | 清除堆栈元素                               |
| **int** getCount();            | 获取堆栈中元素个数                         |
| **Stack&lt;type&gt;*** clone() | 返回实例副本                               |

-----

#### *Map&lt;key,value&gt;  - 哈希表*

| 原型                                   | 注释                                                         |
| -------------------------------------- | ------------------------------------------------------------ |
| Map();                                 | 初始化一个哈希表                                             |
| ~Map();                                | 释放资源                                                     |
| Map(**int** size);                     | 初始化指定大小的哈希表<br />注意：大小至少为11，小于该数将会强制设定为11 |
| **bool** put(**key** k, **value** v);  | 将一对键值放入表中，若键已存在则会覆盖并且返回false，弱键不存在则新建并返回true |
| **bool** get(**key** k, **value*** v); | 根据键获取值，存在则返回true，不存在则返回false              |
| **bool** containsKey(**key** key);     | 判断键是否存在，存在返回true，不存在返回false                |
| **bool** remove(**key** k);            | 根据键删除键值对，若键存在返回true，否则返回false            |
| **void** clear();                      | 清空所有键值对                                               |
| **int** getCount();                    | 获取当前键值对个数                                           |
| **int** getSize();                     | 获取当前容量上限                                             |

-----

#### *Hash&lt;key&gt; - 计算哈希值*

| 原型                                                         | 注释                     |
| ------------------------------------------------------------ | ------------------------ |
| *static* **unsigned int** getHashCode(**key** key,**int** size); | 计算指定数据部分的哈希值 |
| *static* **unsigned int** getHashCode(**key** key);          | 计算哈希值（默认）       |

-----

#### *HashNode&lt;key,value&gt; - 哈希节点*

| 原型 | 注释 |
| ---- | ---- |
| ——   | ——   |

------

#### *Iterator&lt;value&gt; - 前向迭代器*

| 原型                          | 注释                                                        |
| ----------------------------- | ----------------------------------------------------------- |
| Iterator(**Iterable*** impl); | 初始化迭代器                                                |
| **value*** next()             | 迭代并返回下一个节点的数据，若不存在下一个节点则返回nullptr |

-----

#### *HuffmanTreeNode&lt;type&gt; - 哈夫曼树节点*

| 原型                                                         | 注释                         |
| ------------------------------------------------------------ | ---------------------------- |
| **bool** operator>=(const **HuffmanTreeNode&lt;type&gt;&** node); | 比较节点中权重大小，用于排序 |
| **bool** operator<=(const **HuffmanTreeNode&lt;type&gt;&** node); | 比较节点中权重大小，用于排序 |

-----

#### Bin : Queue&lt;Code&gt; - 二进制队列

| 原型                  | 注释         |
| --------------------- | ------------ |
| Bin();                | 初始化队列   |
| **char*** toString(); | 转换为字符串 |

-----

#### *HuffmanTree&lt;type&gt; - 哈夫曼树*

| 原型                                                         | 注释                                     |
| ------------------------------------------------------------ | ---------------------------------------- |
| HuffmanTree();                                               | 初始化哈夫曼树                           |
| ~HuffmanTree();                                              | 释放资源                                 |
| **Node*** create(**Stack&lt;HuffmanTreeNode&lt;type&gt;&gt;*** stack); | 根据堆栈数据构建哈夫曼树并返回树的根节点 |

------

#### *Huffman&lt;type&gt; - 哈夫曼编码*

| 原型                                                         | 注释                             |
| ------------------------------------------------------------ | -------------------------------- |
| *static* **Map*** calculate(**Stack&lt;HuffmanTreeNode&lt;type&gt;*** stack); | 根据堆栈数据计算并返回哈夫曼编码 |



-----

### 接口

#### *Iterable&lt;value&gt; - 前向可迭代接口*

| 原型                                   | 注释                                                      |
| -------------------------------------- | --------------------------------------------------------- |
| *virtual* **Iterable*** getNext() = 0; | 获取指向下一个节点的迭代器，若不存在下一节点则返回nullptr |
| *virtual* **value*** getValue() = 0;   | 获取指向当前节点数据的指针                                |

-----

#### *Cloneable - 可拷贝接口*

| 原型                             | 注释           |
| -------------------------------- | -------------- |
| *virtual* **void*** clone() = 0; | 返回实例的副本 |

-----

### 杂项

#### 函数

| 原型                                                         | 注释                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| *extern* void swab(**type*** A, **type*** B)；               | 交换两个指针所指向的值                                       |
| *extern* int compare(**type** A, **type** B);                | 比较两个对象大小：<br />返回值为0表示相等，<br />返回值为正数表示前者更大，<br />返回值为负数则反之 |
| *extern* void ascSort(**type** nums[], **int** left, **int** right); | 对数组进行正序排序**（请使用sort函数）**                     |
| *extern* void descSort(**type** nums[], **int** left, **int** right); | 对数组进行反序排序**（请使用sort函数）**                     |
| *extern* void sort(**type** objs[], **int** count, **SortMode** mode); | 选择模式对数组进行排序                                       |
| *extern* **type** max(**type** A, **type** B)                | 返回两者之间最大者                                           |

#### 结构

#### *enum class SortMode* - 排序模式枚举

| 值   | 注释     |
| ---- | -------- |
| ASC  | 正序排序 |
| DESC | 反序排序 |

-----

#### enum class Code - 二进制位枚举

| 值   | 注释 |
| ---- | ---- |
| Zero | 1    |
| One  | 0    |



-----

## 信息

Make by ***SHIINASAMA***.