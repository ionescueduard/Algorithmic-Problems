class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def countUnival(tree, rez):
    if tree.left is None and tree.right is None:
        rez[0] += 1
        return tree.val

    left = None
    right = None
    if tree.left:
        left = countUnival(tree.left, rez)
    if tree.right:
        right = countUnival(tree.right, rez)

    if left == -1 or right == -1:
        return -1

    if left is not None and right is not None:
        if left == right and left == tree.val:
            rez[0] += 1
            return left
        else:
            return -1
    elif left is not None and left == tree.val:
        rez[0] += 1
        return left
    elif right is not None and right == tree.val:
        rez[0] += 1
        return right
    return -1



if __name__ == '__main__':
    tree = Node(0, Node(1), Node(0, Node(1, Node(1), Node(1)), Node(0)))

    rez = [0]
    countUnival(tree, rez)
    print(rez)
