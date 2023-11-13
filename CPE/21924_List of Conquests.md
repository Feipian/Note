# (YKL16.UVA272) TeX Quotes 


# (YKL42.UVA490) Rotating Sentences 
Description

In ``Rotating Sentences,'' you are asked to rotate a series of input sentences 90 degrees clockwise. So instead of displaying the input sentences from left to right and top to bottom, your program will display them from top to bottom and right to left.

Input

As input to your program, you will be given a maximum of 100 sentences, each not exceeding 100 characters long. Legal characters include: newline, space, any punctuation characters, digits, and lower case or upper case English letters. (NOTE: Tabs are not legal characters.)

Output

The output of the program should have the last sentence printed out vertically in the leftmost column; the first sentence of the input would subsequently end up at the rightmost column.

## Solution
``` python

sentences = []
# initialize num of sentence
num_sentence = 0
# record the max line's length
max_len = 0

def sentenceTransform(sentences):
	for i in range(max_len):
		# reversed the list from bottom to top read
		for j in range(len(sentences)-1, -1, -1):
			# normal output
			if i < len(sentences[j]):
				print(sentences[j][i], end="")
			# if out some sentence's bound
			else:
				print(" ", end="")
		# Change row	
		print("")	

			
while True:
	try:
		# input the sentence
		sentence = input("")
		# combine all sentence in one list
		sentences.append(sentence)
		num_sentence +=1
		# compare max_len and sentence length, the bigger be max_len
		max_len = max(max_len, len(sentence))
		
	except:
		break

sentenceTransform(sentences)
		
```

## Problem solving-idea

1. An empty list `sentences` is initialized to store the input sentences.
2. The variable `num_sentence` is initialized to 0 to keep track of the number of sentences.
3. The variable `max_len` is initialized to 0 to record the maximum length among all input sentences.

4. The function `sentenceTransform` takes the `sentences` list as input and transforms the sentences to display them in a specific format.

5. It uses a nested loop to iterate over the characters of the sentences. The outer loop iterates `max_len` times, representing the maximum length of any sentence.

6. The inner loop iterates over the sentences in reverse order, from the last sentence to the first.

7. Inside the inner loop, it checks if the current character position `i` is within the length of the current sentence `sentences[j]`. If it is, it prints the character at that position. If it is beyond the length of the sentence, it prints a space character.

8. After printing the characters for each position `i`, it moves to the next line by printing an empty string.

9. The main part of the code uses a `while True` loop to continuously read input sentences until an exception occurs (indicating the end of input).

10. Inside the loop, it reads an input sentence using the `input()` function and appends it to the `sentences` list.

11. The `num_sentence` is incremented to keep track of the number of sentences.

12. The `max_len` is updated to store the maximum length among all input sentences.

13. If an exception occurs (indicating the end of input), the loop is exited with the `break` statement.

14. Finally, the `sentenceTransform` function is called with the `sentences` list to transform and display the sentences in the desired format.
    
**Notice!!** if you using 瘋狂程設 the result well call wrong,but actualy it is right(mycode),you can try in zerojudge (website) to sent this code,it will be runable

# (YKL15.UVA10252) Common 
> Description
Given two strings of lowercase letters, a and b, print the longest string x of lowercase letters such that there is a permutation of x that is a subsequence of a and there is a permutation of x that is a subsequence of b.
Input
Input file contains several lines of input. Consecutive two lines make a set of input. That means in the input file line 1 and 2 is a set of input, line 3 and 4 is a set of input and so on. The first line of a pair contains a and the second contains b. Each string is on a separate line and consists of at most 1000 lowercase letters.
Output
For each set of input, output a line containing x. If several x satisfy the criteria above, choose the first one in alphabetical order.

```python
def Compare_fuc(a, b):
	#sort a and b
	a = sorted(a.replace(" ",""))
	b = sorted(b.replace(" ",""))
	
	# store the same alphabet
	string_compare = ""
	i=0 #place record variable(for a)
	j=0 #record index for b
	while i < len(a) and j < len(b):
		
		if a[i] == b[j]:
			string_compare += a[i]
			i+=1
			j+=1
		elif a[i] < b[j]:
			i+=1
		# b smaller than a
		else:
			#move b place
			j+=1
	return string_compare

while True:
	try:
		a = input()
		b = input()
		
		# Compare 2 line
		result = Compare_fuc(a, b)
		print(result)
	
	except EOFError:
		break

```

