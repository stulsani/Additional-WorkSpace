from packaging.version import Version

class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        try:
            if Version(version1) > Version(version2):
                return 1
            elif Version(version1) < Version(version2):
                return -1
        except ValueError:
            return -2
        return 0


version = Solution()
answer = version.compareVersion("1.0.0.1.0","1.0.1.0")
if answer == 1:
    print("Version1 > Version2")
elif answer == -1:
    print("Version2 > Version1")
elif answer == 0:
    print("Version1 == Version2")
else:
    print("Invalid Version number")
