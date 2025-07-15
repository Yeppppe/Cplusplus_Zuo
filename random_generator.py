import random as std_random

# 1-17对应的17个名字
names = [
   "王彦臻", "刁伟璐", "蔡晨昊", "张凯杰", "张浩翔",
   "宋稼骏",  "沈鑫海", "商光涛", "吴梦洋", 
   "何文俊", "龙昌",   "张浩东", "施浩杰", "田建伟", 
   "胡宇轩", "顾羽麾"
   ]

if __name__ == "__main__":
    # 生成1~17范围内不重复的8个随机数字
    random_indices = std_random.sample(range(17), 8)
    
    sorted_indices = sorted(random_indices)
    for index in sorted_indices:
        print(names[index])
