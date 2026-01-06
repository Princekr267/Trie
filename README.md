# 🌳 Trie Data Structure

> A comprehensive C++ implementation of Trie (Prefix Tree) with practical problem solutions

## 📚 What's Inside

This repository contains my learnings and implementations of the Trie data structure, including solutions to common problems asked in interviews and competitive programming.

## ✨ Features

### Core Operations
- **Insert** - Add words to the trie
- **Search** - Find complete words
- **StartsWith** - Check if any word starts with given prefix
- **Count Nodes** - Total nodes in the trie

### Problem Solutions
| Problem | File | Description |
|---------|------|-------------|
| **Word Break** | `build.cpp` | Check if a string can be segmented into dictionary words |
| **Prefix Problem** | `prefixProb.cpp` | Find shortest unique prefix for each word |
| **Unique Substrings** | `startsWith.cpp` | Count all unique substrings of a string |
| **Longest Word** | `startsWith.cpp` | Find longest word where all prefixes exist |

## 🚀 Quick Start

```cpp
// Compile and run any file
g++ startsWith.cpp -o trie
./trie

// Basic usage example
Trie trie;
trie.insert("hello");
trie.search("hello");      // true
trie.startsWith("hel");    // true
```

## ⚡ Complexity Analysis

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Insert | O(L) | O(L × N) |
| Search | O(L) | O(1) |
| StartsWith | O(L) | O(1) |
| Word Break | O(N × L²) | O(N × L) |

*L = length of word, N = number of words*

## 🛠️ Implementation Details

**Node Structure:**
- Uses `unordered_map<char, Node*>` for children
- Boolean flag for end of word marker
- Frequency counter for prefix problem

**Key Techniques:**
- Recursive backtracking for word break
- DFS traversal for longest word
- Suffix insertion for unique substrings

## 📖 Learning Resources

**When to Use Trie:**
- Autocomplete systems
- Spell checkers
- IP routing tables
- Dictionary implementations
- Prefix matching problems

## 🤝 Contributing

Feel free to fork this repository and add more problems or optimizations!

## 👨‍💻 Author

**Princekr267**

---

⭐ Star this repo if you found it helpful!
