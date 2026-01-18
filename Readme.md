<h1>Mini_utils</h1>
<p>
A small collection of Unix-like command-line utilities written in C.
The goal of this project is to practice systems programming, clean C architecture,
and Unix-style CLI design.</p>

## Usage

### Requirements
- GCC or Clang
- make

### Clone the repository:

```
https://github.com/Misterparadise/mini-utils.git
```


### Build on Linux / macOS
```bash
make
```

### Run cat

```
bin/cat tests/file.txt
```

### Run wc

```
bin/wc tests/file.txt
```

### Run grep

```
bin/grep [options] <pattern> <filename>
```
#### Grep options


<li>-n — print line numbers with matching lines</li>

``
If no options are provided, grep prints matching lines only.
``

<h2>Currently implemented</h2>
<p> cat — concatenate files and print on standard output</p>
<p> wc  — calculates a file's word, line, character, or byte count.</p>
<p> grep —  searching plain-text data (files or input streams) for lines that match a specified pattern</p>

<h2>Features</h2>
<ul>
<li> Read and print one or multiple files</li>
<li> Works with relative and absolute paths</li>
<li> Unix-style CLI behavior</li>
<li> Outputs the line, word, and byte counts</li>
<li> Match the specified pattern, print lines with the line numbers</li>
</ul>


<h2>Examples</h2>

#### wc util
![alt text](mini_utils/images/image-3.png)

![alt text](mini_utils/images/image-2.png)

#### cat util


![alt text](mini_utils/images/image.png)


#### grep util

![alt text](/mini_utils/images/image4.png)
