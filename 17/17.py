def lengthLongestPath(input):
        level = {-1:0}
        maxLength = 0
        for line in input.split('\n'):
            depth = line.count('\t')
            level[depth] = level[depth - 1] + len(line)
            
            if '.' in line:
                maxLength = max(maxLength, level[depth])
        
        return maxLength
        
if __name__ == '__main__':
    print(lengthLongestPath('dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext'))