# MySTL

[TOC]



---

#### 开发环境

- Windows 10 19041.804
- VS2019 v16.8.5

------

#### 文档说明

##### *LinkedList<type>*

| 原型                                        | 注释                                         |
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
| **Iterator<type>*** getIterator();          | 获取迭代器                                 |

------

##### *LinkedListNode : Iterable<type>*

| 原型                           | 注释                       |
| ------------------------------ | -------------------------- |
| **Iterable<type>*** getNext(); | 获取下一个节点的迭代器     |
| **type*** getValue();          | 返回指向当前节点数据的指针 |

------

##### *Queue : LinkedList<type>*

|      |      |
| ---- | ---- |
|      |      |
|      |      |
|      |      |



------



##### Stack

##### Map

##### Hash

##### HashNode

##### Iterator

##### Iterable