1. The function `Compare_fuc` takes two input strings, `a` and `b`, as parameters. It sorts both strings after removing any spaces using the `replace()` and `sorted()` functions.

2. It initializes an empty string `string_compare` to store the common characters.

3. The variables `i` and `j` are initialized to 0. These variables will be used to traverse the strings `a` and `b`, respectively.

4. The `while` loop continues until either `i` reaches the end of string `a` or `j` reaches the end of string `b`. It iterates through the characters of both strings, comparing them.

5. Inside the loop, it checks if the character at index `i` in string `a` is equal to the character at index `j` in string `b`. If they are equal, the character is appended to `string_compare`, and both `i` and `j` are incremented by 1.

6. If the character in string `a` is less than the character in string `b`, `i` is incremented by 1, moving to the next character in string `a`.

7. If the character in string `a` is greater than the character in string `b`, `j` is incremented by 1, moving to the next character in string `b`.

8. After the loop finishes, the function returns the `string_compare`, which contains the common characters between `a` and `b`.

9. The main part of the code uses a `while True` loop to continuously read input lines until an `EOFError` exception is raised.

10. Inside the loop, it reads two input lines using the `input()` function, representing `a` and `b`.

11. The `Compare_fuc` function is called with the input strings `a` and `b`, and the result is stored in the `result` variable.

12. The common characters between `a` and `b` are printed by using the `print()` function.

13. If an `EOFError` exception is raised (indicating the end of input), the loop is exited with the `break` statement.

### Notice!!
請注意輸入有可能是Space key 所以在sorted時必須將" " 換成"" 消除所有空白的地方

# (YKL27.UVA11332) Summing Digits
>For a positive integer n, let f(n) denote the
sum of the digits of n when represented in base
10. It is easy to see that the sequence of numbers n, f(n), f(f(n)), f(f(f(n))), . . . eventually
becomes a single digit number that repeats forever. Let this single digit be denoted g(n).
For example, consider n = 1234567892.
Then:
f(n) = 1+2+3+4+5+6+7+8+9+2 = 47
f(f(n)) = 4 + 7 = 11
f(f(f(n))) = 1 + 1 = 2
Therefore, g(1234567892) = 2.
Input
Each line of input contains a single positive integer n at most 2,000,000,000. Input is terminated
by n = 0 which should not be processed.
Output
For each such integer, you are to output a single
line containing g(n).
Sample Input
2
11
47
1234567892
0
Sample Output
2
2
2
2

## Code:
```python

def calculus_fuc(num):
	# save the calculation sum
	
	while int(num) >9:
		sum = 0
		# print("into")
		# Iterate through the numbers
		# print(num)
		for nm in str(num):
			#print(nm)
			sum += int(nm)
		num = sum
	return num
		

while True:
	
	num = input()
	if int(num) ==0:
		break;
	else:
		answer = calculus_fuc(num)
	print(answer)


```

## Analysis Code:
> 
1. The `calculus_fuc` function takes a number as input and calculates `f(n)` by repeatedly summing its digits until the result becomes a single-digit number. It uses a while loop to check if the number is greater than 9 (i.e., not a single-digit number). Inside the loop, it initializes a variable `sum` to 0 and iterates through each digit in the string representation of the number. It converts each digit back to an integer and adds it to the `sum`. Finally, it updates the `num` variable with the value of `sum`. Once the number becomes a single-digit number, it returns the value of `num`.

2. The main part of the code is the while loop that runs indefinitely until the user enters 0 as the input number. Inside the loop, it reads a number from the input using `input()` and assigns it to the `num` variable. If the number is 0, it breaks out of the loop and terminates the program. Otherwise, it calls the `calculus_fuc` function with `num` as the argument and assigns the returned value to the `answer` variable. Finally, it prints the `answer`.




