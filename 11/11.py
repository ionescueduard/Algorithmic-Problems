class Node:
    def __init__(self, letter, sufixes):
        self.letter = letter
        self.sufixes = sufixes  # list of suffixes so far
        self.children = {}  # letter : Node


def getAutocompleteList(node, prefix, i):
    if i == len(prefix):
        return [prefix + suffix for suffix in node.sufixes]
    if (not node.children and i < len(prefix)) or prefix[i] not in node.children:
        return []
    return getAutocompleteList(node.children[prefix[i]], prefix, i+1)

def constructTrie(root):
    for word in root.sufixes:
        if not word:
            continue
        letter = word[0]
        if letter in root.children:
            root.children[letter].sufixes.append(word[1:])
        else:
            root.children[letter] = Node(letter, [word[1:]])
    for _, k in root.children.items():
        constructTrie(k)


if __name__ == '__main__':
    words = ['dog', 'deer', 'deal', 'asdf', 'asdg', 'asdrfw', 'aswer']

    root = Node(None, words)

    constructTrie(root)

    print(getAutocompleteList(root, 'asw', 0))