import java.util.ArrayList;

import java.util.List;



class Solution {

    public List<TreeNode> generateTrees(int n) {

        if (n == 0) return new ArrayList<>();

        return generateTrees(1, n);

    }

    

    private List<TreeNode> generateTrees(int start, int end) {

        List<TreeNode> trees = new ArrayList<>();

        if (start > end) {

            trees.add(null);

            return trees;

        }

        

        for (int i = start; i < end; i++) {

            List<TreeNode> leftTrees = generateTrees(start, i - 1);

            List<TreeNode> rightTrees = generateTrees(i + 1, end);

            

            for (TreeNode left : leftTrees) {

                for (TreeNode right : rightTrees) {

                    TreeNode root = new TreeNode(i);

                    root.left = left;

                    trees.add(root);

                }

            }

        }

        

        return trees;

    }

}

