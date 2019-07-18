from collections import deque


class Node:
    def __init__(self, val, left=None, right=None):
        self.value = val
        self.left = left
        self.right = right


def pack(root):
    string = ''
    if root:
        string += '({},'.format(root.value)
        if root.left:
            string += pack(root.left)
            string += ','
        else:
            string += 'null,'

        if root.right:
            string += pack(root.right)
            string += ')'
        else:
            string += 'null)'
    return string


def getRootLeftRight(string):
    n = len(string)
    elms = [string[1]]
    istart = 3
    while len(elms) < 3:
        if string[istart] == 'n':
            elms.append('null')
            istart += 5
            continue
        if string[istart] != '(':
            elms.append(string[istart])
        else:
            brackets = 1
            i = istart + 1
            while brackets != 0:
                if string[i] == '(':
                    brackets += 1
                if string[i] == ')':
                    brackets -= 1
                i += 1
            elms.append(string[istart: i])
            istart = i + 1
    return elms


def unpack(string):
    elements = getRootLeftRight(string)
    root = Node(int(elements[0]))

    if len(elements[1]) == 1:
        root.left = Node(int(elements[1]))
    else:
        if elements[1] != 'null':
            root.left = unpack(elements[1])

    if len(elements[2]) == 1:
        root.right = Node(int(elements[2]))
    else:
        if elements[2] != 'null':
            root.right = unpack(elements[2])

    return root


def printTree(root):
    buf = deque()
    output = []
    if not root:
        print('$')
    else:
        buf.append(root)
        count, nextCount = 1, 0
        while count:
            node = buf.popleft()
            if node:
                output.append(node.value)
                count -= 1
                for n in (node.left, node.right):
                    if n:
                        buf.append(n)
                        nextCount += 1
                    else:
                        buf.append(None)
            else:
                output.append('$')
            if not count:
                print(output)
                output = []
                count, nextCount = nextCount, 0
        # print the remaining all empty leaf node part
        output.extend(['$'] * len(buf))
        print(output)


if __name__ == '__main__':
    root = Node(3)
    root.left = Node(1)
    root.left.left = Node(2)
    root.left.right = Node(5)
    root.left.right.left = Node(7)
    root.right = Node(6)
    root.right.right = Node(9)
    root.right.right.left = Node(8)

    printTree(root)

    packed = pack(root)
    unpackedTree = unpack(packed)

    printTree(unpackedTree)
