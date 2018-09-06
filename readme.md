## 数据结构与算法

- 二维数组的查找
    - 题目描述：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
    - 实现源码：[cc](./cc/001.cc)
- 替换空格
    - 题目描述：请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy则经过替换之后的字符串为We%20Are%20Happy。
    - 实现源码：[cc](./cc/002.cc)
- 从尾到头打印链表
    - 题目描述：输入一个链表，从尾到头打印链表每个节点的值。
    - 实现源码：[cc](./cc/003.cc)
- 重建二叉树
    - 题目描述：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
    - 实现源码：[cc](./cc/004.cc)
- 用两个栈实现队列
    - 题目描述：用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
    - 实现源码：[cc](./cc/005.cc)
- 旋转数组的最小数字
    - 题目描述：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
    - 实现源码：[cc](./cc/006.cc)
- 斐波那契数列
    - 题目描述：大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。n<=39
    - 实现源码：[cc](./cc/007.cc)
- 跳台阶
    - 题目描述：一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
    - 实现源码：[cc](./cc/008.cc)
- 变态跳台阶
    - 题目描述：一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
    - 实现源码：[cc](./cc/009.cc)
- 矩形覆盖
    - 题目描述：我们可以用2×1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2×1的小矩形无重叠地覆盖一个2×n的大矩形，总共有多少种方法？
    - 实现源码：[cc](./cc/010.cc)
- 二进制中1的个数
    - 题目描述：输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
    - 实现源码：[cc](./cc/011.cc)
- 被3整除的神奇队列
    - 题目描述：有一个神奇的数列：{1,12,123,1234,12345,123456,1234567,...}，现在输入两个数a，b（a<=b）作为数组的起点和终点，请输出该序列（包含起点和终点）中能被3整除数的个数。
    - 实现源码：[cc](./cc/012.cc)
- 数值的整数次方
    - 题目描述：给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
    - 实现源码：[cc](./cc/013.cc)
- 调整数组顺序使奇数位于偶数前面
    - 题目描述：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
    - 实现源码：[cc](./cc/014.cc)
- 链表中倒数第k个结点
    - 题目描述：输入一个链表，输出该链表中倒数第k个结点。
    - 实现源码：[cc](./cc/015.cc)
- 合并两个排序的链表
    - 题目描述：输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
    - 实现源码：[cc](./cc/016.cc)
- 树的子结构
    - 题目描述：输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）。
    - 实现源码：[cc](./cc/017.cc)
- 二叉树的镜像
    - 题目描述：操作给定的二叉树，将其变换为源二叉树的镜像。
    - 实现源码：[cc](./cc/018.cc)
- 顺时针打印矩阵
    - 题目描述：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
    - 源码实现：[cc](./cc/019.cc)
- 包含min函数的栈
    - 题目描述：定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
    - 源码实现：[cc](./cc/020.cc)
- 反转链表
    - 题目描述：输入一个链表，反转链表后，输出链表的所有元素。
    - 源码实现：[cc](./cc/021.cc)
- 栈的压入、弹出序列
    - 题目描述：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
    - 源码实现：[cc](./cc/022.cc)
- 从上往下打印二叉树
    - 题目描述：从上往下打印出二叉树的每个节点，同层节点从左至右打印。
    - 源码实现：[cc](./cc/023.cc)
- 二叉搜索树的后序遍历序列
    - 题目描述：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
    - 源码实现：[cc](./cc/024.cc)
- 二叉树中和为某一值的路径
    - 题目描述：输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
    - 实现源码：[cc](./cc/025.cc)
- 复杂链表的复制
    - 题目描述：输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
    - 实现源码：[cc](./cc/026.cc)
- 二叉搜索树与双向链表
    - 题目描述：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
    - 实现源码：[cc](./cc/027.cc)
- 字符串的排序
    - 题目描述：输入一个字符串，按字典序打印出该字符串中字符的所有排列。例如输入字符串abc，则打印出由字符a,b,c所能排列出来的所有字符串abc，acb，bac，bca，cab和cba。输入字符串长度不超过9(可能有字符重复)，字符只包括大小写字母。
    - 实现源码：[cc](./cc/028.cc)
