/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type FindElements struct {
    root *TreeNode
}


func Constructor(root *TreeNode) FindElements {
    this := FindElements{root: root}
    this.root.Val = 0
    this.recoverTree(this.root)
    return this
}

func (this *FindElements) recoverTree(root *TreeNode) {
    if root == nil {
        return
    }
    if root.Left != nil {
        root.Left.Val = 2 * root.Val + 1
        this.recoverTree(root.Left)
    }
    if root.Right != nil {
        root.Right.Val = 2 * root.Val + 2
        this.recoverTree(root.Right)
    }
}


func (this *FindElements) Find(target int) bool {
    return this.find(this.root, target)
}

func (this *FindElements) find(root *TreeNode, target int) bool {
    if root == nil {
        return false
    }
    if root.Val == target {
        return true
    }
    return this.find(root.Left, target) || this.find(root.Right, target)
}


/**
 * Your FindElements object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Find(target);
 */
