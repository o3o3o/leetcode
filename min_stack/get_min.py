#https://leetcode.com/problems/min-stack/
class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.ary = []
        self.min = None
        self.need_update = False

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.ary.append(x)
        if not self.need_update:
            if self.min is None or self.min > x:
                 self.min = x
       
    def pop(self):
        """
        :rtype: void
        """
        r = self.ary.pop()
        
        if not self.need_update and r == self.min:
            self.min = None
            self.need_update = True

    def top(self):
        """
        :rtype: int
        """
        if len(self.ary) > 0:
            return self.ary[-1]
        else:
            return None

    def getMin(self):
        """
        :rtype: int
        """
        if self.need_update:
            return self.updateAndFindMin()
        else:
            return self.min

    def updateAndFindMin(self):
        _min = self.ary[0]
        for x in self.ary:
            if _min > x:
                _min = x

        self.min = _min
        self.need_update = False
        return self.min

