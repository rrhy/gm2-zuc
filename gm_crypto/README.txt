1、Makefile中需要在gcc后增加-std=c99解决for循环中int i的问题
2、尖括号寻找h头文件造成的问题，需要改成引号，批量修改方式如下
#尖括号替换为"
sed -i '/include [<"]gmssl/s/>/"/g' *.*
sed -i '/include [<"]gmssl/s/</"/g' *.*
3、在gmssl文件夹中的头文件引用路径为"gmssl/*.h"需要删除gmssl内容，批量修改方式如下
#删除gmssl/
sed -i '/include [<"]gmssl/s/gmssl\///g' *.*
4、在文件夹sdf和skf中，头文件包含时由于包含路径gmssl不在当前路径下，makefile中编译时需要增加包含路径
COM_INC = -I.


参考https://blog.csdn.net/qq_42767455/article/details/104180726
# 对每行匹配到的第一个字符串进行替换
sed -i 's/原字符串/新字符串/' ab.txt 
# 对全局匹配上的所有字符串进行替换
sed -i 's/原字符串/新字符串/g' ab.txt 
# 删除所有匹配到字符串的行
sed -i '/匹配字符串/d'  ab.txt  
# 特定字符串的行后插入新行
sed -i '/特定字符串/a 新行字符串' ab.txt 
# 特定字符串的行前插入新行
sed -i '/特定字符串/i 新行字符串' ab.txt
# 把匹配行中的某个字符串替换为目标字符串
sed -i '/匹配字符串/s/源字符串/目标字符串/g' ab.txt
# 在文件ab.txt中的末行之后，添加bye
sed -i '$a bye' ab.txt   
# 对于文件第3行，把匹配上的所有字符串进行替换
sed -i '3s/原字符串/新字符串/g' ab.txt
