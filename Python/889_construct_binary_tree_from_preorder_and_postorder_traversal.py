# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def constructFromPrePost(self, pre, post):
        """
        :type pre: List[int]
        :type post: List[int]
        :rtype: TreeNode
        """
        if len(pre) == 0:
            return None
        root = TreeNode(pre[0])
        pre = pre[1:]
        post = post[:-1]
        root_index = 0
        for each in post:
            root_index += 1
            if each == pre[0]:
                break 
        root.left = self.constructFromPrePost(pre[:root_index],post[:root_index]) 
        root.right = self.constructFromPrePost(pre[root_index:],post[root_index:]) 
        return root
        