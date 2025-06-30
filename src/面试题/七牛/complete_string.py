# 题目：
# 给定一个字符串s，字符串s只包含一下三个字符 ( ° ) ,请你判断当前字符s是否为一个合法字符串，合法字符串规则如下：
# 1. 左括号 ‘（’ 必须有对应的右括号 ')'
# 2. 右括号 ')'必须有对应的左括号 ‘（’ 
# 3. 左括号必须在对应的右括号前面
# 4. °可以视为单个左括号，也可以视为单个右括号，或者视为一个空字符串
# 5. 空字符也可以视为合法字符串


#* 这个程序通过维护两个变量 min_left 和 max_left 来跟踪可能的左括号数量范围：

#* min_left：表示当前可能的最小左括号数量，遇到 ° 时可能减少（当 ° 被视为右括号时）。
#* max_left：表示当前可能的最大左括号数量，遇到 ° 时可能增加（当 ° 被视为左括号时）。

#* 遍历字符串过程中：

#* 遇到 ( 时，两个计数器都增加。
#* 遇到 ) 时，两个计数器都减少，但确保 min_left 不小于 0。
#* 遇到 ° 时，min_left 可能减少，max_left 可能增加。

#* 如果遍历过程中 max_left 变为负数，说明右括号过多，直接返回 False。最后检查 min_left 是否为 0，确保所有括号都能正确匹配。



def is_valid(s: str) -> bool:
    if not s:
        return True
    # 维护两个计数器，分别记录最小可能的左括号数量和最大可能的左括号数量
    min_left = max_left = 0
    for c in s:
        if c == '(':
            min_left += 1
            max_left += 1
        elif c == ')':
            min_left = max(min_left - 1, 0)
            max_left -= 1
            if max_left < 0:
                return False
        else:  # c是°
            min_left = max(min_left - 1, 0)
            max_left += 1
    return min_left == 0

# 读取输入并输出结果
s = input().strip()
print("YES" if is_valid(s) else "NO")