- 数组中出现次数超过一半的数字
    - 题目描述：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
    - 实现源码：[cc](./cc/029.cc)
- 最小的K个数
    - 题目描述：输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
    - 实现源码：[cc](./cc/030.cc)
- 最大子段和
    - 题目描述：在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。(子向量的长度至少是1)
    - 实现源码：[cc](./cc/031.cc)
- 整数中1出现的次数
    - 题目描述：求出任意非负整数区间中1出现的次数。如1~13中包含1的数字有1、10、11、12、13因此共出现6次。
    - 实现源码：[cc](./cc/032.cc)
- 把数组排成最小的数
    - 题目描述：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
    - 实现源码：[cc](./cc/033.cc)
- 丑数
    - 题目描述：把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
    - 实现源码：[cc](./cc/034.cc)
- 第一个只出现一次的字符
    - 题目描述：在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置。
    - 实现源码：[cc](./cc/035.cc)
- 字符串转换成整数
    - 题目描述：将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
    - 实现源码：[cc](./cc/036.cc)
- 数组中重复地数字
    - 题目描述：在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
    - 实现源码：[cc](./cc/037.cc)
- 表示数值的字符串
    - 题目描述：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
    - 实现源码：[cc](./cc/038.cc)
- 1+2+3+...+n
    - 题目描述：求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
    - 实现源码：[cc](./cc/039.cc)
- 删除链表中重复的节点
    - 题目描述：在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
    - 实现源码：[cc](./cc/040.cc)
- 链表中环的入口节点
    - 题目描述：给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
    - 实现源码：[cc](./cc/041.cc)
- 翻转单词顺序
    - 题目描述：公司最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
    - 实现源码：[cc](./cc/042.cc)
- 构建乘积数组
    - 题目描述：给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
    - 实现源码：[cc](./cc/043.cc)
- 正则表达式匹配
    - 题目描述：请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配。
    - 实现源码：[cc](./cc/044.cc)
- 字符流中第一个不重复的字符
    - 题目描述：请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。如果当前字符流没有存在出现一次的字符，返回#字符。
    - 实现源码：[cc](./cc/045.cc)
- 不用加减乘除做加法
    - 题目描述：写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
    - 实现源码：[cc](./cc/046.cc)
- 滑动窗口的最大值
    - 题目描述：给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
    - 实现源码：[cc](./cc/047.cc)
- 扑克牌顺子
    - 题目描述：LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。
    - 实现源码：[cc](./cc/048.cc)
- 和为S的两个数字
    - 题目描述：输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
    - 实现源码：[cc](./cc/049.cc)
- 和为S的连续正数序列
    - 题目描述：小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
    - 实现源码：[cc](./cc/050.cc)
- 左旋转字符串
    - 题目描述：汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
    - 实现源码：[cc](./cc/051.cc)
- 圆圈中最后剩下的数
    - 题目描述：有个游戏是这样的:首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,可以不用表演,并且拿到名贵的“名侦探柯南”典藏版礼物(名额有限哦!!^_^)。请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
    - 实现源码：[cc](./cc/052.cc)
- 数据流中的中位数
    - 题目描述：如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
    - 实现源码：[cc](./cc/053.cc)
- 将二叉树打印成多行
    - 题目描述：从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
    - 实现源码：[cc](./cc/054.cc)
- 将二叉树按“之”字形顺序打印
    - 题目描述：请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
    - 实现源码：[cc](./cc/055.cc)
- 二叉树的下一个节点
    - 题目描述：给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
    - 实现源码：[cc](./cc/056.cc)
- 对称二叉树
    - 题目描述：请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
    - 实现源码：[cc](./cc/057.cc)
- 数字在排序数组中的位置
    - 题目描述：统计一个数字在排序数组中出现的次数。
    - 实现源码：[cc](./cc/058.cc)
- 序列化二叉树
    - 题目描述：请实现两个函数，分别用来序列化和反序列化二叉树。
    - 实现源码：[cc](./cc/059.cc)
- 二叉搜索树的第k个节点
    - 题目描述：给定一棵二叉搜索树，请找出其中的第k小的结点。例如，（5，3，7，2，4，6，8）中，按结点数值大小顺序第三小结点的值为4。
    - 实现源码：[cc](./cc/060.cc)
