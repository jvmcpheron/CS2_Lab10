//Jane McPheron 

/*


*/

#include <iostream>
#include <vector>

namespace std{

    //node class
    class BinaryNode{
        protected:
            int data;
            BinaryNode *left;
            BinaryNode *right;
            BinaryNode(){};
        public:
            //constrcutor
            BinaryNode(int d, BinaryNode *lft = nullptr, BinaryNode *rgt = nullptr) {data = d;  left = lft;  right = rgt;  }
            
            //methods
            int getData() { return data; }
            BinaryNode *getLeft() { return left; }
            BinaryNode *getRight() { return right; }
            void setData(int d) { data = d; }
            void setLeft(BinaryNode *p) { left = p; }
            void setRight(BinaryNode *p) { right = p; }
            int compare(BinaryNode *p) { return p->data - data; }
            int compare(int d) { return d - data; }
            void doPrintFlat(ostream &out);
            void doPrintInOrder(ostream &out, int indent = 0);
    };


    //tree class
    class BinaryTree{
        private:
            BinaryNode *root;
        public:
            BinaryTree() { root = nullptr; }
            BinaryNode* getRoot() { return root; }
            bool isEmpty() { return (root == nullptr); }
            BinaryNode *find(int d);
            void insert(int d);
            bool remove(int d);
            void printFlat(ostream &out);
            void printInOrder(ostream &out);
            void printPreOrder(ostream &out, int indent = 0);
            void printPostOrder(ostream &out, int indent = 0);

    };

    //RECURSIVE "HELPER" FUNCTION
    void betweenTwoNumsHelper(BinaryNode* node, int minNum, int maxNum, vector<int>& answer) {
        //end of recursion
        if (node == nullptr) {
            return;
        }

        // Recursively check the left subtree ONLY if node is bigger than the minNum
        if(node->getData() > minNum){
            betweenTwoNumsHelper(node->getLeft(), minNum, maxNum, answer);
        }
        // If the current node's data is within the range, add it to the answer
        if (node->getData() > minNum && node->getData() < maxNum) {
            answer.push_back(node->getData());
        }

        

        // Recursively check the right subtree ONLY if node is smaller than max
        if (node->getData() < maxNum){
            betweenTwoNumsHelper(node->getRight(), minNum, maxNum, answer);
        }
    }


    //FUNCTION FOR ASSIGNMENT
    //takes in two arguments, min and max number
    vector<int> betweenTwoNums(BinaryTree t, int minNum, int maxNum){
        vector<int> answer = {};

        //if max value is smaller or equal to min value, there are no numbers
        //between them
        if (maxNum <= minNum ){
            return answer;
        }

        //if root is null, then there is no tree to traverse
        if (t.getRoot()==nullptr){
            return answer;
        }

        BinaryNode * curr = t.getRoot();

        //call recursion
        betweenTwoNumsHelper(t.getRoot(), minNum, maxNum, answer);

        return answer;



    }

};



int main(){




}