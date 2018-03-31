# WordCountPro

### 任务分工
* 刘强：main函数判断输入
* 赵传储：处理输入，统计文件词频，定义其它模块接口
* 赵自煜：排序后将词频输出到文件
* 孙嘉璇：图形界面选取文件控制输入

### 项目框架
* 变量：
  * static unordered_set&lt;char&gt; splitSymbolsSet：  
  记录不计入统计的分隔符
  * static unordered_map&lt;string, int&gt; wordMap;  
  记录词频统计的结果
* 函数：
  * int main(int argc, char \*argv[])：  
  main函数作为程序入口，判断输入
  * void ReadAndCount(string fileName)：  
  根据文件名读取文件内容并统计词频
  * void Output()：  
  将词频结果排序后写入到输出文件中
  * string OpenAFile()：  
  使用图形界面选取文件并返回文件名