- 矩阵中的路径
    - 题目描述：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
    - 实现源码：[cc](./cc/061.cc)
- 机器人的运动范围
    - 题目描述：地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
    - 实现源码：[cc](./cc/062.cc)
- 两个链表的第一个公共节点
    - 题目描述：输入两个链表，找出它们的第一个公共结点。
    - 实现源码：[cc](./cc/063.cc)
- 二叉树的深度
    - 题目描述：输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
    - 实现源码：[cc](./cc/064.cc)
- 平衡二叉树的判断
    - 题目描述：输入一棵二叉树，判断该二叉树是否是平衡二叉树。
    - 实现源码：[cc](./cc/065.cc)
- 数组中只出现了一次的数字
    - 题目描述：一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请写程序找出这两个只出现一次的数字。
    - 实现源码：[cc](./cc/066.cc)
- 数组中的逆序对
    - 题目描述：在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007。
    - 实现源码：[cc](./cc/067.cc)
- 排序
    - 题目描述：经典排序算法（归并排序、冒泡排序、选择排序、堆排序、插入排序、快速排序）。
    - 实现源码：[cc](./cc/068.cc)
- minimum depth of binary tree
    - 题目描述：Given a binary tree, find its minimum depth. The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
    - 实现源码：[cc](./cc/069.cc)
- evaluate reverse polish notation
    - 题目描述：Evaluate the value of an arithmetic expression in Reverse Polish Notation. Valid operators are+,-,\*,/. Each operand may be an integer or another expression. ["2", "1", "+", "3", "\*"] -> ((2 + 1) * 3) -> 9; ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6.
    - 实现源码：[cc](./cc/070.cc)
- word break
    - 题目描述：Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words. For example, given s ="leetcode", dict =["leet", "code"]. Return true because "leetcode" can be segmented as "leet code".
    - 实现源码：[cc](./cc/071.cc)
- sum root to leaf numbers
    - 题目描述：Given a binary tree containing digits from0-9only, each root-to-leaf path could represent a number. An example is the root-to-leaf path 1->2->3 which represents the number123. Find the total sum of all root-to-leaf numbers.
    - 实现源码：[cc](./cc/072.cc)
- path sum
    - 题目描述：Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
    - 实现源码：[cc](./cc/073.cc)
- rotate image
    - 题目描述：You are given an n x n 2D matrix representing an image. Rotate the image by 90 degrees (clockwise).
    - 实现源码：[cc](./cc/074.cc)
- search in rotated sorted array
    - 题目描述：Suppose a sorted array is rotated at some pivot unknown to you beforehand. (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2). You are given a target value to search. If found in the array return its index, otherwise return -1. You may assume no duplicate exists in the array.
    - 实现源码：[cc](./cc/075.cc)
- remove duplicates from sorted array
    - 题目描述：Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length. Do not allocate extra space for another array, you must do this in place with constant memory. For example, Given input array A =[1,1,2], Your function should return length = 2, and A is now [1,2].
    - 实现源码：[cc](./cc/076.cc)
- remove duplicates from sorted array ii
    - 题目描述：Follow up for "Remove Duplicates": What if duplicates are allowed at most twice? For example, Given sorted array A =[1,1,1,2,2,3], Your function should return length = 5, and A is now [1,1,2,2,3].
    - 实现源码：[cc](./cc/077.cc)
- remove nth node from end of list
    - 题目描述：Given a linked list, remove the nth node from the end of list and return its head. For example,    Given linked list: 1->2->3->4->5, and n = 2. After removing the second node from the end, the linked list becomes 1->2->3->5. Note: Given n will always be valid. Try to do this in one pass.
    - 实现源码：[cc](./cc/078.cc)
- remove elements
    - 题目描述：Given an array and a value, remove all instances of that value in place and return the new length. The order of elements can be changed. It doesn't matter what you leave beyond the new length.
    - 实现源码：[cc](./cc/079.cc)
- 循环小数
    - 题目描述：给出被除数和除数，求出循环小数的开始位置（小数点后面的位数）和循环长度。无循环则开始位置为结束位置，长度为0。
    - 实现源码：[cc](./cc/080.cc)
