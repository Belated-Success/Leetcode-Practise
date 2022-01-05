// #include<iostream>
// using namespace std;

/*

struct Node{
    int val;
    Node *left;
    Node *right;
    Node *next;
};

class Solution{
    public:
        Node* connect(Node* root) {
            Node* top = root;

            while(top != null && top.left != null){
                Node n = top;

                while(true){
                    n.left.next = n.right;

                    if(n.next == null)break;
                    n.right.next = n.next.left;
                    n = n.next;
                }
                top = top.left;
            }
            return root;
        }
};
*/

/*
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    

    return 0;
} */