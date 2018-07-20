#include <cassert>
#include <iostream>
#include <memory>

#include "trie.hpp"

using std::unique_ptr;

// TrieNode implementation

void TrieNode::add(const char* cstr)
{
    count++;
    if (*(cstr + 1) == '\0') {
        terminal = true;
    }
    else {
        const int idx = char_idx(*(cstr + 1));

        if (children[idx] == nullptr)
            children[idx] = unique_ptr<TrieNode>(new TrieNode);

        children[idx]->add(cstr + 1);
    }
}

bool TrieNode::contains_word(const char* cstr) const
{
    if (count == 0)
        return false;

    if (*(cstr + 1) == '\0') {
        return terminal;
    }
    else {
        const unique_ptr<TrieNode>& next_char = children[char_idx(*(cstr + 1))];

        if (next_char == nullptr)
            return false;

        return next_char->contains_word(cstr + 1);
    }
}

int TrieNode::count_prefix(const char* cstr) const
{
    if (count == 0)
        return 0;

    if (*(cstr + 1) == '\0') {
        return count;
    }
    else {
        const unique_ptr<TrieNode>& next_char = children[char_idx(*(cstr + 1))];

        if (next_char == nullptr)
            return 0;

        return next_char->count_prefix(cstr + 1);
    }
}

int main()
{
    Trie t;

    t.add("h");
    t.add("hi");
    t.add("helo");
    t.add("hello");

    t.add("a");
    t.add("trie");
    t.add("is");
    t.add("eggoo");
    t.add("cool");

    assert(t.contains_word("hello"));
    assert(t.contains_word("helo"));
    assert(t.contains_word("a"));
    assert(t.contains_word("cool"));

    assert(!t.contains_word("hellow"));
    assert(!t.contains_word("hel"));
    assert(!t.contains_word("hell"));
    assert(!t.contains_word("b"));
    assert(!t.contains_word("xylophone"));

    assert(t.count_prefix("h") == 4);
    assert(t.count_prefix("is") == 1);
    assert(t.count_prefix("hx") == 0);
    assert(t.count_prefix("x") == 0);
    assert(t.count_prefix("hel") == 2);
    assert(t.count_prefix("helllow") == 0);
    assert(t.count_prefix("trie") == 1);

    std::cout << "OK" << std::endl;

    return 0;
}