# (YKL14.UVA10222) Decode the Mad man 
> Once in BUET, an old professor had gone completely mad. He started talking with some peculiar
words. Nobody could realize his speech and lectures. Finally the BUET authority fall in great trouble.
There was no way left to keep that man working in university. Suddenly a student (definitely he was
a registered author at UVA ACM Chapter and hold a good rank on 24 hour-Online Judge) created
a program that was able to decode that professor’s speech. After his invention, everyone got comfort
again and that old teacher started his everyday works as before.
So, if you ever visit BUET and see a teacher talking with a microphone, which is connected to a
IBM computer equipped with a voice recognition software and students are taking their lecture from
the computer screen, don’t get thundered! Because now your job is to write the same program which
can decode that mad teacher’s speech!
Input
The input file will contain only one test case i.e. the encoded message.
The test case consists of one or more words.
Output
For the given test case, print a line containing the decoded words. However, it is not so hard task to
replace each letter or punctuation symbol by the two immediately to its left alphabet on your standard
keyboard.
Sample Input
k[r dyt I[o
Sample Output
how are yo

## Problem solving-ideas
> The given code appears to be a solution to a problem that involves decoding an encoded message using a specific character mapping. Here's a breakdown of the problem-solving approach:

1. Initialize the `alphabet_Table` variable with the character mapping used for decoding.
2. Enter an infinite loop using `while True`.
3. Prompt the user for input using `input()`.
4. Check if the `phrase` variable is not empty (i.e., user has entered some input).
5. Inside the `if` block, initialize an empty string `trans_str` to store the decoded message.
6. Convert the input string to lowercase using `phrase.lower()` to ensure case-insensitive decoding.
7. Iterate over each character `alphabet` in the input string.
8. Check if the `alphabet` character is present in the `alphabet_Table`.
   - If present, find its position in `alphabet_Table` and move two positions back to get the corresponding decoded character.
   - Append the decoded character to `trans_str`.
9. If the `alphabet` character is not in `alphabet_Table`, it might be a space or special character. Append it as it is to `trans_str`.
10. Print the decoded message `trans_str`.
11. If the `phrase` variable is empty (i.e., user has not entered any input), break out of the loop using `break`.
12. Repeat the loop until the user enters an empty line to terminate the program.


## Solution
```
# 用於對照字符轉換
alphabet_Table = "1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"


while True:
	phrase =input()
	if phrase:
		# 儲存轉換後字串
		trans_str = ""
		
		# 把字串都轉換成小寫的
		phrase = phrase.lower()
		# 遍歷一遍輸入的字串
		for alphabet in phrase:
			if alphabet in alphabet_Table:
				# 從表格當中找到位置並往前移動兩格
				index = alphabet_Table.find(alphabet)-2
				
				# 根據index找到轉換後的字符
				trans_str += alphabet_Table[index]
				#print(alphabet_Table[index])
			
			else:
				# 也許是空格
				trans_str += alphabet
				
		# 輸出轉換後字串
		print(trans_str)
				#print(index) 
			#print(alphabet)
		
	else:
		break
	
```

# What's Cryptanalysis?
## Question
```
Time Limit: 3 sec

Description

Cryptanalysis is the process of breaking someone else's cryptographic writing. This sometimes involves some kind of statistical analysis of a passage of (encrypted) text. Your task is to write a program which performs a simple analysis of a given text.

Input

The first line of input contains a single positive decimal integer n. This is the number of lines which follow in the input. The next n lines will contain zero or more characters (possibly including whitespace). This is the text which must be analyzed.

Output

Each line of output contains a single uppercase letter, followed by a single space, then followed by a positive decimal integer. The integer indicates how many times the corresponding letter appears in the input text. Upper and lower case letters in the input are to be considered the same. No other characters must be counted. The output must be sorted in descending count order; that is, the most frequent letter is on the first output line, and the last line of output indicates the least frequent letter. If two letters have the same frequency, then the letter which comes first in the alphabet must appear first in the output. If a letter does not appear in the text, then that letter must not appear in the output.
```

## 解題思路:
- Read the input value n to determine the number of lines to follow.
- Initialize an empty dictionary to store the counts for each letter.
- Iterate over the next n lines of input.
- For each line, iterate over each character.
- Convert the character to uppercase using the upper() function.
- Check if the character is a letter using the isalpha() function.
- If the character is a letter, check if it is already present in the dictionary. If it is, increment the count by 1. If it is not, add the letter to the dictionary with a count of 1.
- After processing all the lines, sort the dictionary by count in descending order and then by letter in ascending order.
- Iterate over the sorted dictionary and print each letter followed by its count.

## Answer:
```
# 輸入資料個數
n = int(input())

# 創建字典儲存字母及次數
dictionary = {}
# 遍歷每次輸入
for _ in range(n):
	text = input()
	#改成大寫
	text = text.upper()
	# 遍歷輸入的字串
	for alpha in text:
		if alpha.isalpha():
			if alpha in dictionary:
				dictionary[alpha] +=1
			# 假如字典沒有此字母就初始化為1 已經存在就+1
			else:
				dictionary[alpha] = 1
				
			
# 降序排列 使用.items() 會把 key 與 value拿出來
sorted_dic = sorted(dictionary.items(), key = lambda x: (-x[1], x[0]))
			
for alpha, count in sorted_dic:
    print(alpha, count)
			
		
	
```
`key = lambda x: (-x[1], x[0])`的意思為:先根據字典當中的數字(值)大小進行排序,之所以要寫成-x[1]的原因是因為sorted函數默認為由小排到大，所以加上一個負號後本來小的數字在前面，但加上負號後小的數字反而比較大，所以就會排在後面，從而實現的反向排序的效果(也可以使用reverse= True來實現)

假如('T' : 1 'B' : 2)
本來T會排前面, 但現在使用lambda函數,元件變成('T' : -1 'B' : -2), 明顯的 -1比-2還大，sorted默認小的會在前面所以變成B在前面達到反向排序的效果。
可能有人會問說那後面的 x[0]的作用是甚麼?其實很簡單，那就是實現了 -x[1]排序之後,有些字母的數字可能是一樣的，但是題目要求我們需要根據字母表來排序，就是如果數字一樣則順序按造ABCDE....來排序 所以x[0]的意思就是按造字母排序，經過兩次排序之後我們元件的內容已經符合題目所需。



# Question:
```
Description

In Act I, Leporello is telling Donna Elvira about his master's long list of conquests:

``This is the list of the beauties my master has loved, a list I've made out myself: take a look, read it with me. In Italy six hundred and forty, in Germany two hundred and thirty-one, a hundred in France, ninety-one in Turkey; but in Spain already a thousand and three! Among them are country girls, waiting-maids, city beauties; there are countesses, baronesses, marchionesses, princesses: women of every rank, of every size, of every age.'' (Madamina, il catalogo è questo)

As Leporello records all the ``beauties'' Don Giovanni ``loved'' in chronological order, it is very troublesome for him to present his master's conquest to others because he needs to count the number of ``beauties'' by their nationality each time. You are to help Leporello to count.

Input

The input consists of at most 2000 lines, but the first. The first line contains a number n, indicating that there will be n more lines. Each following line, with at most 75 characters, contains a country (the first word) and the name of a woman (the rest of the words in the line) Giovanni loved. You may assume that the name of all countries consist of only one word.

Output

The output consists of lines in alphabetical order. Each line starts with the name of a country, followed by the total number of women Giovanni loved in that country, separated by a space.
```


## Think:
Read the input value of n to determine the number of lines to follow.
Initialize an empty dictionary to store the counts for each country.
Iterate over the next n lines of input.
For each line, split the line into the country name and the woman's name.
Check if the country name is already present in the dictionary. If it is, increment the count by 1. If it is not, add the country to the dictionary with a count of 1.
After processing all the lines, sort the dictionary by country name in alphabetical order.
Iterate over the sorted dictionary and print the country name followed by the count.
```
# 輸入資料個數
n = int(input())
# create a dictionary store name and count
data_dic = {}

for _ in range(n):
	data = input()
	# 將資料分割成城市與名字
	country, name = data.split(' ', 1)
	#判斷資料是否在字典當中
	if country in data_dic:
		data_dic[country] +=1
	else:
		data_dic[country] = 1
		
# 排序資料，由小到大
sort_data = sorted(data_dic.items())

for country, count in sort_data:
	print(country, count)
```