## 数据结构与算法

- 二维数组的查找
  - 题目描述：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
  - 实现源码：[001.cc](./001.cc)
- 替换空格
  - 题目描述：请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy则经过替换之后的字符串为We%20Are%20Happy。
  - 实现源码：[002.cc](./002.cc)
- 从尾到头打印链表
  - 题目描述：输入一个链表，从尾到头打印链表每个节点的值。
  - 实现源码：[003.cc](./003.cc)
- 重建二叉树
  - 题目描述：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
  - 实现源码：[004.cc](./004.cc)
- 用两个栈实现队列
  - 题目描述：用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
  - 实现源码：[005.cc](./005.cc)
- 旋转数组的最小数字
  - 题目描述：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
  - 实现源码：[006.cc](./006.cc)
- 斐波那契数列
  - 题目描述：大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。n<=39
  - 实现源码：[007.cc](./007.cc)
- 跳台阶
  - 题目描述：一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
  - 实现源码：[008.cc](./008.cc)
- 变态跳台阶
  - 题目描述：一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
  - 实现源码：[009.cc](./009.cc)
- 矩形覆盖
  - 题目描述：我们可以用2×1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2×1的小矩形无重叠地覆盖一个2×n的大矩形，总共有多少种方法？
  - 实现源码：[010.cc](./010.cc)
- 二进制中1的个数
  - 题目描述：输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
  - 实现源码：[011.cc](./011.cc)
- 被3整除的神奇队列
  - 题目描述：有一个神奇的数列：{1,12,123,1234,12345,123456,1234567,...}，现在输入两个数a，b（a<=b）作为数组的起点和终点，请输出该序列（包含起点和终点）中能被3整除数的个数。
  - 实现源码：[012.cc](./012.cc)
- 数值的整数次方
  - 题目描述：给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
  - 实现源码：[013.cc](./013.cc)
- 调整数组顺序使奇数位于偶数前面
  - 题目描述：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
  - 实现源码：[014.cc](./014.cc)
- 链表中倒数第k个结点
  - 题目描述：输入一个链表，输出该链表中倒数第k个结点。
  - 实现源码：[015.cc](./015.cc)
- 合并两个排序的链表
  - 题目描述：输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
  - 实现源码：[016.cc](./016.cc)
- 树的子结构
  - 题目描述：输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）。
  - 实现源码：[017.cc](./017.cc)
- 二叉树的镜像
  - 题目描述：操作给定的二叉树，将其变换为源二叉树的镜像。
  - 实现源码：[018.cc](./018.cc)
- 顺时针打印矩阵
  - 题目描述：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
  - 源码实现：[019.cc](./019.cc)
- 包含min函数的栈
  - 题目描述：定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
  - 源码实现：[020.cc](./020.cc)
- 反转链表
  - 题目描述：输入一个链表，反转链表后，输出链表的所有元素。
  - 源码实现：[021.cc](./021.cc)
- 栈的压入、弹出序列
  - 题目描述：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
  - 源码实现：[022.cc](./022.cc)
- 从上往下打印二叉树
  - 题目描述：从上往下打印出二叉树的每个节点，同层节点从左至右打印。
  - 源码实现：[023.cc](./023.cc)
- 二叉搜索树的后序遍历序列
  - 题目描述：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
  - 源码实现：[024.cc](./024.cc)
- 二叉树中和为某一值的路径
  - 题目描述：输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
  - 实现源码：[025.cc](./025.cc)
- 复杂链表的复制
  - 题目描述：输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
  - 实现源码：[026.cc](./026.cc)
- 二叉搜索树与双向链表
  - 题目描述：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
  - 实现源码：[027.cc](./027.cc)
- 字符串的排序
  - 题目描述：输入一个字符串，按字典序打印出该字符串中字符的所有排列。例如输入字符串abc，则打印出由字符a,b,c所能排列出来的所有字符串abc，acb，bac，bca，cab和cba。输入字符串长度不超过9(可能有字符重复)，字符只包括大小写字母。
  - 实现源码：[028.cc](./028.cc)
- 数组中出现次数超过一半的数字
  - 题目描述：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
  - 实现源码：[029.cc](./029.cc)