- linked list cycle
    - 题目描述：Given a linked list, determine if it has a cycle in it. Follow up: Can you solve it without using extra space?
    - 实现源码：[cc](./cc/081.cc)
- linked list cycle ii
    - 题目描述：Given a linked list, return the node where the cycle begins. If there is no cycle, return null. Follow up: Can you solve it without using extra space?
    - 实现源码：[cc](./cc/082.cc)
- word ladder
    - 题目描述：Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that: Only one letter can be changed at a time, Each intermediate word must exist in the dictionary. For example, Given: start ="hit", end ="cog", dict =["hot","dot","dog","lot","log"], As one shortest transformation is"hit" -> "hot" -> "dot" -> "dog" -> "cog", return its length 5. Note: Return 0 if there is no such transformation sequence.
    - 实现源码：[cc](./cc/083.cc)
- 翻转数组的前n项和
    - 题目描述：给定整数n和m, 满足n能被2m整除。对于一串连续递增整数数列1, 2, 3, 4…, 每隔m个符号翻转一次, 最初符号为‘-’。例如n = 8, m = 2, 数列就是: -1, -2, +3, +4, -5, -6, +7, +8. 而n = 4, m = 1, 数列就是: -1, +2, -3, + 4. 试求出该数组的前n项和。
    - 实现源码：[cc](./cc/084.cc)
- 歌曲组合
    - 题目描述：给定x首长度为a的歌，y首长度为b的歌，将其组合成总长为k的歌单。请设计算法给出所有组合方式。
    - 实现源码：[cc](./cc/085.cc)
- 不被淹没的陆地面积
    - 题目描述：给定全球海平面上升x的情况下，计算不被淹没的陆地面积。如果存在盆地（群山环绕，中间低）的情况，若群山均不被淹没，则盆地不被淹没。现在为了简化问题，每个单位面积为一整数，且水总时从外围开始涨起来，且水只能上下左右流动。输入描述：第一行输入三个整数，1<=height<=100表示地图的高，1<=width<=100表示地图的宽，0<=waterlevel<=9999表示水位，接下来输入height行，每行width个正整数，每个整数表示单位面积的海拔。输出描述：输出一个数字，表示没被淹没的单位陆地数。
    - 实现源码：[cc](./cc/086.cc)
- gas station
    - 题目描述：There are N gas stations along a circular route, where the amount of gas at station i is gas[i]. You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations. Return the starting gas station's index if you can travel around the circuit once, otherwise return -1. Note: The solution is guaranteed to be unique.
    - 实现源码：[cc](./cc/087.cc)
- single number
    - 题目描述：Given an array of integers, every element appears twice except for one. Find that single one. Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
    - 实现源码：[cc](./cc/088.cc)
- single number ii
    - 题目描述：Given an array of integers, every element appears three times except for one. Find that single one. Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
    - 实现源码：[cc](./cc/089.cc)
- remove duplicates from sorted linked list
    - 题目描述：Given a sorted linked list, delete all duplicates such that each element appear only once. For example, Given1->1->2, return1->2. Given1->1->2->3->3, return1->2->3.
    - 实现源码：[cc](./cc/090.cc)
- remove duplicates from sorted linked list ii
    - 题目描述：Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. For example, Given1->2->3->3->4->4->5, return1->2->5. Given1->1->1->2->3, return2->3.
    - 实现源码：[cc](./cc/091.cc)
- sort linked list
    - 题目描述：Sort a linked list in O(n log n) time using constant space complexity.
    - 实现源码：[cc](./cc/092.cc)
- inertion sort linked list
    - 题目描述：Sort a linked list using insertion sort.
    - 实现源码：[cc](./cc/093.cc)
- plus one
    - 题目描述：Given a number represented as an array of digits, plus one to the number. （给定一个数组，里面存着0-9的数字，组合起来是一个整数，先要求在这个整数上加一，结果仍然是一个存在各位数字的数组。）
    - 实现源码：[cc](./cc/094.cc)
- valid number
    - 题目描述：Validate if a given string is numeric.
    - 实现源码：[cc](./cc/095.cc)
- merge two sorted linked list
    - 题目描述：Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
    - 实现源码：[cc](./cc/096.cc)
