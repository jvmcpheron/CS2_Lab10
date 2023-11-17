//Jane McPheron 

/*

TEST ONE
./main
Add node:100
Add node:68
Add node:50
Add node:90
Add node:567
Add node:0
Add node:1
Add node:89
Add node:1070
Add node:1015
Add node:1000
Add node:666
Add node:1111
Add node:2000
Add node:;
Numbers between 5 and 15: 
Numbers between 1000 and 1010: 
Numbers between 1020 and 1010: 
Numbers between 0 and 1: 
Numbers between 20 and 100: 50 68 89 90 


TEST TWO
./main
Add node:6
Add node:18
Add node:1005
Add node:15
Add node:1010
Add node:5
Add node:7
Add node:555
Add node:123
Add node:;
Numbers between 5 and 15: 6 7 
Numbers between 1000 and 1010: 1005 
Numbers between 1020 and 1010: 
Numbers between 0 and 1: 
Numbers between 20 and 100: 

*/

#include <iostream>
#include <vector>

using namespace std;

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

            //added insert method
            void insert(int d){ 
                if (isEmpty()) {
                    root = new BinaryNode(d);
                } else {
                    BinaryNode* current = root;
                    bool inserted = false;

                    while (!inserted) {
                        if (d < current->getData()) {
                            if (current->getLeft() == nullptr) {
                                current->setLeft(new BinaryNode(d));
                                inserted = true;
                            } else {
                                current = current->getLeft();
                            }
                        } else if (d > current->getData()) {
                            if (current->getRight() == nullptr) {
                                current->setRight(new BinaryNode(d));
                                inserted = true;
                            } else {
                                current = current->getRight();
                            }
                        } else {
                            // Duplicate values are not allowed
                            // You can modify this part based on your requirements
                            inserted = true;
                        }
                    }
                }
            };

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





int main(){

    //TEST

    //test tree
    BinaryTree testTree = BinaryTree();

    string input = "";

    //input nodes
    while (input != ";"){
        cout << "Add node:";
        cin >> input;

        //stops loop if semicolon
        if(input == ";"){
            break;
        }

        int numIn = stoi(input);

        
        //adds input to tree
        testTree.insert(numIn);
        
    }

    //now that there is a tree, time to test 
    vector<int> result1 = betweenTwoNums(testTree, 5, 15);

    //display results
    cout << "Numbers between 5 and 15: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;


    result1 = betweenTwoNums(testTree, 1000, 1010);

    //display results
    cout << "Numbers between 1000 and 1010: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    result1 = betweenTwoNums(testTree, 1020, 1010);

    //display results
    cout << "Numbers between 1020 and 1010: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    result1 = betweenTwoNums(testTree, 0, 1);

    //display results
    cout << "Numbers between 0 and 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    result1 = betweenTwoNums(testTree, 20, 100);

    //display results
    cout << "Numbers between 20 and 100: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;


}