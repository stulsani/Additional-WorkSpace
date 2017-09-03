class Solution(object):
    def removeZeroes(self,version):
        index = len(version) - 1
        for val in reversed(version):
            if val == 0:
                del version[index]
                index -= 1
            else:
                return version
        return version

    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        s1=version1.split('.')
        s1=list(map(int, s1))
        s2 = version2.split('.')
        s2 = list(map(int, s2))
        s1 = self.removeZeroes(s1)
        s2 = self.removeZeroes(s2)
        if s1>s2:
            return 1
        elif s1<s2:
            return -1
        else:
            return 0

version = Solution()
answer = version.compareVersion("1.0.0.1","1.0.1")
if answer == 1:
    print("Version1 > Version2")
elif answer == -1:
    print("Version2 > Version1")
elif answer == 0:
    print("Version1 == Version2")
else:
    print("Invalid Version number")
