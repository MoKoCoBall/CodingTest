# [Gold III] Holy cow, Vim! (Easy) - 19676 

[문제 링크](https://www.acmicpc.net/problem/19676) 

### 성능 요약

메모리: 4528 KB, 시간: 0 ms

### 분류

애드 혹, 해 구성하기

### 제출 일자

2024년 11월 18일 01:32:17

### 문제 설명

<p>Little Johnny is attending a summer programming camp. The very first assignment was to write a program that reads a number <em>x</em> and prints the same number <em>x</em>. Johnny’s program was already working, but then an accident happened. While using the Vim editor, Johnny pressed something without paying attention and his program got turned upside down. That is, he somehow reversed the order of lines in his program.</p>

<p>To Johnny’s amazement, the program still worked, but now it did something different: it read <em>x</em> and printed <em>x</em><sup>2</sup>.</p>

<p>Johnny tried to remember what he pressed to put the lines back in the correct order, but he made another mistake and Vim sorted the lines of his program. Johnny tried the new program and was completely lost for words: the program now read <em>x</em> and printed −<em>x</em>.</p>

<p>“Holy cow, Vim is magic! I’ll use it until the end of my life!” exclaimed Johnny.</p>

<p>“That’s just because nobody knows how to exit it,” another student yelled back.</p>

<p>Can you write a program that behaves the same way as Johnny’s program?</p>

<p>In this problem, you’ll use a simple stack-based programming language. The memory is a stack of signed integers. Various commands push values onto the stack or pop values from the top of the stack. The stack is initially empty and may be left non-empty when the program ends.</p>

<p>A program consists of several <em>lines</em>, and each line consists of one or more <em>commands</em> separated by semicolons. A command can be one of the following:</p>

<ul>
	<li>
	<p>“<code>input</code>”: Reads the number <em>x</em> from the input and pushes it onto the stack. You may only execute “<code>input</code>” once per an execution of your program.</p>
	</li>
	<li>
	<p>“<code>jump</code> <em>j</em>”: Immediately jumps to the beginning of line <em>j</em>. Lines are numbered counting from 0 to <em>n</em> − 1 where <em>n</em> is the number of lines. Jumping to <em>j</em> = <em>n</em> exits the program. Jumping to <em>j</em> < 0 or <em>j</em> > <em>n</em> is an error.</p>
	</li>
	<li>
	<p>“<code>pop</code>”: Removes the top element from the stack. Results in an error if the stack is empty.</p>
	</li>
	<li>
	<p>“<code>print</code>”: Removes the top element from the stack and prints its value. Results in an error if the stack is empty. You may only execute “<code>print</code>” once per an execution of your program.</p>
	</li>
	<li>
	<p>“<code>push</code> <em>p</em>”: Pushes the constant <em>p</em> onto the top of the stack.</p>
	</li>
	<li>
	<p>“<code>dup</code>”: Duplicates the top element of the stack. If the current top element is <em>t</em>, “<code>dup</code>” does the same thing as “<code>push</code> <em>t</em>”. Results in an error if the stack is empty.</p>
	</li>
	<li>
	<p>“<code>+</code>”, “<code>-</code>”, “<code>*</code>” and “<code>/</code>”: Pops the top element <em>a</em> from the stack, then pops the next element <em>b</em> from the stack, then pushes <em>a</em> + <em>b</em>, <em>a</em> − <em>b</em>, <em>a</em> ⋅ <em>b</em>, or <em>a</em>/<em>b</em> rounded towards zero, respectively. Results in an error if the stack contains fewer than two numbers. Division by zero is also an error.</p>
	</li>
</ul>

<p>The language is very strict. You cannot use any extra whitespace or semicolons or anything like that.</p>

<p>Only integers between −2<sup>31</sup> and 2<sup>31</sup> − 1 (inclusive) are supported. Pushing an integer outside of this range to the stack is an error.</p>

### 입력 

 <p>There is no input.</p>

### 출력 

 <p>Your task is to write a program that reads an integer <em>x</em> and outputs <em>x</em>. However, if the order of the lines of the program is reversed (i.e., the last line becomes the first line, etc.), the new program should output <em>x</em><sup>2</sup>. And if the lines of the program are sorted lexicographically, it should output −<em>x</em>.</p>

<p>You may assume that |<em>x</em>|≤30 000.</p>

<p>The program can have at most 1000 lines. For any valid <em>x</em> your program must terminate after the execution of at most 10 000 commands.</p>

<p>Each line may contain <strong>up to 1000 commands</strong>.</p>

