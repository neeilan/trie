#include <memory>

#include "trie.hpp"

using std::unique_ptr;

// TrieNode implementation

void TrieNode::add(const char* cstr)
{
    count++;

    if (*(cstr + 1) == NULL_TERM) {
        terminal = true;
    }
    else {
        const int idx = char_idx(*(cstr + 1));

        if (children[idx] == nullptr)
            children[idx] = std::make_unique<TrieNode>();

        children[idx]->add(cstr + 1);
    }
}

bool TrieNode::contains_word(const char* cstr) const
{
    if (count == 0)
        return false;

    if (*(cstr + 1) == NULL_TERM) {
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

    if (*(cstr + 1) == NULL_TERM) {
        return count;
    }
    else {
        const unique_ptr<TrieNode>& next_char = children[char_idx(*(cstr + 1))];

        if (next_char == nullptr)
            return 0;

        return next_char->count_prefix(cstr + 1);
    }
}

